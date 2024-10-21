# Development with Senzing Python SDK

## Prerequisites

Senzing development with Senzing Python SDK requires the following prerequisites:

1. [Run senzing/demo-quickstart Docker container]
1. [Python 3]
1. [senzing-grpc] Python package.

    1. To install, run the following on the local workstation:

        ```console
        python3 -m pip install --upgrade senzing-grpc

        ```

       If a Python virtual environment is needed,
       see [Installing senzing-grpc in a python virtual environment].

## Start developing

With the prerequisites satisified, you can start using Python tools
to develop Python applications using Senzing.

Here are a few examples of Python programs to help you get started:

1. [Senzing Hello World] - A simple test of connectivity to Senzing engine.
1. [Load Senzing truth-sets] - Load and query the Senzing truth-set-data.
1. [Load user data] - Load custom data.
1. [Show method help] - Show how to display help.

[Installing senzing-grpc in a python virtual environment]: virtual-environment.md
[Load Senzing truth-sets]: load-senzing-truthsets.md
[Load user data]: load-user-data.md
[Python 3]: https://github.com/senzing-garage/knowledge-base/blob/main/WHATIS/python3.md
[Run senzing/demo-quickstart Docker container]: README.md#run-docker-container
[Senzing Hello World]: senzing-hello-world.md
[senzing-grpc]: https://github.com/senzing-garage/sz-sdk-python-grpc
[Show method help]: show-method-help.md
