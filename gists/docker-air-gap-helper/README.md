# How to copy Docker images to air-gapped environment

The following instructions show how to prepare a TGZ file containing
Docker images and a file to help loading docker images to a private Docker registry.

The instructions have 3 major steps:

1. On a non-air-gapped system, create a TGZ file.
1. Transfer the TGZ file from the non-air-gapped system to the air-gapped system.
1. On the air-gapped system, use the TGZ file to populate an local Docker repository
   and (optionally) populate a private Docker registry.

## Contents

1. [On non-air-gapped system](#on-non-air-gapped-system)
    1. [Package docker images](#package-docker-images)
    1. [Create docker-tag-and-push.sh file](#create-docker-tag-and-pushsh-file)
    1. [Create compressed file](#create-compressed-file)
1. [Transfer](#transfer)
1. [On air-gapped system](#on-air-gapped-system)
    1. [Identify file](#identify-file)
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

1. :pencil2: List Docker images to be packaged.
   Add or delete Docker images from the list.
   For extensive list, see
   [docker-image-names.sh](../../lists/docker-image-names.sh)
   Example:

    ```console
    export DOCKER_IMAGE_NAMES=(
        "senzing/senzingapi-runtime:${SENZING_DOCKER_IMAGE_VERSION_SENZINGAPI_RUNTIME:-latest}"
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

### Create docker-tag-and-push.sh file

1. Create `docker-tag-and-push.sh` that will be used to push images to private Docker registry accessible by air-gapped system.
   Example:

    ```console
    for DOCKER_IMAGE_NAME in ${DOCKER_IMAGE_NAMES[@]};
    do
      echo ""                                                                             >> ${SENZING_DOCKER_DIR}/docker-tag-and-push.sh
      echo "docker tag ${DOCKER_IMAGE_NAME} \${DOCKER_REGISTRY_URL}/${DOCKER_IMAGE_NAME}" >> ${SENZING_DOCKER_DIR}/docker-tag-and-push.sh
      echo "docker push \${DOCKER_REGISTRY_URL}/${DOCKER_IMAGE_NAME}"                     >> ${SENZING_DOCKER_DIR}/docker-tag-and-push.sh
      echo "docker rmi \${DOCKER_REGISTRY_URL}/${DOCKER_IMAGE_NAME}"                      >> ${SENZING_DOCKER_DIR}/docker-tag-and-push.sh
    done

    ```

### Create compressed file

1. Compress `.tar` file to make it smaller.
   Example:

    ```console
    tar \
        --create \
        --directory=${SENZING_DOCKER_DIR} \
        --file=${SENZING_DOCKER_DIR}/docker-images.tgz \
        --gzip \
        --verbose \
        docker-images.tar docker-tag-and-push.sh

    ```

## Transfer

1. Transfer the following files to the air-gapped system:
    1. ${SENZING_DOCKER_DIR}/docker-images.tgz

## On air-gapped system

The following instructions show how to populate a private registry in an air-gapped environment.

This method has been tested on Linux systems.

### Identify file

1. :pencil2: Specify the location of the `docker-images.tgz` file.
   Example:

    ```console
    export SENZING_DOCKER_IMAGES_TGZ=~/docker-images.tgz

    ```

### Extract file

1. :pencil2: Specify the output location for uncompressing the file.
   Example:

    ```console
    export SENZING_OUTPUT_DIR=~/my-senzing-output

    ```

1. Uncompress file.
   Example:

    ```console
    mkdir --parents ${SENZING_OUTPUT_DIR}
    tar \
        --directory=${SENZING_OUTPUT_DIR} \
        --extract \
        --file=${SENZING_DOCKER_IMAGES_TGZ} \
        --gzip \
        --verbose

    ```

### Load local Docker repository

This step will add the Docker images to the Docker repository on the local workstation.
The contents of the local Docker repository are seen via the `docker images` command.

1. Load Docker images onto local workstation.
   Example:

    ```console
    docker load --input ${SENZING_OUTPUT_DIR}/docker-images.tar

    ```

### Load private Docker registry

:thinking: **Optional:** This step is only needed if the Docker images
need to be added to a private Docker registry.
If working on a single workstation, this step is not necessary.

1. :pencil2: Identify the URL of the private Docker registry.
   Example:

    ```console
    export DOCKER_REGISTRY_URL=my.docker-registry.com:5000

    ```

1. :pencil2: Run `docker-tag-and-push.sh`
   Example:

    ```console
    ${SENZING_OUTPUT_DIR}/docker-tag-and-push.sh

    ```
