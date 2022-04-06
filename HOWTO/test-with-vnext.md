# HOWTO - Test with VNext

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

1. Create a docker-based Senzing installer.

   **NOTES:**

    1. By running the command using `--build-arg SENZING_ACCEPT_EULA` you consent to the Senzing EULA.
    1. When there is a change in the packages on staging, the command needs to be re-run to pick up the latest package.

   Example:

    ```console
    sudo docker build \
      --build-arg SENZING_ACCEPT_EULA=I_ACCEPT_THE_SENZING_EULA \
      --build-arg SENZING_APT_INSTALL_PACKAGE=senzingapi \
      --build-arg SENZING_APT_REPOSITORY=https://senzing-staging-apt.s3.amazonaws.com/senzingstagingrepo_1.0.0-1_amd64.deb \
      --build-arg SENZING_DATA_VERSION=3.0.0 \
      --tag senzing/installer-staging:3.0.0 \
      https://github.com/senzing/docker-installer.git
    ```

1. :pencil2: Identify a new directory for the Senzing installation.
   That is, don't use an existing directory.
   Example:

    ```console
    export SENZING_VOLUME=~/senzing-3.0.0
    ```

1. Install Senzing binaries into new directory.
   Example:

    ```console
    mkdir -p ${SENZING_VOLUME}

    sudo docker run \
        --rm \
        --user 0 \
        --volume ${SENZING_VOLUME}:/opt/senzing \
        senzing/installer-staging:3.0.0

    sudo chown $(id -u):$(id -g) -R ${SENZING_VOLUME}
    sudo chmod 775 -R ${SENZING_VOLUME}
    ```

1. :pencil2: Identify `docker-compose.yaml` file.
   List of files at
   [docker-compose-demo/resources](https://github.com/Senzing/docker-compose-demo/tree/master/resources).
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
        https://raw.githubusercontent.com/Senzing/docker-compose-demo/master/resources/${SENZING_DOCKER_COMPOSE_YAML}
    ```

1. Identify ane prepare directories.
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

    sudo chown $(id -u):$(id -g) -R ${SENZING_VAR_DIR}
    sudo chmod -R 777 ${SENZING_VAR_DIR}
    ```

1. Download and source the list of docker image version environment variables.
   Example:

   ```console
    curl -X GET \
        --output ${SENZING_VOLUME}/docker-versions-v3.sh \
        https://raw.githubusercontent.com/Senzing/knowledge-base/master/lists/docker-versions-v3.sh}

    source ${SENZING_VOLUME}/docker-versions-v3.sh
    ```

1. :thinking: **Optional:**
   If you are testing locally built ("latest") docker images,
   `export` the appropriate `SENZING_DOCKER_IMAGE_VERSION_xxxx` variable(s).
   Example:

    ```console
    export SENZING_DOCKER_IMAGE_VERSION_SENZING_API_SERVER=latest
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

1. Do testing.
    1. For help using the "helper" tools, see one of the following:
        1. [docker-compose-rabbitmq-postgresql](https://github.com/Senzing/docker-compose-demo/tree/master/docs/docker-compose-rabbitmq-postgresql#view-data)
        1. [docker-compose-rabbitmq-mysql](https://github.com/Senzing/docker-compose-demo/tree/master/docs/docker-compose-rabbitmq-mysql#view-data)
        1. [docker-compose-kafka-postgresql](https://github.com/Senzing/docker-compose-demo/tree/master/docs/docker-compose-kafka-postgresql#view-data)

1. Bring docker-compose stack down.
   Example:

   ```console
    cd ${SENZING_VOLUME}
    sudo --preserve-env docker-compose down
    ```

1. To cleanup, delete the `${SENZING_VOLUME}` directory.
