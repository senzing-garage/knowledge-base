# Use Senzing's Truth Set data

In this demonstration,
the Senzing Truth Set data will be added to an ephemeral
Senzing database inside the running Docker container.

## Prerequisites

1. See [Prerequisites].

## Start interactive Python session

2. Start an interactive Python session.
   Example:

    ```console
    python3

    ```

## Identify data sources

3. To add Truth Set data sources to the Senzing configuration,
   copy/paste the following block of code into the interactive Python session
   and press the **Enter** key.
   Example:

    ```python
    import grpc
    from senzing_grpc import SzAbstractFactory, SzEngineFlags, SzError
    from senzing_truthset import TRUTHSET_DATASOURCES

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
        for datasource in TRUTHSET_DATASOURCES.keys():
            sz_config.add_data_source(config_handle, datasource)
    # Persist new Senzing configuration.
        NEW_JSON_CONFIG = sz_config.export_config(config_handle)
        new_config_id = sz_configmanager.add_config(
            NEW_JSON_CONFIG, "Add TruthSet datasources"
        )
        sz_configmanager.replace_default_config_id(old_config_id, new_config_id)
    # Update other Senzing objects.
        sz_engine.reinitialize(new_config_id)
        sz_diagnostic.reinitialize(new_config_id)
    except SzError as err:
        print(f"\nError:\n{err}\n")

    ```

    or download and run [senzing_truthset_add_datasources.py].

## Add records

4. To add Truth Set data to an ephemeral Senzing database,
   copy/paste the following block of code into the interactive Python session
   and press the **Enter** key.

    ```python
    from senzing_truthset import (
        TRUTHSET_CUSTOMER_RECORDS,
        TRUTHSET_REFERENCE_RECORDS,
        TRUTHSET_WATCHLIST_RECORDS,
    )

    try:
    # Identify records.
        record_sets = [
            TRUTHSET_CUSTOMER_RECORDS,
            TRUTHSET_REFERENCE_RECORDS,
            TRUTHSET_WATCHLIST_RECORDS,
        ]
    # Call Senzing to add record.
        for record_set in record_sets:
            for record in record_set.values():
                info = sz_engine.add_record(
                    record.get("DataSource"),
                    record.get("Id"),
                    record.get("Json"),
                    SzEngineFlags.SZ_WITH_INFO,
                )
                print(info)
    except SzError as err:
        print(f"\nError:\n{err}\n")

    ```

    or download and run [senzing_truthset_add_records.py].

    If running in the interactive Python session, wait until the `>>>` prompt appears before proceeding.

   Note that this is a simple example of adding records to Senzing and is not optimized for performance.
   For higher performance techniques, additional Python programming is needed.
   For examples, see [High performance loading with Python].

## View results

5. Entity details can be viewed.
   Copy/paste the following block of code into the interactive Python session
   and press the **Enter** key.

    ```python
    import json

    try:
        customer_1070_entity = sz_engine.get_entity_by_record_id("CUSTOMERS", "1070")
        print(json.dumps(json.loads(customer_1070_entity), indent=2))
    except SzError as err:
        print(f"\nError:\n{err}\n")

    ```

    or download and run [senzing_truthset_get_entity.py].

1. Entities can be searched.
   Copy/paste the following block of code into the interactive Python session
   and press the **Enter** key.

    ```python
    try:
        search_query = {
            "name_full": "robert smith",
            "date_of_birth": "11/12/1978",
        }
        search_result = sz_engine.search_by_attributes(json.dumps(search_query))
        print(json.dumps(json.loads(search_result), indent=2))
    except SzError as err:
        print(f"\nError:\n{err}\n")

    ```

    or download and run [senzing_truthset_search.py].

1. Help is available.
   Copy/paste each block of code into the interactive Python session
   and press the **Enter** key.

    ```python
    print(sz_engine.help())

    ```

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

9. [Overview]
1. [Try Senzing's Hello World]
1. Use Senzing's Truth Set data
1. [Map and load your own data]

## References

1. [View SQLite database](coleifer-sqlite-web.md)

[Prerequisites]: hello-world.md#prerequisites
[High performance loading with Python]: #
[Map and load your own data]: map-and-load-your-own-data.md
[Overview]: README.md
[senzing_truthset_add_datasources.py]: https://raw.githubusercontent.com/senzing-garage/knowledge-base/main/proposals/quickstart-grpc/senzing_truthset_add_datasources.py
[senzing_truthset_add_records.py]: https://raw.githubusercontent.com/senzing-garage/knowledge-base/main/proposals/quickstart-grpc/senzing_truthset_add_records.py
[senzing_truthset_get_entity.py]: https://raw.githubusercontent.com/senzing-garage/knowledge-base/main/proposals/quickstart-grpc/senzing_truthset_get_entity.py
[senzing_truthset_search.py]: https://raw.githubusercontent.com/senzing-garage/knowledge-base/main/proposals/quickstart-grpc/senzing_truthset_search.py
[Try Senzing's Hello World]: hello-world.md
