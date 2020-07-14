# Setup Senzing REST API development environment on Windows

This set of instructions show how to use Windows Command prompt instructions to setup and run a
[Senzing API Server](https://github.com/Senzing/senzing-api-server).

With a running Senzing API server on a local Windows machine, a developer can write code that makes network requests
(i.e. HTTP request) to the Senzing API server

## Prerequisites

### Install Docker for Windows

1. [Install Docker Desktop on Windows](https://docs.docker.com/docker-for-windows/install/)
    1. Get Stable

### Curl

1.

## Set environment

### Verify variables

1. XXX
   Example:

    ```console
    echo %HOMEDRIVE%
    echo %HOMEPATH%
    ```

### XXX

1. :pencil2: XXX
   Example:

    ```console
    set SENZING_PROJECT_NAME=project01
    ```

### EULA

To use the Senzing code, you must agree to the End User License Agreement (EULA).

1. :warning: This step is intentionally tricky and not simply copy/paste.
   This ensures that you make a conscious effort to accept the EULA.
   Example:

    <pre>set SENZING_ACCEPT_EULA="&lt;the value from <a href="https://github.com/Senzing/knowledge-base/blob/master/lists/environment-variables.md#senzing_accept_eula">this link</a>&gt;"</pre>

### Synthesize variables

1. XXX
   Example:

    ```console
    set SENZING_PROJECT_DIR=%HOMEDRIVE%\%HOMEPATH%\%SENZING_PROJECT_NAME%

    set SENZING_DATA_DIR=%SENZING_PROJECT_DIR%\data
    set SENZING_DATA_VERSION_DIR=%SENZING_PROJECT_DIR%\data\1.0.0
    set SENZING_ETC_DIR=%SENZING_PROJECT_DIR%\etc
    set SENZING_G2_DIR=%SENZING_PROJECT_DIR%\g2
    set SENZING_VAR_DIR=%SENZING_PROJECT_DIR%\var
    ```

## Run docker images

### Download Senzing

1. XXX
   Example:

    ```console
    docker run ^
      --env SENZING_ACCEPT_EULA=%SENZING_ACCEPT_EULA% ^
      --rm ^
      --volume %SENZING_DATA_DIR%:/opt/senzing/data ^
      --volume %SENZING_G2_DIR%:/opt/senzing/g2 ^
      senzing/yum
    ```

### Configure files and database

1. XXX
   Example:

    ```console
    docker run ^
      --rm ^
      --volume %SENZING_DATA_VERSION_DIR%:/opt/senzing/data ^
      --volume %SENZING_ETC_DIR%:/etc/opt/senzing ^
      --volume %SENZING_G2_DIR%:/opt/senzing/g2 ^
      --volume %SENZING_VAR_DIR%:/var/opt/senzing ^
      senzing/init-container
    ```

### Populate database using G2Loader

:thinking: **Optional:** This optional step uses the `G2Loader.py` to populate
the Senzing Model with data.

1. Copy data to the %SENZING_VAR_DIR% folder.

1. Run the `senzing/xterm` docker container.
   Example:

    ```console
    docker run ^
      --interactive ^
      --rm ^
      --tty ^
      --volume %SENZING_DATA_VERSION_DIR%:/opt/senzing/data ^
      --volume %SENZING_ETC_DIR%:/etc/opt/senzing ^
      --volume %SENZING_G2_DIR%:/opt/senzing/g2 ^
      --volume %SENZING_VAR_DIR%:/var/opt/senzing ^
      senzing/xterm
    ```

1. Using a web browser, visit [localhost:5000](http://localhost:5000)
1. In Senzing Xterm, run

    ```console
    G2loader.py /var/opt/senzing/<name-of-file>
    ```

### Run Senzing API service

The [Senzing API Server](https://github.com/Senzing/senzing-api-server) will serve HTTP requests on port 8250

1. XXX
   Example:

    ```console
    docker run ^
      --publish 8250:8250 ^
      --rm ^
      --volume %SENZING_DATA_VERSION_DIR%:/opt/senzing/data ^
      --volume %SENZING_ETC_DIR%:/etc/opt/senzing ^
      --volume %SENZING_G2_DIR%:/opt/senzing/g2 ^
      --volume %SENZING_VAR_DIR%:/var/opt/senzing ^
      senzing/senzing-api-server ^
        -allowedOrigins "*" ^
        -bindAddr all ^
        -concurrency 10 ^
        -httpPort 8250 ^
        -iniFile /etc/opt/senzing/G2Module.ini
    ```

1. Use a curl call to verify the Senzing API Servie is running
   Example:

    ```console
    curl http://localhost:8250/heartbeat
    ```

1. Use the [Swagger Editor](http://editor.swagger.io/?url=https://raw.githubusercontent.com/Senzing/senzing-rest-api-specification/master/senzing-rest-api.yaml) to test drive the [Senzing API](https://github.com/Senzing/senzing-rest-api-specification).
