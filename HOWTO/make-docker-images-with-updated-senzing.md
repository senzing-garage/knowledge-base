# How to make Docker images with updated Senzing

## Preparation

1. Verify version name.
    1. Senzing version: `M.m.P-?????`

## Update Docker images on Docker Hub

### Update Docker images on Docker Hub  - Phase 1

1. Find updated version of `debian` Docker image.
1. Update `properties` in
   [update-dockerfiles-step-1-example.json](https://github.com/Senzing/github-util/blob/main/update-dockerfiles-step-1-example.json)
1. Create Pull Requests by running:

    ```console
    export GITHUB_ACCESS_TOKEN=ghp_....................................
    github-util.py update-dockerfiles --configuration-file update-dockerfiles-step-1-example.json
    ```

1. Review and accept Pull requests generated.
1. Update `senzingapi-runtime` version in `senzing/senzingapi-runtime`
   [Dockerfile](https://github.com/Senzing/senzingapi-runtime/blob/main/Dockerfile)
1. Create versioned releases (including changes to Dockerfile and CHANGELOG.md) of
    1. [senzing/senzingapi-runtime](https://github.com/Senzing/senzingapi-runtime)
    1. [senzing/docker-senzing-base](https://github.com/Senzing/docker-senzing-base)
    1. [senzing/docker-base-image-debian](https://github.com/Senzing/docker-base-image-debian)

### Update Docker images on Docker Hub - Phase 2

1. Find updated version of `senzing/senzingapi-runtime` Docker image.
1. Update `properties` in
   [update-dockerfiles-step-2-example.json](https://github.com/Senzing/github-util/blob/main/update-dockerfiles-step-2-example.json)
1. Create Pull Requests by running:

    ```console
    export GITHUB_ACCESS_TOKEN=ghp_....................................
    github-util.py update-dockerfiles --configuration-file update-dockerfiles-step-2-example.json
    ```

1. Review and accept Pull requests generated.
1. Update `senzingapi-tools` version in `senzing/senzingapi-tools`
   [Dockerfile](https://github.com/Senzing/senzingapi-tools/blob/main/Dockerfile)
1. Create versioned releases (including changes to Dockerfile and CHANGELOG.md) of
    1. [senzing/senzingapi-tools](https://github.com/Senzing/senzingapi-tools)

### Update Docker images on Docker Hub - Phase 3

1. Find updated versions of
   `alpine`,
   `amazonlinux`,
   `busybox`,
   `debian`,
   `ibmcom/db2`,
   `jupyter minimal-notebook`,
   `lambda/python`,
   `node`,
   `senzing/senzing-base`
   `senzing/senzingapi-runtime`,
   `senzing/senzingapi-tools`
    Docker images.
1. Update `properties` in
   [update-dockerfiles-step-3-example.json](https://github.com/Senzing/github-util/blob/main/update-dockerfiles-step-3-example.json)
1. Create Pull Requests by running:

    ```console
    export GITHUB_ACCESS_TOKEN=ghp_....................................
    github-util.py update-dockerfiles --configuration-file update-dockerfiles-step-3-example.json
    ```

1. Review and accept Pull requests generated.
1. Once `:latest` versions are available on DockerHub,
   run a small test similar to
   [docker-compose-rabbitmq-postgresql](https://github.com/Senzing/docker-compose-demo/blob/main/docs/docker-compose-rabbitmq-postgresql/README.md#demonstrate), but with `:latest` versions.
   Example:

    ```console
    export SENZING_VOLUME=~/my-senzing
    export PGADMIN_DIR=${SENZING_VOLUME}/pgadmin
    export POSTGRES_DIR=${SENZING_VOLUME}/postgres
    export RABBITMQ_DIR=${SENZING_VOLUME}/rabbitmq
    export SENZING_VAR_DIR=${SENZING_VOLUME}/var
    export SENZING_UID=$(id -u)
    export SENZING_GID=$(id -g)
    mkdir -p ${PGADMIN_DIR} ${POSTGRES_DIR} ${RABBITMQ_DIR} ${SENZING_VAR_DIR}
    chmod -R 777 ${SENZING_VOLUME}
    curl -X GET \
        --output ${SENZING_VOLUME}/docker-compose.yaml \
        "https://raw.githubusercontent.com/Senzing/docker-compose-demo/main/resources/postgresql/docker-compose-rabbitmq-postgresql.yaml"
    cd ${SENZING_VOLUME}
    sudo --preserve-env docker-compose pull
    sudo --preserve-env docker-compose up

    ```

1. Create versioned releases (including changes to Dockerfile and CHANGELOG.md) of
    1. [senzing/docker-senzing-console](https://github.com/Senzing/docker-senzing-console)
    1. [senzing/docker-sshd](https://github.com/Senzing/docker-sshd)
    1. [senzing/docker-web-app-demo](https://github.com/Senzing/docker-web-app-demo)
    1. [senzing/docker-xterm](https://github.com/Senzing/docker-xterm)
    1. [senzing/entity-search-web-app-console](https://github.com/Senzing/entity-search-web-app-console)
    1. [senzing/entity-search-web-app](https://github.com/Senzing/entity-search-web-app)
    1. [senzing/init-postgresql](https://github.com/Senzing/init-postgresql)
    1. [senzing/redoer](https://github.com/Senzing/redoer)
    1. [senzing/senzing-poc-server](https://github.com/Senzing/senzing-poc-server)
    1. [senzing/stream-loader](https://github.com/Senzing/stream-loader)
    1. [senzing/stream-producer](https://github.com/Senzing/stream-producer)
1. Create versioned releases (including changes to Dockerfile and CHANGELOG.md) of the repositories
   listed in the `repositories` section of
   [update-dockerfiles-step-3-example.json](https://github.com/Senzing/github-util/blob/main/update-dockerfiles-step-3-example.json).

## Update Docker images on AWS Elastic Container Registry

1. ...
