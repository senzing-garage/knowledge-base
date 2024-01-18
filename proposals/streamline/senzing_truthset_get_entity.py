#! /usr/bin/env python3

import json

import grpc
from senzing_grpc import G2EngineGrpc

# Create gRPC channel.

GRPC_URL = "localhost:8261"
grpc_channel = grpc.insecure_channel(GRPC_URL)

# Create Senzing objects.

g2_engine = G2EngineGrpc(grpc_channel=grpc_channel)

# Perform Senzing get entity.

customer_1070_entity = g2_engine.get_entity_by_record_id_v2("CUSTOMERS", "1070", -1)
print(json.dumps(json.loads(customer_1070_entity), indent=2))
