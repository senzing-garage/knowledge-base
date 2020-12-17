# How to update Senzing API

## Overview

Instructions for updating [Senzing API](../WHATIS/senzing-api.md).

### Contents

1. [Update](#update)
    1. [CentOS](#centos)
    1. [Ubuntu](#ubuntu)
    1. [macOS](#macos)
    1. [Windows](#windows)
    1. [Docker](#docker)
1. [Test](#test)
1. [Troubleshooting](#troubleshooting)
1. [References](#references)

## Update

### CentOS

### Ubuntu

### macOS

### Windows

### Docker

This method shows an "in-place" update of Senzing API.
To perform this method, no processes can be using the Senzing Engine nor Senzing SDK API
(i.e. they must be shut down).

1. :warning: To use the Senzing code, you must agree to the End User License Agreement (EULA).
   This step is intentionally tricky and not simply copy/paste.
   This ensures that you make a conscious effort to accept the EULA.
   Example:

    <pre>export SENZING_ACCEPT_EULA="&lt;the value from <a href="https://github.com/Senzing/knowledge-base/blob/master/lists/environment-variables.md#senzing_accept_eula">this link</a>&gt;"</pre>

1. :pencil2: Specify the directory where Senzing already exists on the local host.
   Example:

    ```console
    export SENZING_VOLUME=/opt/my-senzing
    ```

1. Identify directories on the local host.
   Example:

    ```console
    export SENZING_VOLUME_BACKUP=${SENZING_VOLUME}.$(date +%s)
    export SENZING_DATA_DIR=${SENZING_VOLUME}/data
    export SENZING_ETC_DIR=${SENZING_VOLUME}/etc
    export SENZING_G2_DIR=${SENZING_VOLUME}/g2
    export SENZING_VAR_DIR=${SENZING_VOLUME}/var
    ```

1. Backup existing version of Senzing.
   Example:

    ```console
    sudo mv ${SENZING_VOLUME} ${SENZING_VOLUME_BACKUP}
    ```

1. Install new version of Senzing.
   Example:

    ```console
    sudo docker run \
      --env SENZING_ACCEPT_EULA=${SENZING_ACCEPT_EULA} \
      --rm \
      --user 0 \
      --volume ${SENZING_DATA_DIR}:/opt/senzing/data \
      --volume ${SENZING_ETC_DIR}:/etc/opt/senzing \
      --volume ${SENZING_G2_DIR}:/opt/senzing/g2 \
      --volume ${SENZING_VAR_DIR}:/var/opt/senzing \
      senzing/yum:1.1.3
    ```

1. Copy configuration from old Senzing installation to new Senzing installation.
   Example:

    ```console
    sudo cp -R ${SENZING_VOLUME_BACKUP}/etc ${SENZING_VOLUME}
    sudo cp -R ${SENZING_VOLUME_BACKUP}/var ${SENZING_VOLUME}
    ```

## Test

1. Look at currently installed version of Senzing.
   Example:

    ```console
    cat ${SENZING_G2_DIR}/g2BuildVersion.json
    ```

   Example response:

    ```json
    {
        "PLATFORM": "Linux",
        "VERSION": "2.3.0",
        "BUILD_VERSION": "2.3.0.20342",
        "BUILD_NUMBER": "2020_12_07__02_00",
        "DATA_VERSION": "1.0.0"
    }
    ```

## Troubleshooting

## References
