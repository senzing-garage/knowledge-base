# How to initialize Senzing with Docker

## Overview

Instructions for installing [Senzing API](../WHATIS/senzing-api.md)
using Docker containers.

### Contents

1. [Install Senzing](#install-senzing)
1. [Install database drivers](#install-database-drivers)
    1. [Postgresql](#postgresql)
    1. [MySQL](#mysql)
    1. [SQLite](#sqlite)
    1. [Db2](#db2)
    1. [MS SQL](#ms-sql)
1. [Configure](#configure)
1. [References](#references)

## Install Senzing

1. Install Senzing files using docker container.
    1. See [senzing/yum](https://github.com/Senzing/docker-yum) documentation.

## Install database drivers

**Note:**
Docker formations will install database drivers.
Example:

1. [docker-compose-demo](https://github.com/Senzing/docker-compose-demo)

If using a docker formation, the "Install database drivers" step may be skipped;
proceed to [Configure](#configure) step.

### Postgresql

1. No additional steps.

### MySQL

1. No additional steps.

### SQLite

1. No additional steps.

### Db2

1. Determine where to store IBM Db2 drivers.
   Examples:

    ```console
    export SENZING_IBM_DIR=~/opt-ibm
    ```

    ```console
    export SENZING_IBM_DIR=${SENZING_VOLUME}/opt-ibm
    ```

1. Run container.
   Example:

    ```console
    docker run \
      --rm \
      --volume ${SENZING_IBM_DIR}:/opt/IBM \
      senzing/db2-driver-installer:1.0.0
    ```

### MS SQL

1. Determine where to store MS SQL drivers.
   Examples:

    ```console
    export SENZING_OPT_MICROSOFT_DIR=~/opt-microsoft
    ```

    ```console
    export SENZING_OPT_MICROSOFT_DIR=${SENZING_VOLUME}/opt-microsoft
    ```

1. Run container.
   Example:

    ```console
    docker run \
      --env ACCEPT_EULA=Y \
      --rm \
      --volume ${SENZING_OPT_MICROSOFT_DIR}:/opt/microsoft \
      senzing/apt:1.0.0 -y install msodbcsql17
    ```

## Configure

1. Configure volumes and database.
    1. See [senzing/init-container](https://github.com/Senzing/docker-init-container) documentation.

## References
