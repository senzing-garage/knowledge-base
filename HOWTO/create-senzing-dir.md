# Create SENZING_DIR

## Overview

`SENZING_DIR` is a directory created by decompressing the `Senzing_API.tgz` file.

### Expectations

#### Time

Budget 30 minutes, depending on your network speed.

#### Space

This task requires a minimum of 5 GB free disk space.

- 1.5 GB for download
- 3.5 GB for installed package

## Downloading Senzing_API.tgz

### Via web browser

1. Visit [senzing.com](https://senzing.com/).
1. Click on Pricing > [Pricing - Senzing API](https://senzing.com/pricing/pricing-senzing-api/).
1. In the "Try" pane, click on the "Download" button.
1. In the "Download Now" dialog box, click "Download Now" button.

### Via curl command

1. Download [Senzing_API.tgz](https://s3.amazonaws.com/public-read-access/SenzingComDownloads/Senzing_API.tgz)

    ```console
    curl -X GET \
      --output /tmp/Senzing_API.tgz \
      https://s3.amazonaws.com/public-read-access/SenzingComDownloads/Senzing_API.tgz
    ```

## Linux

1. Set environment variables.

    ```console
    export SENZING_DIR=/opt/senzing
    export SENZING_FILE=/tmp/Senzing_API.tgz
    ```

1. Extract [Senzing_API.tgz](https://s3.amazonaws.com/public-read-access/SenzingComDownloads/Senzing_API.tgz)
   to `${SENZING_DIR}`.

    ```console
    sudo mkdir -p ${SENZING_DIR}

    sudo tar \
      --extract \
      --owner=root \
      --group=root \
      --no-same-owner \
      --no-same-permissions \
      --directory=${SENZING_DIR} \
      --file=${SENZING_FILE}
    ```

1. Change permissions.

    ```console
    sudo chmod -R 777 ${SENZING_DIR}/g2/sqldb
    sudo chmod -R 777 ${SENZING_DIR}/g2/python/g2config.json
    ```

## macOS

1. Set environment variables.

    ```console
    export SENZING_DIR=/opt/senzing
    export SENZING_FILE=/tmp/Senzing_API.tgz
    ```

1. Extract [Senzing_API.tgz](https://s3.amazonaws.com/public-read-access/SenzingComDownloads/Senzing_API.tgz)
   to `${SENZING_DIR}`.

    ```console
    sudo mkdir -p ${SENZING_DIR}

    sudo tar \
      --extract \
      --no-same-owner \
      --no-same-permissions \
      --directory=${SENZING_DIR} \
      --file=${SENZING_FILE}
    ```

1. Change permissions.

    ```console
    sudo chmod -R 777 ${SENZING_DIR}/g2/sqldb
    sudo chmod -R 777 ${SENZING_DIR}/g2/python/g2config.json
    ```

## Windows

1. Uncompress `Senzing_API.tgz` to `C:\opt\senzing`
