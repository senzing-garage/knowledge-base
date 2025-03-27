# Working with Config

## Vocabulary

1. **ConfigHandle** - (*int64*) Senzing binary memory location of configuration JSON
1. **ConfigID** - (*int64*) the hash value of the configuration JSON in the Senzing database
1. **ConfigDefinition** - (*string*) the entire Senzing configuration JSON string

## Proposal mjd-N

### Proposal mjd-N assumptions

1. Someday, it would be nice to no longer need a tool like `sz_config_tool` to manage Senzing configuration.
1. The Senzing C binaries can be modified to except **ConfigDefinition** (a JSON string), rather than an `exportHandle`.

### Synopsis

To avoid having the Senzing C binaries keep state for a **ConfigDefinition** under modification,
they receive a **ConfigDefinition** and instructions on the desired modification.
The Senzing C binaries return a new version of the **ConfigDefinition** with the modification.
In this manner, the Senzing C binaries are not keeping state.
This technique is akin to functional programming where new states are created through pure functions.

Each SDK `SzConfig` manages the state of the **ConfigDefinition** under modification.

### SzConfig public interface

#### New methods for SzConfig

- None

#### Modified methods for SzConfig

| Old                                            | New                              | Return value |
|------------------------------------------------|----------------------------------|--------------|
| addDataSource(configHandle, dataSourceCode)    | addDataSource(dataSourceCode)    | string       |
| deleteDataSource(configHandle, dataSourceCode) | deleteDataSource(dataSourceCode) | string       |
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

#### New methods for SzConfigManager

| Signature                                | Return value |
|------------------------------------------|--------------|
| createConfigFromString(configDefinition) | SzConfig     |
| createConfigFromTemplate()               | SzConfig     |

#### Modified methods for SzConfigManager

| Old                 | New                                | Return value |
|---------------------|------------------------------------|--------------|
| getConfig(configId) | createConfigFromConfigID(configID) | SzConfig     |
| addConfig(configDefinition, configComment) | registerConfig(configDefinition, configComment) | int64        |

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

### Proposal mjd-N examples

1. Adding datasources:

```python
sz_abstract_factory = SzAbstractFactoryCore("Example instance", SETTINGS)
sz_configmanager = sz_abstract_factory.create_configmanager()

config_id = sz_configmanager.get_default_config_id()
sz_config = sz_configmanager.create_config_from_config_id(config_id)
sz_config.add_data_source(datasource)
new_config_id = sz_configmanager.add_config(sz_config.to_JSON(), configComment)

sz_abstract_factory.reinitialize(new_config_id)
```

1. Storing configuration in source control:

```python
sz_abstract_factory = SzAbstractFactoryCore("Example instance", SETTINGS)
sz_configmanager = sz_abstract_factory.create_configmanager()

config_id = sz_configmanager.get_default_config_id()
sz_config = sz_configmanager.create_config_from_config_id(config_id)
store_config_definition_in_source_control(sz_config.to_JSON())
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

1. The Senzing C binary `SzConfig_*` requires the new functions like the following, that accept a **ConfigDefinition** parameter:
    1. `addDataSource`
    1. `deleteDataSource`
    1. `getDataSources`
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
