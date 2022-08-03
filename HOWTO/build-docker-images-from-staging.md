# How to build Docker images from staging

## Build individually

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

### senzing/senzing-poc-server

1. Build `senzing/senzing-poc-server:staging`.
   Example:

    ```console
    docker pull senzing/senzingapi-runtime:staging

    docker build \
        --build-arg BASE_IMAGE=senzing/senzingapi-runtime:staging \
        --no-cache \
        --tag senzing/senzing-poc-server \
        --tag senzing/senzing-poc-server:staging \
        https://github.com/senzing/senzing-poc-server.git#main
    ```

1. Push to DockerHub.
   Example:

    ```console
    docker push senzing/senzing-poc-server:staging
    ```

### senzing/senzing-console

1. Build `senzing/senzing-console:staging`.
   Example:

    ```console
    docker pull senzing/senzingapi-tools:staging

    docker build \
        --build-arg BASE_IMAGE=senzing/senzingapi-tools:staging \
        --no-cache \
        --tag senzing/senzing-console \
        --tag senzing/senzing-console:staging \
        https://github.com/senzing/docker-senzing-console.git#issue-64.ron.0
    ```

1. Push to DockerHub.
   Example:

    ```console
    docker push senzing/senzing-console:staging
    ```

### senzing/sshd

1. Build `senzing/sshd:staging`.
   Example:

    ```console
    docker pull senzing/senzingapi-tools:staging

    docker build \
        --build-arg BASE_IMAGE=senzing/senzingapi-tools:staging \
        --no-cache \
        --tag senzing/sshd \
        --tag senzing/sshd:staging \
        https://github.com/senzing/docker-sshd.git#issue-76.ron.0
    ```

1. Push to DockerHub.
   Example:

    ```console
    docker push senzing/sshd:staging
    ```

### senzing/entity-search-web-app-console

1. Build `senzing/entity-search-web-app-console:staging`.
   Example:

    ```console
    docker pull senzing/senzingapi-tools:staging

    docker build \
        --build-arg BASE_IMAGE=senzing/senzingapi-tools:staging \
        --no-cache \
        --tag senzing/entity-search-web-app-console \
        --tag senzing/entity-search-web-app-console:staging \
        https://github.com/senzing/entity-search-web-app-console.git#main
    ```

1. Push to DockerHub.
   Example:

    ```console
    docker push senzing/entity-search-web-app-console:staging
    ```

### senzing/xterm

1. Build `senzing/xterm:staging`.
   Example:

    ```console
    docker pull senzing/senzingapi-tools:staging

    docker build \
        --build-arg BASE_IMAGE=senzing/senzingapi-tools:staging \
        --no-cache \
        --tag senzing/xterm \
        --tag senzing/xterm:staging \
        https://github.com/senzing/docker-xterm.git#main
    ```

1. Push to DockerHub.
   Example:

    ```console
    docker push senzing/xterm:staging
    ```

## Build jobs

1. Build all.
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

    docker push senzing/senzingapi-runtime:staging

    docker build \
        --build-arg BASE_IMAGE=senzing/senzingapi-runtime:staging \
        --build-arg SENZING_APT_INSTALL_PACKAGE=senzingapi-tools \
        --build-arg SENZING_APT_REPOSITORY_NAME=senzingstagingrepo_1.0.1-1_amd64.deb \
        --build-arg SENZING_APT_REPOSITORY_URL=https://senzing-staging-apt.s3.amazonaws.com \
        --no-cache \
        --tag senzing/senzingapi-tools \
        --tag senzing/senzingapi-tools:staging \
        https://github.com/senzing/senzingapi-tools.git#main

    docker push senzing/senzingapi-tools:staging

    docker build \
        --build-arg BASE_IMAGE=senzing/senzingapi-runtime:staging \
        --no-cache \
        --tag senzing/stream-loader \
        --tag senzing/stream-loader:staging \
        https://github.com/senzing/stream-loader.git#main

    docker push senzing/stream-loader:staging

    docker build \
        --build-arg BASE_IMAGE=senzing/senzingapi-runtime:staging \
        --no-cache \
        --tag senzing/redoer \
        --tag senzing/redoer:staging \
        https://github.com/senzing/redoer.git#main

    docker push senzing/redoer:staging

    docker build \
        --build-arg BASE_IMAGE=senzing/senzingapi-runtime:staging \
        --no-cache \
        --tag senzing/senzing-api-server \
        --tag senzing/senzing-api-server:staging \
        https://github.com/senzing/senzing-api-server.git#main

    docker push senzing/senzing-api-server:staging

    docker build \
        --build-arg BASE_IMAGE=senzing/senzingapi-runtime:staging \
        --no-cache \
        --tag senzing/senzing-poc-server \
        --tag senzing/senzing-poc-server:staging \
        https://github.com/senzing/senzing-poc-server.git#main

    docker push senzing/senzing-poc-server:staging

    docker build \
        --build-arg BASE_IMAGE=senzing/senzingapi-tools:staging \
        --no-cache \
        --tag senzing/senzing-console \
        --tag senzing/senzing-console:staging \
        https://github.com/senzing/docker-senzing-console.git#main

    docker push senzing/senzing-console:staging

    docker build \
        --build-arg BASE_IMAGE=senzing/senzingapi-tools:staging \
        --no-cache \
        --tag senzing/sshd \
        --tag senzing/sshd:staging \
        https://github.com/senzing/docker-sshd.git#issue-76.ron.0

    docker push senzing/sshd:staging

    docker build \
        --build-arg BASE_IMAGE=senzing/senzingapi-tools:staging \
        --no-cache \
        --tag senzing/entity-search-web-app-console \
        --tag senzing/entity-search-web-app-console:staging \
        https://github.com/senzing/entity-search-web-app-console.git#issue-64.ron.0

    docker push senzing/entity-search-web-app-console:staging

    docker build \
        --build-arg BASE_IMAGE=senzing/senzingapi-tools:staging \
        --no-cache \
        --tag senzing/xterm \
        --tag senzing/xterm:staging \
        https://github.com/senzing/docker-xterm.git#main

    docker push senzing/xterm:staging
    ```
