# How to install docker image in an air-gapped environment

## Overview

The following steps show how to install the Senzing RPMs on a machine
that is not on the internet, (i.e. "air-gapped").

### Contents

1. [Download latest Senzing API](#download-latest-senzing-api)
1. [Transfer files to air-gapped system](#transfer-files-to-air-gapped-system)
1. [Install Senzing on air-gapped system](#install-senzing-on-air-gapped-system)

## Download latest Senzing API

On an internet-connected machine (i.e. not air-gapped), perform the following:

1. :pencil2: Specify a local directory to receive the downloaded files.
   Example:

    ```console
    export SENZING_RPM_DIR=~/Downloads
    ```

1. Download the Senzing RPMs.
   Example:

    ```console
    docker run \
      --rm \
      --volume ${SENZING_RPM_DIR}:/download \
      senzing/yumdownloader
    ```

## Transfer files to air-gapped system

1. Transfer the downloaded files from the local system to the air-gapped system:
    1. `senzingapi-M.m.P-nnnnn.x86_64.rpm`
    1. `senzingdata-v1-1.0.0-19287.x86_64.rpm`

## Install Senzing on air-gapped system

On the air-gapped system, perform the following:

1. To use the Senzing code, you must agree to the End User License Agreement (EULA).

    1. :warning: This step is intentionally tricky and not simply copy/paste.
       This ensures that you make a conscious effort to accept the EULA.
       Example:

    <pre>export SENZING_ACCEPT_EULA="&lt;the value from <a href="https://github.com/Senzing/knowledge-base/blob/master/lists/environment-variables.md#senzing_accept_eula">this link</a>&gt;"</pre>

1. :pencil2: Specify RPM files and the directory where they are located on the air-gapped system.
   Example:

    ```console
    export SENZING_RPM_DIR=~/Downloads
    export SENZING_API_RPM=senzingapi-2.3.0-20342.x86_64.rpm
    export SENZING_DATA_RPM=senzingdata-v1-1.0.0-19287.x86_64.rpm
    ```

1. :pencil2: Specify the directory on the air-gapped system where the RPMs are to be installed.
   Example:

    ```console
    export SENZING_VOLUME=/opt/my-senzing
    ```

1. Synthesize other variables.
   Example:

    ```console
    export SENZING_DATA_DIR=${SENZING_VOLUME}/data
    export SENZING_DATA_VERSION_DIR=${SENZING_DATA_DIR}/1.0.0
    export SENZING_ETC_DIR=${SENZING_VOLUME}/etc
    export SENZING_G2_DIR=${SENZING_VOLUME}/g2
    export SENZING_VAR_DIR=${SENZING_VOLUME}/var
    ```

1. Install RPMs on the air-gapped system.
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
