# Flags

**Important:**  Current as of Senzing 3.8.0

Flags are 63..0 bits.

## Bits

| Bit | Names |
|----:|------|
|  63 | [RETURN_INFO](#return_info) |
|  62 | [reserved-for-sdks] |
|  61 | [reserved-for-sdks] |
|  60 | [reserved-for-sdks] |
|  59 | [reserved-for-sdks] |
|  58 | [reserved-for-sdks] |
|  57 | [reserved-for-sdks] |
|  56 | [reserved-for-sdks] |
|  55 | [](#) |
|  54 | [](#) |
|  53 | [](#) |
|  52 | [](#) |
|  51 | [](#) |
|  50 | [](#) |
|  49 | [](#) |
|  48 | [](#) |
|  47 | [](#) |
|  46 | [](#) |
|  45 | [](#) |
|  44 | [](#) |
|  43 | [](#) |
|  42 | [](#) |
|  41 | [](#) |
|  40 | [](#) |
|  39 | [](#) |
|  38 | [](#) |
|  37 | [](#) |
|  36 | [](#) |
|  35 | [](#) |
|  34 | [](#) |
|  33 | [](#) |
|  32 | [](#) |
|  31 | [](#) |
|  30 | [](#) |
|  29 | [](#) |
|  28 | [](#) |
|  27 | [G2_SEARCH_INCLUDE_STATS](#g2_search_include_stats) |
|  26 | [G2_INCLUDE_FEATURE_SCORES](#g2_include_feature_scores) |
|  25 | [G2_FIND_PATH_PREFER_EXCLUDE](#g2_find_path_prefer_exclude) |
|  24 | [G2_ENTITY_OPTION_INCLUDE_FEATURE_STATS](#g2_entity_option_include_feature_stats) |
|  23 | [G2_ENTITY_OPTION_INCLUDE_INTERNAL_FEATURES](#g2_entity_option_include_internal_features) |
|  22 | [G2_ENTITY_INCLUDE_RELATED_RECORD_DATA](#g2_entity_include_related_record_data) |
|  21 | [G2_ENTITY_INCLUDE_RELATED_RECORD_SUMMARY](#g2_entity_include_related_record_summary) |
|  20 | [G2_ENTITY_INCLUDE_RELATED_MATCHING_INFO](#g2_entity_include_related_matching_info) |
|  19 | [G2_ENTITY_INCLUDE_RELATED_ENTITY_NAME](#g2_entity_include_related_entity_name) |
|  18 | [G2_ENTITY_INCLUDE_RECORD_FEATURE_IDS](#g2_entity_include_record_feature_ids) |
|  17 | [G2_ENTITY_INCLUDE_RECORD_FORMATTED_DATA](#g2_entity_include_record_formatted_data) |
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
|   5 | [G2_EXPORT_INCLUDE_SINGLETONS](#g2_export_include_singletons) |
|   4 | [G2_EXPORT_INCLUDE_DISCLOSED](#g2_export_include_disclosed) |
|   3 | [G2_EXPORT_INCLUDE_NAME_ONLY](#g2_export_include_name_only) |
|   2 | [G2_EXPORT_INCLUDE_POSSIBLY_RELATED](#g2_export_include_possibly_related) |
|   1 | [G2_EXPORT_INCLUDE_POSSIBLY_SAME](#g2_export_include_possibly_same) |
|   0 | [G2_EXPORT_INCLUDE_RESOLVED](#g2_export_include_resolved) |

### G2_ENTITY_INCLUDE_ALL_FEATURES

### G2_ENTITY_INCLUDE_DISCLOSED_RELATIONS

### G2_ENTITY_INCLUDE_ENTITY_NAME

### G2_ENTITY_INCLUDE_NAME_ONLY_RELATIONS

### G2_ENTITY_INCLUDE_POSSIBLY_RELATED_RELATIONS

### G2_ENTITY_INCLUDE_POSSIBLY_SAME_RELATIONS

### G2_ENTITY_INCLUDE_RECORD_DATA

### G2_ENTITY_INCLUDE_RECORD_FEATURE_IDS

### G2_ENTITY_INCLUDE_RECORD_FORMATTED_DATA

### G2_ENTITY_INCLUDE_RECORD_JSON_DATA

### G2_ENTITY_INCLUDE_RECORD_MATCHING_INFO

### G2_ENTITY_INCLUDE_RECORD_SUMMARY

### G2_ENTITY_INCLUDE_RELATED_ENTITY_NAME

### G2_ENTITY_INCLUDE_RELATED_MATCHING_INFO

### G2_ENTITY_INCLUDE_RELATED_RECORD_DATA

### G2_ENTITY_INCLUDE_RELATED_RECORD_SUMMARY

### G2_ENTITY_INCLUDE_REPRESENTATIVE_FEATURES

### G2_ENTITY_OPTION_INCLUDE_FEATURE_STATS

### G2_ENTITY_OPTION_INCLUDE_INTERNAL_FEATURES

### G2_EXPORT_INCLUDE_DISCLOSED

### G2_EXPORT_INCLUDE_NAME_ONLY

### G2_EXPORT_INCLUDE_POSSIBLY_RELATED

### G2_EXPORT_INCLUDE_POSSIBLY_SAME

### G2_EXPORT_INCLUDE_RESOLVED

### G2_EXPORT_INCLUDE_SINGLETONS

### G2_FIND_PATH_PREFER_EXCLUDE

### G2_INCLUDE_FEATURE_SCORES

### G2_SEARCH_INCLUDE_STATS

### RETURN_INFO

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
