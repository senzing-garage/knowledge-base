# Senzing Product IDs

Used in log message identifiers in the format `senzing-ppppnnnnt`, where:

- "p" is the 4 digit product identifier
- "n" is the 4 digit message identifier within product
- "t" is the 1 character message type: Info, Warn, Error

## Senzing components

1. **5001** - [stream-loader.py](https://github.com/Senzing/stream-loader/blob/main/stream-loader.py)
1. **5002** - [mock-data-generator.py](https://github.com/Senzing/mock-data-generator/blob/main/mock-data-generator.py)
1. **5003** - [senzing-package.py](https://github.com/Senzing/senzing-package/blob/main/senzing-package.py)
1. **5004** - [stream-configuration.py](https://github.com/Senzing/stream-configuration/blob/main/stream-configuration.py)
1. **5005** - [g2-configuration-initializer.py](https://github.com/Senzing/g2-configuration-initializer/blob/main/g2-configuration-initializer.py)
1. **5006** - [resolver.py](https://github.com/Senzing/resolver/blob/main/resolver.py)
1. **5007** - [init-container.py](https://github.com/Senzing/docker-init-container/blob/main/init-container.py)
1. **5008** - [db2-driver-installer.py](https://github.com/Senzing/docker-db2-driver-installer/blob/main/db2-driver-installer.py)
1. **5009** - [configurator.py](https://github.com/Senzing/configurator/blob/main/configurator.py)
1. **5010** - [redoer.py](https://github.com/Senzing/redoer/blob/main/redoer.py)
1. **5011** - [stream-logger.py](https://github.com/Senzing/stream-logger/blob/main/stream-logger.py)
1. **5012** - [github-util.py](https://github.com/Senzing/github-util/blob/main/github-util.py)
1. **5014** - [stream-producer.py](https://github.com/Senzing/stream-producer/blob/main/stream-producer.py)
1. **5015** - [senzing-environment.py](https://github.com/Senzing/stream-producer/blob/main/senzing-environment.py)
1. **5016** - [awesome.py](https://github.com/Senzing/awesome/blob/main/awesome.py)
1. **5017** - [senzing_governor.py](https://github.com/Senzing/governor-postgresql-transaction-id/blob/main/senzing_governor.py) for PostgreSQL Transaction ID management
1. **5018** - [dockerhub-util.py](https://github.com/Senzing/dockerhub-util/blob/main/dockerhub-util.py)
1. **5019** - [self_signed_certificates.py](https://github.com/Senzing/aws-lambda-self-signed-certificates/blob/main/self_signed_certificates.py)
1. **5020** - [senzing_accountant.py](https://github.com/Senzing/accountant-aws-marketplace)
1. **5021** - [accountant-aws-marketplace.py](https://github.com/Senzing/accountant-aws-marketplace)
1. **5022** - [cognito_authorizer.py](https://github.com/Senzing/aws-lambda-cognito-authorizer/blob/main/cognito_authorizer.py)
1. **5023** - [git-submodule-versions.py](https://github.com/Senzing/g2-python/blob/main/bin/github-submodule-versions.py)
1. **5024** - [docker-xterm](https://github.com/Senzing/docker-xterm)
1. **5025** - [senzing-api-server](https://github.com/Senzing/senzing-api-server)
1. **5026** - [senzing-poc-server](https://github.com/Senzing/senzing-poc-server)
1. **5027** - [G2Engine](https://github.com/Senzing/g2engine)
1. **5028** - [docker-compose-air-gapper](https://github.com/Senzing/docker-compose-air-gapper)
1. **5029** - [ready-for-senzing](https://github.com/Senzing/ready-for-senzing)
1. **5030** - [init-postgresql](https://github.com/Senzing/init-postgresql)
1. **5031** - [init-mysql](https://github.com/Senzing/init-mysql)
1. **5032** - [keystore-generator](https://github.com/Senzing/keystore-generator)
1. **5032** - [init-mssql](https://github.com/Senzing/init-mssql)

## Go SDK and apps

### SDK
1. **6001** - github.com/senzing/g2-sdk-go/g2config
1. **6002** - github.com/senzing/g2-sdk-go/g2configmgr
1. **6003** - github.com/senzing/g2-sdk-go/g2diagnostic
1. **6004** - github.com/senzing/g2-sdk-go/g2engine
1. **6005** - github.com/senzing/g2-sdk-go/g2hasher
1. **6006** - github.com/senzing/g2-sdk-go/g2product
1. **6007** - github.com/senzing/g2-sdk-go/g2ssadm
1. **6008** - github.com/senzing/g2-sdk-go/test
1. **6009** - github.com/senzing/g2-sdk-go/testhelpers
1. **6011** - github.com/senzing/servegrpc/g2configserver
1. **6012** - github.com/senzing/servegrpc/g2configmgrserver
1. **6013** - github.com/senzing/servegrpc/g2diagnosticserver
1. **6014** - github.com/senzing/servegrpc/g2engineserver
1. **6015** - github.com/senzing/servegrpc/g2hasherserver
1. **6016** - github.com/senzing/servegrpc/g2productserver
1. **6017** - github.com/senzing/servegrpc/g2ssadmserver
1. **6021** - github.com/senzing/g2-sdk-go-grpc/2configclient
1. **6022** - github.com/senzing/g2-sdk-go-grpc/g2configmgrclient
1. **6023** - github.com/senzing/g2-sdk-go-grpc/g2diagnosticclient
1. **6024** - github.com/senzing/g2-sdk-go-grpc/g2engineclient
1. **6025** - github.com/senzing/g2-sdk-go-grpc/g2hasherclient
1. **6026** - github.com/senzing/g2-sdk-go-grpc/g2productclient
1. **6027** - github.com/senzing/g2-sdk-go-grpc/g2ssadmclient
1. **6030** - github.com/senzing/go-sdk-abstract-factory/factory


### senzing-tools

1. **6100** - github.com/senzing/senzing-tools/...

### Components for senzing-tools

1. **6201** - github.com/senzing/load
1. **6202** - github.com/senzing/move
1. **6203** - github.com/senzing/validate
1. **6204** - github.com/senzing/servegrpc

