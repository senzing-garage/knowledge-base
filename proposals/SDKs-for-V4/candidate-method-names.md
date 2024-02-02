# Candidate method names

## Mapping

| Existing name | Canonical Name | Return values | Smells |
|---------------|----------------|---------------|--------|
| G2ConfigMgr_addConfig(configStr, configComments, configID) | addConfig(configStr, configComments) | int64 |
| G2ConfigMgr_clearLastException() | [not-public] | |
| G2ConfigMgr_destroy() | | |
| G2ConfigMgr_getConfig(configID, responseBuf, bufSize, resizeFunc) | getConfig(configID) | string |
| G2ConfigMgr_getConfigList(responseBuf, bufSize, resizeFunc) | getConfigList() | string |
| G2ConfigMgr_getDefaultConfigID(configID) | getDefaultConfigID() | int64 |
| G2ConfigMgr_getLastException(buffer, bufSize) | [not-public] | |
| G2ConfigMgr_getLastExceptionCode() | [not-public] | |
| G2ConfigMgr_init(moduleName, iniParams, verboseLogging) | | |
| G2ConfigMgr_replaceDefaultConfigID(oldConfigID, newConfigID) | | |
| G2ConfigMgr_setDefaultConfigID(configID) | | |
| G2Config_addDataSource(configHandle, inputJson, responseBuf, bufSize, resizeFunc) | addDataSource(configHandle, inputJson) | string |
| G2Config_clearLastException() | [not-public] | |
| G2Config_close(configHandle) | | |
| G2Config_create(configHandle) | create() | configHandle |
| G2Config_deleteDataSource(configHandle, inputJson) | | |
| G2Config_destroy() | | |
| G2Config_getLastException(buffer, bufSize) | [not-public] | |
| G2Config_getLastExceptionCode() | [not-public] | |
| G2Config_init(moduleName, iniParams, verboseLogging) | | |
| G2Config_listDataSources(configHandle, responseBuf, bufSize, resizeFunc) | listDataSources(configHandle) | string |
| G2Config_load(jsonConfig, configHandle) | load(jsonConfig) | configHandle |
| G2Config_save(configHandle, responseBuf, bufSize, resizeFunc) | save(configHandle)  | string |
| G2Diagnostic_checkDBPerf(secondsToRun, responseBuf, bufSize, resizeFunc) | checkDBPerf(secondsToRun) | string |
| G2Diagnostic_clearLastException() | [not-public] | |
| G2Diagnostic_closeEntityListBySize(EntityListBySizeHandle entityListBySizeHandle) | [not-implemented]  | |
| G2Diagnostic_destroy() | | |
| G2Diagnostic_fetchNextEntityBySize(entityListBySizeHandle, responseBuf, bufSize) | [not-implemented] | |
| G2Diagnostic_findEntitiesByFeatureIDs(features, responseBuf, bufSize, resizeFunc) | [not-implemented] | |
| G2Diagnostic_getAvailableMemory() | | int64 |
| G2Diagnostic_getDBInfo(responseBuf, bufSize, resizeFunc) | getDBInfo() | string |
| G2Diagnostic_getDataSourceCounts(responseBuf, bufSize, resizeFunc) | [not-implemented] | |
| G2Diagnostic_getEntityDetails(entityID, includeInternalFeatures, responseBuf, bufSize, resizeFunc) | [not-implemented] | |
| G2Diagnostic_getEntityListBySize(entitySize, entityListBySizeHandle) | [not-implemented] | |
| G2Diagnostic_getEntityResume(entityID, responseBuf, bufSize, resizeFunc) | [not-implemented] | |
| G2Diagnostic_getEntitySizeBreakdown(minimumEntitySize, includeInternalFeatures, responseBuf, bufSize, resizeFunc) | [not-implemented] | |
| G2Diagnostic_getFeature(libFeatID, responseBuf, bufSize, resizeFunc) | [not-implemented] | |
| G2Diagnostic_getGenericFeatures(featureType, maximumEstimatedCount, responseBuf, bufSize, resizeFunc) | [not-implemented] | |
| G2Diagnostic_getLastException(buffer, bufSize) | [not-public] | |
| G2Diagnostic_getLastExceptionCode() | [not-public] | |
| G2Diagnostic_getLogicalCores() | | int |
| G2Diagnostic_getMappingStatistics(includeInternalFeatures, responseBuf, bufSize, resizeFunc) | [not-implemented] | |
| G2Diagnostic_getPhysicalCores() | | int |
| G2Diagnostic_getRelationshipDetails(relationshipID, includeInternalFeatures, responseBuf, bufSize, resizeFunc) | [not-implemented] | |
| G2Diagnostic_getResolutionStatistics(responseBuf, bufSize, resizeFunc) | [not-implemented] | |
| G2Diagnostic_getTotalSystemMemory() | | int64 |
| G2Diagnostic_init(moduleName, iniParams, verboseLogging) | | |
| G2Diagnostic_initWithConfigID(moduleName, iniParams, initConfigID, verboseLogging) | | |
| G2Diagnostic_reinit(initConfigID) | | |
| G2Product_clearLastException() | [not-public] | |
| G2Product_destroy() | | |
| G2Product_getLastException(buffer, bufSize) | [not-public] | |
| G2Product_getLastExceptionCode() | [not-public]| |
| G2Product_init(moduleName, iniParams, verboseLogging) | | |
| G2Product_license() | | string | Smell-1 |
| G2Product_validateLicenseFile(licenseFilePath, errorBuf, errorBufSize, resizeFunc) | [not-implemented] | |
| G2Product_validateLicenseStringBase64(licenseString, errorBuf, errorBufSize, resizeFunc) | [not-implemented] | |
| G2Product_version() | | string | Smell-1 |
| G2_addRecord(dataSourceCode, recordID, jsonData, loadID) | | |
| G2_addRecordWithInfo(dataSourceCode, recordID, jsonData, loadID, flags, responseBuf, bufSize, resizeFunc) |  addRecordAndReturnInfo(dataSourceCode, recordID, jsonData, loadID, flags) | string |
| G2_addRecordWithInfoWithReturnedRecordID(dataSourceCode, jsonData, loadID, flags, recordIDBuf, recordIDBufSize, responseBuf, responseBufSize, resizeFunc) | [not-implemented] | |
| G2_addRecordWithReturnedRecordID(dataSourceCode, jsonData, loadID, recordIDBuf, bufSize) | [not-implemented] | |
| G2_checkRecord(record, recordQueryList, responseBuf, bufSize, resizeFunc ) | [not-implemented] | |
| G2_clearLastException() | [not-public] | |
| G2_closeExport(responseHandle) | | |
| G2_countRedoRecords() | | int64 |
| G2_deleteRecord(dataSourceCode, recordID, loadID) | | |
| G2_deleteRecordWithInfo(dataSourceCode, recordID, loadID, flags, responseBuf, bufSize, resizeFunc) | deleteRecordAndReturnInfo(dataSourceCode, recordID, loadID, flags) | string |
| G2_destroy() | | |
| G2_exportCSVEntityReport(csvColumnList, flags, responseHandle) | exportCSVEntityReport(csvColumnList, flags) | responseHandle |
| G2_exportConfig(responseBuf, bufSize, resizeFunc) | exportConfig() | string |
| G2_exportConfigAndConfigID(responseBuf, bufSize, resizeFunc, configID) | exportConfigAndConfigID() | string, int64 |
| G2_exportJSONEntityReport(flags, responseHandle) | exportJSONEntityReport(flags) | responseHandle |
| G2_fetchNext(responseHandle, responseBuf, bufSize) | fetchNext(responseHandle)  | string |
| G2_findInterestingEntitiesByEntityID(entityID, flags, responseBuf, bufSize, resizeFunc) | findInterestingEntitiesByEntityID(entityID, flags) | string |
| G2_findInterestingEntitiesByRecordID(dataSourceCode, recordID, flags, responseBuf, bufSize, resizeFunc) | findInterestingEntitiesByRecordID(dataSourceCode, recordID, flags) | string |
| G2_findNetworkByEntityID(entityList, maxDegree, buildOutDegree, maxEntities, responseBuf, bufSize, resizeFunc) | findNetworkByEntityID(entityList, maxDegree, buildOutDegree, maxEntities, flags)  | string |
| G2_findNetworkByEntityID_V2(entityList, maxDegree, buildOutDegree, maxEntities, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | |
| G2_findNetworkByRecordID(recordList, maxDegree, buildOutDegree, maxEntities, responseBuf, bufSize, resizeFunc) | findNetworkByRecordID(recordList, maxDegree, buildOutDegree, maxEntities, flags) | string |
| G2_findNetworkByRecordID_V2(recordList, maxDegree, buildOutDegree, maxEntities, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | |
| G2_findPathByEntityID(entityID1, entityID2, maxDegree, responseBuf, bufSize, resizeFunc) | findPathByEntityID(entityID1, entityID2, maxDegree, flags) | string |
| G2_findPathByEntityID_V2(entityID1, entityID2, maxDegree, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | |
| G2_findPathByRecordID(dataSourceCode1, recordID1, dataSourceCode2, recordID2, maxDegree, responseBuf, bufSize, resizeFunc) | findPathByRecordID(dataSourceCode1, recordID1, dataSourceCode2, recordID2, maxDegree, flags) | string |
| G2_findPathByRecordID_V2(dataSourceCode1, recordID1, dataSourceCode2, recordID2, maxDegree, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | |
| G2_findPathExcludingByEntityID(entityID1, entityID2, maxDegree, excludedEntities, responseBuf, bufSize, resizeFunc) | findPathExcludingByEntityID(entityID1, entityID2, maxDegree, excludedEntities, flags) | string |
| G2_findPathExcludingByEntityID_V2(entityID1, entityID2, maxDegree, excludedEntities, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | |
| G2_findPathExcludingByRecordID(dataSourceCode1, recordID1, dataSourceCode2, recordID2, maxDegree, excludedRecords, responseBuf, bufSize, resizeFunc) | findPathExcludingByRecordID(dataSourceCode1, recordID1, dataSourceCode2, recordID2, maxDegree, excludedRecords, flags) | string |
| G2_findPathExcludingByRecordID_V2(dataSourceCode1, recordID1, dataSourceCode2, recordID2, maxDegree, excludedRecords, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | |
| G2_findPathIncludingSourceByEntityID(entityID1, entityID2, maxDegree, excludedEntities, requiredDsrcs, responseBuf, bufSize, resizeFunc) | findPathIncludingSourceByEntityID(entityID1, entityID2, maxDegree, excludedEntities, requiredDsrcs, flags) | string |
| G2_findPathIncludingSourceByEntityID_V2(entityID1, entityID2, maxDegree, excludedEntities, requiredDsrcs, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | |
| G2_findPathIncludingSourceByRecordID(dataSourceCode1, recordID1, dataSourceCode2, recordID2, maxDegree, excludedRecords, requiredDsrcs, responseBuf, bufSize, resizeFunc) | findPathIncludingSourceByRecordID(dataSourceCode1, recordID1, dataSourceCode2, recordID2, maxDegree, excludedRecords, requiredDsrcs, flags) | string |
| G2_findPathIncludingSourceByRecordID_V2(dataSourceCode1, recordID1, dataSourceCode2, recordID2, maxDegree, excludedRecords, requiredDsrcs, flags, responseBuf, bufSize, esizeFunc) | [collapsed] | |
| G2_getActiveConfigID(configID) | | int64 |
| G2_getEntityByEntityID(entityID, responseBuf, bufSize, resizeFunc) | getEntityByEntityID(entityID, flags) | string |
| G2_getEntityByEntityID_V2(entityID, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | |
| G2_getEntityByRecordID(dataSourceCode, recordID, responseBuf, bufSize, resizeFunc) | getEntityByRecordID(dataSourceCode, recordID, flags) | string |
| G2_getEntityByRecordID_V2(dataSourceCode, recordID, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | |
| G2_getLastException(buffer, bufSize) | [not-public] | |
| G2_getLastExceptionCode() | [not-public] | |
| G2_getRecord(dataSourceCode, recordID, responseBuf, bufSize, resizeFunc) | getRecord(dataSourceCode, recordID, flags) | string |
| G2_getRecord_V2(dataSourceCode, recordID, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | |
| G2_getRedoRecord(responseBuf, bufSize, resizeFunc ) | getRedoRecord() | string |
| G2_getRepositoryLastModifiedTime(lastModifiedTime) | getRepositoryLastModifiedTime()  | int64 |
| G2_getVirtualEntityByRecordID(recordList, responseBuf, bufSize, resizeFunc) | getVirtualEntityByRecordID(recordList, flags) | string |
| G2_getVirtualEntityByRecordID_V2(recordList, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | |
| G2_howEntityByEntityID(entityID, responseBuf, bufSize, resizeFunc) | howEntityByEntityID(entityID, flags) | string | Smell-1 |
| G2_howEntityByEntityID_V2(entityID, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | | Smell-1 |
| G2_init(moduleName, iniParams, verboseLogging) | | |
| G2_initWithConfigID(moduleName, iniParams, initConfigID, verboseLogging) | | |
| G2_primeEngine() | | |
| G2_process(record) | | |
| G2_processRedoRecord(responseBuf, bufSize, resizeFunc ) | [not-implemented] | |
| G2_processRedoRecordWithInfo(flags, responseBuf, bufSize, infoBuf, infoBufSize, resizeFunc) | [not-implemented] | |
| G2_processWithInfo(record, flags, responseBuf, bufSize, resizeFunc) | processAndReturnInfo(record, flags)  | string |
| G2_processWithResponse(record, responseBuf, bufSize) | [not-implemented] | |
| G2_processWithResponseResize(record, responseBuf, bufSize, resizeFunc ) | [not-implemented] | |
| G2_purgeRepository() | [moved to G2Diagnostic] | |
| G2_reevaluateEntity(entityID, flags) | | |
| G2_reevaluateEntityWithInfo(entityID, flags, responseBuf, bufSize, resizeFunc) | reevaluateEntityAndReturnInfo(entityID, flags) | string |
| G2_reevaluateRecord(dataSourceCode, recordID, flags) | | |
| G2_reevaluateRecordWithInfo(dataSourceCode, recordID, flags, responseBuf, bufSize, resizeFunc) | reevaluateRecordAndReturnInfo(dataSourceCode, recordID, flags) | string |
| G2_reinit(initConfigID) | | |
| G2_replaceRecord(dataSourceCode, recordID, jsonData, loadID) | | |
| G2_replaceRecordWithInfo(dataSourceCode, recordID, jsonData, loadID, flags, responseBuf, bufSize, resizeFunc) | replaceRecordAndReturnInfo(dataSourceCode, recordID, jsonData, loadID, flags) | string |
| G2_searchByAttributes(jsonData, responseBuf, bufSize, resizeFunc) | searchByAttributes(jsonData, searchProfile, flags) | string |
| G2_searchByAttributes_V2(jsonData, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | |
| G2_searchByAttributes_V3(jsonData, searchProfile, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | |
| G2_stats(responseBuf, bufSize, resizeFunc ) | | string | Smell-1 |
| G2_whyEntities(entityID1, entityID2, responseBuf, bufSize, resizeFunc) | whyEntities(entityID1, entityID2, flags) | string | Smell-1 |
| G2_whyEntities_V2(entityID1, entityID2, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | |
| G2_whyEntityByEntityID(entityID, responseBuf, bufSize, resizeFunc) | whyEntityByEntityID(entityID, flags) | string | Smell-1 |
| G2_whyEntityByEntityID_V2(entityID, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | |
| G2_whyEntityByRecordID(dataSourceCode, recordID, responseBuf, bufSize, resizeFunc) | whyEntityByRecordID(dataSourceCode, recordID, flags) | string | Smell-1 |
| G2_whyEntityByRecordID_V2(dataSourceCode, recordID, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | |
| G2_whyRecordInEntity(dataSourceCode, recordID, responseBuf, bufSize, resizeFunc) | whyRecordInEntity(dataSourceCode, recordID, flags) | string | Smell-1 |
| G2_whyRecordInEntity_V2(dataSourceCode, recordID, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | |
| G2_whyRecords(dataSourceCode1, recordID1, dataSourceCode2, recordID2, responseBuf, bufSize, resizeFunc) | whyRecords(dataSourceCode1, recordID1, dataSourceCode2, recordID2, flags) | string | Smell-1 |
| G2_whyRecords_V2(dataSourceCode1, recordID1, dataSourceCode2, recordID2, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | |


## Smells

1. Smell-1: Function naming.  For consistency, say the phrase "To *method-name".  If it sounds awkward, consider renaming the method.
   1. Good: "To `getVirtualEntityByRecordID()`", "To `addRecordAndReturnInfo()`"
   1. Bad: "To `howEntityByEntityID()`", "To `version()`"
