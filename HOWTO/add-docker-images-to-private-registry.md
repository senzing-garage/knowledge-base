# How to add Docker images to private registry

The following instructions show how to pull Docker containers
from public Docker registries
and push them to a private Docker registry.

## Contents

1. [Prerequisites](#prerequisites)
1. [Build docker images](#build-docker-images)
1. [Identify docker images](#identify-docker-images)
1. [Pull images from public Docker registries](#pull-images-from-public-docker-registries)
1. [Push images to private Docker registry](#pull-images-from-public-docker-registries)

## Prerequisites

1. If you need to create a private docker registry, see
       [HOWTO - Install docker registry server](https://github.com/Senzing/knowledge-base/blob/main/HOWTO/install-docker-registry-server.md).

## Build docker images

:thinking: **Optional:**
Build any Docker images that aren't on a public Docker registry.

1. Build Senzing "helper" Docker images.
   Example:

    ```console
    docker build --tag senzing/mysql        https://github.com/senzing/docker-mysql.git#main
    docker build --tag senzing/mysql-init   https://github.com/senzing/docker-mysql-init.git#main

    ```

## Identify docker images

1. :thinking: **Optional:**
   Specify versions of Docker images.
   Example:

    ```console
    curl -X GET \
        --output /tmp/docker-versions-stable.sh \
        https://raw.githubusercontent.com/Senzing/knowledge-base/main/lists/docker-versions-stable.sh
    source /tmp/docker-versions-stable.sh

    ```

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

## Pull images from public Docker registries

1. Add docker images to local docker repository.
   Example:

    ```console
    for DOCKER_IMAGE_NAME in ${DOCKER_IMAGE_NAMES[@]};\
    do \
      docker pull ${DOCKER_IMAGE_NAME}; \
    done

    ```

## Push images to private Docker registry

1. :pencil2: Identify the URL of the private Docker registry.
   Example:

    ```console
    export DOCKER_REGISTRY_URL=my.docker-registry.com:5000
    ```

1. Push Docker images to private docker registry.
   Example:

    ```console
    for DOCKER_IMAGE_NAME in ${DOCKER_IMAGE_NAMES[@]};\
    do
      docker tag  ${DOCKER_IMAGE_NAME} ${DOCKER_REGISTRY_URL}/${DOCKER_IMAGE_NAME};
      docker push ${DOCKER_REGISTRY_URL}/${DOCKER_IMAGE_NAME};
      docker rmi  ${DOCKER_REGISTRY_URL}/${DOCKER_IMAGE_NAME};
    done

    ```
