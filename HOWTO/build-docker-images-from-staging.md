# How to build Docker images from staging

## Build locally and push to DockerHub

### senzing/senzingapi-runtime

1. Build `senzing/senzingapi-runtime:staging`.
   Example:

    ```console
    docker build \
        --build-arg SENZING_APT_INSTALL_PACKAGE=senzingapi-runtime \
        --build-arg SENZING_APT_REPOSITORY_NAME=senzingstagingrepo_1.0.1-1_amd64.deb \
        --build-arg SENZING_APT_REPOSITORY_URL=https://senzing-staging-apt.s3.amazonaws.com \
        --no-cache \
        --tag senzing/senzingapi-runtime \
        --tag senzing/senzingapi-runtime:staging \
        https://github.com/senzing/senzingapi-runtime.git#main
    ```

1. Push to DockerHub.
   Example:

    ```console
    docker push senzing/senzingapi-runtime:staging
    ```

### senzing/senzingapi-tools

1. Build `senzing/senzingapi-tools:staging`.
   Example:

    ```console
    docker pull senzing/senzingapi-runtime:staging

    docker build \
        --build-arg BASE_IMAGE=senzing/senzingapi-runtime:staging \
        --build-arg SENZING_APT_INSTALL_PACKAGE=senzingapi-tools \
        --build-arg SENZING_APT_REPOSITORY_NAME=senzingstagingrepo_1.0.1-1_amd64.deb \
        --build-arg SENZING_APT_REPOSITORY_URL=https://senzing-staging-apt.s3.amazonaws.com \
        --no-cache \
        --tag senzing/senzingapi-tools \
        --tag senzing/senzingapi-tools:staging \
        https://github.com/senzing/senzingapi-tools.git#main
    ```

1. Push to DockerHub.
   Example:

    ```console
    docker push senzing/senzingapi-tools:staging
    ```

### senzing/stream-loader

1. Build `senzing/stream-loader:staging`.
   Example:

    ```console
    docker pull senzing/senzingapi-runtime:staging

    docker build \
        --build-arg BASE_IMAGE=senzing/senzingapi-runtime:staging \
        --no-cache \
        --tag senzing/stream-loader \
        --tag senzing/stream-loader:staging \
        https://github.com/senzing/stream-loader.git#main
    ```

1. Push to DockerHub.
   Example:

    ```console
    docker push senzing/stream-loader:staging
    ```

### senzing/redoer

1. Build `senzing/redoer:staging`.
   Example:

    ```console
    docker pull senzing/senzingapi-runtime:staging

    docker build \
        --build-arg BASE_IMAGE=senzing/senzingapi-runtime:staging \
        --no-cache \
        --tag senzing/redoer \
        --tag senzing/redoer:staging \
        https://github.com/senzing/redoer.git#main
    ```

1. Push to DockerHub.
   Example:

    ```console
    docker push senzing/redoer:staging
    ```

### senzing/senzing-api-server

1. Build `senzing/senzing-api-server:staging`.
   Example:

    ```console
    docker pull senzing/senzingapi-runtime:staging

    docker build \
        --build-arg BASE_IMAGE=senzing/senzingapi-runtime:staging \
        --no-cache \
        --tag senzing/senzing-api-server \
        --tag senzing/senzing-api-server:staging \
        https://github.com/senzing/senzing-api-server.git#main
    ```

1. Push to DockerHub.
   Example:

    ```console
    docker push senzing/senzing-api-server:staging
    ```

### senzing/senzing-console

### senzing/sshd

### senzing/entity-search-web-app-console

### senzing/xterm
