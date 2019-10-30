# Migrate Senzing using Docker

## Contents

1. [Preparation](#preparation)
    1. [Docker network](#docker-network)
1. [Migrations](#migrations)
    1. [Migrate 1.11.0 to 1.12.0](#migrate-1110-to-1120)
    1. [Migrate 1.12.0 to 1.13.0](#migrate-1120-to-1130)

## Preparation

### Docker network

:thinking: **Optional:**  Use if docker container is part of a docker network.

1. List docker networks.
   Example:

    ```console
    sudo docker network ls
    ```

1. :pencil2: Specify docker network.
   Choose value from NAME column of `docker network ls`.
   Example:

    ```console
    export SENZING_NETWORK=*nameofthe_network*
    ```

1. Construct parameter for `docker run`.
   Example:

    ```console
    export SENZING_NETWORK_PARAMETER="--net ${SENZING_NETWORK}"
    ```

## Migrations

### Migrate 1.11.0 to 1.12.0

#### Copy 1.11.0 to 1.12.0 configuration

1. Create a docker container running an "old" Senzing installation.
   Perform the following instructions in a new terminal window.
    1. :pencil2: Identify location of "old" Senzing installation.
       Example:

        ```console
        export SENZING_DATA_VERSION_DIR=/opt/my-senzing-1.11.0/data/1.0.0
        export SENZING_ETC_DIR=/opt/my-senzing-1.11.0/etc
        export SENZING_G2_DIR=/opt/my-senzing-1.11.0/g2
        export SENZING_VAR_DIR=/opt/my-senzing-1.11.0/var
        ```

    1. Run a docker container pointing to "old" Senzing installation.
       Example:

        ```console
        sudo docker run \
          --interactive \
          --name senzing-1.11.0 \
          --rm \
          --tty \
          --volume ${SENZING_DATA_VERSION_DIR}:/opt/senzing/data \
          --volume ${SENZING_ETC_DIR}:/etc/opt/senzing \
          --volume ${SENZING_G2_DIR}:/opt/senzing/g2 \
          --volume ${SENZING_VAR_DIR}:/var/opt/senzing \
          senzing/senzing-debug
        ```

1. Create a docker container running a "new" Senzing installation.
   Perform the following instructions in a new terminal window.
    1. :pencil2: Identify location of "new" Senzing installation.
       Example:

        ```console
        export SENZING_DATA_VERSION_DIR=/opt/my-senzing-1.12.0/data/1.0.0
        export SENZING_ETC_DIR=/opt/my-senzing-1.12.0/etc
        export SENZING_G2_DIR=/opt/my-senzing-1.12.0/g2
        export SENZING_VAR_DIR=/opt/my-senzing-1.12.0/var
        ```

    1. Run a docker container pointing to "new" Senzing installation.
       Example:

        ```console
        sudo docker run \
          --interactive \
          --name senzing-1.12.0 \
          --rm \
          --tty \
          --volume ${SENZING_DATA_VERSION_DIR}:/opt/senzing/data \
          --volume ${SENZING_ETC_DIR}:/etc/opt/senzing \
          --volume ${SENZING_G2_DIR}:/opt/senzing/g2 \
          --volume ${SENZING_VAR_DIR}:/var/opt/senzing \
          senzing/senzing-debug
        ```

1. Copy files from "old" to "new" Senzing installations.
   Perform the following instructions in a new terminal window.
    1. Make a temporary directory to hold files to be copied.
       Example:

        ```console
        export DOCKER_TMP_COPY_DIR=/tmp/docker-copy-$(date +%s)
        mkdir ${DOCKER_TMP_COPY_DIR}
        ```

    1. Copy files from one docker container to another via temporary directory.
       Example:

        ```console
        docker cp senzing-1.11.0:/etc/opt/senzing/. ${DOCKER_TMP_COPY_DIR}
        docker cp ${DOCKER_TMP_COPY_DIR}/. senzing-1.12.0:/etc/opt/senzing
        ```

#### Update Senzing configuration to 1.12.0

1. Perform G2ConfigTool operations.
   Perform the following instructions in a new terminal window.
    1. :pencil2: Identify location of "new" Senzing installation.
       Example:

        ```console
        export SENZING_DATA_VERSION_DIR=/opt/my-senzing-1.12.0/data/1.0.0
        export SENZING_ETC_DIR=/opt/my-senzing-1.12.0/etc
        export SENZING_G2_DIR=/opt/my-senzing-1.12.0/g2
        export SENZING_VAR_DIR=/opt/my-senzing-1.12.0/var
        ```

    1. Perform updates in `g2core-config-upgrade-1.11-to-1.11.2.gtc`.
       Example:

        ```console
        sudo docker run \
          ${SENZING_NETWORK_PARAMETER} \
          --rm \
          --volume ${SENZING_DATA_VERSION_DIR}:/opt/senzing/data \
          --volume ${SENZING_ETC_DIR}:/etc/opt/senzing \
          --volume ${SENZING_G2_DIR}:/opt/senzing/g2 \
          --volume ${SENZING_VAR_DIR}:/var/opt/senzing \
          senzing/g2configtool \
            -c /etc/opt/senzing/G2Module.ini \
            -f /opt/senzing/g2/resources/config/g2core-config-upgrade-1.11-to-1.11.2.gtc
        ```

    1. Perform updates in `g2core-config-upgrade-1.11.2-to-1.12.gtc`.
       Example:

        ```console
        sudo docker run \
          ${SENZING_NETWORK_PARAMETER} \
          --rm \
          --volume ${SENZING_DATA_VERSION_DIR}:/opt/senzing/data \
          --volume ${SENZING_ETC_DIR}:/etc/opt/senzing \
          --volume ${SENZING_G2_DIR}:/opt/senzing/g2 \
          --volume ${SENZING_VAR_DIR}:/var/opt/senzing \
          senzing/g2configtool \
            -c /etc/opt/senzing/G2Module.ini \
            -f /opt/senzing/g2/resources/config/g2core-config-upgrade-1.11.2-to-1.12.gtc
        ```

### Migrate 1.12.0 to 1.13.0

#### Copy 1.12.0 to 1.13.0 configuration

1. Create a docker container running an "old" Senzing installation.
   Perform the following instructions in a new terminal window.
    1. :pencil2: Identify location of "old" Senzing installation.
       Example:

        ```console
        export SENZING_DATA_VERSION_DIR=/opt/my-senzing-1.12.0/data/1.0.0
        export SENZING_ETC_DIR=/opt/my-senzing-1.12.0/etc
        export SENZING_G2_DIR=/opt/my-senzing-1.12.0/g2
        export SENZING_VAR_DIR=/opt/my-senzing-1.12.0/var
        ```

    1. Run a docker container pointing to "old" Senzing installation.
       Example:

        ```console
        sudo docker run \
          --interactive \
          --name senzing-1.12.0 \
          --rm \
          --tty \
          --volume ${SENZING_DATA_VERSION_DIR}:/opt/senzing/data \
          --volume ${SENZING_ETC_DIR}:/etc/opt/senzing \
          --volume ${SENZING_G2_DIR}:/opt/senzing/g2 \
          --volume ${SENZING_VAR_DIR}:/var/opt/senzing \
          senzing/senzing-debug
        ```

1. Create a docker container running a "new" Senzing installation.
   Perform the following instructions in a new terminal window.
    1. :pencil2: Identify location of "new" Senzing installation.
       Example:

        ```console
        export SENZING_DATA_VERSION_DIR=/opt/my-senzing-1.13.0/data/1.0.0
        export SENZING_ETC_DIR=/opt/my-senzing-1.13.0/etc
        export SENZING_G2_DIR=/opt/my-senzing-1.13.0/g2
        export SENZING_VAR_DIR=/opt/my-senzing-1.13.0/var
        ```

    1. Run a docker container pointing to "new" Senzing installation.
       Example:

        ```console
        sudo docker run \
          --interactive \
          --name senzing-1.13.0 \
          --rm \
          --tty \
          --volume ${SENZING_DATA_VERSION_DIR}:/opt/senzing/data \
          --volume ${SENZING_ETC_DIR}:/etc/opt/senzing \
          --volume ${SENZING_G2_DIR}:/opt/senzing/g2 \
          --volume ${SENZING_VAR_DIR}:/var/opt/senzing \
          senzing/senzing-debug
        ```

1. Copy files from "old" to "new" Senzing installations.
   Perform the following instructions in a new terminal window.
    1. Make a temporary directory to hold files to be copied.
       Example:

        ```console
        export DOCKER_TMP_COPY_DIR=/tmp/docker-copy-$(date +%s)
        mkdir ${DOCKER_TMP_COPY_DIR}
        ```

    1. Copy files from one docker container to another via temporary directory.
       Example:

        ```console
        docker cp senzing-1.12.0:/etc/opt/senzing/. ${DOCKER_TMP_COPY_DIR}
        docker cp ${DOCKER_TMP_COPY_DIR}/. senzing-1.13.0:/etc/opt/senzing
        ```

#### Update Senzing configuration to 1.13.0

1. List docker networks.
   Example:

    ```console
    sudo docker network ls
    ```

1. :pencil2: Specify docker network.
   Choose value from NAME column of `docker network ls`.
   Example:

    ```console
    export SENZING_NETWORK=*nameofthe_network*
    ```

1. Construct parameter for `docker run`.
   Example:

    ```console
    export SENZING_NETWORK_PARAMETER="--net ${SENZING_NETWORK}"
    ```

1. Perform G2ConfigTool operations.
   Perform the following instructions in a new terminal window.
    1. :pencil2: Identify location of "new" Senzing installation.
       Example:

        ```console
        export SENZING_DATA_VERSION_DIR=/opt/my-senzing-1.13.0/data/1.0.0
        export SENZING_ETC_DIR=/opt/my-senzing-1.13.0/etc
        export SENZING_G2_DIR=/opt/my-senzing-1.13.0/g2
        export SENZING_VAR_DIR=/opt/my-senzing-1.13.0/var
        ```

    1. Perform updates in `g2core-config-upgrade-1.12-to-1.13.gtc`.
       Example:

        ```console
        sudo docker run \
          ${SENZING_NETWORK_PARAMETER} \
          --rm \
          --volume ${SENZING_DATA_VERSION_DIR}:/opt/senzing/data \
          --volume ${SENZING_ETC_DIR}:/etc/opt/senzing \
          --volume ${SENZING_G2_DIR}:/opt/senzing/g2 \
          --volume ${SENZING_VAR_DIR}:/var/opt/senzing \
          senzing/g2configtool \
            -c /etc/opt/senzing/G2Module.ini \
            -f /opt/senzing/g2/resources/config/g2core-config-upgrade-1.12-to-1.13.gtc
        ```
