# Candidate method names - condensed

To see the expanded version, visit
[canonical names](canonical-names.md).
The
[canonical names condensed](canonical-names-condensed.md)
list factors out `not-public`, `not-implemented`, and `collapsed` entries.

The following list should reflect modifications documented in
[Senzing 4.0 Breaking Changes](https://senzing.atlassian.net/wiki/spaces/~794719871/pages/2754641921/Senzing+4.0+Breaking+Changes).

## Mapping

### SzConfig

| Differs in C | Existing name                                                                     | Canonical Name                                     | Return value | Smells |
|:------------:| --------------------------------------------------------------------------------- | -------------------------------------------------- | ------------ | ------ |
| *            | SzConfig_addDataSource(configHandle, inputJson, responseBuf, bufSize, resizeFunc) | registerDataSource(dataSourceCode)                 | string       |        |
| *            | SzConfig_deleteDataSource(configHandle, inputJson)                                | unregisterDataSource(dataSourceCode)               | -            |        |
| *            | SzConfig_listDataSources(configHandle, responseBuf, bufSize, resizeFunc)          | getDataSourceRegistry()                            | string       |        |
| *            | SzConfig_save(configHandle, responseBuf, bufSize, resizeFunc)                     | export()                                           | string       |        |

### SzConfigManager

| Differs in C | Existing name                                                     | Canonical Name                                                     | Return value | Note                                         |
|:------------:| ----------------------------------------------------------------- | ------------------------------------------------------------------ | ------------ | -------------------------------------------- |
| *            | SzConfigMgr_addConfig(configStr, configComment, configID)         | registerConfig(configDefinition, configComment)                    | int64        |                                              |
| *            | SzConfigMgr_getConfigList(responseBuf, bufSize, resizeFunc)       | getConfigRegistry()                                                | string       |                                              |

### SzDiagnostic

| Differs in C | Existing name                                                            | Canonical Name                                               | Return value | Smells                                                          |
|:------------:| ------------------------------------------------------------------------ | ------------------------------------------------------------ | ------------ | --------------------------------------------------------------- |
| *            | SzDiagnostic_checkDBPerf(secondsToRun, responseBuf, bufSize, resizeFunc) | checkRepositoryPerformance(secondsToRun)                     | string       |                                                                 |
| *            | SzDiagnostic_getDatastoreInfo(responseBuf, bufSize, resizeFunc)          | getRepositoryInfo()                                          | string       |                                                                 |
| *            | SzDiagnostic_getFeature(libFeatID, responseBuf, bufSize, resizeFunc)     | getFeature(featureId)                                        | string       | \*\* Not approved yet                                           |

### SzEngine

| Differs in C | Existing name                                                                                                              | Canonical Name                                                                                                                                  | Return value | Smells                                                          |
|:------------:| -------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------- | ------------ | --------------------------------------------------------------- |
| *            | Sz_closeExport(responseHandle)                                                                                             | closeExportReport(exportHandle)                                                                                                                 | -            |                                                                 |
| *            | Sz_preprocessRecord(jsonData, flags, responseBuf, bufSize, resizeFunc )                                                    | getRecordPreview(recordDefinition, flags)                                                                                                       | string       |                                                                 |

### SzProduct

| Differs in C | Existing name                                                                            | Canonical Name                                     | Return value | Smells |
|:------------:| ---------------------------------------------------------------------------------------- | -------------------------------------------------- | ------------ | ------ |
| *            | SzProduct_license()                                                                      | getLicense()                                       | string       |        |
| *            | SzProduct_version()                                                                      | getVersion()                                       | string       |        |
