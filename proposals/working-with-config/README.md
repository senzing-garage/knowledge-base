# Working with Config

## Assumptions

1. A user's only usecase is to add (delete?) data sources from a Senzing configuration.
1. `sz_config_tools` requires the entire JSON for configuration manipulation.
1. The "easy button":
    1. Is it the case that developers would only add datasources to the default config during development
       and that the `sz_config_tool` should be used for production systems?
       1. Could it also be true that only the `sz_config_tool` is used to export/import configurations for source code version control?

## Vocabulary

1. **ConfigHandle** - (*int64*) Senzing binary memory location of configuration JSON
1. **ConfigID** - (*int64*) the hash value of the configuration JSON in the Senzing database
1. **ConfigDefinition** - (*string*) the entire Senzing configuration JSON string
1. **DataSourceList** - (*string*) a list of data source names (format currently undetermined)

## Proposal 1

1. Remove SzConfig API
1. Add the following to SzConfigManager:
    1. `getTemplateConfig()` returns **ConfigDefinition**
    1. `addDataSources(String configDefinition, String... dataSourceCodes)` returns  **ConfigDefinition**
    1. `deleteDataSources(String configDefinition, String... dataSourceCodes)` returns  **ConfigDefinition**
    1. `getDataSources(String configDefinition)` returns **DataSourceList**
1. Pros:
    1. No change to Senzing C binaries.
1. Cons:

## Proposal 2

1. Remove SzConfig API
1. Add the following to SzConfigManager:
    1. `getTemplateConfig()` returns **ConfigDefinition**
    1. `addDataSources(String configDefinition, String... dataSourceCodes)` returns  **ConfigDefinition**
    1. `deleteDataSources(String configDefinition, String... dataSourceCodes)` returns  **ConfigDefinition**
    1. `getDataSources(String configDefinition)` returns **DataSourceList**
    1. `getDataSources(long configId)` returns **DataSourceList**
1. Pros:
    1. No change to Senzing C binaries.
1. Cons:

## Proposal 3

Synopsis:

1. Remove SzConfig package
1. Add 3 methods to SzConfigManager
1. Create a Python, internal-only, package for `sz_config_tool`
1. None of the SDKs expose the Senzing configuration JSON

Details:

1. Remove SzConfig API
1. SzConfigManager would have the following method signatures:
    1. New:
        1. `createNewConfig(fromConfigID, newConfigComment, dataSourceCodes)` returns **ConfigID**
            1. If `fromConfigID` == 0, the Template Config is used.
        1. `getDataSources(ConfigID)` returns **DataSourceList**
        1. `getTemplateConfigId()` returns **ConfigID**
    1. Existing:
        1. `addConfig(ConfigDefinition, configComment)`  returns **ConfigID**
        1. `getConfig(ConfigID)` returns **ConfigDefinition**
        1. `getConfigs()` returns JSON
        1. `getDefaultConfigId()` returns **ConfigID**
        1. `replaceDefaultConfigId(currentDefaultConfigID, newDefaultConfigID)`
        1. `setDefaultConfigId(ConfigID)`
1. Pros:
    1. No change to Senzing C binaries.
    1. Each "grpc" SDK only has to call the gRPC server to do the "heavy lifting".
    1. Updating the Senzing Configuration over gRPC is not sensitive to non-sticky routing.
    1. User never manipulates **ConfigDefinition** directly
    1. **ConfigDefinition** can use source control via `getConfig()` and `addConfig()`
    1. There no confusion in the User's mind as to whether the configuration is in memory, in the database, or active.
    1. One less Senzing "object".  `SzConfig` is removed.
1. Cons:
    1. Each "core" SDK has to implement a 3 new methods that make multiple calls to Senzing C binaries.
    1. Every `createNewConfig()` creates a configuration in the database.
    1. The returned message may have to return the result of each data source added.

### Proposal 3 Implementation

1. Modify the following methods in SzConfigManager:
    1. Add `createNewConfig(fromConfigID, newConfigComment, dataSourceCodes)` returns **ConfigID**
        1. if `fromConfigId` is 0, then the default ConfigID is used.
        1. If there is no default ConfigID, the method inserts the template configuration, adds the data sources, and returns the new ConfigID.
        1. Alternative: `createNewConfigDeleteDatasources(fromConfigId, dataSourceCodes)` returns **ConfigID**
        1. Alternative: `createNewConfig(fromConfigId, adddataSourceCodes, deletedataSourceCodes)` returns **ConfigID**
        1. This method:
            1. If `fromConfigID` == 0:
                1. Calls `SzConfigManager.getDefaultConfigId()` to get ConfigId
            1. Calls `SzConfigMgr_getConfig(ConfigId)` returning a **ConfigDefinition**
            1. Calls `SzConfig_load(ConfigDefinition)` returning a **ConfigHandle**
            1. For each datasource, call `SzConfig_addDataSource(ConfigHandle, datasource)` returning result message
                1. If delete supported, use `SzConfig_deleteDataSource(ConfigHandle, datasource)`
            1. Calls `SzConfig_save(ConfigHandle)` returning a **ConfigDefinition**
            1. Calls `SzConfig_close(ConfigHandle)`
            1. Calls `SzConfigMgr_addConfig(ConfigDefinition, newConfigComment)` returning a **ConfigID**
            1. Method returns **ConfigID**
    1. Add `getDataSources(ConfigID)` returns **DataSourceList**
        1. Essentially this method is moved from SzConfig to SzConfigManager
        1. This method:
            1. If `ConfigID` == 0:
                1. Calls `SzConfigManager.getDefaultConfigId()` to get ConfigId
            1. Calls `SzConfigMgr_getConfig(ConfigId)` returning a **ConfigDefinition**
            1. Calls `SzConfig_load(ConfigDefinition)` returning a **ConfigHandle**
            1. Calls `SzConfig_listDataSources(ConfigHandle)` returning a **DataSourceList**
            1. Calls `SzConfig_close(ConfigHandle)`
            1. Method returns **DataSourceList**
    1. Add `getTemplateConfigId()` returns **ConfigID**
        1. A replacement for `SzConfig.createConfig()`, but returns **ConfigID**, not **ConfigHandle**
        1. This method:
            1. Calls `SzConfig_create()` returning a **ConfigHandle**
            1. Calls `SzConfig_save(ConfigHandle)` returning a **ConfigDefinition**
            1. Calls `SzConfig_close(ConfigHandle)`
            1. Calls `SzConfigMgr_addConfig(ConfigDefinition, "Template date: YYYY-MM-DDThh:mm:ss")` returning a **ConfigID**
                1. Timestamp in RFC 3339 format
            1. Method returns **ConfigID**
    1. Modify `getDefaultConfigId()`
        1. If no default exists:
            1. Calls `SzConfigManager.getTemplateConfigId()` returning a **ConfigID**
            1. Method returns **ConfigID**
    1. Move `addConfig(ConfigDefinition, configComment)` to new **python-only** API
    1. Move `getConfig(configId)` to new **python-only** API
1. Add new **python-only** API for sz_config_tool (perhaps `SzInternalConfigManager`)
    1. `addConfig(ConfigDefinition, String configComment)` returns **ConfigID**
        1. This method:
            1. Calls `SzConfigMgr_addConfig(ConfigDefinition, configComment)` returning a **ConfigID**
            1. Method returns **ConfigID**
    1. `getConfig(ConfigID)` returns **ConfigDefinition**
        1. `getConfig(0)` returns Default **ConfigDefinition**
        1. This method:
            1. If `ConfigID` == 0:
                1. Calls `SzConfigManager.getDefaultConfigId()` returning a **ConfigID**
            1. Calls `SzConfigMgr_getConfig(ConfigID)` returning a **ConfigDefinition**
            1. Method returns **ConfigDefinition**
    1. `getTemplateConfig()` returns  **ConfigDefinition**
        1. This method:
            1. Calls `SzConfig_create()` returning a **ConfigHandle**
            1. Calls `SzConfig_save(ConfigHandle)` returning a **ConfigDefinition**
            1. Calls `SzConfig_close(ConfigHandle)`
            1. Method returns **ConfigDefinition**

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
    new_config_id = sz_configmanger.create_new_config(old_config_id, "my comment", datasources**)
    sz_configmanager.replace_default_config_id(old_config_id, new_config_id)


    sz_abstract_factory.reinitialize(new_config_id)
    ```

## Proposal 3 counter-example

May have temporal dependency similar to Proposal 4 counter-example.

## Proposal 4

Synopsis:

1. Remove the `SzConfig` functional interface
1. Add a new `SzConfig` interface with object-oriented semantics:
   - `addDataSource(String dataSourceCode)`
   - `deleteDataSource(String dataSourceCode)`
   - `String getDataSources()`
   - `toString()` / `export()`
1. Change `SzConfigManager` as follows:
   - `ConfigID addConfig(SzConfig, String comment)` (NOTE: `registerConfig(SzConfig config, String comment)` -- preferred by Barry)
   - `SzConfig getConfig(ConfigID)`
   - `String getConfigRegistry()`
   - `ConfigID getDefaultConfigId()`
   - `void replaceDefaultConfigId(ConfigID currentDefaultConfigId, ConfigID newDefaultConfigId)`
   - `void setDefaultConfigId(ConfigID configId)`
   - `SzConfig createTemplateConfig()`
1. Have proto file define:
   - `String SzConfigManager.addDataSource(String configDefinition, String dataSourceCode)`
   - `String SzConfigManager.deleteDataSource(String configDefinition, String dataSourceCode)`
1. Implement `SzCoreConfig` (implements `SzConfig`) and works with `native SzConfig_*`
   - has data member `configDefinition` (type string)
1. Implement `SzGrpcConfig` (implements `SzConfig`) and works with private GRPC functions `addDataSource()` and `deleteDataSource()`)
   - has data member `configDefinition` (type string)
   - has a data member to know where to communicate for GRPC
1. Pros:
    1. No change to Senzing C binaries.
    1. Each "grpc" SDK only has to call the gRPC server to do the "heavy lifting".
    1. Does support errors for introducing individual DATA_SOURCE_CODEs.
    1. Updating the Senzing Configuration over gRPC is not sensitive to non-sticky routing.
    1. One less Senzing "object".  `SzConfig` is removed.
1. Cons:
    1. First use of object-orientation. SDK uses a "functional" programming style.
        1. The underlying C binary is written in the functional style.
        1. "Side-effects" need to be considered now that there's state and mutable data.
            1. What happens when there are two or more `SzConfig` objects, potentially in separate processes?
            1. They each hold state, even though the "others" may be changing state.
            1. It's the first foray into RESTful architecture
    1. Entire **ConfigDefinition** sent over the wire multiple times.

### Proposal 4 example

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

    config = sz_configmanager.get_config(old_config_id)

    for datasource in datasources:
        try:
            config.add_data_source(datasource)
        except SzError as err:
            print(err)

    new_config_id = sz_configmanger.register_config(config, "my comment")

    sz_configmanager.replace_default_config_id(old_config_id, new_config_id)
    sz_abstract_factory.reinitialize(new_config_id)
    ```

## Proposal 4 counter-example

1. Temporal dependencies

    ```python
    old_config_id = sz_configmanager.get_default_config_id()
    config1 = sz_configmanager.get_config(old_config_id)
    config2 = sz_configmanager.get_config(old_config_id)
    doSomethingWith(config2)
    for datasource in datasources1:
        try:
            config1.add_data_source(datasource)
        except SzError as err:
            print(err)
    new_config_id = sz_configmanger.register_config(config, "my comment")
    sz_configmanager.replace_default_config_id(old_config_id, new_config_id)
    ```

At this point, `config2` may have completely changed the default config; rendering `config1` with incompatible state.
This approach introduces a temporal dependency.

## Proposal 5

This is the simplest option (the "easy button") and is only for adding data source
codes.  All "real" Senzing configuration is done via `sz_config_tool`.

Rationale: When processing records, the only configuration change would be to add datasources.
Any other Senzing configuration change would be independent of programmatic functionality.
Therefore, `sz_config_tool` would be used for non-programatic Senzing configuration changes.

1. Remove SzConfig API
1. SzConfigManager would have the following method signatures:
    1. New:
        1. `addDataSourcesToConfig(ConfigID, dataSourceCodes)` returns **ConfigID**
        1. `getDataSources(ConfigID)` returns **DataSourceList**
        1. `getTemplateConfigId()` returns **ConfigID** (registers the template if not registered)
    1. Existing:
        1. `addConfig(ConfigDefinition, configComment)` returns **ConfigID**
        1. `getConfig(ConfigID)` returns **ConfigDefinition**
        1. `getConfigs()` returns JSON
        1. `getDefaultConfigId()` returns **ConfigID**
        1. `replaceDefaultConfigId(currentDefaultConfigID, newDefaultConfigID)`
        1. `setDefaultConfigId(ConfigID)`
1. Pros:
    1. Works over gRPC.
    1. Very straight-forward usage
    1. Can be augmented in future releases without breaking backwards compatibility
1. Cons:
    1. Very focused application (e.g.: new functions would be required for adding features)

Details:

1. The `addDataSourcesToConfig()` function does the following:
    1. Calls `SzConfigMgr_getConfig(OldConfigId)` returning a **ConfigDefinition**
    1. Calls `SzConfig_load(ConfigDefinition)` returning a **ConfigHandle**
    1. For each datasource, call `SzConfig_addDataSource(ConfigHandle, datasource)`
    1. Calls `SzConfig_save(ConfigHandle)` returning a **ConfigDefinition**
    1. Calls `SzConfig_close(ConfigHandle)`
    1. Calls `SzConfigMgr_addConfig(ConfigDefinition, "EasyButton: YYYY-MM-DDThh:mm:ss")` returning a **ConfigID**
    1. Method returns **ConfigID**

### Proposal 5 example

1. The "easy button":

```python
sz_abstract_factory = SzAbstractFactoryCore("Example instance", SETTINGS)
sz_configmanager = sz_abstract_factory.create_configmanager()

base_config_id = sz_configmanager.get_template_config_id()
new_config_id = sz_configmanger.add_data_sources_to_config(base_config_id, datasources**)

# sz_abstract_factory.reinitialize(new_config_id)
```

## Proposal 6

### SzConfig public interface

#### New methods for SzConfig

- None

#### Modified methods for SzConfig

| Old                                            | New                              | Return value |
|------------------------------------------------|----------------------------------|--------------|
| addDataSource(configHandle, dataSourceCode)    | addDataSource(dataSourceCode)    | string       |
| deleteDataSource(configHandle, dataSourceCode) | deleteDataSource(dataSourceCode) |              |
| getDataSources(configHandle)                   | getDataSources()                 | string       |
| exportConfig(configHandle)                     | export()                         | string       |

#### Unmodified methods for SzConfig

| Signature | Return value |
|-----------|--------------|
| initialize(instanceName, settings, verboseLogging) | |

#### Deleted methods for SzConfig

| Signature                      | Return value |
|--------------------------------|--------------|
| closeConfig(configHandle)      ||
| createConfig()                 | configHandle |
| destroy()                      ||
| importConfig(configDefinition) ||

### SzConfigManager

- **Note:** The creation patterns `createConfig...` may vary from SDK to SDK.
  Java can use method overloading.
  Python can take different input datatype.
  Go is pretty rigid.

#### New methods for SzConfigManager

| Signature                                | Return value | Notes |
|------------------------------------------|--------------|-------|
| createConfig(...)                        | SzConfig     | General principle |
| createConfigFromString(configDefinition) | SzConfig     | Potential variant |
| createConfigFromTemplate()               | SzConfig     | Potential variant |
| setDefaultConfig(configDefinition, configComment) | int64 | |

#### Modified methods for SzConfigManager

| Old                 | New                                | Return value | Notes |
|---------------------|------------------------------------|--------------|-------|
| getConfig(configId) | createConfigFromConfigId(configId) | SzConfig     | Potential variant |
| addConfig(configDefinition, configComment) | registerConfig(configDefinition, configComment) | int64        ||

#### Unmodified methods for SzConfigManager

| Signature                                                          | Return value |
|--------------------------------------------------------------------|--------------|
| destroy()                                                          |              |
| getConfigs()                                                       | string       |
| getDefaultConfigId()                                               | int64        |
| initialize(instanceName, settings, verboseLogging)                 |              |
| replaceDefaultConfigId(currentDefaultConfigId, newDefaultConfigId) |              |
| setDefaultConfigId(configId)                                       |              |

#### Deleted methods for SzConfigManager

- None

### Proposal 6 examples

1. Adding datasources:

```python
sz_abstract_factory = SzAbstractFactoryCore("Example instance", SETTINGS)
sz_configmanager = sz_abstract_factory.create_configmanager()

config_id = sz_configmanager.get_default_config_id()
sz_config = sz_configmanager.create_config_from_config_id(config_id)
sz_config.add_data_source(datasource)
new_config_id = sz_configmanager.register_config(sz_config.export(), configComment)

sz_abstract_factory.reinitialize(new_config_id)
```

1. Storing configuration in source control:

```python
sz_abstract_factory = SzAbstractFactoryCore("Example instance", SETTINGS)
sz_configmanager = sz_abstract_factory.create_configmanager()

config_id = sz_configmanager.get_default_config_id()
sz_config = sz_configmanager.create_config_from_config_id(config_id)
store_config_definition_in_source_control(sz_config.export())
```

1. Updating configuration from source control:

```python
sz_abstract_factory = SzAbstractFactoryCore("Example instance", SETTINGS)
sz_configmanager = sz_abstract_factory.create_configmanager()

config_definition = getConfigDefinitionFromSourceControl()
new_config_id = sz_configmanager.add_config(config_definition, configComment)

sz_abstract_factory.reinitialize(new_config_id)
```

### Analysis

1. The Senzing C binary `SzConfigMgr_* requires no changes.
1. The only way to get an SzConfig is via SzConfigManager.
   The "SzConfig" public interface intentionally does not have a way to load the JSON.
1. Pros:
    1. Works over gRPC.
    1. Similar to existing Object model.
    1. SzConfig can be augmented in future releases without breaking backwards compatibility.
    1. SzConfigManager is essentially "closed", since new features would be in the SzConfig object.
1. Cons:
    1. ????

Details:
