#! /usr/bin/env python3

import grpc
from senzing_grpc import G2EngineGrpc, G2Exception
from senzing_truthset import (
    TRUTHSET_CUSTOMER_RECORDS,
    TRUTHSET_REFERENCE_RECORDS,
    TRUTHSET_WATCHLIST_RECORDS,
)

try:
    # Create gRPC channel.

    GRPC_URL = "localhost:8261"
    grpc_channel = grpc.insecure_channel(GRPC_URL)

    # Create Senzing objects.

    g2_engine = G2EngineGrpc(grpc_channel=grpc_channel)

    # Identify records.

    record_sets = [
        TRUTHSET_CUSTOMER_RECORDS,
        TRUTHSET_REFERENCE_RECORDS,
        TRUTHSET_WATCHLIST_RECORDS,
    ]

    # Call Senzing to add record.

    for record_set in record_sets:
        for record in record_set.values():
            g2_engine.add_record(
                record.get("DataSource"), record.get("Id"), record.get("Json")
            )
except G2Exception as err:
    print(f"\nError:\n{err}\n")
