# Environment variables

## List

### ADMINER_DEFAULT_SERVER

1. Synopsis:
    1. The default hostname/ip-address of the database server.
    1. See [Adminer on DockerHub](https://hub.docker.com/_/adminer)
1. [Where used](https://github.com/search?q=org%3ASenzing+ADMINER_DEFAULT_SERVER&type=code)

### AWS_ACCESS_KEY_ID

1. Synopsis:
    1. The access key for your AWS account.
    1. When used in python programs, see [Boto3 Configuration, Using environment variables](https://boto3.amazonaws.com/v1/documentation/api/latest/guide/configuration.html#using-environment-variables).
1. Examples:
    1. See [How to set AWS environment variables](https://github.com/Senzing/knowledge-base/blob/master/HOWTO/set-aws-environment-variables.md#aws_access_key_id)
1. [Where used](https://github.com/search?q=org%3ASenzing+AWS_ACCESS_KEY_ID&type=code)

### AWS_CA_BUNDLE

1. Synopsis:
    1. The path to a custom certificate bundle to use when establishing SSL/TLS connections.
    1. When used in python programs, see [Boto3 Configuration, Using environment variables](https://boto3.amazonaws.com/v1/documentation/api/latest/guide/configuration.html#using-environment-variables).
1. [Where used](https://github.com/search?q=org%3ASenzing+AWS_CA_BUNDLE&type=code)

### AWS_CONFIG_FILE

1. Synopsis:
    1. The location of the config file.
    1. When used in python programs, see [Boto3 Configuration, Using environment variables](https://boto3.amazonaws.com/v1/documentation/api/latest/guide/configuration.html#using-environment-variables).
1. [Where used](https://github.com/search?q=org%3ASenzing+AWS_CONFIG_FILE&type=code)

### AWS_DATA_PATH

1. Synopsis:
    1. A list of additional directories to check when loading botocore data.
    1. When used in python programs, see [Boto3 Configuration, Using environment variables](https://boto3.amazonaws.com/v1/documentation/api/latest/guide/configuration.html#using-environment-variables).
1. [Where used](https://github.com/search?q=org%3ASenzing+AWS_DATA_PATH&type=code)

### AWS_DEFAULT_REGION

1. Synopsis:
    1. The default AWS Region to use.
    1. When used in python programs, see [Boto3 Configuration, Using environment variables](https://boto3.amazonaws.com/v1/documentation/api/latest/guide/configuration.html#using-environment-variables).
1. Examples:
    1. `us-east-1`
    1. `us-west-2`
    1. See [How to set AWS environment variables](https://github.com/Senzing/knowledge-base/blob/master/HOWTO/set-aws-environment-variables.md#aws_default_region)
1. [Where used](https://github.com/search?q=org%3ASenzing+AWS_DEFAULT_REGION&type=code)

### AWS_MAX_ATTEMPTS

1. Synopsis:
    1. The total number of attempts made for a single request.
    1. When used in python programs, see [Boto3 Configuration, Using environment variables](https://boto3.amazonaws.com/v1/documentation/api/latest/guide/configuration.html#using-environment-variables).
1. [Where used](https://github.com/search?q=org%3ASenzing+AWS_MAX_ATTEMPTS&type=code)

### AWS_METADATA_SERVICE_NUM_ATTEMPTS

1. Synopsis:
    1. Number of attempts to retrieve credentials on an Amazon EC2 instance.
    1. When used in python programs, see [Boto3 Configuration, Using environment variables](https://boto3.amazonaws.com/v1/documentation/api/latest/guide/configuration.html#using-environment-variables).
1. Values:
    - Default: 1
1. [Where used](https://github.com/search?q=org%3ASenzing+AWS_METADATA_SERVICE_NUM_ATTEMPTS&type=code)

### AWS_METADATA_SERVICE_TIMEOUT

1. Synopsis:
    1. The number of seconds before a connection to the instance metadata service should time out.
    1. When used in python programs, see [Boto3 Configuration, Using environment variables](https://boto3.amazonaws.com/v1/documentation/api/latest/guide/configuration.html#using-environment-variables).
1. [Where used](https://github.com/search?q=org%3ASenzing+AWS_METADATA_SERVICE_TIMEOUT&type=code)

### AWS_PROFILE

1. Synopsis:
    1. The default profile to use, if any.
    1. When used in python programs, see [Boto3 Configuration, Using environment variables](https://boto3.amazonaws.com/v1/documentation/api/latest/guide/configuration.html#using-environment-variables).
1. [Where used](https://github.com/search?q=org%3ASenzing+AWS_PROFILE&type=code)

### AWS_RETRY_MODE

1. Synopsis:
    1. Specifies the types of retries the SDK will use.
    1. When used in python programs, see [Boto3 Configuration, Using environment variables](https://boto3.amazonaws.com/v1/documentation/api/latest/guide/configuration.html#using-environment-variables).
1. [Where used](https://github.com/search?q=org%3ASenzing+AWS_RETRY_MODE&type=code)

### AWS_SECRET_ACCESS_KEY

1. Synopsis:
    1. The secret key for your AWS account.
    1. When used in python programs, see [Boto3 Configuration, Using environment variables](https://boto3.amazonaws.com/v1/documentation/api/latest/guide/configuration.html#using-environment-variables).
1. Examples:
    1. See [How to set AWS environment variables](https://github.com/Senzing/knowledge-base/blob/master/HOWTO/set-aws-environment-variables.md#aws_secret_access_key)
1. [Where used](https://github.com/search?q=org%3ASenzing+AWS_SECRET_ACCESS_KEY&type=code)

### AWS_SESSION_TOKEN

1. Synopsis:
    1. The session key for your AWS account.
    1. When used in python programs, see [Boto3 Configuration, Using environment variables](https://boto3.amazonaws.com/v1/documentation/api/latest/guide/configuration.html#using-environment-variables).
1. Examples:
    1. See [How to set AWS environment variables](https://github.com/Senzing/knowledge-base/blob/master/HOWTO/set-aws-environment-variables.md#aws_session_token)
1. [Where used](https://github.com/search?q=org%3ASenzing+AWS_SESSION_TOKEN&type=code)

### AWS_SHARED_CREDENTIALS_FILE

1. Synopsis:
    1. The location of the shared credentials file.
    1. When used in python programs, see [Boto3 Configuration, Using environment variables](https://boto3.amazonaws.com/v1/documentation/api/latest/guide/configuration.html#using-environment-variables).
1. Values:
    - Default: `~/.aws/credentials`
1. [Where used](https://github.com/search?q=org%3ASenzing+AWS_SHARED_CREDENTIALS_FILE&type=code)

### AWS_STS_REGIONAL_ENDPOINTS

1. Synopsis:
    1. Sets AWS STS endpoint resolution logic.
    1. When used in python programs, see [Boto3 Configuration, Using environment variables](https://boto3.amazonaws.com/v1/documentation/api/latest/guide/configuration.html#using-environment-variables).
1. [Where used](https://github.com/search?q=org%3ASenzing+AWS_STS_REGIONAL_ENDPOINTS&type=code)

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

1. [Where used](https://github.com/search?q=org%3ASenzing+DATABASE_DATABASE&type=code)

### DATABASE_HOST

1. Synopsis:
   1. A component of [SENZING_DATABASE_URL](#senzing_database_url).
   1. A hostname, IP address, or symbolic name of the database service.
1. Examples:
    1. Using an IP address:

        ```console
        export DATABASE_HOST=10.1.1.17
        ```

1. [Where used](https://github.com/search?q=org%3ASenzing+DATABASE_HOST&type=code)

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

### PYTHONPATH

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

### RABBITMQ_USE_EXISTING_ENTITIES

1. Synopsis:
    1. Should preexisting RabbitMQ exchanges, queues, and mappings be used.
1. Values:
    1. Default: Varies
    2. True: Connect to an existing exchange or queue using the given name. Fails if the entity does not exist.
    3. False: Create the entities if they do not exist, or connect to a prexisting entity if it has the right settings. Fails if the settings passed when conncting differ from the settings on the existing entity.
1. Where used:
    1. [stream-loader](https://github.com/Senzing/stream-loader)
    1. [stream-producer](https://github.com/Senzing/stream-producer)

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

### SENZING_CONFIGURATION_CHECK_FREQUENCY

1. Synopsis:
    1. Determine how often to check for a change in the Senzing configuration.
1. Where used:
    1. [stream-loader](https://github.com/Senzing/stream-loader),

### SENZING_CONFIG_PATH

1. Synopsis:
    1. Used for `PIPELINE.CONFIGPATH` value in G2 Engine configuration.
1. Values:
    1. Default: `/etc/opt/senzing`
1. Where used:
    1. [resolver](https://github.com/Senzing/resolver),
    1. [stream-loader](https://github.com/Senzing/stream-loader),

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

### SENZING_DELAY_IN_SECONDS

1. Synopsis:
    1. Time to delay before actually starting process
    1. Used for simple choreography.
1. Where used:
    1. [stream-loader](https://github.com/Senzing/stream-loader),

### SENZING_DELAY_RANDOMIZED

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

### SENZING_DOCKER_IMAGE_VERSION_ADMINER

1. Synopsis:
    1. The desired version of
       [senzing/adminer](https://hub.docker.com/r/senzing/adminer).
1. To see latest version, visit
   [docker-versions-latest.sh](https://github.com/Senzing/knowledge-base/blob/master/lists/docker-versions-latest.sh)
1. Where used:
    1. [docker-compose-demo](https://github.com/Senzing/docker-compose-demo)

### SENZING_DOCKER_IMAGE_VERSION_APT

1. Synopsis:
    1. The desired version of
       [senzing/apt](https://hub.docker.com/r/senzing/apt).
1. To see latest version, visit
   [docker-versions-latest.sh](https://github.com/Senzing/knowledge-base/blob/master/lists/docker-versions-latest.sh)
1. Where used:
    1. [docker-compose-demo](https://github.com/Senzing/docker-compose-demo)

### SENZING_DOCKER_IMAGE_VERSION_DB2_DRIVER_INSTALLER

1. Synopsis:
    1. The desired version of
       [senzing/db2-driver-installer](https://hub.docker.com/r/senzing/db2-driver-installer).
1. To see latest version, visit
   [docker-versions-latest.sh](https://github.com/Senzing/knowledge-base/blob/master/lists/docker-versions-latest.sh)
1. Where used:
    1. [docker-compose-demo](https://github.com/Senzing/docker-compose-demo)

### SENZING_DOCKER_IMAGE_VERSION_ENTITY_SEARCH_WEB_APP

1. Synopsis:
    1. The desired version of
       [senzing/entity-search-web-app](https://hub.docker.com/r/senzing/entity-search-web-app).
1. To see latest version, visit
   [docker-versions-latest.sh](https://github.com/Senzing/knowledge-base/blob/master/lists/docker-versions-latest.sh)
1. Where used:
    1. [docker-compose-demo](https://github.com/Senzing/docker-compose-demo)

### SENZING_DOCKER_IMAGE_VERSION_INIT_CONTAINER

1. Synopsis:
    1. The desired version of
       [senzing/init-container](https://hub.docker.com/r/senzing/init-container).
1. To see latest version, visit
   [docker-versions-latest.sh](https://github.com/Senzing/knowledge-base/blob/master/lists/docker-versions-latest.sh)
1. Where used:
    1. [docker-compose-demo](https://github.com/Senzing/docker-compose-demo)

### SENZING_DOCKER_IMAGE_VERSION_JUPYTER

1. Synopsis:
    1. The desired version of
       [senzing/jupyter](https://hub.docker.com/r/senzing/jupyter).
1. To see latest version, visit
   [docker-versions-latest.sh](https://github.com/Senzing/knowledge-base/blob/master/lists/docker-versions-latest.sh)
1. Where used:
    1. [docker-compose-demo](https://github.com/Senzing/docker-compose-demo)

### SENZING_DOCKER_IMAGE_VERSION_PHPPGADMIN

1. Synopsis:
    1. The desired version of
       [senzing/phppgadmin](https://hub.docker.com/r/senzing/phppgadmin).
1. To see latest version, visit
   [docker-versions-latest.sh](https://github.com/Senzing/knowledge-base/blob/master/lists/docker-versions-latest.sh)
1. Where used:
    1. [docker-compose-demo](https://github.com/Senzing/docker-compose-demo)

### SENZING_DOCKER_IMAGE_VERSION_PORTAINER

1. Synopsis:
    1. The desired version of
       [portainer/portainer](https://hub.docker.com/r/portainer/portainer).
1. To see latest version, visit
   [docker-versions-latest.sh](https://github.com/Senzing/knowledge-base/blob/master/lists/docker-versions-latest.sh)

### SENZING_DOCKER_IMAGE_VERSION_POSTGRES

1. Synopsis:
    1. The desired version of
       [postgres](https://hub.docker.com/_/postgres).
1. To see latest version, visit
   [docker-versions-latest.sh](https://github.com/Senzing/knowledge-base/blob/master/lists/docker-versions-latest.sh)

### SENZING_DOCKER_IMAGE_VERSION_POSTGRESQL_CLIENT

1. Synopsis:
    1. The desired version of
       [senzing/postgresql-client](https://hub.docker.com/r/senzing/postgresql-client).
1. To see latest version, visit
   [docker-versions-latest.sh](https://github.com/Senzing/knowledge-base/blob/master/lists/docker-versions-latest.sh)
1. Where used:
    1. [docker-compose-demo](https://github.com/Senzing/docker-compose-demo)

### SENZING_DOCKER_IMAGE_VERSION_RABBITMQ

1. Synopsis:
    1. The desired version of
       [bitnami/rabbitmq](https://hub.docker.com/r/bitnami/rabbitmq).
1. To see latest version, visit
   [docker-versions-latest.sh](https://github.com/Senzing/knowledge-base/blob/master/lists/docker-versions-latest.sh)

### SENZING_DOCKER_IMAGE_VERSION_REDOER

1. Synopsis:
    1. The desired version of
       [senzing/redoer](https://hub.docker.com/r/senzing/redoer).
1. To see latest version, visit
   [docker-versions-latest.sh](https://github.com/Senzing/knowledge-base/blob/master/lists/docker-versions-latest.sh)
1. Where used:
    1. [docker-compose-demo](https://github.com/Senzing/docker-compose-demo)

### SENZING_DOCKER_IMAGE_VERSION_RESOLVER

1. Synopsis:
    1. The desired version of
       [senzing/resolver](https://hub.docker.com/r/senzing/resolver).
1. To see latest version, visit
   [docker-versions-latest.sh](https://github.com/Senzing/knowledge-base/blob/master/lists/docker-versions-latest.sh)
1. Where used:
    1. [docker-compose-demo](https://github.com/Senzing/docker-compose-demo)

### SENZING_DOCKER_IMAGE_VERSION_SENZING_API_SERVER

1. Synopsis:
    1. The desired version of
       [senzing/senzing-api-server](https://hub.docker.com/r/senzing/senzing-api-server).
1. To see latest version, visit
   [docker-versions-latest.sh](https://github.com/Senzing/knowledge-base/blob/master/lists/docker-versions-latest.sh)
1. Where used:
    1. [docker-compose-demo](https://github.com/Senzing/docker-compose-demo)
    1. [entity-search-web-app](https://github.com/Senzing/entity-search-web-app)

### SENZING_DOCKER_IMAGE_VERSION_SENZING_CONSOLE

1. Synopsis:
    1. The desired version of
       [senzing/console](https://hub.docker.com/r/senzing/console).
1. To see latest version, visit
   [docker-versions-latest.sh](https://github.com/Senzing/knowledge-base/blob/master/lists/docker-versions-latest.sh)

### SENZING_DOCKER_IMAGE_VERSION_SENZING_DEBUG

1. Synopsis:
    1. The desired version of
       [senzing/senzing-debug](https://hub.docker.com/r/senzing/senzing-debug).
1. To see latest version, visit
   [docker-versions-latest.sh](https://github.com/Senzing/knowledge-base/blob/master/lists/docker-versions-latest.sh)
1. Where used:
    1. [docker-compose-demo](https://github.com/Senzing/docker-compose-demo)

### SENZING_DOCKER_IMAGE_VERSION_SQLITE_WEB

1. Synopsis:
    1. The desired version of
       [coleifer/sqlite-web](https://hub.docker.com/r/coleifer/sqlite-web).
1. To see latest version, visit
   [docker-versions-latest.sh](https://github.com/Senzing/knowledge-base/blob/master/lists/docker-versions-latest.sh)

### SENZING_DOCKER_IMAGE_VERSION_SSHD

1. Synopsis:
    1. The desired version of
       [senzing/sshd](https://hub.docker.com/r/senzing/sshd).
1. To see latest version, visit
   [docker-versions-latest.sh](https://github.com/Senzing/knowledge-base/blob/master/lists/docker-versions-latest.sh)

### SENZING_DOCKER_IMAGE_VERSION_STREAM_LOADER

1. Synopsis:
    1. The desired version of
       [senzing/stream-loader](https://hub.docker.com/r/senzing/stream-loader).
1. To see latest version, visit
   [docker-versions-latest.sh](https://github.com/Senzing/knowledge-base/blob/master/lists/docker-versions-latest.sh)
1. Where used:
    1. [docker-compose-demo](https://github.com/Senzing/docker-compose-demo)

### SENZING_DOCKER_IMAGE_VERSION_STREAM_LOGGER

1. Synopsis:
    1. The desired version of
       [senzing/stream-logger](https://hub.docker.com/r/senzing/stream-logger).
1. To see latest version, visit
   [docker-versions-latest.sh](https://github.com/Senzing/knowledge-base/blob/master/lists/docker-versions-latest.sh)
1. Where used:
    1. [docker-compose-demo](https://github.com/Senzing/docker-compose-demo)

### SENZING_DOCKER_IMAGE_VERSION_STREAM_PRODUCER

1. Synopsis:
    1. The desired version of
       [senzing/stream-producer](https://hub.docker.com/r/senzing/stream-producer).
1. To see latest version, visit
   [docker-versions-latest.sh](https://github.com/Senzing/knowledge-base/blob/master/lists/docker-versions-latest.sh)
1. Where used:
    1. [docker-compose-demo](https://github.com/Senzing/docker-compose-demo)
    1. [stream-producer](https://github.com/Senzing/stream-producer)

### SENZING_DOCKER_IMAGE_VERSION_WEB_APP_DEMO

1. Synopsis:
    1. The desired version of
       [senzing/web-app-demo](https://hub.docker.com/r/senzing/web-app-demo).
1. To see latest version, visit
   [docker-versions-latest.sh](https://github.com/Senzing/knowledge-base/blob/master/lists/docker-versions-latest.sh)

### SENZING_DOCKER_IMAGE_VERSION_XTERM

1. Synopsis:
    1. The desired version of
       [senzing/xterm](https://hub.docker.com/r/senzing/xterm).
1. To see latest version, visit
   [docker-versions-latest.sh](https://github.com/Senzing/knowledge-base/blob/master/lists/docker-versions-latest.sh)
1. Where used:
    1. [docker-compose-demo](https://github.com/Senzing/docker-compose-demo)

### SENZING_DOCKER_IMAGE_VERSION_YUM

1. Synopsis:
    1. The desired version of
       [senzing/yum](https://hub.docker.com/r/senzing/yum).
1. To see latest version, visit
   [docker-versions-latest.sh](https://github.com/Senzing/knowledge-base/blob/master/lists/docker-versions-latest.sh)
1. Where used:
    1. [docker-compose-demo](https://github.com/Senzing/docker-compose-demo)

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

### SENZING_DOCKERHUB_API_ENDPOINT_V1

1. Synopsis:
    1. URL of the docker registry's
       Version 1 API.
1. Examples:
    1. registry.hub.docker.com

        ```console
        export SENZING_DOCKERHUB_API_ENDPOINT_V1=https://registry.hub.docker.com/v1
        ```

1. Where used:
    1. [dockerhub-util](https://github.com/Senzing/dockerhub-util),

### SENZING_DOCKERHUB_API_ENDPOINT_V2

1. Synopsis:
    1. URL of the docker registry's
       [Version 2 API](https://docs.docker.com/registry/spec/api/).
1. Examples:
    1. hub.docker.com

        ```console
        export SENZING_DOCKERHUB_API_ENDPOINT_V2=https://hub.docker.com/v2
        ```

1. Where used:
    1. [dockerhub-util](https://github.com/Senzing/dockerhub-util),

### SENZING_DOCKERHUB_ORGANIZATION

1. Synopsis:
    1. Organization name on [hub.docker.com](https://hub.docker.com)
1. Examples:

    1. A "senzing" organization.

        ```console
        export SENZING_DOCKERHUB_ORGANIZATION=senzing
        ```

1. Where used:
    1. [dockerhub-util](https://github.com/Senzing/dockerhub-util),

### SENZING_DOCKERHUB_PASSWORD

1. Synopsis:
    1. [SENZING_DOCKERHUB_USERNAME](#senzing_dockerhub_username)'s password for logging into [hub.docker.com](https://hub.docker.com)
1. Where used:
    1. [dockerhub-util](https://github.com/Senzing/dockerhub-util),

### SENZING_DOCKERHUB_USERNAME

1. Synopsis:
    1. Login username for for [hub.docker.com](https://hub.docker.com)
1. Where used:
    1. [dockerhub-util](https://github.com/Senzing/dockerhub-util),

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

### SENZING_EXIT_ON_EMPTY_QUEUE

1. Synopsis:
    1. Signify that program should end when queue is empty.
1. Values:
     1. Datatype: boolean
     1. Default: False
1. Where used:
    1. [stream-loader](https://github.com/Senzing/stream-loader),

### SENZING_EXIT_SLEEP_TIME_IN_SECONDS

1. Synopsis:
    1. Amount of time to sleep before exiting.
    1. Used in autoscaling to slow down "cool down".
1. Values:
     1. Default: 0
1. Where used:
    1. [stream-loader](https://github.com/Senzing/stream-loader),

### SENZING_EXPIRATION_WARNING_IN_DAYS

1. Synopsis:
    1. Number of days before logging Senzing license expiration notices.
1. Values:
     1. Default: 30
1. Where used:
    1. [stream-loader](https://github.com/Senzing/stream-loader),

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

### SENZING_GOVERNOR_DATABASE_URLS

1. Synopsis:
    1. A list of one or more comma-separated
       [SENZING_DATABASE_URL](#senzing_database_url)s.
1. Examples:
    1. Single SENZING_DATABASE_URL.
       Example:

        ```console
        export SENZING_GOVERNOR_DATABASE_URLS=postgresql://postgres:postgres@localhost:5432/G2
        ```

    1. Multiple SENZING_DATABASE_URLs.
       Example:

        ```console
        export SENZING_GOVERNOR_DATABASE_URLS=postgresql://postgres:postgres@localhost:5432/G2,postgresql://postgres:postgres@localhost:5432/G2_RES
        ```

1. Where used:
    1. [governor-postgresql-transaction-id](https://github.com/Senzing/governor-postgresql-transaction-id),

### SENZING_GOVERNOR_INTERVAL

1. Synopsis:
    1. The number of records "skipped" before executing the analysis for governing.
1. Examples:
    1. Analyze once every 10 million records.
       Example:

        ```console
        export SENZING_GOVERNOR_INTERVAL=10000000
        ```

1. Where used:
    1. [governor-postgresql-transaction-id](https://github.com/Senzing/governor-postgresql-transaction-id),

### SENZING_GOVERNOR_LIST_SEPARATOR

1. Synopsis:
    1. The character used to separate items in a list.
1. Values:
    1. Default: ","  (a single comma)
1. Examples:
    1. Use a plus sign instead of a comma.
       Example:

        ```console
        export SENZING_GOVERNOR_LIST_SEPARATOR="+"
        ```

1. Where used:
    1. [governor-postgresql-transaction-id](https://github.com/Senzing/governor-postgresql-transaction-id),

### SENZING_GOVERNOR_POSTGRESQL_HIGH_WATERMARK

1. Synopsis:
    1. The maximum age of the PostgreSQL transaction ID (XID) before "governance" starts.
1. Values:
    1. Default: 10000000000  (10 billion)
1. Examples:
    1. Set to 9 billion.
       Example:

        ```console
        export SENZING_GOVERNOR_POSTGRESQL_HIGH_WATERMARK=9000000000
        ```

1. Where used:
    1. [governor-postgresql-transaction-id](https://github.com/Senzing/governor-postgresql-transaction-id),

### SENZING_GOVERNOR_POSTGRESQL_LOW_WATERMARK

1. Synopsis:
    1. The maximum age of the PostgreSQL transaction ID (XID) before "governance" stops.
1. Values:
    1. Default: 9000000000 (9 billion)
1. Examples:
    1. Set to 7 billion.
       Example:

        ```console
        export SENZING_GOVERNOR_POSTGRESQL_LOW_WATERMARK=7000000000
        ```

1. Where used:
    1. [governor-postgresql-transaction-id](https://github.com/Senzing/governor-postgresql-transaction-id),

### SENZING_GOVERNOR_PROJECT_DIR

1. Synopsis:
    1. A directory where governor and test code are placed.
1. Examples:
    1. Set to 7 billion.
       Example:

        ```console
        export SENZING_GOVERNOR_PROJECT_DIR=~/test-governor
        ```

1. Where used:
    1. [governor-postgresql-transaction-id](https://github.com/Senzing/governor-postgresql-transaction-id),

### SENZING_GOVERNOR_WAIT

1. Synopsis:
    1. The number of seconds to wait before querying the database.
1. Values:
    1. Default: 15 seconds
1. Examples:
    1. Set to 10 minutes.
       Example:

        ```console
        export SENZING_GOVERNOR_WAIT=600
        ```

1. Where used:
    1. [governor-postgresql-transaction-id](https://github.com/Senzing/governor-postgresql-transaction-id),

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

### SENZING_KAFKA_FAILURE_BOOTSTRAP_SERVER

### SENZING_KAFKA_FAILURE_TOPIC

### SENZING_KAFKA_GROUP

1. Synopsis:
    1. Kafka group.
1. Values:
    1. Default: "senzing-kafka-group"
1. Where used:
    1. [stream-loader](https://github.com/Senzing/stream-loader),

### SENZING_KAFKA_INFO_BOOTSTRAP_SERVER

### SENZING_KAFKA_INFO_TOPIC

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

### SENZING_LOG_LICENSE_PERIOD_IN_SECONDS

1. Synopsis:
    1. Interval between logging Senzing license information.
1. Values:
     1. Default: 1 day
1. Where used:
    1. [stream-loader](https://github.com/Senzing/stream-loader),

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

### SENZING_PRIME_ENGINE

### SENZING_PSTACK_PID

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
    1. Name of the RabbitMQ exchange used for routing messages.
1. Values
    1. Default: "senzing-rabbitmq-exchange"
1. Where used:
    1. [stream-producer](https://github.com/Senzing/stream-producer)

### SENZING_RABBITMQ_FAILURE_EXCHANGE

1. Synopsis:
    1. Name of the RabbitMQ exchange used for routing info messages about loaded records
1. Where used:
    1. [stream-producer](https://github.com/Senzing/stream-loader)
    1. [stream-loader](https://github.com/Senzing/stream-loader)

### SENZING_RABBITMQ_FAILURE_HOST

1. Synopsis:
    1. Host name of the RabbitMQ server used to post records that failed to load
1. Values:
    1. Default: The value of SENZING_RABBITMQ_HOST
1. Where used:
    1. [stream-loader](https://github.com/Senzing/stream-loader)

### SENZING_RABBITMQ_FAILURE_PASSWORD

1. Synopsis:
    1. The password for the RabbitMQ failure server.
1. Values:
    1. Default: The value of SENZING_RABBITMQ_PASSWORD
1. Where used:
    1. [stream-loader](https://github.com/Senzing/stream-loader)

### SENZING_RABBITMQ_FAILURE_PORT

1. Synopsis:
    1. The port to use to connect to the RabbitMQ server specified by SENZING_RABBITMQ_FAILURE_HOST
1. Values:
    1. Default: The value of SENZING_RABBITMQ_PORT
1. Where used:
    1. [stream-loader](https://github.com/Senzing/stream-loader)

### SENZING_RABBITMQ_FAILURE_QUEUE

1. Synopsis:
    1. Name of the RabbitMQ queue used for records that failed to load.
1. Values:
    1. Default: "senzing-rabbitmq-queue"
1. Where used:
    1. [stream-loader](https://github.com/Senzing/stream-loader)

### SENZING_RABBITMQ_FAILURE_ROUTING_KEY

1. Synopsis:
    1. The RabbitMQ routing key to use when creating a binding or publishing a record.
1. Values:
    1. Default: "senzing.failure"
1. Where used:
    1. [stream-producer](https://github.com/Senzing/stream-producer)
    1. [stream-loader](https://github.com/Senzing/stream-loader)

### SENZING_RABBITMQ_FAILURE_USERNAME

1. Synopsis:
    1. The username for the RabbitMQ server.
1. Values:
    1. Default: The value of SENZING_RABBITMQ_USERNAME
1. Where used:
    1. [stream-producer](https://github.com/Senzing/stream-producer)

### SENZING_RABBITMQ_FAILURE_VIRTUAL_HOST

1. Synopsis:
    1. The name of the virtual host where the failure queue exists.
1. Values:
    1. Default: SENZING_RABBITMQ_VIRTUAL_HOST
1. Where used:
    1. [stream-producer](https://github.com/Senzing/stream-producer)

### SENZING_RABBITMQ_HEARTBEAT_IN_SECONDS

1. Synopsis:
    1. Heartbeat time in seconds on connections to the RabbitMQ server.
1. Values:
    1. Default: "60"
1. Where used:
    1. [stream-loader](https://github.com/Senzing/stream-loader)

### SENZING_RABBITMQ_HOST

1. Synopsis:
    1. Host name of the RabbitMQ server.
1. Values:
    1. Default: "localhost:5672"
1. Where used:
    1. [stream-loader](https://github.com/Senzing/stream-loader)
    1. [stream-producer](https://github.com/Senzing/stream-producer)
    1. [stream-logger](https://github.com/Senzing/stream-logger)

### SENZING_RABBITMQ_INFO_EXCHANGE

1. Synopsis:
    1. Name of the RabbitMQ exchange used for routing info messages about loaded records
1. Where used:
    1. [stream-producer](https://github.com/Senzing/stream-loader)

### SENZING_RABBITMQ_INFO_HOST

1. Synopsis:
    1. Host name of the RabbitMQ server used to post the info about a loaded record
1. Values:
    1. Default: The value of SENZING_RABBITMQ_HOST
1. Where used:
    1. [stream-loader](https://github.com/Senzing/stream-loader)

### SENZING_RABBITMQ_INFO_PASSWORD

1. Synopsis:
    1. The password for the RabbitMQ info server.
1. Values:
    1. Default: The value of SENZING_RABBITMQ_PASSWORD
1. Where used:
    1. [stream-loader](https://github.com/Senzing/stream-loader)

### SENZING_RABBITMQ_INFO_PORT

1. Synopsis:
    1. The port to use to connect to the RabbitMQ server specified by SENZING_RABBITMQ_INFO_HOST
1. Values:
    1. Default: The value of SENZING_RABBITMQ_PORT
1. Where used:
    1. [stream-loader](https://github.com/Senzing/stream-loader)

### SENZING_RABBITMQ_INFO_QUEUE

1. Synopsis:
    1. Name of the RabbitMQ queue used for communication.
1. Values:
    1. Default: "senzing-rabbitmq-queue"
1. Where used:
    1. [stream-loader](https://github.com/Senzing/stream-loader)

### SENZING_RABBITMQ_INFO_ROUTING_KEY

1. Synopsis:
    1. The RabbitMQ routing key to use when creating a binding or publishing a record.
1. Values:
    1. Default: "senzing.info"
1. Where used:
    1. [stream-producer](https://github.com/Senzing/stream-producer)
    1. [stream-loader](https://github.com/Senzing/stream-loader)

### SENZING_RABBITMQ_INFO_USERNAME

1. Synopsis:
    1. The username for the RabbitMQ server.
1. Values:
    1. Default: The value of SENZING_RABBITMQ_USERNAME
1. Where used:
    1. [stream-producer](https://github.com/Senzing/stream-producer)

### SENZING_RABBITMQ_INFO_VIRTUAL_HOST

1. Synopsis:
    1. The name of the virtual host where the info queue exists.
1. Values:
    1. Default: SENZING_RABBITMQ_VIRTUAL_HOST
1. Where used:
    1. [stream-producer](https://github.com/Senzing/stream-producer)

### SENZING_RABBITMQ_PASSWORD

1. Synopsis:
    1. The password for the RabbitMQ queue.
1. Values:
    1. Default: "bitnami"
1. Where used:
    1. [stream-loader](https://github.com/Senzing/stream-loader),

### SENZING_RABBITMQ_PORT

1. Synopsis:
    1. The port to use to connect to the RabbitMQ server specified by SENZING_RABBITMQ_HOST
1. Values:
    1. Default: "5672"
1. Where used:
    1. [stream-producer](https://github.com/Senzing/stream-producer)
    1. [stream-loader](https://github.com/Senzing/stream-loader)
    1. [stream-logger](https://github.com/Senzing/stream-logger)

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
    1. [stream-producer](https://github.com/Senzing/stream-producer),

### SENZING_RABBITMQ_PUBLISH_INTERVAL

1. Synopsis:
    1. How often (in seconds) to publish a batch of records to the RabbitMQ Queue
1. Values:
    1. Default: "0.0"
1. Where used:
    1. [stream-producer](https://github.com/Senzing/stream-producer),

### SENZING_RABBITMQ_QUEUE

1. Synopsis:
    1. Name of the RabbitMQ queue used for communication.
1. Values:
    1. Default: "senzing-rabbitmq-queue"
1. Where used:
    1. [stream-loader](https://github.com/Senzing/stream-loader),

### SENZING_RABBITMQ_RECONNECT_DELAY_IN_SECONDS

1. Synopsis:
    1. The time (in seconds) to wait between attempts to reconnect to the RabbitMQ broker.
1. Values:
    1. Default: 60
1. Where used:
    1. [stream-loader](https://github.com/Senzing/stream-loader),

### SENZING_RABBITMQ_RECONNECT_NUMBER_OF_RETRIES

1. Synopsis:
    1. The number of times to try reconnecting a dropped connection to the RabbitMQ broker.
1. Values:
    1. Default: 10
1. Where used:
    1. [stream-loader](https://github.com/Senzing/stream-loader),

### SENZING_RABBITMQ_ROUTING_FAILURE_KEY

1. Synopsis:
    1. The RabbitMQ routing key to use when creating a binding to the failure queue or publishing to the failure exchange.
1. Values:
    1. Default: "senzing.failure"
1. Where used:
    1. [stream-loader](https://github.com/Senzing/stream-loader)

### SENZING_RABBITMQ_ROUTING_INFO_KEY

1. Synopsis:
    1. The RabbitMQ routing key to use when creating a binding to the info queue or publishing to the info exchange.
1. Values:
    1. Default: "senzing.info"
1. Where used:
    1. [stream-loader](https://github.com/Senzing/stream-loader)

### SENZING_RABBITMQ_ROUTING_KEY

1. Synopsis:
    1. The RabbitMQ routing key to use when creating a binding or publishing a record.
1. Values:
    1. Default: "senzing.records"
1. Where used:
    1. [stream-producer](https://github.com/Senzing/stream-producer)
    1. [stream-loader](https://github.com/Senzing/stream-loader)

### SENZING_RABBITMQ_USERNAME

1. Synopsis:
    1. The username for the RabbitMQ queue.
1. Values:
    1. Default: "user"
1. Where used:
    1. [stream-loader](https://github.com/Senzing/stream-loader),

### SENZING_RABBITMQ_USE_EXISTING_ENTITIES

1. Synopsis:
    1. Use existing RabbitMQ entities (exchanges, queues). That is, don't create the entities.
1. Where used:
    1. [stream-producer](https://github.com/Senzing/stream-producer),
    1. [stream-loader](https://github.com/Senzing/stream-loader),

### SENZING_RABBITMQ_VIRTUAL_HOST

1. Synopsis:
    1. The name of the virtual host where the queues exists.
1. Values:
    1. Default: The RabbitMQ defined default virtual host, which is currently '\'
1. Where used:
    1. [stream-producer](https://github.com/Senzing/stream-producer)

### SENZING_RANDOM_SEED

1. Synopsis:
    1. Identify seed for random number generator.
       Value of 0 uses system clock.
       Values greater than 0 give repeatable results.
1. Values:
    1. Default: "0"
1. Where used:
    1. [stream-producer](https://github.com/Senzing/stream-producer),

### SENZING_RECORD_IDENTIFIER

1. Synopsis:
    1. JSON key whose value uniquely identifies a record.
    1. Used to identify specific records when logging errors.
1. Values:
    1. Default: "RECORD_ID"
1. Where used:
    1. [stream-producer](https://github.com/Senzing/stream-producer),

### SENZING_RECORD_MAX

1. Synopsis:
    1. Identify highest record number to generate.
1. Values:
    1. Value of 0 means no maximum.
    1. Default: "0"
1. Where used:
    1. [stream-producer](https://github.com/Senzing/stream-producer),

### SENZING_RECORD_MIN

1. Synopsis:
    1. Identify lowest record number to generate.
1. Values:
    1. Default: "1"
1. Where used:
    1. [stream-producer](https://github.com/Senzing/stream-producer),

### SENZING_RECORD_MONITOR

1. Synopsis:
    1. Write a log record every N mock records.
1. Values:
    1. Default: "10000"
1. Where used:
    1. [stream-producer](https://github.com/Senzing/stream-producer),

### SENZING_RECORDS_PER_SECOND

1. Synopsis:
    1. Throttle output to a specified records per second.
1. Values:
    1. Value of 0 means no throttling.
    1. Default: "0"
1. Where used:
    1. [stream-producer](https://github.com/Senzing/stream-producer),

### SENZING_RECORD_SIZE_MAX

1. Synopsis:
    1. Maximum size of a record that will be sent to a Queue.
    1. Records that exceed the maximum size will be logged.
        1. See [SENZING_RECORD_IDENTIFIER](#senzing_record_identifier)
1. Values:
    1. Value of 0 means no maximum.
    1. Default: "0"
1. Where used:
    1. [stream-producer](https://github.com/Senzing/stream-producer),

### SENZING_RESOURCE_PATH

1. Synopsis:
    1. Used in `PIPELINE_RESOURCEPATH` for G2 Engine configuration.
1. Values:
    1. Default: `/opt/senzing/g2/resources`
1. Where used:
    1. [stream-loader](https://github.com/Senzing/stream-loader),

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

### SENZING_SKIP_DATABASE_PERFORMANCE_TEST

1. Synopsis:
    1. When true, do not perform initial performance evaluation.
1. Where used:
    1. [stream-loader](https://github.com/Senzing/stream-loader),

### SENZING_SKIP_GOVERNOR

### SENZING_SKIP_INFO_FILTER

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

### SENZING_SQS_DEAD_LETTER_QUEUE_ENABLED

1. Synopsis:
    1. Indicate that an AWS SQS "dead-letter" queue has been enables.
    1. This changes the logging behavior.
1. Where used:
    1. [stream-loader](https://github.com/Senzing/stream-loader),

### SENZING_SQS_FAILURE_QUEUE_URL

1. Synopsis:
    1. The Amazon SQS Queue URL used convey messages that cannot be processed by the Senzing Engine.
1. Examples:
    1. `https://sqs.us-east-1.amazonaws.com/000000000000/senzing-failure-queue`
1. Where used:
    1. [stream-loader](https://github.com/Senzing/stream-loader),
    1. [stream-producer](https://github.com/Senzing/stream-producer),

### SENZING_SQS_INFO_QUEUE_DELAY_SECONDS

1. Synopsis:
    1. The length of time, in seconds, for which to delay a specific message on the Info queue.
1. Values:
    1. Default: 10
1. References:
    1. [Boto3 send_message](https://boto3.amazonaws.com/v1/documentation/api/latest/reference/services/sqs.html#SQS.Client.send_message) See `DelaySeconds` parameter.
1. Where used:
    1. [stream-loader](https://github.com/Senzing/stream-loader),

### SENZING_SQS_INFO_QUEUE_URL

1. Synopsis:
    1. The Amazon SQS Queue URL used convey "withInfo" messages from the Senzing Engine.
1. Examples:
    1. `https://sqs.us-east-1.amazonaws.com/000000000000/senzing-info-queue`
1. Where used:
    1. [stream-loader](https://github.com/Senzing/stream-loader),
    1. [stream-producer](https://github.com/Senzing/stream-producer),

### SENZING_SQS_QUEUE_URL

1. Synopsis:
    1. The Amazon SQS Queue URL used convey messages for ingestion into the Senzing Engine.
1. Examples:
    1. `https://sqs.us-east-1.amazonaws.com/000000000000/senzing-queue`
1. Where used:
    1. [stream-loader](https://github.com/Senzing/stream-loader),
    1. [stream-producer](https://github.com/Senzing/stream-producer),

### SENZING_SQS_WAIT_TIME_SECONDS

1. Synopsis:
    1. For use with SQS "long-polling"
1. Where used:
    1. [stream-loader](https://github.com/Senzing/stream-loader),

### SENZING_STREAM_LOADER_DIRECTIVE_NAME

1. Synopsis:
    1. The property name in a JSON Message that identifies a JSON property with information
       to be used by the
       [stream-loader](https://github.com/Senzing/stream-loader).
    1. More information at
       [stream-loader](https://github.com/Senzing/stream-loader#directive).
1. Values:
    1. Default: `senzingStreamLoader`

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
