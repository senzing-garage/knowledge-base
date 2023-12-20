# Renaming parameters

## Considerations

- Consider removing "datatype" from variable name.
  In some SDKs the input parameter may not be JSON in the strictest sense.
  For instance, in Python it may be a `dict` that is the datatype of the parameter.
  (e.g.`jsonConfig`, `jsonData`, `inputJson`, `configStr`, `licenseString`)
- Consider full names to ease comprehension by user.
  Most, actually almost all, variable names do this well.
  But there are a few.
  (e.g. `bufferSize`, `errorBuffer`, `infoBuffer`, `iniParameters`)
- Consider collapsing variables that have the same semantic meaning but different names.
  (e.g. `configStr` and `jsonConfig` seem to have the same semantic meaning)
- Consider splitting variables that have the same name but different semantic meaning.
  (e.g. The `jsonData` of `G2_addRecord` is different from `jsonData` of `G2_searchByAttributes`)

## Ideas

The following table has suggestions for variable name changes.
The "Before" column is the current name of the variable.
The "After" column is a suggested replacement.
The "Comments" column has rationale.

| Before                | After              | Comments                             |
|-----------------------|--------------------|--------------------------------------|
| buffSize              | bufferSize         | Use full names. |
| configStr             | config             | Remove datatype. Similar to `features` and `record`. |
| errorBuf              | errorBuffer        | Use full names. |
| errorBufSize          | errorBufferSize    | Use full names. |
| infoBuff              | infoBuffer         | Use full names. |
| infoBuffSize          | infoBufferSize     | Use full names. |
| iniParams             | initParameters     | Use full names. |
| inputJson             | dataSourceSpec     | Remove datatype. Used in `G2Config_addDataSource` and `G2Config_deleteDataSource`. |
| jsonConfig            | config             | Remove datatype. Used in `G2Config_load`. See `configStr` above. |
| jsonData              | record             | Remove datatype. When used in `G2_addRecord*` functions. Note: `record` is used elsewhere. |
| jsonData              | searchQuery        | Remove datatype. When used in `G2_searchByAttributes*` functions. |
| licenseString         | license            | Remove datatype. |
| maximumEstimatedCount | maxEstimatedCount  | Consistent with `maxDegree`, `maxEntities`|
| minimumEntitySize     | minEntitySize      | Consistent with `maxDegree`, `maxEntities` |
| ptr                   | ???                | Probably not externalized. Languages like Python don't deal in pointers.|
| recordIDBuf           | recordIDBuffer     | Use full names. |
| recordIDBufSize       | recordIDBuferSize  | Use full names. |
| responseBuf           | responseBuffer     | Use full names. |
| responseBufSize       | responseBufferSize | Use full names. |

## Current C code

The following is a copy of the C code used in this analysis.

1. [Current C function signatures aggregated](./all.h)
1. [libg2.h](./libg2.h)
1. [libg2config.h](./libg2config.h)
1. [libg2configmgr.h](./libg2configmgr.h)
1. [libg2diagnostic.h](./libg2diagnostic.h)
1. [libg2product.h](./libg2product.h)

## Table of variable use

The following table lists the variables used in the
[Current C Code](#current-c-code)
in alphabetical order with the number of occurrances of each variable.

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

## Lexical analysis

This is an analysis of the components of variable name composition.

### Nouns used

These are the "things" recognized by the Senzing API.

| Noun         | Comment |
|--------------|---------|
| Buffer       | An internal memory space. |
| Config       | The Senzing engine configuration. |
| DataSource   | An identifier of the provenance of a set of records. |
| Dsrc         | A Senzing "Entity".|
| Entity       | A Senzing-constructed representation of a set of records. |
| Error        ||
| Feature      ||
| Flags        | Specification of output contents. |
| Info         ||
| LibFeat      ||
| License      ||
| Load         ||
| Logging      | Refers to Senzing log information to STDERR. |
| Module       ||
| Parameters   ||
| Record       | A customer "record". |
| Relationship | A discovered relationship between entities. |
| Response     ||
| Search       ||

### Adjectives used

These are attributes of the "things" listed above.

| Adjective | Comment |
|-----------|---------|
| Code      ||
| Comments  ||
| Degree    ||
| Excluded  ||
| FilePath  ||
| Handle    ||
| ID        ||
| Init      ||
| List      ||
| Max       ||
| Min       ||
| Name      ||
| New       ||
| Old       ||
| Profile   ||
| QueryList ||
| Required  ||
| Size      ||
| Type      ||
| Verbose   ||

### Misc

These variables are somewhat outliers.
Many do contain a known noun or adjective,
but still are unique in their construction.

| Variable                | Comment |
|-------------------------|---------|
| buildOutDegree          ||
| csvColumnList           ||
| entityListBySizeHandle  | Oddly, only "by" is not listed above.|
| includeInternalFeatures ||
| lastModifiedTime        ||
| maximumEstimatedCount   ||
| ptr                     ||
| resizeFunc              ||
| secondsToRun            ||
