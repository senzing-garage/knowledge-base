# air-gap-senzing-environment

The following instructions show how to prepare a TGZ file containing
[senzing-enviroment](https://github.com/Senzing/senzing-environment)
and its dependencies.
The TGZ file is used in an air-gapped environment
for adding Docker support to an existing Senzing project.

The instructions have 3 major steps:

1. On a non-air-gapped system, create a TGZ file.
1. Transfer the TGZ file from the non-air-gapped system to the air-gapped system.
1. On the air-gapped system, use the TGZ file to populate an local Docker repository,
   (optionally) populate a private Docker registry,
   and run a program to add Docker support to an existing Senzing project.

## Contents

1. [On non-air-gapped system](#on-non-air-gapped-system)
    1. [Download](#download)
    1. [Run](#run)
1. [Transfer](#transfer)
1. [On air-gapped system](#on-air-gapped-system)
    1. [Extract file](#extract-file)
    1. [Load local Docker repository](#load-local-docker-repository)
    1. [Load private Docker registry](#load-private-docker-registry)
    1. [Add Docker support to Senzing project](#add-docker-support-to-senzing-project)

## On non-air-gapped system

The goal of these steps is to produce a compressed file in `tgz` format
containing Docker images that can be installed on an air-gapped private Docker registry
and the `senzing-environment.py` program.

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
        export SENZING_AIR_GAP_SCRIPT=~/air-gap-senzing-environment.sh
        ```

    1. Download file.
       Example:

        ```console
        curl -X GET \
          --output ${SENZING_AIR_GAP_SCRIPT} \
          https://raw.githubusercontent.com/Senzing/knowledge-base/master/gists/air-gap-senzing-environment/air-gap-senzing-environment.sh
        ```

    1. Make file executable.
       Example:

        ```console
        chmod +x ${SENZING_AIR_GAP_SCRIPT}
        ```

### Run

1. Run `air-gap-senzing-environment.sh`.
   Example:

    ```console
    ${SENZING_AIR_GAP_SCRIPT}
    ```

1. This produces the following output:
    1. A directory in the form `~/air-gap-senzing-environment-nnnnnnnnnn` where `nnnnnnnnnn` is the Unix Timestamp of creation.
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
    export SENZING_AIR_GAP_TGZ=~/air-gap-senzing-environment-nnnnnnnnnn.tgz
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
    tar -zxvf ${SENZING_AIR_GAP_TGZ} --directory ${MY_OUTPUT_DIR}
    ```

### Load local Docker repository

This step will add the Docker images to the Docker repository on the local workstation.
The contents of the local Docker repository are seen via the `docker images` command.

1. View Docker images before loading the new images.
   Example:

    ```console
    sudo docker images | grep senzing
    ```

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

1. Verify the new Docker images.
   Example:

    ```console
    sudo docker images | grep senzing
    ```

### Load private Docker registry

:thinking: **Optional:** This step is only needed if the Docker images
need to be added to a private Docker registry.
If working on a single workstation, this step is not necessary.

1. :pencil2: Make extracted directory the current working directory.
   Example:

    ```console
    cd ${MY_OUTPUT_DIR}/air-gap-senzing-environment-nnnnnnnnnn
    ```

1. :pencil2: Identify the URL of the private Docker registry.
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

Before installing Docker support on an air-gapped system
Senzing needs to be installed and a Senzing project needs to be created.
Instructions for this are at
[Install - Air Gapped Systems](https://senzing.zendesk.com/hc/en-us/articles/360039787373-Install-Air-Gapped-Systems)
and
[Quickstart Guide](https://senzing.zendesk.com/hc/en-us/articles/115002408867-Quickstart-Guide).

1. :pencil2: Specify the location of the Senzing project on the host system.
   Example:

    ```console
    export SENZING_PROJECT_DIR=~/senzing-project
    ```

1. Add Docker support to existing Senzing project.
   Example:

    ```console
    ${MY_OUTPUT_DIR}/senzing-environment.py add-docker-support --project-dir ${SENZING_PROJECT_DIR}
    ```
