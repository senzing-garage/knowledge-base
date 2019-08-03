# Environment variables

## List

### DATABASE_DATABASE

1. Synopsis:
   1. A component of [SENZING_DATABASE_URL](#senzing_database_url).
   1. The name of the database holding the Senzing G2 model.
1. Values:
    - Default: None.
    - Usually: G2
1. Examples:
    1. Using `G2` as the database:

        ```console
        export DATABASE_DATABASE=G2
        ```

### DATABASE_HOST

1. Synopsis:
   1. A component of [SENZING_DATABASE_URL](#senzing_database_url).
   1. A hostname, IP address, or symbolic name of the database service.
1. Examples:
    1. Using an IP address:

        ```console
        export DATABASE_HOST=10.1.1.17
        ```

### DATABASE_PASSWORD

1. Synopsis:
   1. A component of [SENZING_DATABASE_URL](#senzing_database_url).
   1. The password for the database user, [DATABASE_USERNAME](#database_username).
1. Examples:
    1. Using password of "my;password!":

        ```console
        export DATABASE_PASSWORD="my;password!"
        ```

### DATABASE_PORT

1. Synopsis:
   1. A component of [SENZING_DATABASE_URL](#senzing_database_url).
   1. The port on the machine offering the database service.
1. Values:
    - 50000 - db2 default
    - 3306 - mysql default
    - 5432 - postresql default
    - sqlite3 has no default as it is file-based.
    - Default: none
1. Examples:
    1. Using default port for postgresql:

        ```console
        export DATABASE_PORT=5432
        ```

### DATABASE_PROTOCOL

1. Synopsis:
   1. A component of [SENZING_DATABASE_URL](#senzing_database_url).
   1. Identifies which type of database will be connected.
1. Values:
    - db2
    - mysql
    - postgresql
    - sqlite3
    - Default: None.
1. Examples:

    1. PostgreSQL

        ```console
        export DATABASE_PROTOCOL=postgresql
        ```

### DATABASE_USERNAME

1. Synopsis:
   1. A component of [SENZING_DATABASE_URL](#senzing_database_url).
   1. The name of a user authorized to work with the [DATABASE_DATABASE](#database_database) database.
1. Examples:
    1. Using user name of "my-user":

        ```console
        export DATABASE_USERNAME="my-user"
        ```

### GIT_ACCOUNT

1. Where used:
    1. [docker-yum](https://github.com/Senzing/docker-yum)

### GIT_ACCOUNT_DIR

1. Where used:
    1. [docker-yum](https://github.com/Senzing/docker-yum)

### GIT_REPOSITORY

1. Where used:
    1. [docker-yum](https://github.com/Senzing/docker-yum)

### GIT_REPOSITORY_DIR

1. Where used:
    1. [docker-yum](https://github.com/Senzing/docker-yum)

### SENZING_ACCEPT_EULA

1. Synopsis:
    1. This is your acceptance of the End User License Agreement (EULA).
       The EULA is located at
       [https://senzing.com/end-user-license-agreement](https://senzing.com/end-user-license-agreement/).
1. Values:
    1. If you accept the Senzing End User Licence Agreement (EULA),
       the value is "I_ACCEPT_THE_SENZING_EULA"
1. Where used:
    1. [docker-yum](https://github.com/Senzing/docker-yum)

### SENZING_CONFIG_PATH

1. Where used:
    1. [resolver](https://github.com/Senzing/resolver)

### SENZING_DATA_DIR

1. Where used:
    1. [docker-yum](https://github.com/Senzing/docker-yum)

### SENZING_DATA_VERSION_DIR

1. Where used:
    1. [docker-senzing-base](https://github.com/Senzing/docker-senzing-base)

### SENZING_DATA_SOURCE

1. Where used:
    1. [resolver](https://github.com/Senzing/resolver)

### SENZING_DATABASE_URL

1. Synopsis:
    1. Database URI in the form:

        [DATABASE_PROTOCOL](#database_protocol)://[DATABASE_USERNAME](#database_username):[DATABASE_PASSWORD](#database_password)@[DATABASE_HOST](#database_host):[DATABASE_PORT](#database_port)/[DATABASE_DATABASE](#database_database).
1. Values:
    - Default: Use the internal SQLite database.
1. Examples:
    1. MySQL

        ```console
        export SENZING_DATABASE_URL=mysql://user:password@my.example.com:3306/G2
        ```

    1. PostgreSQL

        ```console
        export SENZING_DATABASE_URL=postgresql://user:password@my.example.com:5432/G2
        ```

    1. Db2:

        ```console
        export SENZING_DATABASE_URL=db2://db2inst1:db2inst1@my.example.com:50000/G2
        ```

    1. SQLite

        ```console
        export SENZING_DATABASE_URL=sqlite3://na:na@/var/opt/senzing/sqlite/G2C.db
        ```

1. Where used:
    1. [resolver](https://github.com/Senzing/resolver)

### SENZING_DOWNLOAD_DIR

1. Synopsis:
    1. Directory on local system where a download will be placed.
1. Examples:
    1. Download to `/tmp/my-downloads`

        ```console
        export SENZING_DOWNLOAD_DIR=/tmp/my-downloads
        ```

1. Where used:
    1. [docker-yumdownloader](https://github.com/Senzing/docker-yumdownloader)

### SENZING_DEBUG

1. Synopsis:
    1. Enable debug information.
1. Values:
   - 0 = no debug
   - 1 = debug
   - Default: 0
1. Examples:
    1. Turn debugging on

        ```console
        export SENZING_DEBUG=1
        ```

1. Where used:
    1. [resolver](https://github.com/Senzing/resolver)

### SENZING_DIR

1. Deprecated.

### SENZING_DOCKER_LAUNCHED

1. Where used:
    1. [docker-init-container](https://github.com/Senzing/docker-init-container)

### SENZING_ENTITY_TYPE

1. Where used:
    1. [resolver](https://github.com/Senzing/resolver)

### SENZING_ETC_DIR

1. Where used:
    1. [docker-yum](https://github.com/Senzing/docker-yum)

### SENZING_G2_DIR

1. Where used:
    1. [docker-yum](https://github.com/Senzing/docker-yum)

### SENZING_GID

1. Where used:
    1. [docker-init-container](https://github.com/Senzing/docker-init-container)

### SENZING_HOST

1. Where used:
    1. [resolver](https://github.com/Senzing/resolver)

### SENZING_INPUT_FILE

1. Where used:
    1. [resolver](https://github.com/Senzing/resolver)

### SENZING_INTERNAL_DATABASE

1. Where used:
    1. [resolver](https://github.com/Senzing/resolver)

### SENZING_LOG_LEVEL

1. Where used:
    1. [docker-init-container](https://github.com/Senzing/docker-init-container)

### SENZING_NETWORK

1. Synopsis:
    1. Used in `docker-compose` formations to identify the docker network.
1. Examples:
    1. Search for network in docker-compose:

        ```console
        sudo docker network ls

        # Choose value from NAME column of docker network ls
        export SENZING_NETWORK=nameofthe_network
        ```

### SENZING_OUTPUT_FILE

1. Where used:
    1. [resolver](https://github.com/Senzing/resolver)

### SENZING_PORT

1. Where used:
    1. [resolver](https://github.com/Senzing/resolver)

### SENZING_RPM_DIR

1. Where used:
    1. [docker-yum](https://github.com/Senzing/docker-yum)

### SENZING_RPM_FILENAME

1. Where used:
    1. [docker-yum](https://github.com/Senzing/docker-yum)

### SENZING_SLEEP_TIME_IN_SECONDS

1. Where used:
    1. [resolver](https://github.com/Senzing/resolver)

### SENZING_SUBCOMMAND

1. Where used:
    1. [resolver](https://github.com/Senzing/resolver)

### SENZING_SUPPORT_PATH

1. Where used:
    1. [resolver](https://github.com/Senzing/resolver)

### SENZING_UID

1. Where used:
    1. [docker-init-container](https://github.com/Senzing/docker-init-container)

### SENZING_VAR_DIR

1. Where used:
    1. [docker-yum](https://github.com/Senzing/docker-yum)

### SENZING_VOLUME

1. Where used:
    1. [docker-yum](https://github.com/Senzing/docker-yum)
