# Working with Config

## Assumptions

1. A user's only usecase is to add (delete?) data sources from a Senzing configuration.
1. `sz_config_tools` requires the entire JSON for configuration manipulation.

## Vocabulary

1. **ConfigHandle** - (*int64*) Senzing binary memory location of configuration JSON
1. **ConfigID** - (*int64*) the hash value of the configuration JSON in the Senzing database
1. **ConfigDefinition** - (*string*) the entire Senzing configuration JSON string
1. **DataSourceList** - (*string*) a list of data source names (format currently undetermined)

## Proposal 1

1. Remove SzConfig API
1. Add the following to SzConfigManager:
    1. `getTemplateConfig()` returns **ConfigDefinition**
    1. `addDataSources(String configDefinition, String... dataSources)` returns  **ConfigDefinition**
    1. `deleteDataSources(String configDefinition, String... dataSources)` returns  **ConfigDefinition**
    1. `getDataSources(String configDefinition)` returns **DataSourceList**
1. Pros:
1. Cons:

## Proposal 2

1. Remove SzConfig API
1. Add the following to SzConfigManager:
    1. `getTemplateConfig()` returns **ConfigDefinition**
    1. `addDataSources(String configDefinition, String... dataSources)` returns  **ConfigDefinition**
    1. `deleteDataSources(String configDefinition, String... dataSources)` returns  **ConfigDefinition**
    1. `getDataSources(String configDefinition)` returns **DataSourceList**
    1. `getDataSources(long configId)` returns **DataSourceList**
1. Pros:
1. Cons:

## Proposal 3

1. Remove SzConfig API
1. Modify the following methods in SzConfigManager:
    1. Add `getTemplateConfigId()` returns **ConfigID**
        1. A replacement for `SzConfig.createConfig()`, but returns **ConfigID**, not **ConfigHandle**
        1. This method:
            1. Calls `SzConfig_create()` returning a **ConfigHandle**
            1. Calls `SzConfig_save(ConfigHandle)` returning a **ConfigDefinition**
            1. Calls `SzConfig_close(ConfigHandle)`
            1. Calls `SzConfigMgr_addConfig(ConfigDefinition, "Template as of YYYY-MM-DDThh:mm:ss")` returning a **ConfigID**
                1. Timestamp in ISO 8601 format
            1. Method returns **ConfigID**
    1. Add `createNewConfigAddDatasources(fromConfigID, String... dataSource)` returns **ConfigID**
        1. if `fromConfigId` is 0, then the default ConfigID is used.
        1. If there is no default ConfigID, the method inserts the template configuration, adds the data sources, and returns the new ConfigID.
        1. Alternative: `createNewConfigDeleteDatasources(fromConfigId, String... dataSource)` returns **ConfigID**
        1. Alternative: `createNewConfig(fromConfigId, String[] addDataSources, String[] deleteDataSources)` returns **ConfigID**
        1. This method:
            1. If `fromConfigID` == 0:
                1. Calls `SzConfigManager.getDefaultConfigId()` to get ConfigId
            1. Calls `SzConfigMgr_getConfig(ConfigId)` returning a **ConfigDefinition**
            1. Calls `SzConfig_load(ConfigDefinition)` returning a **ConfigHandle**
            1. For each datasource, call `SzConfig_addDataSource(ConfigHandle, datasource)` returning result message
            1. Calls `SzConfig_save(ConfigHandle)` returning a **ConfigDefinition**
            1. Calls `SzConfig_close(ConfigHandle)`
            1. Calls `SzConfigMgr_addConfig(ConfigDefinition, comment)` returning a **ConfigID**
            1. Method returns **ConfigID**
    1. Add `getDataSources(ConfigID)` returns **DataSourceList**
        1. This method:
            1. If `ConfigID` == 0:
                1. Calls `SzConfigManager.getDefaultConfigId()` to get ConfigId
            1. Calls `SzConfigMgr_getConfig(ConfigId)` returning a **ConfigDefinition**
            1. Calls `SzConfig_load(ConfigDefinition)` returning a **ConfigHandle**
            1. Calls `SzConfig_listDataSources(ConfigHandle)` returning a **DataSourceList**
            1. Calls `SzConfig_close(ConfigHandle)`
            1. Method returns **DataSourceList**
    1. Modify `getDefaultConfigId()`
        1. If no default exists:
            1. Calls `SzConfigManager.getTemplateConfigId()` returning a **ConfigID**
            1. Method returns **ConfigID**
    1. Move `addConfig(ConfigDefinition, configComment)` to new **python-only** API
    1. Move `getConfig(configId)` to new **python-only** API
1. SzConfigManager would then have the following method signatures:
    1. New:
        1. `createNewConfigAddDatasources(fromConfigID, String... dataSource)` returns **ConfigID**
        1. `getDataSources(ConfigID)` returns **DataSourceList**
        1. `getTemplateConfigId()` returns **ConfigID**
    1. Existing:
        1. `getConfigs()` returns JSON
        1. `getDefaultConfigId()` returns **ConfigID**
        1. `replaceDefaultConfigId(currentDefaultConfigID, newDefaultConfigID)`
        1. `setDefaultConfigId(ConfigID)`
    1. Moved to new **python-only** API
        1. `addConfig(ConfigDefinition, configComment)`
        1. `getConfig(configId)`
1. Add new **python-only** API for sz_config_tool (perhaps `SzInternalConfigManager`)
    1. `addConfig(ConfigDefinition, String configComment)` returns **ConfigID**
    1. `getConfig(ConfigID)` returns **ConfigDefinition**
        1. `getConfig(0)` returns Default **ConfigDefinition**
    1. `getTemplateConfig()` returns  **ConfigDefinition**
1. Pros:
    1. The user never has a copy of **ConfigDefinition**.  So they can't corrupt it.
    1. Each "grpc" SDK only has to call the gRPC server to do the "heavy lifting".
    1. Updating the Senzing Configuration over gRPC is not sensitive to non-sticky routing.
    1. One less Senzing "object".  `SzConfig` is removed.
1. Cons:
    1. Each "core" SDK has to implement a sophisticated `createNewConfigAddDatasources` method.
    1. The returned message may have to return the result of each data source added.

### Proposal 3 example

1. Python before

```python
sz_abstract_factory = SzAbstractFactoryCore("Example instance", SETTINGS)

# Create Senzing objects.

sz_config = sz_abstract_factory.create_config()
sz_configmanager = sz_abstract_factory.create_configmanager()

# Get current Senzing configuration.

old_config_id = sz_configmanager.get_default_config_id()
old_json_config = sz_configmanager.get_config(old_config_id)
config_handle = sz_config.import_config(old_json_config)

# Add DataSources to Senzing configuration.

for datasource in datasources:
    try:
        sz_config.add_data_source(config_handle, datasource)
    except SzError as err:
        print(err)

# Persist new Senzing configuration.

new_json_config = sz_config.export_config(config_handle)
new_config_id = sz_configmanager.add_config(new_json_config, "Add TruthSet datasources")
sz_configmanager.replace_default_config_id(old_config_id, new_config_id)

# With the change in Senzing configuration, Senzing objects need to be updated.

sz_abstract_factory.reinitialize(new_config_id)
```

1. Python after

```python
sz_abstract_factory = SzAbstractFactoryCore("Example instance", SETTINGS)
sz_configmanager = sz_abstract_factory.create_configmanager()
old_config_id = sz_configmanager.get_default_config_id()
new_config_id = sz_configmanger.create_new_config_add_datasources(old_config_id, datasources**)
sz_configmanager.replace_default_config_id(old_config_id, new_config_id)
sz_abstract_factory.reinitialize(new_config_id)
```
