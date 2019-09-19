# Ports used in Demonstrations

This is a list of ports used in docker formations.
The intent is to avoid using reserved ports as specified by
[IANA's Service Name and Transport Protocol Port Number Registry](http://www.iana.org/assignments/service-names-port-numbers/service-names-port-numbers.txt).
Also avoiding collisions with the list on [Wikipedia](https://en.wikipedia.org/wiki/List_of_TCP_and_UDP_port_numbers).

## Reserved

Ports used by existing components for network communication.

1. **2181** - Zookeeper
1. **3306** - MySQL
1. **5432** - PostgreSQL
1. **5672** - RabbitMQ
1. **9092** - Kafka
1. **15672** - RabbitMQ
1. **50000** - Db2

## Senzing

Open range: 8250-8265

1. **8250** - [Senzing API server](https://github.com/Senzing/senzing-api-server)
1. **8251** - [Senzing Entity Search Web App](https://github.com/Senzing/entity-search-web-app)

## Other

Open range: 9165-9190

1. **9170** - [Portainer](https://www.portainer.io/)
1. **9171** - [phpPgAdmin - http](http://phppgadmin.sourceforge.net/doku.php)
1. **9172** - [phpPgAdmin - https](http://phppgadmin.sourceforge.net/doku.php)
1. **9173** - [phpMyAdmin](https://www.phpmyadmin.net/)
1. **9174** - [SqliteWeb](https://github.com/coleifer/sqlite-web)
1. **9175** - [Kafka Manager](https://github.com/yahoo/kafka-manager)
