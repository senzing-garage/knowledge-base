# Use Senzing's Truth Set data - Linux/macOS

In this demonstration, the Senzing Truth Set data will be added to the ephemeral
Senzing database inside the running Docker container.

## Prerequisites

1. Make sure the
   [prerequisites](README.md#Prerequisistes)
   are satisfied.

## Create Senzing gRPC service

1. Run a Senzing gRPC service using Docker.
   Example:

    ```console
    docker run --name senzing-streamline -p 8260:8260 -p 8261:8261 --pull always --rm senzing/senzing-tools demo-quickstart

    ```

   **Note:** In this example, the database is *inside* the container.
   Thus, the database is temporal and will be deleted when the container is killed.

1. In a separate window, start an interactive Python session.
   Example:

    ```console
    python3

    ```

1. To set the URL of the Senzing gRPC service started above,
   copy/paste the following block of code into the interactive Python session
   and press the **Enter** key.

    ```python
    GRPC_URL = "localhost:8261"
    ```

## Identify data sources

5. To add Truth Set data sources to the Senzing configuration,
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
    # Persist new Senzing configuration.
        NEW_JSON_CONFIG = g2_config.save(config_handle)
        new_config_id = g2_configmgr.add_config(NEW_JSON_CONFIG, "Add TruthSet datasources")
        g2_configmgr.replace_default_config_id(old_config_id, new_config_id)
    # Update other Senzing objects.
        g2_engine.reinit(new_config_id)
        g2_diagnostic.reinit(new_config_id)
    except G2Exception as err:
        print(f"\nError:\n{err}\n")

    ```

    or download and run
    [senzing_truthset_add_datasources.py](https://raw.githubusercontent.com/senzing-garage/knowledge-base/main/proposals/streamline/senzing_truthset_add_datasources.py).

## Add records

6. To add Truth Set data to the Senzing database,
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
                g2_engine.add_record(record.get("DataSource"), record.get("Id"), record.get("Json"))
    except G2Exception as err:
        print(f"\nError:\n{err}\n")

    ```

    or download and run
    [senzing_truthset_add_records.py](https://raw.githubusercontent.com/senzing-garage/knowledge-base/main/proposals/streamline/senzing_truthset_add_records.py).

    If running in the interactive Python session, wait until the `>>>` prompt appears before proceeding.

## View results

7. Entity details can be viewed.
   Copy/paste the following block of code into the interactive Python session
   and press the **Enter** key.

    ```python
    import json

    customer_1070_entity = g2_engine.get_entity_by_record_id_v2("CUSTOMERS", "1070", -1)
    print(json.dumps(json.loads(customer_1070_entity), indent=2))

    ```

    or download and run
    [senzing_truthset_get_entity.py](https://raw.githubusercontent.com/senzing-garage/knowledge-base/main/proposals/streamline/senzing_truthset_get_entity.py).

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

    or download and run
    [senzing_truthset_search.py](https://raw.githubusercontent.com/senzing-garage/knowledge-base/main/proposals/streamline/senzing_truthset_search.py).

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

## Explore data using Senzing tools

11. View the Entity Search demonstration at
   [http://localhost:8260/entity-search](http://localhost:8260/entity-search).

1. Using `G2Snapshot.py`.
    1. Visit
       [http://localhost:8260/xterm](http://localhost:8260/xterm).

    1. Start `G2Snapshot.py` by running
       the following block of code in the web browser based Xterm:

        ```console
        G2Snapshot.py -o /tmp/demo-snap-v1 -a
        ```

    1. For more information on SnapShots, visit
       [Exploratory Data Analysis - Taking a snapshot](https://senzing.zendesk.com/hc/en-us/articles/360051874294-Exploratory-Data-Analysis-3-Taking-a-snapshot)

1. Using `G2Explorer.py`.
    1. Visit
       [http://localhost:8260/xterm](http://localhost:8260/xterm).

    1. Start `G2Explorer.py` by running
       the following block of code in the web browser based Xterm:

        ```console
        G2Explorer.py -s /tmp/demo-snap-v1.json
        ```

    1. In `G2Explorer.py`, enter

        ```console
        get customers 1070
        ```

    1. In `G2Explorer.py`, enter

        ```console
        search {"name_full": "robert smith", "date_of_birth": "11/12/1978"}
        ```

    1. For more examples, see
       [Exploratory Data Analysis - Basic exploration](https://senzing.zendesk.com/hc/en-us/articles/360051768234-Exploratory-Data-Analysis-2-Basic-exploration)

    1. To exit `G2Explorer.py`, enter

        ```console
        quit
        ```

1. Using `G2Audit.py`

    1. For more information on auditing, visit
       [Exploratory Data Analysis - Comparing ER results](https://senzing.zendesk.com/hc/en-us/articles/360050643034-Exploratory-Data-Analysis-4-Comparing-ER-results)

1. To end the Senzing gRPC service using Docker,
   use `ctrl-c` to stop the `docker run ...` program.
   **Warning:** Once the docker container has been stopped, the data is gone.

## Next steps

1. [Try Senzing's Hello World](README.md)
1. Use Senzing's Truth Set data - Linux/macOS
1. [Map and load your own data - Linux/macOS](map-and-load-your-own-data-linux-macos.md)
1. [Entity resolution in motion - Linux/macOS](entity-resolution-in-motion-linux-macos.md)

## References

1. [View SQLite database](coleifer-sqlite-web.md)
