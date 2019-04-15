# Senzing Product IDs

Used in log message identifiers in the format `senzing-ppppnnnnt`, where:

- "p" is the 4 digit product identifier
- "n" is the 4 digit message identifier within product
- "t" is the 1 character message type: Info, Warn, Error

## Python scripts

1. **5001** - [stream-loader.py](https://github.com/Senzing/stream-loader/blob/master/stream-loader.py)
1. **5002** - [mock-data-generator.py](https://github.com/Senzing/mock-data-generator/blob/master/mock-data-generator.py)
1. **5003** - [senzing-package.py](https://github.com/Senzing/senzing-package/blob/master/senzing-package.py)
1. **5004** - [docker-entrypoint.py](https://github.com/Senzing/docker-senzing-base/blob/master/rootfs/app/docker-entrypoint.py)

## Docker apps

1. **6001** - [senzing/python-flask-rest-api](https://github.com/Senzing/docker-python-flask-rest-api)
