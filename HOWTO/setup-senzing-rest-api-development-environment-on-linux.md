# Setup Senzing REST API development environment on Linux

This set of instructions shows how to use Linux terminal instructions
to setup and run a
[Senzing API Server](https://github.com/Senzing/senzing-api-server).

With a running Senzing API server on a local Linux machine,
a developer can write code that makes network requests
(i.e. HTTP request) to the Senzing API server.

## Contents

1. [Prerequisites](#prerequisites)
    1. [Install Docker](#install-docker)
    1. [Install curl](#install-curl)
1. [Set environment](#set-environment)
    1. [Specify project name](#specify-project-name)
    1. [EULA](#eula)
    1. [Synthesize variables](#synthesize-variables)
1. [Install and configure Senzing](#install-and-configure-senzing)
    1. [Download Senzing](#download-senzing)
    1. [Configure files and database](#configure-files-and-database)
1. [Load Senzing Engine](#load-senzing-engine)
    1. [Load Senzing Truth Set](#load-senzing-truth-set)
    1. [Load custom file](#load-custom-file)
1. [Access Senzing Model](#access-senzing-model)
    1. [Run Senzing API service](#run-senzing-api-service)
    1. [Run Senzing Entity search web app](#run-senzing-entity-search-web-app)
    1. [Run Senzing Console](#run-senzing-console)
    1. [run Jupyter notebooks](#run-jupyter-notebooks)

## Prerequisites

### Install Docker

1. See [How to install docker](install-docker.md).

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

### Specify project name

1. :pencil2: Choose a project name.
   This will be used to create a subdirectory containing all of the Senzing artifacts.
   Example:

    ```console
    export SENZING_PROJECT_NAME=project01
    ```

### EULA

To use the Senzing code, you must agree to the End User License Agreement (EULA).

1. :warning: This step is intentionally tricky and not simply copy/paste.
   This ensures that you make a conscious effort to accept the EULA.
   Example:

    <pre>export SENZING_ACCEPT_EULA="&lt;the value from <a href="https://github.com/Senzing/knowledge-base/blob/main/lists/environment-variables.md#senzing_accept_eula">this link</a>&gt;"</pre>

### Synthesize variables

1. Given the variables set before, create new environment variables for use with docker commands.
   Example:

    ```console
    export SENZING_PROJECT_DIR=~/${SENZING_PROJECT_NAME}

    export SENZING_DATA_DIR=${SENZING_PROJECT_DIR}/data
    export SENZING_DATA_VERSION_DIR=${SENZING_PROJECT_DIR}/data/1.0.0
    export SENZING_ETC_DIR=${SENZING_PROJECT_DIR}/etc
    export SENZING_G2_DIR=${SENZING_PROJECT_DIR}/g2
    export SENZING_VAR_DIR=${SENZING_PROJECT_DIR}/var
    ```

## Install and configure Senzing

These steps only need to be run once per `SENZING_PROJECT_NAME` to install and configure Senzing.

### Download Senzing

1. Running the
   [senzing/yum](https://github.com/Senzing/docker-yum)
   docker container will install Senzing binaries
   into the `SENZING_PROJECT_DIR` directory.
   Example:

    ```console
    docker run \
      --env SENZING_ACCEPT_EULA=${SENZING_ACCEPT_EULA} \
      --rm \
      --volume ${SENZING_DATA_DIR}:/opt/senzing/data \
      --volume ${SENZING_G2_DIR}:/opt/senzing/g2 \
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
    docker run \
      --rm \
      --user 0 \
      --volume ${SENZING_DATA_VERSION_DIR}:/opt/senzing/data \
      --volume ${SENZING_ETC_DIR}:/etc/opt/senzing \
      --volume ${SENZING_G2_DIR}:/opt/senzing/g2 \
      --volume ${SENZING_VAR_DIR}:/var/opt/senzing \
      senzing/init-container
    ```

1. Wait until docker container exits.

## Load Senzing Engine

:thinking:  **Optional:**
These steps show how to load the Senzing Engine using the `G2Loader.py` program.
Once they are run, the Senzing model is persisted in the SQLite database located at
`${SENZING_VAR_DIR}/var/sqlite`.

### Load Senzing Truth Set

:thinking:  **Optional:**

1. Download "truth set" files.
   Example:

    ```console
    curl -X GET \
        --output ${SENZING_VAR_DIR}/truthset-person-v1-set1.csv \
        https://public-read-access.s3.amazonaws.com/TestDataSets/SenzingTruthSet/truthset-person-v1-set1.csv
    ```

    ```console
    curl -X GET \
        --output ${SENZING_VAR_DIR}/truthset-person-v1-set2.csv \
        https://public-read-access.s3.amazonaws.com/TestDataSets/SenzingTruthSet/truthset-person-v1-set2.csv
    ```

1. Create `${SENZING_VAR_DIR}/sample-data-project.csv` file with following contents:

    ```csv
    DATA_SOURCE,FILE_FORMAT,FILE_NAME
    customer,CSV,/var/opt/senzing/truthset-person-v1-set1.csv
    watchlist,CSV,/var/opt/senzing/truthset-person-v1-set2.csv
    ```

1. Create `${SENZING_VAR_DIR}/sample-data-project.ini` file with following contents:

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
    docker run \
        --rm \
        --volume ${SENZING_DATA_VERSION_DIR}:/opt/senzing/data \
        --volume ${SENZING_ETC_DIR}:/etc/opt/senzing \
        --volume ${SENZING_G2_DIR}:/opt/senzing/g2 \
        --volume ${SENZING_VAR_DIR}:/var/opt/senzing \
        senzing/g2loader \
            -p /var/opt/senzing/sample-data-project.csv
    ```

### Load custom file

:thinking: **Optional:** This optional step uses the `G2Loader.py` to populate
the Senzing Model with custom data.

1. Copy source files to the `${SENZING_VAR_DIR}` folder.

1. Running the
   [senzing/xterm](https://github.com/Senzing/docker-xterm)
   docker container will allow a user to run a command terminal.
   Example:

    ```console
    docker run \
      --interactive \
      --publish 8254:5000 \
      --rm \
      --tty \
      --volume ${SENZING_DATA_VERSION_DIR}:/opt/senzing/data \
      --volume ${SENZING_ETC_DIR}:/etc/opt/senzing \
      --volume ${SENZING_G2_DIR}:/opt/senzing/g2 \
      --volume ${SENZING_VAR_DIR}:/var/opt/senzing \
      senzing/xterm
    ```

1. Using a web browser, visit [localhost:8254](http://localhost:8254)
1. In Senzing Xterm, run

    ```console
    G2Loader.py /var/opt/senzing/<name-of-file>
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
    docker run \
      --publish 8250:8250 \
      --rm \
      --volume ${SENZING_DATA_VERSION_DIR}:/opt/senzing/data \
      --volume ${SENZING_ETC_DIR}:/etc/opt/senzing \
      --volume ${SENZING_G2_DIR}:/opt/senzing/g2 \
      --volume ${SENZING_VAR_DIR}:/var/opt/senzing \
      senzing/senzing-api-server \
        -allowedOrigins "*" \
        -bindAddr all \
        -concurrency 10 \
        -httpPort 8250 \
        -iniFile /etc/opt/senzing/G2Module.ini
    ```

1. From a separate Command Prompt window, use a `curl` call to verify the Senzing API Service is running
   Example:

    ```console
    curl http://localhost:8250/heartbeat
    ```

1. Use the [Swagger Editor](http://editor.swagger.io/?url=https://raw.githubusercontent.com/Senzing/senzing-rest-api-specification/main/senzing-rest-api.yaml) to test drive the [Senzing API](https://github.com/Senzing/senzing-rest-api-specification).

### Run Senzing Entity search web app

1. :pencil2: Identify the IP address of the host system.
   Example:

    ```console
    export SENZING_DOCKER_HOST_IP_ADDR=10.1.1.100
    ```

    1. To find the value for `SENZING_DOCKER_HOST_IP_ADDR` by using Python interactively, visit
       [SENZING_DOCKER_HOST_IP_ADDR](https://github.com/Senzing/knowledge-base/blob/main/lists/environment-variables.md#senzing_docker_host_ip_addr).

1. Running the
   [Senzing Entity Search Web App](https://github.com/Senzing/entity-search-web-app)
   docker container will deliver the Entity Search Web App on port 8251.
   Example:

    ```console
    docker run \
      --env SENZING_API_SERVER_URL=http://${SENZING_DOCKER_HOST_IP_ADDR}:8250 \
      --env SENZING_WEB_SERVER_ADMIN_AUTH_MODE=JWT \
      --env SENZING_WEB_SERVER_ADMIN_AUTH_PATH=http://localhost:8251 \
      --env SENZING_WEB_SERVER_API_PATH=/api \
      --env SENZING_WEB_SERVER_PORT=8251 \
      --env SENZING_WEB_SERVER_URL=http://localhost:8251 \
      --publish 8251:8251 \
      --rm \
      senzing/entity-search-web-app
    ```

1. Visit Senzing Entity Search Web App at [localhost:8251](http://localhost:8251).

### Run Senzing Console

1. To run a Linux shell using Docker, run the Senzing console.
   Example:

    ```console
    docker run \
      --interactive \
      --rm \
      --tty \
      --volume ${SENZING_DATA_VERSION_DIR}:/opt/senzing/data \
      --volume ${SENZING_ETC_DIR}:/etc/opt/senzing \
      --volume ${SENZING_G2_DIR}:/opt/senzing/g2 \
      --volume ${SENZING_VAR_DIR}:/var/opt/senzing \
      senzing/senzing-console /bin/bash
    ```

### Run Jupyter notebooks

1. Run Jupyter notebooks using Docker.
   Example:

    ```console
    docker run \
      --env SENZING_SQL_CONNECTION=sqlite3://na:na@/var/opt/senzing/sqlite/G2C.db \
      --interactive \
      --publish 9178:8888 \
      --rm \
      --tty \
      --volume ${SENZING_PROJECT_DIR}/notebooks/shared \
      --volume ${SENZING_DATA_VERSION_DIR}:/opt/senzing/data \
      --volume ${SENZING_ETC_DIR}:/etc/opt/senzing \
      --volume ${SENZING_G2_DIR}:/opt/senzing/g2 \
      --volume ${SENZING_VAR_DIR}:/var/opt/senzing \
      senzing/jupyter start.sh jupyter notebook --NotebookApp.token=''
    ```

1. Visit Senzing Jupyter notebooks
   [localhost:9178](http://localhost:9178).
