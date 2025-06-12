# SDK Documentation - canonical description

 Proposal for[sdk-documentation].

## SzConfig

1. **addDataSource**

    - Method AddDataSource adds a new data source to the Senzing configuration.

1. **deleteDataSource**
1. **export**
1. **getDataSources**

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
