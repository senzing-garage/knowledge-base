# How to use docker with system install

## Overview

A Senzing system installation is done with `apt` or `yum` as describe in
[install Senzing API](https://github.com/Senzing/knowledge-base/blob/master/HOWTO/install-senzing-api.md).

The Senzing system installation follows the [Linux File Hierarchy Standard](https://refspecs.linuxfoundation.org/FHS_3.0/fhs-3.0.pdf).

- Senzing static files are located in:
  - `/opt/senzing/data`
  - `/opt/senzing/g2`
- Senzing system configuration files are located in:
  - `/etc/opt/senzing`
- Senzing system variable files are located in:
  - `/var/opt/senzing`

The following shows how to use docker containers with a Senzing system installation.

### Contents

1. [Set environment variables](#set-environment-variables)
1. [Run docker container](#run-docker-container)

## Set environment variables

1. Environment variable definitions:

- **[SENZING_DATA_VERSION_DIR](https://github.com/Senzing/knowledge-base/blob/master/lists/environment-variables.md#senzing_data_version_dir)**
- **[SENZING_ETC_DIR](https://github.com/Senzing/knowledge-base/blob/master/lists/environment-variables.md#senzing_etc_dir)**
- **[SENZING_G2_DIR](https://github.com/Senzing/knowledge-base/blob/master/lists/environment-variables.md#senzing_g2_dir)**
- **[SENZING_VAR_DIR](https://github.com/Senzing/knowledge-base/blob/master/lists/environment-variables.md#senzing_var_dir)**

1. Set environment variables for docker containers.
   The values reflect a Senzing system installation.
   Example:

    ```console
    export SENZING_DATA_VERSION_DIR=/opt/senzing/data/1.0.0
    export SENZING_ETC_DIR=/etc/opt/senzing
    export SENZING_G2_DIR=/opt/senzing/g2
    export SENZING_VAR_DIR=/var/opt/senzing
    ```

## Run docker container

The following is an example of how to mount volumes from the host system containing the Senzing system install onto the docker container
using the `--volume` parameters.

1. Run docker container.
   Example:

    ```console
    sudo docker run \
      :
      --volume ${SENZING_DATA_VERSION_DIR}:/opt/senzing/data \
      --volume ${SENZING_ETC_DIR}:/etc/opt/senzing \
      --volume ${SENZING_G2_DIR}:/opt/senzing/g2 \
      --volume ${SENZING_VAR_DIR}:/var/opt/senzing \
      :
      senzing/xxxxx
    ```
