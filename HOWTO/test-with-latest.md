# HOWTO - Test with latest

## TL;DR

1. Perform once per new Senzing version:

    1. To use the Senzing code, you must agree to the End User License Agreement (EULA).

       :warning: This step is intentionally tricky and not simply copy/paste.
       This ensures that you make a conscious effort to accept the EULA.
       Example:

        <pre>export SENZING_ACCEPT_EULA="&lt;the value from <a href="https://github.com/Senzing/knowledge-base/blob/main/lists/environment-variables.md#senzing_accept_eula">this link</a>&gt;"</pre>

    1. Build a Docker image which will be used to install Senzing.
       Example:

        ```console
        curl -X GET \
            --output /tmp/senzing-versions-latest.sh \
            https://raw.githubusercontent.com/Senzing/knowledge-base/main/lists/senzing-versions-latest.sh

        source /tmp/senzing-versions-latest.sh

        sudo docker build \
          --build-arg SENZING_ACCEPT_EULA=${SENZING_ACCEPT_EULA} \
          --build-arg SENZING_APT_INSTALL_PACKAGE=senzingapi=${SENZING_VERSION_SENZINGAPI_BUILD} \
          --build-arg SENZING_DATA_VERSION=${SENZING_VERSION_SENZINGDATA} \
          --no-cache \
          --tag senzing/installer:${SENZING_VERSION_SENZINGAPI} \
          https://github.com/senzing/docker-installer.git#main
        ```

1. Bring up docker-compose stack.

    ```console
    sudo date
    curl -X GET \
        --output /tmp/senzing-versions-latest.sh \
        https://raw.githubusercontent.com/Senzing/knowledge-base/main/lists/senzing-versions-latest.sh
    source /tmp/senzing-versions-latest.sh
    export SENZING_VOLUME=~/senzing-${SENZING_VERSION_SENZINGAPI}
    rm -rf ${SENZING_VOLUME}
    mkdir -p ${SENZING_VOLUME}
    sudo docker run \
        --rm \
        --user 0 \
        --volume ${SENZING_VOLUME}:/opt/senzing \
        senzing/installer:${SENZING_VERSION_SENZINGAPI}
    export SENZING_DOCKER_COMPOSE_YAML=postgresql/docker-compose-rabbitmq-postgresql.yaml
    curl -X GET \
        --output ${SENZING_VOLUME}/docker-compose.yaml \
        "https://raw.githubusercontent.com/Senzing/docker-compose-demo/main/resources/${SENZING_DOCKER_COMPOSE_YAML}"
    export SENZING_DATA_DIR=${SENZING_VOLUME}/data
    export SENZING_DATA_VERSION_DIR=${SENZING_DATA_DIR}
    export SENZING_ETC_DIR=${SENZING_VOLUME}/etc
    export SENZING_G2_DIR=${SENZING_VOLUME}/g2
    export SENZING_VAR_DIR=${SENZING_VOLUME}/var
    export PGADMIN_DIR=${SENZING_VAR_DIR}/pgadmin
    export POSTGRES_DIR=${SENZING_VAR_DIR}/postgres
    export RABBITMQ_DIR=${SENZING_VAR_DIR}/rabbitmq
    sudo mkdir -p ${PGADMIN_DIR} ${POSTGRES_DIR} ${RABBITMQ_DIR}
    sudo chown $(id -u):$(id -g) -R ${SENZING_VOLUME}
    sudo chmod -R 770 ${SENZING_VOLUME}
    sudo chmod -R 777 ${PGADMIN_DIR} ${POSTGRES_DIR} ${RABBITMQ_DIR}
    curl -X GET \
        --output ${SENZING_VOLUME}/docker-versions-latest.sh \
        https://raw.githubusercontent.com/Senzing/knowledge-base/main/lists/docker-versions-latest.sh
    source ${SENZING_VOLUME}/docker-versions-latest.sh
    cd ${SENZING_VOLUME}
    sudo --preserve-env docker-compose up
    ```

1. Bring docker-compose stack down.

    ```console
    cd ${SENZING_VOLUME}
    sudo --preserve-env docker-compose down
    ```

## Docker senzing stack

These instructions create a Senzing stack with
stream-producer,
stream-loader,
senzing-poc-server,
entity-search-web-app,
and other "helper" docker containers.

1. :thinking: **Optional:**
   Start
   [portainer](../WHATIS/portainer.md).

1. Download and source the list of docker image version environment variables.
   Example:

    ```console
    curl -X GET \
        --output /tmp/senzing-versions-latest.sh \
        https://raw.githubusercontent.com/Senzing/knowledge-base/main/lists/senzing-versions-latest.sh

    source /tmp/senzing-versions-latest.sh
    ```

1. Create a docker-based Senzing installer.

   **Notes:**

    1. By running the command using `--build-arg SENZING_ACCEPT_EULA` you consent to the Senzing EULA.
    1. `SENZING_VERSION_*` variable were "sourced" above.
    1. When there is a change in the packages on staging, the command needs to be re-run to pick up the latest package.

   Example:

    ```console
    sudo docker build \
      --build-arg SENZING_ACCEPT_EULA=I_ACCEPT_THE_SENZING_EULA \
      --build-arg SENZING_APT_INSTALL_PACKAGE=senzingapi=${SENZING_VERSION_SENZINGAPI_BUILD} \
      --build-arg SENZING_DATA_VERSION=${SENZING_VERSION_SENZINGDATA} \
      --no-cache \
      --tag senzing/installer:${SENZING_VERSION_SENZINGAPI} \
      https://github.com/senzing/docker-installer.git#main
    ```

1. :pencil2: Identify a new directory for the Senzing installation.
   That is, don't use an existing directory.
   Example:

    ```console
    export SENZING_VOLUME=~/senzing-${SENZING_VERSION_SENZINGAPI}
    ```

1. Install Senzing binaries into new directory.
   Example:

    ```console
    mkdir -p ${SENZING_VOLUME}

    sudo docker run \
        --rm \
        --user 0 \
        --volume ${SENZING_VOLUME}:/opt/senzing \
        senzing/installer:${SENZING_VERSION_SENZINGAPI}
    ```

1. :pencil2: Identify `docker-compose.yaml` file.
   List of files at
   [docker-compose-demo/resources](https://github.com/Senzing/docker-compose-demo/tree/main/resources).
   Example:

    ```console
    export SENZING_DOCKER_COMPOSE_YAML=postgresql/docker-compose-rabbitmq-postgresql.yaml
    ```

   Other candidate values:

    1. mysql/docker-compose-kafka-mysql.yaml
    1. mysql/docker-compose-rabbitmq-mysql.yaml
    1. postgresql/docker-compose-kafka-postgresql.yaml
    1. postgresql/docker-compose-rabbitmq-postgresql-redoer-rabbitmq-withinfo.yaml
    1. postgresql/docker-compose-rabbitmq-postgresql.yaml

1. Download the `docker-compose.yaml` file.
   Example:

    ```console
    curl -X GET \
        --output ${SENZING_VOLUME}/docker-compose.yaml \
        "https://raw.githubusercontent.com/Senzing/docker-compose-demo/main/resources/${SENZING_DOCKER_COMPOSE_YAML}"
    ```

1. Identify and prepare directories.
   Example:

    ```console
    export SENZING_DATA_DIR=${SENZING_VOLUME}/data
    export SENZING_DATA_VERSION_DIR=${SENZING_DATA_DIR}
    export SENZING_ETC_DIR=${SENZING_VOLUME}/etc
    export SENZING_G2_DIR=${SENZING_VOLUME}/g2
    export SENZING_VAR_DIR=${SENZING_VOLUME}/var

    export PGADMIN_DIR=${SENZING_VAR_DIR}/pgadmin
    export POSTGRES_DIR=${SENZING_VAR_DIR}/postgres
    export RABBITMQ_DIR=${SENZING_VAR_DIR}/rabbitmq

    sudo mkdir -p ${PGADMIN_DIR}
    sudo mkdir -p ${POSTGRES_DIR}
    sudo mkdir -p ${RABBITMQ_DIR}

    sudo chown $(id -u):$(id -g) -R ${SENZING_VOLUME}
    sudo chmod -R 770 ${SENZING_VOLUME}
    sudo chmod -R 777 ${PGADMIN_DIR}
    ```

1. Download and source the list of docker image version environment variables.
   Example:

    ```console
    curl -X GET \
        --output ${SENZING_VOLUME}/docker-versions-latest.sh \
        https://raw.githubusercontent.com/Senzing/knowledge-base/main/lists/docker-versions-latest.sh

    source ${SENZING_VOLUME}/docker-versions-latest.sh
    ```

1. :thinking: **Optional:**
   If you are testing locally built (i.e. "latest") docker images,
   `export` the appropriate `SENZING_DOCKER_IMAGE_VERSION_xxxx` variable(s).
   Example:

    ```console
    export SENZING_DOCKER_IMAGE_VERSION_SENZING_POC_SERVER=latest
    ```

   Other candidate values:

    1. SENZING_DOCKER_IMAGE_VERSION_SENZING_API_SERVER
    1. SENZING_DOCKER_IMAGE_VERSION_STREAM_PRODUCER
    1. SENZING_DOCKER_IMAGE_VERSION_POSTGRESQL_CLIENT
    1. SENZING_DOCKER_IMAGE_VERSION_INIT_CONTAINER
    1. SENZING_DOCKER_IMAGE_VERSION_STREAM_LOADER
    1. SENZING_DOCKER_IMAGE_VERSION_REDOER
    1. SENZING_DOCKER_IMAGE_VERSION_SENZING_POC_SERVER
    1. SENZING_DOCKER_IMAGE_VERSION_ENTITY_SEARCH_WEB_APP

1. Bring docker-compose stack up.
   Example:

    ```console
    cd ${SENZING_VOLUME}
    sudo --preserve-env docker-compose up
    ```

1. Do your testing.
    1. For help using the "helper" tools, see one of the following:
        1. [docker-compose-rabbitmq-postgresql](https://github.com/Senzing/docker-compose-demo/tree/main/docs/docker-compose-rabbitmq-postgresql#view-data)
        1. [docker-compose-rabbitmq-mysql](https://github.com/Senzing/docker-compose-demo/tree/main/docs/docker-compose-rabbitmq-mysql#view-data)
        1. [docker-compose-kafka-postgresql](https://github.com/Senzing/docker-compose-demo/tree/main/docs/docker-compose-kafka-postgresql#view-data)

1. Bring docker-compose stack down.
   Example:

    ```console
    cd ${SENZING_VOLUME}
    sudo --preserve-env docker-compose down
    ```

1. To cleanup, delete the `${SENZING_VOLUME}` directory.
