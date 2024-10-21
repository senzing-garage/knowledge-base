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

    # Perform Senzing get entity.

    customer_1070_entity = sz_engine.get_entity_by_record_id("CUSTOMERS", "1070")
    print(json.dumps(json.loads(customer_1070_entity), indent=2))

except SzError as err:
    print(f"\nError:\n{err}\n")
