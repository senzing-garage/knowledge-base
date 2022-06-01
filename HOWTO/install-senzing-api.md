# How to install Senzing API

## Overview

Instructions for installing
[Senzing API](../WHATIS/senzing-api.md).

### Contents

1. [Install](#install)
    1. [Ubuntu](#ubuntu)
    1. [CentOS](#centos)
    1. [macOS](#macos)
    1. [Windows](#windows)
    1. [Docker](#docker)
1. [Test](#test)
1. [Troubleshooting](#troubleshooting)
1. [References](#references)

## Install

### Ubuntu

1. Add required system packages.
   Example:

    ```console
    sudo apt install \
        apt-transport-https \
        curl
    ```

1. Install Senzing APT repository metadata.
   Example:

    ```console
    curl \
      --output ~/senzingrepo_1.0.0-1_amd64.deb \
      https://senzing-production-apt.s3.amazonaws.com/senzingrepo_1.0.0-1_amd64.deb

    sudo apt -y install ~/senzingrepo_1.0.0-1_amd64.deb
    sudo apt update
    rm  ~/senzingrepo_1.0.0-1_amd64.deb
    ```

1. :thinking: **Optional:**
   To use the Senzing code, you must agree to the End User License Agreement (EULA).

    1. :warning: This step is intentionally tricky and not simply copy/paste.
       This ensures that you make a conscious effort to accept the EULA.
       Example:

        <pre>export SENZING_ACCEPT_EULA="&lt;the value from <a href="https://github.com/Senzing/knowledge-base/blob/main/lists/environment-variables.md#senzing_accept_eula">this link</a>&gt;"</pre>

1. Install Senzing API.
   If `SENZING_ACCEPT_EULA` environment variable is not set,
   you will be prompted to accept the Senzing End User License Agreement (EULA)
   The EULA is located at [https://senzing.com/end-user-license-agreement](https://senzing.com/end-user-license-agreement/).
   Example:

    ```console
    sudo --preserve-env apt -y install senzingapi
    ```

### CentOS

For installation on Red Hat, CentOS, openSuse and
[others](https://en.wikipedia.org/wiki/List_of_Linux_distributions#RPM-based).

1. Install Senzing YUM repository metadata.
   Example:

    ```console
    sudo yum -y install https://senzing-production-yum.s3.amazonaws.com/senzingrepo-1.0.0-1.x86_64.rpm
    ```

1. :thinking: **Optional:**
   To use the Senzing code, you must agree to the End User License Agreement (EULA).

    1. :warning: This step is intentionally tricky and not simply copy/paste.
       This ensures that you make a conscious effort to accept the EULA.
       Example:

        <pre>export SENZING_ACCEPT_EULA="&lt;the value from <a href="https://github.com/Senzing/knowledge-base/blob/main/lists/environment-variables.md#senzing_accept_eula">this link</a>&gt;"</pre>

1. Install Senzing API.
   If `SENZING_ACCEPT_EULA` environment variable is not set,
   you will be prompted to accept the Senzing End User License Agreement (EULA)
   The EULA is located at [https://senzing.com/end-user-license-agreement](https://senzing.com/end-user-license-agreement/).
   Example:

    ```console
    sudo --preserve-env yum -y install senzingapi
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
