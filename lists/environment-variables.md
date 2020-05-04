# Environment variables

## List

### ADMINER_DEFAULT_SERVER

1. Synopsis:
    1. The default hostname/ip-address of the database server.
    1. See [Adminer on DockerHub](https://hub.docker.com/_/adminer)
1. Where used:
    1. [docker-adminer](https://github.com/Senzing/docker-adminer),

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

### DB2_DIR

1. Synopsis:
    1. Path on local system where the database files are stored.
1. Values:
    1. Default: None.  Application dependent.
1. Where used:
    1. [docker-compose-demo](https://github.com/Senzing/docker-compose-demo),

### DB2_PASSWORD

1. Synopsis:
    1. Password for the database "root" username.
1. Values:
    1. Default: "db2inst1"
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

### DEMO_NAMESPACE

1. Synopsis:
    1. In a Kubernetes environment, a value used for the namespace.
1. Values:
    1. Example: "my-namespace"
1. Where used:
    1. [kubernetes-demo](https://github.com/Senzing/kubernetes-demo),

### DEMO_PREFIX

1. Synopsis:
    1. In a Kubernetes environment, a value prefixed used to object names.
1. Values:
    1. Example: "my"
1. Where used:
    1. [kubernetes-demo](https://github.com/Senzing/kubernetes-demo),

### DOCKER_APP

1. Synopsis:
    1. The docker app command, based on the type of installation (Stand-alone or Docker CLI plugin).
    1. Docker App [installation](https://github.com/docker/app#installation)
1. Values:
    1. "docker-app"
    1. "docker app"
    1. Default: None
1. Where used:
    1. [docker-app-demo](https://github.com/Senzing/docker-app-demo),

### DOCKER_APP_PARAMETERS_FILE

1. Synopsis:
    1. Location of file used in Docker App `--parameters-file` command-line option.
1. Values:
    1. Default: None
1. Where used:
    1. [docker-app-demo](https://github.com/Senzing/docker-app-demo),

### DOCKER_REGISTRY_SECRET

1. Synopsis:
    1. In a Kubernetes environment, the name of the Kubernetes Secret for accessing the public or local Docker registry.
1. Where used:
    1. [kubernetes-demo](https://github.com/Senzing/kubernetes-demo),

### DOCKER_REGISTRY_URL

1. Synopsis:
    1. URL of a public or local Docker registry.
1. Values:
    1. Example: "docker.io"
1. Where used:
    1. [kubernetes-demo](https://github.com/Senzing/kubernetes-demo),

### G2_LICENSE_PATH

1. Synopsis:
    1. Location of the `g2.lic` file on a local workstation
1. Examples:
    1. Using `Downloads` directory.

        ```console
        export G2_LICENSE_PATH="~/Downloads/g2.lic"
        ```

1. Where used:
    1. [docker-g2command](https://github.com/Senzing/docker-compose-demo),

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

### GITHUB_ACTION

1. See [GitHub Actions environment variables](https://help.github.com/en/actions/automating-your-workflow-with-github-actions/using-environment-variables#default-environment-variables).

### GITHUB_ACTIONS

1. See [GitHub Actions environment variables](https://help.github.com/en/actions/automating-your-workflow-with-github-actions/using-environment-variables#default-environment-variables).

### GITHUB_ACTOR

1. See [GitHub Actions environment variables](https://help.github.com/en/actions/automating-your-workflow-with-github-actions/using-environment-variables#default-environment-variables).

### GITHUB_BASE_REF

1. See [GitHub Actions environment variables](https://help.github.com/en/actions/automating-your-workflow-with-github-actions/using-environment-variables#default-environment-variables).

### GITHUB_EVENT_NAME

1. See [GitHub Actions environment variables](https://help.github.com/en/actions/automating-your-workflow-with-github-actions/using-environment-variables#default-environment-variables).

### GITHUB_EVENT_PATH

1. See [GitHub Actions environment variables](https://help.github.com/en/actions/automating-your-workflow-with-github-actions/using-environment-variables#default-environment-variables).

### GITHUB_HEAD_REF

1. See [GitHub Actions environment variables](https://help.github.com/en/actions/automating-your-workflow-with-github-actions/using-environment-variables#default-environment-variables).

### GITHUB_REF

1. See [GitHub Actions environment variables](https://help.github.com/en/actions/automating-your-workflow-with-github-actions/using-environment-variables#default-environment-variables).

### GITHUB_REPOSITORY

1. See [GitHub Actions environment variables](https://help.github.com/en/actions/automating-your-workflow-with-github-actions/using-environment-variables#default-environment-variables).

### GITHUB_SHA

1. See [GitHub Actions environment variables](https://help.github.com/en/actions/automating-your-workflow-with-github-actions/using-environment-variables#default-environment-variables).

### GITHUB_WORKFLOW

1. See [GitHub Actions environment variables](https://help.github.com/en/actions/automating-your-workflow-with-github-actions/using-environment-variables#default-environment-variables).

### GITHUB_WORKSPACE

1. See [GitHub Actions environment variables](https://help.github.com/en/actions/automating-your-workflow-with-github-actions/using-environment-variables#default-environment-variables).

### HELM_TLS

1. Synopsis:
    1. In a Kubernetes environment, a parameter for the `kubectl` command.
1. Examples:
    1. Setting parameter.

        ```console
        export HELM_TLS="--tls"
        ```

1. Where used:
    1. [ibm-openshift-guide](https://github.com/Senzing/ibm-openshift-guide),

### HELM_VALUES_DIR

1. Synopsis:
    1. In a Kubernetes environment, a directory holding files for use in the `helm --values` parameter.
1. Where used:
    1. [kubernetes-demo](https://github.com/Senzing/kubernetes-demo),

### JUPYTER_NOTEBOOKS_PORT

1. Synopsis:
    1. Port on localhost for [senzing/jupyter](https://github.com/Senzing/docker-jupyter).
    1. See [Port 9178](https://github.com/Senzing/knowledge-base/blob/master/lists/ports-used-in-demonstrations.md#9178)
1. Values:
    1. Default: 9178
1. Where used:
    1. [docker-juptyer](https://github.com/Senzing/docker-jupyter),

### JUPYTER_NOTEBOOKS_SHARED_DIR

1. Synopsis:
    1. A directory on the localhost that is shared with the docker container as Jupyter's `shared` folder.
1. Values:
    1. Default: None
1. Where used:
    1. [docker-jupyter](https://github.com/Senzing/docker-jupyter),

### KUBERNETES_DIR

1. Synopsis:
    1. In a Kubernetes environment, a directory holding files for use in the helm `kubectl --filename` parameter.
1. Where used:
    1. [kubernetes-demo](https://github.com/Senzing/kubernetes-demo),

### MYSQL_DATABASE

1. Synopsis:
    1. The database schema name.
1. Values:
    1. Default: "G2"
1. Where used:
    1. [docker-compose-demo](https://github.com/Senzing/docker-compose-demo),

### MYSQL_DIR

1. Synopsis:
    1. Path on local system where the database files are stored.
1. Values:
    1. Default: None.  Application dependent.
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

### POSTGRES_DIR

1. Synopsis:
    1. Path on local system where the database files are stored.
1. Values:
    1. Default: None.  Application dependent.
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

### RABBITMQ_DIR

1. Synopsis:
    1. Path on local system where RabbitMQ files are stored.
1. Values:
    1. Default: None.  Application dependent.
1. Where used:
    1. [docker-compose-demo](https://github.com/Senzing/docker-compose-demo),

### RABBITMQ_PASSWORD

1. Synopsis:
    1. the password for the RabbitMQ user.
1. Values:
    1. Default: None.  Application dependent.

### RABBITMQ_USERNAME

1. Synopsis:
    1. the username for the RabbitMQ user.
1. Values:
    1. Default: None.  Application dependent.

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

### SENZING_API_RPM_DIR

1. Synopsis:
    1. Filename for the
       [Senzing API](../WHATIS/senzing-api.md)
       RPM file.
1. Values:
    1. Format: `senzingapi-M.m.P.x86_64.rpm`
    1. Default: none
1. Where used:
    1. [docker-yum](https://github.com/Senzing/docker-yum),
    1. [docker-yumdownloader](https://github.com/Senzing/docker-yumdownloader),

### SENZING_API_SERVICE_PORT

1. Synopsis:
    1. Port on localhost for Senzing API service.
    1. See [Port 8250](https://github.com/Senzing/knowledge-base/blob/master/lists/ports-used-in-demonstrations.md#8250)
1. Values:
    1. Default: 8250
1. Where used:
    1. [senzing-api-server](https://github.com/Senzing/senzing-api-server),

### SENZING_API_SERVER_URL

1. Synopsis:
    1. A URL consisting of host:port running Senzing API server.
    1. See [Port 8250](https://github.com/Senzing/knowledge-base/blob/master/lists/ports-used-in-demonstrations.md#8250)
1. Values:
    1. Format: `http://${hostname}:${SENZING_API_SERVICE_PORT}`
    1. Default: None
1. Examples:
    1. Using hostname.

        ```console
        export SENZING_API_SERVER_URL="http://example.com:8250"
        ```

1. Where used:
    1. [entity-search-web-app](https://github.com/Senzing/entity-search-web-app),

### SENZING_CONFIG_PATH

1. Where used:
    1. [resolver](https://github.com/Senzing/resolver),

### SENZING_DATA_DIR

1. Where used:
    1. [docker-yum](https://github.com/Senzing/docker-yum),

### SENZING_DATA_RPM_DIR

1. Filename for the
   [Senzing Data](../WHATIS/senzing-data.md)
   RPM file.
1. Values:
    1. Format: `senzingdata-M.m.P.x86_64.rpm`
    1. Default: none
1. Where used:
    1. [docker-yum](https://github.com/Senzing/docker-yum),
    1. [docker-yumdownloader](https://github.com/Senzing/docker-yumdownloader),

### SENZING_DATA_SOURCE

1. Synopsis:
    1. Default "DATA_SOURCE" value for incoming records.
       If a JSON line does not have the `DATA_SOURCE` key/value, this value is inserted.
1. Values:
    1. Default: none
1. Forms:
    1. Helm: senzing.dataSource
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

1. Forms:
    1. Helm: senzing.databaseUrl
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

1. Forms:
    1. Helm: senzing.debug
1. Where used:
    1. [docker-g2command](https://github.com/Senzing/docker-g2command),
       [docker-senzing-base](https://github.com/Senzing/docker-senzing-base),
       [resolver](https://github.com/Senzing/resolver),
       [stream-loader](https://github.com/Senzing/stream-loader),

### SENZING_DIR

1. **Deprecated**
1. Synopsis:
    1. Path on the local system where
       [Senzing_API.tgz](https://s3.amazonaws.com/public-read-access/SenzingComDownloads/Senzing_API.tgz)
       has been extracted.
       See [HOWTO - Create SENZING_DIR](https://github.com/Senzing/knowledge-base/blob/master/HOWTO/create-senzing-dir.md).
1. Values:
    1. Default: None
    1. Usually set to "/opt/senzing".
1. Forms:
    1. Helm: senzing.senzingDir

### SENZING_DOCKER_HOST_IP_ADDR

1. Synopsis:
    1. The IP address of the system hosting Docker containers.
1. Examples:
    1. Manually specify.
       Example:

        ```console
        export SENZING_DOCKER_HOST_IP_ADDR=10.1.1.100
        ```

    1. To find the value for SENZING_DOCKER_HOST_IP_ADDR use Python interactively:
       Example:

        ```console
        python3
        ```

       Copy and paste the following lines into the Python REPL (Read-Evaluate-Print Loop):

        ```python
        import socket

        sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        sock.connect(("8.8.8.8", 80))
        print("export SENZING_DOCKER_HOST_IP_ADDR={0}".format(sock.getsockname()[0]))
        sock.close()
        quit()
        ```

       Copy and paste the printed export statement into the host terminal.

1. Where used:
    1. [senzing-environment](https://github.com/Senzing/senzing-environment),

### SENZING_DOCKER_LAUNCHED

1. Where used:
    1. [docker-init-container](https://github.com/Senzing/docker-init-container),

### SENZING_DOCKER_SOCKET

1. Synopsis:
    1. Location of socket used to communicate with Docker.
1. Examples:
    1. Common Linux location

        ```console
        export SENZING_DOCKER_SOCKET=/var/run/docker.sock
        ```

1. Where used:
    1. [senzing-environment](https://github.com/Senzing/senzing-environment),

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

### SENZING_DOWNLOAD_FILE

1. Synopsis:
    1. Location of where to place a downloaded file.
1. Examples:
    1. Download to `/tmp/my-downloads/x-file.tmp`

        ```console
        export SENZING_DOWNLOAD_FILE=/tmp/my-downloads/x-file.tmp
        ```

### SENZING_ENGINE_CONFIGURATION_JSON

1. Synopsis:
    1. A JSON string that is a parameter to the Senzing Engine's `*.initV2()` function.

### SENZING_ENTITY_TYPE

1. Synopsis:
    1. Default "ENTITY_TYPE" value for incoming records.
       If a JSON line does not have the `ENTITY_TYPE` key/value, this value is inserted.
1. Values:
    1. Default: none
1. Forms:
    1. Helm: senzing.entityType
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
1. Forms:
    1. Helm: senzing.logLevel
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

### SENZING_MONITORING_PERIOD_IN_SECONDS

1. Synopsis:
    1. Time, in seconds, between monitoring log records.
1. Values:
    1. Default: 600

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

### SENZING_OPT_IBM_DIR

1. Synopsis:
    1. Path on the local system where the `/opt/IBM` code resides.
       For instance, the Db2 client driver configuration would be located at
       `${SENZING_OPT_IBM_DIR}/db2/clidriver/cfg/db2dsdriver.cfg`
1. Values:
    1. Default: none
    1. Usually set to `/opt/IBM`
1. Where used:
    1. [docker-db2-driver-installer](https://github.com/Senzing/docker-db2-driver-installer),

### SENZING_OPT_MICROSOFT_DIR

1. Synopsis:
    1. Path on the local system where the `/opt/microsoft` code resides.
1. Values:
    1. Default: none
    1. Usually set to `/opt/microsoft`

### SENZING_OUTPUT_FILE

1. Where used:
    1. [resolver](https://github.com/Senzing/resolver),

### SENZING_PLUGINS_DIR

1. Synopsis:
    1. Path on the local system where plugin files are located.
1. Values:
    1. Default: none
1. Examples:
    1. Using an IP address:

        ```console
        export SENZING_PLUGINS_DIR=${GIT_REPOSITORY_DIR}/resources/plugins
        ```

1. Where used:
    1. [docker-compose-demo](https://github.com/Senzing/docker-compose-demo),

### SENZING_PORT

1. Where used:
    1. [resolver](https://github.com/Senzing/resolver),

### SENZING_PORTAINER_DIR

1. Synopsis:
    1. A directory where [Portainer](https://github.com/Senzing/knowledge-base/blob/master/WHATIS/portainer.md) can keep variable data.
1. Where used:
    1. [senzing-environment](https://github.com/Senzing/senzing-environment),

### SENZING_SQL_CONNECTION

1. Synopsis:
    1. A database URI in the form native to the database client driver.
    1. This differs from [SENZING_DATABASE_URL](#senzing_database_url), which has been "normalized"
       and is not in the native format.
1. Examples:
    1. Using an IP address:

        ```console
        export SENZING_SQL_CONNECTION=mysql://username:password@hostname:3306/?schema=schemaname
        ```

1. Where used:
    1. [senzing-environment](https://github.com/Senzing/senzing-environment),

### SENZING_PROCESSES

1. Synopsis:
    1. Number of processes to allocated for processing.
1. Values:
    1. Default: 1
1. Where used:
    1. [stream-loader](https://github.com/Senzing/stream-loader),

### SENZING_PROJECT_DIR

1. Synopsis:
    1. A path to a Senzing project.
1. Examples:
    1. A project in the home directory.
       Example:

        ```console
        export SENZING_PROJECT_DIR=~/my-senzing-project
        ```

1. Where used:
    1. [senzing-environment](https://github.com/Senzing/senzing-enviroment),

### SENZING_PROJECT_NAME

1. Synopsis:
    1. The name of a Senzing project.
    1. Used as a prefix when creating objects for the project.
1. Examples:
    1. A project in the home directory.
       Example:

        ```console
        export SENZING_PROJECT_NAME=~/test01
        ```

1. Where used:
    1. [senzing-environment](https://github.com/Senzing/senzing-enviroment),

### SENZING_QUEUE_MAX

1. Synopsis:
    1. Maximum items for internal queue.
1. Values:
    1. Default: 10
1. Where used:
    1. [stream-loader](https://github.com/Senzing/stream-loader),

### SENZING_RABBITMQ_EXCHANGE

1. Synopsis:
    1. Name of the RabbitMQ exchange used for communication.
1. Values:
    1. Default: "senzing-exchange"
1. Where used:
    1. [mock-data-generator](https://github.com/Senzing/mock-data-generator),

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

### SENZING_RABBITMQ_PREFETCH_COUNT

1. Synopsis:
    1. The number of records to get from the RabbitMQ queue in one request. Reduces the number of overall requests to the RabbitMQ server and improves performance.
1. Values:
    1. Default: 50
1. Where used:
    1. [stream-loader](https://github.com/Senzing/stream-loader),

### SENZING_RABBITMQ_PUBLISH_BATCH_SIZE

1. Synopsis:
    1. The number of records to publish to RabbitMQ in a batch
1. Values:
    1. Default: "1000"
1. Where used:
    1. [mock-data-generator](https://github.com/Senzing/mock-data-generator),

### SENZING_RABBITMQ_PUBLISH_INTERVAL

1. Synopsis:
    1. How often (in seconds) to publish a batch of records to the RabbitMQ Queue
1. Values:
    1. Default: "0.0"
1. Where used:
    1. [mock-data-generator](https://github.com/Senzing/mock-data-generator),

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

### SENZING_RANDOM_SEED

1. Synopsis:
    1. Identify seed for random number generator.
       Value of 0 uses system clock.
       Values greater than 0 give repeatable results.
1. Values:
    1. Default: "0"
1. Where used:
    1. [mock-data-generator](https://github.com/Senzing/mock-data-generator),

### SENZING_RECORD_MAX

1. Synopsis:
    1. Identify highest record number to generate.
1. Values:
    1. Value of 0 means no maximum.
    1. Default: "0"
1. Where used:
    1. [mock-data-generator](https://github.com/Senzing/mock-data-generator),

### SENZING_RECORD_MIN

1. Synopsis:
    1. Identify lowest record number to generate.
1. Values:
    1. Default: "1"
1. Where used:
    1. [mock-data-generator](https://github.com/Senzing/mock-data-generator),

### SENZING_RECORD_MONITOR

1. Synopsis:
    1. Write a log record every N mock records.
1. Values:
    1. Default: "10000"
1. Where used:
    1. [mock-data-generator](https://github.com/Senzing/mock-data-generator),

### SENZING_RECORDS_PER_SECOND

1. Synopsis:
    1. Throttle output to a specified records per second.
1. Values:
    1. Value of 0 means no throttling.
    1. Default: "0"
1. Where used:
    1. [mock-data-generator](https://github.com/Senzing/mock-data-generator),

### SENZING_RPM_FILENAME

1. Synopsis:
    1. Filename for the
       [Senzing API](../WHATIS/senzing-api.md)
       RPM file.
1. Values:
    1. Format: `senzingapi-MM.mm.PP.x86_64.rpm`
    1. Default: none
1. Where used:
    1. [docker-yum](https://github.com/Senzing/docker-yum),

### SENZING_RUNAS_USER

1. Synopsis:
    1. A parameter for the `docker run` statement to force the container to run as a specific user.
1. Values:
    1. Default: 1001
1. Examples:
    1. root

        ```console
        export SENZING_RUNAS_USER="0"
        ```

1. Where used:
    1. [docker-init-container](https://github.com/Senzing/docker-init-container),

### SENZING_SLEEP_TIME

1. Synopsis:
    1. Amount of time to sleep, in seconds, before running command.
1. Forms:
    1. Helm: senzing.sleepTime
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
1. Forms:
    1. Helm: senzing.subcommand
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

### SENZING_WEB_SERVER_PORT

1. Synopsis:
    1. Port on localhost for Senzing Entity Search WebApp.
    1. See [Port 8251](https://github.com/Senzing/knowledge-base/blob/master/lists/ports-used-in-demonstrations.md#8251)
1. Values:
    1. Default: 8251
1. Where used:
    1. [entity-search-web-app](https://github.com/Senzing/entity-search-web-app),

### SENZING_WEBAPP_PORT

1. Synopsis:
    1. Port on localhost for Docker web application service.
1. Values:
    1. Default: none
1. Where used:
    1. [senzing-api-server](https://github.com/Senzing/senzing-api-server),

### SQLITE_DATABASE

1. Synopsis:
    1. Name of SQLite database containing Senzing schema.
1. Values:
    1. Usual value: `G2C.db`
    1. Default: none

## References

1. [GitHub environment variables](https://help.github.com/en/actions/automating-your-workflow-with-github-actions/using-environment-variables#default-environment-variables)
