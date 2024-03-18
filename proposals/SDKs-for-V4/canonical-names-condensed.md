# Candidate method names - condensed

To see the expanded version, visit
[canonical names](canonical-names.md).

## Mapping

### G2Config

| Existing name | Canonical Name | Return values | Smells |
|---------------|----------------|---------------|--------|
| G2Config_addDataSource(configHandle, inputJson, responseBuf, bufSize, resizeFunc) | addDataSource(configHandle, dataSourceCode) | | |
| G2Config_clearLastException() | [not-public] | | |
| G2Config_close(configHandle) | | - | |
| G2Config_create(configHandle) | create() | configHandle | |
| G2Config_deleteDataSource(configHandle, inputJson) | deleteDataSource(configHandle, dataSourceCode) | - | |
| G2Config_destroy() | | - | |
| G2Config_init(moduleName, iniParams, verboseLogging) | initialize(instanceName, settings, verboseLogging) | - | Consider single object |
| G2Config_listDataSources(configHandle, responseBuf, bufSize, resizeFunc) | getDataSources(configHandle) | string | |
| G2Config_load(jsonConfig, configHandle) | load(configDefinition) | configHandle | |
| G2Config_save(configHandle, responseBuf, bufSize, resizeFunc) | getJsonString(configHandle)  | string | |

### G2ConfigMgr

| Existing name | Canonical Name | Return values | Smells |
|---------------|----------------|---------------|--------|
| G2ConfigMgr_addConfig(configStr, configComments, configID) | addConfig(configDefinition, configComments) | int64 | |
| G2ConfigMgr_destroy() | | - | |
| G2ConfigMgr_getConfig(configID, responseBuf, bufSize, resizeFunc) | getConfig(configId) | string | |
| G2ConfigMgr_getConfigList(responseBuf, bufSize, resizeFunc) | getConfigList() | string | |
| G2ConfigMgr_getDefaultConfigID(configID) | getDefaultConfigId() | int64 | |
| G2ConfigMgr_init(moduleName, iniParams, verboseLogging) | initialize(instanceName, settings, verboseLogging) | - | Consider single object |
| G2ConfigMgr_replaceDefaultConfigID(oldConfigID, newConfigID) | replaceDefaultConfigId(currentDefaultConfigId, newDefaultConfigId) | - | |
| G2ConfigMgr_setDefaultConfigID(configID) | setDefaultConfigId(configId) | - | |

### G2Diagnostic

| Existing name | Canonical Name | Return values | Smells |
|---------------|----------------|---------------|--------|
| G2Diagnostic_checkDBPerf(secondsToRun, responseBuf, bufSize, resizeFunc) | checkDatabasePerformance(secondsToRun) | string | |
| G2Diagnostic_destroy() | | - | |
| G2Diagnostic_init(moduleName, iniParams, verboseLogging) | initialize(instanceName, settings, verboseLogging, configId) | | `configId` can be `nil`, `None`, `null`. Consider single object |
| G2Diagnostic_purgeRepository(????) | purgeRepository(????) | | |
| G2Diagnostic_reinit(initConfigID) | reinitialize(configId) | - | |

### G2Engine

| Existing name | Canonical Name | Return values | Smells |
|---------------|----------------|---------------|--------|
| G2_addRecord(dataSourceCode, recordID, jsonData) | addRecord(dataSourceCode, recordId, recordDefinition, flags) | string | |
| G2_closeExport(responseHandle) | closeExport(exportHandle) | - | |
| G2_countRedoRecords() | | int64 | |
| G2_deleteRecord(dataSourceCode, recordID) | deleteRecord(dataSourceCode, recordId, flags) | string | |
| G2_destroy() | | - | |
| G2_exportCSVEntityReport(csvColumnList, flags, responseHandle) | exportCsvEntityReport(csvColumnList, flags) | exportHandle | |
| G2_exportJSONEntityReport(flags, responseHandle) | exportJsonEntityReport(flags) | exportHandle | |
| G2_fetchNext(responseHandle, responseBuf, bufSize) | fetchNext(exportHandle)  | string | |
| G2_findNetworkByEntityID(entityList, maxDegree, buildOutDegree, maxEntities, responseBuf, bufSize, resizeFunc) | findNetworkByEntityId(entityList, maxDegrees, buildOutDegree, maxEntities, flags)  | string | SM-3.1 |
| G2_findNetworkByRecordID(recordList, maxDegree, buildOutDegree, maxEntities, responseBuf, bufSize, resizeFunc) | findNetworkByRecordId(recordList, maxDegrees, buildOutDegree, maxEntities, flags) | string | SM-3.1 |
| G2_findPathByEntityID(entityID1, entityID2, maxDegree, responseBuf, bufSize, resizeFunc) | findPathByEntityId(startEntityId, endEntityId, maxDegrees, exclusions, requiredDataSources, flags) | string | SM-3.1 |
| G2_findPathByRecordID(dataSourceCode1, recordID1, dataSourceCode2, recordID2, maxDegree, responseBuf, bufSize, resizeFunc) | findPathByRecordId(startDataSourceCode, startRecordId, endDataSourceCode, endRecordId, maxDegrees, exclusions, requiredDataSources, flags) | string | SM-3.1 |
| G2_getActiveConfigID(configID) | getActiveConfigId() | int64 | |
| G2_getEntityByEntityID(entityID, responseBuf, bufSize, resizeFunc) | getEntityByEntityId(entityId, flags) | string | |
| G2_getEntityByRecordID(dataSourceCode, recordID, responseBuf, bufSize, resizeFunc) | getEntityByRecordId(dataSourceCode, recordId, flags) | string | |
| G2_getRecord(dataSourceCode, recordID, responseBuf, bufSize, resizeFunc) | getRecord(dataSourceCode, recordId, flags) | string | |
| G2_getRedoRecord(responseBuf, bufSize, resizeFunc ) | getRedoRecord() | string | |
| G2_getRepositoryLastModifiedTime(lastModifiedTime) | getRepositoryLastModifiedTime()  | int64 | |
| G2_getVirtualEntityByRecordID(recordList, responseBuf, bufSize, resizeFunc) | getVirtualEntityByRecordId(recordList, flags) | string | |
| G2_howEntityByEntityID(entityID, responseBuf, bufSize, resizeFunc) | howEntityByEntityId(entityId, flags) | string | SM-1, SM-3.3 |
| G2_init(moduleName, iniParams, verboseLogging) | initialize(instanceName, settings, verboseLogging, configId) | - | `configId` can be `nil`, `None`, `null`. Consider single object |
| G2_primeEngine() | | - | |
| G2_processRedoRecord(responseBuf, bufSize, resizeFunc ) | processRedoRecord(redoRecord, flags) | string | |
| G2_reevaluateEntity(entityID, flags) | reevaluateEntity(entityId, flags) | string | `flags` has `WITH_INFO` bit |
| G2_reevaluateRecord(dataSourceCode, recordID, flags) | reevaluateRecord(dataSourceCode, recordId, flags) | string | `flags` has `WITH_INFO` bit |
| G2_reinit(initConfigID) | reinitialize(configId) | - | ??? |
| G2_replaceRecord(dataSourceCode, recordID, jsonData) | replaceRecord(dataSourceCode, recordId, recordDefinition, flags) | string | |
| G2_searchByAttributes(jsonData, responseBuf, bufSize, resizeFunc) | searchByAttributes(attributes, searchProfile, flags) | string | |
| G2_stats(responseBuf, bufSize, resizeFunc ) | getStats() | string | |
| G2_whyEntities(entityID1, entityID2, responseBuf, bufSize, resizeFunc) | whyEntities(entityId1, entityId2, flags) | string | SM-1, SM-3.3 |
| G2_whyRecordInEntity(dataSourceCode, recordID, responseBuf, bufSize, resizeFunc) | whyRecordInEntity(dataSourceCode, recordId, flags) | string | SM-1, SM-3.3 |
| G2_whyRecords(dataSourceCode1, recordID1, dataSourceCode2, recordID2, responseBuf, bufSize, resizeFunc) | whyRecords(dataSourceCode1, recordId1, dataSourceCode2, recordId2, flags) | string | SM-1, SM-3.3 |

### G2Product

| Existing name | Canonical Name | Return values | Smells |
|---------------|----------------|---------------|--------|
| G2Product_destroy() | | - | |
| G2Product_init(moduleName, iniParams, verboseLogging) | initialize(instanceName, settings, verboseLogging) | - | |
| G2Product_license() | getLicense() | string | |
| G2Product_validateLicenseStringBase64(licenseString, errorBuf, errorBufSize, resizeFunc) | ??? | | |
| G2Product_version() | getVersion() | string | |

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
         info = g2_engine.add_record(dataSourceCode, recordId, record, resultFlags)
         ```

   1. If `resultFlags` is 0 (i.e. no bit flags are on) then the returned value is `{}`, an empty JSON string.
   1. Beneath the covers, the SDK determines if the `WITH_INFO` bit is **off**, in which case it calls `G2_addRecord`.
      If the `WITH_INFO` bit is **on**, the SDK calls `G2_addRecordWithInfo`.
   1. Flag can be OR-ed for future expansion. Example:

         ```python
         info = g2_engine.add_record(dataSourceCode, recordId, record, WITH_INFO | WITHOUT_SOMETHING_ELSE)
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
         g2_engine.add_record(dataSourceCode, recordId, record)
         ```

         ```python
         info = g2_engine.add_record(dataSourceCode, recordId, record, resultFlags)
         ```

   1. Java language specifics:
      1. Use method overloading to factor out the `resultFlags` parameter.
      1. Examples of use:

         ```java
         g2Engine.addRecord(dataSourceCode, recordId, record)
         ```

         ```java
         info = g2Engine.addRecord(dataSourceCode, recordId, record, WITH_INFO)
         ```

   1. Go language specifics:
      1. Go doesn't have optional parameters nor method overloading.
      1. Examples of use:

         ```go
         _, err := g2Engine.AddRecord(dataSourceCode, recordId, record, g2api.WITHOUT_INFO)
         ```

         ```go
         info, err := g2Engine.AddRecord(dataSourceCode, recordId, record, g2api.WITH_INFO)
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
