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
        --tag senzing/senzingapi-runtime:staging \
        https://github.com/senzing-garage/senzingapi-runtime.git#main
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
      --build-arg SENZING_APT_INSTALL_TOOLS_PACKAGE=senzingapi-tools \
      --no-cache \
      --tag senzing/senzingapi-tools:staging \
      https://github.com/senzing-garage/senzingapi-tools.git#main
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
        --tag senzing/stream-loader:staging \
        https://github.com/senzing-garage/stream-loader.git#main
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
        --tag senzing/redoer:staging \
        https://github.com/senzing-garage/redoer.git#main
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
        --tag senzing/senzing-api-server:staging \
        https://github.com/senzing-garage/senzing-api-server.git#main
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
        --tag senzing/senzing-poc-server:staging \
        https://github.com/senzing-garage/senzing-poc-server.git#main
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
        --tag senzing/senzing-console:staging \
        https://github.com/senzing-garage/docker-senzing-console.git#main
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
        --tag senzing/sshd:staging \
        https://github.com/senzing-garage/docker-sshd.git#main
    ```

1. Push to DockerHub.
   Example:

    ```console
    docker push senzing/sshd:staging
    ```

### senzing/xterm

1. Build `senzing/xterm:staging`.
   Example:

    ```console
    docker pull senzing/senzingapi-tools:staging

    docker build \
        --build-arg BASE_IMAGE=senzing/senzingapi-tools:staging \
        --no-cache \
        --tag senzing/xterm:staging \
        https://github.com/senzing-garage/docker-xterm.git#main
    ```

1. Push to DockerHub.
   Example:

    ```console
    docker push senzing/xterm:staging
    ```

### senzing/g2configtool

1. Build `senzing/g2configtool:staging`.
   Example:

    ```console
    docker pull senzing/senzingapi-tools:staging

    docker build \
        --build-arg BASE_IMAGE=senzing/senzingapi-tools:staging \
        --no-cache \
        --tag senzing/g2configtool:staging \
        https://github.com/senzing-garage/g2configtool.git#main
    ```

### senzing/init-postgresql

1. Build `senzing/init-postgresql:staging`.
   Example:

    ```console
    docker pull senzing/senzingapi-runtime:staging

    docker build \
        --build-arg BASE_IMAGE=senzing/senzingapi-runtime:staging \
        --no-cache \
        --tag senzing/init-postgresql:staging \
        https://github.com/senzing-garage/init-postgresql.git#main
    ```

1. Push to DockerHub.
   Example:

    ```console
    docker push senzing/init-postgresql:staging
    ```

### senzing/web-app-demo

1. Build `senzing/web-app-demo:staging`.
   Example:

    ```console
    docker pull senzing/senzingapi-runtime:staging

    docker build \
        --build-arg BASE_IMAGE=senzing/senzingapi-runtime:staging \
        --no-cache \
        --tag senzing/web-app-demo:staging \
        https://github.com/senzing-garage/docker-web-app-demo.git#main
    ```

1. Push to DockerHub.
   Example:

    ```console
    docker push senzing/web-app-demo:staging
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
        --tag senzing/senzingapi-runtime:staging \
        https://github.com/senzing-garage/senzingapi-runtime.git#main

    docker push senzing/senzingapi-runtime:staging

    docker build \
        --build-arg BASE_IMAGE=senzing/senzingapi-runtime:staging \
        --build-arg SENZING_APT_INSTALL_TOOLS_PACKAGE=senzingapi-tools \
        --no-cache \
        --tag senzing/senzingapi-tools:staging \
        https://github.com/senzing-garage/senzingapi-tools.git#main

    docker push senzing/senzingapi-tools:staging

    docker build \
        --build-arg BASE_IMAGE=senzing/senzingapi-runtime:staging \
        --no-cache \
        --tag senzing/stream-loader:staging \
        https://github.com/senzing-garage/stream-loader.git#main

    docker push senzing/stream-loader:staging

    docker build \
        --build-arg BASE_IMAGE=senzing/senzingapi-runtime:staging \
        --no-cache \
        --tag senzing/redoer:staging \
        https://github.com/senzing-garage/redoer.git#main

    docker push senzing/redoer:staging

    docker build \
        --build-arg BASE_IMAGE=senzing/senzingapi-runtime:staging \
        --no-cache \
        --tag senzing/senzing-api-server:staging \
        https://github.com/senzing-garage/senzing-api-server.git#main

    docker push senzing/senzing-api-server:staging

    docker build \
        --build-arg BASE_IMAGE=senzing/senzingapi-runtime:staging \
        --no-cache \
        --tag senzing/senzing-poc-server:staging \
        https://github.com/senzing-garage/senzing-poc-server.git#main

    docker push senzing/senzing-poc-server:staging

    docker build \
        --build-arg BASE_IMAGE=senzing/senzingapi-tools:staging \
        --no-cache \
        --tag senzing/senzing-console:staging \
        https://github.com/senzing-garage/docker-senzing-console.git#main

    docker push senzing/senzing-console:staging

    docker build \
        --build-arg BASE_IMAGE=senzing/senzingapi-tools:staging \
        --no-cache \
        --tag senzing/sshd:staging \
        https://github.com/senzing-garage/docker-sshd.git#main

    docker push senzing/sshd:staging

    docker build \
        --build-arg BASE_IMAGE=senzing/senzingapi-tools:staging \
        --no-cache \
        --tag senzing/entity-search-web-app-console:staging \
        https://github.com/senzing-garage/entity-search-web-app-console.git#main

    docker push senzing/entity-search-web-app-console:staging

    docker build \
        --build-arg BASE_IMAGE=senzing/senzingapi-tools:staging \
        --no-cache \
        --tag senzing/xterm:staging \
        https://github.com/senzing-garage/docker-xterm.git#main

    docker push senzing/xterm:staging

    docker build \
        --build-arg BASE_IMAGE=senzing/senzingapi-tools:staging \
        --no-cache \
        --tag senzing/g2configtool:staging \
        https://github.com/senzing-garage/g2configtool.git#main

    docker push senzing/g2configtool:staging

    docker build \
        --build-arg BASE_IMAGE=senzing/senzingapi-runtime:staging \
        --no-cache \
        --tag senzing/init-postgresql:staging \
        https://github.com/senzing-garage/init-postgresql.git#main

    docker push senzing/init-postgresql:staging

    docker build \
        --build-arg BASE_IMAGE=senzing/senzingapi-runtime:staging \
        --no-cache \
        --tag senzing/web-app-demo:staging \
        https://github.com/senzing-garage/docker-web-app-demo.git#main

    docker push senzing/web-app-demo:staging
    ```
