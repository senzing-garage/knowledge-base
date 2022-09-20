# How to use senzingapi-runtime

## Synopsis

The
[senzing/senzingapi-runtime](https://hub.docker.com/r/senzing/senzingapi-runtime)
Docker image has the Senzing binaries "baked-in".
This Docker image and its corresponding
[senzingapi-runtime GitHub repository](https://github.com/Senzing/senzingapi-runtime)
can be used in a number of ways to simplify development using the Senzing SDK library.

## Overview

The

1. x

## Simple inheritance

Docker images consist of layers.
The Dockerfile's `FROM` instruction identifies the initial layer.
The `senzing/senzingapi-runtime` image can be used as an initial layer.

1. Use in a Dockerfile `FROM` instruction.
   Example:

    ```Dockerfile
    FROM senzing/senzingapi-runtime
    :
    ```

1. It's recommended to use a "pinned" version of an image.
   So in practice, it would look something more like:

    ```Dockerfile
    FROM senzing/senzingapi-runtime:3.2.0
    :
    ```

## Wrapping existing image

1. :pencil2: Set environment variables.

   - **DOCKER_BASE_IMAGE** - The Docker image to build upon.
     It will be used as the Dockerfile's `FROM` value.
     The image must be a debian-based Linux distribution
     (e.g. `debian`, `ubuntu`, and
     [others](https://en.wikipedia.org/wiki/List_of_Linux_distributions#Debian-based))
     Please note that `ubuntu:22.04` is currently not supported.
   - **DOCKER_IMAGE_SUFFIX** - A suffix to append to the *output* Docker image.
     This is meant to differentiate between the "stock" `senzing/senzingapi-runtime`
     and a customized `senzing/senzingapi-runtime-xyz`.
   - **SENZING_DOCKER_IMAGE_VERSION_SENZINGAPI_RUNTIME** - The version of the Senzing Dockerfile to use.
     The latest version can be seen in
     [docker-versions-latest.sh)](https://github.com/Senzing/knowledge-base/blob/main/lists/docker-versions-latest.sh).

   Example:

    ```console
    export DOCKER_BASE_IMAGE=ubuntu:20.04
    export DOCKER_IMAGE_SUFFIX=mycompany
    export SENZING_DOCKER_IMAGE_VERSION_SENZINGAPI_RUNTIME=3.2.0
    ```

1. Build new Docker image.
   Example:

    ```console
    docker pull ${DOCKER_BASE_IMAGE}

    docker build \
      --build-arg BASE_IMAGE=${DOCKER_BASE_IMAGE} \
      --tag senzing/senzingapi-runtime-${DOCKER_IMAGE_SUFFIX}:${SENZING_DOCKER_IMAGE_VERSION_SENZINGAPI_RUNTIME} \
      https://github.com/Senzing/senzingapi-runtime.git#${SENZING_DOCKER_IMAGE_VERSION_SENZINGAPI_RUNTIME}
    ```
