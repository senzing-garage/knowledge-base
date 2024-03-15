# Flags

**Important:**  Current as of Senzing 3.8.0

Flags are 63..0 bits.

## Bits

| Bit | Names |
|----:|------|
|  63 | [G2_RETURN_INFO](#g2_return_info) |
|  62 | [reserved-for-sdks] |
|  61 | [reserved-for-sdks] |
|  60 | [reserved-for-sdks] |
|  59 | [reserved-for-sdks] |
|  58 | [reserved-for-sdks] |
|  57 | [reserved-for-sdks] |
|  56 | [reserved-for-sdks] |
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
|  34 | [](#unused) |
|  33 | [](#unused) |
|  32 | [](#unused) |
|  31 | [](#unused) |
|  30 | [](#unused) |
|  29 | [](#unused) |
|  28 | [](#unused) |
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
|   3 | [G2_EXPORT_INCLUDE_NAME_ONLY](#g2_export_include_name_only), [G2_SEARCH_INCLUDE_NAME_ONLY](#g2_search_include_name_only) |
|   2 | [G2_EXPORT_INCLUDE_POSSIBLY_RELATED](#g2_export_include_possibly_related), [G2_SEARCH_INCLUDE_POSSIBLY_RELATED](#g2_search_include_possibly_related) |
|   1 | [G2_EXPORT_INCLUDE_POSSIBLY_SAME](#g2_export_include_possibly_same), [G2_SEARCH_INCLUDE_POSSIBLY_SAME](#g2_search_include_possibly_same) |
|   0 | [G2_EXPORT_INCLUDE_RESOLVED](#g2_export_include_resolved), [G2_SEARCH_INCLUDE_RESOLVED](#g2_search_include_resolved) |

## Aggregates

| Bits                 | Name | Aggregates |
|---------------------:|------|------------|
|  0000 0000 0000 0000 | [G2_EXPORT_INCLUDE_ALL_ENTITIES](#) | [G2_EXPORT_INCLUDE_RESOLVED](#), [G2_EXPORT_INCLUDE_RESOLVED](#) |
|  0000 0000 0000 0000 | [G2_EXPORT_INCLUDE_ALL_RELATIONSHIPS](#) | G2_EXPORT_INCLUDE_POSSIBLY_SAME, G2_EXPORT_INCLUDE_POSSIBLY_RELATED, G2_EXPORT_INCLUDE_NAME_ONLY, G2_EXPORT_INCLUDE_DISCLOSED |
|  0000 0000 0000 0000 | [G2_ENTITY_INCLUDE_ALL_RELATIONS](#) | G2_ENTITY_INCLUDE_POSSIBLY_SAME_RELATIONS, G2_ENTITY_INCLUDE_POSSIBLY_RELATED_RELATIONS, G2_ENTITY_INCLUDE_NAME_ONLY_RELATIONS, G2_ENTITY_INCLUDE_DISCLOSED_RELATIONS |
|  0000 0000 0000 0000 | [G2_SEARCH_INCLUDE_ALL_ENTITIES](#) | G2_SEARCH_INCLUDE_RESOLVED, G2_SEARCH_INCLUDE_POSSIBLY_SAME, G2_SEARCH_INCLUDE_POSSIBLY_RELATED, G2_SEARCH_INCLUDE_NAME_ONLY |
|  0000 0000 0000 0000 | [G2_RECORD_DEFAULT_FLAGS](#) | G2_ENTITY_INCLUDE_RECORD_JSON_DATA |
|  0000 0000 0000 0000 | [G2_ENTITY_DEFAULT_FLAGS](#) | G2_ENTITY_INCLUDE_ALL_RELATIONS, G2_ENTITY_INCLUDE_REPRESENTATIVE_FEATURES, G2_ENTITY_INCLUDE_ENTITY_NAME, G2_ENTITY_INCLUDE_RECORD_SUMMARY, G2_ENTITY_INCLUDE_RECORD_DATA, G2_ENTITY_INCLUDE_RECORD_MATCHING_INFO, G2_ENTITY_INCLUDE_RELATED_ENTITY_NAME, G2_ENTITY_INCLUDE_RELATED_RECORD_SUMMARY, G2_ENTITY_INCLUDE_RELATED_MATCHING_INFO |
|  0000 0000 0000 0000 | [G2_ENTITY_BRIEF_DEFAULT_FLAGS](#) | G2_ENTITY_INCLUDE_RECORD_MATCHING_INFO, G2_ENTITY_INCLUDE_ALL_RELATIONS, G2_ENTITY_INCLUDE_RELATED_MATCHING_INFO |
|  0000 0000 0000 0000 | [G2_EXPORT_DEFAULT_FLAGS](#) | G2_EXPORT_INCLUDE_ALL_ENTITIES, G2_EXPORT_INCLUDE_ALL_RELATIONSHIPS, G2_ENTITY_INCLUDE_ALL_RELATIONS, G2_ENTITY_INCLUDE_REPRESENTATIVE_FEATURES, G2_ENTITY_INCLUDE_ENTITY_NAME, G2_ENTITY_INCLUDE_RECORD_DATA, G2_ENTITY_INCLUDE_RECORD_MATCHING_INFO, G2_ENTITY_INCLUDE_RELATED_MATCHING_INFO |
|  0000 0000 0000 0000 | [G2_FIND_PATH_DEFAULT_FLAGS](#) | G2_ENTITY_INCLUDE_ALL_RELATIONS, G2_ENTITY_INCLUDE_ENTITY_NAME, G2_ENTITY_INCLUDE_RECORD_SUMMARY, G2_ENTITY_INCLUDE_RELATED_MATCHING_INFO |
|  0000 0000 0000 0000 | [G2_WHY_ENTITY_DEFAULT_FLAGS](#) | G2_ENTITY_DEFAULT_FLAGS, G2_ENTITY_INCLUDE_RECORD_FEATURE_IDS, G2_ENTITY_OPTION_INCLUDE_INTERNAL_FEATURES, G2_ENTITY_OPTION_INCLUDE_FEATURE_STATS, G2_INCLUDE_FEATURE_SCORES |
|  0000 0000 0000 0000 | [G2_HOW_ENTITY_DEFAULT_FLAGS](#) | G2_ENTITY_DEFAULT_FLAGS, G2_ENTITY_INCLUDE_RECORD_FEATURE_IDS, G2_ENTITY_OPTION_INCLUDE_INTERNAL_FEATURES, G2_ENTITY_OPTION_INCLUDE_FEATURE_STATS, G2_INCLUDE_FEATURE_SCORES |
|  0000 0000 0000 0000 | [G2_SEARCH_BY_ATTRIBUTES_ALL](#) | G2_SEARCH_INCLUDE_RESOLVED, G2_SEARCH_INCLUDE_POSSIBLY_SAME, G2_ENTITY_INCLUDE_REPRESENTATIVE_FEATURES, G2_ENTITY_INCLUDE_ENTITY_NAME, G2_ENTITY_INCLUDE_RECORD_SUMMARY, G2_SEARCH_INCLUDE_FEATURE_SCORES |
|  0000 0000 0000 0000 | [G2_SEARCH_BY_ATTRIBUTES_STRONG](#) | G2_SEARCH_INCLUDE_RESOLVED, G2_SEARCH_INCLUDE_POSSIBLY_SAME, G2_ENTITY_INCLUDE_REPRESENTATIVE_FEATURES, G2_ENTITY_INCLUDE_ENTITY_NAME, G2_ENTITY_INCLUDE_RECORD_SUMMARY, G2_SEARCH_INCLUDE_FEATURE_SCORES |
|  0000 0000 0000 0000 | [G2_SEARCH_BY_ATTRIBUTES_MINIMAL_ALL](#) | G2_SEARCH_INCLUDE_ALL_ENTITIES |
|  0000 0000 0000 0000 | [G2_SEARCH_BY_ATTRIBUTES_MINIMAL_STRONG](#) | G2_SEARCH_INCLUDE_RESOLVED, G2_SEARCH_INCLUDE_POSSIBLY_SAME |
|  0000 0000 0000 0000 | [G2_SEARCH_BY_ATTRIBUTES_DEFAULT_FLAGS](#) | G2_SEARCH_BY_ATTRIBUTES_ALL |

## Flag names

### G2_ENTITY_DEFAULT_FLAGS

### G2_ENTITY_INCLUDE_ALL_FEATURES

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+XXX_XXX&type=code):
    1. xxxXxxxx()

### G2_ENTITY_INCLUDE_DISCLOSED_RELATIONS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+XXX_XXX&type=code):
    1. xxxXxxxx()

### G2_ENTITY_INCLUDE_ENTITY_NAME

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+XXX_XXX&type=code):
    1. xxxXxxxx()

### G2_ENTITY_INCLUDE_NAME_ONLY_RELATIONS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+XXX_XXX&type=code):
    1. xxxXxxxx()

### G2_ENTITY_INCLUDE_POSSIBLY_RELATED_RELATIONS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+XXX_XXX&type=code):
    1. xxxXxxxx()

### G2_ENTITY_INCLUDE_POSSIBLY_SAME_RELATIONS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+XXX_XXX&type=code):
    1. xxxXxxxx()

### G2_ENTITY_INCLUDE_RECORD_DATA

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+XXX_XXX&type=code):
    1. xxxXxxxx()

### G2_ENTITY_INCLUDE_RECORD_FEATURE_IDS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+XXX_XXX&type=code):
    1. xxxXxxxx()

### G2_ENTITY_INCLUDE_RECORD_FORMATTED_DATA

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+XXX_XXX&type=code):
    1. xxxXxxxx()

### G2_ENTITY_INCLUDE_RECORD_JSON_DATA

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+XXX_XXX&type=code):
    1. xxxXxxxx()

### G2_ENTITY_INCLUDE_RECORD_MATCHING_INFO

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+XXX_XXX&type=code):
    1. xxxXxxxx()

### G2_ENTITY_INCLUDE_RECORD_SUMMARY

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+XXX_XXX&type=code):
    1. xxxXxxxx()

### G2_ENTITY_INCLUDE_RELATED_ENTITY_NAME

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+XXX_XXX&type=code):
    1. xxxXxxxx()

### G2_ENTITY_INCLUDE_RELATED_MATCHING_INFO

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+XXX_XXX&type=code):
    1. xxxXxxxx()

### G2_ENTITY_INCLUDE_RELATED_RECORD_DATA

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+XXX_XXX&type=code):
    1. xxxXxxxx()

### G2_ENTITY_INCLUDE_RELATED_RECORD_SUMMARY

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+XXX_XXX&type=code):
    1. xxxXxxxx()

### G2_ENTITY_INCLUDE_REPRESENTATIVE_FEATURES

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+XXX_XXX&type=code):
    1. xxxXxxxx()

### G2_ENTITY_OPTION_INCLUDE_FEATURE_STATS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+XXX_XXX&type=code):
    1. xxxXxxxx()

### G2_ENTITY_OPTION_INCLUDE_INTERNAL_FEATURES

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+XXX_XXX&type=code):
    1. xxxXxxxx()

### G2_EXPORT_INCLUDE_DISCLOSED

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+XXX_XXX&type=code):
    1. xxxXxxxx()

### G2_EXPORT_INCLUDE_NAME_ONLY

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+XXX_XXX&type=code):
    1. xxxXxxxx()

### G2_EXPORT_INCLUDE_POSSIBLY_RELATED

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+XXX_XXX&type=code):
    1. xxxXxxxx()

### G2_EXPORT_INCLUDE_POSSIBLY_SAME

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+XXX_XXX&type=code):
    1. xxxXxxxx()

### G2_EXPORT_INCLUDE_RESOLVED

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+XXX_XXX&type=code):
    1. xxxXxxxx()

### G2_EXPORT_INCLUDE_SINGLETONS

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+XXX_XXX&type=code):
    1. xxxXxxxx()

### G2_FIND_PATH_PREFER_EXCLUDE

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+XXX_XXX&type=code):
    1. xxxXxxxx()

### G2_INCLUDE_FEATURE_SCORES

[TODO: Write Synopsis]

1. **Values:**
    - 0:
    - 1:
1. [Where used](https://github.com/search?q=org%3Asenzing-garage+XXX_XXX&type=code):
    1. xxxXxxxx()

### G2_RECORD_DEFAULT_FLAGS

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

### G2_SEARCH_INCLUDE_FEATURE_SCORES

### G2_SEARCH_INCLUDE_RESOLVED

### G2_SEARCH_INCLUDE_POSSIBLY_SAME

### G2_SEARCH_INCLUDE_POSSIBLY_RELATED

### G2_SEARCH_INCLUDE_NAME_ONLY

### G2_SEARCH_INCLUDE_STATS

### G2_SEARCH_INCLUDE_ALL_ENTITIES

### Unused
