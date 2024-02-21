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
   Examples:
   `RESOLVED_ENTITY`, `ENTITY_ID`, `ENTITY_NAME`, `FEATURES`, `FEAT_DESC`, `LIB_FEAT_ID`, `USAGE_TYPE`, `FEAT_DESC_VALUES`, etc.
1. Some of the JSON keys are "dynamic".
   They can be customized by the Senzing customer.
   Examples:
   `ADDRESS`, `DOB`, `EMAIL`, `CUSTOMER_FIELD`, `RECORD_TYPE`.
1. [RFC8927 - JSON Type Definition](https://www.rfc-editor.org/rfc/rfc8927.html)
   is a standard for documenting JSON "shapes" (not content).
   It is useful for generating code that works with JSON documents.
    1. Example code generation:
       [jtd-codegen](https://github.com/jsontypedef/json-typedef-codegen)
1. From what we currently know,
   [RFC8927](https://www.rfc-editor.org/rfc/rfc8927.html)
   does not support "dynamic" JSON keys.

## For consideration

1. Move from a dictionary with dynamic keys to a list of dictionaries containing an `ID` JSON key.
   Example:

    ```json
    {
        "RESOLVED_ENTITY": {
            "ENTITY_ID": 1,
            "ENTITY_NAME": "blank",
            "FEATURES": [
                {
                    "ID": "ADDRESS",
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
                    "ID": "DOB",
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
                    "ID": "EMAIL",
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
                    "ID": "CUSTOMER_FIELD",
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
                    "ID": "RECORD_TYPE",
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
