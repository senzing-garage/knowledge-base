# Working with Config

## Assumptions

1. User's only usecase is to add (delete?) data sources from config.
1. `sz_config_tools` requires the entire JSON for configuration manipulation.

## Vocabulary

1. **ConfigHandle** - (*int64*) memory location of configuration JSON
1. **ConfigID** - (*int64*) the hash value of the configuration JSON
1. **ConfigDefinition** - (*string*) the entire Senzing configuration JSON string
1. **DataSourceList** - (*string*) a list of data source names (format currently undetermined)

## Proposal 1

1. Remove SzConfig API
1. Add the following to SzConfigManager:
    1. `getTemplateConfig()` returns **ConfigDefinition**
    1. `addDataSources(String configDefinition, String... dataSources)` returns  **ConfigDefinition**
    1. `deleteDataSources(String configDefinition, String... dataSources)` returns  **ConfigDefinition**
    1. `getDataSources(String configDefinition)` returns **DataSourceList**

## Proposal 2

1. Remove SzConfig API
1. Add the following to SzConfigManager:
    1. `getTemplateConfig()` returns **ConfigDefinition**
    1. `addDataSources(String configDefinition, String... dataSources)` returns  **ConfigDefinition**
    1. `deleteDataSources(String configDefinition, String... dataSources)` returns  **ConfigDefinition**
    1. `getDataSources(String configDefinition)` returns **DataSourceList**
    1. `getDataSources(long configId)` returns **DataSourceList**

## Proposal 3

1. Remove SzConfig API
1. Add the following to SzConfigManager:
    1. `getTemplateConfigId()` returns **ConfigID**
    1. `createNewConfigAddDatasources(long fromConfigId, String... dataSource)` returns **ConfigID**
    1. Alternative: `createNewConfigDeleteDatasources(long fromConfigId, String... dataSource)` returns **ConfigID**
    1. Alternative: `createNewConfig(long fromConfigId, String[] addDataSources, String[] deleteDataSources)` returns **ConfigID**
1. Add new **python-only** API for sz_config_tool (perhaps `SzInternalConfigManager`)
    1. `addConfig(String configDefinition, String configComment)`  returns **ConfigID**
    1. `getTemplateConfig()` returns  **ConfigDefinition**

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
