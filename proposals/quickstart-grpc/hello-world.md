# Try Senzing's Hello World

## Prerequisistes

The Senzing QuickStart using Python over gRPC requires the following prerequisites:

1. [Run senzing/demo-quickstart Docker container]
1. [Python 3]
1. [senzing-grpc] Python package.
   To install, run:

    ```console
    python3 -m pip install --upgrade senzing-grpc

    ```

    1. If using Python virtual enviroment, example:

        ```console
        python3 -m venv ~/my-venv
        source ~/my-venv/bin/activate
        python3 -m pip install --upgrade senzing-grpc

        ```

## View Senzing version

The following example shows how to start
the Senzing QuickStart using Python over gRPC
and access it with Python.

4. In a separate window, start an interactive Python session.
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

    or download and run [senzing_hello_world.py].

1. To end the interactive Python session,
   copy/paste the following block of code into the interactive Python session
   and press the **Enter** key.

    ```python
    quit()

    ```

1. To stop the Docker container,
   use `ctrl-c` to stop the `docker run ...` program.

## Next steps

8. [Overview]
1. Try Senzing's Hello World
1. [Use Senzing's Truth Set data]
1. [Map and load your own data]

[Map and load your own data]: map-and-load-your-own-datas.md
[Overview]: README.md
[Python 3]: https://github.com/senzing-garage/knowledge-base/blob/main/WHATIS/python3.md
[Run senzing/demo-quickstart Docker container]: README.md#run-docker-container
[senzing_hello_world.py]: https://raw.githubusercontent.com/senzing-garage/knowledge-base/main/proposals/quickstart-grpc/senzing_hello_world.py
[senzing-grpc]: https://github.com/senzing-garage/sz-sdk-python-grpc
[Use Senzing's Truth Set data]: use-senzings-truth-set-data.md
