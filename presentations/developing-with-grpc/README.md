# Developing with gRPC

## Overview

1. Quick look at gRPC
1. Service definition
1. Writing to native gRPC code
1. Senzing SDK support
1. Create gRPC server docker image
1. Run python/go from commandline

## Quick look at gRPC

1. [gRPC] - Google Remote Procedure Call
1. 10 years since inception; first release 2015.
1. Two aspects:
    1. Transportation - HTTP/2
    1. Message - Protobuf
1. Performance: Anecdotal evidence on internet suggests 7 times faster than HTML/REST.

## Service definition

1. [sz-sdk-proto]
    1. Example: [szengine.proto]
       1. `option:` metadata for transpiling into target languages.
       1. `service:` lists all of the procedure calls.
       1. `message:` list all of the request and response messages.
1. Using transpiler, these `.proto` specifications are used to generate code
    1. Example generation: [generate Python gRPC code]
    1. Example output:
        1. [szengine_pb2_grpc.py] - transportation (gRPC)
        1. [szengine_pb2.py] - message (Protobuf)
1. For hints on how to transpile, view the [sz-sdk-proto Makefile].

## Writing to native gRPC code

```console
stub = szengine_pb2_grpc.SzEngineStub(grpc_channel)

try:
    request = szengine_pb2.AddRecordRequest(
        dataSourceCode=as_str(data_source_code),
        recordId=as_str(record_id),
        recordDefinition=as_str(record_definition),
        flags=flags,
    )
    response = stub.AddRecord(request)
except Exception as err:
    raise new_exception(err) from err
```

1. *Problem:*  Code to access Senzing differs from "native" SDK.
   So you would have to write it one way to access via gRPC and a different way to access natively.
   Native access look like this:

    ```console
    try:
        info = sz_engine.add_record(data_source_code, record_id, record_definition, flags)
    except SzError as err:
        print(err)
    ```

## Senzing SDK support

1. Senzing has "core" SDKs to talk directly to the underlying Senzing binary libraries.
    1. Languages:  Python, Java, Go
1. Senzing also has "gRPC" SDKs that implement the same interface as the "core" SDKs.
    1. The gRPC SDKs are an [adapter pattern] translating from the Senzing interface to the gRPC interface.
    1. Languages:  Python, Java, Go
1. With Senzing "core" and "gRPC" SDKs, you can access Senzing in the same manner.
   Example:

    ```console
    try:
        info = sz_engine.add_record(data_source_code, record_id, record_definition, flags)
    except SzError as err:
        print(err)
    ```

1. Under the covers the [gRPC add_record method] is adapting from the Senzing SDK interfact to the gRPC interface.

1. **NOTE:** If you are writing in a [gRPC supported language] other than Python, Java, or Go, you can still use gRPC natively.

## Create gRPC server docker image

## Run python/go from commandline

[adapter pattern]: https://en.wikipedia.org/wiki/Adapter_pattern
[gRPC supported language]: https://grpc.io/docs/languages/
[gRPC]: https://grpc.io
[sz-sdk-proto]: https://github.com/senzing-garage/sz-sdk-proto
[szengine.proto]: https://github.com/senzing-garage/sz-sdk-proto/blob/main/szengine.proto
[generate Python gRPC code]: https://grpc.io/docs/languages/python/quickstart/#generate-grpc-code
[szengine_pb2.py]: https://github.com/senzing-garage/sz-sdk-proto/blob/main/example_generated_source_code/python/szengine/szengine_pb2.py
[szengine_pb2_grpc.py]: https://github.com/senzing-garage/sz-sdk-proto/blob/main/example_generated_source_code/python/szengine/szengine_pb2_grpc.py
[sz-sdk-proto Makefile]: https://github.com/senzing-garage/sz-sdk-proto/blob/main/Makefile
[gRPC add_record method]: https://github.com/senzing-garage/sz-sdk-python-grpc/blob/4731a2ec428f3c3265e10aacb8b3e813067292c6/src/senzing_grpc/szengine.py#L77-L94
