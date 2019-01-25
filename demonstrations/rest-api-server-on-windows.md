# Demonstrate Senzing REST API server on Windows

## Overview

The following instructions will demonstrate the
[Senzing REST API server](https://github.com/Senzing/rest-api-server-java)
on a Windows system.

### Contents

## Dependencies

1. Windows 10 pro x64
1. [Java](../HOWTO/install-java.md)
1. [Senzing App](../HOWTO/install-senzing-app.md#windows)
1. [sz-api-server-M.m.P.jar](https://github.com/Senzing/rest-api-server-java)

## Download example data sources

1. Get example data.

    1. Method #1 - git

        ```console
        git clone git@github.com:Senzing/example-senzing-projects.git
        ```  

    1. Method #2 - curl

        ```console
        curl -X GET --output %HOMEPATH%\Downloads\Co-workers.csv https://raw.githubusercontent.com/Senzing/example-senzing-projects/master/coworkers/csv/Co-workers.csv
        curl -X GET --output %HOMEPATH%\Downloads\Company-Directory.csv https://raw.githubusercontent.com/Senzing/example-senzing-projects/master/coworkers/csv/Company-Directory.csv
        ```

## Load data

Loading data will be done via the Senzing App.

1. In Windows, launch "Senzing"
    1. Search for "Senzing", choose Apps > Senzing Desktop app
1. Close introductory dialogs.
    1. Accept End User License Agreement
1. Add Data source
    1. On initial invocation, "Project has no data loaded. Click to load data" is seen.
        1. Click it.
        1. Otherwise, on left-hand navigation bar, choose "Data".
    1. Click on "Add Data Source".
    1. Open `.csv` file(s) in `%HOMEPATH%\Downloads\` or the cloned `example-senzing-projects` git repository.
    1. For each tile,
        1. Click "Review Mapping" link.
        1. In "Enter data source name" text entry box, provide a name.  Example: "Co-workers"
        1. Click "[ ] Ready to Load" button.
    1. For each tile,
        1. Click "Load Now" link.
1. Feel free to peruse Senzing App. :eyes:
1. Close Senzing App.

## Run API server.

1. Configuration

    * **SENZING_JAR_FILE** -
        Location of sz-api-server-M.m.P.jar
    * **SENZING_INI_FILE** -
        Location of Senzing app configuration file.
        Usually in `%HOMEPATH%\AppData\Local\Senzing\Workbench\` directory. 

1. Start the service. Example:

    ```console
    set SENZING_DIR=%ProgramFiles%\Senzing
    set SENZING_LIB_DIR=%SENZING_DIR%\g2\lib
    set SENZING_JAR_FILE=%HOMEPATH%\Downloads\sz-api-server-1.5.1.jar
    set SENZING_API_PORT=8080
    set SENZING_INI_FILE=%HOMEPATH%\AppData\Local\Senzing\Workbench\project_1\g2.ini

    set Path=%SENZING_LIB_DIR%;%Path%

    java -jar %SENZING_JAR_FILE% -concurrency 4 -httpPort %SENZING_API_PORT% -bindAddr all -iniFile %SENZING_INI_FILE%
    ```

## Test API server  

1. Check the service "heartbeat".  Example:

    ```console
    set SENZING_API_PORT=8080
    set SENZING_API_SERVICE=http://localhost:%SENZING_API_PORT%

    curl -X GET %SENZING_API_SERVICE%/heartbeat
    ```

## API examples

1. Version

    ```console
    curl -X GET %SENZING_API_SERVICE%/license
    ```

1. data-sources

    ```console
    curl -X GET %SENZING_API_SERVICE%/data-sources
    ```

1. entities

    ```console
    curl -X GET %SENZING_API_SERVICE%/entities/1
    ```