# Development-using-gRPC

The Senzing Development using gRPC supports local development using a Senzing gRPC server
and an ephemeral database.

## Prerequisistes

The Senzing QuickStart using Python over gRPC requires the following prerequisites:

1. [Docker]

## Run Docker container

2. Run the Senzing QuickStart Docker container.
   Example:

    ```console
    docker run -it --name senzing-serve-grpc -p 8261:8261 --pull always --rm senzing/serve-grpc

    ```

## Next steps

3. [Python development]
1. Java development
1. Go development

[Docker]: https://github.com/senzing-garage/knowledge-base/blob/main/WHATIS/docker.md
[Python development]: development-with-senzing-python-sdk.md
