# How to update Senzing images on DockerHub

## Overview

Instructions for updating [Senzing Docker images on DockerHub](https://hub.docker.com/u/senzing).

### Contents

1. [Delete local Senzing images](#delete-local-senzing-images)
1. [Build docker images](#build-docker-images)
1. [Log into DockerHub](#log-into-dockerhub)
1. [Push to images DockerHub](#push-images-to-dockerhub)

## Delete local Senzing images

Delete Senzing images from local Docker repository.

1. List Senzing images.  Example:

    ```console
    sudo docker images | grep senzing
    ```

1. Delete docker images.  Example:

    ```console
    sudo docker rmi --force e8aeb6c2fd95 3f112102dccc
    ```

## Build docker images

1. Create docker images from repositories.  Example:

    ```console
    sudo docker build --tag senzing/senzing-base        https://github.com/senzing/docker-senzing-base.git
    sudo docker build --tag senzing/senzing-debug       https://github.com/senzing/docker-senzing-debug.git
    sudo docker build --tag senzing/g2command           https://github.com/senzing/docker-g2command.git
    sudo docker build --tag senzing/g2loader            https://github.com/senzing/docker-g2loader.git
    sudo docker build --tag senzing/jupyter             https://github.com/senzing/docker-jupyter.git
    sudo docker build --tag senzing/stream-producer     https://github.com/senzing/stream-producer.git
    sudo docker build --tag senzing/python-demo         https://github.com/senzing/docker-python-demo.git
    sudo docker build --tag senzing/senzing-poc-utility https://github.com/senzing/docker-senzing-poc-utility.git
    sudo docker build --tag senzing/stream-loader       https://github.com/senzing/stream-loader.git
    ```

1. Manual builds.
     1. [senzing/senzing-api-server](https://github.com/Senzing/senzing-api-server)

## Log into DockerHub

1. Use "[docker login](https://docs.docker.com/engine/reference/commandline/login/)".

1. Example:

    ```console
    docker login \
      --username my-username \
      --password my-password
    ```

## Push images to DockerHub

1. Make a list of Senzing docker images. Example:

    ```console
    export DOCKER_IMAGE_NAMES=( \
      "senzing/senzing-base" \
      "senzing/senzing-debug" \
      "senzing/g2command" \
      "senzing/g2loader" \
      "senzing/jupyter" \
      "senzing/stream-producer" \
      "senzing/python-demo" \
      "senzing/senzing-api-server" \
      "senzing/senzing-poc-utility" \
      "senzing/stream-loader" \
    )
    ```

1. :pencil2: Set tag of push.  Example:

    ```console
    export GIT_TAG=0.2.4
    ```

1. Push to DockerHub.  Example:

    ```console
    for DOCKER_IMAGE_NAME in ${DOCKER_IMAGE_NAMES[@]}; \
    do \
      sudo docker tag ${DOCKER_IMAGE_NAME} ${DOCKER_IMAGE_NAME}:${GIT_TAG}; \
      sudo docker push ${DOCKER_IMAGE_NAME}; \
      sudo docker push ${DOCKER_IMAGE_NAME}:${GIT_TAG}; \
      sudo docker rmi ${DOCKER_IMAGE_NAME}:${GIT_TAG}; \
    done
    ```
