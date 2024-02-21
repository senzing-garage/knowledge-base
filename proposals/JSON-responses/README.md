# JSON responses

## Background

1. Currently G2Engine's `getEntityByEntityId()` returns something like:

    ```json
    {
        "RESOLVED_ENTITY": {
            "ENTITY_ID": 1,
            "ENTITY_NAME": "blank",
            "FEATURES": {
                "ADDRESS": [
                    {
                        "FEAT_DESC": "blank",
                        "LIB_FEAT_ID": 1,
                        "USAGE_TYPE": "blank",
                        "FEAT_DESC_VALUES": [
                            {
                                "FEAT_DESC": "blank",
                                "LIB_FEAT_ID": 1
                            }
                        ]
                    },
                    {
                        "FEAT_DESC": "blank",
                        "LIB_FEAT_ID": 2,
                        "USAGE_TYPE": "blank",
                        "FEAT_DESC_VALUES": [
                            {
                                "FEAT_DESC": "blank",
                                "LIB_FEAT_ID": 2
                            }
                        ]
                    }
                ],
                "DOB": [
                    {
                        "FEAT_DESC": "blank",
                        "LIB_FEAT_ID": 1,
                        "FEAT_DESC_VALUES": [
                            {
                                "FEAT_DESC": "blank",
                                "LIB_FEAT_ID": 1
                            },
                            {
                                "FEAT_DESC": "blank",
                                "LIB_FEAT_ID": 1
                            }
                        ]
                    }
                ],
                "EMAIL": [
                    {
                        "FEAT_DESC": "blank",
                        "LIB_FEAT_ID": 1,
                        "FEAT_DESC_VALUES": [
                            {
                                "FEAT_DESC": "blank",
                                "LIB_FEAT_ID": 1
                            }
                        ]
                    }
                ],
                "CUSTOMER_FIELD": [
                    {
                        "FEAT_DESC": "blank",
                        "LIB_FEAT_ID": 1,
                        "USAGE_TYPE": "blank",
                        "FEAT_DESC_VALUES": [
                            {
                                "FEAT_DESC": "blank",
                                "LIB_FEAT_ID": 1
                            }
                        ]
                    }
                ],
                "RECORD_TYPE": [
                    {
                        "FEAT_DESC": "blank",
                        "LIB_FEAT_ID": 1,
                        "FEAT_DESC_VALUES": [
                            {
                                "FEAT_DESC": "blank",
                                "LIB_FEAT_ID": 1
                            }
                        ]
                    }
                ]
            },
            "RECORD_SUMMARY": [
                {
                    "DATA_SOURCE": "blank",
                    "RECORD_COUNT": 1,
                    "FIRST_SEEN_DT": "blank",
                    "LAST_SEEN_DT": "blank"
                }
            ],
            "LAST_SEEN_DT": "blank",
            "RECORDS": [
                {
                    "DATA_SOURCE": "blank",
                    "RECORD_ID": "blank",
                    "ENTITY_TYPE": "blank",
                    "INTERNAL_ID": 1,
                    "ENTITY_KEY": "blank",
                    "ENTITY_DESC": "blank",
                    "MATCH_KEY": "blank",
                    "MATCH_LEVEL": 1,
                    "MATCH_LEVEL_CODE": "blank",
                    "ERRULE_CODE": "blank",
                    "LAST_SEEN_DT": "blank"
                }
            ]
        },
        "RELATED_ENTITIES": []
    }
    ```

1. Many of the JSON keys are "static".
   The key has the same name in the same place in the JSON structure.
   Examples:
   `RESOLVED_ENTITY`, `ENTITY_ID`, `ENTITY_NAME`, `FEATURES`, `FEAT_DESC`, `LIB_FEAT_ID`, `USAGE_TYPE`, `FEAT_DESC_VALUES`, etc.
1. Some of the JSON keys are "dynamic".
   They can be customized by the Senzing customer.
   Examples:
   `ADDRESS`, `DOB`, `EMAIL`, `CUSTOMER_FIELD`, `RECORD_TYPE`.
1. In Python, parsing through "dynamic" JSON keys is pretty straight forward.
   Example:

    ```python
    result_json = g2engine.get_entity_by_entity_id(...)
    result = json.loads(result_json)
    print(result.get("RESOLVED_ENTITY", {}).get("FEATURES", {}).get("ADDRESS", [])[0].get("FEAT_DESC"))
    ```

   However in languages like Java and Go, it is not so straight forward.

1. [RFC8927 - JSON Type Definition](https://www.rfc-editor.org/rfc/rfc8927.html)
   is a standard for documenting JSON "shapes" (not content).
   It is useful for generating code that works with JSON documents.
    1. Example code generation:
       [jtd-codegen](https://github.com/jsontypedef/json-typedef-codegen)
1. From what we currently know,
   [RFC8927](https://www.rfc-editor.org/rfc/rfc8927.html)
   does not support "dynamic" JSON keys.

## For consideration

1. Move from a dictionary with dynamic keys to a list of dictionaries containing an `FEATURE_NAME` JSON key.
   Example:

    ```json
    {
        "RESOLVED_ENTITY": {
            "ENTITY_ID": 1,
            "ENTITY_NAME": "blank",
            "FEATURES": [
                {
                    "FEATURE_NAME": "ADDRESS",
                    "FEAT_DESC": "blank",
                    "LIB_FEAT_ID": 1,
                    "USAGE_TYPE": "blank",
                    "FEAT_DESC_VALUES": [
                        {
                            "FEAT_DESC": "blank",
                            "LIB_FEAT_ID": 1
                        }
                    ]
                },
                {
                    "FEATURE_NAME": "ADDRESS",
                    "FEAT_DESC": "blank",
                    "LIB_FEAT_ID": 2,
                    "USAGE_TYPE": "blank",
                    "FEAT_DESC_VALUES": [
                        {
                            "FEAT_DESC": "blank",
                            "LIB_FEAT_ID": 2
                        }
                    ]
                },
                {
                    "FEATURE_NAME": "DOB",
                    "FEAT_DESC": "blank",
                    "LIB_FEAT_ID": 1,
                    "FEAT_DESC_VALUES": [
                        {
                            "FEAT_DESC": "blank",
                            "LIB_FEAT_ID": 1
                        },
                        {
                            "FEAT_DESC": "blank",
                            "LIB_FEAT_ID": 1
                        }
                    ]
                },
                {
                    "FEATURE_NAME": "EMAIL",
                    "FEAT_DESC": "blank",
                    "LIB_FEAT_ID": 1,
                    "FEAT_DESC_VALUES": [
                        {
                            "FEAT_DESC": "blank",
                            "LIB_FEAT_ID": 1
                        }
                    ]
                },
                {
                    "FEATURE_NAME": "CUSTOMER_FIELD",
                    "FEAT_DESC": "blank",
                    "LIB_FEAT_ID": 1,
                    "USAGE_TYPE": "blank",
                    "FEAT_DESC_VALUES": [
                        {
                            "FEAT_DESC": "blank",
                            "LIB_FEAT_ID": 1
                        }
                    ]
                },
                {
                    "FEATURE_NAME": "RECORD_TYPE",
                    "FEAT_DESC": "blank",
                    "LIB_FEAT_ID": 1,
                    "FEAT_DESC_VALUES": [
                        {
                            "FEAT_DESC": "blank",
                            "LIB_FEAT_ID": 1
                        }
                    ]
                }
            ],
            "RECORD_SUMMARY": [
                {
                    "DATA_SOURCE": "blank",
                    "RECORD_COUNT": 1,
                    "FIRST_SEEN_DT": "blank",
                    "LAST_SEEN_DT": "blank"
                }
            ],
            "LAST_SEEN_DT": "blank",
            "RECORDS": [
                {
                    "DATA_SOURCE": "blank",
                    "RECORD_ID": "blank",
                    "ENTITY_TYPE": "blank",
                    "INTERNAL_ID": 1,
                    "ENTITY_KEY": "blank",
                    "ENTITY_DESC": "blank",
                    "MATCH_KEY": "blank",
                    "MATCH_LEVEL": 1,
                    "MATCH_LEVEL_CODE": "blank",
                    "ERRULE_CODE": "blank",
                    "LAST_SEEN_DT": "blank"
                }
            ]
        },
        "RELATED_ENTITIES": []
    }
    ```

1. This will simplify the work being done in
   [g2-sdk-json-type-definition](https://github.com/senzing-garage/g2-sdk-json-type-definition).

1. Python example.

    ```python
    result_json = g2engine.get_entity_by_entity_id(...)
    result = G2engineGetEntityByEntityIDResponse.from_json_data(result_json)
    for feature in result.resolved_entity.features:
        if feature.feature_name == "ADDRESS":
            print(feature.feat_desc)
    ```

   Additional benefits:
    - Static code checking
    - Type hinting

## For consideration - 2

1. Move from a dictionary with dynamic keys to a list of dictionaries containing an `FEATURE_NAME` JSON key and list of feature elements.
   Example:

    ```json
    {
        "RESOLVED_ENTITY": {
            "ENTITY_ID": 1,
            "ENTITY_NAME": "blank",
            "FEATURES": [
                {
                    "FEATURE_NAME": "ADDRESS",
                    "FEATURE_ELEMENTS": [
                        {
                            "FEAT_DESC": "blank",
                            "LIB_FEAT_ID": 1,
                            "USAGE_TYPE": "blank",
                            "FEAT_DESC_VALUES": [
                                {
                                    "FEAT_DESC": "blank",
                                    "LIB_FEAT_ID": 1
                                }
                            ]
                        },
                        {
                            "FEAT_DESC": "blank",
                            "LIB_FEAT_ID": 2,
                            "USAGE_TYPE": "blank",
                            "FEAT_DESC_VALUES": [
                                {
                                    "FEAT_DESC": "blank",
                                    "LIB_FEAT_ID": 2
                                }
                            ]
                        }
                    ]
                },
                {
                    "FEATURE_NAME": "DOB",
                    "FEATURE_ELEMENTS": [
                        {
                            "FEAT_DESC": "blank",
                            "LIB_FEAT_ID": 1,
                            "USAGE_TYPE": "blank",
                            "FEAT_DESC_VALUES": [
                                {
                                    "FEAT_DESC": "blank",
                                    "LIB_FEAT_ID": 1
                                }
                            ]
                        }
                    ]
                },
                {
                    "FEATURE_NAME": "EMAIL",
                    "FEATURE_ELEMENTS": [
                        {
                            "FEAT_DESC": "blank",
                            "LIB_FEAT_ID": 1,
                            "USAGE_TYPE": "blank",
                            "FEAT_DESC_VALUES": [
                                {
                                    "FEAT_DESC": "blank",
                                    "LIB_FEAT_ID": 1
                                }
                            ]
                        }
                    ]
                },
                {
                    "FEATURE_NAME": "CUSTOMER_FIELD",
                    "FEATURE_ELEMENTS": [
                        {
                            "FEAT_DESC": "blank",
                            "LIB_FEAT_ID": 1,
                            "USAGE_TYPE": "blank",
                            "FEAT_DESC_VALUES": [
                                {
                                    "FEAT_DESC": "blank",
                                    "LIB_FEAT_ID": 1
                                }
                            ]
                        }
                    ]
                },
                {
                    "FEATURE_NAME": "RECORD_TYPE",
                    "FEATURE_ELEMENTS": [
                        {
                            "FEAT_DESC": "blank",
                            "LIB_FEAT_ID": 1,
                            "USAGE_TYPE": "blank",
                            "FEAT_DESC_VALUES": [
                                {
                                    "FEAT_DESC": "blank",
                                    "LIB_FEAT_ID": 1
                                }
                            ]
                        }
                    ]
                }
            ],
            "RECORD_SUMMARY": [
                {
                    "DATA_SOURCE": "blank",
                    "RECORD_COUNT": 1,
                    "FIRST_SEEN_DT": "blank",
                    "LAST_SEEN_DT": "blank"
                }
            ],
            "LAST_SEEN_DT": "blank",
            "RECORDS": [
                {
                    "DATA_SOURCE": "blank",
                    "RECORD_ID": "blank",
                    "ENTITY_TYPE": "blank",
                    "INTERNAL_ID": 1,
                    "ENTITY_KEY": "blank",
                    "ENTITY_DESC": "blank",
                    "MATCH_KEY": "blank",
                    "MATCH_LEVEL": 1,
                    "MATCH_LEVEL_CODE": "blank",
                    "ERRULE_CODE": "blank",
                    "LAST_SEEN_DT": "blank"
                }
            ]
        },
        "RELATED_ENTITIES": []
    }
    ```

### Areas where Dynamic JSON keys are seen

In the current [senzingapi-RFC8927](https://github.com/senzing-garage/g2-sdk-json-type-definition/blob/main/senzingapi-RFC8927.json),
"dynamic" JSON keys are currently "faked" in:

- [AttributeCounter](https://github.com/senzing-garage/g2-sdk-json-type-definition/blob/b46806560498257e1e74011391a8ad89a151afd8/senzingapi-RFC8927.json#L64-L235)
- [FeatureScores](https://github.com/senzing-garage/g2-sdk-json-type-definition/blob/b46806560498257e1e74011391a8ad89a151afd8/senzingapi-RFC8927.json#L1501-L1798)
- [MatchInfoCandidateKeys](https://github.com/senzing-garage/g2-sdk-json-type-definition/blob/b46806560498257e1e74011391a8ad89a151afd8/senzingapi-RFC8927.json#L4135-L4432)
- [MatchScores](https://github.com/senzing-garage/g2-sdk-json-type-definition/blob/b46806560498257e1e74011391a8ad89a151afd8/senzingapi-RFC8927.json#L4497-L4794)
