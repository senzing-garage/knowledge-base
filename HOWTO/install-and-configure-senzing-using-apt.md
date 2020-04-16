# How to install and configure using apt

The following instructions are meant to be "copy-and-paste"
to install and configure Senzing Engine for repository projects.

This process requires the following files:

1. `${GIT_REPOSITORY_DIR}/src/apt-packages.txt`
1. `${GIT_REPOSITORY_DIR}/requirements.txt`

## Overview

1. [Prerequisite software](#prerequisite-software)
1. [Set environment variables](#set-environment-variables)
1. [Install](#install)

## Prerequisite software

The following software programs need to be installed:

1. [senzingdata](https://github.com/Senzing/knowledge-base/blob/master/HOWTO/install-senzing-data.md#ubuntu)
1. [senzingapi](https://github.com/Senzing/knowledge-base/blob/master/HOWTO/install-senzing-api.md#ubuntu)

## Set Environment variables

1. Synthesize environment variables.

    ```console
    export LD_LIBRARY_PATH=/opt/senzing/g2/lib:/opt/senzing/g2/lib/debian:$LD_LIBRARY_PATH
    export PYTHONPATH=/opt/senzing/g2/python
    ```

## Install

### APT installs

1. Run:

    ```console
    sudo xargs apt -y install < ${GIT_REPOSITORY_DIR}/src/apt-packages.txt
    ```

### PIP installs

1. Run:

    ```console
    sudo pip3 install -r ${GIT_REPOSITORY_DIR}/requirements.txt
    ```

## Configure

1. Get configuration tool.
   Example:

    ```console
    curl -X GET \
      --output ~/init-container.py \
      https://raw.githubusercontent.com/Senzing/docker-init-container/master/init-container.py
    ```

1. Make `init-container.py` executable.
   Example:

    ```console
    chmod +x ~/init-container.py
    ```

1. Configure Senzing for use.
   Example:

    ```console
    sudo \
      LD_LIBRARY_PATH=${LD_LIBRARY_PATH} \
      PYTHONPATH=${PYTHONPATH} \
      ~/init-container.py initialize
    ```

1. Permit `/var/opt/senzing` for use by current user.
   Example:

    ```console
    sudo chown $(id -u):$(id -g) -R /var/opt/senzing
    ```
