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
      x"arey/mysql-client:latest" \
      x"bitnami/kafka:2.4.0" \
      x"bitnami/phpmyadmin:4.8.5" \
      x"bitnami/postgresql:11.6.0" \
      x"bitnami/rabbitmq:3.8.2" \
      x"bitnami/zookeeper:3.5.6" \
      x"coleifer/sqlite-web:latest" \
      x"confluentinc/cp-kafka:4.0.1-1" \
      x"dockage/phppgadmin:latest" \
      x"ibmcom/db2:11.5.0.0a" \
      x"jbergknoff/postgresql-client:latest" \
      x"kafkamanager/kafka-manager:2.0.0.2" \
      x"mysql:5.7" \
      x"obsidiandynamics/kafdrop:3.23.0" \
      x"phpmyadmin/phpmyadmin:4.9" \
      x"postgres:11.6" \
      x"senzing/apt:latest" \
      x"senzing/configurator:latest" \
      x"senzing/db2-driver-installer:latest" \
      x"senzing/entity-search-web-app:latest" \
      x"senzing/g2command:latest" \
      x"senzing/g2configtool:latest" \
      x"senzing/g2loader:latest" \
      x"senzing/ibm-db2:latest" \
      x"senzing/init-container:latest" \
      x"senzing/jupyter:latest" \
      x"senzing/stream-producer:latest" \
      x"senzing/mysql:latest" \
      x"senzing/mysql-init:latest" \
      x"senzing/phppgadmin:latest" \
      x"senzing/python-demo:latest" \
      x"senzing/redoer:latest" \
      x"senzing/senzing-api-server:latest" \
      x"senzing/senzing-base:latest" \
      x"senzing/senzing-debug:latest" \
      x"senzing/senzing-poc-utility:latest" \
      x"senzing/stream-loader:latest" \
      x"senzing/stream-logger:latest" \
      x"senzing/yum:latest" \
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
