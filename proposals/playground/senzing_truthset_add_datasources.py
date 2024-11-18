#! /usr/bin/env python3

import grpc
from senzing_grpc import SzAbstractFactory, SzError
from senzing_truthset import TRUTHSET_DATASOURCES

try:

    # Create Senzing objects.

    sz_abstract_factory = SzAbstractFactory(
        grpc_channel=grpc.insecure_channel("localhost:8261")
    )
    sz_config = sz_abstract_factory.create_sz_config()
    sz_configmanager = sz_abstract_factory.create_sz_configmanager()
    sz_diagnostic = sz_abstract_factory.create_sz_diagnostic()
    sz_engine = sz_abstract_factory.create_sz_engine()

    # Get existing Senzing configuration.

    old_config_id = sz_configmanager.get_default_config_id()
    OLD_JSON_CONFIG = sz_configmanager.get_config(old_config_id)
    config_handle = sz_config.import_config(OLD_JSON_CONFIG)

    # Add DataSources to existing Senzing configuration.

    for datasource in TRUTHSET_DATASOURCES.keys():
        sz_config.add_data_source(config_handle, datasource)

    # Persist new Senzing configuration.

    NEW_JSON_CONFIG = sz_config.export_config(config_handle)
    new_config_id = sz_configmanager.add_config(
        NEW_JSON_CONFIG, "Add TruthSet datasources"
    )
    sz_configmanager.replace_default_config_id(old_config_id, new_config_id)

    # Update other Senzing objects.

    sz_abstract_factory.reinitialize(new_config_id)

except SzError as err:
    print(f"\nError:\n{err}\n")
