# Show method help

In this demonstration,
helper functions are shown.

## Prerequisites

1. See [Prerequisites].

## Start interactive Python session

2. Start an interactive Python session.
   Example:

    ```console
    python3

    ```

## Show help

3. To create an abstract factory and Senzing object,
   copy/paste the following block of code into the interactive Python session
   and press the **Enter** key.
   Example:

    ```python
    import grpc
    from senzing_grpc import SzAbstractFactory, SzError

    try:
        sz_abstract_factory = SzAbstractFactory(
            grpc_channel=grpc.insecure_channel("localhost:8261")
        )
        sz_engine = sz_abstract_factory.create_sz_engine()
    except SzError as err:
        print(f"\nError:\n{err}\n")

    ```

1. To display methods of the Senzing object,
   copy/paste the following block code into the interactive Python session
   and press the **Enter** key.

    ```python
    print(sz_engine.help())

    ```

1. To display the details of a specific method,
   copy/paste the following block code into the interactive Python session
   and press the **Enter** key.

    ```python
    print(sz_engine.help("get_entity_by_record_id"))

    ```

1. To end the interactive Python session,
   copy/paste the following block of code into the interactive Python session
   and press the **Enter** key.

    ```python
    quit()

    ```

## Next steps

7. [Senzing Python SDK demonstration]
    1. [Senzing Hello World]
    1. [Load Senzing truth-sets]
    1. [Load user data]
    1. Show method help
    1. [Clean up]

[Clean up]: cleanup.md
[Load Senzing truth-sets]: load-senzing-truthsets.md
[Load user data]: load-user-data.md
[Prerequisites]: development-with-senzing-python-sdk.md#prerequisites
[Senzing Hello World]: senzing-hello-world.md
[Senzing Python SDK demonstration]: senzing-python-sdk-demonstration.md
