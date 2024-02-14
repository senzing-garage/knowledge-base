# V3 to V4 Changes

## General

1. `loadID` parameter is removed from
    1. `addRecord()`
    1. `addRecordWithInfo()`
    1. `addRecordWithReturnedRecordID()`
    1. `addRecordWithInfoWithReturnedRecordID()`
    1. `replaceRecord()`
    1. `replaceRecordWithInfo()`
    1. `deleteRecord()`
    1. `deleteRecordWithInfo()`
1. `G2_FIND_PATH_DEFAULT_FLAGS` is replaced by `G2_FIND_NETWORK_DEFAULT_FLAGS`
    1. `findNetworkByEntityID()`
    1. `findNetworkByRecordID()`
1. `G2_WHY_ENTITY_DEFAULT_FLAGS` is replaced by `G2_WHY_RECORD_IN_ENTITY_DEFAULT_FLAGS`
    1. `whyRecordInEntity()`
1. `G2_HOW_ENTITY_DEFAULT_FLAGS` is replaced by `G2_VIRTUAL_ENTITY_DEFAULT_FLAGS`
    1. `getVirtualEntityByRecordID()`
1. `G2_WHY_ENTITY_DEFAULT_FLAGS` is replaced by `G2_WHY_ENTITIES_DEFAULT_FLAGS`
    1. `whyEntities()`
1. `G2_WHY_ENTITY_DEFAULT_FLAGS` is replaced by `G2_WHY_RECORDS_DEFAULT_FLAGS`
    1. `whyRecords()`
1. Added functions:
    1. G2Diagnostic
        1. `purgeRepository()`
1. Removed functions:
    1. G2Engine
        1. `whyEntityByRecordIDV2()`
        1. `whyEntityByRecordID()`
        1. `whyEntityByEntityIDV2()`
        1. `whyEntityByEntityID()`
        1. `purgeRepository()`
1. Renamed Flags

| Old Name                                | New Name                                   | Old Value | New Value  |
|-----------------------------------------|--------------------------------------------|---------------|----------------|
| G2_EXPORT_INCLUDE_RESOLVED              | G2_EXPORT_INCLUDE_MULTI_RECORD_ENTITIES    |     0000 0001 |  same          |
| G2_EXPORT_INCLUDE_SINGLETONS            | G2_EXPORT_INCLUDE_SINGLE_RECORD_ENTITIES   |     0000 0010 |  same          |
| G2_EXPORT_INCLUDE_ALL_RELATIONSHIPS     | G2_EXPORT_INCLUDE_ALL_HAVING_RELATIONSHIPS |     0000 001E |  same          |
| G2_ENTITY_INCLUDE_RECORD_FORMATTED_DATA | <deleted>                                  |     0002 0000 |                |
|                                         | G2_ENTITY_INCLUDE_RECORD_UNMAPPED_DATA     |               | 0000 8000 0000 |
|                                         | G2_ENTITY_INCLUDE_RELATED_RECORD_TYPES     |               | 0000 2000 0000 |
|                                         | G2_ENTITY_OPTION_INCLUDE_FEATURE_ELEMENTS  |               | 0001 0000 0000 |
|                                         | G2_ENTITY_OPTION_INCLUDE_MATCH_KEY_DETAILS |               | 0004 0000 0000 |
|                                         | G2_FIND_PATH_MATCHING_INFO                 |               | 0000 4000 0000 |
|                                         | G2_FIND_NETWORK_MATCHING_INFO              |               | 0002 0000 0000 |
|                                         | G2_SEARCH_INCLUDE_MATCH_KEY_DETAILS        |               | G2_ENTITY_OPTION_INCLUDE_MATCH_KEY_DETAILS |
| G2_SEARCH_INCLUDE_RESOLVED              |                                            |               | <has new value> |
| G2_EXPORT_DEFAULT_FLAGS                 |                                            |               | <has new value> |
| G2_FIND_PATH_DEFAULT_FLAGS              |                                            |               | <has new value> |
| G2_WHY_ENTITY_DEFAULT_FLAGS             | <deleted>                                  |               |                 |
| G2_HOW_ENTITY_DEFAULT_FLAGS             |                                            |               | <has new value> |
|                                         |  G2_VIRTUAL_ENTITY_DEFAULT_FLAGS           |               |                 |

## Python

- [g2-sdk-python diff](https://github.com/senzing-garage/g2-sdk-python/compare/main...develop-g2v4.0)
