# Renaming parameters

## Considerations

- Consider removing "datatype" from variable name.
  In some SDKs the input parameter may not be JSON in the strictest sense.
  In Python it may be a `dict`  (e.g.`jsonConfig`, `jsonData`, `inputJson`, `configStr`, `licenseString`)
- To ease comprehension by user, consider full names.
  Most, actually almost all, variable names do this well.
  But there are a few.
  (e.g. `bufferSize`, `errorBuffer`, `infoBuffer`, `iniParameters`)

## Ideas

| Before                | After              | Comments                             |
|-----------------------|--------------------|--------------------------------------|
| buffSize              | bufferSize         ||
| configStr             | config             | Similar to `features`. `record` |
| errorBuf              | errorBuffer        ||
| errorBufSize          | errorBufferSize    ||
| infoBuff              | infoBuffer         ||
| infoBuffSize          | infoBufferSize     ||
| iniParams             | initParameters     ||
| inputJson             |                    ||
| jsonConfig            |                    ||
| jsonData              |                    ||
| licenseString         | license            ||
| maximumEstimatedCount | maxEstimatedCount  | Consistency with `maxDegree`, `maxEntities`|
| minimumEntitySize     | minEntitySize      | Consistency with `maxDegree`, `maxEntities` |
| recordIDBuf           | recordIDBuffer     ||
| recordIDBufSize       | recordIDBuferSize  ||
| responseBuf           | responseBuffer     ||
| responseBufSize       | responseBufferSize ||

## Current C code

1. [Current C function signatures aggregated](./all.h)
1. [libg2.h](./libg2.h)
1. [libg2config.h](./libg2config.h)
1. [libg2configmgr.h](./libg2configmgr.h)
1. [libg2diagnostic.h](./libg2diagnostic.h)
1. [libg2product.h](./libg2product.h)

## Table of varable use

| Parameter               | Count |
|-------------------------|------:|
| buffer                  |     5 |
| bufSize                 |    81 |
| buildOutDegree          |     4 |
| configComments          |     1 |
| configHandle            |     7 |
| configID                |     6 |
| configStr               |     1 |
| csvColumnList           |     1 |
| dataSourceCode          |    19 |
| dataSourceCode1         |     8 |
| dataSourceCode2         |     8 |
| entityID                |    11 |
| entityID1               |     8 |
| entityID2               |     8 |
| entityList              |     2 |
| entityListBySizeHandle  |     3 |
| entitySize              |     1 |
| errorBuf                |     2 |
| errorBufSize            |     2 |
| excludedEntities        |     4 |
| excludedRecords         |     4 |
| features                |     1 |
| featureType             |     1 |
| flags                   |    34 |
| includeInternalFeatures |     4 |
| infoBuf                 |     1 |
| infoBufSize             |     1 |
| iniParams               |     7 |
| initConfigID            |     4 |
| inputJson               |     2 |
| jsonConfig              |     1 |
| jsonData                |     9 |
| lastModifiedTime        |     1 |
| libFeatID               |     1 |
| licenseFilePath         |     1 |
| licenseString           |     1 |
| loadID                  |     8 |
| maxDegree               |    16 |
| maxEntities             |     4 |
| maximumEstimatedCount   |     1 |
| minimumEntitySize       |     1 |
| moduleName              |     7 |
| newConfigID             |     1 |
| newSize                 |    75 |
| oldConfigID             |     1 |
| ptr                     |    75 |
| record                  |     5 |
| recordID                |    17 |
| recordID1               |     8 |
| recordID2               |     8 |
| recordIDBuf             |     2 |
| recordIDBufSize         |     1 |
| recordList              |     4 |
| recordQueryList         |     1 |
| relationshipID          |     1 |
| requiredDsrcs           |     4 |
| resizeFunc              |    75 |
| responseBuf             |    77 |
| responseBufSize         |     1 |
| responseHandle          |     4 |
| searchProfile           |     1 |
| secondsToRun            |     1 |
| verboseLogging          |     7 |
