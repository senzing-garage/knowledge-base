# Candidate method names - condensed

## Mapping

### G2Config

| Existing name                                                                     | Canonical Name                         | Return values | Smells |
| --------------------------------------------------------------------------------- | -------------------------------------- | ------------- | ------ |
| G2Config_addDataSource(configHandle, inputJson, responseBuf, bufSize, resizeFunc) | addDataSource(configHandle, inputJson) | string        | SM-2   |
| G2Config_close(configHandle)                                                      |                                        | -             |        |
| G2Config_create(configHandle)                                                     | create()                               | configHandle  |        |
| G2Config_deleteDataSource(configHandle, inputJson)                                |                                        | -             | SM-2   |
| G2Config_destroy()                                                                |                                        | -             |        |
| G2Config_init(moduleName, iniParams, verboseLogging)                              |                                        | -             |        |
| G2Config_listDataSources(configHandle, responseBuf, bufSize, resizeFunc)          | listDataSources(configHandle)          | string        | SM-3.2 |
| G2Config_load(jsonConfig, configHandle)                                           | load(jsonConfig)                       | configHandle  | SM-2   |
| G2Config_save(configHandle, responseBuf, bufSize, resizeFunc)                     | save(configHandle)                     | string        |        |

### G2ConfigMgr

| Existing name                                                     | Canonical Name                       | Return values | Smells |
| ----------------------------------------------------------------- | ------------------------------------ | ------------- | ------ |
| G2ConfigMgr_addConfig(configStr, configComments, configID)        | addConfig(configStr, configComments) | int64         | SM-2   |
| G2ConfigMgr_destroy()                                             |                                      | -             |        |
| G2ConfigMgr_getConfig(configID, responseBuf, bufSize, resizeFunc) | getConfig(configID)                  | string        |        |
| G2ConfigMgr_getConfigList(responseBuf, bufSize, resizeFunc)       | getConfigList()                      | string        |        |
| G2ConfigMgr_getDefaultConfigID(configID)                          | getDefaultConfigID()                 | int64         |        |
| G2ConfigMgr_init(moduleName, iniParams, verboseLogging)           |                                      | -             |        |
| G2ConfigMgr_replaceDefaultConfigID(oldConfigID, newConfigID)      |                                      | -             |        |
| G2ConfigMgr_setDefaultConfigID(configID)                          |                                      | -             |        |

### G2Diagnostic

| Existing name                                                                      | Canonical Name            | Return values | Smells |
| ---------------------------------------------------------------------------------- | ------------------------- | ------------- | ------ |
| G2Diagnostic_checkDBPerf(secondsToRun, responseBuf, bufSize, resizeFunc)           | checkDBPerf(secondsToRun) | string        |        |
| G2Diagnostic_destroy()                                                             |                           | -             |        |
| G2Diagnostic_init(moduleName, iniParams, verboseLogging)                           |                           | -             |        |
| G2Diagnostic_initWithConfigID(moduleName, iniParams, initConfigID, verboseLogging) |                           | -             |        |
| G2Diagnostic_reinit(initConfigID)                                                  |                           | -             |        |

### G2Engine

| Existing name                                                                                                                                                            | Canonical Name                                                                                                                              | Return values  | Smells       |
| ------------------------------------------------------------------------------------------------------------------------------------------------------------------------ | ------------------------------------------------------------------------------------------------------------------------------------------- | -------------- | ------------ |
| G2_addRecord(dataSourceCode, recordID, jsonData, loadID)                                                                                                                 | addRecord(dataSourceCode, recordID, jsonData, resultFlags)                                                                                  | string         | SM-2         |
| G2_closeExport(responseHandle)                                                                                                                                           |                                                                                                                                             | -              |              |
| G2_countRedoRecords()                                                                                                                                                    |                                                                                                                                             | int64          |              |
| G2_deleteRecord(dataSourceCode, recordID, loadID)                                                                                                                        | deleteRecord(dataSourceCode, recordID, resultFlags)                                                                                         | string         |              |
| G2_destroy()                                                                                                                                                             |                                                                                                                                             | -              |              |
| G2_exportCSVEntityReport(csvColumnList, flags, responseHandle)                                                                                                           | exportCSVEntityReport(csvColumnList, flags)                                                                                                 | responseHandle |              |
| G2_exportConfig(responseBuf, bufSize, resizeFunc)                                                                                                                        | exportConfig()                                                                                                                              | string         |              |
| G2_exportConfigAndConfigID(responseBuf, bufSize, resizeFunc, configID)                                                                                                   | exportConfigAndConfigID()                                                                                                                   | string, int64  |              |
| G2_exportJSONEntityReport(flags, responseHandle)                                                                                                                         | exportJSONEntityReport(flags)                                                                                                               | responseHandle |              |
| G2_fetchNext(responseHandle, responseBuf, bufSize)                                                                                                                       | fetchNext(responseHandle)                                                                                                                   | string         |              |
| G2_findInterestingEntitiesByEntityID(entityID, flags, responseBuf, bufSize, resizeFunc)                                                                                  | findInterestingEntitiesByEntityID(entityID, flags)                                                                                          | string         | SM-3.1       |
| G2_findInterestingEntitiesByRecordID(dataSourceCode, recordID, flags, responseBuf, bufSize, resizeFunc)                                                                  | findInterestingEntitiesByRecordID(dataSourceCode, recordID, flags)                                                                          | string         | SM-3.1       |
| G2_findNetworkByEntityID(entityList, maxDegree, buildOutDegree, maxEntities, responseBuf, bufSize, resizeFunc)                                                           | findNetworkByEntityID(entityList, maxDegree, buildOutDegree, maxEntities, flags)                                                            | string         | SM-3.1       |
| G2_findNetworkByRecordID(recordList, maxDegree, buildOutDegree, maxEntities, responseBuf, bufSize, resizeFunc)                                                           | findNetworkByRecordID(recordList, maxDegree, buildOutDegree, maxEntities, flags)                                                            | string         | SM-3.1       |
| G2_findPathByEntityID(entityID1, entityID2, maxDegree, responseBuf, bufSize, resizeFunc)                                                                                 | findPathByEntityID(entityID1, entityID2, maxDegree, flags)                                                                                  | string         | SM-3.1       |
| G2_findPathByRecordID(dataSourceCode1, recordID1, dataSourceCode2, recordID2, maxDegree, responseBuf, bufSize, resizeFunc)                                               | findPathByRecordID(dataSourceCode1, recordID1, dataSourceCode2, recordID2, maxDegree, flags)                                                | string         | SM-3.1       |
| G2_findPathExcludingByEntityID(entityID1, entityID2, maxDegree, excludedEntities, responseBuf, bufSize, resizeFunc)                                                      | findPathExcludingByEntityID(entityID1, entityID2, maxDegree, excludedEntities, flags)                                                       | string         | SM-3.1       |
| G2_findPathExcludingByRecordID(dataSourceCode1, recordID1, dataSourceCode2, recordID2, maxDegree, excludedRecords, responseBuf, bufSize, resizeFunc)                     | findPathExcludingByRecordID(dataSourceCode1, recordID1, dataSourceCode2, recordID2, maxDegree, excludedRecords, flags)                      | string         | SM-3.1       |
| G2_findPathIncludingSourceByEntityID(entityID1, entityID2, maxDegree, excludedEntities, requiredDsrcs, responseBuf, bufSize, resizeFunc)                                 | findPathIncludingSourceByEntityID(entityID1, entityID2, maxDegree, excludedEntities, requiredDsrcs, flags)                                  | string         | SM-3.1       |
| G2_findPathIncludingSourceByRecordID(dataSourceCode1, recordID1, dataSourceCode2, recordID2, maxDegree, excludedRecords, requiredDsrcs, responseBuf, bufSize, resizeFunc | findPathIncludingSourceByRecordID(dataSourceCode1, recordID1, dataSourceCode2, recordID2, maxDegree, excludedRecords, requiredDsrcs, flags) | string         | SM-3.1       |
| G2_getActiveConfigID(configID)                                                                                                                                           |                                                                                                                                             | int64          |              |
| G2_getEntityByEntityID(entityID, responseBuf, bufSize, resizeFunc)                                                                                                       | getEntityByEntityID(entityID, flags)                                                                                                        | string         |              |
| G2_getEntityByRecordID(dataSourceCode, recordID, responseBuf, bufSize, resizeFunc)                                                                                       | getEntityByRecordID(dataSourceCode, recordID, flags)                                                                                        | string         |              |
| G2_getRecord(dataSourceCode, recordID, responseBuf, bufSize, resizeFunc)                                                                                                 | getRecord(dataSourceCode, recordID, flags)                                                                                                  | string         |              |
| G2_getRedoRecord(responseBuf, bufSize, resizeFunc )                                                                                                                      | getRedoRecord()                                                                                                                             | string         |              |
| G2_getRepositoryLastModifiedTime(lastModifiedTime)                                                                                                                       | getRepositoryLastModifiedTime()                                                                                                             | int64          |              |
| G2_getVirtualEntityByRecordID(recordList, responseBuf, bufSize, resizeFunc)                                                                                              | getVirtualEntityByRecordID(recordList, flags)                                                                                               | string         |              |
| G2_howEntityByEntityID(entityID, responseBuf, bufSize, resizeFunc)                                                                                                       | howEntityByEntityID(entityID, flags)                                                                                                        | string         | SM-1, SM-3.3 |
| G2_init(moduleName, iniParams, verboseLogging)                                                                                                                           |                                                                                                                                             | -              |              |
| G2_initWithConfigID(moduleName, iniParams, initConfigID, verboseLogging)                                                                                                 |                                                                                                                                             | -              |              |
| G2_primeEngine()                                                                                                                                                         |                                                                                                                                             | -              |              |
| G2_reevaluateEntity(entityID, flags)                                                                                                                                     | reevaluateEntity(entityID, flags, resultFlags)                                                                                              | string         |              |
| G2_reevaluateRecord(dataSourceCode, recordID, flags)                                                                                                                     | reevaluateRecord(dataSourceCode, recordID, flags, resultFlags)                                                                              | string         |              |
| G2_reinit(initConfigID)                                                                                                                                                  |                                                                                                                                             | -              |              |
| G2_replaceRecord(dataSourceCode, recordID, jsonData, loadID)                                                                                                             | replaceRecord(dataSourceCode, recordID, jsonData, resultFlags)                                                                              | string         | SM-2         |
| G2_searchByAttributes(jsonData, responseBuf, bufSize, resizeFunc)                                                                                                        | searchByAttributes(jsonData, searchProfile, flags)                                                                                          | string         | SM-2         |
| G2_stats(responseBuf, bufSize, resizeFunc )                                                                                                                              | stats()                                                                                                                                     | string         | SM-1         |
| G2_whyEntities(entityID1, entityID2, responseBuf, bufSize, resizeFunc)                                                                                                   | whyEntities(entityID1, entityID2, flags)                                                                                                    | string         | SM-1, SM-3.3 |
| G2_whyRecordInEntity(dataSourceCode, recordID, responseBuf, bufSize, resizeFunc)                                                                                         | whyRecordInEntity(dataSourceCode, recordID, flags)                                                                                          | string         | SM-1, SM-3.3 |
| G2_whyRecords(dataSourceCode1, recordID1, dataSourceCode2, recordID2, responseBuf, bufSize, resizeFunc)                                                                  | whyRecords(dataSourceCode1, recordID1, dataSourceCode2, recordID2, flags)                                                                   | string         | SM-1, SM-3.3 |

### G2Product

| Existing name                                         | Canonical Name | Return values | Smells |
| ----------------------------------------------------- | -------------- | ------------- | ------ |
| G2Product_destroy()                                   |                | -             |        |
| G2Product_init(moduleName, iniParams, verboseLogging) |                | -             |        |
| G2Product_license()                                   |                | string        | SM-1   |
| G2Product_version()                                   |                | string        | SM-1   |

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
      > Passing a boolean into a function is a truly terrible practice.
      > It immediately complicates the signature of the method, loudly proclaiming that this function does more than one thing.
      > -- **("Clean Code", Chapter 3, "Flag Arguments")**

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

1. SM-1: Function naming. For consistency, say the phrase "To _method-name_". If it sounds awkward, consider renaming the method.
   1. Good: "To `getVirtualEntityByRecordID()`", "To `addRecordAndReturnInfo()`"
   1. Bad: "To `howEntityByEntityID()`", "To `version()`"
1. SM-2: Parameter naming. For portability across different programming languages, the parameter name shouldn't include a data-type.
   1. Good: `dataSourceSpec`
   1. Bad: `inputJson`
1. SM-3: Inconsistent function/method verbs
   1. SM-3.1 `find` instead of standard `get`
   1. SM-3.2 `list` instead of standard `get`
   1. SM-3.3 Non-verb (The "to" principle)
