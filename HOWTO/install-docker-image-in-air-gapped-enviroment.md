# Install docker image in an air-gapped environment

## Overview

The following steps show how to transfer a docker image from a machine
that is on the internet to a machine that is not on the internet, (i.e. "air-gapped").

### Contents

1. [Set environment variables](#set-environment-variables)
1. [Pull docker image to local repository](#pull-docker-image-to-local-repository)
1. [Package docker image](#package-docker-image)
1. [Transfer tar file to air-gapped machine](#transfer-tar-file-to-air-gapped-machine)
1. [Unpackage docker image to local repository](#unpackage-docker-image-to-local-repository)
1. [Push image to private registry](#push-image-to-private-registry)

## Set environment variables

1. Using [senzing/hello-world-on-hub-docker-com:latest](https://hub.docker.com/r/senzing/hello-world-on-hub-docker-com) as an example:

    ```console
    export DOCKER_ACCOUNT=senzing
    export DOCKER_IMAGE=hello-world-on-hub-docker-com
    export DOCKER_TAG=latest
    ```

## Pull docker image to local repository

1. On networked system:

    ```console
    docker pull ${DOCKER_ACCOUNT}/${DOCKER_IMAGE}:${DOCKER_TAG}
    ```

    Reference: [docker pull](https://docs.docker.com/engine/reference/commandline/pull/)

## Package docker image

1. Use `docker save` to package docker image. Example:

    ```console
    docker save ${DOCKER_ACCOUNT}/${DOCKER_IMAGE}:${DOCKER_TAG} \
      --output ~/${DOCKER_ACCOUNT}-${DOCKER_IMAGE}-${DOCKER_TAG}.tar
    ```

    Reference: [docker save](https://docs.docker.com/engine/reference/commandline/save/)

## Transfer tar file to air-gapped machine

1. If `scp` or `sftp` connectivity is available, a network file transfer is possible. Example:

    ```console
    scp ~/${DOCKER_ACCOUNT}-${DOCKER_IMAGE}-${DOCKER_TAG}.tar my.example.com:
    ```

1. If truly air-gapped, copy `tar` file to a portable storage medium to transfer to air-gapped machine.

## Unpackage docker image to local repository

1. On air-gapped machine, set environment variables.
   Using [senzing/hello-world-on-hub-docker-com:latest](https://hub.docker.com/r/senzing/hello-world-on-hub-docker-com) as an example:

    ```console
    export DOCKER_ACCOUNT=senzing
    export DOCKER_IMAGE=hello-world-on-hub-docker-com
    export DOCKER_TAG=latest
    ```

1. Unpackage `tar` file. Assuming `tar` file is in the ${HOME} directory, example:

    ```console
    docker load \
      --input ~/${DOCKER_ACCOUNT}-${DOCKER_IMAGE}-${DOCKER_TAG}.tar  
    ```

    Reference: [docker load](https://docs.docker.com/engine/reference/commandline/load/)

## Push image to private registry

1. Set environment variable. Example:

    ```console
    export DOCKER_REGISTRY_URL=my.docker-registry.com:5000
    ```

1. Tag docker image for private docker registry.

    ```console
    sudo docker tag \
      ${DOCKER_ACCOUNT}/${DOCKER_IMAGE}:${DOCKER_TAG} \
      ${DOCKER_REGISTRY_URL}/${DOCKER_ACCOUNT}/${DOCKER_IMAGE}:${DOCKER_TAG}
    ```

    Reference: [docker tag](https://docs.docker.com/engine/reference/commandline/tag/)

1. Push tagged image to private docker registry.

    ```console
    sudo docker push ${DOCKER_REGISTRY_URL}/${DOCKER_ACCOUNT}/${DOCKER_IMAGE}:${DOCKER_TAG}
    ```

    Reference: [docker push](https://docs.docker.com/engine/reference/commandline/push/)

1. Remove tag from local repository docker image.

    ```console
    sudo docker rmi ${DOCKER_REGISTRY_URL}/${DOCKER_ACCOUNT}/${DOCKER_IMAGE}:${DOCKER_TAG}
    ```

    Reference: [docker rmi](https://docs.docker.com/engine/reference/commandline/rmi/)
