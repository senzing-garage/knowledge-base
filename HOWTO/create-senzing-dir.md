# Create SENZING_DIR

## Overview

`SENZING_DIR` is a directory created by decompressing the `Senzing_API.tgz` file.
It is usually located at `/opt/senzing`.

There are 2 methods of creating the `SENZING_DIR`:

1. [Using Docker](#using-docker)
1. [Manual download and extract](#manual-download-and-extract)

### Expectations

#### Time

Budget 30 minutes, depending on your network speed.

#### Space

This task requires a minimum of 5 GB free disk space.

- 1.5 GB for download
- 3.5 GB for installed package

## Using Docker

1. Accept license agreement for `store/senzing/senzing-package` docker image.
    1. Visit [HOWTO- Accept EULA](accept-eula.md#storesenzingsenzing-package-docker-image).

1. :pencil2: Set environment variables.
   Example:

    ```console
    export SENZING_DIR=/opt/senzing

    export SENZING_SUBCOMMAND=install
    export SENZING_DOCKER_TAG=1.9.19155
    ```

1. Populate `SENZING_DIR`.
   Example:

    ```console
    sudo mkdir -p ${SENZING_DIR}

    sudo docker run \
      --env SENZING_SUBCOMMAND="${SENZING_SUBCOMMAND}" \
      --rm \
      --volume ${SENZING_DIR}:/opt/senzing \
      store/senzing/senzing-package:${SENZING_DOCKER_TAG}
    ```

## Manual download and extract

### Downloading Senzing_API.tgz

#### Via web browser

1. Visit [senzing.com](https://senzing.com/).
1. Click on Pricing > [Pricing - Senzing API](https://senzing.com/pricing/pricing-senzing-api/).
1. In the "Try" pane, click on the "Download" button.
1. In the "Download Now" dialog box, click "Download Now" button.

#### Via curl command

1. :pencil2: Set environment variables.

    ```console
    export SENZING_FILE=/tmp/Senzing_API.tgz
    ```

1. Download [Senzing_API.tgz](https://s3.amazonaws.com/public-read-access/SenzingComDownloads/Senzing_API.tgz)

    ```console
    curl -X GET \
      --location \
      --output Senzing_API.tgz \
      https://senzing.com/APILatest
    ```

### Linux

1. :pencil2: Set environment variables.

    ```console
    export SENZING_DIR=/opt/senzing
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

### macOS

1. :pencil2: Set environment variables.

    ```console
    export SENZING_DIR=/opt/senzing
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

### Windows

1. Uncompress `Senzing_API.tgz` to `C:\opt\senzing`
