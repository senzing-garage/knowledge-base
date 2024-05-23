# Candidate method names

This is the full list of Senzing C APIs mapped into Senzing SDK APIs.
The
[canonical names condensed](canonical-names-condensed.md)
list factors out `not-public`, `not-implemented`,  and `collapsed` entries.

## Mapping

### SzConfig

| Existing name | Canonical Name | Return value | Smells |
|---------------|----------------|--------------|--------|
| G2Config_addDataSource(configHandle, inputJson, responseBuf, bufSize, resizeFunc) | addDataSource(configHandle, dataSourceCode) | string | |
| G2Config_clearLastException() | [not-public] | | |
| G2Config_close(configHandle) | closeConfig(configHandle) | - | |
| G2Config_create(configHandle) | createConfig() | configHandle | |
| G2Config_deleteDataSource(configHandle, inputJson) | deleteDataSource(configHandle, dataSourceCode) | - | |
| G2Config_destroy() | | - | |
| G2Config_getLastException(buffer, bufSize) | [not-public] | | |
| G2Config_getLastExceptionCode() | [not-public] | | |
| G2Config_init(moduleName, iniParams, verboseLogging) | initialize(instanceName, settings, verboseLogging) | - | Consider single object |
| G2Config_listDataSources(configHandle, responseBuf, bufSize, resizeFunc) | getDataSources(configHandle) | string | |
| G2Config_load(jsonConfig, configHandle) | importConfig(configDefinition) | configHandle | |
| G2Config_save(configHandle, responseBuf, bufSize, resizeFunc) | exportConfig(configHandle)  | string | |

### SzConfigManager

| Existing name | Canonical Name | Return value | Smells |
|---------------|----------------|--------------|--------|
| G2ConfigMgr_addConfig(configStr, configComment, configID) | addConfig(configDefinition, configComment) | int64 | |
| G2ConfigMgr_clearLastException() | [not-public] | | |
| G2ConfigMgr_destroy() | | - | |
| G2ConfigMgr_getConfig(configID, responseBuf, bufSize, resizeFunc) | getConfig(configId) | string | |
| G2ConfigMgr_getConfigList(responseBuf, bufSize, resizeFunc) | getConfigs() | string | |
| G2ConfigMgr_getDefaultConfigID(configID) | getDefaultConfigId() | int64 | |
| G2ConfigMgr_getLastException(buffer, bufSize) | [not-public] | | |
| G2ConfigMgr_getLastExceptionCode() | [not-public] | | |
| G2ConfigMgr_init(moduleName, iniParams, verboseLogging) | initialize(instanceName, settings, verboseLogging) | - | Consider single object |
| G2ConfigMgr_replaceDefaultConfigID(oldConfigID, newConfigID) | replaceDefaultConfigId(currentDefaultConfigId, newDefaultConfigId) | - | |
| G2ConfigMgr_setDefaultConfigID(configID) | setDefaultConfigId(configId) | - | |

### SzDiagnostic

| Existing name | Canonical Name | Return value | Smells |
|---------------|----------------|--------------|--------|
| G2Diagnostic_checkDBPerf(secondsToRun, responseBuf, bufSize, resizeFunc) | checkDatastorePerformance(secondsToRun) | string | |
| G2Diagnostic_clearLastException() | [not-public] | | |
| G2Diagnostic_destroy() | | - | |
| G2Diagnostic_getDatastoreInfo(responseBuf, bufSize, resizeFunc) | getDatastoreInfo() | string | |
| G2Diagnostic_getFeature(libFeatID, responseBuf, bufSize, resizeFunc) | getFeature(featureId) | string | ** Not approved yet |
| G2Diagnostic_getLastException(buffer, bufSize) | [not-public] | | |
| G2Diagnostic_getLastExceptionCode() | [not-public] | | |
| G2Diagnostic_init(moduleName, iniParams, verboseLogging) | initialize(instanceName, settings, configId, verboseLogging) | | `configId` can be `nil`, `None`, `null`. Consider single object |
| G2Diagnostic_initWithConfigID(moduleName, iniParams, initConfigID, verboseLogging) | [collapsed] | | |
| G2Diagnostic_purgeRepository(????) | purgeRepository(????) | | |
| G2Diagnostic_reinit(initConfigID) | reinitialize(configId) | - | |

### SzEngine

| Existing name | Canonical Name | Return value | Smells |
|---------------|----------------|--------------|--------|
| G2_addRecord(dataSourceCode, recordID, jsonData) | addRecord(dataSourceCode, recordId, recordDefinition, flags) | string | |
| G2_addRecordWithInfo(dataSourceCode, recordID, jsonData, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | | |
| G2_clearLastException() | [not-public] | | |
| G2_closeExport(responseHandle) | closeExport(exportHandle) | - | |
| G2_countRedoRecords() | | int64 | |
| G2_deleteRecord(dataSourceCode, recordID) | deleteRecord(dataSourceCode, recordId, flags) | string | |
| G2_deleteRecordWithInfo(dataSourceCode, recordID, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | | |
| G2_destroy() | | - | |
| G2_exportCSVEntityReport(csvColumnList, flags, responseHandle) | exportCsvEntityReport(csvColumnList, flags) | exportHandle | |
| G2_exportConfig(responseBuf, bufSize, resizeFunc) | [not-implemented] | | |
| G2_exportConfigAndConfigID(responseBuf, bufSize, resizeFunc, configID) | [not-implemented] | | |
| G2_exportJSONEntityReport(flags, responseHandle) | exportJsonEntityReport(flags) | exportHandle | |
| G2_fetchNext(responseHandle, responseBuf, bufSize) | fetchNext(exportHandle)  | string | |
| G2_findInterestingEntitiesByEntityID(entityID, flags, responseBuf, bufSize, resizeFunc) | findInterestingEntitiesByEntityId(entityId, flags)  | string |  |
| G2_findInterestingEntitiesByRecordID(dataSourceCode, recordID, flags, responseBuf, bufSize, resizeFunc) | findInterestingEntitiesByRecordId(dataSourceCode, recordId, flags)  | string |  |
| G2_findNetworkByEntityID(entityList, maxDegree, buildOutDegree, maxEntities, responseBuf, bufSize, resizeFunc) | findNetworkByEntityId(entityIds, maxDegrees, buildOutDegree, buildOutMaxEntities, flags)  | string | SM-3.1 |
| G2_findNetworkByEntityID_V2(entityList, maxDegree, buildOutDegree, maxEntities, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | | |
| G2_findNetworkByRecordID(recordList, maxDegree, buildOutDegree, maxEntities, responseBuf, bufSize, resizeFunc) | findNetworkByRecordId(recordKeys, maxDegrees, buildOutDegree, buildOutMaxEntities, flags) | string | SM-3.1 |
| G2_findNetworkByRecordID_V2(recordList, maxDegree, buildOutDegree, maxEntities, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | | |
| G2_findPathByEntityID(entityID1, entityID2, maxDegree, responseBuf, bufSize, resizeFunc) | findPathByEntityId(startEntityId, endEntityId, maxDegrees, exclusions, requiredDataSources, flags) | string | SM-3.1 |
| G2_findPathByEntityID_V2(entityID1, entityID2, maxDegree, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | | |
| G2_findPathByRecordID(dataSourceCode1, recordID1, dataSourceCode2, recordID2, maxDegree, responseBuf, bufSize, resizeFunc) | findPathByRecordId(startDataSourceCode, startRecordId, endDataSourceCode, endRecordId, maxDegrees, exclusions, requiredDataSources, flags) | string | SM-3.1 |
| G2_findPathByRecordID_V2(dataSourceCode1, recordID1, dataSourceCode2, recordID2, maxDegree, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | | |
| G2_findPathExcludingByEntityID(entityID1, entityID2, maxDegree, excludedEntities, responseBuf, bufSize, resizeFunc) |  [collapsed]  | | |
| G2_findPathExcludingByEntityID_V2(entityID1, entityID2, maxDegree, excludedEntities, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | | |
| G2_findPathExcludingByRecordID(dataSourceCode1, recordID1, dataSourceCode2, recordID2, maxDegree, excludedRecords, responseBuf, bufSize, resizeFunc) | [collapsed] | | |
| G2_findPathExcludingByRecordID_V2(dataSourceCode1, recordID1, dataSourceCode2, recordID2, maxDegree, excludedRecords, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | | |
| G2_findPathIncludingSourceByEntityID(entityID1, entityID2, maxDegree, excludedEntities, requiredDsrcs, responseBuf, bufSize, resizeFunc) |  [collapsed]  | |  |
| G2_findPathIncludingSourceByEntityID_V2(entityID1, entityID2, maxDegree, excludedEntities, requiredDsrcs, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | | |
| G2_findPathIncludingSourceByRecordID(dataSourceCode1, recordID1, dataSourceCode2, recordID2, maxDegree, excludedRecords, requiredDsrcs, responseBuf, bufSize, resizeFunc |  [collapsed]  | | |
| G2_findPathIncludingSourceByRecordID_V2(dataSourceCode1, recordID1, dataSourceCode2, recordID2, maxDegree, excludedRecords, requiredDsrcs, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | | |
| G2_getActiveConfigID(configID) | getActiveConfigId() | int64 | |
| G2_getEntityByEntityID(entityID, responseBuf, bufSize, resizeFunc) | getEntityByEntityId(entityId, flags) | string | |
| G2_getEntityByEntityID_V2(entityID, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | | |
| G2_getEntityByRecordID(dataSourceCode, recordID, responseBuf, bufSize, resizeFunc) | getEntityByRecordId(dataSourceCode, recordId, flags) | string | |
| G2_getEntityByRecordID_V2(dataSourceCode, recordID, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | | |
| G2_getLastException(buffer, bufSize) | [not-public] | | |
| G2_getLastExceptionCode() | [not-public] | | |
| G2_getRecord(dataSourceCode, recordID, responseBuf, bufSize, resizeFunc) | getRecord(dataSourceCode, recordId, flags) | string | |
| G2_getRecord_V2(dataSourceCode, recordID, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | | |
| G2_getRedoRecord(responseBuf, bufSize, resizeFunc ) | getRedoRecord() | string | |
| G2_getRepositoryLastModifiedTime(lastModifiedTime) |  [not-implemented] | | |
| G2_getVirtualEntityByRecordID(recordList, responseBuf, bufSize, resizeFunc) | getVirtualEntityByRecordId(recordKeys, flags) | string | |
| G2_getVirtualEntityByRecordID_V2(recordList, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | | |
| G2_howEntityByEntityID(entityID, responseBuf, bufSize, resizeFunc) | howEntityByEntityId(entityId, flags) | string | SM-1, SM-3.3 |
| G2_howEntityByEntityID_V2(entityID, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | | |
| G2_init(moduleName, iniParams, verboseLogging) | initialize(instanceName, settings, configId, verboseLogging) | - | `configId` can be `nil`, `None`, `null`. Consider single object |
| G2_initWithConfigID(moduleName, iniParams, initConfigID, verboseLogging) | [collapsed]  | | |
| G2_primeEngine() | | - | |
| G2_processRedoRecord(responseBuf, bufSize, resizeFunc ) | processRedoRecord(redoRecord, flags) | string | |
| G2_processRedoRecordWithInfo(flags, responseBuf, bufSize, infoBuf, infoBufSize, resizeFunc) | [collapsed] | | |
| G2_reevaluateEntity(entityID, flags) | reevaluateEntity(entityId, flags) | string | `flags` has `WITH_INFO` bit |
| G2_reevaluateEntityWithInfo(entityID, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | string | |
| G2_reevaluateRecord(dataSourceCode, recordID, flags) | reevaluateRecord(dataSourceCode, recordId, flags) | string | `flags` has `WITH_INFO` bit |
| G2_reevaluateRecordWithInfo(dataSourceCode, recordID, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | | |
| G2_reinit(initConfigID) | reinitialize(configId) | - | ??? |
| G2_replaceRecord(dataSourceCode, recordID, jsonData) | [not-implemented] | string | |
| G2_replaceRecordWithInfo(dataSourceCode, recordID, jsonData, flags, responseBuf, bufSize, resizeFunc) | [not-implemented]  | | |
| G2_searchByAttributes(jsonData, responseBuf, bufSize, resizeFunc) | searchByAttributes(attributes, searchProfile, flags) | string | |
| G2_searchByAttributes_V2(jsonData, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | | |
| G2_searchByAttributes_V3(jsonData, searchProfile, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | | |
| G2_stats(responseBuf, bufSize, resizeFunc ) | getStats() | string | |
| G2_whyEntities(entityID1, entityID2, responseBuf, bufSize, resizeFunc) | whyEntities(entityId1, entityId2, flags) | string | SM-1, SM-3.3 |
| G2_whyEntities_V2(entityID1, entityID2, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | | |
| G2_whyRecordInEntity(dataSourceCode, recordID, responseBuf, bufSize, resizeFunc) | whyRecordInEntity(dataSourceCode, recordId, flags) | string | SM-1, SM-3.3 |
| G2_whyRecordInEntity_V2(dataSourceCode, recordID, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | | |
| G2_whyRecords(dataSourceCode1, recordID1, dataSourceCode2, recordID2, responseBuf, bufSize, resizeFunc) | whyRecords(dataSourceCode1, recordId1, dataSourceCode2, recordId2, flags) | string | SM-1, SM-3.3 |
| G2_whyRecords_V2(dataSourceCode1, recordID1, dataSourceCode2, recordID2, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | | |

### SzProduct

| Existing name | Canonical Name | Return value | Smells |
|---------------|----------------|--------------|--------|
| G2Product_clearLastException() | [not-public] | | |
| G2Product_destroy() | | - | |
| G2Product_getLastException(buffer, bufSize) | [not-public] | | |
| G2Product_getLastExceptionCode() | [not-public]| | |
| G2Product_init(moduleName, iniParams, verboseLogging) | initialize(instanceName, settings, verboseLogging) | - | |
| G2Product_license() | getLicense() | string | |
| G2Product_validateLicenseFile(licenseFilePath, errorBuf, errorBufSize, resizeFunc) | [not-implemented] | | |
| G2Product_validateLicenseStringBase64(licenseString, errorBuf, errorBufSize, resizeFunc) | ??? | | |
| G2Product_version() | getVersion() | string | |

## Abstract Factory

### SzAbstractFactory

| Existing name | Canonical Name | Return value | Smells |
|---------------|----------------|--------------|--------|
|| createSzConfig()         | [object conforming to SzConfig interface]         ||
|| createSzConfigManager()  | [object conforming to SzConfigManager interface]  ||
|| createSzDiagnostic()     | [object conforming to SzDiagnostic interface]     ||
|| createSzEngine()         | [object conforming to SzEngine interface]         ||
|| createSzProduct()        | [object conforming to SzProduct interface]        ||

## Method signature proposals

### Handling WithInfo - Proposal 1

1. Functions affected:
   - G2_addRecordWithInfo
   - G2_deleteRecordWithInfo
   - G2_processWithInfo
   - G2_reevaluateEntityWithInfo
   - G2_reevaluateRecordWithInfo
   - G2_replaceRecordWithInfo
1. Approach:
   1. Function name becomes shortened to match the non-with-info name (e.g. `G2_addRecord()`).
   1. The `xx_withInfo()` function/method signature is not in the SDK.
   1. Function always returns JSON string.
   1. A final input parameter, say `resultFlags` (int64 used as a bit-mask), indicates the nature of the content returned in the JSON string.
   1. Example:

         ```python
         info = engine.add_record(dataSourceCode, recordId, record, resultFlags)
         ```

   1. If `resultFlags` is 0 (i.e. no bit flags are on) then the returned value is `{}`, an empty JSON string.
   1. Beneath the covers, the SDK determines if the `WITH_INFO` bit is **off**, in which case it calls `G2_addRecord`.
      If the `WITH_INFO` bit is **on**, the SDK calls `G2_addRecordWithInfo`.
   1. Flag can be OR-ed for future expansion. Example:

         ```python
         info = engine.add_record(dataSourceCode, recordId, record, WITH_INFO | WITHOUT_SOMETHING_ELSE)
         ```

   1. Although flag arguments are not best practice,

      > Flag arguments are ugly.
        Passing a boolean into a function is a truly terrible practice.
        It immediately complicates the signature of the method, loudly proclaiming that this function does more than one thing.
        -- **("Clean Code", Chapter 3, "Flag Arguments")**

      given the desires for a single method name, multiple return values, and immutable input parameters, it's a reasonable compromise.
   1. Python language specifics:
      1. The definition of the python function can be

          ```python
         def add_record(
            data_source_code: str,
            record_id: str,
            record: str,
            resultFlags: int = 0,
            **kwargs: Any,
         ) -> str:
          ```

      1. Examples of use

         ```python
         engine.add_record(dataSourceCode, recordId, record)
         ```

         ```python
         info = engine.add_record(dataSourceCode, recordId, record, resultFlags)
         ```

   1. Java language specifics:
      1. Use method overloading to factor out the `resultFlags` parameter.
      1. Examples of use:

         ```java
         engine.addRecord(dataSourceCode, recordId, record)
         ```

         ```java
         info = engine.addRecord(dataSourceCode, recordId, record, WITH_INFO)
         ```

   1. Go language specifics:
      1. Go doesn't have optional parameters nor method overloading.
      1. Examples of use:

         ```go
         _, err := engine.AddRecord(dataSourceCode, recordId, record, szapi.WITHOUT_INFO)
         ```

         ```go
         info, err := engine.AddRecord(dataSourceCode, recordId, record, szapi.WITH_INFO)
         ```

## Smells

1. SM-1: Function naming.  For consistency, say the phrase "To *method-name*".  If it sounds awkward, consider renaming the method.
   1. Good: "To `getVirtualEntityByRecordId()`", "To `addRecordAndReturnInfo()`"
   1. Bad: "To `howEntityByEntityId()`", "To `version()`"
1. SM-2: Parameter naming. For portability across different programming languages, the parameter name shouldn't include a data-type.
   1. Good: `dataSourceSpec`
   1. Bad: `inputJson`
1. SM-3: Inconsistent function/method verbs
   1. SM-3.1 `find` instead of standard `get`
   1. SM-3.2 `list` instead of standard `get`
   1. SM-3.3 Non-verb (The "to" principle)
1. SM-4: Method name does not convey what is happening
1. SM-5: Multiple returns not supported in Java
1. SM-6: Can `resultFlags` be the high-order bits of `flags` and cleared out before sending to Senzing C API?
