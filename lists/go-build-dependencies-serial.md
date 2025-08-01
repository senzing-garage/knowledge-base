# Go build dependencies - serial

1. List all Go repositories
   1. <https://github.com/search?q=topic%3Agolang+org%3ASenzing&type=Repositories>

## Dependencies

1. No dependencies
   1. [ ] [sz-sdk-json-type-definition](https://github.com/senzing-garage/sz-sdk-json-type-definition)
   1. [ ] [sz-sdk-proto/go](https://github.com/senzing-garage/sz-sdk-proto/go)
   1. [ ] [go-grpcing](https://github.com/senzing-garage/go-grpcing)
   1. [ ] [go-messaging](https://github.com/senzing-garage/go-messaging)
1. Requires: sz-sdk-json-type-definition
   1. [ ] [sz-sdk-go](https://github.com/senzing-garage/sz-sdk-go)
1. Requires: go-messaging
   1. [ ] [go-helpers](https://github.com/senzing-garage/go-helpers)
1. Requires: go-helpers
   1. [ ] [go-logging](https://github.com/senzing-garage/go-logging)
   1. [ ] [go-observing](https://github.com/senzing-garage/go-observing)
   1. [ ] [go-cmdhelping](https://github.com/senzing-garage/go-cmdhelping)
1. Requires: go-observing
1. Requires: go-logging
   1. [ ] [go-databasing](https://github.com/senzing-garage/go-databasing)
1. Requires: go-cmdhelping
   1. [ ] [explain](https://github.com/senzing-garage/explain)
   1. [ ] [observe](https://github.com/senzing-garage/observe)
   1. [ ] [template-go](https://github.com/senzing-garage/template-go)
   1. [ ] [validate](https://github.com/senzing-garage/validate)
1. Requires: sz-sdk-go
   1. [ ] [sz-sdk-go-core](https://github.com/senzing-garage/sz-sdk-go-core)
   1. [ ] [sz-sdk-go-mock](https://github.com/senzing-garage/sz-sdk-go-mock)
   1. [ ] [sz-sdk-go-grpc](https://github.com/senzing-garage/sz-sdk-go-grpc) (requires `serve-grpc` for testing later)
   1. [ ] [go-queueing](https://github.com/senzing-garage/go-queueing)
1. Requires: sz-sdk-go-grpc
   1. [ ] [go-sdk-abstract-factory](https://github.com/senzing-garage/go-sdk-abstract-factory)
1. Requires: go-databasing
   1. [ ] [init-database](https://github.com/senzing-garage/init-database)
1. Requires: sz-sdk-go-core
   1. [ ] [serve-grpc](https://github.com/senzing-garage/serve-grpc)  (needs init-database backpatch)
1. Requires: serve-grpc (for testing)
1. Requires: go-queueing
   1. [ ] [move](https://github.com/senzing-garage/move)
1. Requires: go-sdk-abstract-factory
   1. [ ] [check-self](https://github.com/senzing-garage/check-self)
   1. [ ] [go-rest-api-service](https://github.com/senzing-garage/go-rest-api-service)
   1. [ ] [load](https://github.com/senzing-garage/load)
   1. [ ] [serve-chat](https://github.com/senzing-garage/serve-chat)
1. Requires: go-rest-api-service
   1. [ ] [demo-entity-search](https://github.com/senzing-garage/demo-entity-search)
   1. [ ] [serve-http](https://github.com/senzing-garage/serve-http)
1. Requires: demo-entity-search
1. Requires: init-database
1. Requires: observe
1. Requires: serve-grpc
1. Requires: serve-http
1. Requires: demo-quickstart
   1. [ ] [playground](https://github.com/senzing-garage/playground)
   1. [ ] [senzing-tools](https://github.com/senzing-garage/senzing-tools)

## Not included

1 [ ] [senzing-with-chatgpt-notebook](https://github.com/senzing-garage/senzing-with-chatgpt-notebook)
