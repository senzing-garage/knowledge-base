# docker-compose-demo tips

The following is a list of tips when using
[docker-compose-demo](https://github.com/Senzing/docker-compose-demo).

## Contents

1. [Kafka](#kafka)
    1. [View Kafka-manager](#view-kafka-manager)
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

## Kafka

### View Kafka-manager

1. Kafka-manager is viewable at
   [localhost:9175](http://localhost:9175).

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
