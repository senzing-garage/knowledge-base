# Create SENZING_DIR

## Overview

`SENZING_DIR` is a directory created by decompressing the `Senzing_API.tgz` file.

### Expectations 

- **Time:** Budget about 40 minutes, depending on your internet speed.
- **Space:** It requires about 3GB for installed package plus 1GB for download, a minimum of 5GB.

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

## Decompress Senzing_API.tgz

1. Set environment variables.

    ```console
    export SENZING_DIR=/opt/senzing
    export SENZING_FILE=/tmp/Senzing_API.tgz
    ```

### Linux

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

### macOS

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

## Change permissions
+
1. Set environment variables.

    ```console
    export SENZING_DIR=/opt/senzing
    ```

1. Change permissions.

    ```console
    sudo chmod -R 777 ${SENZING_DIR}/g2/sqldb
    sudo chmod -R 777 ${SENZING_DIR}/g2/python/g2config.json
    ```
