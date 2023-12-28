# How to pull latest Senzing docker images

## Build docker images

1. Build Senzing "helper" Docker images.
   Example:

    ```console
    docker build --tag senzing/mysql        https://github.com/senzing-garage/docker-mysql.git#main
    docker build --tag senzing/mysql-init   https://github.com/senzing-garage/docker-mysql-init.git#main

    ```

## Identify docker images

1. :pencil2: List docker images in DockerHub in an environment variable.
   Add or delete Docker images from the list.
   For extensive list, see
   [docker-image-names.sh](../lists/docker-image-names.sh)
   Example:

    ```console
    export DOCKER_IMAGE_NAMES=(
        "senzing/senzingapi-runtime:${SENZING_DOCKER_IMAGE_VERSION_SENZINGAPI_RUNTIME:-latest}"
    )

    ```

## Pull images from DockerHub

1. Add docker images to local docker repository.
   Example:

    ```console
    for DOCKER_IMAGE_NAME in ${DOCKER_IMAGE_NAMES[@]};\
    do \
        docker pull ${DOCKER_IMAGE_NAME}; \
    done

    ```
