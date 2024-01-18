#! /usr/bin/env python3

import grpc
from senzing_grpc import G2ProductGrpc

g2_product = G2ProductGrpc(grpc_channel=grpc.insecure_channel("localhost:8261"))
print(g2_product.version())
