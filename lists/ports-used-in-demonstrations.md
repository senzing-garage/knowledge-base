# Ports used in Demonstrations

This is a list of ports used in docker formations.
The intent is to avoid using reserved ports as specified by
[IANA's Service Name and Transport Protocol Port Number Registry](http://www.iana.org/assignments/service-names-port-numbers/service-names-port-numbers.txt).
Also avoiding collisions with the list on [Wikipedia](https://en.wikipedia.org/wiki/List_of_TCP_and_UDP_port_numbers).

## Reserved

Ports used by existing components for network communication.

### 2181

- Zookeeper

### 3306

- MySQL

### 5432

- PostgreSQL

### 5672

- RabbitMQ

### 9092

- Kafka

### 15672

- RabbitMQ

### 50000

- Db2

## Senzing

Open range: 8250-8265

### 8250

- [Senzing API server](https://github.com/Senzing/senzing-api-server)

### 8251

- [Senzing Entity Search Web App](https://github.com/Senzing/entity-search-web-app)

## Other

Open range: 9165-9190

### 9170

- [Portainer](https://www.portainer.io/)

### 9171

- [phpPgAdmin - http](http://phppgadmin.sourceforge.net/doku.php)

### 9172

- [phpPgAdmin - https](http://phppgadmin.sourceforge.net/doku.php)

### 9173

- [phpMyAdmin](https://www.phpmyadmin.net/)

### 9174

- [SqliteWeb](https://github.com/coleifer/sqlite-web)

### 9175

- [Kafka Manager](https://github.com/yahoo/kafka-manager)

### 9176

- [Jenkins Blue Ocean](https://github.com/Senzing/knowledge-base/blob/master/WHATIS/jenkins-blue-ocean.md)
