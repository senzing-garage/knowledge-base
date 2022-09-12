# How to deploy RabbitMQ and PostgreSQL backing services

## Using docker-compose

1. Specify a new directory to place artifacts in.
   Example:

    ```console
    export SENZING_VOLUME=~/my-senzing
    ```

1. Create directories.
   Example:

    ```console
    export PGADMIN_DIR=${SENZING_VOLUME}/pgadmin
    export POSTGRES_DIR=${SENZING_VOLUME}/postgres
    export RABBITMQ_DIR=${SENZING_VOLUME}/rabbitmq
    export SENZING_UID=$(id -u)
    export SENZING_GID=$(id -g)
    mkdir -p ${PGADMIN_DIR} ${POSTGRES_DIR} ${RABBITMQ_DIR}
    chmod -R 777 ${SENZING_VOLUME}
    ```

1. Download artifacts.
   Example:

    ```console
    curl -X GET \
      --output ${SENZING_VOLUME}/docker-compose-rabbitmq-postgresql-backing-services-only.yaml \
      https://raw.githubusercontent.com/Senzing/docker-compose-demo/main/resources/postgresql/docker-compose-rabbitmq-postgresql-backing-services-only.yaml
    ```

1. :thinking: **Optional:**
   Specify versions of Docker images.
   Example:

    ```console
    curl -X GET \
        --output ${SENZING_VOLUME}/docker-versions-stable.sh \
        https://raw.githubusercontent.com/Senzing/knowledge-base/main/lists/docker-versions-stable.sh
    source ${SENZING_VOLUME}/docker-versions-stable.sh
    ```

1. Bring up a Docker Compose stack with backing services.
   Example:

    ```console
    docker-compose \
      -f ${SENZING_VOLUME}/docker-compose-rabbitmq-postgresql-backing-services-only.yaml \
      up
    ```
