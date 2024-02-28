# Candidate method names

This is the full list of Senzing C APIs mapped into Senzing SDK APIs.
The
[canonical names condensed](canonical-names-condensed.md)
list factors out `not-public`, `not-implemented`,  and `collapsed` entries.

## Mapping

### G2Config

| Existing name | Canonical Name | Return values | Smells |
|---------------|----------------|---------------|--------|
| G2Config_addDataSource(configHandle, inputJson, responseBuf, bufSize, resizeFunc) | addDataSource(configHandle, dataSourceDefinition) | string | |
| G2Config_clearLastException() | [not-public] | | |
| G2Config_close(configHandle) | | - | |
| G2Config_create(configHandle) | create() | configHandle | |
| G2Config_deleteDataSource(configHandle, inputJson) | deleteDataSource(configHandle, dataSourceCode) | - | ?? |
| G2Config_destroy() | | - | |
| G2Config_getLastException(buffer, bufSize) | [not-public] | | |
| G2Config_getLastExceptionCode() | [not-public] | | |
| G2Config_init(moduleName, iniParams, verboseLogging) | initialize(instanceName, settings, verboseLogging) | - | |
| G2Config_listDataSources(configHandle, responseBuf, bufSize, resizeFunc) | getDataSources(configHandle) | string | |
| G2Config_load(jsonConfig, configHandle) | load(configDefinition) | configHandle | |
| G2Config_save(configHandle, responseBuf, bufSize, resizeFunc) | save(configHandle)  | string | SM-4, ?? |

### G2ConfigMgr

| Existing name | Canonical Name | Return values | Smells |
|---------------|----------------|---------------|--------|
| G2ConfigMgr_addConfig(configStr, configComments, configID) | addConfig(configDefinition, configComments) | int64 | |
| G2ConfigMgr_clearLastException() | [not-public] | | |
| G2ConfigMgr_destroy() | | - | |
| G2ConfigMgr_getConfig(configID, responseBuf, bufSize, resizeFunc) | getConfig(configID) | string | |
| G2ConfigMgr_getConfigList(responseBuf, bufSize, resizeFunc) | getConfigList() | string | |
| G2ConfigMgr_getDefaultConfigID(configID) | getDefaultConfigID() | int64 | |
| G2ConfigMgr_getLastException(buffer, bufSize) | [not-public] | | |
| G2ConfigMgr_getLastExceptionCode() | [not-public] | | |
| G2ConfigMgr_init(moduleName, iniParams, verboseLogging) | initialize(instanceName, settings, verboseLogging) | - | |
| G2ConfigMgr_replaceDefaultConfigID(oldConfigID, newConfigID) | replaceDefaultConfigID(currentDefaultConfigID, newDefaultConfigID) | - | |
| G2ConfigMgr_setDefaultConfigID(configID) | | - | |

### G2Diagnostic

| Existing name | Canonical Name | Return values | Smells |
|---------------|----------------|---------------|--------|
| G2Diagnostic_checkDBPerf(secondsToRun, responseBuf, bufSize, resizeFunc) | checkDBPerf(secondsToRun) | string | |
| G2Diagnostic_clearLastException() | [not-public] | | |
| G2Diagnostic_destroy() | | - | |
| G2Diagnostic_getLastException(buffer, bufSize) | [not-public] | | |
| G2Diagnostic_getLastExceptionCode() | [not-public] | | |
| G2Diagnostic_init(moduleName, iniParams, verboseLogging) | initialize(instanceName, settings, verboseLogging, configID) | | `configID` can be `nil`, `None`, `null` |
| G2Diagnostic_initWithConfigID(moduleName, iniParams, initConfigID, verboseLogging) | [collapsed] | | |
| G2Diagnostic_purgeRepository(????) | | | |
| G2Diagnostic_reinit(initConfigID) | reInitialize(configID) | - | |

### G2Engine

| Existing name | Canonical Name | Return values | Smells |
|---------------|----------------|---------------|--------|
| G2_addRecord(dataSourceCode, recordID, jsonData) | addRecord(dataSourceCode, recordID, recordDefinition, flags) | string | |
| G2_addRecordWithInfo(dataSourceCode, recordID, jsonData, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | | |
| G2_clearLastException() | [not-public] | | |
| G2_closeExport(responseHandle) | closeExport(exportHandle) | - | |
| G2_countRedoRecords() | | int64 | |
| G2_deleteRecord(dataSourceCode, recordID) | deleteRecord(dataSourceCode, recordID, flags) | string | |
| G2_deleteRecordWithInfo(dataSourceCode, recordID, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | | |
| G2_destroy() | | - | |
| G2_exportCSVEntityReport(csvColumnList, flags, responseHandle) | exportCSVEntityReport(csvColumnList, flags) | exportHandle | |
| G2_exportConfig(responseBuf, bufSize, resizeFunc) | getActiveConfig() | string | |
| G2_exportConfigAndConfigID(responseBuf, bufSize, resizeFunc, configID) |  [not-implemented] ??? | string, int64 | SM-5 |
| G2_exportJSONEntityReport(flags, responseHandle) | exportJSONEntityReport(flags) | exportHandle | |
| G2_fetchNext(responseHandle, responseBuf, bufSize) | fetchNext(exportHandle)  | string | |
| G2_findInterestingEntitiesByEntityID(entityID, flags, responseBuf, bufSize, resizeFunc) | findInterestingEntitiesByEntityID(entityID, flags) | string | SM-3.1 |
| G2_findInterestingEntitiesByRecordID(dataSourceCode, recordID, flags, responseBuf, bufSize, resizeFunc) | findInterestingEntitiesByRecordID(dataSourceCode, recordID, flags) | string | SM-3.1 |
| G2_findNetworkByEntityID(entityList, maxDegree, buildOutDegree, maxEntities, responseBuf, bufSize, resizeFunc) | findNetworkByEntityID(entityList, maxDegrees, buildOutDegree, maxEntities, flags)  | string | SM-3.1 |
| G2_findNetworkByEntityID_V2(entityList, maxDegree, buildOutDegree, maxEntities, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | | |
| G2_findNetworkByRecordID(recordList, maxDegree, buildOutDegree, maxEntities, responseBuf, bufSize, resizeFunc) | findNetworkByRecordID(recordList, maxDegrees, buildOutDegree, maxEntities, flags) | string | SM-3.1 |
| G2_findNetworkByRecordID_V2(recordList, maxDegree, buildOutDegree, maxEntities, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | | |
| G2_findPathByEntityID(entityID1, entityID2, maxDegree, responseBuf, bufSize, resizeFunc) | findPathByEntityID(startEntityID, endEntityID, maxDegrees, exclusions, requiredDataSources, flags) | string | SM-3.1 |
| G2_findPathByEntityID_V2(entityID1, entityID2, maxDegree, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | | |
| G2_findPathByRecordID(dataSourceCode1, recordID1, dataSourceCode2, recordID2, maxDegree, responseBuf, bufSize, resizeFunc) | findPathByRecordID(startDataSourceCode, startRecordID, endDataSourceCode, endRecordID, maxDegrees, exclusions, requiredDataSources, flags) | string | SM-3.1 |
| G2_findPathByRecordID_V2(dataSourceCode1, recordID1, dataSourceCode2, recordID2, maxDegree, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | | |
| G2_findPathExcludingByEntityID(entityID1, entityID2, maxDegree, excludedEntities, responseBuf, bufSize, resizeFunc) |  [collapsed]  | | |
| G2_findPathExcludingByEntityID_V2(entityID1, entityID2, maxDegree, excludedEntities, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | | |
| G2_findPathExcludingByRecordID(dataSourceCode1, recordID1, dataSourceCode2, recordID2, maxDegree, excludedRecords, responseBuf, bufSize, resizeFunc) | [collapsed] | | |
| G2_findPathExcludingByRecordID_V2(dataSourceCode1, recordID1, dataSourceCode2, recordID2, maxDegree, excludedRecords, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | | |
| G2_findPathIncludingSourceByEntityID(entityID1, entityID2, maxDegree, excludedEntities, requiredDsrcs, responseBuf, bufSize, resizeFunc) |  [collapsed]  | |  |
| G2_findPathIncludingSourceByEntityID_V2(entityID1, entityID2, maxDegree, excludedEntities, requiredDsrcs, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | | |
| G2_findPathIncludingSourceByRecordID(dataSourceCode1, recordID1, dataSourceCode2, recordID2, maxDegree, excludedRecords, requiredDsrcs, responseBuf, bufSize, resizeFunc |  [collapsed]  | | |
| G2_findPathIncludingSourceByRecordID_V2(dataSourceCode1, recordID1, dataSourceCode2, recordID2, maxDegree, excludedRecords, requiredDsrcs, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | | |
| G2_getActiveConfigID(configID) | getActiveConfigID() | int64 | |
| G2_getEntityByEntityID(entityID, responseBuf, bufSize, resizeFunc) | getEntityByEntityID(entityID, flags) | string | |
| G2_getEntityByEntityID_V2(entityID, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | | |
| G2_getEntityByRecordID(dataSourceCode, recordID, responseBuf, bufSize, resizeFunc) | getEntityByRecordID(dataSourceCode, recordID, flags) | string | |
| G2_getEntityByRecordID_V2(dataSourceCode, recordID, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | | |
| G2_getLastException(buffer, bufSize) | [not-public] | | |
| G2_getLastExceptionCode() | [not-public] | | |
| G2_getRecord(dataSourceCode, recordID, responseBuf, bufSize, resizeFunc) | getRecord(dataSourceCode, recordID, flags) | string | |
| G2_getRecord_V2(dataSourceCode, recordID, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | | |
| G2_getRedoRecord(responseBuf, bufSize, resizeFunc ) | getRedoRecord() | string | |
| G2_getRepositoryLastModifiedTime(lastModifiedTime) | getRepositoryLastModifiedTime()  | int64 | |
| G2_getVirtualEntityByRecordID(recordList, responseBuf, bufSize, resizeFunc) | getVirtualEntityByRecordID(recordList, flags) | string | |
| G2_getVirtualEntityByRecordID_V2(recordList, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | | |
| G2_howEntityByEntityID(entityID, responseBuf, bufSize, resizeFunc) | howEntityByEntityID(entityID, flags) | string | SM-1, SM-3.3 |
| G2_howEntityByEntityID_V2(entityID, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | | |
| G2_init(moduleName, iniParams, verboseLogging) | initialize(instanceName, settings, verboseLogging, configID) | - | `configID` can be `nil`, `None`, `null` |
| G2_initWithConfigID(moduleName, iniParams, initConfigID, verboseLogging) | [collapsed]  | | |
| G2_primeEngine() | | - | |
| G2_processRedoRecord(responseBuf, bufSize, resizeFunc ) | TBD | | |
| G2_processRedoRecordWithInfo(flags, responseBuf, bufSize, infoBuf, infoBufSize, resizeFunc) | TBD | | |
| G2_reevaluateEntity(entityID, flags) | reevaluateEntity(entityID, flags) | string | `flags` has `WITH_INFO` bit |
| G2_reevaluateEntityWithInfo(entityID, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | string | |
| G2_reevaluateRecord(dataSourceCode, recordID, flags) | reevaluateRecord(dataSourceCode, recordID, flags) | string | `flags` has `WITH_INFO` bit |
| G2_reevaluateRecordWithInfo(dataSourceCode, recordID, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | | |
| G2_reinit(initConfigID) | reInitialize(configID) | - | |
| G2_replaceRecord(dataSourceCode, recordID, jsonData) | replaceRecord(dataSourceCode, recordID, recordDefinition, flags) | string | |
| G2_replaceRecordWithInfo(dataSourceCode, recordID, jsonData, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | | |
| G2_searchByAttributes(jsonData, responseBuf, bufSize, resizeFunc) | searchByAttributes(searchCriteria, searchProfile, flags) | string | |
| G2_searchByAttributes_V2(jsonData, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | | |
| G2_searchByAttributes_V3(jsonData, searchProfile, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | | |
| G2_stats(responseBuf, bufSize, resizeFunc ) | getStats() | string | |
| G2_whyEntities(entityID1, entityID2, responseBuf, bufSize, resizeFunc) | whyEntities(entityID1, entityID2, flags) | string | SM-1, SM-3.3 |
| G2_whyEntities_V2(entityID1, entityID2, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | | |
| G2_whyRecordInEntity(dataSourceCode, recordID, responseBuf, bufSize, resizeFunc) | whyRecordInEntity(dataSourceCode, recordID, flags) | string | SM-1, SM-3.3 |
| G2_whyRecordInEntity_V2(dataSourceCode, recordID, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | | |
| G2_whyRecords(dataSourceCode1, recordID1, dataSourceCode2, recordID2, responseBuf, bufSize, resizeFunc) | whyRecords(dataSourceCode1, recordID1, dataSourceCode2, recordID2, flags) | string | SM-1, SM-3.3 |
| G2_whyRecords_V2(dataSourceCode1, recordID1, dataSourceCode2, recordID2, flags, responseBuf, bufSize, resizeFunc) | [collapsed] | | |

### G2Product

| Existing name | Canonical Name | Return values | Smells |
|---------------|----------------|---------------|--------|
| G2Product_clearLastException() | [not-public] | | |
| G2Product_destroy() | | - | |
| G2Product_getLastException(buffer, bufSize) | [not-public] | | |
| G2Product_getLastExceptionCode() | [not-public]| | |
| G2Product_init(moduleName, iniParams, verboseLogging) | initialize(instanceName, settings, verboseLogging) | - | |
| G2Product_license() | getLicense() | string | |
| G2Product_validateLicenseFile(licenseFilePath, errorBuf, errorBufSize, resizeFunc) | [not-implemented] | | |
| G2Product_validateLicenseStringBase64(licenseString, errorBuf, errorBufSize, resizeFunc) | [not-implemented] | | |
| G2Product_version() | getVersion() | string | |

## Method signature proposals

### Handling WithInfo - Proposal 1

1. Functions affected:
   - G2_addRecordWithInfo
   - G2_deleteRecordWithInfo
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
         info = g2_engine.add_record(dataSourceCode, recordID, record, resultFlags)
         ```

   1. If `resultFlags` is 0 (i.e. no bit flags are on) then the returned value is `{}`, an empty JSON string.
   1. Beneath the covers, the SDK determines if the `WITH_INFO` bit is **off**, in which case it calls `G2_addRecord`.
      If the `WITH_INFO` bit is **on**, the SDK calls `G2_addRecordWithInfo`.
   1. Flag can be OR-ed for future expansion. Example:

         ```python
         info = g2_engine.add_record(dataSourceCode, recordID, record, WITH_INFO | WITHOUT_SOMETHING_ELSE)
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
         g2_engine.add_record(dataSourceCode, recordID, record)
         ```

         ```python
         info = g2_engine.add_record(dataSourceCode, recordID, record, resultFlags)
         ```

   1. Java language specifics:
      1. Use method overloading to factor out the `resultFlags` parameter.
      1. Examples of use:

         ```java
         g2Engine.addRecord(dataSourceCode, recordID, record)
         ```

         ```java
         info = g2Engine.addRecord(dataSourceCode, recordID, record, WITH_INFO)
         ```

   1. Go language specifics:
      1. Go doesn't have optional parameters nor method overloading.
      1. Examples of use:

         ```go
         _, err := g2Engine.AddRecord(dataSourceCode, recordID, record, g2api.WITHOUT_INFO)
         ```

         ```go
         info, err := g2Engine.AddRecord(dataSourceCode, recordID, record, g2api.WITH_INFO)
         ```

## Smells

1. SM-1: Function naming.  For consistency, say the phrase "To *method-name*".  If it sounds awkward, consider renaming the method.
   1. Good: "To `getVirtualEntityByRecordID()`", "To `addRecordAndReturnInfo()`"
   1. Bad: "To `howEntityByEntityID()`", "To `version()`"
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
