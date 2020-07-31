# Setup Senzing REST API development environment on Windows

This set of instructions shows how to use Windows Command Prompt instructions
to setup and run a
[Senzing API Server](https://github.com/Senzing/senzing-api-server).

With a running Senzing API server on a local Windows machine,
a developer can write code that makes network requests
(i.e. HTTP request) to the Senzing API server.

## Contents

1. [Prerequisites](#prerequisites)
    1. [Install Docker for Windows](#install-docker-for-windows)
    1. [Install curl](#install-curl)
1. [Set environment](#set-environment)
    1. [Verify variables](#verify-variables)
    1. [Specify project name](#specify-project-name)
    1. [EULA](#eula)
    1. [Synthesize variables](#synthesize-variables)
    1. [Enable file sharing](#enable-file-sharing)
1. [Install and configure Senzing](#install-and-configure-senzing)
    1. [Download Senzing](#download-senzing)
    1. [Configure files and database](#configure-files-and-database)
1. [Load Senzing Engine](#load-senzing-engine)
    1. [Load Senzing Truth Set](#load-senzing-truth-set)
    1. [Load custom file](#load-custom-file)
1. [Access Senzing Model](#access-senzing-model)
    1. [Run Senzing API service](#run-senzing-api-service)
    1. [Run Senzing Entity search web app](#run-senzing-entity-search-web-app)

## Prerequisites

### Install Docker for Windows

1. [Install Docker Desktop on Windows](https://docs.docker.com/docker-for-windows/install/)
    1. Suggestion: Use "Get Stable"
1. Test. In a command prompt, run the following.
   Example:

    ```console
    docker version
    docker run hello-world
    ```

### Install curl

1. Test.
   Example:

    ```console
    curl --version
    ```

## Set environment

### Verify variables

1. The following variables will be used to construct `SENZING_PROJECT_DIR`.
   Example:

    ```console
    echo %HOMEDRIVE%
    echo %HOMEPATH%
    ```

### Specify project name

1. :pencil2: Choose a project name.
   This will be used to create a subdirectory containing all of the Senzing artifacts.
   Example:

    ```console
    set SENZING_PROJECT_NAME=project01
    ```

### EULA

To use the Senzing code, you must agree to the End User License Agreement (EULA).

1. :warning: This step is intentionally tricky and not simply copy/paste.
   This ensures that you make a conscious effort to accept the EULA.
   Example:

    <pre>set SENZING_ACCEPT_EULA="&lt;the value from <a href="https://github.com/Senzing/knowledge-base/blob/master/lists/environment-variables.md#senzing_accept_eula">this link</a>&gt;"</pre>

### Synthesize variables

1. Given the variables set before, create new environment variables for use with docker commands.
   Example:

    ```console
    set SENZING_PROJECT_DIR=%HOMEDRIVE%\%HOMEPATH%\%SENZING_PROJECT_NAME%

    set SENZING_DATA_DIR=%SENZING_PROJECT_DIR%\data
    set SENZING_DATA_VERSION_DIR=%SENZING_PROJECT_DIR%\data\1.0.0
    set SENZING_ETC_DIR=%SENZING_PROJECT_DIR%\etc
    set SENZING_G2_DIR=%SENZING_PROJECT_DIR%\g2
    set SENZING_VAR_DIR=%SENZING_PROJECT_DIR%\var
    ```

### Enable file sharing

1. :warning:
   **Windows** - [File sharing](https://github.com/Senzing/knowledge-base/blob/master/HOWTO/share-directories-with-docker.md#windows)
   must be enabled for `SENZING_PROJECT_DIR`.

## Install and configure Senzing

These steps only need to be run once per `SENZING_PROJECT_NAME` to install and configure Senzing.

### Download Senzing

1. Running the
   [senzing/yum](https://github.com/Senzing/docker-yum)
   docker container will install Senzing binaries
   into the `SENZING_PROJECT_DIR` directory.
   Example:

    ```console
    docker run ^
      --env SENZING_ACCEPT_EULA=%SENZING_ACCEPT_EULA% ^
      --rm ^
      --volume %SENZING_DATA_DIR%:/opt/senzing/data ^
      --volume %SENZING_G2_DIR%:/opt/senzing/g2 ^
      senzing/yum
    ```

1. Wait until docker container exits.

### Configure files and database

1. Running the
   [senzing/init-container](https://github.com/Senzing/docker-init-container)
   docker container will create Senzing configuration files
   in the `SENZING_PROJECT_DIR` directory.
   Example:

    ```console
    docker run ^
      --rm ^
      --volume %SENZING_DATA_VERSION_DIR%:/opt/senzing/data ^
      --volume %SENZING_ETC_DIR%:/etc/opt/senzing ^
      --volume %SENZING_G2_DIR%:/opt/senzing/g2 ^
      --volume %SENZING_VAR_DIR%:/var/opt/senzing ^
      senzing/init-container
    ```

1. Wait until docker container exits.

## Load Senzing Engine

:thinking:  **Optional:**
These steps show how to load the Senzing Engine using the `G2Loader.py` program.
Once they are run, the Senzing model is persisted in the SQLite database located at
`%SENZING_VAR_DIR%/var/sqlite`.

### Load Senzing Truth Set

:thinking:  **Optional:**

1. Download "truth set" files.
   Example:

    ```console
    curl -X GET ^
        --output %SENZING_VAR_DIR%\truthset-person-v1-set1.csv ^
        https://public-read-access.s3.amazonaws.com/TestDataSets/SenzingTruthSet/truthset-person-v1-set1.csv
    ```

    ```console
    curl -X GET ^
        --output %SENZING_VAR_DIR%/truthset-person-v1-set2.csv ^
        https://public-read-access.s3.amazonaws.com/TestDataSets/SenzingTruthSet/truthset-person-v1-set2.csv
    ```

1. Create `%SENZING_VAR_DIR%/sample-data-project.csv` file with following contents:

    ```csv
    DATA_SOURCE,FILE_FORMAT,FILE_NAME
    customer,CSV,/var/opt/senzing/truthset-person-v1-set1.csv
    watchlist,CSV,/var/opt/senzing/truthset-person-v1-set2.csv
    ```

1. Create `%SENZING_VAR_DIR%/sample-data-project.ini` file with following contents:

    ```console
    [g2]
    G2Connection=sqlite3://na:na@/var/opt/senzing/sqlite/G2C.db
    iniPath=/etc/opt/senzing/G2Module.ini
    collapsedTableSchema=Y
    evalQueueProcessing=1

    [project]
    projectFileName=/var/opt/senzing/sample-data-project.csv

    [transport]
    numThreads=4

    [report]
    sqlCommitSize=1000
    reportCategoryLimit=1000
    ```

1. Running the
   [senzing/g2loader](https://github.com/Senzing/docker-g2loader)
   docker container loads the contents of the downloaded files.
   Example:

    ```console
    docker run ^
        --rm ^
        --volume %SENZING_DATA_VERSION_DIR%:/opt/senzing/data ^
        --volume %SENZING_ETC_DIR%:/etc/opt/senzing ^
        --volume %SENZING_G2_DIR%:/opt/senzing/g2 ^
        --volume %SENZING_VAR_DIR%:/var/opt/senzing ^
        senzing/g2loader ^
            -c /var/opt/senzing/sample-data-project.ini ^
            -p /var/opt/senzing/sample-data-project.csv
    ```

### Load custom file

:thinking: **Optional:** This optional step uses the `G2Loader.py` to populate
the Senzing Model with custom data.

1. Copy source files to the `%SENZING_VAR_DIR%` folder.

1. Running the
   [senzing/xterm](https://github.com/Senzing/docker-xterm)
   docker container will allow a user to run a command terminal.
   Example:

    ```console
    docker run ^
      --interactive ^
      --rm ^
      --tty ^
      --volume %SENZING_DATA_VERSION_DIR%:/opt/senzing/data ^
      --volume %SENZING_ETC_DIR%:/etc/opt/senzing ^
      --volume %SENZING_G2_DIR%:/opt/senzing/g2 ^
      --volume %SENZING_VAR_DIR%:/var/opt/senzing ^
      senzing/xterm
    ```

1. Using a web browser, visit [localhost:5000](http://localhost:5000)
1. In Senzing Xterm, run

    ```console
    G2loader.py /var/opt/senzing/<name-of-file>
    ```

## Access Senzing Model

These steps set up services that can be used to access the Senzing Model.
They may be started and stopped repeatedly without having to perform the prior steps.

### Run Senzing API service

1. Running the
   [Senzing API Server](https://github.com/Senzing/senzing-api-server)
   docker container will serve HTTP requests on port 8250.
   Example:

    ```console
    docker run ^
      --publish 8250:8250 ^
      --rm ^
      --volume %SENZING_DATA_VERSION_DIR%:/opt/senzing/data ^
      --volume %SENZING_ETC_DIR%:/etc/opt/senzing ^
      --volume %SENZING_G2_DIR%:/opt/senzing/g2 ^
      --volume %SENZING_VAR_DIR%:/var/opt/senzing ^
      senzing/senzing-api-server ^
        -allowedOrigins "*" ^
        -bindAddr all ^
        -concurrency 10 ^
        -httpPort 8250 ^
        -iniFile /etc/opt/senzing/G2Module.ini
    ```

1. From a separate Command Prompt window, use a `curl` call to verify the Senzing API Service is running
   Example:

    ```console
    curl http://localhost:8250/heartbeat
    ```

1. Use the [Swagger Editor](http://editor.swagger.io/?url=https://raw.githubusercontent.com/Senzing/senzing-rest-api-specification/master/senzing-rest-api.yaml) to test drive the [Senzing API](https://github.com/Senzing/senzing-rest-api-specification).

### Run Senzing Entity search web app

1. Specify hostname/IP address of `senzing/senzing-api-server` docker container.
   **Note:** The use of `localhost` does not work.
   It must be an hostname/address that can be accessed from *within* the docker container.
   Example:

    ```console
    SENZING_API_SERVER_HOSTNAME=172.17.0.1
    ```

1. Running the
   [Senzing Entity Search Web App](https://github.com/Senzing/entity-search-web-app)
   docker container will deliver the Entity Search Web App on port 8251.
   Example:

    ```console
    docker run ^
      --env SENZING_API_SERVER_URL=http://%SENZING_API_SERVER_HOSTNAME%:8250 ^
      --env SENZING_WEB_SERVER_PORT=8251 ^
      --publish 8251:8251 ^
      --rm ^
      senzing/entity-search-web-app
    ```

1. Visit Senzing Entity Search Web App at [localhost:8251](http://localhost:8251).


### Run Senzing Entity search web app

1. Xxx

    ```console
    docker run ^
      --interactive ^
      --rm ^
      --tty ^
      --volume %SENZING_DATA_VERSION_DIR%:/opt/senzing/data ^
      --volume %SENZING_ETC_DIR%:/etc/opt/senzing ^
      --volume %SENZING_G2_DIR%:/opt/senzing/g2 ^
      --volume %SENZING_VAR_DIR%:/var/opt/senzing ^
      senzing/senzing-console /bin/bash
    ```
