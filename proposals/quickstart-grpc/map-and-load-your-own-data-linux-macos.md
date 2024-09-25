# Map and load your own data  - Linux/macOS

In this demonstration, your data will be added to the Senzing database.
This time the data will be persisted into SQLite database files residing on your local workstation
and custom ports will be used.

## Prerequisites

1. [Run Docker container].

## Create your input file

2. On your local workstation, create a file of JSON-lines with your data to be loaded into Senzing.

   To create an example file of JSON-lines,
   copy/paste the following into a terminal window:

    ```console
    cat <<EOT > /tmp/example-data-for-senzing.json
    {"DATA_SOURCE": "MY_DATASOURCE", "RECORD_ID": "157616467", "DRIVERS_LICENSE_NUMBER": "00", "DATE_OF_BIRTH": "20/12/1965", "ADDR_POSTAL_CODE": "47201", "ADDR_CITY": "Columbus", "SSN_NUMBER": "883-24-5259", "NAME_FIRST": "CYNTHIA", "NAME_LAST": "SHORTS", "GENDER": "F",  "DSRC_ACTION": "A", "ADDR_LINE1": "696 15th ST"}
    {"DATA_SOURCE": "MY_DATASOURCE", "RECORD_ID": "115212881", "SOCIAL_HANDLE": "thyroidss", "DATE_OF_BIRTH": "20/11/1960", "ADDR_STATE": "AR", "SSN_NUMBER": "434-59-7109", "NAME_FIRST": "KEVIN", "PASSPORT_NUMBER": "154CE0YTD", "GENDER": "M", "DSRC_ACTION": "A", "ADDR_CITY": "Lewisville", "DRIVERS_LICENSE_STATE": "DE", "PHONE_NUMBER": "501-357-3875", "NAME_LAST": "HZIRT", "ADDR_LINE1": "330 5th ST"}
    {"DATA_SOURCE": "MY_DATASOURCE", "RECORD_ID": "645217904", "ADDR_STATE": "Minnesota", "ADDR_POSTAL_CODE": "55804", "SSN_NUMBER": "113-56-6093", "NAME_FIRST": "LINDA", "GENDER": "F", "CC_ACCOUNT_NUMBER": "6442498315525524",  "DSRC_ACTION": "A", "ADDR_CITY": "Duluth", "DRIVERS_LICENSE_NUMBER": "S90976292", "DRIVERS_LICENSE_STATE": "HI", "PHONE_NUMBER": "952-757-7688", "NAME_LAST": "BUCHANAN", "ADDR_LINE1": "486 41st AVE"}
    {"DATA_SOURCE": "MY_DATASOURCE", "RECORD_ID": "212359276", "DATE_OF_BIRTH": "23/2/1968", "ADDR_STATE": "ID", "ADDR_POSTAL_CODE": "83709", "SSN_NUMBER": "441-76-2625", "NAME_FIRST": "ROLANDA", "PASSPORT_NUMBER": "CFP1XM4Q", "GENDER": "N/A", "CC_ACCOUNT_NUMBER": "50186266717162531",  "DSRC_ACTION": "A", "DRIVERS_LICENSE_NUMBER": "X8865625161887", "DRIVERS_LICENSE_STATE": "IW", "ADDR_CITY": "Boise", "NAME_LAST": "JOHNSON", "ADDR_LINE1": "142 AuYto DR"}
    {"DATA_SOURCE": "MY_DATASOURCE", "RECORD_ID": "526429955", "SSN_NUMBER": "388-69-4882", "NAME_FIRST": "JOHNNIE", "PASSPORT_NUMBER": "CN5QGN8HY8", "GENDER": "M", "CC_ACCOUNT_NUMBER": "541119397002419249", "DSRC_ACTION": "A", "DRIVERS_LICENSE_NUMBER": "943105509", "DRIVERS_LICENSE_STATE": "IV", "PHONE_NUMBER": "355-9553", "NAME_LAST": "H", "ADDR_LINE1": "69 Cayuga CT"}
    {"DATA_SOURCE": "MY_DATASOURCE", "RECORD_ID": "604947448", "ADDR_CITY": "Port Jefferson Station", "DRIVERS_LICENSE_NUMBER": "50951659", "ADDR_STATE": "NY", "ADDR_POSTAL_CODE": "11776", "PHONE_NUMBER": "268-8561", "NAME_FIRST": "ALBERT", "NAME_LAST": "GALLAHER", "GENDER": "M",  "DSRC_ACTION": "A", "ADDR_LINE1": "22 BroadShurst ST"}
    {"DATA_SOURCE": "MY_DATASOURCE", "RECORD_ID": "513789670", "SOCIAL_HANDLE": "tainsz", "ADDR_STATE": "OK", "ADDR_POSTAL_CODE": "34133", "SSN_NUMBER": "758-42-2397", "NAME_FIRST": "JAFMES", "GENDER": "M", "DSRC_ACTION": "A", "ADDR_CITY": "TAlsa", "DRIVERS_LICENSE_STATE": "NY", "PHONE_NUMBER": "580-558-8123", "NAME_LAST": "HENDERSON", "ADDR_LINE1": "6738 112thEast AVE"}
    {"DATA_SOURCE": "MY_DATASOURCE", "RECORD_ID": "212442489", "SOCIAL_HANDLE": "debrides7", "ADDR_STATE": "CO", "ADDR_POSTAL_CODE": "80501", "NAME_FIRST": "S", "GENDER": "M", "CC_ACCOUNT_NUMBER": "676396021499009121", "DSRC_ACTION": "A", "DRIVERS_LICENSE_STATE": "NE", "ADDR_CITY": "Longmont", "NAME_LAST": "JONES", "ADDR_LINE1": "948 10th AVE"}
    EOT

    ```

   The command created a new `/tmp/example-data-for-senzing.json` file on your local workstation.

## Start interactive Python session

3. Start an interactive Python session.
   Example:

    ```console
    python3

    ```

## Identify data sources

4. To add your data sources to the Senzing configuration,
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

5. To add your data to the Senzing database,
   in the following example modify the value of `INPUT_FILENAME` to match the path to your file of JSON lines.

    1. :pencil2:
       To identify the file containing your data,
       copy/modify/paste the following into the interactive Python session:

        ```python
        INPUT_FILENAME = "/tmp/example-data-for-senzing.json"

        ```

    1. Copy/paste the following into the interactive Python session
       and press the **Enter** key.

        ```python
        import json

        try:
            with open(INPUT_FILENAME, "r") as file:
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

6. To end the Senzing gRPC service using Docker,
   use `ctrl-c` to stop the `docker run ...` program.

## Next steps

1. [Try Senzing's Hello World]
1. [Use Senzing's Truth Set data - Linux/macOS]
1. Map and load your own data - Linux/macOS

## References

1. [View SQLite database]

[Run Docker container]: README.md#run-docker-container
[Try Senzing's Hello World]: README.md
[Use Senzing's Truth Set data - Linux/macOS]: use-senzings-truth-set-data-linux-macos.md
[View SQLite database]: coleifer-sqlite-web.md
[High performance loading with Python]: #
