# How to use senzingapi-runtime

## Synopsis

The
[senzing/senzingapi-runtime](https://hub.docker.com/r/senzing/senzingapi-runtime)
Docker image has the Senzing binaries "baked-in".
This Docker image and its corresponding
[senzingapi-runtime GitHub repository](https://github.com/Senzing/senzingapi-runtime)
can be used in a number of ways to simplify development using the Senzing SDK library.

## Overview

There a few techniques to consider.
Each choice produces similar result,
so the choice will depend upon the existing Docker environment.

1. [Simple inheritance](#simple-inheritance)
1. [Wrap existing image](#wrap-existing-image)
1. [Add Docker instructions to existing Dockerfile](#add-docker-instructions-to-existing-dockerfile)

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

## Wrap existing image

The following steps creates a new Docker image by wrapping an existing image with Senzing binaries.

1. :pencil2: Set environment variables.

   - **DOCKER_BASE_IMAGE** - The Docker image to build upon.
     It will be used as the Dockerfile's `FROM` value.
     This may be an image that has been "blessed" by an organization.
     The image must be a debian-based Linux distribution
     (e.g. `debian`, `ubuntu`, and
     [others](https://en.wikipedia.org/wiki/List_of_Linux_distributions#Debian-based))
     Please note that `ubuntu:22.04` is currently not supported.
   - **DOCKER_IMAGE_SUFFIX** - A suffix to append to the *output* Docker image.
     This is meant to differentiate between the "stock" `senzing/senzingapi-runtime` Docker image
     and a customized `senzing/senzingapi-runtime-xyz` Docker image.

   Example:

    ```console
    export DOCKER_BASE_IMAGE=ubuntu:20.04
    export DOCKER_IMAGE_SUFFIX=mycompany

    ```

1. Get versions of Docker images.
   This step sets environment variables that will be used when creating Docker images.
   Example:

    ```console
    curl -X GET \
        --output /tmp/docker-versions-stable.sh \
        https://raw.githubusercontent.com/Senzing/knowledge-base/main/lists/docker-versions-stable.sh
    source /tmp/docker-versions-stable.sh

    ```

1. Synthesize environment variables.
   This step sets environment variables that simplify following steps.
   Example:

    ```console
    export DOCKER_IMAGE_TAG=senzing/senzingapi-runtime-${DOCKER_IMAGE_SUFFIX}:${SENZING_DOCKER_IMAGE_VERSION_SENZINGAPI_RUNTIME}
    echo ${DOCKER_IMAGE_TAG}

    ```

1. Build new Docker image that will become the "base image" for other Docker images.
   Example:

    ```console
    docker pull ${DOCKER_BASE_IMAGE}

    docker build \
      --build-arg BASE_IMAGE=${DOCKER_BASE_IMAGE} \
      --tag ${DOCKER_IMAGE_TAG} \
      https://github.com/Senzing/senzingapi-runtime.git#${SENZING_DOCKER_IMAGE_VERSION_SENZINGAPI_RUNTIME}

    ```

## Add Docker instructions to existing Dockerfile

This technique is to copy, paste, and modify Docker instructions into the "original"
Dockerfile to install Senzing.

1. Using the `senzing/senzingapi-runtime`
   [Dockerfile](https://github.com/Senzing/senzingapi-runtime/blob/main/Dockerfile) as a guide,
   copy the Docker instructions into your `Dockerfile`

1. The following environment variable are important:
   - `LD_LIBRARY_PATH`

## Build Senzing images upon custom base image

1. List the Github repository, DockerHub repository, version tag, and user for each Docker image and their
   [corresponding environment variable name](https://github.com/Senzing/knowledge-base/blob/main/lists/docker-versions-stable.sh).

   Format: `GitHub repository`;`DockerHub repository`;`tag`;`user` where `user` defaults to `1001`.

   Example:

    ```console
    export BASE_IMAGES=( \
      "docker-senzing-console;senzing/senzing-console;${SENZING_DOCKER_IMAGE_VERSION_SENZING_CONSOLE:-latest}" \
      "docker-sshd;senzing/sshd;${SENZING_DOCKER_IMAGE_VERSION_SSHD:-latest};0" \
      "docker-xterm;senzing/xterm;${SENZING_DOCKER_IMAGE_VERSION_XTERM:-latest}" \
      "entity-search-web-app-console;senzing/entity-search-web-app-console;${SENZING_DOCKER_IMAGE_VERSION_ENTITY_SEARCH_WEB_APP_CONSOLE:-latest}" \
      "redoer;senzing/redoer;${SENZING_DOCKER_IMAGE_VERSION_REDOER:-latest};1001" \
      "senzing-api-server;senzing/senzing-api-server;${SENZING_DOCKER_IMAGE_VERSION_SENZING_API_SERVER:-latest}" \
      "senzingapi-tools;senzing/senzingapi-tools;${SENZING_DOCKER_IMAGE_VERSION_SENZINGAPI_TOOLS:-latest}" \
      "stream-loader;senzing/stream-loader;${SENZING_DOCKER_IMAGE_VERSION_STREAM_LOADER:-latest}" \
    )

    ```

1. Build each of the Docker images in the list.
   Example:

    ```console
    for BASE_IMAGE in ${BASE_IMAGES[@]}; \
    do \
        IFS=";" read -r -a BASE_IMAGE_DATA <<< "${BASE_IMAGE}"
        BASE_IMAGE_REPOSITORY="${BASE_IMAGE_DATA[0]}"
        BASE_IMAGE_NAME="${BASE_IMAGE_DATA[1]}"
        BASE_IMAGE_VERSION="${BASE_IMAGE_DATA[2]}"
        BASE_IMAGE_USER="${BASE_IMAGE_DATA[3]}"
        docker build \
            --build-arg BASE_IMAGE=${DOCKER_IMAGE_TAG} \
            --build-arg USER=${BASE_IMAGE_USER:-1001} \
            --tag ${BASE_IMAGE_NAME}-${DOCKER_IMAGE_SUFFIX}:${BASE_IMAGE_VERSION} \
            https://github.com/Senzing/${BASE_IMAGE_REPOSITORY}.git#${BASE_IMAGE_VERSION}

    done

    ```

1. Needs a-fixin'.
   Example:

    ```console
    export BASE_IMAGES=( \
      "senzing-poc-server;senzing/senzing-poc-server;${SENZING_DOCKER_IMAGE_VERSION_SENZING_POC_SERVER:-latest}" \

    )
    ```
