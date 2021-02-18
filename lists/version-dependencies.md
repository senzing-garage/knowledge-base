# Version dependencies

## Latest versions

1. Find Docker images at
   [hub.docker.com/u/senzing](https://hub.docker.com/u/senzing).

1. Latest versions:

    ```console
    export SENZING_DOCKER_IMAGE_VERSION_ADMINER=1.0.0
    export SENZING_DOCKER_IMAGE_VERSION_APT=1.0.4
    export SENZING_DOCKER_IMAGE_VERSION_DB2_DRIVER_INSTALLER=1.0.2
    export SENZING_DOCKER_IMAGE_VERSION_ENTITY_SEARCH_WEB_APP=2.2.1
    export SENZING_DOCKER_IMAGE_VERSION_ENVIRONMENT=1.2.2
    export SENZING_DOCKER_IMAGE_VERSION_G2COMMAND=1.4.1
    export SENZING_DOCKER_IMAGE_VERSION_G2CONFIGTOOL=1.4.1
    export SENZING_DOCKER_IMAGE_VERSION_G2LOADER=1.4.1
    export SENZING_DOCKER_IMAGE_VERSION_INIT_CONTAINER=1.6.6
    export SENZING_DOCKER_IMAGE_VERSION_JUPYTER=1.2.0
    export SENZING_DOCKER_IMAGE_VERSION_PHPPGADMIN=1.0.0
    export SENZING_DOCKER_IMAGE_VERSION_PORTAINER=latest
    export SENZING_DOCKER_IMAGE_VERSION_POSTGRES=11.6
    export SENZING_DOCKER_IMAGE_VERSION_POSTGRESQL_CLIENT=1.0.0
    export SENZING_DOCKER_IMAGE_VERSION_PYTHON_DEMO=1.4.1
    export SENZING_DOCKER_IMAGE_VERSION_RABBITMQ=3.8.2
    export SENZING_DOCKER_IMAGE_VERSION_REDOER=1.3.4
    export SENZING_DOCKER_IMAGE_VERSION_RESOLVER=1.3.1
    export SENZING_DOCKER_IMAGE_VERSION_SENZING_API_SERVER=2.3.2
    export SENZING_DOCKER_IMAGE_VERSION_SENZING_BASE=1.5.5
    export SENZING_DOCKER_IMAGE_VERSION_SENZING_CONSOLE=1.0.0
    export SENZING_DOCKER_IMAGE_VERSION_SENZING_DEBUG=1.3.5
    export SENZING_DOCKER_IMAGE_VERSION_SQLITE_WEB=latest
    export SENZING_DOCKER_IMAGE_VERSION_SSHD=1.0.3
    export SENZING_DOCKER_IMAGE_VERSION_STREAM_LOADER=1.7.1
    export SENZING_DOCKER_IMAGE_VERSION_STREAM_LOGGER=1.1.2
    export SENZING_DOCKER_IMAGE_VERSION_STREAM_PRODUCER=1.3.3
    export SENZING_DOCKER_IMAGE_VERSION_SWAGGERAPI_SWAGGER_UI=latest
    export SENZING_DOCKER_IMAGE_VERSION_WEB_APP_DEMO=2.1.1
    export SENZING_DOCKER_IMAGE_VERSION_XTERM=1.0.5
    export SENZING_DOCKER_IMAGE_VERSION_YUM=1.1.4
    ```

## Repositories

### aws-cloudformation-ecs

1. `Image:` values in `cloudformation.yaml` files in [cloudformation](https://github.com/Senzing/aws-cloudformation-ecs/tree/main/cloudformation) folder.

### aws-cloudformation-ecs-poc-simple

1. `Image:` values in [cloudformation.yaml](https://github.com/Senzing/aws-cloudformation-ecs-poc-simple/blob/main/cloudformation.yaml)

### charts

1. [charts](https://github.com/Senzing/charts/tree/master/charts)`/<chart-name>/<chart-name>/values.yaml` files.

### docker-app-demo

1. `image:` values in [senzing-demo-dockerapp/docker-compose.yml](https://github.com/Senzing/docker-app-demo/blob/master/senzing-demo.dockerapp/docker-compose.yml)
1. `image:` values in [senzing-install.dockerapp/docker-compose.yml](https://github.com/Senzing/docker-app-demo/blob/master/senzing-install.dockerapp/docker-compose.yml)

### docker-compose-aws-ecscli-demo

1. `docker-compose-xxx.yaml` files in [resources](https://github.com/Senzing/docker-compose-aws-ecscli-demo/tree/master/resources) folder.

### docker-compose-demo

1. `docker-compose-xxx.yaml` files in [resources](https://github.com/Senzing/docker-compose-demo/tree/master/resources) folder.

### senzing-environment

1. [senzing-environment.py](https://github.com/Senzing/senzing-environment/blob/master/senzing-environment.py)

    ```bash
    export SENZING_DOCKER_IMAGE_VERSION_APT=M.m.P
    export SENZING_DOCKER_IMAGE_VERSION_DB2_DRIVER_INSTALLER=M.m.P
    export SENZING_DOCKER_IMAGE_VERSION_ENTITY_SEARCH_WEB_APP=M.m.P
    export SENZING_DOCKER_IMAGE_VERSION_INIT_CONTAINER=M.m.P
    export SENZING_DOCKER_IMAGE_VERSION_JUPYTER=M.m.P
    export SENZING_DOCKER_IMAGE_VERSION_PHPPGADMIN=1.0.0
    export SENZING_DOCKER_IMAGE_VERSION_PORTAINER=latest
    export SENZING_DOCKER_IMAGE_VERSION_POSTGRES=11.6
    export SENZING_DOCKER_IMAGE_VERSION_POSTGRESQL_CLIENT=1.0.0
    export SENZING_DOCKER_IMAGE_VERSION_RABBITMQ=3.8.2
    export SENZING_DOCKER_IMAGE_VERSION_SENZING_API_SERVER=M.m.P
    export SENZING_DOCKER_IMAGE_VERSION_SENZING_CONSOLE=M.m.P
    export SENZING_DOCKER_IMAGE_VERSION_SENZING_DEBUG=M.m.P
    export SENZING_DOCKER_IMAGE_VERSION_SQLITE_WEB=M.m.P
    export SENZING_DOCKER_IMAGE_VERSION_STREAM_LOADER=M.m.P
    export SENZING_DOCKER_IMAGE_VERSION_STREAM_PRODUCER=M.m.P
    export SENZING_DOCKER_IMAGE_VERSION_SWAGGERAPI_SWAGGER_UI=latest
    export SENZING_DOCKER_IMAGE_VERSION_WEB_APP_DEMO=M.m.P
    export SENZING_DOCKER_IMAGE_VERSION_XTERM=M.m.P
    export SENZING_DOCKER_IMAGE_VERSION_YUM=M.m.P
    ```

### senzing-up

1. [senzing-up.sh](https://github.com/Senzing/senzing-up/blob/master/senzing-up.sh)

    ```bash
    SENZING_DOCKER_IMAGE_VERSION_G2LOADER=M.m.P
    SENZING_DOCKER_IMAGE_VERSION_INIT_CONTAINER=M.m.P
    SENZING_DOCKER_IMAGE_VERSION_SENZING_DEBUG=M.m.P
    SENZING_DOCKER_IMAGE_VERSION_WEB_APP_DEMO=M.m.P
    SENZING_DOCKER_IMAGE_VERSION_YUM=M.m.P
    ```
