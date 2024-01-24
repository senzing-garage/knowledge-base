# Entity resolution in motion

In this demonstration, ...

Pattern:

1. Record into Python variable
1. run code to insert the single record
1. G2Snapshot.py
1. G2Explorer.py
1. repeat

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

1. To add your data sources to the Senzing configuration,
   determine the list of data sources used in your data.
   Also modify the value of `GRPC_URL` to use the custom port number specified above.

   Copy/paste the following into the interactive Python session
   and press the **Enter** key.

    ```python
    GRPC_URL = "localhost:8261"

    def add_record_to_senzing(record)
    ```

1. To add your data sources to the Senzing configuration,
   determine the list of data sources used in your data.
   Also modify the value of `GRPC_URL` to use the custom port number specified above.

   Copy/paste the following into the interactive Python session
   and press the **Enter** key.

    ```python
    INPUT_RECORD = ``
    GRPC_URL = "localhost:8261"
    ```
