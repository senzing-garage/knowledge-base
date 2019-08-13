# Environment variables

## List

### DATABASE_DATABASE

1. Synopsis:
   1. A component of [SENZING_DATABASE_URL](#senzing_database_url).
   1. The name of the database holding the Senzing G2 model.
1. Values:
    - Default: none
    - Usually: G2
1. Examples:
    1. Using `G2` as the database:

        ```console
        export DATABASE_DATABASE=G2
        ```

1. Where used:
    1. [docker-g2command](https://github.com/Senzing/docker-g2command),
       [docker-senzing-base](https://github.com/Senzing/docker-senzing-base),

### DATABASE_HOST

1. Synopsis:
   1. A component of [SENZING_DATABASE_URL](#senzing_database_url).
   1. A hostname, IP address, or symbolic name of the database service.
1. Examples:
    1. Using an IP address:

        ```console
        export DATABASE_HOST=10.1.1.17
        ```

1. Where used:
    1. [docker-g2command](https://github.com/Senzing/docker-g2command),
       [docker-senzing-base](https://github.com/Senzing/docker-senzing-base),

### DATABASE_PASSWORD

1. Synopsis:
   1. A component of [SENZING_DATABASE_URL](#senzing_database_url).
   1. The password for the database user, [DATABASE_USERNAME](#database_username).
1. Examples:
    1. Using password of "my;password!":

        ```console
        export DATABASE_PASSWORD="my;password!"
        ```

1. Where used:
    1. [docker-g2command](https://github.com/Senzing/docker-g2command),
       [docker-senzing-base](https://github.com/Senzing/docker-senzing-base),

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

1. Where used:
    1. [docker-g2command](https://github.com/Senzing/docker-g2command),
       [docker-senzing-base](https://github.com/Senzing/docker-senzing-base),

### DATABASE_PROTOCOL

1. Synopsis:
   1. A component of [SENZING_DATABASE_URL](#senzing_database_url).
   1. Identifies which type of database will be connected.
1. Values:
    - db2
    - mysql
    - postgresql
    - sqlite3
    - Default: none
1. Examples:

    1. PostgreSQL

        ```console
        export DATABASE_PROTOCOL=postgresql
        ```

1. Where used:
    1. [docker-g2command](https://github.com/Senzing/docker-g2command),
       [docker-senzing-base](https://github.com/Senzing/docker-senzing-base),

### DATABASE_USERNAME

1. Synopsis:
   1. A component of [SENZING_DATABASE_URL](#senzing_database_url).
   1. The name of a user authorized to work with the [DATABASE_DATABASE](#database_database) database.
1. Examples:
    1. Using user name of "my-user":

        ```console
        export DATABASE_USERNAME="my-user"
        ```

1. Where used:
    1. [docker-g2command](https://github.com/Senzing/docker-g2command),
       [docker-senzing-base](https://github.com/Senzing/docker-senzing-base),

### DB2_CUSTOM_DIR

1. Synopsis:
    1. The directory containing custom scripts for
       [ibmcom/db2](https://hub.docker.com/r/ibmcom/db2)
       docker container. Is mounted to `/var/custom`.
1. Values:
    1. Default: None
1. Where used:
    1. [docker-compose-demo](https://github.com/Senzing/docker-compose-demo),

### DB2_DB

1. Synopsis:
    1. The database schema name.
1. Values:
    1. Default: "G2"
1. Where used:
    1. [docker-compose-demo](https://github.com/Senzing/docker-compose-demo),

### DB2_PASSWORD

1. Synopsis:
    1. Password for the database "root" username.
1. Values:
    1. Default: "db2inst1"
1. Where used:
    1. [docker-compose-demo](https://github.com/Senzing/docker-compose-demo),

### DB2_STORAGE

1. Synopsis:
    1. Path on local system where the database files are stored.
1. Values:
    1. Default: "/storage/docker/senzing/docker-compose-stream-loader-kafka-db2"
1. Where used:
    1. [docker-compose-demo](https://github.com/Senzing/docker-compose-demo),

### DB2_USERNAME

1. Synopsis:
    1. The username for the the database "root" user.
1. Values:
    1. Default: "db2inst1"
1. Where used:
    1. [docker-compose-demo](https://github.com/Senzing/docker-compose-demo),

### DB2INST1_PASSWORD

1. Synopsis:
    1. The password for the "db2inst1" user name.
1. Values:
    1. Default: "db2inst1"
1. Where used:
    1. [docker-compose-demo](https://github.com/Senzing/docker-compose-demo),

### GIT_ACCOUNT

1. Where used:
    1. [docker-g2command](https://github.com/Senzing/docker-g2command),
       [docker-senzing-base](https://github.com/Senzing/docker-senzing-base),
       [docker-yum](https://github.com/Senzing/docker-yum),
       [docker-yumdownloader](https://github.com/Senzing/docker-yumdownloader),

### GIT_ACCOUNT_DIR

1. Where used:
    1. [docker-g2command](https://github.com/Senzing/docker-g2command),
       [docker-senzing-base](https://github.com/Senzing/docker-senzing-base),
       [docker-yum](https://github.com/Senzing/docker-yum),
       [docker-yumdownloader](https://github.com/Senzing/docker-yumdownloader),

### GIT_REPOSITORY

1. Where used:
    1. [docker-g2command](https://github.com/Senzing/docker-g2command),
       [docker-senzing-base](https://github.com/Senzing/docker-senzing-base),
       [docker-yum](https://github.com/Senzing/docker-yum),
       [docker-yumdownloader](https://github.com/Senzing/docker-yumdownloader),

### GIT_REPOSITORY_DIR

1. Where used:
    1. [docker-g2command](https://github.com/Senzing/docker-g2command),
       [docker-senzing-base](https://github.com/Senzing/docker-senzing-base),
       [docker-yum](https://github.com/Senzing/docker-yum),
       [docker-yumdownloader](https://github.com/Senzing/docker-yumdownloader),

### MYSQL_DATABASE

1. Synopsis:
    1. The database schema name.
1. Values:
    1. Default: "G2"
1. Where used:
    1. [docker-compose-demo](https://github.com/Senzing/docker-compose-demo),

### MYSQL_PASSWORD

1. Synopsis:
    1. Password for [MYSQL_USERNAME](#mysql_username).
1. Values:
    1. Default: "g2"
1. Where used:
    1. [docker-compose-demo](https://github.com/Senzing/docker-compose-demo),

### MYSQL_ROOT_PASSWORD

1. Synopsis:
    1. The password for the the database "root" user name.
1. Values:
    1. Default: "root"
1. Where used:
    1. [docker-compose-demo](https://github.com/Senzing/docker-compose-demo),

### MYSQL_STORAGE

1. Synopsis:
    1. Path on local system where the database files are stored.
1. Values:
    1. Default: "/storage/docker/senzing/docker-compose-kafka-mysql/mysql"
1. Where used:
    1. [docker-compose-demo](https://github.com/Senzing/docker-compose-demo),

### MYSQL_USERNAME

1. Synopsis:
    1. Non-root MySQL user.
1. Values:
    1. Default: "g2"
1. Where used:
    1. [docker-compose-demo](https://github.com/Senzing/docker-compose-demo),

### POSTGRES_DB

1. Synopsis:
    1. The database schema name.
1. Values:
    1. Default: "G2"
1. Where used:
    1. [docker-compose-demo](https://github.com/Senzing/docker-compose-demo),

### POSTGRES_PASSWORD

1. Synopsis:
    1. The password for the the database "root" user name.
1. Values:
    1. Default: "postgres"
1. Where used:
    1. [docker-compose-demo](https://github.com/Senzing/docker-compose-demo),

### POSTGRES_USERNAME

1. Synopsis:
    1. The username for the the database "root" user name.
1. Values:
    1. Default: "postgres"
1. Where used:
    1. [docker-compose-demo](https://github.com/Senzing/docker-compose-demo),

### POSTGRES_STORAGE

1. Synopsis:
    1. Path on local system where the database files are stored.
1. Values:
    1. Default: "/storage/docker/senzing/docker-compose-kafka-postgres/postgres"
1. Where used:
    1. [docker-compose-demo](https://github.com/Senzing/docker-compose-demo),

### SENZING_ACCEPT_EULA

1. Synopsis:
    1. This is your acceptance of the End User License Agreement (EULA).
       The EULA is located at
       [https://senzing.com/end-user-license-agreement](https://senzing.com/end-user-license-agreement/).
1. Values:
    1. If you accept the Senzing End User Licence Agreement (EULA),
       the value is "I_ACCEPT_THE_SENZING_EULA"
1. Where used:
    1. [docker-yum](https://github.com/Senzing/docker-yum),

### SENZING_CONFIG_PATH

1. Where used:
    1. [resolver](https://github.com/Senzing/resolver),

### SENZING_DATA_DIR

1. Where used:
    1. [docker-yum](https://github.com/Senzing/docker-yum),

### SENZING_DATA_SOURCE

1. Synopsis:
    1. Default "DATA_SOURCE" value for incoming records.
1. Values:
    1. Default: none
1. Where used:
    1. [resolver](https://github.com/Senzing/resolver),
       [stream-loader](https://github.com/Senzing/stream-loader),

### SENZING_DATA_VERSION_DIR

1. Synopsis:
    1. Path on the local system where Senzing *data/nn.nnn.nnn* directory is located.
       It differs from the value of the
       [SENZING_DATA_DIR](#senzing_data_dir)
       environment variable
       used in [installing Senzing](https://github.com/Senzing/docker-yum#volumes)
       because it includes the version of the data in the path.
       This directory contains immutable data files used by Senzing G2.
1. Values:
    1. Default: none
    1. Usually set to `/opt/senzing/data/1.0.0`
1. Where used:
    1. [docker-g2command](https://github.com/Senzing/docker-g2command),
       [docker-senzing-base](https://github.com/Senzing/docker-senzing-base),
       [stream-loader](https://github.com/Senzing/stream-loader),

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
    1. [docker-g2command](https://github.com/Senzing/docker-g2command),
       [docker-senzing-base](https://github.com/Senzing/docker-senzing-base),
       [resolver](https://github.com/Senzing/resolver),
       [stream-loader](https://github.com/Senzing/stream-loader),

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
    1. [docker-g2command](https://github.com/Senzing/docker-g2command),
       [docker-senzing-base](https://github.com/Senzing/docker-senzing-base),
       [resolver](https://github.com/Senzing/resolver),
       [stream-loader](https://github.com/Senzing/stream-loader),

### SENZING_DIR

1. Deprecated.

### SENZING_DOCKER_LAUNCHED

1. Where used:
    1. [docker-init-container](https://github.com/Senzing/docker-init-container),

### SENZING_DOWNLOAD_DIR

1. Synopsis:
    1. Directory on local system where a download will be placed.
1. Examples:
    1. Download to `/tmp/my-downloads`

        ```console
        export SENZING_DOWNLOAD_DIR=/tmp/my-downloads
        ```

1. Where used:
    1. [docker-yumdownloader](https://github.com/Senzing/docker-yumdownloader),

### SENZING_ENTITY_TYPE

1. Synopsis:
    1. Default "ENTITY_TYPE" value for incoming records.
1. Values:
    1. Default: none
1. Where used:
    1. [resolver](https://github.com/Senzing/resolver),
       [stream-loader](https://github.com/Senzing/stream-loader),

### SENZING_ETC_DIR

1. Synopsis:
    1. Path on the local system where Senzing *etc* directory is located.
       This directory contains Senzing configuration templates and files.
1. Values:
    1. Default: none
    1. Usually set to `/etc/opt/senzing`
1. Where used:
    1. [docker-g2command](https://github.com/Senzing/docker-g2command),
       [docker-senzing-base](https://github.com/Senzing/docker-senzing-base),
       [docker-yum](https://github.com/Senzing/docker-yum),
       [stream-loader](https://github.com/Senzing/stream-loader),

### SENZING_G2_DIR

1. Synopsis:
    1. Path on the local system where Senzing *g2* directory is located.
       This directory contains Senzing G2 code.
1. Values:
    1. Default: none
    1. Usually set to `/opt/senzing/g2`
1. Where used:
    1. [docker-g2command](https://github.com/Senzing/docker-g2command),
       [docker-senzing-base](https://github.com/Senzing/docker-senzing-base),
       [docker-yum](https://github.com/Senzing/docker-yum),
       [stream-loader](https://github.com/Senzing/stream-loader),

### SENZING_GID

1. Where used:
    1. [docker-init-container](https://github.com/Senzing/docker-init-container),

### SENZING_HOST

1. Where used:
    1. [resolver](https://github.com/Senzing/resolver),

### SENZING_IBM_DIR

1. Synopsis:
    1. Path on the local system where the `/opt/IBM` code resides.
       For instance, the Db2 client driver configuration would be located at
       `${SENZING_IBM_DIR}/db2/clidriver/cfg/db2dsdriver.cfg`
1. Values:
    1. Default: none
    1. Usually set to `/opt/IBM`
1. Where used:
    1. [docker-db2-driver-installer](https://github.com/Senzing/docker-db2-driver-installer),

### SENZING_INIT_CONTAINER_SLEEP

1. Synopsis:
    1. Time to sleep, in seconds, before doing initialization
1. Values:
    1. Default: 0
1. Where used:
    1. [docker-init-container](https://github.com/Senzing/docker-init-container),

### SENZING_INPUT_FILE

1. Where used:
    1. [resolver](https://github.com/Senzing/resolver),

### SENZING_INPUT_URL

1. Synopsis:
    1. URL of source file.
1. Values:
    1. Default: none
1. Where used:
    1. [stream-loader](https://github.com/Senzing/stream-loader),

### SENZING_INTERNAL_DATABASE

1. Where used:
    1. [resolver](https://github.com/Senzing/resolver),

### SENZING_KAFKA_BOOTSTRAP_SERVER

1. Synopsis:
    1. Hostname and port of Kafka server.
1. Values:
    1. Default: localhost:9092
1. Where used:
    1. [stream-loader](https://github.com/Senzing/stream-loader),

### SENZING_KAFKA_GROUP

1. Synopsis:
    1. Kafka group.
1. Values:
    1. Default: "senzing-kafka-group"
1. Where used:
    1. [stream-loader](https://github.com/Senzing/stream-loader),

### SENZING_KAFKA_TOPIC

1. Synopsis:
    1. Kafka topic.
1. Values:
    1. Default: "senzing-kafka-topic"
1. Where used:
    1. [stream-loader](https://github.com/Senzing/stream-loader),

### SENZING_LOG_LEVEL

1. Synopsis:
    1. Level of logging
1. Values:
    1. notset
    1. debug
    1. info
    1. warning
    1. error
    1. critical
    1. Default: info

1. Where used:
    1. [docker-init-container](https://github.com/Senzing/docker-init-container),
       [stream-loader](https://github.com/Senzing/stream-loader),

### SENZING_MONITORING_PERIOD

1. Synopsis:
    1. Time, in seconds, between monitoring log records.
1. Values:
    1. Default: 300
1. Where used:
    1. [stream-loader](https://github.com/Senzing/stream-loader),

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

1. Where used:
    1. [docker-g2command](https://github.com/Senzing/docker-g2command),
       [docker-senzing-base](https://github.com/Senzing/docker-senzing-base),
       [resolver](https://github.com/Senzing/resolver),

### SENZING_OUTPUT_FILE

1. Where used:
    1. [resolver](https://github.com/Senzing/resolver),

### SENZING_PORT

1. Where used:
    1. [resolver](https://github.com/Senzing/resolver),

### SENZING_PROCESSES

1. Synopsis:
    1. Number of processes to allocated for processing.
1. Values:
    1. Default: 1
1. Where used:
    1. [stream-loader](https://github.com/Senzing/stream-loader),

### SENZING_QUEUE_MAX

1. Synopsis:
    1. Maximum items for internal queue.
1. Values:
    1. Default: 10
1. Where used:
    1. [stream-loader](https://github.com/Senzing/stream-loader),

### SENZING_RABBITMQ_HOST

1. Synopsis:
    1. Host name of the RabbitMQ exchange.
1. Values:
    1. Default: "localhost:5672"
1. Where used:
    1. [stream-loader](https://github.com/Senzing/stream-loader),

### SENZING_RABBITMQ_PASSWORD

1. Synopsis:
    1. The password for the RabbitMQ queue.
1. Values:
    1. Default: "bitnami"
1. Where used:
    1. [stream-loader](https://github.com/Senzing/stream-loader),

### SENZING_RABBITMQ_QUEUE

1. Synopsis:
    1. Name of the RabbitMQ queue used for communication.
1. Values:
    1. Default: "senzing-rabbitmq-queue"
1. Where used:
    1. [stream-loader](https://github.com/Senzing/stream-loader),

### SENZING_RABBITMQ_USERNAME

1. Synopsis:
    1. The username for the RabbitMQ queue.
1. Values:
    1. Default: "user"
1. Where used:
    1. [stream-loader](https://github.com/Senzing/stream-loader),

### SENZING_RPM_DIR

1. Where used:
    1. [docker-yum](https://github.com/Senzing/docker-yum),

### SENZING_RPM_FILENAME

1. Where used:
    1. [docker-yum](https://github.com/Senzing/docker-yum),

### SENZING_SLEEP_TIME

1. Synopsis:
    1. Amount of time to sleep, in seconds, before running command.
1. Where used:
    1. [stream-loader](https://github.com/Senzing/stream-loader),

### SENZING_SLEEP_TIME_IN_SECONDS

1. Where used:
    1. [resolver](https://github.com/Senzing/resolver),

### SENZING_SUBCOMMAND

1. Synopsis:
    1. Identify the subcommand to be run.
1. Values:
    1. Run `program-name --help` for complete list.
1. Where used:
    1. [resolver](https://github.com/Senzing/resolver),
       [stream-loader](https://github.com/Senzing/stream-loader),

### SENZING_SUPPORT_PATH

1. Where used:
    1. [resolver](https://github.com/Senzing/resolver),

### SENZING_THREADS_PER_PROCESS

1. Synopsis:
    1. Number of threads per process to allocate for processing.
1. Values:
    1. Default: 4
1. Where used:
    1. [stream-loader](https://github.com/Senzing/stream-loader),

### SENZING_UID

1. Where used:
    1. [docker-init-container](https://github.com/Senzing/docker-init-container),

### SENZING_VAR_DIR

1. Synopsis:
    1. Path on the local system where Senzing *var* directory is located.
       This directory contains files that may mutate during execution.
1. Values:
    1. Default: none
    1. Usually set to `/var/opt/senzing`

1. Where used:
    1. [docker-g2command](https://github.com/Senzing/docker-g2command),
       [docker-senzing-base](https://github.com/Senzing/docker-senzing-base),
       [docker-yum](https://github.com/Senzing/docker-yum),
       [resolver](https://github.com/Senzing/resolver),
       [stream-loader](https://github.com/Senzing/stream-loader),

### SENZING_VOLUME

1. Where used:
    1. [docker-yum](https://github.com/Senzing/docker-yum),

### SENZING_WEBAPP_PORT

1. Synopsis:
    1. Port on localhost for Docker web application service.
1. Values:
    1. Default: none
1. Where used:
    1. [senzing-api-server](https://github.com/Senzing/senzing-api-server),
