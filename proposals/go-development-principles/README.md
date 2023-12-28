# Go development principles

## Naming

### Repository naming principles

1. Cross-cutting concerns
    1. Repositories that have a single-focus aspect of reuse.
    1. Format: `go-xxxxing` where `xxxx` is the identifer of the cross-cutting concern
    1. Examples:
        1. [go-cmdhelping](https://github.com/senzing-garage/go-cmdhelping)
        1. [go-databasing](https://github.com/senzing-garage/go-databasing)
        1. [go-grpcing](https://github.com/senzing-garage/go-grpcing)
        1. [go-logging](https://github.com/senzing-garage/go-logging)
        1. [go-messaging](https://github.com/senzing-garage/go-messaging)
        1. [go-observing](https://github.com/senzing-garage/go-observing)
        1. [go-queueing](https://github.com/senzing-garage/go-queueing)
1. `senzing-tools` commands
    1. Repositories that are subcommands for [senzing-tools](https://github.com/senzing-garage/senzing-tools)
    1. Repository will have a `cmd` directory
    1. Format: `<verb>` or `<verb>-<noun>`
    1. Examples:
        1. [check-self](https://github.com/senzing-garage/check-self)
        1. [explain](https://github.com/senzing-garage/explain)
        1. [init-database](https://github.com/senzing-garage/init-database)
        1. [load](https://github.com/senzing-garage/load)
        1. [move](https://github.com/senzing-garage/move)
        1. [observe](https://github.com/senzing-garage/observe)
        1. [serve-chat](https://github.com/senzing-garage/serve-chat)
        1. [serve-grpc](https://github.com/senzing-garage/serve-grpc)
        1. [serve-http](https://github.com/senzing-garage/serve-http)
        1. [validate](https://github.com/senzing-garage/validate)
1. SenzingAPI specific
    1. Format: `g2-sdk-xxxxxx`
    1. This is to match non-Golang repositories like:
        1. [g2-sdk-java](https://github.com/senzing-garage/g2-sdk-java)
        1. [g2-sdk-json-type-definition](https://github.com/senzing-garage/g2-sdk-json-type-definition)
        1. [g2-sdk-proto](https://github.com/senzing-garage/g2-sdk-proto)
        1. [g2-sdk-python](https://github.com/senzing-garage/g2-sdk-python)
    1. Examples:
        1. [g2-sdk-go-base](https://github.com/senzing-garage/g2-sdk-go-base)
        1. [g2-sdk-go-grpc](https://github.com/senzing-garage/g2-sdk-go-grpc)
        1. [g2-sdk-go-mock](https://github.com/senzing-garage/g2-sdk-go-mock)
        1. [g2-sdk-go](https://github.com/senzing-garage/g2-sdk-go)
1. General
    1. Format: `go-xxxxxx`
    1. Examples:
        1. [go-common](https://github.com/senzing-garage/go-common)
        1. [go-sdk-abstract-factory](https://github.com/senzing-garage/go-sdk-abstract-factory)
        1. [go-rest-api-service](https://github.com/senzing-garage/go-rest-api-service)
