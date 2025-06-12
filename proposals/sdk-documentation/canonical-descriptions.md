# SDK Documentation - canonical description

 Proposal for [sdk-documentation].

 1. Guiding principles
    1. Approach from the customer point of view.
    1. First sentence is a "topic" sentence as it may show up in synopsis and code hints.
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
1. **createConfigFromString**
1. **createConfigFromTemplate**
1. **getConfigs**
1. **getDefaultConfigId**
1. **registerConfig**
1. **replaceDefaultConfigId**
1. **setDefaultConfig**
1. **setDefaultConfigId**

## SzDiagnostic

1. **checkDatastorePerformance**
1. **getDatastoreInfo**
1. **getFeature**
1. **purgeRepository**
1. **reinitialize**

## SzEngine

1. **addRecord**
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
1. **getVersion**

[sdk-documentation]: README.md
