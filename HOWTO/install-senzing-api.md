# Install Senzing API

## Overview

Instructions for installing [Senzing API](../WHATIS/senzing-api.md).

### Contents

1. [Install](#install)
    1. [CentOS](#centos)
    1. [Ubuntu](#ubuntu)
    1. [macOS](#macos)
    1. [Windows](#windows)
    1. [Docker](#docker)
1. [Test](#test)
1. [Troubleshooting](#troubleshooting)
1. [References](#references)

## Install

### CentOS

1. Install Senzing YUM repository metadata.
   Example:

    ```console
    sudo yum -y install https://senzing-production-yum.s3.amazonaws.com/senzingrepo-1.0.0-1.x86_64.rpm
    ```

1. Install Senzing API.
   During this installation, you will be prompted to accept the Senzing End User License Agreement (EULA)
   The EULA is located at [https://senzing.com/end-user-license-agreement](https://senzing.com/end-user-license-agreement/).
   Example:

    ```console
    sudo yum -y install senzingapi
    ```

1. For automation:  To agree to Senzing EULA, set the following environment variable before running `yum install`.

    ```console
    export SENZING_ACCEPT_EULA=I_ACCEPT_THE_SENZING_EULA
    ```

### Ubuntu

### macOS

### Windows

### Docker

1. When using Docker, the platform-specific installations described above can be used.
   If platform specific installations are used, set the following variables with these values:

    ```console
    export SENZING_DATA_DIR=/opt/senzing/data
    export SENZING_G2_DIR=/opt/senzing/g2
    export SENZING_ETC_DIR=/etc/opt/senzing
    export SENZING_VAR_DIR=/var/opt/senzing
    ```

1. If using docker orchestration such as Kubernetes, OpenShift, Rancher, Docker Swarm, etc.
   which uses persistent volume claims (PVC),
   the recommendation is to use the [senzing/yum](https://github.com/Senzing/docker-yum) docker image
   to place files from the data, g2, etc, and var directories onto the PVC.

## Test

## Troubleshooting

## References
