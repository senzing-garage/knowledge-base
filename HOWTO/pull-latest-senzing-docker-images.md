# How to pull latest Senzing docker images

## Build docker images

1. Build Senzing "helper" Docker images.
   Example:

    ```console
    sudo docker build --tag senzing/mysql        https://github.com/senzing/docker-mysql.git#main
    sudo docker build --tag senzing/mysql-init   https://github.com/senzing/docker-mysql-init.git#main
    ```

## Identify docker images

1. :pencil2: List docker images in DockerHub in an environment variable.
   Example:

    ```console
    export DOCKER_IMAGE_NAMES=( \
      "senzing/adminer:latest" \
      "senzing/apt:latest" \
      "senzing/aptdownloader:latest" \
      "senzing/base-image-centos:latest" \
      "senzing/base-image-debian:latest" \
      "senzing/configurator:latest" \
      "senzing/db2-driver-installer:latest" \
      "senzing/docker-app-senzing-demo:latest" \
      "senzing/docker-app-senzing-install:latest" \
      "senzing/entity-search-web-app:latest" \
      "senzing/g2command:latest" \
      "senzing/g2configtool:latest" \
      "senzing/g2loader:latest" \
      "senzing/ibm-db2:latest" \
      "senzing/init-container:latest" \
      "senzing/jupyter:latest" \
      "senzing/stream-producer:latest" \
      "senzing/mysql-init:latest" \
      "senzing/mysql:latest" \
      "senzing/phppgadmin:latest" \
      "senzing/postgresql-client:latest" \
      "senzing/python-demo:latest" \
      "senzing/redoer:latest" \
      "senzing/resolver:latest" \
      "senzing/senzing-api-server:latest" \
      "senzing/senzing-base:latest" \
      "senzing/senzing-debug:latest" \
      "senzing/senzing-environment:latest" \
      "senzing/senzing-poc-utility:latest" \
      "senzing/stream-loader:latest" \
      "senzing/stream-logger:latest" \
      "senzing/stream-producer:latest" \
      "senzing/web-app-demo-unstable:latest" \
      "senzing/web-app-demo:latest" \
      "senzing/xterm:latest" \
      "senzing/yum:latest" \
      "senzing/yumdownloader:latest" \
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
