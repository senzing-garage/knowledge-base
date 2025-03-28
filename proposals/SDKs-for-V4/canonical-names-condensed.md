# Candidate method names - condensed

To see the expanded version, visit
[canonical names](canonical-names.md).

The following list should reflect modifications documented in
[Senzing 4.0 Breaking Changes](https://senzing.atlassian.net/wiki/spaces/~794719871/pages/2754641921/Senzing+4.0+Breaking+Changes).

## Mapping

### SzConfig

| Existing name | Canonical Name | Return value | Smells |
|---------------|----------------|--------------|--------|
| SzConfig_addDataSource(configHandle, inputJson, responseBuf, bufSize, resizeFunc) | addDataSource(dataSourceCode) | string | |
| SzConfig_deleteDataSource(configHandle, inputJson) | deleteDataSource(dataSourceCode) | - | |
| SzConfig_init(moduleName, iniParams, verboseLogging) | initialize(instanceName, settings, verboseLogging) | - | |
| SzConfig_listDataSources(configHandle, responseBuf, bufSize, resizeFunc) | getDataSources() | string | |
| SzConfig_save(configHandle, responseBuf, bufSize, resizeFunc) | export()  | string | |

### SzConfigManager

| Existing name | Canonical Name | Return value | Smells |
|---------------|----------------|--------------|--------|
| SzConfigMgr_addConfig(configStr, configComment, configID) | registerConfig(configDefinition, configComment) | int64 | |
| SzConfigMgr_destroy() | | - | |
| SzConfigMgr_getConfig(configID, responseBuf, bufSize, resizeFunc) | createConfigFromConfigID(configId) | SzConfig | May vary by SDK |
| | createConfigFromString(configDefinition) | SzConfig | May vary by SDK|
| | createConfigFromTemplate() | SzConfig | May vary by SDK|
| SzConfigMgr_getConfigList(responseBuf, bufSize, resizeFunc) | getConfigs() | string | |
| SzConfigMgr_getDefaultConfigID(configID) | getDefaultConfigId() | int64 | |
| SzConfigMgr_init(moduleName, iniParams, verboseLogging) | initialize(instanceName, settings, verboseLogging) | - | |
| SzConfigMgr_replaceDefaultConfigID(oldConfigID, newConfigID) | replaceDefaultConfigId(currentDefaultConfigId, newDefaultConfigId) | - | |
| SzConfigMgr_setDefaultConfigID(configID) | setDefaultConfigId(configId) | - | |
| | setDefaultConfig(configDefinition) | - | |

### SzDiagnostic

| Existing name | Canonical Name | Return value | Smells |
|---------------|----------------|--------------|--------|
| SzDiagnostic_checkDBPerf(secondsToRun, responseBuf, bufSize, resizeFunc) | checkDatastorePerformance(secondsToRun) | string | |
| SzDiagnostic_destroy() | | - | |
| SzDiagnostic_getDatastoreInfo(responseBuf, bufSize, resizeFunc) | getDatastoreInfo() | string | |
| SzDiagnostic_getFeature(libFeatID, responseBuf, bufSize, resizeFunc) | getFeature(featureId) | string | ** Not approved yet |
| SzDiagnostic_init(moduleName, iniParams, verboseLogging) | initialize(instanceName, settings, configId, verboseLogging) | | `configId` can be `nil`, `None`, `null`. Consider single object |
| SzDiagnostic_purgeRepository(????) | purgeRepository(????) | | |
| SzDiagnostic_reinit(initConfigID) | reinitialize(configId) | - | |

### SzEngine

| Existing name | Canonical Name | Return value | Smells |
|---------------|----------------|--------------|--------|
| Sz_addRecord(dataSourceCode, recordID, jsonData) | addRecord(dataSourceCode, recordId, recordDefinition, flags) | string | |
| Sz_closeExport(responseHandle) | closeExport(exportHandle) | - | |
| Sz_countRedoRecords() | | int64 | |
| Sz_deleteRecord(dataSourceCode, recordID) | deleteRecord(dataSourceCode, recordId, flags) | string | |
| Sz_destroy() | | - | |
| Sz_exportCSVEntityReport(csvColumnList, flags, responseHandle) | exportCsvEntityReport(csvColumnList, flags) | exportHandle | |
| Sz_exportJSONEntityReport(flags, responseHandle) | exportJsonEntityReport(flags) | exportHandle | |
| Sz_fetchNext(responseHandle, responseBuf, bufSize) | fetchNext(exportHandle)  | string | |
| Sz_findInterestingEntitiesByEntityID(entityID, flags, responseBuf, bufSize, resizeFunc) | findInterestingEntitiesByEntityId(entityId, flags)  | string |  |
| Sz_findInterestingEntitiesByRecordID(dataSourceCode, recordID, flags, responseBuf, bufSize, resizeFunc) | findInterestingEntitiesByRecordId(dataSourceCode, recordId, flags)  | string |  |
| Sz_findNetworkByEntityID(entityList, maxDegree, buildOutDegree, maxEntities, responseBuf, bufSize, resizeFunc) | findNetworkByEntityId(entityIds, maxDegrees, buildOutDegrees, buildOutMaxEntities, flags)  | string | SM-3.1 |
| Sz_findNetworkByRecordID(recordList, maxDegree, buildOutDegree, maxEntities, responseBuf, bufSize, resizeFunc) | findNetworkByRecordId(recordKeys, maxDegrees, buildOutDegrees, buildOutMaxEntities, flags) | string | SM-3.1 |
| Sz_findPathByEntityID(entityID1, entityID2, maxDegree, responseBuf, bufSize, resizeFunc) | findPathByEntityId(startEntityId, endEntityId, maxDegrees, avoidEntityIds, requiredDataSources, flags) | string | SM-3.1 |
| Sz_findPathByRecordID(dataSourceCode1, recordID1, dataSourceCode2, recordID2, maxDegree, responseBuf, bufSize, resizeFunc) | findPathByRecordId(startDataSourceCode, startRecordId, endDataSourceCode, endRecordId, maxDegrees, avoidRecordKeys, requiredDataSources, flags) | string | SM-3.1 |
| Sz_getActiveConfigID(configID) | getActiveConfigId() | int64 | |
| Sz_getEntityByEntityID(entityID, responseBuf, bufSize, resizeFunc) | getEntityByEntityId(entityId, flags) | string | |
| Sz_getEntityByRecordID(dataSourceCode, recordID, responseBuf, bufSize, resizeFunc) | getEntityByRecordId(dataSourceCode, recordId, flags) | string | |
| Sz_getRecord(dataSourceCode, recordID, responseBuf, bufSize, resizeFunc) | getRecord(dataSourceCode, recordId, flags) | string | |
| Sz_getRedoRecord(responseBuf, bufSize, resizeFunc ) | getRedoRecord() | string | |
| Sz_getVirtualEntityByRecordID(recordList, responseBuf, bufSize, resizeFunc) | getVirtualEntityByRecordId(recordKeys, flags) | string | |
| Sz_howEntityByEntityID(entityID, responseBuf, bufSize, resizeFunc) | howEntityByEntityId(entityId, flags) | string | SM-1, SM-3.3 |
| Sz_init(moduleName, iniParams, verboseLogging) | initialize(instanceName, settings, configId, verboseLogging) | - | `configId` can be `nil`, `None`, `null`. Consider single object |
| Sz_preprocessRecord(jsonData, flags, responseBuf, bufSize, resizeFunc ) | preprocessRecord(recordDefinition, flags) | string | |
| Sz_primeEngine() | | - | |
| Sz_processRedoRecord(responseBuf, bufSize, resizeFunc ) | processRedoRecord(redoRecord, flags) | string | |
| Sz_reevaluateEntity(entityID, flags) | reevaluateEntity(entityId, flags) | string | `flags` has `WITH_INFO` bit |
| Sz_reevaluateRecord(dataSourceCode, recordID, flags) | reevaluateRecord(dataSourceCode, recordId, flags) | string | `flags` has `WITH_INFO` bit |
| Sz_reinit(initConfigID) | reinitialize(configId) | - | ??? |
| Sz_searchByAttributes(jsonData, responseBuf, bufSize, resizeFunc) | searchByAttributes(attributes, searchProfile, flags) | string | |
| Sz_stats(responseBuf, bufSize, resizeFunc ) | getStats() | string | |
| Sz_whyEntities(entityID1, entityID2, responseBuf, bufSize, resizeFunc) | whyEntities(entityId1, entityId2, flags) | string | SM-1, SM-3.3 |
| Sz_whyRecordInEntity(dataSourceCode, recordID, responseBuf, bufSize, resizeFunc) | whyRecordInEntity(dataSourceCode, recordId, flags) | string | SM-1, SM-3.3 |
| Sz_whyRecords(dataSourceCode1, recordID1, dataSourceCode2, recordID2, responseBuf, bufSize, resizeFunc) | whyRecords(dataSourceCode1, recordId1, dataSourceCode2, recordId2, flags) | string | SM-1, SM-3.3 |
| Sz_whySearch(jsonData, entityID, searchProfile, responseBuf, bufSize, resizeFunc) | whySearch(attributes, entityID, searchProfile, flags) | string | SM-1, SM-3.3 |

### SzProduct

| Existing name | Canonical Name | Return value | Smells |
|---------------|----------------|--------------|--------|
| SzProduct_destroy() | | - | |
| SzProduct_init(moduleName, iniParams, verboseLogging) | initialize(instanceName, settings, verboseLogging) | - | |
| SzProduct_license() | getLicense() | string | |
| SzProduct_validateLicenseStringBase64(licenseString, errorBuf, errorBufSize, resizeFunc) | ??? | | |
| SzProduct_version() | getVersion() | string | |

## Abstract Factory

### SzAbstractFactory

| Existing name | Canonical Name | Return value | Smells |
|---------------|----------------|--------------|--------|
|| createConfig()         | [object conforming to SzConfig interface]         ||
|| createConfigManager()  | [object conforming to SzConfigManager interface]  ||
|| createDiagnostic()     | [object conforming to SzDiagnostic interface]     ||
|| createEngine()         | [object conforming to SzEngine interface]         ||
|| createProduct()        | [object conforming to SzProduct interface]        ||

## Method signature proposals

### Handling WithInfo - Proposal 1

1. Functions affected:
   - Sz_addRecordWithInfo
   - Sz_deleteRecordWithInfo
   - Sz_processWithInfo
   - Sz_reevaluateEntityWithInfo
   - Sz_reevaluateRecordWithInfo
   - Sz_replaceRecordWithInfo
1. Approach:
   1. Function name becomes shortened to match the non-with-info name (e.g. `Sz_addRecord()`).
   1. The `xx_withInfo()` function/method signature is not in the SDK.
   1. Function always returns JSON string.
   1. A final input parameter, say `resultFlags` (int64 used as a bit-mask), indicates the nature of the content returned in the JSON string.
   1. Example:

         ```python
         info = engine.add_record(dataSourceCode, recordId, record, resultFlags)
         ```

   1. If `resultFlags` is 0 (i.e. no bit flags are on) then the returned value is `{}`, an empty JSON string.
   1. Beneath the covers, the SDK determines if the `WITH_INFO` bit is **off**, in which case it calls `Sz_addRecord`.
      If the `WITH_INFO` bit is **on**, the SDK calls `Sz_addRecordWithInfo`.
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
