#! /usr/bin/env python3

import json

import grpc
from senzing_grpc import G2EngineGrpc

# Create gRPC channel.

GRPC_URL = "localhost:8261"
grpc_channel = grpc.insecure_channel(GRPC_URL)

# Create Senzing objects.

g2_engine = G2EngineGrpc(grpc_channel=grpc_channel)

# Perform Senzing search.

search_query = {
    "name_full": "robert smith",
    "date_of_birth": "11/12/1978",
}
search_result = g2_engine.search_by_attributes_v2(search_query)
print(json.dumps(json.loads(search_result), indent=2))
