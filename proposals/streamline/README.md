# Streamline

This Python demonstration of Senzing works on Linux, macOS, and Windows.

## Prerequisistes

1. Python 3
1. Docker -
   [Linux](https://docs.docker.com/desktop/install/linux-install/),
   [Mac](https://docs.docker.com/desktop/install/mac-install/),
   [Windows](https://docs.docker.com/desktop/install/windows-install/)
1. `senzing-grpc`.  To install, run

    ```console
    python3 -m pip install --upgrade senzing-abstract senzing-grpc
    ```

## Try Senzing's Hello World

The following example shows how to start a Senzing gRPC server Docker container
and access it using the `senzing_grpc` Python package.

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

    or download and run
    [senzing_hello_world.py](https://raw.githubusercontent.com/senzing-garage/knowledge-base/main/proposals/streamline/senzing_hello_world.py).

### Use Senzing's Truth Set data

In this demonstration, the Senzing Truth Set data will be added to the ephemeral
Senzing database inside the running Docker container.

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

    or download and run
    [senzing_truthset_add_records.py](https://raw.githubusercontent.com/senzing-garage/knowledge-base/main/proposals/streamline/senzing_truthset_add_records.py).

    If running in the interactive Python session, wait until the `>>>` prompt appears before proceeding.

1. Entity details can be viewed.
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

### Explore data using Senzing tools

1. View the Entity Search demonstration at
   [http://localhost:8260/entity-search](http://localhost:8260/entity-search).

1. Using `G2Snapshot.py`.
    1. Visit
       [http://localhost:8260/xterm](http://localhost:8260/xterm).

    1. Start `G2Snapshot.py` by running

        ```console
        G2Snapshot.py -o /tmp/demo-snap-v1 -a
        ```

    1. For more information on SnapShots, visit
       [Exploratory Data Analysis - Taking a snapshot](https://senzing.zendesk.com/hc/en-us/articles/360051874294-Exploratory-Data-Analysis-3-Taking-a-snapshot)

1. Using `G2Explorer.py`.
    1. Visit
       [http://localhost:8260/xterm](http://localhost:8260/xterm).

    1. Start `G2Explorer.py` by running

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

## Map and load your own data

In this demonstration, your data will be added to the Senzing database.
This time the data will be persisted into SQLite database files residing on your local workstation
and custom ports will be used.

1. On your local workstation, create a file of JSON-lines with your data to be loaded into Senzing.

   As an example,
   either download
   [example-data-for-senzing.json](https://raw.githubusercontent.com/senzing-garage/knowledge-base/main/proposals/streamline/example-data-for-senzing.json)
   or use the following Linux/macOS command on your local workstation:

    ```console
    cat <<EOT > /tmp/example-data-for-senzing.json
    {"DATA_SOURCE": "MY_DATASOURCE", "RECORD_ID": "157616467", "DRIVERS_LICENSE_NUMBER": "00", "DATE_OF_BIRTH": "20/12/1965", "ADDR_POSTAL_CODE": "47201", "ADDR_CITY": "Columbus", "SSN_NUMBER": "883-24-5259", "NAME_FIRST": "CYNTHIA", "NAME_LAST": "SHORTS", "GENDER": "F",  "DSRC_ACTION": "A", "ADDR_LINE1": "696 15th ST"}
    {"DATA_SOURCE": "MY_DATASOURCE", "RECORD_ID": "115212881", "SOCIAL_HANDLE": "thyroidss", "DATE_OF_BIRTH": "20/11/1960", "ADDR_STATE": "AR", "SSN_NUMBER": "434-59-7109", "NAME_FIRST": "KEVIN", "PASSPORT_NUMBER": "154CE0YTD", "GENDER": "M", "DSRC_ACTION": "A", "ADDR_CITY": "Lewisville", "DRIVERS_LICENSE_STATE": "DE", "PHONE_NUMBER": "501-357-3875", "NAME_LAST": "HZIRT", "ADDR_LINE1": "330 5th ST"}
    {"DATA_SOURCE": "MY_DATASOURCE", "RECORD_ID": "645217904", "ADDR_STATE": "Minnesota", "ADDR_POSTAL_CODE": "55804", "SSN_NUMBER": "113-56-6093", "NAME_FIRST": "LINDA", "GENDER": "F", "CC_ACCOUNT_NUMBER": "6442498315525524",  "DSRC_ACTION": "A", "ADDR_CITY": "Duluth", "DRIVERS_LICENSE_NUMBER": "S90976292", "DRIVERS_LICENSE_STATE": "HI", "PHONE_NUMBER": "952-757-7688", "NAME_LAST": "BUCHANAN", "ADDR_LINE1": "486 41st AVE"}
    {"DATA_SOURCE": "MY_DATASOURCE", "RECORD_ID": "212359276", "DATE_OF_BIRTH": "23/2/1968", "ADDR_STATE": "ID", "ADDR_POSTAL_CODE": "83709", "SSN_NUMBER": "441-76-2625", "NAME_FIRST": "ROLANDA", "PASSPORT_NUMBER": "CFP1XM4Q", "GENDER": "N/A", "CC_ACCOUNT_NUMBER": "50186266717162531",  "DSRC_ACTION": "A", "DRIVERS_LICENSE_NUMBER": "X8865625161887", "DRIVERS_LICENSE_STATE": "IW", "ADDR_CITY": "Boise", "NAME_LAST": "JOHNSON", "ADDR_LINE1": "142 AuYto DR"}
    {"DATA_SOURCE": "MY_DATASOURCE", "RECORD_ID": "526429955", "SSN_NUMBER": "388-69-4882", "NAME_FIRST": "JOHNNIE", "PASSPORT_NUMBER": "CN5QGN8HY8", "GENDER": "M", "CC_ACCOUNT_NUMBER": "541119397002419249", "DSRC_ACTION": "A", "DRIVERS_LICENSE_NUMBER": "943105509", "DRIVERS_LICENSE_STATE": "IV", "PHONE_NUMBER": "355-9553", "NAME_LAST": "H", "ADDR_LINE1": "69 Cayuga CT"}
    {"DATA_SOURCE": "MY_DATASOURCE", "RECORD_ID": "604947448", "ADDR_CITY": "Port Jefferson Station", "DRIVERS_LICENSE_NUMBER": "50951659", "ADDR_STATE": "NY", "ADDR_POSTAL_CODE": "11776", "PHONE_NUMBER": "268-8561", "NAME_FIRST": "ALBERT", "NAME_LAST": "GALLAHER", "GENDER": "M",  "DSRC_ACTION": "A", "ADDR_LINE1": "22 BroadShurst ST"}
    {"DATA_SOURCE": "MY_DATASOURCE", "RECORD_ID": "513789670", "SOCIAL_HANDLE": "tainsz", "ADDR_STATE": "OK", "ADDR_POSTAL_CODE": "34133", "SSN_NUMBER": "758-42-2397", "NAME_FIRST": "JAFMES", "GENDER": "M", "DSRC_ACTION": "A", "ADDR_CITY": "TAlsa", "DRIVERS_LICENSE_STATE": "NY", "PHONE_NUMBER": "580-558-8123", "NAME_LAST": "HENDERSON", "ADDR_LINE1": "6738 112thEast AVE"}
    {"DATA_SOURCE": "MY_DATASOURCE", "RECORD_ID": "212442489", "SOCIAL_HANDLE": "debrides7", "ADDR_STATE": "CO", "ADDR_POSTAL_CODE": "80501", "NAME_FIRST": "S", "GENDER": "M", "CC_ACCOUNT_NUMBER": "676396021499009121", "DSRC_ACTION": "A", "DRIVERS_LICENSE_STATE": "NE", "ADDR_CITY": "Longmont", "NAME_LAST": "JONES", "ADDR_LINE1": "948 10th AVE"}
    EOT

    ```

1. On your local workstation, create an empty Sqlite Senzing database on your local workstation.
   Modify the value of `SENZING_MY_DEMO_1` to specify where you want the database files kept.

   **Linux/macOS example:**

    1. To create a new directory to store the new SQLite database files,
       copy/modify/paste the following:

        ```console
        export SENZING_MY_DEMO_1="/tmp/my-demo-1"
        ```

    1. Copy/paste the following:

        ```console
        mkdir ${SENZING_MY_DEMO_1}
        docker run \
            --env SENZING_TOOLS_DATABASE_URL=sqlite3://na:na@/tmp/sqlite/G2C.db \
            --rm \
            --volume ${SENZING_MY_DEMO_1}:/tmp/sqlite \
            senzing/senzing-tools init-database

        ```

   **Windows Command Prompt (not Windows PowerShell) example:**

    1. To create a new directory to store the new SQLite database files,
       copy/modify/paste the following:

        ```console
        set SENZING_MY_DEMO_1="C:\\Users\\username\\my-demo-1"
        ```

    1. Copy/paste the following:

        ```console
        mkdir %SENZING_MY_DEMO_1%
        docker run ^
            --env SENZING_TOOLS_DATABASE_URL=sqlite3://na:na@/tmp/sqlite/G2C.db ^
            --rm ^
            --volume %SENZING_MY_DEMO_1%:/tmp/sqlite ^
            senzing/senzing-tools init-database

        ```

1. Run a Senzing gRPC service using Docker.
   Notice that the ports published via `--publish` must be unique for your workstation.
   Inside the container `8260` is the port of the HTTP server, `8261` is the port of the gRPC server.
   In the following example they are mapped to ports `9140` and `9141` on your workstation.
   Also notice that the `--volume` must point to the directory of the database files you wish to use.
   Optionally, you may change the `--name` value to a custom name.
   For more information on `docker run` parameters,
   visit [docker run](https://docs.docker.com/engine/reference/commandline/run/).

   **Linux/macOS example:**

    ```console
    docker run \
        --name senzing-my-demo-1 \
        --publish 9140:8260 \
        --publish 9141:8261 \
        --pull always \
        --rm \
        --volume ${SENZING_MY_DEMO_1}:/tmp/sqlite \
        senzing/senzing-tools demo-quickstart

    ```

   **Windows Command Prompt (not Windows PowerShell) example:**

    ```console
    docker run ^
        --name senzing-my-demo-1 ^
        --publish 9140:8260 ^
        --publish 9141:8261 ^
        --pull always ^
        --rm ^
        --volume %SENZING_MY_DEMO_1%:/tmp/sqlite ^
        senzing/senzing-tools demo-quickstart

    ```

1. In a separate window on your local workstation, start an interactive Python session.
   Example:

    ```console
    python3
    ```

1. To add your data sources to the Senzing configuration,
   determine the list of data sources used in your data.
   Then in the following example, modify the value of `DATASOURCES` to match your data.
   Also modify the value of `GRPC_URL` to use the custom port number specified above.

   Copy/modify/paste the following:

    ```python
    DATASOURCES = ["MY_DATASOURCE"]
    GRPC_URL = "localhost:9141"
    ```

   Copy/paste the following and press the **Enter** key.

    ```python
    import grpc

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
        for datasource in DATASOURCES:
            datasource_json = {"DSRC_CODE": datasource}
            g2_config.add_data_source(config_handle, datasource_json)
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

1. To add your data to the Senzing database,
   in the following example modify the value of `INPUT_FILENAME` to match the path to your file of JSON lines.
   For Windows, use a format like `C:\\Users\\username\\Downloads\\example-data-for-senzing.json` for `INPUT_FILENAME`.

   Copy/modify/paste the following:

    ```python
    INPUT_FILENAME = "/tmp/example-data-for-senzing.json"
    ```

   Copy/paste the following and press the **Enter** key.

    ```python
    import json

    try:
        with open(INPUT_FILENAME, "r") as file:
            for line in file:
                line_as_dict = json.loads(line)
                data_source = line_as_dict.get("DATA_SOURCE")
                record_id = line_as_dict.get("RECORD_ID")
                g2_engine.add_record(data_source, record_id, line)
    except G2Exception as err:
        print(f"\nError:\n{err}\n")

    ```

   Note that this is a simple example of adding records to Senzing and is not optimized for performance.
   For higher performance techniques, additional Python programming is needed.
   For examples, see
   [High performance loading with Python](#).

1. Once records have been inserted you can
   [Explore data using Senzing tools](#explore-data-using-senzing-tools) using
   the custom port number chosen above.  Examples:
    1. [http://localhost:9140/entity-search](http://localhost:9140/entity-search).
    1. [http://localhost:9140/xterm](http://localhost:9140/xterm).

1. To end the Senzing gRPC service using Docker,
   use `ctrl-c` to stop the `docker run ...` program.

1. To restart the service, re-run the command seen in Step #3.
   Although the port mappings using `--publish` may be changed, the value of `--volume`
   must match the original value so the database files on your workstation will be attached.

   **Linux/macOS example:**

    ```console
    docker run \
        --name senzing-my-demo-1 \
        --publish 9140:8260 \
        --publish 9141:8261 \
        --pull always \
        --rm \
        --volume ${SENZING_MY_DEMO_1}:/tmp/sqlite \
        senzing/senzing-tools demo-quickstart

    ```

   **Windows Command Prompt (not Windows PowerShell) example:**

    ```console
    docker run ^
        --name senzing-my-demo-1 ^
        --publish 9140:8260 ^
        --publish 9141:8261 ^
        --pull always ^
        --rm ^
        --volume %SENZING_MY_DEMO_1%:/tmp/sqlite ^
        senzing/senzing-tools demo-quickstart

    ```

    *Remember:* Use the new port values in the interactive Python and web URLs.
