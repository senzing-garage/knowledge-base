# docker-compose-demo tips

The following is a list of tips when using
[docker-compose-demo](https://github.com/Senzing/docker-compose-demo).

## Contents

1. [Kafka(#kafka)
    1. [Send to Kafka topic](#send-to-kafka-topic)
    1. [Read Kafka topic](#read-kafka-topic)
    1. [Kafka references](#kafka-references)

## Kafka

### Send to Kafka topic

1. Enter "senzing-kafka" container.
   Example:

    ```console
    sudo docker exec -it senzing-kafka /bin/bash
    ```

1. Inside "senzing-kafka" container, run "kafka-local-producer.sh".
   Example:

    ```console
    /opt/bitnami/kafka/bin/kafka-console-producer.sh \
      --broker-list localhost:9092 \
      --topic senzing-kafka-topic
    ```

1. Enter lines of JSON.
   Each line is a Kafka message.

### Read Kafka topic

1. Enter "senzing-kafka" container.
   Example:

    ```console
    sudo docker exec -it senzing-kafka /bin/bash
    ```

1. Inside "senzing-kafka" container, run "kafka-local-consumer.sh".
   Example:

    ```console
    /opt/bitnami/kafka/bin/kafka-console-consumer.sh \
      --bootstrap-server localhost:9092 \
      --topic senzing-kafka-topic \
      --from-beginning
    ```

### Kafka references

1. [Quickstart](https://kafka.apache.org/quickstart)
