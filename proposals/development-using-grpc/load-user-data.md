# Load user data

In this demonstration,
the user data will be added to an ephemeral
Senzing database inside the running Docker container.

## Prerequisites

1. See [Prerequisites].

## Create an input file

2. On a local workstation, create a file of JSON-lines with custom data to be loaded into Senzing.

   As an example, download [example-data-for-senzing.json] into the `Downloads` directory.

## Start interactive Python session

3. Start an interactive Python session.
   Example:

   ```console
   python3

   ```

## Identify data sources

4. To add data sources to the Senzing configuration,
   determine the list of data sources used in the data.
   Then in the following example, modify the value of `DATASOURCES` to match the data.
   1. :pencil2:
      Copy/**modify**/paste the following into the interactive Python session
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
          sz_abstract_factory.reinitialize(new_config_id)
      except SzError as err:
          print(f"\nError:\n{err}\n")

      ```

## Add records

5. To add data to an ephemeral Senzing database,
   in the following example modify the value of `INPUT_FILENAME` to match the path of the file of JSON lines.
   1. :pencil2:
      To identify the file containing the data,
      copy/**modify**/paste the following into the interactive Python session:
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

## Next steps

7. [Development with Senzing Python SDK]
   1. [Senzing Hello World]
   1. [Load Senzing truth-sets]
   1. Load user data
   1. [Show method help]
   1. [Clean up]

[Clean up]: cleanup.md
[Development with Senzing Python SDK]: development-with-senzing-python-sdk.md
[example-data-for-senzing.json]: https://raw.githubusercontent.com/senzing-garage/knowledge-base/main/proposals/quickstart-grpc/example-data-for-senzing.json
[High performance loading with Python]: #
[Load Senzing truth-sets]: load-senzing-truthsets.md
[Prerequisites]: development-with-senzing-python-sdk.md#prerequisites
[Senzing Hello World]: senzing-hello-world.md
[Show method help]: show-method-help.md
