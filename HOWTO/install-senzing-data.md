# Install Senzing data

## Overview

Instructions for installing the data portion of the
[Senzing API](../WHATIS/senzing-api.md).

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

1. :thinking: **Optional:**
   To use the Senzing code, you must agree to the End User License Agreement (EULA).
   The EULA is located at [https://senzing.com/end-user-license-agreement](https://senzing.com/end-user-license-agreement/).
   To agree to Senzing EULA in an automated fashion,
   set the `SENZING_ACCEPT_EULA` environment variable before running `yum install`.

    1. :warning: This step is intentionally tricky and not simply copy/paste.
       This ensures that you make a conscious effort to accept the EULA.
       See
       [SENZING_ACCEPT_EULA](https://github.com/Senzing/knowledge-base/blob/master/lists/environment-variables.md#senzing_accept_eula)
       for the correct value.
       Replace the double-quote character in the example with the correct value.
       The use of the double-quote character is intentional to prevent simple copy/paste.
       Example:

        ```console
        export SENZING_ACCEPT_EULA="
        ```

1. Install Senzing API.
   During this installation, you will be prompted to accept the Senzing End User License Agreement (EULA)
   The EULA is located at [https://senzing.com/end-user-license-agreement](https://senzing.com/end-user-license-agreement/).
   Example:

    ```console
    sudo yum -y install \
      SENZING_ACCEPT_EULA=${SENZING_ACCEPT_EULA} \
      senzingdata-v1
    ```

### Ubuntu

1. Install Senzing APT repository metadata.
   Example:

    ```console
    curl \
      --output ~/senzingrepo_1.0.0-1_amd64.deb \
      https://senzing-production-apt.s3.amazonaws.com/senzingrepo_1.0.0-1_amd64.deb

    sudo apt -y install ~/senzingrepo_1.0.0-1_amd64.deb
    sudo apt update
    ```

1. :thinking: **Optional:**
   To use the Senzing code, you must agree to the End User License Agreement (EULA).
   The EULA is located at [https://senzing.com/end-user-license-agreement](https://senzing.com/end-user-license-agreement/).
   To agree to Senzing EULA in an automated fashion,
   set the `SENZING_ACCEPT_EULA` environment variable before running `yum install`.

    1. :warning: This step is intentionally tricky and not simply copy/paste.
       This ensures that you make a conscious effort to accept the EULA.
       See
       [SENZING_ACCEPT_EULA](https://github.com/Senzing/knowledge-base/blob/master/lists/environment-variables.md#senzing_accept_eula)
       for the correct value.
       Replace the double-quote character in the example with the correct value.
       The use of the double-quote character is intentional to prevent simple copy/paste.
       Example:

        ```console
        export SENZING_ACCEPT_EULA="
        ```

1. Install Senzing API.
   During this installation, you will be prompted to accept the Senzing End User License Agreement (EULA)
   The EULA is located at [https://senzing.com/end-user-license-agreement](https://senzing.com/end-user-license-agreement/).
   Example:

    ```console
    sudo apt -y install senzingdata-v1
    ```

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
