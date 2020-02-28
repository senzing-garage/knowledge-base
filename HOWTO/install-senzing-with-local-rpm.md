# Install Senzing with local RPM

## Overview

Instructions for downloading Senzing RPMs and installing the
[Senzing API](../WHATIS/senzing-api.md)
from the downloaded RPMs.

### Contents

1. [Download RPM](#download-rpm)
1. [RPM filenames](#rpm-filenames)
1. [Volumes](#volumes)
1. [EULA](#eula)
1. [Install RPM](#install-rpm)

## Download RPM

1. :pencil2: Specify the directory where Senzing RPM should be downloaded on the local host.
   Example:

    ```console
    export SENZING_RPM_DIR=~/Downloads
    ```

1. Run the docker container.
   This will download the RPM files.
   Example:

    ```console
    sudo docker run \
      --rm \
      --volume ${SENZING_RPM_DIR}:/download \
      senzing/yumdownloader
    ```

## RPM filenames

1. Identify the downloaded filenames.
   Example:

    ```console
    cd ${SENZING_RPM_DIR}
    ls -latr
    ```

   The files should be near the bottom of the list.

1. :pencil2: Specify the Senzing RPM filenames.
   Example:

    ```console
    export SENZING_API_RPM=senzingapi-1.14.3-20059.x86_64.rpm
    export SENZING_DATA_RPM=senzingdata-v1-1.0.0-19287.x86_64.rpm
    ```

## Volumes

1. :pencil2: Specify the directory where Senzing should be installed on the local host.
   Example:

    ```console
    export SENZING_VOLUME=/opt/my-senzing
    ```

    1. :warning:
       **macOS** - [File sharing](https://github.com/Senzing/knowledge-base/blob/master/HOWTO/share-directories-with-docker.md#macos)
       must be enabled for `SENZING_VOLUME`.
    1. :warning:
       **Windows** - [File sharing](https://github.com/Senzing/knowledge-base/blob/master/HOWTO/share-directories-with-docker.md#windows)
       must be enabled for `SENZING_VOLUME`.

1. Identify directories on the local host.
   Example:

    ```console
    export SENZING_DATA_DIR=${SENZING_VOLUME}/data
    export SENZING_DATA_VERSION_DIR=${SENZING_DATA_DIR}/1.0.0
    export SENZING_ETC_DIR=${SENZING_VOLUME}/etc
    export SENZING_G2_DIR=${SENZING_VOLUME}/g2
    export SENZING_VAR_DIR=${SENZING_VOLUME}/var
    ```

## EULA

To use the Senzing code, you must agree to the End User License Agreement (EULA).

1. :warning: This step is intentionally tricky and not simply copy/paste.
   This ensures that you make a conscious effort to accept the EULA.
   Example:

    <code>export SENZING_ACCEPT_EULA="&lt;the value from [this link](https://github.com/Senzing/knowledge-base/blob/master/lists/environment-variables.md#senzing_accept_eula)&gt;"</code>

## Install RPM

1. :warning: Remove existing Senzing installation.
   If `SENZING_VOLUME` set incorrectly, this could be dangerous.
   So the first step is to verify the value of `SENZING_VOLUME`.
   Example:

    ```console
    echo ${SENZING_VOLUME}
    ```

    ```console
    sudo rm -rf ${SENZING_VOLUME}
    ```

1. Run docker container to install Senzing.
   Example:

    ```console
    sudo docker run \
      --env SENZING_ACCEPT_EULA=${SENZING_ACCEPT_EULA} \
      --rm \
      --volume ${SENZING_DATA_DIR}:/opt/senzing/data \
      --volume ${SENZING_G2_DIR}:/opt/senzing/g2 \
      --volume ${SENZING_ETC_DIR}:/etc/opt/senzing \
      --volume ${SENZING_VAR_DIR}:/var/opt/senzing \
      --volume ${SENZING_RPM_DIR}:/data \
      senzing/yum -y localinstall /data/${SENZING_API_RPM} /data/${SENZING_DATA_RPM}
    ```

1. Once complete, the Senzing API will be4 installed into `${SENZING_VOLUME}`.
