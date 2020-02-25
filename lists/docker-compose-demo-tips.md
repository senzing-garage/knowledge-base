# docker-compose-demo tips

The following is a list of tips when using
[docker-compose-demo](https://github.com/Senzing/docker-compose-demo).

## Contents

1. [Senzing license](#senzing-license)
    1. [Request Senzing license](#request-senzing-license)
    1. [Install Senzing license](#install-senzing-license)
1. [Kafka](#kafka)
    1. [View Kafdrop](#view-kafdrop)
    1. [Send messages to Kafka topic](#send-messages-to-kafka-topic)
    1. [Read messages from Kafka topic](#read-messages-from-kafka-topic)
    1. [Kafka references](#kafka-references)
1. [Senzing API server](#senzing-api-server)
    1. [Senzing API server via web browser](#senzing-api-server-via-web-browser)
    1. [Senzing API server via curl](#senzing-api-server-via-curl)
    1. [Senzing API server via Swagger editor](#senzing-api-server-via-swagger-editor)
1. [Senzing Entity Search WebApp](#senzing-entity-search-webapp)
    1. [View Senzing Entity Search WebApp](#view-senzing-entity-search-webapp)
    1. [Senzing Entity Search WebApp demo](#senzing-entity-search-webapp-demo)

## Senzing license

### Request Senzing license

1. If working with more than 10,000 records,
   [obtain a Senzing license](https://github.com/Senzing/knowledge-base/blob/master/HOWTO/obtain-senzing-license.md).

### Install Senzing license

1. :pencil2: Identify location of `g2.lic` on local workstation.
   Example:

    ```console
    export G2_LICENSE_PATH=/path/to/local/g2.lic
    ```

1. Copy license to volume.
   Example:

    ```console
    sudo cp ${G2_LICENSE_PATH} ${SENZING_ETC_DIR}/g2.lic
    ```

## Kafka

### View Kafdrop

1. Kafdrop is viewable at
   [localhost:9179](http://localhost:9179).

1. References:
    1. [Kafdrop - An Open-Source Kafka Web UI](https://dev.to/ekoutanov/kafdrop-an-open-source-kafka-web-ui-mbn)
    1. [GitHub](https://github.com/obsidiandynamics/kafdrop)

### Send messages to Kafka topic

1. Enter "senzing-kafka" container.
   Example:

    ```console
    sudo docker exec -it senzing-kafka /bin/bash
    ```

1. Inside "senzing-kafka" container, run `kafka-local-producer.sh`.
   Example:

    ```console
    /opt/bitnami/kafka/bin/kafka-console-producer.sh \
      --broker-list localhost:9092 \
      --topic senzing-kafka-topic
    ```

1. Enter lines of JSON.
   Each line is a Kafka message.

### Read messages from Kafka topic

1. Enter "senzing-kafka" container.
   Example:

    ```console
    sudo docker exec -it senzing-kafka /bin/bash
    ```

1. Inside "senzing-kafka" container, run `kafka-local-consumer.sh`.
   Example:

    ```console
    /opt/bitnami/kafka/bin/kafka-console-consumer.sh \
      --bootstrap-server localhost:9092 \
      --topic senzing-kafka-topic \
      --from-beginning
    ```

### Kafka references

1. [Quickstart](https://kafka.apache.org/quickstart)

## Senzing API server

The Senzing REST API server supports the
[Senzing REST API](https://github.com/Senzing/senzing-rest-api).

### Senzing API server via web browser

1. From a web browser.
   Examples:
    1. [localhost:8250/heartbeat](http://localhost:8250/heartbeat)
    1. [localhost:8250/license](http://localhost:8250/license)
    1. [localhost:8250/entities/1](http://localhost:8250/entities/1)

### Senzing API server via curl

1. From `curl`.
   Examples:

    ```console
    export SENZING_API_SERVICE=http://localhost:8250

    curl -X GET ${SENZING_API_SERVICE}/heartbeat
    curl -X GET ${SENZING_API_SERVICE}/license
    curl -X GET ${SENZING_API_SERVICE}/entities/1
    ```

### Senzing API server via Swagger editor

1. From [OpenApi "Swagger" editor](http://editor.swagger.io/?url=https://raw.githubusercontent.com/Senzing/senzing-rest-api/master/senzing-rest-api.yaml).

## Senzing Entity Search WebApp

### View Senzing Entity Search WebApp

1. Senzing Entity Search WebApp is viewable at
   [localhost:8251](http://localhost:8251).
    1. Example entity:
       [localhost:8251/entity/1](http://localhost:8251/entity/1).

### Senzing Entity Search WebApp demo

1. The [demonstration](https://github.com/Senzing/knowledge-base/blob/master/demonstrations/docker-compose-web-app.md)
   instructions will give a tour of the Senzing web app.
