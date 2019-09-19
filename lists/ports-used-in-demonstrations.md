# Ports used in Demonstrations

This is a list of ports used in docker formations.
The intent is to avoid using reserved ports as specified by
[IANA port assignments](http://www.iana.org/assignments/service-names-port-numbers/service-names-port-numbers.txt).

4380 - 4388
4434-4440
4459-4483
4503-4533
4574-4589
4606-4620
4622-4657
4805-4826
5365-5396

8212-8229
8244-8265


9165-9190


## Reserved

Ports used by existing components for network communication.

1.  **2181** - Zookeeper
1.  **3306** - MySQL
1.  **5432** - PostgreSQL
1.  **5672** - RabbitMQ
1.  **9092** - Kafka
1. **15672** - RabbitMQ
1. **50000** - Db2

## Senzing

Open range: 8244-8265

1. **8245** - [Senzing API server](https://github.com/Senzing/senzing-api-server)
1. **8246** - [Senzing Entity Search Web App](https://github.com/Senzing/entity-search-web-app)

## Other

Open range: 9165-9190

1. **9170** - [Portainer]()
1. **9171** - [phpPgAdmin - http]()
1. **9172** - [phpPgAdmin - https]()
1. **9173** - [phpMyAdmin]()
1. **9174** - [SqliteWeb]()
1. **9175** - [KafkaManager]()
