# How to add docker images to private registry

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
    sudo docker build --tag senzing/mysql        https://github.com/senzing/docker-mysql.git
    sudo docker build --tag senzing/mysql-init   https://github.com/senzing/docker-mysql-init.git
    ```

## Identify docker images

1. :pencil2: List docker images in DockerHub in an environment variable.
   Example:

    ```console
    export DOCKER_IMAGE_NAMES=( \
      "arey/mysql-client:latest" \
      "bitnami/kafka:2.4.0" \
      "bitnami/phpmyadmin:4.8.5" \
      "bitnami/postgresql:11.6.0" \
      "bitnami/rabbitmq:3.8.2" \
      "bitnami/zookeeper:3.5.6" \
      "coleifer/sqlite-web:latest" \
      "confluentinc/cp-kafka:4.0.1-1" \
      "dockage/phppgadmin:latest" \
      "ibmcom/db2:11.5.0.0a" \
      "jbergknoff/postgresql-client:latest" \
      "kafkamanager/kafka-manager:2.0.0.2" \
      "mysql:5.7" \
      "obsidiandynamics/kafdrop:3.23.0" \
      "phpmyadmin/phpmyadmin:4.9" \
      "portainer/portainer:latest" \
      "postgres:11.6" \
      "senzing/adminer:latest" \
      "senzing/apt:latest" \
      "senzing/configurator:latest" \
      "senzing/db2-driver-installer:latest" \
      "senzing/entity-search-web-app:latest" \
      "senzing/g2command:latest" \
      "senzing/g2configtool:latest" \
      "senzing/g2loader:latest" \
      "senzing/ibm-db2:latest" \
      "senzing/init-container:latest" \
      "senzing/jupyter:latest" \
      "senzing/mysql-init:latest" \
      "senzing/mysql:latest" \
      "senzing/phppgadmin:latest" \
      "senzing/python-demo:latest" \
      "senzing/redoer:latest" \
      "senzing/resolver:latest" \
      "senzing/senzing-api-server:latest" \
      "senzing/senzing-base:latest" \
      "senzing/senzing-console:latest" \
      "senzing/senzing-debug:latest" \
      "senzing/senzing-poc-utility:latest" \
      "senzing/sshd:latest" \
      "senzing/stream-loader:latest" \
      "senzing/stream-logger:latest" \
      "senzing/stream-producer:latest" \
      "senzing/xterm:latest" \
      "senzing/yum:latest" \
      "swaggerapi/swagger-ui:latest" \
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
