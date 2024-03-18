# Experience Entity Resolution Record-by-Record  - Linux/macOS

In this demonstration, ...TODO:

## Prerequisites

1. Make sure the
   [prerequisites](README.md#Prerequisistes)
   are installed.
1. Make sure Docker is running.

## Initialize database

On your local workstation,
either create or reuse a SQLite Senzing database.

3. :pencil2:
   To identify a directory to store the new SQLite database files,
   copy/modify/paste the following into the terminal window:

    ```console
    export SENZING_MY_DEMO_2="/tmp/my-demo-2"
    ```

    For Docker Desktop on macOS,
    [file sharing](https://github.com/senzing-garage/knowledge-base/blob/main/HOWTO/share-directories-with-docker.md#macos)
    must be enabled for `SENZING_MY_DEMO_2` path.

    Remember the value of `SENZING_MY_DEMO_2` as it may be reused when doing a
    [restart](#restart).

1. **Optional:** If you don't already have a SQLite Senzing database,
   create new SQLite database files based on the value of `SENZING_MY_DEMO_2`.

   To create a new database in the directory,
   copy/paste the following into the terminal window:

    ```console
    mkdir ${SENZING_MY_DEMO_2}
    docker run \
        --env SENZING_TOOLS_DATABASE_URL=sqlite3://na:na@/tmp/sqlite/G2C.db \
        --pull always \
        --rm \
        --volume ${SENZING_MY_DEMO_2}:/tmp/sqlite \
        senzing/senzing-tools init-database

    ```

   The commands created new files in the `${SENZING_MY_DEMO_2}` directory.

## Run Senzing gRPC service

5. Run a Senzing gRPC service using Docker.
   Notice that the `--volume` must point to the directory of the database files you wish to use.
   For more information on `docker run` parameters,
   visit [docker run](https://docs.docker.com/engine/reference/commandline/run/).

   Copy/paste the following into the terminal window:

    ```console
    docker run \
        --name senzing-my-demo-2 \
        --publish 8260:8260 \
        --publish 8261:8261 \
        --pull always \
        --rm \
        --volume ${SENZING_MY_DEMO_2}:/tmp/sqlite \
        senzing/demo-quickstart

    ```

## Start interactive Python session

6. In a separate window on your local workstation, start an interactive Python session.
   Example:

    ```console
    python3

    ```

## Initialize python

7. To create a connection to the Senzing gRPC service
   and define a function for adding records,
   copy/paste the following into the interactive Python session
   and press the **Enter** key.

    ```python
    import json

    import grpc
    from senzing_grpc import G2EngineGrpc

    GRPC_URL = "localhost:8261"
    grpc_channel = grpc.insecure_channel(GRPC_URL)
    g2_engine = G2EngineGrpc(grpc_channel=grpc_channel)


    def add_record_to_senzing(record):
        result = g2_engine.add_record_with_info(
            record.get("DATA_SOURCE"), record.get("RECORD_ID"), record
        )
        print(json.dumps(json.loads(result), indent=2))

    ```

## Iterate

The following iterations have a common pattern:

1. Insert records into Senzing
1. Create a snapshot using `G2Snapshot.py`
1. Explore data using `G2Explorer.py`

You will be oscillating between two applications:

1. The window running `python3` known as the interactive Python session
1. A web browser based Xterm at
   [http://localhost:8260/xterm](http://localhost:8260/xterm).

### Iteration number 1

8. In the interactive Python session,
   to add the first two records
   copy/paste the following and press the **Enter** key.

    ```python
    (
        add_record_to_senzing(
            {
                "DATA_SOURCE": "Test",
                "RECORD_ID": "1",
                "DRIVERS_LICENSE_NUMBER": "12435345",
                "DATE_OF_BIRTH": "20/12/1965",
                "ADDR_FULL":"175 West Clay St, New York, Ohio 47201",
                "SSN_NUMBER": "883-24-5259",
                "NAME_FIRST": "CYNTHIA",
                "NAME_LAST": "SHORTS",
                "GENDER": "F",
                "DSRC_ACTION": "A"
            }
        )
    )

    (
        add_record_to_senzing(
            {
                "DATA_SOURCE": "Test",
                "RECORD_ID": "4",
                "DRIVERS_LICENSE_NUMBER": "12435345",
                "DATE_OF_BIRTH": "20/12/1965",
                "SSN_NUMBER": "883-24-5259",
                "ADDR_FULL":"3465 Wilmington Road, NY, Ohio 47201",
                "NAME_FULL": "Thea Shorts",
                "GENDER": "F",
                "DSRC_ACTION": "A"
            }
        )
    )

    ```

1. In the
   [web browser based Xterm](http://localhost:8260/xterm),
   create a snapshot by running the following block of code:

   ```console
   G2Snapshot.py -o /tmp/senzing-my-demo-2-1 -a
   ```

   *Note:* When pasting the command, make sure to remove any extra characters.

1. In the
   [web browser based Xterm](http://localhost:8260/xterm),
   explore the data by running the following block of code::

    ```console
    G2Explorer.py -s /tmp/senzing-my-demo-2-1.json
    ```

   *Note:* When pasting the command, make sure to remove any extra characters.

1. In `G2Explorer.py`,
   copy/paste the following and press the **Enter** key.

    ```console
    search {"DRIVERS_LICENSE_NUMBER": "12435345"}
    ```

   Notice two entities.
   One for "TEST: 1" and a second for "TEST: 4" seen in the "Data Sources" column.

1. :pencil2: In `G2Explorer.py`,
   using the "Entity ID" values from the two entities shown above,
   run `why`.
   Example:

    ```console
    why 1 2
    ```

   TODO: Explain what is shown.

1. To exit `G2Explorer.py`, enter

    ```console
    quit
    ```

### Iteration number 2

14. In the interactive Python session,
   to add the third record
   copy/paste the following and press the **Enter** key.

    ```python
    (
        add_record_to_senzing(
            {
                "DATA_SOURCE": "Test",
                "RECORD_ID": "6",
                "DRIVERS_LICENSE_NUMBER": "12435345",
                "DATE_OF_BIRTH": "20/12/1965",
                "SSN_NUMBER": "883-24-5259",
                "ADDR_FULL":"3465 Wilmington Road, NY, Ohio 47201",
                "NAME_FULL": "Cindy Shorter",
                "GENDER": "F",
                "DSRC_ACTION": "A"
            }
        )
    )

    ```

1. In the
   [web browser based Xterm](http://localhost:8260/xterm),
   create a snapshot by running the following block of code:

   ```console
   G2Snapshot.py -o /tmp/senzing-my-demo-2-2 -a
   ```

1. In the
   [web browser based Xterm](http://localhost:8260/xterm),
   explore the data by running the following block of code:

    ```console
    G2Explorer.py -s /tmp/senzing-my-demo-2-2.json
    ```

1. In `G2Explorer.py`,
   copy/paste the following and press the **Enter** key.

    ```console
    search {"DRIVERS_LICENSE_NUMBER": "12435345"}
    ```

   Notice one entity.
   There are no longer two entities, nor three.
   Senzing has determined that all three records refer to the same entity.

1. :pencil2: In `G2Explorer.py`,
   using the "Entity ID" value from the entity shown above,
   run `why`.
   Example:

    ```console
    why 1
    ```

    TODO:  Explain what is shown.

1. :pencil2: In `G2Explorer.py`,
   using the "Entity ID" value from the entity shown above,
   run `how`.
   Example:

    ```console
    how 1
    ```

   TODO: Explain what is shown.

1. To exit `G2Explorer.py`, enter

    ```console
    quit
    ```

## Shutdown

21. To end the Senzing gRPC service using Docker,
   use `ctrl-c` to stop the `docker run ...` program.

## Restart

22. To restart the service, re-run the command seen in Step #3.
   Although the port mappings using `--publish` may be changed, the value of `--volume`
   must match the original value so the database files on your workstation will be attached.

    1. :pencil2:
       To identify the directory storing the SQLite database files,
       copy/modify/paste the following into the terminal window:

        ```console
        export SENZING_MY_DEMO_2="/tmp/my-demo-2"
        ```

        The value of `SENZING_MY_DEMO_2` must match the value set in
        [Initialize database](#initialize-database)

    1. To re-run the docker container using the existing database files,
       copy/paste the following into the terminal window:

        ```console
        docker run \
            --name senzing-my-demo-2 \
            --publish 8260:8260 \
            --publish 8261:8261 \
            --pull always \
            --rm \
            --volume ${SENZING_MY_DEMO_2}:/tmp/sqlite \
            senzing/demo-quickstart

        ```

## Next steps

1. [Try Senzing's Hello World](README.md)
1. [Use Senzing's Truth Set data - Linux/macOS](use-senzings-truth-set-data-linux-macos.md)
1. [Map and load your own data - Linux/macOS](map-and-load-your-own-data-linux-macos.md)
1. Experience Entity Resolution Record-by-Record - Linux/macOS
1. [Bad-Guy Hunting](bad-guy-hunting/bad-guy-hunting-linux-macos.md)

## References

1. [View SQLite database](coleifer-sqlite-web.md)
