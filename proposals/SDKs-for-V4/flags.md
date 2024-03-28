# Flags

Flags are 64..1 bits.

Reference:  [libg2.h](libg2.h)

## Bits

| Bit | Flag variable names |
|----:|---------------------|
|  64 | [sign bit for int64](#sign-bit-for-int64) |
|  63 | [WITH_INFO](#sz_with_info) |
|  62 | [reserved-for-sdks](#reserved-for-sdks) |
|  61 | [reserved-for-sdks](#reserved-for-sdks) |
|  60 | [reserved-for-sdks](#reserved-for-sdks) |
|  59 | [reserved-for-sdks](#reserved-for-sdks) |
|  58 | [reserved-for-sdks](#reserved-for-sdks) |
|  57 | [reserved-for-sdks](#reserved-for-sdks) |
|  56 | [](#unused) |
|  55 | [](#unused) |
|  54 | [](#unused) |
|  53 | [](#unused) |
|  52 | [](#unused) |
|  51 | [](#unused) |
|  50 | [](#unused) |
|  49 | [](#unused) |
|  48 | [](#unused) |
|  47 | [](#unused) |
|  46 | [](#unused) |
|  45 | [](#unused) |
|  44 | [](#unused) |
|  43 | [](#unused) |
|  42 | [](#unused) |
|  41 | [](#unused) |
|  40 | [](#unused) |
|  39 | [](#unused) |
|  38 | [](#unused) |
|  37 | [](#unused) |
|  36 | [](#unused) |
|  35 | [SZ_ENTITY_OPTION_INCLUDE_MATCH_KEY_DETAILS](#sz_entity_option_include_match_key_details), [SZ_SEARCH_INCLUDE_MATCH_KEY_DETAILS](#sz_search_include_match_key_details) |
|  34 | [SZ_FIND_NETWORK_MATCHING_INFO](#sz_find_network_matching_info) |
|  33 | [SZ_ENTITY_OPTION_INCLUDE_FEATURE_ELEMENTS](#sz_entity_option_include_feature_elements) |
|  32 | [SZ_ENTITY_INCLUDE_RECORD_UNMAPPED_DATA](#sz_entity_include_record_unmapped_data) |
|  31 | [SZ_FIND_PATH_MATCHING_INFO](#sz_find_path_matching_info) |
|  30 | [SZ_ENTITY_INCLUDE_RELATED_RECORD_TYPES](#sz_entity_include_related_record_types) |
|  29 | [SZ_ENTITY_INCLUDE_RECORD_TYPES](#sz_entity_include_record_types) |
|  28 | [SZ_SEARCH_INCLUDE_STATS](#sz_search_include_stats) |
|  27 | [SZ_INCLUDE_FEATURE_SCORES](#sz_include_feature_scores), [SZ_SEARCH_INCLUDE_FEATURE_SCORES](#sz_search_include_feature_scores) |
|  26 | [SZ_FIND_PATH_PREFER_EXCLUDE](#sz_find_path_prefer_exclude) |
|  25 | [SZ_ENTITY_OPTION_INCLUDE_FEATURE_STATS](#sz_entity_option_include_feature_stats) |
|  24 | [SZ_ENTITY_OPTION_INCLUDE_INTERNAL_FEATURES](#sz_entity_option_include_internal_features) |
|  23 | [SZ_ENTITY_INCLUDE_RELATED_RECORD_DATA](#sz_entity_include_related_record_data) |
|  22 | [SZ_ENTITY_INCLUDE_RELATED_RECORD_SUMMARY](#sz_entity_include_related_record_summary) |
|  21 | [SZ_ENTITY_INCLUDE_RELATED_MATCHING_INFO](#sz_entity_include_related_matching_info) |
|  20 | [SZ_ENTITY_INCLUDE_RELATED_ENTITY_NAME](#sz_entity_include_related_entity_name) |
|  19 | [SZ_ENTITY_INCLUDE_RECORD_FEATURE_IDS](#sz_entity_include_record_feature_ids) |
|  18 | [](#unused) |
|  17 | [SZ_ENTITY_INCLUDE_RECORD_JSON_DATA](#sz_entity_include_record_json_data) |
|  16 | [SZ_ENTITY_INCLUDE_RECORD_MATCHING_INFO](#sz_entity_include_record_matching_info) |
|  15 | [SZ_ENTITY_INCLUDE_RECORD_DATA](#sz_entity_include_record_data) |
|  14 | [SZ_ENTITY_INCLUDE_RECORD_SUMMARY](#sz_entity_include_record_summary) |
|  13 | [SZ_ENTITY_INCLUDE_ENTITY_NAME](#sz_entity_include_entity_name) |
|  12 | [SZ_ENTITY_INCLUDE_REPRESENTATIVE_FEATURES](#sz_entity_include_representative_features) |
|  11 | [SZ_ENTITY_INCLUDE_ALL_FEATURES](#sz_entity_include_all_features) |
|  10 | [SZ_ENTITY_INCLUDE_DISCLOSED_RELATIONS](#sz_entity_include_disclosed_relations) |
|   9 | [SZ_ENTITY_INCLUDE_NAME_ONLY_RELATIONS](#sz_entity_include_name_only_relations) |
|   8 | [SZ_ENTITY_INCLUDE_POSSIBLY_RELATED_RELATIONS](#sz_entity_include_possibly_related_relations) |
|   7 | [SZ_ENTITY_INCLUDE_POSSIBLY_SAME_RELATIONS](#sz_entity_include_possibly_same_relations) |
|   6 | [SZ_EXPORT_INCLUDE_SINGLE_RECORD_ENTITIES](#sz_export_include_single_record_entities) |
|   5 | [SZ_EXPORT_INCLUDE_DISCLOSED](#sz_export_include_disclosed) |
|   4 | [SZ_EXPORT_INCLUDE_NAME_ONLY](#sz_export_include_name_only), [SZ_SEARCH_INCLUDE_NAME_ONLY](#sz_search_include_name_only) |
|   3 | [SZ_EXPORT_INCLUDE_POSSIBLY_RELATED](#sz_export_include_possibly_related), [SZ_SEARCH_INCLUDE_POSSIBLY_RELATED](#sz_search_include_possibly_related) |
|   2 | [SZ_EXPORT_INCLUDE_POSSIBLY_SAME](#sz_export_include_possibly_same), [SZ_SEARCH_INCLUDE_POSSIBLY_SAME](#sz_search_include_possibly_same) |
|   1 | [SZ_EXPORT_INCLUDE_MULTI_RECORD_ENTITIES](#sz_export_include_multi_record_entities), [SZ_SEARCH_INCLUDE_RESOLVED](#sz_search_include_resolved) |

## Aggregates

Although the **Bits** column shows 4 4-digit values, it is meant to be read as a 64-bit hexadecimal number.
For instance, the value for `SZ_ENTITY_BRIEF_DEFAULT_FLAGS` is `0000 0000 0010 83C0`.
The **Bits** column calculated by [flags.py](flags.py).

| Flag variable name | Aggregates | Bits |
|--------------------|------------|-----:|
| [SZ_ENTITY_BRIEF_DEFAULT_FLAGS](#sz_entity_brief_default_flags) | [SZ_ENTITY_INCLUDE_ALL_RELATIONS](#sz_entity_include_all_relations), [SZ_ENTITY_INCLUDE_RECORD_MATCHING_INFO](#sz_entity_include_record_matching_info), [SZ_ENTITY_INCLUDE_RELATED_MATCHING_INFO](#sz_entity_include_related_matching_info), | 0000 0000 0010 83C0 |
| [SZ_ENTITY_DEFAULT_FLAGS](#sz_entity_default_flags) | [SZ_ENTITY_INCLUDE_ALL_RELATIONS](#sz_entity_include_all_relations), [SZ_ENTITY_INCLUDE_ENTITY_NAME](#sz_entity_include_entity_name), [SZ_ENTITY_INCLUDE_RECORD_DATA](#sz_entity_include_record_data), [SZ_ENTITY_INCLUDE_RECORD_MATCHING_INFO](#sz_entity_include_record_matching_info), [SZ_ENTITY_INCLUDE_RECORD_SUMMARY](#sz_entity_include_record_summary), [SZ_ENTITY_INCLUDE_RELATED_ENTITY_NAME](#sz_entity_include_related_entity_name), [SZ_ENTITY_INCLUDE_RELATED_MATCHING_INFO](#sz_entity_include_related_matching_info),  [SZ_ENTITY_INCLUDE_RELATED_RECORD_SUMMARY](#sz_entity_include_related_record_summary), [SZ_ENTITY_INCLUDE_REPRESENTATIVE_FEATURES](#sz_entity_include_representative_features) | 0000 0000 0038 FBC0 |
| [SZ_ENTITY_INCLUDE_ALL_RELATIONS](#sz_entity_include_all_relations) | [SZ_ENTITY_INCLUDE_DISCLOSED_RELATIONS](#sz_entity_include_disclosed_relations), [SZ_ENTITY_INCLUDE_NAME_ONLY_RELATIONS](#sz_entity_include_name_only_relations), [SZ_ENTITY_INCLUDE_POSSIBLY_RELATED_RELATIONS](#sz_entity_include_possibly_related_relations), [SZ_ENTITY_INCLUDE_POSSIBLY_SAME_RELATIONS](#sz_entity_include_possibly_same_relations) | 0000 0000 0000 03C0 |
| [SZ_EXPORT_DEFAULT_FLAGS](#sz_export_default_flags) | [SZ_ENTITY_DEFAULT_FLAGS](#sz_entity_default_flags), [SZ_EXPORT_INCLUDE_ALL_ENTITIES](#sz_export_include_all_entities) | 0000 0000 0038 FBE1 |
| [SZ_EXPORT_INCLUDE_ALL_ENTITIES](#sz_export_include_all_entities) | [SZ_EXPORT_INCLUDE_MULTI_RECORD_ENTITIES](#sz_export_include_multi_record_entities), [SZ_EXPORT_INCLUDE_SINGLE_RECORD_ENTITIES](#sz_export_include_single_record_entities) | 0000 0000 0000 0021 |
| [SZ_EXPORT_INCLUDE_ALL_HAVING_RELATIONSHIPS](#sz_export_include_all_having_relationships) | [SZ_EXPORT_INCLUDE_DISCLOSED](#sz_export_include_disclosed), [SZ_EXPORT_INCLUDE_NAME_ONLY](#sz_export_include_name_only), [SZ_EXPORT_INCLUDE_POSSIBLY_RELATED](#sz_export_include_possibly_related), [SZ_EXPORT_INCLUDE_POSSIBLY_SAME](#sz_export_include_possibly_same) | 0000 0000 0000 001E |
| [SZ_FIND_NETWORK_DEFAULT_FLAGS](#sz_find_network_default_flags) | [SZ_ENTITY_INCLUDE_ENTITY_NAME](#sz_entity_include_entity_name), [SZ_ENTITY_INCLUDE_RECORD_SUMMARY](#sz_entity_include_record_summary), [SZ_FIND_NETWORK_MATCHING_INFO](#sz_find_network_matching_info) | 0000 0002 0000 3000 |
| [SZ_FIND_PATH_DEFAULT_FLAGS](#sz_find_path_default_flags) | [SZ_ENTITY_INCLUDE_ENTITY_NAME](#sz_entity_include_entity_name), [SZ_ENTITY_INCLUDE_RECORD_SUMMARY](#sz_entity_include_record_summary), [SZ_FIND_PATH_MATCHING_INFO](#sz_find_path_matching_info) | 0000 0000 4000 3000 |
| [SZ_HOW_ENTITY_DEFAULT_FLAGS](#sz_how_entity_default_flags) | [SZ_INCLUDE_FEATURE_SCORES](#sz_include_feature_scores) | 0000 0000 0400 0000 |
| [SZ_RECORD_DEFAULT_FLAGS](#sz_record_default_flags) | [SZ_ENTITY_INCLUDE_RECORD_JSON_DATA](#sz_entity_include_record_json_data) | 0000 0000 0001 0000 |
| [SZ_SEARCH_BY_ATTRIBUTES_ALL](#sz_search_by_attributes_all) | [SZ_ENTITY_INCLUDE_ENTITY_NAME](#sz_entity_include_entity_name), [SZ_ENTITY_INCLUDE_RECORD_SUMMARY](#sz_entity_include_record_summary), [SZ_ENTITY_INCLUDE_REPRESENTATIVE_FEATURES](#sz_entity_include_representative_features), [SZ_SEARCH_INCLUDE_ALL_ENTITIES](#sz_search_include_all_entities), [SZ_SEARCH_INCLUDE_FEATURE_SCORES](#sz_search_include_feature_scores) | 0000 0000 0400 380F |
| [SZ_SEARCH_BY_ATTRIBUTES_DEFAULT_FLAGS](#sz_search_by_attributes_default_flags) | [SZ_SEARCH_BY_ATTRIBUTES_ALL](#sz_search_by_attributes_all) | 0000 0000 0400 380F |
| [SZ_SEARCH_BY_ATTRIBUTES_MINIMAL_ALL](#sz_search_by_attributes_minimal_all) | [SZ_SEARCH_INCLUDE_ALL_ENTITIES](#sz_search_include_all_entities) | 0000 0000 0000 000F |
| [SZ_SEARCH_BY_ATTRIBUTES_MINIMAL_STRONG](#sz_search_by_attributes_minimal_strong) | [SZ_SEARCH_INCLUDE_POSSIBLY_SAME](#sz_search_include_possibly_same), [SZ_SEARCH_INCLUDE_RESOLVED](#sz_search_include_resolved) | 0000 0000 0000 0003 |
| [SZ_SEARCH_BY_ATTRIBUTES_STRONG](#sz_search_by_attributes_strong) | [SZ_ENTITY_INCLUDE_ENTITY_NAME](#sz_entity_include_entity_name), [SZ_ENTITY_INCLUDE_RECORD_SUMMARY](#sz_entity_include_record_summary), [SZ_ENTITY_INCLUDE_REPRESENTATIVE_FEATURES](#sz_entity_include_representative_features), [SZ_SEARCH_INCLUDE_FEATURE_SCORES](#sz_search_include_feature_scores), [SZ_SEARCH_INCLUDE_POSSIBLY_SAME](#sz_search_include_possibly_same), [SZ_SEARCH_INCLUDE_RESOLVED](#sz_search_include_resolved) | 0000 0000 0400 3803 |
| [SZ_SEARCH_INCLUDE_ALL_ENTITIES](#sz_search_include_all_entities) | [SZ_SEARCH_INCLUDE_NAME_ONLY](#sz_search_include_name_only), [SZ_SEARCH_INCLUDE_POSSIBLY_RELATED](#sz_search_include_possibly_related), [SZ_SEARCH_INCLUDE_POSSIBLY_SAME](#sz_search_include_possibly_same), [SZ_SEARCH_INCLUDE_RESOLVED](#sz_search_include_resolved) | 0000 0000 0000 000F |
| [SZ_VIRTUAL_ENTITY_DEFAULT_FLAGS](#sz_virtual_entity_default_flags) | [SZ_ENTITY_DEFAULT_FLAGS](#sz_entity_default_flags) | 0000 0000 0038 FBC0 |
| [SZ_WHY_ENTITIES_DEFAULT_FLAGS](#sz_why_entities_default_flags) | [SZ_ENTITY_DEFAULT_FLAGS](#sz_entity_default_flags), [SZ_ENTITY_OPTION_INCLUDE_FEATURE_STATS](#sz_entity_option_include_feature_stats), [SZ_ENTITY_OPTION_INCLUDE_INTERNAL_FEATURES](#sz_entity_option_include_internal_features), [SZ_INCLUDE_FEATURE_SCORES](#sz_include_feature_scores) | 0000 0000 05B8 FBC0 |
| [SZ_WHY_RECORD_IN_ENTITY_DEFAULT_FLAGS](#sz_why_record_in_entity_default_flags) | [SZ_ENTITY_DEFAULT_FLAGS](#sz_entity_default_flags), [SZ_ENTITY_OPTION_INCLUDE_FEATURE_STATS](#sz_entity_option_include_feature_stats), [SZ_ENTITY_OPTION_INCLUDE_INTERNAL_FEATURES](#sz_entity_option_include_internal_features), [SZ_INCLUDE_FEATURE_SCORES](#sz_include_feature_scores) | 0000 0000 05B8 FBC0 |
| [SZ_WHY_RECORDS_DEFAULT_FLAGS](#sz_why_records_default_flags) | [SZ_ENTITY_DEFAULT_FLAGS](#sz_entity_default_flags), [SZ_ENTITY_OPTION_INCLUDE_FEATURE_STATS](#sz_entity_option_include_feature_stats), [SZ_ENTITY_OPTION_INCLUDE_INTERNAL_FEATURES](#sz_entity_option_include_internal_features), [SZ_INCLUDE_FEATURE_SCORES](#sz_include_feature_scores) | 0000 0000 05B8 FBC0 |

## Flag names

### SZ_ENTITY_BRIEF_DEFAULT_FLAGS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_ENTITY_BRIEF_DEFAULT_FLAGS&type=code):
    1. xxxXxxxx()

### SZ_ENTITY_DEFAULT_FLAGS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_ENTITY_DEFAULT_FLAGS&type=code):
    1. xxxXxxxx()

### SZ_ENTITY_INCLUDE_ALL_FEATURES

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
        - [Example output](https://docs.senzing.com/flags/index.html#sz_entity_include_all_features)
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_ENTITY_INCLUDE_ALL_FEATURES&type=code):
    1. xxxXxxxx()

### SZ_ENTITY_INCLUDE_ALL_RELATIONS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_ENTITY_INCLUDE_ALL_RELATIONS&type=code):
    1. xxxXxxxx()

### SZ_ENTITY_INCLUDE_DISCLOSED_RELATIONS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
        - [Example output](https://docs.senzing.com/flags/index.html#sz_entity_include_disclosed_relations)
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_ENTITY_INCLUDE_DISCLOSED_RELATIONS&type=code):
    1. xxxXxxxx()

### SZ_ENTITY_INCLUDE_ENTITY_NAME

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
        - [Example output](https://docs.senzing.com/flags/index.html#sz_entity_include_entity_name)
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_ENTITY_INCLUDE_ENTITY_NAME&type=code):
    1. xxxXxxxx()

### SZ_ENTITY_INCLUDE_NAME_ONLY_RELATIONS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
        - [Example output](https://docs.senzing.com/flags/index.html#sz_entity_include_name_only_relations)
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_ENTITY_INCLUDE_NAME_ONLY_RELATIONS&type=code):
    1. xxxXxxxx()

### SZ_ENTITY_INCLUDE_POSSIBLY_RELATED_RELATIONS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
        - [Example output](https://docs.senzing.com/flags/index.html#sz_entity_include_possibly_related_relations)
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_ENTITY_INCLUDE_POSSIBLY_RELATED_RELATIONS&type=code):
    1. xxxXxxxx()

### SZ_ENTITY_INCLUDE_POSSIBLY_SAME_RELATIONS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_ENTITY_INCLUDE_POSSIBLY_SAME_RELATIONS&type=code):
    1. xxxXxxxx()

### SZ_ENTITY_INCLUDE_RECORD_DATA

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
        - [Example output](https://docs.senzing.com/flags/index.html#sz_entity_include_record_data)
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_ENTITY_INCLUDE_RECORD_DATA&type=code):
    1. xxxXxxxx()

### SZ_ENTITY_INCLUDE_RECORD_FEATURE_IDS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
        - [Example output](https://docs.senzing.com/flags/index.html#sz_entity_include_record_feature_ids)
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_ENTITY_INCLUDE_RECORD_FEATURE_IDS&type=code):
    1. xxxXxxxx()

### SZ_ENTITY_INCLUDE_RECORD_JSON_DATA

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
        - [Example output](https://docs.senzing.com/flags/index.html#sz_entity_include_record_json_data)
        - [Example output](https://docs.senzing.com/flags/index.html#sz_entity_include_record_json_data-1)
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_ENTITY_INCLUDE_RECORD_JSON_DATA&type=code):
    1. xxxXxxxx()

### SZ_ENTITY_INCLUDE_RECORD_MATCHING_INFO

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
        - [Example output](https://docs.senzing.com/flags/index.html#sz_entity_include_record_matching_info)
        - [Example output](https://docs.senzing.com/flags/index.html#sz_entity_include_record_matching_info-1)
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_ENTITY_INCLUDE_RECORD_MATCHING_INFO&type=code):
    1. xxxXxxxx()

### SZ_ENTITY_INCLUDE_RECORD_SUMMARY

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
        - [Example output](https://docs.senzing.com/flags/index.html#sz_entity_include_record_summary)
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_ENTITY_INCLUDE_RECORD_SUMMARY&type=code):
    1. xxxXxxxx()

### SZ_ENTITY_INCLUDE_RECORD_TYPES

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_ENTITY_INCLUDE_RECORD_TYPES&type=code):
    1. xxxXxxxx()

### SZ_ENTITY_INCLUDE_RECORD_UNMAPPED_DATA

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_ENTITY_INCLUDE_RECORD_UNMAPPED_DATA&type=code):
    1. xxxXxxxx()

### SZ_ENTITY_INCLUDE_RELATED_ENTITY_NAME

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
        - [Example output](https://docs.senzing.com/flags/index.html#sz_entity_include_related_entity_name)
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_ENTITY_INCLUDE_RELATED_ENTITY_NAME&type=code):
    1. xxxXxxxx()

### SZ_ENTITY_INCLUDE_RELATED_MATCHING_INFO

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
        - [Example output](https://docs.senzing.com/flags/index.html#sz_entity_include_related_matching_info)
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_ENTITY_INCLUDE_RELATED_MATCHING_INFO&type=code):
    1. xxxXxxxx()

### SZ_ENTITY_INCLUDE_RELATED_RECORD_DATA

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
        - [Example output](https://docs.senzing.com/flags/index.html#sz_entity_include_related_record_data)
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_ENTITY_INCLUDE_RELATED_RECORD_DATA&type=code):
    1. xxxXxxxx()

### SZ_ENTITY_INCLUDE_RELATED_RECORD_SUMMARY

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
        - [Example output](https://docs.senzing.com/flags/index.html#sz_entity_include_related_record_summary)
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_ENTITY_INCLUDE_RELATED_RECORD_SUMMARY&type=code):
    1. xxxXxxxx()

### SZ_ENTITY_INCLUDE_RELATED_RECORD_TYPES

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_ENTITY_INCLUDE_RELATED_RECORD_TYPES&type=code):
    1. xxxXxxxx()

### SZ_ENTITY_INCLUDE_REPRESENTATIVE_FEATURES

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
        - [Example output](https://docs.senzing.com/flags/index.html#sz_entity_include_representative_features)
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_ENTITY_INCLUDE_REPRESENTATIVE_FEATURES&type=code):
    1. xxxXxxxx()

### SZ_ENTITY_OPTION_INCLUDE_FEATURE_ELEMENTS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_ENTITY_OPTION_INCLUDE_FEATURE_ELEMENTS&type=code):
    1. xxxXxxxx()

### SZ_ENTITY_OPTION_INCLUDE_FEATURE_STATS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
        - [Example output](https://docs.senzing.com/flags/index.html#sz_entity_option_include_feature_stats)
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_ENTITY_OPTION_INCLUDE_FEATURE_STATS&type=code):
    1. xxxXxxxx()

### SZ_ENTITY_OPTION_INCLUDE_INTERNAL_FEATURES

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
        - [Example output](https://docs.senzing.com/flags/index.html#sz_entity_option_include_internal_features)
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_ENTITY_OPTION_INCLUDE_INTERNAL_FEATURES&type=code):
    1. xxxXxxxx()

### SZ_ENTITY_OPTION_INCLUDE_MATCH_KEY_DETAILS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_ENTITY_OPTION_INCLUDE_MATCH_KEY_DETAILS&type=code):
    1. xxxXxxxx()

### SZ_EXPORT_DEFAULT_FLAGS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_EXPORT_DEFAULT_FLAGS&type=code):
    1. xxxXxxxx()

### SZ_EXPORT_INCLUDE_ALL_ENTITIES

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_EXPORT_INCLUDE_ALL_ENTITIES&type=code):
    1. xxxXxxxx()

### SZ_EXPORT_INCLUDE_ALL_HAVING_RELATIONSHIPS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_EXPORT_INCLUDE_ALL_HAVING_RELATIONSHIPS&type=code):
    1. xxxXxxxx()

### SZ_EXPORT_INCLUDE_DISCLOSED

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_EXPORT_INCLUDE_DISCLOSED&type=code):
    1. xxxXxxxx()

### SZ_EXPORT_INCLUDE_MULTI_RECORD_ENTITIES

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_EXPORT_INCLUDE_MULTI_RECORD_ENTITIES&type=code):
    1. xxxXxxxx()

### SZ_EXPORT_INCLUDE_NAME_ONLY

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_EXPORT_INCLUDE_NAME_ONLY&type=code):
    1. xxxXxxxx()

### SZ_EXPORT_INCLUDE_POSSIBLY_RELATED

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_EXPORT_INCLUDE_POSSIBLY_RELATED&type=code):
    1. xxxXxxxx()

### SZ_EXPORT_INCLUDE_POSSIBLY_SAME

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_EXPORT_INCLUDE_POSSIBLY_SAME&type=code):
    1. xxxXxxxx()

### SZ_EXPORT_INCLUDE_SINGLE_RECORD_ENTITIES

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_EXPORT_INCLUDE_SINGLE_RECORD_ENTITIES&type=code):
    1. xxxXxxxx()

### SZ_FIND_NETWORK_DEFAULT_FLAGS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_FIND_NETWORK_DEFAULT_FLAGS&type=code):
    1. xxxXxxxx()

### SZ_FIND_NETWORK_MATCHING_INFO

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_FIND_NETWORK_MATCHING_INFO&type=code):
    1. xxxXxxxx()

### SZ_FIND_PATH_DEFAULT_FLAGS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_FIND_PATH_DEFAULT_FLAGS&type=code):
    1. xxxXxxxx()

### SZ_FIND_PATH_MATCHING_INFO

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_FIND_PATH_MATCHING_INFO&type=code):
    1. xxxXxxxx()

### SZ_FIND_PATH_PREFER_EXCLUDE

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
        - [Example output](https://docs.senzing.com/flags/index.html#sz_find_path_prefer_exclude)
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_FIND_PATH_PREFER_EXCLUDE&type=code):
    1. xxxXxxxx()

### SZ_HOW_ENTITY_DEFAULT_FLAGS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_HOW_ENTITY_DEFAULT_FLAGS&type=code):
    1. xxxXxxxx()

### SZ_INCLUDE_FEATURE_SCORES

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_INCLUDE_FEATURE_SCORES&type=code):
    1. xxxXxxxx()

### SZ_RECORD_DEFAULT_FLAGS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_RECORD_DEFAULT_FLAGS&type=code):
    1. xxxXxxxx()

### SZ_SEARCH_BY_ATTRIBUTES_ALL

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
        - [Example output](https://docs.senzing.com/flags/index.html#sz_search_by_attributes_all)
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_SEARCH_BY_ATTRIBUTES_ALL&type=code):
    1. xxxXxxxx()

### SZ_SEARCH_BY_ATTRIBUTES_DEFAULT_FLAGS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_SEARCH_BY_ATTRIBUTES_DEFAULT_FLAGS&type=code):
    1. xxxXxxxx()

### SZ_SEARCH_BY_ATTRIBUTES_MINIMAL_ALL

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
        - [Example output](https://docs.senzing.com/flags/index.html#sz_search_by_attributes_minimal_all)
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_SEARCH_BY_ATTRIBUTES_MINIMAL_ALL&type=code):
    1. xxxXxxxx()

### SZ_SEARCH_BY_ATTRIBUTES_MINIMAL_STRONG

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
        - [Example output](https://docs.senzing.com/flags/index.html#sz_search_by_attributes_minimal_strong)
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_SEARCH_BY_ATTRIBUTES_MINIMAL_STRONG&type=code):
    1. xxxXxxxx()

### SZ_SEARCH_BY_ATTRIBUTES_STRONG

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
        - [Example output](https://docs.senzing.com/flags/index.html#sz_search_by_attributes_strong)
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_SEARCH_BY_ATTRIBUTES_STRONG&type=code):
    1. xxxXxxxx()

### SZ_SEARCH_INCLUDE_ALL_ENTITIES

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_SEARCH_INCLUDE_ALL_ENTITIES&type=code):
    1. xxxXxxxx()

### SZ_SEARCH_INCLUDE_FEATURE_SCORES

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
        - [Example output](https://docs.senzing.com/flags/index.html#sz_search_include_feature_scores)
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_SEARCH_INCLUDE_FEATURE_SCORES&type=code):
    1. xxxXxxxx()

### SZ_SEARCH_INCLUDE_MATCH_KEY_DETAILS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_SEARCH_INCLUDE_MATCH_KEY_DETAILS&type=code):
    1. xxxXxxxx()

### SZ_SEARCH_INCLUDE_NAME_ONLY

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_SEARCH_INCLUDE_NAME_ONLY&type=code):
    1. xxxXxxxx()

### SZ_SEARCH_INCLUDE_POSSIBLY_RELATED

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_SEARCH_INCLUDE_POSSIBLY_RELATED&type=code):
    1. xxxXxxxx()

### SZ_SEARCH_INCLUDE_POSSIBLY_SAME

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_SEARCH_INCLUDE_POSSIBLY_SAME&type=code):
    1. xxxXxxxx()

### SZ_SEARCH_INCLUDE_RESOLVED

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_SEARCH_INCLUDE_RESOLVED&type=code):
    1. xxxXxxxx()

### SZ_SEARCH_INCLUDE_STATS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
        - [Example output](https://docs.senzing.com/flags/index.html#sz_search_include_stats)
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_SEARCH_INCLUDE_STATS&type=code):
    1. xxxXxxxx()

### SZ_VIRTUAL_ENTITY_DEFAULT_FLAGS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_VIRTUAL_ENTITY_DEFAULT_FLAGS&type=code):
    1. xxxXxxxx()

### SZ_WHY_ENTITIES_DEFAULT_FLAGS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_WHY_ENTITIES_DEFAULT_FLAGS&type=code):
    1. xxxXxxxx()

### SZ_WHY_RECORD_IN_ENTITY_DEFAULT_FLAGS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_WHY_RECORD_IN_ENTITY_DEFAULT_FLAGS&type=code):
    1. xxxXxxxx()

### SZ_WHY_RECORDS_DEFAULT_FLAGS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+SZ_WHY_RECORDS_DEFAULT_FLAGS&type=code):
    1. xxxXxxxx()

### SZ_WITH_INFO

Specify if information should be returned from the method call.

1. **Values:**
    - 0: Return empty JSON string.  No information returned in the JSON.
    - 1: Return JSON string with information.
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+RETURN_INFO&type=code):
    1. addRecord()
    1. deleteRecord()
    1. process()
    1. reevaluateEntity()
    1. reevaluateRecord()
    1. replaceRecord()

### Reserved for SDKs

### Sign bit for int64

To put all bits in an `int64` (not a `uint64`) the sign bit must remain unused.

### Unused
