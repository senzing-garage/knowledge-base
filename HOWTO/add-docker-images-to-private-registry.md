# Add docker images to private registry

## Prerequisites

1. If you need to create a private docker registry, see
       [HOWTO - Install docker registry server](https://github.com/Senzing/knowledge-base/blob/master/HOWTO/install-docker-registry-server.md).

## Identify private registry

1. :pencil2: Set environment variable.  Example:

    ```console
    export DOCKER_REGISTRY_URL=my.docker-registry.com:5000
    ```

## Identify docker images

1. :pencil2: List docker images in an environment variable.  Example:

    ```console
    export DOCKER_IMAGE_NAMES=( \
      "senzing/mock-data-generator:latest" \
      "senzing/senzing-api-server:latest" \
      "senzing/senzing-debug:latest" \
      "senzing/senzing-package:latest" \
      "senzing/stream-loader:latest" \
    )
    ```

## Pull images from DockerHub

1. Add Senzing docker images to private docker registry.  Example:

    ```console
    for DOCKER_IMAGE_NAME in ${DOCKER_IMAGE_NAMES[@]};\
    do \
      sudo docker pull ${DOCKER_IMAGE_NAME}; \
    done
    ```

## Push images to private registry

1. Add Senzing docker images to private docker registry.  Example:

    ```console
    for DOCKER_IMAGE_NAME in ${DOCKER_IMAGE_NAMES[@]};\
    do \
      sudo docker tag  ${DOCKER_IMAGE_NAME} ${DOCKER_REGISTRY_URL}/${DOCKER_IMAGE_NAME}; \
      sudo docker push ${DOCKER_REGISTRY_URL}/${DOCKER_IMAGE_NAME}; \
      sudo docker rmi  ${DOCKER_REGISTRY_URL}/${DOCKER_IMAGE_NAME}; \
    done
    ```
