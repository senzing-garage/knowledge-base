# Senzing Playground

The Senzing Playground runs a Senzing gRPC server and HTTP server for use in Senzing exploration.
The Senzing Playground works on Linux, macOS, and Windows.

## Prerequisistes

The Senzing Playground requires the following prerequisites:

1. [Docker]

## Run Docker container

2. Run the Senzing Playground Docker container.
   Example:

    ```console
    docker run -it --name senzing-playground -p 8260:8260 -p 8261:8261 --pull always --rm senzing/playground

    ```

## Explore

3. Once the docker container is running, explore Senzing at [http://localhost:8260].

## Advanced setup

4. If only the gRPC server is required, run

```console
    docker run -it --name senzing-serve-grpc -p 8261:8261 --pull always --rm senzing/serve-grpc

```

[Docker]: https://github.com/senzing-garage/knowledge-base/blob/main/WHATIS/docker.md
[http://localhost:8260]: http://localhost:8260
