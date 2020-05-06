# air-gap-senzing-environment

The following instructions show how to prepare a TGZ file for use with
[senzing-enviroment](https://github.com/Senzing/senzing-environment)
in an air-gapped environment.

The method involves 3 steps:

1. On a non-air-gapped system, create a TGZ file.
1. Transfer the TGZ file from the non-air-gapped system to the air-gapped system.
1. Use the TGZ file on the air-gapped file to populate a docker repository,
   (optionally) populate a docker registry,
   and run a program to add Docker support to a Senzing project.

## Contents

1. [On non-air-gapped system](#on-non-air-gapped-system)
    1. [Download](#download)
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
   [air-gap-senzing-environment.sh](air-gap-senzing-environment.sh).
   Example:

    1. :pencil2: Specify where to download file.
       Example:

        ```console
        export MY_DOCKER_AIR_GAP_HELPER=~/air-gap-senzing-environment.sh
        ```

    1. Download file.
       Example:

        ```console
        curl -X GET \
          --output ${MY_DOCKER_AIR_GAP_HELPER} \
          https://raw.githubusercontent.com/Senzing/knowledge-base/master/gists/air-gap-senzing-environment/air-gap-senzing-environment.sh
        ```

    1. Make file executable.
       Example:

        ```console
        chmod +x ${MY_DOCKER_AIR_GAP_HELPER}
        ```

### Run

1. Run `air-gap-senzing-environment.sh`.
   Example:

    ```console
    ${MY_DOCKER_AIR_GAP_HELPER}
    ```

1. This produces the following output:
    1. A directory in the form `~/air-gap-senzing-environment-nnnnnnnnnn.tgz` where `nnnnnnnnnn` is the Unix Timestamp of creation.
    1. A file in the form `~/air-gap-senzing-environment-nnnnnnnnnn.tgz` which is a tar-gzipped version of the directory.

## Transfer

1. Transfer the `air-gap-senzing-environment-nnnnnnnnnn.tgz` file to the air-gapped system.

## On air-gapped system

The following instructions show how to populate a private registry in an air-gapped environment.

This method has been tested on Linux systems.

### Extract file

1. :pencil2: Specify the location of the `air-gap-senzing-environment-nnnnnnnnnn.tgz` file.
   Example:

    ```console
    export MY_DOCKER_AIR_GAP_HELPER_TGZ=~/air-gap-senzing-environment-nnnnnnnnnn.tgz
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

This step will add the docker images to the docker repository on the local workstation.
The contents of the local docker repository are seen via the `docker images` command.

1. :pencil2: Make extracted directory the current working directory.
   Example:

    ```console
    cd ${MY_OUTPUT_DIR}/air-gap-senzing-environment-nnnnnnnnnn
    ```

1. Run script to perform multiple
   [docker load](https://docs.docker.com/engine/reference/commandline/load/)
   commands.
   Example:

    ```console
    sudo ./docker-air-gap-load-repository.sh
    ```

1. Verify the new docker images.
   Example:

    ```console
    sudo docker images | grep senzing
    ```

### Load private docker registry

:thinking: **Optional:** This step is only needed if the docker images
need to be added to a private docker registry.
If working on a single workstation, this step is not necessary.

1. :pencil2: Make extracted directory the current working directory.
   Example:

    ```console
    cd ${MY_OUTPUT_DIR}/air-gap-senzing-environment-nnnnnnnnnn
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

### Add Docker support to Senzing project

1. :pencil2: Specify the location of the Senzing project on the host system.
   Example:

    ```console
    export SENZING_PROJECT_DIR=~/senzing-demo-project-1
    ```

1. Add Docker support to existing Senzing project.
   Example:

    ```console
    ${MY_OUTPUT_DIR}/senzing-environment.py add-docker-support --project-dir ${SENZING_PROJECT_DIR}
    ```
