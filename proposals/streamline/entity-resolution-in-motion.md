# Entity resolution in motion

In this demonstration, ...

Pattern:

1. Make sure the
   [prerequisites](README.md#Prerequisistes)
   are satisfied.

1. Specify where the SQLite Senzing database files are kept.

   **Linux/macOS example:**

   Use these instructions if you are running on a Linux or macOS system.

    1. To identify a directory to store the new SQLite database files,
       copy/modify/paste the following into the terminal window:

        ```console
        export SENZING_MY_DEMO_2="/tmp/my-demo-2"
        ```

   **Windows Command Prompt (not Windows PowerShell) example:**

   Use these instructions if you are running on a Windows system.

    1. To identify a directory to store the new SQLite database files,
       using an editor like Notepad
       copy/modify/paste the following into the Windows Command Prompt:

        ```console
        set SENZING_MY_DEMO_2="C:\\Users\\username\\my-demo-2"
        ```

1. **Optional:** If you don't already have a SQLite Senzing database,
   create new SQLite database files based on the value of `SENZING_MY_DEMO_2`.

   **Linux/macOS example:**

   Use these instructions if you are running on a Linux or macOS system.

    1. To create a new database in the directory,
       copy/paste the following into the terminal window:

        ```console
        mkdir ${SENZING_MY_DEMO_2}
        docker run \
            --env SENZING_TOOLS_DATABASE_URL=sqlite3://na:na@/tmp/sqlite/G2C.db \
            --rm \
            --volume ${SENZING_MY_DEMO_2}:/tmp/sqlite \
            senzing/senzing-tools init-database

        ```

   **Windows Command Prompt (not Windows PowerShell) example:**

   Use these instructions if you are running on a Windows system.

    1. To create a new database in the directory,
       copy/paste the following into the Windows Command Prompt:

        ```console
        mkdir %SENZING_MY_DEMO_2%
        docker run ^
            --env SENZING_TOOLS_DATABASE_URL=sqlite3://na:na@/tmp/sqlite/G2C.db ^
            --rm ^
            --volume %SENZING_MY_DEMO_2%:/tmp/sqlite ^
            senzing/senzing-tools init-database

        ```

1. Run a Senzing gRPC service using Docker.
   Notice that the `--volume` must point to the directory of the database files you wish to use.
   For more information on `docker run` parameters,
   visit [docker run](https://docs.docker.com/engine/reference/commandline/run/).

   **Linux/macOS example:**

   If you are running on a Linux or macOS system,
   copy/paste the following into the terminal window:

    ```console
    docker run \
        --name senzing-my-demo-1 \
        --publish 8260:8260 \
        --publish 8261:8261 \
        --pull always \
        --rm \
        --volume ${SENZING_MY_DEMO_2}:/tmp/sqlite \
        senzing/senzing-tools demo-quickstart

    ```

   **Windows Command Prompt (not Windows PowerShell) example:**

   If you are running on a Windows system,
   copy/paste the following into the Windows Command Prompt:

    ```console
    docker run ^
        --name senzing-my-demo-1 ^
        --publish 8260:8260 ^
        --publish 8261:8261 ^
        --pull always ^
        --rm ^
        --volume %SENZING_MY_DEMO_2%:/tmp/sqlite ^
        senzing/senzing-tools demo-quickstart

    ```

1. In a separate window on your local workstation, start an interactive Python session.
   Example:

    ```console
    python3
    ```

1. To create a connection to the Senzing gRPC service
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
            record.get("DATA_SOURCE"), record.get("RECORD_ID"), record, flags=-1
        )
        print(json.dumps(json.loads(result), indent=2))
    ```

## Iterate

The following iterations have a common pattern:

1. Insert a record into Senzing
1. Create a snapshot using `G2Snapshot.py`
1. Explore data using `G2Explorer.py`

You will be oscillating between two applications:

1. The window running `python3` known as the interactive Python session
1. A web browser based Xterm at
   [http://localhost:8260/xterm](http://localhost:8260/xterm).

### Iteration number 1

1. To add the first record
   copy/paste the following into the interactive Python session
   and press the **Enter** key.

    ```python
    (
        add_record_to_senzing(
            {
                "DATA_SOURCE": "Test",
                "RECORD_ID": "1",
                "DRIVERS_LICENSE_NUMBER": "00",
                "DATE_OF_BIRTH": "20/12/1965",
                "ADDR_POSTAL_CODE": "47201",
                "ADDR_CITY": "Columbus",
                "SSN_NUMBER": "883-24-5259",
                "NAME_FIRST": "CYNTHIA",
                "NAME_LAST": "SHORTS",
                "GENDER": "F",
                "DSRC_ACTION": "A",
                "ADDR_LINE1": "696 15th ST",
            }
        )
    )
    ```

1. Create a snapshot by running
   the following block of code in the web browser based Xterm:

   ```console
   G2Snapshot.py -o /tmp/senzing-my-demo-1.1 -a
   ```

1. Explore the data by running
   the following block of code in the web browser based Xterm:

    ```console
    G2Explorer.py -s /tmp/senzing-my-demo-1.1.json
    ```

1. TODO:
   Explain what to look at

### Iteration number 2

1. To add the second record
   copy/paste the following into the interactive Python session
   and press the **Enter** key.

    ```python
    (
        add_record_to_senzing(
            {
                "DATA_SOURCE": "TEST",
                "RECORD_ID": "2",
                "DATE_OF_BIRTH": "21/12/1965",
                "ADDR_POSTAL_CODE": "47201",
                "ADDR_CITY": "Columbus",
                "SSN_NUMBER": "883-24-525x",
                "NAME_FIRST": "CYN",
                "NAME_LAST": "SHORT",
                "GENDER": "F",
                "DSRC_ACTION": "A",
                "ADDR_LINE1": "695 15th ST"
            }
        )
    )
    ```

1. Create a snapshot by running
   the following block of code in the web browser based Xterm:

   ```console
   G2Snapshot.py -o /tmp/senzing-my-demo-1.2 -a
   ```

1. Explore the data by running
   the following block of code in the web browser based Xterm:

    ```console
    G2Explorer.py -s /tmp/senzing-my-demo-1.2.json
    ```

1. TODO:
   Explain what to look at

### Iteration number 3

1. To add the second record
   copy/paste the following into the interactive Python session
   and press the **Enter** key.

    ```python
    (
        add_record_to_senzing(
            {
                "DATA_SOURCE": "TEST",
                "RECORD_ID": "3",
                "DATE_OF_BIRTH": "20/12/1965",
                "ADDR_POSTAL_CODE": "47201",
                "ADDR_CITY": "Columbus",
                "SSN_NUMBER": "883-24-5258",
                "NAME_FIRST": "CYN",
                "NAME_LAST": "SHORT",
                "GENDER": "F",
                "DSRC_ACTION": "A",
                "ADDR_LINE1": "696 15th ST"
            }
        )
    )
    ```

1. Create a snapshot by running
   the following block of code in the web browser based Xterm:

   ```console
   G2Snapshot.py -o /tmp/senzing-my-demo-1.3 -a
   ```

1. Explore the data by running
   the following block of code in the web browser based Xterm:

    ```console
    G2Explorer.py -s /tmp/senzing-my-demo-1.3.json
    ```

1. TODO:
   Explain what to look at
