# Map and load your own data  - Windows

In this demonstration, your data will be added to the Senzing database.
This time the data will be persisted into SQLite database files residing on your local workstation
and custom ports will be used.

## Prerequisites

1. Make sure the
   [prerequisites](README.md#Prerequisistes)
   are installed.
1. Make sure Docker is running.

## Create your input file

3. On your local workstation, create a file of JSON-lines with your data to be loaded into Senzing.

   As an example, download
   [example-data-for-senzing.json](https://raw.githubusercontent.com/senzing-garage/knowledge-base/main/proposals/streamline/example-data-for-senzing.json) into your `Downloads` directory.

3. On your local workstation, create an empty Sqlite Senzing database on your local workstation.
   Modify the value of `SENZING_MY_DEMO_1` to specify where you want the database files kept.

    1. :pencil2:
       To identify a directory to store the new SQLite database files,
       using an editor like Notepad
       copy/modify/paste the following into the Windows Command Prompt (not Windows PowerShell):

        ```console
        set SENZING_MY_DEMO_1="C:\\Users\\username\\my-demo-1"
        ```

    1. To create a new database in the directory,
       copy/paste the following into the Windows Command Prompt (not Windows PowerShell):

        ```console
        mkdir %SENZING_MY_DEMO_1%
        docker run ^
            --env SENZING_TOOLS_DATABASE_URL=sqlite3://na:na@/tmp/sqlite/G2C.db ^
            --rm ^
            --volume %SENZING_MY_DEMO_1%:/tmp/sqlite ^
            senzing/senzing-tools init-database

        ```

   The commands created new files in the `%SENZING_MY_DEMO_1%` directory.

1. Run a Senzing gRPC service using Docker.
   Notice that the ports published via `--publish` must be unique for your workstation.
   Inside the container `8260` is the port of the HTTP server, `8261` is the port of the gRPC server.
   In the following example they are mapped to ports `9140` and `9141` on your workstation.
   Also notice that the `--volume` must point to the directory of the database files you wish to use.
   Optionally, you may change the `--name` value to a custom name.
   For more information on `docker run` parameters,
   visit [docker run](https://docs.docker.com/engine/reference/commandline/run/).

   Copy/paste the following into the Windows Command Prompt (not Windows PowerShell):

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

## Identify data sources

5. In a separate window on your local workstation, start an interactive Python session.
   Example:

    ```console
    python3

    ```

1. To add your data sources to the Senzing configuration,
   determine the list of data sources used in your data.
   Then in the following example, modify the value of `DATASOURCES` to match your data.
   Also modify the value of `GRPC_URL` to use the custom port number specified above.

    1. :pencil2:
       Copy/modify/paste the following into the interactive Python session
       and press the **Enter** key.

        ```python
        DATASOURCES = ["MY_DATASOURCE"]
        GRPC_URL = "localhost:9141"
        ```

    1. Copy/paste the following into the interactive Python session
       and press the **Enter** key.

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

## Add records

7. To add your data to the Senzing database,
   in the following example modify the value of `INPUT_FILENAME` to match the path to your file of JSON lines.

    1. :pencil2:
       To identify the file containing your data,
       copy/modify/paste the following into the interactive Python session:

        ```python
        INPUT_FILENAME = "C:\\Users\\username\\Downloads\\example-data-for-senzing.json"
        ```

    1. Copy/paste the following into the interactive Python session
       and press the **Enter** key.

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

1. To end the interactive Python session,
   copy/paste the following block of code into the interactive Python session
   and press the **Enter** key.

    ```python
    quit()

    ```

## Explore data using Senzing tools

9. Once records have been inserted you can
   [Explore data using Senzing tools](README.md#explore-data-using-senzing-tools) using
   the custom port number chosen above.  Examples:
    1. [http://localhost:9140/entity-search](http://localhost:9140/entity-search).
    1. [http://localhost:9140/xterm](http://localhost:9140/xterm).

1. To end the Senzing gRPC service using Docker,
   use `ctrl-c` to stop the `docker run ...` program.

## Restart

11. To restart the service, re-run the command seen in Step #3.
   Although the port mappings using `--publish` may be changed, the value of `--volume`
   must match the original value so the database files on your workstation will be attached.

    1. :pencil2:
       To identify the directory storing the SQLite database files,
       copy/modify/paste the following into the terminal window:

        ```console
        set SENZING_MY_DEMO_1="C:\\Users\\username\\my-demo-1"
        ```

    1. To re-run the docker container using the existing database files,
    copy/paste the following into the Windows Command Prompt (not Windows PowerShell):

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

## Next steps

1. [Try Senzing's Hello World](README.md)
1. [Use Senzing's Truth Set data - Windows](use-senzings-truth-set-data-windows.md)
1. Map and load your own data - Windows
1. [Experience Entity Resolution Record-by-Record - Windows](experience-entity-resolution-record-by-record-windows.md)

## References

1. [View SQLite database](coleifer-sqlite-web.md)
