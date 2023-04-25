# docker-air-gap-helper

The following instructions show how to prepare a TGZ file containing
[senzing-enviroment](https://github.com/Senzing/senzing-environment)
and its dependencies.
The TGZ file is used in an air-gapped environment
for adding Docker support to an existing Senzing project.

The instructions have 3 major steps:

1. On a non-air-gapped system, create a TGZ file.
1. Transfer the TGZ file from the non-air-gapped system to the air-gapped system.
1. On the air-gapped system, use the TGZ file to populate an local Docker repository,
   (optionally) populate a private Docker registry,
   and run a program to add Docker support to an existing Senzing project.

## Contents

1. [On non-air-gapped system](#on-non-air-gapped-system)
    1. [Package docker images](#package-docker-images)
    1. [Create docker-load.sh file](#create-docker-load-sh-file)
1. [Transfer](#transfer)
1. [On air-gapped system](#on-air-gapped-system)
    1. [Identify files](#identify-files)
    1. [Extract file](#extract-file)
    1. [Load local Docker repository](#load-local-docker-repository)
    1. [Load private Docker registry](#load-private-docker-registry)

## On non-air-gapped system

The goal of these steps is to produce a compressed file in `tgz` format
containing Docker images that can be installed on an air-gapped private Docker registry.

The following steps are performed on an internet-connected system.
They will not work on an air-gapped system.

### Package docker images

1. :pencil2: Identify a new directory for outputting files.
   Example:

    ```console
    export SENZING_DOCKER_DIR=~/my-senzing-docker

    ```

1. Make directories for output.
   Example:

    ```console
    mkdir -p ${SENZING_DOCKER_DIR}

    ```

1. Get versions of Docker images.
   Example:

    ```console
    curl -X GET \
        --output ${SENZING_DOCKER_DIR}/docker-versions-stable.sh \
        https://raw.githubusercontent.com/Senzing/knowledge-base/main/lists/docker-versions-stable.sh
    source ${SENZING_DOCKER_DIR}/docker-versions-stable.sh

    ```

1. :pencil2: List Docker images to be packages.
   Add or delete Docker images from the list.
   Example:

    ```console
    export DOCKER_IMAGE_NAMES=(
        "bitnami/kafka:${SENZING_DOCKER_IMAGE_VERSION_BITNAMI_KAFKA:-latest}"
        "bitnami/rabbitmq:${SENZING_DOCKER_IMAGE_VERSION_BITNAMI_RABBITMQ:-latest}"
        "bitnami/zookeeper:${SENZING_DOCKER_IMAGE_VERSION_BITNAMI_ZOOKEEPER:-latest}"
        "coleifer/sqlite-web:${SENZING_DOCKER_IMAGE_VERSION_SQLITE_WEB:-latest}"
        "confluentinc/cp-kafka:${SENZING_DOCKER_IMAGE_VERSION_CONFLUENTINC_CP_KAFKA:-latest}"
        "dpage/pgadmin4:${SENZING_DOCKER_IMAGE_VERSION_DPAGE_PGADMIN4:-latest}"
        "obsidiandynamics/kafdrop:${SENZING_DOCKER_IMAGE_VERSION_OBSIDIANDYNAMICS_KAFDROP:-latest}"
        "senzing/adminer:${SENZING_DOCKER_IMAGE_VERSION_ADMINER:-latest}"
        "senzing/apt:${SENZING_DOCKER_IMAGE_VERSION_APT:-latest}"
        "senzing/configurator:${SENZING_DOCKER_IMAGE_VERSION_CONFIGURATOR:-latest}"
        "senzing/data-encryption-aes256cbc-sample:${SENZING_DOCKER_IMAGE_VERSION_DATA_ENCRYPTION_AES256CBC_SAMPLE:-latest}"
        "senzing/db2-driver-installer:${SENZING_DOCKER_IMAGE_VERSION_DB2_DRIVER_INSTALLER:-latest}"
        "senzing/entity-search-web-app-console:${SENZING_DOCKER_IMAGE_VERSION_ENTITY_SEARCH_WEB_APP_CONSOLE:-latest}"
        "senzing/entity-search-web-app:${SENZING_DOCKER_IMAGE_VERSION_ENTITY_SEARCH_WEB_APP:-latest}"
        "senzing/file-loader:${SENZING_DOCKER_IMAGE_VERSION_FILE_LOADER:-latest}"
        "senzing/ibm-db2:${SENZING_DOCKER_IMAGE_VERSION_IBM_DB2:-latest}"
        "senzing/init-container:${SENZING_DOCKER_IMAGE_VERSION_INIT_CONTAINER:-latest}"
        "senzing/init-postgresql:${SENZING_DOCKER_IMAGE_VERSION_INIT_POSTGRESQL:-latest}"
        "senzing/postgresql-client:${SENZING_DOCKER_IMAGE_VERSION_POSTGRESQL_CLIENT:-latest}"
        "senzing/redoer:${SENZING_DOCKER_IMAGE_VERSION_REDOER:-latest}"
        "senzing/resolver:${SENZING_DOCKER_IMAGE_VERSION_RESOLVER:-latest}"
        "senzing/senzing-api-server:${SENZING_DOCKER_IMAGE_VERSION_SENZING_API_SERVER:-latest}"
        "senzing/senzing-base:${SENZING_DOCKER_IMAGE_VERSION_SENZING_BASE:-latest}"
        "senzing/senzing-console-slim:${SENZING_DOCKER_IMAGE_VERSION_SENZING_CONSOLE_SLIM:-latest}"
        "senzing/senzing-console:${SENZING_DOCKER_IMAGE_VERSION_SENZING_CONSOLE:-latest}"
        "senzing/senzing-poc-server:${SENZING_DOCKER_IMAGE_VERSION_SENZING_POC_SERVER:-latest}"
        "senzing/senzing-tools:${SENZING_DOCKER_IMAGE_VERSION_SENZING_TOOLS:-latest}"
        "senzing/senzingapi-runtime:${SENZING_DOCKER_IMAGE_VERSION_SENZINGAPI_RUNTIME:-latest}"
        "senzing/senzingapi-tools:${SENZING_DOCKER_IMAGE_VERSION_SENZINGAPI_TOOLS:-latest}"
        "senzing/sshd:${SENZING_DOCKER_IMAGE_VERSION_SSHD:-latest}"
        "senzing/stream-loader:${SENZING_DOCKER_IMAGE_VERSION_STREAM_LOADER:-latest}"
        "senzing/stream-logger:${SENZING_DOCKER_IMAGE_VERSION_STREAM_LOGGER:-latest}"
        "senzing/stream-producer:${SENZING_DOCKER_IMAGE_VERSION_STREAM_PRODUCER:-latest}"
        "senzing/web-app-demo:${SENZING_DOCKER_IMAGE_VERSION_WEB_APP_DEMO:-latest}"
        "senzing/xterm:${SENZING_DOCKER_IMAGE_VERSION_XTERM=:-latest}"
        "senzing/yum:${SENZING_DOCKER_IMAGE_VERSION_YUM:-latest}"
    )

    ```

1. Pull Docker images to local workstation.
   Example:

    ```console
    for DOCKER_IMAGE_NAME in ${DOCKER_IMAGE_NAMES[@]};
    do
      docker pull ${DOCKER_IMAGE_NAME}
    done

    ```

1. Save Docker images as a `.tar` file.
   Example:

    ```console
    docker save ${DOCKER_IMAGE_NAMES[@]} --output ${SENZING_DOCKER_DIR}/docker-images.tar

    ```

1. Compress `.tar` file to make it smaller.
   Example:

    ```console
    tar -czvf ${SENZING_DOCKER_DIR}/docker-images.tgz ${SENZING_DOCKER_DIR}/docker-images.tar

    ```

### Create docker-load.sh file

1. :pencil2: Identify the URL of the private Docker registry.
   Example:

    ```console
    export DOCKER_REGISTRY_URL=my.docker-registry.com:5000

    ```

1. Create `docker-load.sh` shell script to load files on air-gapped system.
   Example:

    ```console
    for DOCKER_IMAGE_NAME in ${DOCKER_IMAGE_NAMES[@]};
    do
      echo "" >> ${OUTPUT_LOAD_REGISTRY_SCRIPT}
      echo "docker tag ${DOCKER_IMAGE_NAME} \${DOCKER_REGISTRY_URL}/${DOCKER_IMAGE_NAME}" >> ${SENZING_DOCKER_DIR}/docker-load.sh
      echo "docker push \${DOCKER_REGISTRY_URL}/${DOCKER_IMAGE_NAME}" >> ${SENZING_DOCKER_DIR}/docker-load.sh
      echo "docker rmi \${DOCKER_REGISTRY_URL}/${DOCKER_IMAGE_NAME}" >> ${SENZING_DOCKER_DIR}/docker-load.sh
    done
    ```

## Transfer

1. Transfer the following files to the air-gapped system:
    1. ${SENZING_DOCKER_DIR}/docker-images.tgz
    1. ${SENZING_DOCKER_DIR}/docker-load.sh

## On air-gapped system

The following instructions show how to populate a private registry in an air-gapped environment.

This method has been tested on Linux systems.

### Identify files

1. :pencil2: Specify the location of the `docker-images.tgz` and `docker-load.sh` files.
   Example:

    ```console
    export MY_DOCKER_IMAGE_TGZ=~/docker-images.tgz
    export MY_DOCKER_LOAD_SH=~/docker-load.sh

    ```

### Extract file

1. :pencil2: Specify the output location for uncompressing the file.
   Example:

    ```console
    export MY_OUTPUT_DIR=~/my-output

    mkdir --parents ${MY_OUTPUT_DIR}
    ```

1. Uncompress file.
   Example:

    ```console
    tar -zxvf ${MY_DOCKER_IMAGE_TGZ} --directory ${MY_OUTPUT_DIR}
    ```

### Load local Docker repository

This step will add the Docker images to the Docker repository on the local workstation.
The contents of the local Docker repository are seen via the `docker images` command.

1. Load Docker images onto local workstation.
   Example:

    ```console
    docker load --input ${MY_DOCKER_IMAGE_TGZ}
    ```

### Load private Docker registry

:thinking: **Optional:** This step is only needed if the Docker images
need to be added to a private Docker registry.
If working on a single workstation, this step is not necessary.

1. :pencil2: Run `docker-load.sh`
   Example:

    ```console
    ${MY_DOCKER_LOAD_SH}
    ```
