# docker-air-gap-helper

## Contents

1. [On non-air-gapped system](#on-non-air-gapped-system)
    1. [Download](#download)
    1. [Modify](#modify)
    1. [Run](#run)
1. [Transfer](#transfer)
1. [On air-gapped system](#on-air-gapped-system)
    1. [Extract file](#extract-file)
    1. [Load local docker repository](#load-local-docker-repository)
    1. [Load private docker registry](#load-private-docker-registry)

## On non-air-gapped system

The goal of these steps is to produce a compressed file of `tgz` format
containing docker images that can be installed on an air-gapped private docker registry.

The following steps are performed on an internet-connected system.
They will not work on an air-gapped system.

This method has been tested on Linux and macOS systems.

### Download

1. Get a local copy of
   [docker-air-gap-helper.sh](docker-air-gap-helper.sh).
   Example:

    1. :pencil2: Specify where to download file.
       Example:

        ```console
        export MY_DOCKER_AIR_GAP_HELPER=~/docker-air-gap-helper.sh
        ```

    1. Download file.
       Example:

        ```console
        curl -X GET \
          --output ${MY_DOCKER_AIR_GAP_HELPER} \
          https://raw.githubusercontent.com/Senzing/knowledge-base/master/gists/docker-air-gap-helper/docker-air-gap-helper.sh
        ```

    1. Make file executable.
       Example:

        ```console
        chmod +x ${MY_DOCKER_AIR_GAP_HELPER}
        ```

### Modify

1. Modify the `DOCKER_IMAGE_NAMES` list in the local copy of
   [docker-air-gap-helper.sh](docker-air-gap-helper.sh)
   (e.g. `MY_DOCKER_AIR_GAP_HELPER`)
   to add or delete docker images to be pulled from DockerHub (docker.io)
   and packaged to be transferred to the private registry.

### Run

1. Run `docker-air-gap-helper.sh`.
   Example:

    ```console
    ${MY_DOCKER_AIR_GAP_HELPER}
    ```

1. This produces the following output:
    1. A directory in the form `~/docker-air-gap-helper-nnnnnnnnnn.tgz` where `nnnnnnnnnn` is the Unix Timestamp of creation.
    1. A file in the form `~/docker-air-gap-helper-nnnnnnnnnn.tgz` which is a tar-gzipped version of the directory.

## Transfer

1. Transfer `~/docker-air-gap-helper-nnnnnnnnnn.tgz` to the air-gapped system.

## On air-gapped system

The following instructions show how to populate a private registry in an air-gapped environment.

This method has been tested on Linux systems.

### Extract file

1. :pencil2: Specify the location of the `docker-air-gap-helper-nnnnnnnnnn.tgz` file.
   Example:

    ```console
    export MY_DOCKER_AIR_GAP_HELPER_TGZ=~/docker-air-gap-helper-nnnnnnnnnn.tgz
    ```

1. :pencil2: Specify the output location for uncompressing the file.
   Example:

    ```console
    export MY_OUTPUT_DIR=~/my-output

    mkdir --parents ${MY_OUTPUT_DIR}
    ```

1. Uncompress file.
   Example:

    ```console
    tar -zxvf ${MY_DOCKER_AIR_GAP_HELPER_TGZ} --directory ${MY_OUTPUT_DIR}
    ```

### Load local docker repository

1. :pencil2: Make extracted directory the current working directory.
   Example:

    ```console
    cd ${MY_OUTPUT_DIR}/docker-air-gap-helper-nnnnnnnnnn
    ```

1. Run script to perform multiple
   [docker load](https://docs.docker.com/engine/reference/commandline/load/)
   commands.
   Example:

    ```console
    sudo ./docker-air-gap-load-repository.sh
    ```

### Load private docker registry

1. :pencil2: Make extracted directory the current working directory.
   Example:

    ```console
    cd ${MY_OUTPUT_DIR}/docker-air-gap-helper-nnnnnnnnnn
    ```

1. :pencil2: Identify the URL of the private docker registry.
   Example:

    ```console
    export DOCKER_REGISTRY_URL=my.docker-registry.com:5000
    ```

1. Run script to perform multiple
   [docker push](https://docs.docker.com/engine/reference/commandline/push/)
   commands.
   Example:

    ```console
    sudo --preserve-env ./docker-air-gap-load-registry.sh
    ```
