#! /usr/bin/env python3

import json

# -----------------------------------------------------------------------------
# Example functions.
# -----------------------------------------------------------------------------


def calc_name_key(*args, **kwargs):
    result = None
    if kwargs.get("hint") == "full":
        result = ".".join([
            kwargs.get("FIRSTNAME"),
            kwargs.get("MIDDLENAME"),
            kwargs.get("LASTNAME")
        ])
    elif kwargs.get("hint") == "sgn":
        result = ".".join([
            kwargs.get("FIRSTNAME"),
            kwargs.get("LASTNAME")
        ])
    return result


def calc_org_key(*args, **kwargs):
    return kwargs.get("GCA_BUSINESSNAME")


def composite_key_builder(*args, **kwargs):
    result = None
    for key in kwargs.get('keys', []):
        value = kwargs.get(key)
        if value:
            if result:
                result = ".".join([result, value])
            else:
                result = value
    return result


def country_code(*args, **kwargs):
    result = None
    if kwargs.get("GCA_COUNTRYCODE"):
        result = str(kwargs.get("GCA_COUNTRYCODE")).upper().strip()
    return result


def postal_code(*args, **kwargs):
    result = None
    if kwargs.get("GCA_POSTALCODE"):
        result = str(kwargs.get("GCA_POSTALCODE"))[:3].upper().strip()
    return result

# -----------------------------------------------------------------------------
# Example row data.   2 Rows given.
# -----------------------------------------------------------------------------


rows = [
    {
     "FIRSTNAME": "John",
     "MIDDLENAME": "Jon",
     "LASTNAME": "Smith",
     "GCA_BUSINESSNAME": "Dewey_and_Howe",
     "GCA_POSTALCODE": 12345,
     "GCA_COUNTRYCODE": "USA",
     "CALC_FULL_NAME_KEY": "my_FULL_NAME_KEY",
     "CALC_COUNTRY_CODE": "my_COUNTRY_CODE",
     "DUNS": "my_DUNS",
     "CALC_ORG_NAME_KEY": "my_ORG_NAME_KEY",
    }, {
     "FIRSTNAME": "Mary",
     "MIDDLENAME": "Jane",
     "LASTNAME": "Jones",
    },
]

# -----------------------------------------------------------------------------
# Dictionary of functions and parameters.
# -----------------------------------------------------------------------------

calculations = {
    "CALC_FULL_NAME_KEY": {
        "function": calc_name_key,
        "parameters": {
            "hint": "full"
        }
    },
    "CALC_SGN_NAME_KEY": {
        "function": calc_name_key,
        "parameters": {
            "hint": "sgn"
        }
    },
    "CALC_ORG_NAME_KEY": {
        "function": calc_org_key,
    },
    "CK_NAME_CNTRY": {
        "function": composite_key_builder,
        "parameters": {
            "keys": ["CALC_FULL_NAME_KEY", "CALC_COUNTRY_CODE"]
        }
    },
    "CK_NAME_DUNS": {
        "function": composite_key_builder,
        "parameters": {
            "keys": ["CALC_FULL_NAME_KEY", "DUNS"]
        }
    },
    "CK_NAME_ORGNM": {
        "function": composite_key_builder,
        "parameters": {
            "keys": ["CALC_FULL_NAME_KEY", "CALC_ORG_NAME_KEY"]
        }
    },
    "CALC_POSTAL_KEY": {
        "function": postal_code,
    },
    "CALC_COUNTRY_CODE": {
        "function": country_code,
    },
}

# -----------------------------------------------------------------------------
# Test
# -----------------------------------------------------------------------------

# Perform calculations on rows and append results to each row.

for row in rows:
    for key, value in calculations.items():
        parameters = {
            **row,
            **value.get('parameters', {})
        }
        result = value.get("function")(**parameters)
        if result:
            row[key] = result

# Pretty print results.

rows_json = json.dumps(rows, sort_keys=True, indent=4)
print(rows_json)
