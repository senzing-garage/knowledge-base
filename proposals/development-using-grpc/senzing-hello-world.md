# Senzing Hello World

This demonstration shows how to start
the Senzing QuickStart using Python over gRPC
and access it with Python.

## Prerequisites

1. See [Prerequisites].

## Start interactive Python session

2. Start an interactive Python session.
   Example:

   ```console
   python3

   ```

## View Senzing version

3. For a quick test of calling Senzing's `sz_product.get_version()`,
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

5. [Development with Senzing Python SDK]
   1. Senzing Hello World
   1. [Load Senzing truth-sets]
   1. [Load user data]
   1. [Show method help]
   1. [Clean up]

[Clean up]: cleanup.md
[Development with Senzing Python SDK]: development-with-senzing-python-sdk.md
[Load Senzing truth-sets]: load-senzing-truthsets.md
[Load user data]: load-user-data.md
[Prerequisites]: development-with-senzing-python-sdk.md#prerequisites
[senzing_hello_world.py]: https://raw.githubusercontent.com/senzing-garage/knowledge-base/main/proposals/quickstart-grpc/senzing_hello_world.py
[Show method help]: show-method-help.md
