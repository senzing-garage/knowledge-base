#! /usr/bin/env python3

import grpc
from senzing_grpc import (
    G2ConfigGrpc,
    G2ConfigMgrGrpc,
    G2DiagnosticGrpc,
    G2EngineGrpc,
    G2Exception,
)
from senzing_truthset import TRUTHSET_DATASOURCES

try:
    # Create gRPC channel.

    GRPC_URL = "localhost:8261"
    grpc_channel = grpc.insecure_channel(GRPC_URL)

    # Create Senzing objects.

    g2_config = G2ConfigGrpc(grpc_channel=grpc_channel)
    g2_configmgr = G2ConfigMgrGrpc(grpc_channel=grpc_channel)
    g2_engine = G2EngineGrpc(grpc_channel=grpc_channel)
    g2_diagnostic = G2DiagnosticGrpc(grpc_channel=grpc_channel)

    # Get existing Senzing configuration.

    old_config_id = g2_configmgr.get_default_config_id()
    OLD_JSON_CONFIG = g2_configmgr.get_config(old_config_id)
    config_handle = g2_config.load(OLD_JSON_CONFIG)

    # Add DataSources to existing Senzing configuration.

    for datasource in TRUTHSET_DATASOURCES.values():
        g2_config.add_data_source(config_handle, datasource.get("Json", {}))

    # Persist new Senzing configuration.

    NEW_JSON_CONFIG = g2_config.save(config_handle)
    new_config_id = g2_configmgr.add_config(NEW_JSON_CONFIG, "Add TruthSet datasources")
    g2_configmgr.replace_default_config_id(old_config_id, new_config_id)

    # Update other Senzing objects.

    g2_engine.reinit(new_config_id)
    g2_diagnostic.reinit(new_config_id)
except G2Exception as err:
    print(f"\nError:\n{err}\n")
