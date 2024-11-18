#! /usr/bin/env python3

import json

import grpc
from senzing_grpc import SzAbstractFactory, SzError

try:

    # Create Senzing objects.

    sz_abstract_factory = SzAbstractFactory(
        grpc_channel=grpc.insecure_channel("localhost:8261")
    )
    sz_engine = sz_abstract_factory.create_sz_engine()

    # Perform Senzing search.

    search_query = {
        "name_full": "robert smith",
        "date_of_birth": "11/12/1978",
    }
    search_result = sz_engine.search_by_attributes(json.dumps(search_query))
    print(json.dumps(json.loads(search_result), indent=2))

except SzError as err:
    print(f"\nError:\n{err}\n")
