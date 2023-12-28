# Senzing Component IDs

Used in log message identifiers in the format `senzing-ppppnnnnt`, where:

- "p" is the 4 digit product identifier
- "n" is the 4 digit message identifier within product
- "t" is the 1 character message type: Info, Warn, Error

## Senzing components

1. **5001** - [stream-loader.py](https://github.com/senzing-garage/stream-loader/blob/main/stream-loader.py)
1. **5002** - [mock-data-generator.py](https://github.com/senzing-garage/mock-data-generator/blob/main/mock-data-generator.py)
1. **5003** - [senzing-package.py](https://github.com/senzing-garage/senzing-package/blob/main/senzing-package.py)
1. **5004** - [stream-configuration.py](https://github.com/senzing-garage/stream-configuration/blob/main/stream-configuration.py)
1. **5005** - [g2-configuration-initializer.py](https://github.com/senzing-garage/g2-configuration-initializer/blob/main/g2-configuration-initializer.py)
1. **5006** - [resolver.py](https://github.com/senzing-garage/resolver/blob/main/resolver.py)
1. **5007** - [init-container.py](https://github.com/senzing-garage/docker-init-container/blob/main/init-container.py)
1. **5008** - [db2-driver-installer.py](https://github.com/senzing-garage/docker-db2-driver-installer/blob/main/db2-driver-installer.py)
1. **5009** - [configurator.py](https://github.com/senzing-garage/configurator/blob/main/configurator.py)
1. **5010** - [redoer.py](https://github.com/senzing-garage/redoer/blob/main/redoer.py)
1. **5011** - [stream-logger.py](https://github.com/senzing-garage/stream-logger/blob/main/stream-logger.py)
1. **5012** - [github-util.py](https://github.com/senzing-garage/github-util/blob/main/github-util.py)
1. **5014** - [stream-producer.py](https://github.com/senzing-garage/stream-producer/blob/main/stream-producer.py)
1. **5015** - [senzing-environment.py](https://github.com/senzing-garage/stream-producer/blob/main/senzing-environment.py)
1. **5016** - [awesome.py](https://github.com/senzing-garage/awesome/blob/main/awesome.py)
1. **5017** - [senzing_governor.py](https://github.com/senzing-garage/governor-postgresql-transaction-id/blob/main/senzing_governor.py) for PostgreSQL Transaction ID management
1. **5018** - [dockerhub-util.py](https://github.com/senzing-garage/dockerhub-util/blob/main/dockerhub-util.py)
1. **5019** - [self_signed_certificates.py](https://github.com/senzing-garage/aws-lambda-self-signed-certificates/blob/main/self_signed_certificates.py)
1. **5020** - [senzing_accountant.py](https://github.com/senzing-garage/accountant-aws-marketplace)
1. **5021** - [accountant-aws-marketplace.py](https://github.com/senzing-garage/accountant-aws-marketplace)
1. **5022** - [cognito_authorizer.py](https://github.com/senzing-garage/aws-lambda-cognito-authorizer/blob/main/cognito_authorizer.py)
1. **5023** - [git-submodule-versions.py](https://github.com/senzing-garage/g2-python/blob/main/bin/github-submodule-versions.py)
1. **5024** - [docker-xterm](https://github.com/senzing-garage/docker-xterm)
1. **5025** - [senzing-api-server](https://github.com/senzing-garage/senzing-api-server)
1. **5026** - [senzing-poc-server](https://github.com/senzing-garage/senzing-poc-server)
1. **5027** - G2Engine - migrated to 5043
1. **5028** - [docker-compose-air-gapper](https://github.com/senzing-garage/docker-compose-air-gapper)
1. **5029** - [ready-for-senzing](https://github.com/senzing-garage/ready-for-senzing)
1. **5030** - [init-postgresql](https://github.com/senzing-garage/init-postgresql)
1. **5031** - [init-mysql](https://github.com/senzing-garage/init-mysql)
1. **5032** - [keystore-generator](https://github.com/senzing-garage/keystore-generator)
1. **5032** - [init-mssql](https://github.com/senzing-garage/init-mssql)
1. **5040** - [G2Config](https://github.com/senzing-garage/g2-sdk-python/blob/main/src/senzing/g2config.py)
1. **5041** - [G2Configmgr](https://github.com/senzing-garage/g2-sdk-python/blob/main/src/senzing/g2configmgr.py)
1. **5042** - [G2Diagnostic](https://github.com/senzing-garage/g2-sdk-python/blob/main/src/senzing/g2diagnostic.py)
1. **5043** - [G2Engine](https://github.com/senzing-garage/g2-sdk-python/blob/main/src/senzing/g23ngine.py)
1. **5044** - [G2Exception](https://github.com/senzing-garage/g2-sdk-python/blob/main/src/senzing/g23xception.py)
1. **5045** - [G2Hasher](https://github.com/senzing-garage/g2-sdk-python/blob/main/src/senzing/g2hasher.py)
1. **5046** - [G2Product](https://github.com/senzing-garage/g2-sdk-python/blob/main/src/senzing/g2product.py)
1. **5047** - [g2version](https://github.com/senzing-garage/g2-sdk-python/blob/main/src/senzing/g2version.py)
1. **5050** - [G2ConfigGrpc](https://github.com/senzing-garage/g2-sdk-python/blob/main/src/senzing/g2config_grpc.py)
1. **5051** - [G2ConfigmgrGrpc](https://github.com/senzing-garage/g2-sdk-python/blob/main/src/senzing/g2configmgr_grpc.py)
1. **5052** - [G2DiagnosticGrpc](https://github.com/senzing-garage/g2-sdk-python/blob/main/src/senzing/g2diagnostic_grpc.py)
1. **5053** - [G2EngineGrpc](https://github.com/senzing-garage/g2-sdk-python/blob/main/src/senzing/g2engine_grpc.py)
1. **5054** - [G2Exception](https://github.com/senzing-garage/g2-sdk-python/blob/main/src/senzing/g2exception._grpcpy)
1. **5055** - [G2HasherGrpc](https://github.com/senzing-garage/g2-sdk-python/blob/main/src/senzing/g2hasher_grpc.py)
1. **5056** - [G2ProductGrpc](https://github.com/senzing-garage/g2-sdk-python/blob/main/src/senzing/g2product_grpc.py)

## Go SDK and apps

### SDK

1. **6001** - github.com/senzing/g2-sdk-go-base/g2config
1. **6002** - github.com/senzing/g2-sdk-go-base/g2configmgr
1. **6003** - github.com/senzing/g2-sdk-go-base/g2diagnostic
1. **6004** - github.com/senzing/g2-sdk-go-base/g2engine
1. **6005** - github.com/senzing/g2-sdk-go-base/g2hasher
1. **6006** - github.com/senzing/g2-sdk-go-base/g2product
1. **6007** - github.com/senzing/g2-sdk-go-base/g2ssadm
1. **6008** - github.com/senzing/g2-sdk-go-base/test
1. **6009** - github.com/senzing/g2-sdk-go-base/testhelpers
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
1. **6031** - github.com/senzing/g2-sdk-go-mock/g2config
1. **6032** - github.com/senzing/g2-sdk-go-mock/g2configmgr
1. **6033** - github.com/senzing/g2-sdk-go-mock/g2diagnostic
1. **6034** - github.com/senzing/g2-sdk-go-mock/g2engine
1. **6035** - github.com/senzing/g2-sdk-go-mock/g2hasher
1. **6036** - github.com/senzing/g2-sdk-go-mock/g2product
1. **6037** - github.com/senzing/g2-sdk-go-mock/g2ssadm
1. **6038** - github.com/senzing/g2-sdk-go-mock/test
1. **6039** - github.com/senzing/g2-sdk-go-mock/testhelpers
1. **6041** - github.com/senzing/go-sdk-abstract-factory/factory

### senzing-tools

1. **6100** - github.com/senzing/senzing-tools/...

### ComponentIds for senzing-tools

1. **6201** - github.com/senzing/load
1. **6202** - github.com/senzing/move
1. **6203** - github.com/senzing/validate
1. **6204** - github.com/senzing/serve-grpc
1. **6205** - github.com/senzing/init-database
1. **6206** - github.com/senzing/shuffle
1. **6207** - github.com/senzing/observe

### Reusable packages

1. **6401** - github.com/senzing/go-common/engineconfigurationparser
1. **6402** - github.com/senzing/go-common/g2engineconfigurationjson
1. **6403** - github.com/senzing/go-common/record
1. **6404** - github.com/senzing/go-common/truthset
1. **6421** - github.com/senzing/go-databasing/connector
1. **6422** - github.com/senzing/go-databasing/sqlexecutor
1. **6423** - github.com/senzing/go-databasing/postgresql
1. **6424** - github.com/senzing/go-databasing/checker
1. **6441** - github.com/senzing/go-logging/
1. **6461** - github.com/senzing/go-observing/notifier
1. **6462** - github.com/senzing/go-observing/observer
1. **6463** - github.com/senzing/go-observing/subject
1. **6464** - github.com/senzing/go-observing/grpcsubject
1. **6481** - github.com/senzing/go-queuing/
1. **6501** - github.com/senzing/initdatabase/initializer
1. **6502** - github.com/senzing/initdatabase/senzingconfig
1. **6503** - github.com/senzing/initdatabase/senzingschema
1. **6601** - github.com/senzing/load/loader
1. **6602** - github.com/senzing/move/mover
1. **6620** - github.com/senzing/serve-chat/senzingchatserver
