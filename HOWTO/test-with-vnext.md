# HOWTO - Test with VNext

## Docker senzing stack

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
    ```

1. :pencil2: Identify `docker-compose.yaml` file.
   List of files at
   [docker-compose-demo/resources](https://github.com/Senzing/docker-compose-demo/tree/master/resources).
   Example:

    ```console
    export SENZING_DOCKER_COMPOSE_YAML=postgresql/docker-compose-rabbitmq-postgresql.yaml
    ```

1. XX
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

    sudo chmod -R 777 ${SENZING_VAR_DIR}

    source <(curl -X GET https://raw.githubusercontent.com/Senzing/knowledge-base/master/lists/docker-versions-latest.sh)
    export SENZING_DOCKER_IMAGE_VERSION_SENZING_API_SERVER=latest

    curl -X GET \
        --output ${SENZING_VOLUME}/docker-compose.yaml \
        https://raw.githubusercontent.com/Senzing/docker-compose-demo/master/resources/${SENZING_DOCKER_COMPOSE_YAML}
    ```
