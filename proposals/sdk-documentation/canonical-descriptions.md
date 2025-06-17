# SDK Documentation - canonical description

 Proposal for [sdk-documentation].

 1. Guiding principles
    1. Approach from the customer point of view.
    1. First sentence is a "topic" sentence as it may show up in synopsis and code hints.
        1. Although the topic sentence starts with a verb in this list, each SDK may choose the appropriate introduction
            1. e.g.  *Go:* Method AddDataSource adds a new data source to this instance
    1. Less is better.
    1. Avoid redundancy.
        1. Overview shouldn't talk about parameter specifics.
        1. Specifics about parameters should be described in the parameters
    1. Tailoring to SDK language specific style is OK.

## SzConfig

1. **addDataSource**

    - Adds a new data source to this instance.

1. **deleteDataSource**

    - Deletes a data source from this instance.
        - Is idempotent

1. **export**

    - Retrieves the configuration definition for this instance.

1. **getDataSources**

    - Gets the data sources for this instance.

## SzConfigManager

1. **createConfigFromConfigID**

- Creates a new SzConfig instance for a configuration ID.

1. **createConfigFromString**

- Creates a new SzConfig instance from a configuration definition.

1. **createConfigFromTemplate**

- Creates a new SzConfig instance from the template configuration defintion.

1. **getConfigRegistry**

- Gets the configuration registry.

1. **getDefaultConfigId**

- Gets the default configuration for the repository.

1. **registerConfig**

- Registers a configuration defintion with the repository.

1. **replaceDefaultConfigId**

- Replaces the existing default configuration ID with a new configuration ID.
  - Acts like "Compare and swap"

1. **setDefaultConfig**

- Registers a configuration with the repository and sets its ID as the default for the repository.
  - Convenience method for `registerConfig` and `setDefaultConfigId`.

1. **setDefaultConfigId**

- Sets the default configuration ID.

## SzDiagnostic

1. **checkDatastorePerformance**

- Conducts a rudimentary datastore test to gauge I/O performance.

1. **getDatastoreInfo**

- Returns overview information about the datastore.

1. **getFeature**

- Experimental/internal for Senzing support use only.

1. **purgeRepository**

- ???? determine "repository" vs. "datastore"
- Purges all entity data in the entire repository.
  - Very dangerous method

1. **reinitialize**

- Hidden

## SzEngine

1. **addRecord**

-

1. **closeExport**
1. **countRedoRecords**
1. **deleteRecord**
1. **exportCsvEntityReport**
1. **exportJsonEntityReport**
1. **fetchNext**
1. **findInterestingEntitiesByEntityId**
1. **findInterestingEntitiesByRecordId**
1. **findNetworkByEntityId**
1. **findNetworkByRecordId**
1. **findPathByEntityId**
1. **findPathByRecordId**
1. **getActiveConfigId**
1. **getEntityByEntityId**
1. **getEntityByRecordId**
1. **getRecord**
1. **getRedoRecord**
1. **getStats**
1. **getVirtualEntityByRecordId**
1. **howEntityByEntityId**
1. **preprocessRecord**
1. **primeEngine**
1. **processRedoRecord**
1. **reevaluateEntity**
1. **reevaluateRecord**
1. **reinitialize**
1. **searchByAttributes**
1. **whyEntities**
1. **whyRecordInEntity**
1. **whyRecords**
1. **whySearch**

## SzProduct

1. **getLicense**

- Gets the product license details.

1. **getVersion**

- Gets the product version details.

[sdk-documentation]: README.md
