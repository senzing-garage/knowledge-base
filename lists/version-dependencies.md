# Version dependencies

## Latest versions

1. Find Docker images at
   [hub.docker.com/u/senzing](https://hub.docker.com/u/senzing).

1. Latest versions:
   1. See [latest-versions.sh](latest-versions.sh)

## Repositories

### aws-cloudformation-ecs

1. `Image:` values in `cloudformation.yaml` files in [cloudformation](https://github.com/senzing-garage/aws-cloudformation-ecs/tree/main/cloudformation) folder.

### aws-cloudformation-ecs-poc-simple

1. `Image:` values in [cloudformation.yaml](https://github.com/senzing-garage/aws-cloudformation-ecs-poc-simple/blob/main/cloudformation.yaml)

### charts

1. [charts](https://github.com/senzing-garage/charts/tree/main/charts)`/<chart-name>/<chart-name>/values.yaml` files.

### docker-app-demo

1. `image:` values in [senzing-demo-dockerapp/docker-compose.yml](https://github.com/senzing-garage/docker-app-demo/blob/main/senzing-demo.dockerapp/docker-compose.yml)
1. `image:` values in [senzing-install.dockerapp/docker-compose.yml](https://github.com/senzing-garage/docker-app-demo/blob/main/senzing-install.dockerapp/docker-compose.yml)

### docker-compose-aws-ecscli-demo

1. `docker-compose-xxx.yaml` files in [resources](https://github.com/senzing-garage/docker-compose-aws-ecscli-demo/tree/main/resources) folder.

### docker-compose-demo

1. `docker-compose-xxx.yaml` files in [resources](https://github.com/senzing-garage/docker-compose-demo/tree/main/resources) folder.

### senzing-environment

1. [senzing-environment.py](https://github.com/senzing-garage/senzing-environment/blob/main/senzing-environment.py)

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

1. [senzing-up.sh](https://github.com/senzing-garage/senzing-up/blob/main/senzing-up.sh)

   ```bash
   SENZING_DOCKER_IMAGE_VERSION_G2LOADER=M.m.P
   SENZING_DOCKER_IMAGE_VERSION_INIT_CONTAINER=M.m.P
   SENZING_DOCKER_IMAGE_VERSION_SENZING_DEBUG=M.m.P
   SENZING_DOCKER_IMAGE_VERSION_WEB_APP_DEMO=M.m.P
   SENZING_DOCKER_IMAGE_VERSION_YUM=M.m.P
   ```
