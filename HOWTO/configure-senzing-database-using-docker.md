# How to configure Senzing database using Docker

## Overview

The following instructions show how to setup the Senzing database on various database products using the command line.
Alternatively, to set up the Senzing database using Docker, see
[How to configure Senzing database using Docker](configure-senzing-database-using-docker.md)

### Contents

1. [Db2](#db2)
1. [MS SQL](#ms-sql)
1. [MySQL](#mysql)
1. [PostgreSQL](#postgresql)

## Db2

## MS SQL

Configuring the Senzing database in MS SQL uses the
[sqlcmd Utility](https://docs.microsoft.com/en-us/sql/tools/sqlcmd-utility)
in a [mcr.microsoft.com/mssql-tools](https://hub.docker.com/_/microsoft-mssql-tools) docker image.

1. :pencil2: Identify the hostname of the database.
   **Tip:** Do not use `localhost` nor `127.0.0.1` as that assumes the database is inside the docker container.
   Example:

    ```console
    export MSSQL_HOSTNAME=mysql.example.com
    export MSSQL_SA_PASSWORD=Password
    export SENZING_G2_DIR=/opt/my-senzing/g2
    ```

1. Create database.
   Example:

    ```console
    docker run \
      --interactive \
      --name senzing-mssql-create-database \
      --rm \
      --tty \
      mcr.microsoft.com/mssql-tools \
        /opt/mssql-tools/bin/sqlcmd \
        -P ${MSSQL_SA_PASSWORD} \
        -Q "CREATE DATABASE G2" \
        -S ${MSSQL_HOSTNAME} \
        -U sa
    ```

1. Populate database.
   Example:

    ```console
    docker run \
      --interactive \
      --name senzing-mssql-create-senzing \
      --rm \
      --tty \
      --volume ${SENZING_G2_DIR}:/opt/senzing/g2 \
      mcr.microsoft.com/mssql-tools \
        /opt/mssql-tools/bin/sqlcmd \
        -d G2 \
        -e \
        -i /opt/senzing/g2/resources/schema/g2core-schema-mssql-create.sql \
        -o /dev/stdout \
        -P ${MSSQL_SA_PASSWORD} \
        -S ${MSSQL_HOSTNAME} \
        -U sa
    ```

## MySQL

## PostgreSQL
