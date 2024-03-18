# Flags

Flags are 63..0 bits.

Reference:  [libg2.h](libg2.h)

## Bits

| Bit | Flag variable names |
|----:|---------------------|
|  63 | [sign bit for int64](#sign-bit-for-int64) |
|  62 | [G2_RETURN_INFO](#g2_return_info) |
|  61 | [reserved-for-sdks](#reserved-for-sdks) |
|  60 | [reserved-for-sdks](#reserved-for-sdks) |
|  59 | [reserved-for-sdks](#reserved-for-sdks) |
|  58 | [reserved-for-sdks](#reserved-for-sdks) |
|  57 | [reserved-for-sdks](#reserved-for-sdks) |
|  56 | [reserved-for-sdks](#reserved-for-sdks) |
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
|  35 | [](#unused) |
|  34 | [G2_ENTITY_OPTION_INCLUDE_MATCH_KEY_DETAILS](#g2_entity_option_include_match_key_details), [G2_SEARCH_INCLUDE_MATCH_KEY_DETAILS](#g2_search_include_match_key_details) |
|  33 | [G2_FIND_NETWORK_MATCHING_INFO](#g2_find_network_matching_info) |
|  32 | [G2_ENTITY_OPTION_INCLUDE_FEATURE_ELEMENTS](#g2_entity_option_include_feature_elements) |
|  31 | [G2_ENTITY_INCLUDE_RECORD_UNMAPPED_DATA](#g2_entity_include_record_unmapped_data) |
|  30 | [G2_FIND_PATH_MATCHING_INFO](#g2_find_path_matching_info) |
|  29 | [G2_ENTITY_INCLUDE_RELATED_RECORD_TYPES](#g2_entity_include_related_record_types) |
|  28 | [G2_ENTITY_INCLUDE_RECORD_TYPES](#g2_entity_include_record_types) |
|  27 | [G2_SEARCH_INCLUDE_STATS](#g2_search_include_stats) |
|  26 | [G2_INCLUDE_FEATURE_SCORES](#g2_include_feature_scores), [G2_SEARCH_INCLUDE_FEATURE_SCORES](#g2_search_include_feature_scores) |
|  25 | [G2_FIND_PATH_PREFER_EXCLUDE](#g2_find_path_prefer_exclude) |
|  24 | [G2_ENTITY_OPTION_INCLUDE_FEATURE_STATS](#g2_entity_option_include_feature_stats) |
|  23 | [G2_ENTITY_OPTION_INCLUDE_INTERNAL_FEATURES](#g2_entity_option_include_internal_features) |
|  22 | [G2_ENTITY_INCLUDE_RELATED_RECORD_DATA](#g2_entity_include_related_record_data) |
|  21 | [G2_ENTITY_INCLUDE_RELATED_RECORD_SUMMARY](#g2_entity_include_related_record_summary) |
|  20 | [G2_ENTITY_INCLUDE_RELATED_MATCHING_INFO](#g2_entity_include_related_matching_info) |
|  19 | [G2_ENTITY_INCLUDE_RELATED_ENTITY_NAME](#g2_entity_include_related_entity_name) |
|  18 | [G2_ENTITY_INCLUDE_RECORD_FEATURE_IDS](#g2_entity_include_record_feature_ids) |
|  17 | [](#unused) |
|  16 | [G2_ENTITY_INCLUDE_RECORD_JSON_DATA](#g2_entity_include_record_json_data) |
|  15 | [G2_ENTITY_INCLUDE_RECORD_MATCHING_INFO](#g2_entity_include_record_matching_info) |
|  14 | [G2_ENTITY_INCLUDE_RECORD_DATA](#g2_entity_include_record_data) |
|  13 | [G2_ENTITY_INCLUDE_RECORD_SUMMARY](#g2_entity_include_record_summary) |
|  12 | [G2_ENTITY_INCLUDE_ENTITY_NAME](#g2_entity_include_entity_name) |
|  11 | [G2_ENTITY_INCLUDE_REPRESENTATIVE_FEATURES](#g2_entity_include_representative_features) |
|  10 | [G2_ENTITY_INCLUDE_ALL_FEATURES](#g2_entity_include_all_features) |
|   9 | [G2_ENTITY_INCLUDE_DISCLOSED_RELATIONS](#g2_entity_include_disclosed_relations) |
|   8 | [G2_ENTITY_INCLUDE_NAME_ONLY_RELATIONS](#g2_entity_include_name_only_relations) |
|   7 | [G2_ENTITY_INCLUDE_POSSIBLY_RELATED_RELATIONS](#g2_entity_include_possibly_related_relations) |
|   6 | [G2_ENTITY_INCLUDE_POSSIBLY_SAME_RELATIONS](#g2_entity_include_possibly_same_relations) |
|   5 | [G2_EXPORT_INCLUDE_SINGLE_RECORD_ENTITIES](#g2_export_include_single_record_entities) |
|   4 | [G2_EXPORT_INCLUDE_DISCLOSED](#g2_export_include_disclosed) |
|   3 | [G2_EXPORT_INCLUDE_NAME_ONLY](#g2_export_include_name_only), [G2_SEARCH_INCLUDE_NAME_ONLY](#g2_search_include_name_only) |
|   2 | [G2_EXPORT_INCLUDE_POSSIBLY_RELATED](#g2_export_include_possibly_related), [G2_SEARCH_INCLUDE_POSSIBLY_RELATED](#g2_search_include_possibly_related) |
|   1 | [G2_EXPORT_INCLUDE_POSSIBLY_SAME](#g2_export_include_possibly_same), [G2_SEARCH_INCLUDE_POSSIBLY_SAME](#g2_search_include_possibly_same) |
|   0 | [G2_EXPORT_INCLUDE_MULTI_RECORD_ENTITIES](#g2_export_include_multi_record_entities), [G2_SEARCH_INCLUDE_RESOLVED](#g2_search_include_resolved) |

## Aggregates

Although the **Bits** column shows 4 4-digit values, it is meant to be read as a 64-bit hexadecimal number.
For instance, the value for `G2_ENTITY_BRIEF_DEFAULT_FLAGS` is `0000 0000 0010 83C0`.
The **Bits** column calculated by [flags.py](flags.py).

| Flag variable name | Aggregates | Bits |
|--------------------|------------|-----:|
| [G2_ENTITY_BRIEF_DEFAULT_FLAGS](#g2_entity_brief_default_flags) | [G2_ENTITY_INCLUDE_ALL_RELATIONS](#g2_entity_include_all_relations), [G2_ENTITY_INCLUDE_RECORD_MATCHING_INFO](#g2_entity_include_record_matching_info), [G2_ENTITY_INCLUDE_RELATED_MATCHING_INFO](#g2_entity_include_related_matching_info), | 0000 0000 0010 83C0 |
| [G2_ENTITY_DEFAULT_FLAGS](#g2_entity_default_flags) | [G2_ENTITY_INCLUDE_ALL_RELATIONS](#g2_entity_include_all_relations), [G2_ENTITY_INCLUDE_ENTITY_NAME](#g2_entity_include_entity_name), [G2_ENTITY_INCLUDE_RECORD_DATA](#g2_entity_include_record_data), [G2_ENTITY_INCLUDE_RECORD_MATCHING_INFO](#g2_entity_include_record_matching_info), [G2_ENTITY_INCLUDE_RECORD_SUMMARY](#g2_entity_include_record_summary), [G2_ENTITY_INCLUDE_RELATED_ENTITY_NAME](#g2_entity_include_related_entity_name), [G2_ENTITY_INCLUDE_RELATED_MATCHING_INFO](#g2_entity_include_related_matching_info),  [G2_ENTITY_INCLUDE_RELATED_RECORD_SUMMARY](#g2_entity_include_related_record_summary), [G2_ENTITY_INCLUDE_REPRESENTATIVE_FEATURES](#g2_entity_include_representative_features) | 0000 0000 0038 FBC0 |
| [G2_ENTITY_INCLUDE_ALL_RELATIONS](#g2_entity_include_all_relations) | [G2_ENTITY_INCLUDE_DISCLOSED_RELATIONS](#g2_entity_include_disclosed_relations), [G2_ENTITY_INCLUDE_NAME_ONLY_RELATIONS](#g2_entity_include_name_only_relations), [G2_ENTITY_INCLUDE_POSSIBLY_RELATED_RELATIONS](#g2_entity_include_possibly_related_relations), [G2_ENTITY_INCLUDE_POSSIBLY_SAME_RELATIONS](#g2_entity_include_possibly_same_relations) | 0000 0000 0000 03C0 |
| [G2_EXPORT_DEFAULT_FLAGS](#g2_export_default_flags) | [G2_ENTITY_DEFAULT_FLAGS](#g2_entity_default_flags), [G2_EXPORT_INCLUDE_ALL_ENTITIES](#g2_export_include_all_entities) | 0000 0000 0038 FBE1 |
| [G2_EXPORT_INCLUDE_ALL_ENTITIES](#g2_export_include_all_entities) | [G2_EXPORT_INCLUDE_MULTI_RECORD_ENTITIES](#g2_export_include_multi_record_entities), [G2_EXPORT_INCLUDE_SINGLE_RECORD_ENTITIES](#g2_export_include_single_record_entities) | 0000 0000 0000 0021 |
| [G2_EXPORT_INCLUDE_ALL_HAVING_RELATIONSHIPS](#g2_export_include_all_having_relationships) | [G2_EXPORT_INCLUDE_DISCLOSED](#g2_export_include_disclosed), [G2_EXPORT_INCLUDE_NAME_ONLY](#g2_export_include_name_only), [G2_EXPORT_INCLUDE_POSSIBLY_RELATED](#g2_export_include_possibly_related), [G2_EXPORT_INCLUDE_POSSIBLY_SAME](#g2_export_include_possibly_same) | 0000 0000 0000 001E |
| [G2_FIND_NETWORK_DEFAULT_FLAGS](#g2_find_network_default_flags) | [G2_ENTITY_INCLUDE_ENTITY_NAME](#g2_entity_include_entity_name), [G2_ENTITY_INCLUDE_RECORD_SUMMARY](#g2_entity_include_record_summary), [G2_FIND_NETWORK_MATCHING_INFO](#g2_find_network_matching_info) | 0000 0002 0000 3000 |
| [G2_FIND_PATH_DEFAULT_FLAGS](#g2_find_path_default_flags) | [G2_ENTITY_INCLUDE_ENTITY_NAME](#g2_entity_include_entity_name), [G2_ENTITY_INCLUDE_RECORD_SUMMARY](#g2_entity_include_record_summary), [G2_FIND_PATH_MATCHING_INFO](#g2_find_path_matching_info) | 0000 0000 4000 3000 |
| [G2_HOW_ENTITY_DEFAULT_FLAGS](#g2_how_entity_default_flags) | [G2_INCLUDE_FEATURE_SCORES](#g2_include_feature_scores) | 0000 0000 0400 0000 |
| [G2_RECORD_DEFAULT_FLAGS](#g2_record_default_flags) | [G2_ENTITY_INCLUDE_RECORD_JSON_DATA](#g2_entity_include_record_json_data) | 0000 0000 0001 0000 |
| [G2_SEARCH_BY_ATTRIBUTES_ALL](#g2_search_by_attributes_all) | [G2_ENTITY_INCLUDE_ENTITY_NAME](#g2_entity_include_entity_name), [G2_ENTITY_INCLUDE_RECORD_SUMMARY](#g2_entity_include_record_summary), [G2_ENTITY_INCLUDE_REPRESENTATIVE_FEATURES](#g2_entity_include_representative_features), [G2_SEARCH_INCLUDE_ALL_ENTITIES](#g2_search_include_all_entities), [G2_SEARCH_INCLUDE_FEATURE_SCORES](#g2_search_include_feature_scores) | 0000 0000 0400 380F |
| [G2_SEARCH_BY_ATTRIBUTES_DEFAULT_FLAGS](#g2_search_by_attributes_default_flags) | [G2_SEARCH_BY_ATTRIBUTES_ALL](#g2_search_by_attributes_all) | 0000 0000 0400 380F |
| [G2_SEARCH_BY_ATTRIBUTES_MINIMAL_ALL](#g2_search_by_attributes_minimal_all) | [G2_SEARCH_INCLUDE_ALL_ENTITIES](#g2_search_include_all_entities) | 0000 0000 0000 000F |
| [G2_SEARCH_BY_ATTRIBUTES_MINIMAL_STRONG](#g2_search_by_attributes_minimal_strong) | [G2_SEARCH_INCLUDE_POSSIBLY_SAME](#g2_search_include_possibly_same), [G2_SEARCH_INCLUDE_RESOLVED](#g2_search_include_resolved) | 0000 0000 0000 0003 |
| [G2_SEARCH_BY_ATTRIBUTES_STRONG](#g2_search_by_attributes_strong) | [G2_ENTITY_INCLUDE_ENTITY_NAME](#g2_entity_include_entity_name), [G2_ENTITY_INCLUDE_RECORD_SUMMARY](#g2_entity_include_record_summary), [G2_ENTITY_INCLUDE_REPRESENTATIVE_FEATURES](#g2_entity_include_representative_features), [G2_SEARCH_INCLUDE_FEATURE_SCORES](#g2_search_include_feature_scores), [G2_SEARCH_INCLUDE_POSSIBLY_SAME](#g2_search_include_possibly_same), [G2_SEARCH_INCLUDE_RESOLVED](#g2_search_include_resolved) | 0000 0000 0400 3803 |
| [G2_SEARCH_INCLUDE_ALL_ENTITIES](#g2_search_include_all_entities) | [G2_SEARCH_INCLUDE_NAME_ONLY](#g2_search_include_name_only), [G2_SEARCH_INCLUDE_POSSIBLY_RELATED](#g2_search_include_possibly_related), [G2_SEARCH_INCLUDE_POSSIBLY_SAME](#g2_search_include_possibly_same), [G2_SEARCH_INCLUDE_RESOLVED](#g2_search_include_resolved) | 0000 0000 0000 000F |
| [G2_VIRTUAL_ENTITY_DEFAULT_FLAGS](#g2_virtual_entity_default_flags) | [G2_ENTITY_DEFAULT_FLAGS](#g2_entity_default_flags) | 0000 0000 0038 FBC0 |
| [G2_WHY_ENTITIES_DEFAULT_FLAGS](#g2_why_entities_default_flags) | [G2_ENTITY_DEFAULT_FLAGS](#g2_entity_default_flags), [G2_ENTITY_OPTION_INCLUDE_FEATURE_STATS](#g2_entity_option_include_feature_stats), [G2_ENTITY_OPTION_INCLUDE_INTERNAL_FEATURES](#g2_entity_option_include_internal_features), [G2_INCLUDE_FEATURE_SCORES](#g2_include_feature_scores) | 0000 0000 05B8 FBC0 |
| [G2_WHY_RECORD_IN_ENTITY_DEFAULT_FLAGS](#g2_why_record_in_entity_default_flags) | [G2_ENTITY_DEFAULT_FLAGS](#g2_entity_default_flags), [G2_ENTITY_OPTION_INCLUDE_FEATURE_STATS](#g2_entity_option_include_feature_stats), [G2_ENTITY_OPTION_INCLUDE_INTERNAL_FEATURES](#g2_entity_option_include_internal_features), [G2_INCLUDE_FEATURE_SCORES](#g2_include_feature_scores) | 0000 0000 05B8 FBC0 |
| [G2_WHY_RECORDS_DEFAULT_FLAGS](#g2_why_records_default_flags) | [G2_ENTITY_DEFAULT_FLAGS](#g2_entity_default_flags), [G2_ENTITY_OPTION_INCLUDE_FEATURE_STATS](#g2_entity_option_include_feature_stats), [G2_ENTITY_OPTION_INCLUDE_INTERNAL_FEATURES](#g2_entity_option_include_internal_features), [G2_INCLUDE_FEATURE_SCORES](#g2_include_feature_scores) | 0000 0000 05B8 FBC0 |

## Flag names

### G2_ENTITY_BRIEF_DEFAULT_FLAGS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_ENTITY_BRIEF_DEFAULT_FLAGS&type=code):
    1. xxxXxxxx()

### G2_ENTITY_DEFAULT_FLAGS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_ENTITY_DEFAULT_FLAGS&type=code):
    1. xxxXxxxx()

### G2_ENTITY_INCLUDE_ALL_FEATURES

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
        - [Example output](https://docs.senzing.com/flags/index.html#g2_entity_include_all_features)
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_ENTITY_INCLUDE_ALL_FEATURES&type=code):
    1. xxxXxxxx()

### G2_ENTITY_INCLUDE_ALL_RELATIONS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_ENTITY_INCLUDE_ALL_RELATIONS&type=code):
    1. xxxXxxxx()

### G2_ENTITY_INCLUDE_DISCLOSED_RELATIONS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
        - [Example output](https://docs.senzing.com/flags/index.html#g2_entity_include_disclosed_relations)
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_ENTITY_INCLUDE_DISCLOSED_RELATIONS&type=code):
    1. xxxXxxxx()

### G2_ENTITY_INCLUDE_ENTITY_NAME

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
        - [Example output](https://docs.senzing.com/flags/index.html#g2_entity_include_entity_name)
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_ENTITY_INCLUDE_ENTITY_NAME&type=code):
    1. xxxXxxxx()

### G2_ENTITY_INCLUDE_NAME_ONLY_RELATIONS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
        - [Example output](https://docs.senzing.com/flags/index.html#g2_entity_include_name_only_relations)
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_ENTITY_INCLUDE_NAME_ONLY_RELATIONS&type=code):
    1. xxxXxxxx()

### G2_ENTITY_INCLUDE_POSSIBLY_RELATED_RELATIONS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
        - [Example output](https://docs.senzing.com/flags/index.html#g2_entity_include_possibly_related_relations)
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_ENTITY_INCLUDE_POSSIBLY_RELATED_RELATIONS&type=code):
    1. xxxXxxxx()

### G2_ENTITY_INCLUDE_POSSIBLY_SAME_RELATIONS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_ENTITY_INCLUDE_POSSIBLY_SAME_RELATIONS&type=code):
    1. xxxXxxxx()

### G2_ENTITY_INCLUDE_RECORD_DATA

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
        - [Example output](https://docs.senzing.com/flags/index.html#g2_entity_include_record_data)
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_ENTITY_INCLUDE_RECORD_DATA&type=code):
    1. xxxXxxxx()

### G2_ENTITY_INCLUDE_RECORD_FEATURE_IDS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
        - [Example output](https://docs.senzing.com/flags/index.html#g2_entity_include_record_feature_ids)
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_ENTITY_INCLUDE_RECORD_FEATURE_IDS&type=code):
    1. xxxXxxxx()

### G2_ENTITY_INCLUDE_RECORD_JSON_DATA

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
        - [Example output](https://docs.senzing.com/flags/index.html#g2_entity_include_record_json_data)
        - [Example output](https://docs.senzing.com/flags/index.html#g2_entity_include_record_json_data-1)
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_ENTITY_INCLUDE_RECORD_JSON_DATA&type=code):
    1. xxxXxxxx()

### G2_ENTITY_INCLUDE_RECORD_MATCHING_INFO

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
        - [Example output](https://docs.senzing.com/flags/index.html#g2_entity_include_record_matching_info)
        - [Example output](https://docs.senzing.com/flags/index.html#g2_entity_include_record_matching_info-1)
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_ENTITY_INCLUDE_RECORD_MATCHING_INFO&type=code):
    1. xxxXxxxx()

### G2_ENTITY_INCLUDE_RECORD_SUMMARY

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
        - [Example output](https://docs.senzing.com/flags/index.html#g2_entity_include_record_summary)
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_ENTITY_INCLUDE_RECORD_SUMMARY&type=code):
    1. xxxXxxxx()

### G2_ENTITY_INCLUDE_RECORD_TYPES

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_ENTITY_INCLUDE_RECORD_TYPES&type=code):
    1. xxxXxxxx()

### G2_ENTITY_INCLUDE_RECORD_UNMAPPED_DATA

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_ENTITY_INCLUDE_RECORD_UNMAPPED_DATA&type=code):
    1. xxxXxxxx()

### G2_ENTITY_INCLUDE_RELATED_ENTITY_NAME

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
        - [Example output](https://docs.senzing.com/flags/index.html#g2_entity_include_related_entity_name)
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_ENTITY_INCLUDE_RELATED_ENTITY_NAME&type=code):
    1. xxxXxxxx()

### G2_ENTITY_INCLUDE_RELATED_MATCHING_INFO

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
        - [Example output](https://docs.senzing.com/flags/index.html#g2_entity_include_related_matching_info)
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_ENTITY_INCLUDE_RELATED_MATCHING_INFO&type=code):
    1. xxxXxxxx()

### G2_ENTITY_INCLUDE_RELATED_RECORD_DATA

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
        - [Example output](https://docs.senzing.com/flags/index.html#g2_entity_include_related_record_data)
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_ENTITY_INCLUDE_RELATED_RECORD_DATA&type=code):
    1. xxxXxxxx()

### G2_ENTITY_INCLUDE_RELATED_RECORD_SUMMARY

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
        - [Example output](https://docs.senzing.com/flags/index.html#g2_entity_include_related_record_summary)
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_ENTITY_INCLUDE_RELATED_RECORD_SUMMARY&type=code):
    1. xxxXxxxx()

### G2_ENTITY_INCLUDE_RELATED_RECORD_TYPES

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_ENTITY_INCLUDE_RELATED_RECORD_TYPES&type=code):
    1. xxxXxxxx()

### G2_ENTITY_INCLUDE_REPRESENTATIVE_FEATURES

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
        - [Example output](https://docs.senzing.com/flags/index.html#g2_entity_include_representative_features)
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_ENTITY_INCLUDE_REPRESENTATIVE_FEATURES&type=code):
    1. xxxXxxxx()

### G2_ENTITY_OPTION_INCLUDE_FEATURE_ELEMENTS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_ENTITY_OPTION_INCLUDE_FEATURE_ELEMENTS&type=code):
    1. xxxXxxxx()

### G2_ENTITY_OPTION_INCLUDE_FEATURE_STATS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
        - [Example output](https://docs.senzing.com/flags/index.html#g2_entity_option_include_feature_stats)
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_ENTITY_OPTION_INCLUDE_FEATURE_STATS&type=code):
    1. xxxXxxxx()

### G2_ENTITY_OPTION_INCLUDE_INTERNAL_FEATURES

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
        - [Example output](https://docs.senzing.com/flags/index.html#g2_entity_option_include_internal_features)
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_ENTITY_OPTION_INCLUDE_INTERNAL_FEATURES&type=code):
    1. xxxXxxxx()

### G2_ENTITY_OPTION_INCLUDE_MATCH_KEY_DETAILS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_ENTITY_OPTION_INCLUDE_MATCH_KEY_DETAILS&type=code):
    1. xxxXxxxx()

### G2_EXPORT_DEFAULT_FLAGS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_EXPORT_DEFAULT_FLAGS&type=code):
    1. xxxXxxxx()

### G2_EXPORT_INCLUDE_ALL_ENTITIES

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_EXPORT_INCLUDE_ALL_ENTITIES&type=code):
    1. xxxXxxxx()

### G2_EXPORT_INCLUDE_ALL_HAVING_RELATIONSHIPS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_EXPORT_INCLUDE_ALL_HAVING_RELATIONSHIPS&type=code):
    1. xxxXxxxx()

### G2_EXPORT_INCLUDE_DISCLOSED

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_EXPORT_INCLUDE_DISCLOSED&type=code):
    1. xxxXxxxx()

### G2_EXPORT_INCLUDE_MULTI_RECORD_ENTITIES

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_EXPORT_INCLUDE_MULTI_RECORD_ENTITIES&type=code):
    1. xxxXxxxx()

### G2_EXPORT_INCLUDE_NAME_ONLY

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_EXPORT_INCLUDE_NAME_ONLY&type=code):
    1. xxxXxxxx()

### G2_EXPORT_INCLUDE_POSSIBLY_RELATED

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_EXPORT_INCLUDE_POSSIBLY_RELATED&type=code):
    1. xxxXxxxx()

### G2_EXPORT_INCLUDE_POSSIBLY_SAME

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_EXPORT_INCLUDE_POSSIBLY_SAME&type=code):
    1. xxxXxxxx()

### G2_EXPORT_INCLUDE_SINGLE_RECORD_ENTITIES

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_EXPORT_INCLUDE_SINGLE_RECORD_ENTITIES&type=code):
    1. xxxXxxxx()

### G2_FIND_NETWORK_DEFAULT_FLAGS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_FIND_NETWORK_DEFAULT_FLAGS&type=code):
    1. xxxXxxxx()

### G2_FIND_NETWORK_MATCHING_INFO

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_FIND_NETWORK_MATCHING_INFO&type=code):
    1. xxxXxxxx()

### G2_FIND_PATH_DEFAULT_FLAGS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_FIND_PATH_DEFAULT_FLAGS&type=code):
    1. xxxXxxxx()

### G2_FIND_PATH_MATCHING_INFO

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_FIND_PATH_MATCHING_INFO&type=code):
    1. xxxXxxxx()

### G2_FIND_PATH_PREFER_EXCLUDE

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
        - [Example output](https://docs.senzing.com/flags/index.html#g2_find_path_prefer_exclude)
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_FIND_PATH_PREFER_EXCLUDE&type=code):
    1. xxxXxxxx()

### G2_HOW_ENTITY_DEFAULT_FLAGS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_HOW_ENTITY_DEFAULT_FLAGS&type=code):
    1. xxxXxxxx()

### G2_INCLUDE_FEATURE_SCORES

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_INCLUDE_FEATURE_SCORES&type=code):
    1. xxxXxxxx()

### G2_RECORD_DEFAULT_FLAGS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_RECORD_DEFAULT_FLAGS&type=code):
    1. xxxXxxxx()

### G2_RETURN_INFO

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

### G2_SEARCH_BY_ATTRIBUTES_ALL

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
        - [Example output](https://docs.senzing.com/flags/index.html#g2_search_by_attributes_all)
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_SEARCH_BY_ATTRIBUTES_ALL&type=code):
    1. xxxXxxxx()

### G2_SEARCH_BY_ATTRIBUTES_DEFAULT_FLAGS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_SEARCH_BY_ATTRIBUTES_DEFAULT_FLAGS&type=code):
    1. xxxXxxxx()

### G2_SEARCH_BY_ATTRIBUTES_MINIMAL_ALL

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
        - [Example output](https://docs.senzing.com/flags/index.html#g2_search_by_attributes_minimal_all)
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_SEARCH_BY_ATTRIBUTES_MINIMAL_ALL&type=code):
    1. xxxXxxxx()

### G2_SEARCH_BY_ATTRIBUTES_MINIMAL_STRONG

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
        - [Example output](https://docs.senzing.com/flags/index.html#g2_search_by_attributes_minimal_strong)
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_SEARCH_BY_ATTRIBUTES_MINIMAL_STRONG&type=code):
    1. xxxXxxxx()

### G2_SEARCH_BY_ATTRIBUTES_STRONG

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
        - [Example output](https://docs.senzing.com/flags/index.html#g2_search_by_attributes_strong)
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_SEARCH_BY_ATTRIBUTES_STRONG&type=code):
    1. xxxXxxxx()

### G2_SEARCH_INCLUDE_ALL_ENTITIES

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_SEARCH_INCLUDE_ALL_ENTITIES&type=code):
    1. xxxXxxxx()

### G2_SEARCH_INCLUDE_FEATURE_SCORES

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
        - [Example output](https://docs.senzing.com/flags/index.html#g2_search_include_feature_scores)
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_SEARCH_INCLUDE_FEATURE_SCORES&type=code):
    1. xxxXxxxx()

### G2_SEARCH_INCLUDE_MATCH_KEY_DETAILS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_SEARCH_INCLUDE_MATCH_KEY_DETAILS&type=code):
    1. xxxXxxxx()

### G2_SEARCH_INCLUDE_NAME_ONLY

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_SEARCH_INCLUDE_NAME_ONLY&type=code):
    1. xxxXxxxx()

### G2_SEARCH_INCLUDE_POSSIBLY_RELATED

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_SEARCH_INCLUDE_POSSIBLY_RELATED&type=code):
    1. xxxXxxxx()

### G2_SEARCH_INCLUDE_POSSIBLY_SAME

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_SEARCH_INCLUDE_POSSIBLY_SAME&type=code):
    1. xxxXxxxx()

### G2_SEARCH_INCLUDE_RESOLVED

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_SEARCH_INCLUDE_RESOLVED&type=code):
    1. xxxXxxxx()

### G2_SEARCH_INCLUDE_STATS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
        - [Example output](https://docs.senzing.com/flags/index.html#g2_search_include_stats)
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_SEARCH_INCLUDE_STATS&type=code):
    1. xxxXxxxx()

### G2_VIRTUAL_ENTITY_DEFAULT_FLAGS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_VIRTUAL_ENTITY_DEFAULT_FLAGS&type=code):
    1. xxxXxxxx()

### G2_WHY_ENTITIES_DEFAULT_FLAGS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_WHY_ENTITIES_DEFAULT_FLAGS&type=code):
    1. xxxXxxxx()

### G2_WHY_RECORD_IN_ENTITY_DEFAULT_FLAGS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_WHY_RECORD_IN_ENTITY_DEFAULT_FLAGS&type=code):
    1. xxxXxxxx()

### G2_WHY_RECORDS_DEFAULT_FLAGS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+G2_WHY_RECORDS_DEFAULT_FLAGS&type=code):
    1. xxxXxxxx()

### Reserved for SDKs

### Sign bit for int64

To put all bits in an `int64` (not a `uint64`) the sign bit must remain unused.

### Unused
