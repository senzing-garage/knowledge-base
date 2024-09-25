#! /usr/bin/env python3

import grpc
from senzing_grpc import SzAbstractFactory, SzEngineFlags, SzError
from senzing_truthset import (
    TRUTHSET_CUSTOMER_RECORDS,
    TRUTHSET_REFERENCE_RECORDS,
    TRUTHSET_WATCHLIST_RECORDS,
)

try:

    # Create Senzing objects.

    sz_abstract_factory = SzAbstractFactory(
        grpc_channel=grpc.insecure_channel("localhost:8261")
    )
    sz_engine = sz_abstract_factory.create_sz_engine()

    # Identify records.

    record_sets = [
        TRUTHSET_CUSTOMER_RECORDS,
        TRUTHSET_REFERENCE_RECORDS,
        TRUTHSET_WATCHLIST_RECORDS,
    ]

    # Call Senzing to add record.

    for record_set in record_sets:
        for record in record_set.values():
            info = sz_engine.add_record(
                record.get("DataSource"),
                record.get("Id"),
                record.get("Json"),
                SzEngineFlags.SZ_WITH_INFO,
            )
            print(info)

except SzError as err:
    print(f"\nError:\n{err}\n")
