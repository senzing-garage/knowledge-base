# quickstart-grpc

The Senzing QuickStart using Python over gRPC works on Linux, macOS, and Windows.

## Prerequisistes

The Senzing QuickStart using Python over gRPC requires the following prerequisites:

1. [Python 3]
1. [Docker]
1. [senzing-grpc] Python package.
   To install, run:

    ```console
    python3 -m pip install --upgrade senzing-grpc

    ```

## Run Docker container

4. After installing [prerequisites], run the Docker container.
   Example:

    ```console
    docker run --name senzing-demo-quickstart -p 8260:8260 -p 8261:8261 --pull always --rm senzing/demo-quickstart
    ```

## Try Senzing's Hello World

The following example shows how to start
the Senzing QuickStart using Python over gRPC
and access it with Python.

5. In a separate window, start an interactive Python session.
   Example:

    ```console
    python3

    ```

1. For a quick test of calling Senzing's `sz_product.get_version()`,
   copy/paste the following block of code into the interactive Python session
   and press the **Enter** key.
   Example:

    ```python
    import grpc
    from senzing_grpc import SzAbstractFactory
    sz_abstract_factory = SzAbstractFactory(grpc_channel=grpc.insecure_channel("localhost:8261"))
    sz_product = sz_abstract_factory.create_sz_product()
    print(sz_product.get_version())

    ```

    or download and run
    [senzing_hello_world.py](https://raw.githubusercontent.com/senzing-garage/knowledge-base/main/proposals/quickstart-grpc/senzing_hello_world.py).

1. To end the interactive Python session,
   copy/paste the following block of code into the interactive Python session
   and press the **Enter** key.

    ```python
    quit()

    ```

1. To stop the Docker container,
   use `ctrl-c` to stop the `docker run ...` program.

## Next steps

Now that an environment is setup,
feel free to explore Senzing.

- Linux / macOs
    1. Try Senzing's Hello World
    1. [Use Senzing's Truth Set data - Linux/macOS]
    1. [Map and load your own data - Linux/macOS]
    1. [Experience Entity Resolution Record-by-Record - Linux/macOS]
    1. [Bad-Guy Hunting - Linux/macOS]
- Windows
    1. Try Senzing's Hello World
    1. [Use Senzing's Truth Set data - Windows]
    1. [Map and load your own data - Windows]
    1. [Experience Entity Resolution Record-by-Record - Windows]
    1. [Bad-Guy Hunting - Windows]

[Bad-Guy Hunting - Linux/macOS]: bad-guy-hunting/bad-guy-hunting-linux-macos.md
[Bad-Guy Hunting - Windows]: bad-guy-hunting/bad-guy-hunting-windows.md
[Docker]: https://github.com/senzing-garage/knowledge-base/blob/main/WHATIS/docker.md
[Experience Entity Resolution Record-by-Record - Linux/macOS]: experience-entity-resolution-record-by-record-linux-macos.md
[Experience Entity Resolution Record-by-Record - Windows]: experience-entity-resolution-record-by-record-windows.md
[Map and load your own data - Linux/macOS]: map-and-load-your-own-data-linux-macos.md
[Map and load your own data - Windows]: map-and-load-your-own-data-windows.md
[prerequisites]: #prerequisistes
[Python 3]: https://github.com/senzing-garage/knowledge-base/blob/main/WHATIS/python3.md
[senzing-grpc]: https://github.com/senzing-garage/sz-sdk-python-grpc
[Use Senzing's Truth Set data - Linux/macOS]: use-senzings-truth-set-data-linux-macos.md
[Use Senzing's Truth Set data - Windows]: use-senzings-truth-set-data-windows.md
