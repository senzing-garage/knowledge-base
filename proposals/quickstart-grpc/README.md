# quickstart-grpc

This Python demonstration of Senzing works on Linux, macOS, and Windows.

## Prerequisistes

1. Python 3
1. Docker - To install, see
   [Linux](https://docs.docker.com/desktop/install/linux/),
   [Mac](https://docs.docker.com/desktop/install/mac-install/), or
   [Windows](https://docs.docker.com/desktop/install/windows-install/).
    1. Make sure Docker is running.
    1. **Optional:** To pre-load docker images, run

        ```console
        docker pull senzing/demo-quickstart

        ```

1. `senzing-grpc` - To install, run

    ```console
    python3 -m pip install --upgrade senzing-grpc

    ```

## Try Senzing's Hello World

The following example shows how to start a Senzing gRPC service
and access it with Python.

5. Run a Senzing gRPC service using Docker.
   Example:

    ```console
    docker run --name senzing-demo-quickstart -p 8260:8260 -p 8261:8261 --pull always --rm senzing/demo-quickstart
    ```

1. In a separate window, start an interactive Python session.
   Example:

    ```console
    python3

    ```

1. For a quick test of calling Senzing's `sz_product.version()`,
   copy/paste the following block of code into the interactive Python session
   and press the **Enter** key.
   Example:

    ```python
    import grpc
    from senzing_grpc import SzAbstractFactory
    sz_abstract_factory = SzAbstractFactory(grpc_channel=grpc.insecure_channel("localhost:8261"))
    sz_product = sz_abstract_factory.create_sz_product()
    print(sz_product.version())

    ```

    or download and run
    [senzing_hello_world.py](https://raw.githubusercontent.com/senzing-garage/knowledge-base/main/proposals/quickstart-grpc/senzing_hello_world.py).

1. To end the interactive Python session,
   copy/paste the following block of code into the interactive Python session
   and press the **Enter** key.

    ```python
    quit()

    ```

1. To end the Senzing gRPC service,
   use `ctrl-c` to stop the `docker run ...` program.

## Next steps

- Linux / macOs
    1. Try Senzing's Hello World
    1. [Use Senzing's Truth Set data - Linux/macOS](use-senzings-truth-set-data-linux-macos.md)
    1. [Map and load your own data - Linux/macOS](map-and-load-your-own-data-linux-macos.md)
    1. [Experience Entity Resolution Record-by-Record - Linux/macOS](experience-entity-resolution-record-by-record-linux-macos.md)
    1. [Bad-Guy Hunting](bad-guy-hunting/bad-guy-hunting-linux-macos.md)
- Windows
    1. Try Senzing's Hello World
    1. [Use Senzing's Truth Set data - Windows](use-senzings-truth-set-data-windows.md)
    1. [Map and load your own data - Windows](map-and-load-your-own-data-windows.md)
    1. [Experience Entity Resolution Record-by-Record - Windows](experience-entity-resolution-record-by-record-windows.md)
    1. [Bad-Guy Hunting](bad-guy-hunting/bad-guy-hunting-windows.md)
