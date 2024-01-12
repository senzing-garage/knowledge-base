# Senzing quickstart using gRPC

This Python demonstration works on Linux, Windows, and macOS.

## Prerequisistes

1. Python 3
1. Docker
1. `senzing-grpc`.  To install, run

    ```console
    python3 -m pip install --upgrade senzing-abstract senzing-grpc
    ```

## Use

The following example shows how to start a Senzing gRPC server Docker container
and access it using the `senzing_grpc` Python package.

1. Run a Senzing gRPC service using Docker.
   Example:

    ```console
    docker run -p 8260:8260 -p 8261:8261 --pull always --rm senzing/senzing-tools demo-quickstart

    ```

   **Note:** In this example, the database is *inside* the container.
   Thus the database is temporal and will be deleted when the container is killed.

1. In a separate window, start an interactive Python session.
   Example:

    ```console
    python3

    ```

1. For a quick test of calling Senzing's `g2_product.version()`,
   copy/paste the following block of code into the interactive Python session
   and press the **Enter** key.
   Example:

    ```python
    import grpc
    from senzing_grpc import G2ProductGrpc
    g2_product = G2ProductGrpc(grpc_channel=grpc.insecure_channel("localhost:8261"))
    print(g2_product.version())
    ```

1. To add Truth Set data sources to the Senzing configuration,
   copy/paste the following block of code into the interactive Python session
   and press the **Enter** key.
   Example:

    ```python
    import grpc
    from senzing_truthset import TRUTHSET_DATASOURCES

    from senzing_grpc import (
        G2ConfigGrpc,
        G2ConfigMgrGrpc,
        G2DiagnosticGrpc,
        G2EngineGrpc,
        G2Exception,
    )

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
    # Add Datasources to existing Senzing configuration.
        for datasource in TRUTHSET_DATASOURCES.values():
            g2_config.add_data_source(config_handle, datasource.get("Json", {}))
    # Externalize new Senzing configuration.
        NEW_JSON_CONFIG = g2_config.save(config_handle)
        new_config_id = g2_configmgr.add_config(NEW_JSON_CONFIG, "Add TruthSet datasources")
        g2_configmgr.replace_default_config_id(old_config_id, new_config_id)
    # Update other Senzing objects.
        g2_engine.reinit(new_config_id)
        g2_diagnostic.reinit(new_config_id)
    except G2Exception as err:
        print(f"\nError:\n{err}\n")

    ```

1. To add Truth Set data to the Senzing database,
   copy/paste the following block of code into the interactive Python session
   and press the **Enter** key.

    ```python
    from senzing_truthset import (
        TRUTHSET_CUSTOMER_RECORDS,
        TRUTHSET_REFERENCE_RECORDS,
        TRUTHSET_WATCHLIST_RECORDS,
    )

    try:
        record_sets = [
            TRUTHSET_CUSTOMER_RECORDS,
            TRUTHSET_REFERENCE_RECORDS,
            TRUTHSET_WATCHLIST_RECORDS,
        ]
        for record_set in record_sets:
            for record in record_set.values():
                g2_engine.add_record(
                    record.get("DataSource"), record.get("Id"), record.get("Json")
                )
    except G2Exception as err:
        print(f"\nError:\n{err}\n")

    ```

1. Entity details can be viewed.
   Copy/paste the following block of code into the interactive Python session
   and press the **Enter** key.

    ```python
    import json

    customer_1070_entity = g2_engine.get_entity_by_record_id_v2("CUSTOMERS", "1070", -1)
    print(json.dumps(json.loads(customer_1070_entity), indent=2))

    ```

1. Entities can be searched.
   Copy/paste the following block of code into the interactive Python session
   and press the **Enter** key.

    ```python
    search_query = {
        "name_full": "robert smith",
        "date_of_birth": "11/12/1978",
    }
    search_result = g2_engine.search_by_attributes_v2(search_query)
    print(json.dumps(json.loads(search_result), indent=2))

    ```

1. Help is available.
   Copy/paste each block of code into the interactive Python session
   and press the **Enter** key.

    ```python
    general_help = g2_engine.help()
    print(general_help)

    ```

    ```python
    specific_help = g2_engine.help("get_entity_by_record_id_v2")
    print(specific_help)

    ```

1. To end the interactive Python session,
   copy/paste the following block of code into the interactive Python session
   and press the **Enter** key.

    ```python
    quit()
    ```

1. View the Entity Search demonstration at
   [http://localhost:8260/entity-search](http://localhost:8260/entity-search).
