# quickstart-grpc

The Senzing QuickStart using Python over gRPC works on Linux, macOS, and Windows.

## Prerequisistes

The Senzing QuickStart using Python over gRPC requires the following prerequisites:

1. [Docker]

## Run Docker container

2. After installing [prerequisites], run the Docker container.
   Example:

    ```console
    docker run -it --name senzing-demo-quickstart -p 8260:8260 -p 8261:8261 --pull always --rm senzing/demo-quickstart
    ```

sour

## Next steps

Now that an environment is setup, feel free to explore Senzing.

3. Visit [http://localhost:8260] for Jupyter Lab demonstration.
1. Native Python Software Development Kit (SDK) demonstrations:
    1. Linux / macOs
        1. [Try Senzing's Hello World - Linux/macOS]
        1. [Use Senzing's Truth Set data - Linux/macOS]
        1. [Map and load your own data - Linux/macOS]
    1. Windows
        1. [Try Senzing's Hello World - Windows]
        1. [Use Senzing's Truth Set data - Windows]
        1. [Map and load your own data - Windows]

[Docker]: https://github.com/senzing-garage/knowledge-base/blob/main/WHATIS/docker.md
[http://localhost:8260]: http://localhost:8260
[Map and load your own data - Linux/macOS]: map-and-load-your-own-data-linux-macos.md
[Map and load your own data - Windows]: map-and-load-your-own-data-windows.md
[prerequisites]: #prerequisistes
[Try Senzing's Hello World - Linux/macOS]: hello-world-linux-macos.md
[Try Senzing's Hello World - Windows]: hello-world-windows.md
[Use Senzing's Truth Set data - Linux/macOS]: use-senzings-truth-set-data-linux-macos.md
[Use Senzing's Truth Set data - Windows]: use-senzings-truth-set-data-windows.md
