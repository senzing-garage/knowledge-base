# Add docker images to private registry

## Prerequisites

1. If you need to create a private docker registry, see
       [HOWTO - Install docker registry server](https://github.com/Senzing/knowledge-base/blob/master/HOWTO/install-docker-registry-server.md).

## Accept End User License Agreement

1. Accept End User License Agreement (EULA) for `store/senzing/senzing-package` docker image.
    1. Visit [HOWTO - Accept EULA](https://github.com/Senzing/knowledge-base/blob/master/HOWTO/accept-eula.md#storesenzingsenzing-package-docker-image).

## Build docker images

1. Build Senzing "helper" Docker images.
   Example:

    ```console
    sudo docker build --tag senzing/db2          https://github.com/senzing/docker-db2.git
    sudo docker build --tag senzing/db2express-c https://github.com/senzing/docker-db2express-c.git
    sudo docker build --tag senzing/mysql        https://github.com/senzing/docker-mysql.git
    sudo docker build --tag senzing/mysql-init   https://github.com/senzing/docker-mysql-init.git
    ```

## Identify docker images

1. :pencil2: List docker images in DockerHub in an environment variable.
   Example:

    ```console
    export DOCKER_IMAGE_NAMES=( \
      "arey/mysql-client:latest" \
      "bitnami/kafka:2.3.0-debian-9-r4" \
      "bitnami/phpmyadmin:4.8.5" \
      "bitnami/postgresql:11.6.0" \
      "bitnami/rabbitmq:3.7.18-debian-9-r1" \
      "bitnami/rabbitmq:3.8.2-debian-9-r0" \
      "bitnami/rabbitmq:3.8.2-debian-9-r31" \
      "coleifer/sqlite-web:latest" \
      "confluentinc/cp-kafka:4.0.1-1" \
      "dockage/phppgadmin:latest" \
      "jbergknoff/postgresql-client:latest" \
      "senzing/configurator:latest" \
      "senzing/db2:latest" \
      "senzing/db2-driver-installer:latest" \
      "senzing/entity-search-web-app:latest" \
      "senzing/g2command:latest" \
      "senzing/g2configtool:latest" \
      "senzing/g2loader:latest" \
      "senzing/ibm-db2:latest" \
      "senzing/init-container:latest" \
      "senzing/jupyter:latest" \
      "senzing/mock-data-generator:latest" \
      "senzing/mysql:latest" \
      "senzing/python-demo:latest" \
      "senzing/redoer:latest" \
      "senzing/senzing-api-server:latest" \
      "senzing/senzing-base:latest" \
      "senzing/senzing-debug:latest" \
      "senzing/senzing-poc-utility:latest" \
      "senzing/stream-loader:latest" \
      "senzing/yum:latest" \
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
