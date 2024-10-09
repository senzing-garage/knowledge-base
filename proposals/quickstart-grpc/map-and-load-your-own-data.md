# Map and load your own data

In this demonstration, your data will be added to the Senzing database.
This time the data will be persisted into SQLite database files residing on your local workstation
and custom ports will be used.

## Prerequisites

1. [Run senzing/demo-quickstart Docker container]
1. [Python 3]
1. [senzing-grpc] Python package.
   To install, run:

    ```console
    python3 -m pip install --upgrade senzing-grpc

    ```

## Create your input file

4. On your local workstation, create a file of JSON-lines with your data to be loaded into Senzing.

   As an example, download [example-data-for-senzing.json] into your `Downloads` directory.

## Start interactive Python session

5. Start an interactive Python session.
   Example:

    ```console
    python3

    ```

## Identify data sources

6. To add your data sources to the Senzing configuration,
   determine the list of data sources used in your data.
   Then in the following example, modify the value of `DATASOURCES` to match your data.

    1. :pencil2:
       Copy/modify/paste the following into the interactive Python session
       and press the **Enter** key.

        ```python
        DATASOURCES = ["MY_DATASOURCE"]

        ```

    1. Copy/paste the following into the interactive Python session
       and press the **Enter** key.

        ```python
        import grpc
        from senzing_grpc import SzAbstractFactory, SzEngineFlags, SzError

        try:
        # Create Senzing objects.
            sz_abstract_factory = SzAbstractFactory(
                grpc_channel=grpc.insecure_channel("localhost:8261")
            )
            sz_config = sz_abstract_factory.create_sz_config()
            sz_configmanager = sz_abstract_factory.create_sz_configmanager()
            sz_diagnostic = sz_abstract_factory.create_sz_diagnostic()
            sz_engine = sz_abstract_factory.create_sz_engine()
        # Get existing Senzing configuration.
            old_config_id = sz_configmanager.get_default_config_id()
            OLD_JSON_CONFIG = sz_configmanager.get_config(old_config_id)
            config_handle = sz_config.import_config(OLD_JSON_CONFIG)
        # Add DataSources to existing Senzing configuration.
            for datasource in DATASOURCES:
                sz_config.add_data_source(config_handle, datasource)
        # Persist new Senzing configuration.
            NEW_JSON_CONFIG = sz_config.export_config(config_handle)
            new_config_id = sz_configmanager.add_config(NEW_JSON_CONFIG, "Add My datasources")
            sz_configmanager.replace_default_config_id(old_config_id, new_config_id)
        # Update other Senzing objects.
            sz_engine.reinitialize(new_config_id)
            sz_diagnostic.reinitialize(new_config_id)
        except SzError as err:
            print(f"\nError:\n{err}\n")

        ```

## Add records

7. To add your data to the Senzing database,
   in the following example modify the value of `INPUT_FILENAME` to match the path to your file of JSON lines.

    1. :pencil2:
       To identify the file containing your data,
       copy/modify/paste the following into the interactive Python session:

       1. Linux/macOS example:

        ```python
        INPUT_FILENAME = "~/Downloads/example-data-for-senzing.json"

        ```

       1. Windows example:

        ```python
        INPUT_FILENAME = "C:\\Users\\username\\Downloads\\example-data-for-senzing.json"

        ```

    1. Copy/paste the following into the interactive Python session
       and press the **Enter** key.

        ```python
        import json
        import os

        try:
            with open(os.path.expanduser(INPUT_FILENAME), "r") as file:
                for line in file:
                    line_as_dict = json.loads(line)
                    data_source = line_as_dict.get("DATA_SOURCE")
                    record_id = line_as_dict.get("RECORD_ID")
                    info = sz_engine.add_record(data_source, record_id, line, SzEngineFlags.SZ_WITH_INFO)
                    print(info)
        except SzError as err:
            print(f"\nError:\n{err}\n")

        ```

   Note that this is a simple example of adding records to Senzing and is not optimized for performance.
   For higher performance techniques, additional Python programming is needed.
   For examples, see [High performance loading with Python].

1. To end the interactive Python session,
   copy/paste the following block of code into the interactive Python session
   and press the **Enter** key.

    ```python
    quit()

    ```

## Shutdown

9. To end the Senzing gRPC service using Docker,
   use `ctrl-c` to stop the `docker run ...` program.

## Next steps

10. [Overview]
1. [Try Senzing's Hello World]
1. [Use Senzing's Truth Set data]
1. Map and load your own data

[example-data-for-senzing.json]: https://raw.githubusercontent.com/senzing-garage/knowledge-base/main/proposals/streamline/example-data-for-senzing.json
[High performance loading with Python]: #
[Overview]: README.md
[Python 3]: https://github.com/senzing-garage/knowledge-base/blob/main/WHATIS/python3.md
[Run senzing/demo-quickstart Docker container]: README.md#run-docker-container
[senzing-grpc]: https://github.com/senzing-garage/sz-sdk-python-grpc
[Try Senzing's Hello World]: hello-world.md
[Use Senzing's Truth Set data]: use-senzings-truth-set-data.md
