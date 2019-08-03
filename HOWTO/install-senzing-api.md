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

1. See [senzing/docker-yum](https://github.com/Senzing/docker-yum)
   for instructions on using a docker container to install Senzing files.
   **Note:** Although the docker container uses `yum`,
   it can be used on CentOS, Debian, macOS, and Windows systems.

## Test

## Troubleshooting

## References
