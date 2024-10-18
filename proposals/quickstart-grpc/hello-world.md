# Senzing Hello World

This demonstration shows how to start
the Senzing QuickStart using Python over gRPC
and access it with Python.

## Prerequisites

The Senzing QuickStart using Python over gRPC requires the following prerequisites:

1. [Run senzing/demo-quickstart Docker container]
1. [Python 3]
1. [senzing-grpc] Python package.

    1. To install, run the following on the local workstation:

        ```console
        python3 -m pip install --upgrade senzing-grpc

        ```

       If a Python virtual environment is needed,
       see [Installing senzing-grpc in a python virtual environment].

## Start interactive Python session

4. Start an interactive Python session.
   Example:

    ```console
    python3

    ```

## View Senzing version

5. For a quick test of calling Senzing's `sz_product.get_version()`,
   copy/paste the following block of code into the interactive Python session
   and press the **Enter** key.

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

## Next steps

7. [Senzing Python Software Development Kit]
    1. Senzing Hello World
    1. [Load Senzing truth-sets]
    1. [Load user data]
    1. [Show method help]
    1. [Clean up]

[Clean up]: cleanup.md
[Installing senzing-grpc in a python virtual environment]: virtual-environment.md
[Load Senzing truth-sets]: load-truthsets.md
[Load user data]: load-user-data.md
[Python 3]: https://github.com/senzing-garage/knowledge-base/blob/main/WHATIS/python3.md
[Run senzing/demo-quickstart Docker container]: README.md#run-docker-container
[Senzing Python Software Development Kit]: python-sdk.md
[senzing_hello_world.py]: https://raw.githubusercontent.com/senzing-garage/knowledge-base/main/proposals/quickstart-grpc/senzing_hello_world.py
[senzing-grpc]: https://github.com/senzing-garage/sz-sdk-python-grpc
[Show method help]: method-help.md
