# How to add docker images to private registry

## Prerequisites

1. If you need to create a private docker registry, see
       [HOWTO - Install docker registry server](https://github.com/Senzing/knowledge-base/blob/main/HOWTO/install-docker-registry-server.md).

## Accept End User License Agreement

1. Accept End User License Agreement (EULA) for `store/senzing/senzing-package` docker image.
    1. Visit [HOWTO - Accept EULA](https://github.com/Senzing/knowledge-base/blob/main/HOWTO/accept-eula.md#storesenzingsenzing-package-docker-image).

## Build docker images

1. Build Senzing "helper" Docker images.
   Example:

    ```console
    sudo docker build --tag senzing/mysql        https://github.com/senzing/docker-mysql.git#main
    sudo docker build --tag senzing/mysql-init   https://github.com/senzing/docker-mysql-init.git#main
    ```

## Identify docker images

1. :thinking: **Optional:**
   Specify versions of Docker images.
   Example:

    ```console
    curl -X GET \
        --output /tmp/docker-versions-stable.sh \
        https://raw.githubusercontent.com/Senzing/knowledge-base/main/lists/docker-versions-stable.sh
    source /tmp/docker-versions-stable.sh

    ```

1. :pencil2: List docker images in DockerHub in an environment variable.
   Example:

    ```console
    export DOCKER_IMAGE_NAMES=(
        "arey/mysql-client:${SENZING_DOCKER_IMAGE_VERSION_AREY_MYSQL_CLIENT:-latest}"
        "bitnami/bitnami-shell:${SENZING_DOCKER_IMAGE_VERSION_BITNAMI_SHELL:-latest}"
        "bitnami/kafka:${SENZING_DOCKER_IMAGE_VERSION_BITNAMI_KAFKA:-latest}"
        "bitnami/mysql:${SENZING_DOCKER_IMAGE_VERSION_BITNAMI_MYSQL:-latest}"
        "bitnami/nginx-ingress-controller:${SENZING_DOCKER_IMAGE_VERSION_BITNAMI_NGINX_INGRESS_CONTROLLER:-latest}"
        "bitnami/phpmyadmin:${SENZING_DOCKER_IMAGE_VERSION_BITNAMI_PHPMYADMIN:-latest}"
        "bitnami/postgresql:${SENZING_DOCKER_IMAGE_VERSION_BITNAMI_POSTGRESQL:-latest}"
        "bitnami/rabbitmq:${SENZING_DOCKER_IMAGE_VERSION_BITNAMI_RABBITMQ:-latest}"
        "bitnami/zookeeper:${SENZING_DOCKER_IMAGE_VERSION_BITNAMI_ZOOKEEPER:-latest}"
        "busybox:${SENZING_DOCKER_IMAGE_VERSION_BUSYBOX:-latest}"
        "coleifer/sqlite-web:${SENZING_DOCKER_IMAGE_VERSION_SQLITE_WEB:-latest}"
        "confluentinc/cp-kafka:${SENZING_DOCKER_IMAGE_VERSION_CONFLUENTINC_CP_KAFKA:-latest}"
        "dpage/pgadmin4:${SENZING_DOCKER_IMAGE_VERSION_DPAGE_PGADMIN4:-latest}"
        "obsidiandynamics/kafdrop:${SENZING_DOCKER_IMAGE_VERSION_OBSIDIANDYNAMICS_KAFDROP:-latest}"
        "senzing/adminer:${SENZING_DOCKER_IMAGE_VERSION_ADMINER:-latest}"
        "senzing/apt:${SENZING_DOCKER_IMAGE_VERSION_APT:-latest}"
        "senzing/configurator:${SENZING_DOCKER_IMAGE_VERSION_CONFIGURATOR:-latest}"
        "senzing/data-encryption-aes256cbc-sample:${SENZING_DOCKER_IMAGE_VERSION_DATA_ENCRYPTION_AES256CBC_SAMPLE:-latest}"
        "senzing/db2-driver-installer:${SENZING_DOCKER_IMAGE_VERSION_DB2_DRIVER_INSTALLER:-latest}"
        "senzing/entity-search-web-app-console:${SENZING_DOCKER_IMAGE_VERSION_ENTITY_SEARCH_WEB_APP_CONSOLE:-latest}"
        "senzing/entity-search-web-app:${SENZING_DOCKER_IMAGE_VERSION_ENTITY_SEARCH_WEB_APP:-latest}"
        "senzing/file-loader:${SENZING_DOCKER_IMAGE_VERSION_FILE_LOADER:-latest}"
        "senzing/ibm-db2:${SENZING_DOCKER_IMAGE_VERSION_IBM_DB2:-latest}"
        "senzing/init-container:${SENZING_DOCKER_IMAGE_VERSION_INIT_CONTAINER:-latest}"
        "senzing/init-postgresql:${SENZING_DOCKER_IMAGE_VERSION_INIT_POSTGRESQL:-latest}"
        "senzing/postgresql-client:${SENZING_DOCKER_IMAGE_VERSION_POSTGRESQL_CLIENT:-latest}"
        "senzing/redoer:${SENZING_DOCKER_IMAGE_VERSION_REDOER:-latest}"
        "senzing/resolver:${SENZING_DOCKER_IMAGE_VERSION_RESOLVER:-latest}"
        "senzing/senzing-api-server:${SENZING_DOCKER_IMAGE_VERSION_SENZING_API_SERVER:-latest}"
        "senzing/senzing-base:${SENZING_DOCKER_IMAGE_VERSION_SENZING_BASE:-latest}"
        "senzing/senzing-console-slim:${SENZING_DOCKER_IMAGE_VERSION_SENZING_CONSOLE_SLIM:-latest}"
        "senzing/senzing-console:${SENZING_DOCKER_IMAGE_VERSION_SENZING_CONSOLE:-latest}"
        "senzing/senzing-debug:${SENZING_DOCKER_IMAGE_VERSION_SENZING_DEBUG:-latest}"
        "senzing/senzing-poc-server:${SENZING_DOCKER_IMAGE_VERSION_SENZING_POC_SERVER:-latest}"
        "senzing/senzing-tools:${SENZING_DOCKER_IMAGE_VERSION_SENZING_TOOLS:-latest}"
        "senzing/senzingapi-runtime:${SENZING_DOCKER_IMAGE_VERSION_SENZINGAPI_RUNTIME:-latest}"
        "senzing/senzingapi-tools:${SENZING_DOCKER_IMAGE_VERSION_SENZINGAPI_TOOLS:-latest}"
        "senzing/sshd:${SENZING_DOCKER_IMAGE_VERSION_SSHD:-latest}"
        "senzing/stream-loader:${SENZING_DOCKER_IMAGE_VERSION_STREAM_LOADER:-latest}"
        "senzing/stream-producer:${SENZING_DOCKER_IMAGE_VERSION_STREAM_PRODUCER:-latest}"
        "senzing/xterm:${SENZING_DOCKER_IMAGE_VERSION_XTERM=:-latest}"
        "senzing/yum:${SENZING_DOCKER_IMAGE_VERSION_YUM:-latest}"
        "swaggerapi/swagger-ui:${SENZING_DOCKER_IMAGE_VERSION_SWAGGERAPI_SWAGGER_UI:-latest}"
    )

    ```

## Pull images from DockerHub

1. Add docker images to local docker repository.
   Example:

    ```console
    for DOCKER_IMAGE_NAME in ${DOCKER_IMAGE_NAMES[@]};\
    do \
      sudo docker pull ${DOCKER_IMAGE_NAME}; \
    done
    ```

## Identify private registry

1. :pencil2: Set environment variable.
   Example:

    ```console
    export DOCKER_REGISTRY_URL=my.docker-registry.com:5000
    ```

## Push images to private registry

1. Add docker images to private docker registry.
   Example:

    ```console
    for DOCKER_IMAGE_NAME in ${DOCKER_IMAGE_NAMES[@]};\
    do \
      sudo docker tag  ${DOCKER_IMAGE_NAME} ${DOCKER_REGISTRY_URL}/${DOCKER_IMAGE_NAME}; \
      sudo docker push ${DOCKER_REGISTRY_URL}/${DOCKER_IMAGE_NAME}; \
      sudo docker rmi  ${DOCKER_REGISTRY_URL}/${DOCKER_IMAGE_NAME}; \
    done
    ```
