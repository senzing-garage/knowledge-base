# How to bring up an ELK stack

The following gives steps and an outline on how to bring up an ELK stack for docker-compose stacks.
An existing ELK stack exists in the [docker-compose-demo]
github repository. This page assumes a working knowledge of docker and docker-compose.

## Prerequisites

1. [docker] - minimum version: [20.10.16]
2. [docker-compose] - minimum version: [1.29.0]
3. [elasticsearch] - minimum version: [8.5.3]

### Notes

This example simply shows the containers for the ELK stack in a docker-compose form to be able to connect
with other containers. This example is easily expandable and if the containers to log are brought up with
docker-compose they can be added to the example `yaml` given below or brought up in a separate `yaml`.

If the 'containers to log' are brought up separately from the ELK stack `yaml` then these are the most
important requirements

- The 'containers to log' use the same `NETWORK` as the ELK stack
- `Elasticsearch`, `kibana`, and `logstash`, are not present in any `depends_on` sections
- Each container to log has a logging field (This is also required if the containers are in the same `yaml`). Example:

```yaml
logging:
  driver: gelf
  options:
    gelf-address: "udp://<hostIP>:12201"
    tag: "container-to-log"
```

### Portainer

- A good tool to monitor individual Docker logs is [Portainer]. When running, portainer is viewable at localhost:9170

### 📘 Instructions

1. :pencil2: Specify a new directory to hold demonstration artifacts on the local host.
   Example:

   ```console
   export SENZING_DEMO_DIR=~/my-senzing

   ```

1. Create directory.

   ```console
   mkdir ${SENZING_DEMO_DIR}

   ```

1. Get versions of Docker images.
   Example:

   ```console
   curl -X GET \
       --output ${SENZING_DEMO_DIR}/docker-versions-stable.sh \
       https://raw.githubusercontent.com/Senzing/knowledge-base/main/lists/docker-versions-stable.sh
   source ${SENZING_DEMO_DIR}/docker-versions-stable.sh

   ```

1. Download `docker-compose.yaml` and Docker images.
   Example:

   ```console
   curl -X GET \
       --output ${SENZING_DEMO_DIR}/docker-compose.yaml \
       "https://raw.githubusercontent.com/Senzing/docker-compose-demo/main/resources/custom/docker-compose-ELK.yaml"
   cd ${SENZING_DEMO_DIR}
   sudo --preserve-env docker-compose pull

   ```

### Bring up ELK stack

- Remember that the ELK stack takes a couple of minutes to start up, so ideally do this step before
  bringing up the container you wish to log, the stack is usually fully functional when kibana is viewable;
  during its startup, there will almost always be error logs.
- Make sure you are in the directory with the `yaml` for the ELK stack

  ```console
  sudo --preserve-env docker-compose up

  ```

## View logs

- Give the ELK stack a few minutes to start and then logs are viewable in kibana at localhost:5601.
  Navigate to "Analytics" -> "Discover" to see logs

[1.29.0]: https://docs.docker.com/compose/release-notes/#1290
[8.5.3]: https://www.elastic.co/guide/en/elasticsearch/reference/current/release-highlights.html
[20.10.16]: https://docs.docker.com/engine/release-notes/#201016
[docker]: https://github.com/senzing-garage/knowledge-base/blob/main/WHATIS/docker.md
[docker-compose]: https://github.com/senzing-garage/knowledge-base/blob/main/WHATIS/docker-compose.md
[docker-compose-demo]: https://github.com/senzing-garage/docker-compose-demo/blob/main/resources/postgresql/docker-compose-rabbitmq-postgresql-with-ELK.yaml
[elasticsearch]: https://www.elastic.co/guide/en/elasticsearch/reference/current/install-elasticsearch.html
[Portainer]: https://github.com/senzing-garage/knowledge-base/blob/main/WHATIS/portainer.md
