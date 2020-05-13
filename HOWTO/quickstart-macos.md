# Quick Start for macOS

## Contents

1. [Prerequisites](#prerequisites)
1. [Install Senzing](#install-senzing)
1. [Identify Senzing database](#identify-senzing-database)
1. [Add Docker support](#add-docker-support)
1. [Run demonstration](#run-demonstration)

### Legend

1. :thinking: - A "thinker" icon means that a little extra thinking may be required.
   Perhaps there are some choices to be made.
   Perhaps it's an optional step.
1. :pencil2: - A "pencil" icon means that the instructions may need modification before performing.
1. :warning: - A "warning" icon means that something tricky is happening, so pay attention.

## Prerequisites

:thinking: The following tasks need to be complete before proceeding.
These are "one-time tasks" which may already have been completed.

1. The following software programs need to be installed and running on the workstation:
    1. [docker](https://github.com/Senzing/knowledge-base/blob/master/HOWTO/install-docker.md)
        1. Verify.
           Example:

            ```console
            sudo docker run hello-world
            ```

    1. [curl](https://github.com/Senzing/knowledge-base/blob/master/HOWTO/install-curl.md)
        1. Verify.
           Example:

            ```console
            curl --version
            ```

    1. [pip3](https://github.com/Senzing/knowledge-base/blob/master/HOWTO/install-pip3.md)
        1. Verify.
           Example:

            ```console
            pip3 --version
            ```

    1. Python modules.

        1. `pip3` installs.
           Example:

            ```console
            sudo pip3 install parse
            ```

        1. Verify.
           Bring up the Python REPL (Read-Evaluate-Print Loop).
           Example:

            ```console
            python3
            ```

           Copy and paste the following lines into the Python REPL:

            ```python
            import parse
            quit()
            ```

           If successful, no error will appear.

## Identify Senzing database

:thinking: **Optional, but recommended:**
By default, an SQLite database is used by the Quickstart instructions.
The system runs better with a PostgreSQL database.
If a PostgreSQL database is not desired, proceed to
[Initialize Senzing project](#initialize-senzing-project).

To set up a PostgreSQL database, visit
[Setup PostgreSQL on RedHat/CentOS](https://senzing.zendesk.com/hc/en-us/articles/360026348454-Setup-PostgreSQL-on-RedHat-CentOS).

Once the PostgreSQL database is running and has a Senzing schema installed,
perform the following steps:

1. :pencil2: Specify database.
   Example:

    ```console
    export DATABASE_PROTOCOL=postgresql
    export DATABASE_USERNAME=postgres
    export DATABASE_PASSWORD=postgres
    export DATABASE_HOST=db.example.com
    export DATABASE_PORT=5432
    export DATABASE_DATABASE=G2
    ```

1. :thinking: If the `DATABASE_HOST` is the workstation running docker containers,
   do not use `localhost` nor `127.0.0.1` for value of `DATABASE_HOST`.
   Reason: the value of `DATABASE_HOST` needs to be from the perspective of *inside* the docker container.
   To find the IP address of workstation, set the
   [SENZING_DOCKER_HOST_IP_ADDR](https://github.com/Senzing/knowledge-base/blob/master/lists/environment-variables.md#senzing_docker_host_ip_addr)
   environment variable. Then set:

    ```console
    export DATABASE_HOST=${SENZING_DOCKER_HOST_IP_ADDR}
    ```

1. Construct Database URL.
   Example:

    ```console
    export SENZING_DATABASE_URL="${DATABASE_PROTOCOL}://${DATABASE_USERNAME}:${DATABASE_PASSWORD}@${DATABASE_HOST}:${DATABASE_PORT}/${DATABASE_DATABASE}"
    ```

## Add Docker support

These steps add files to the Senzing project used to bring up Docker containers.

1. Get a local copy of
   [senzing-environment.py](https://raw.githubusercontent.com/Senzing/senzing-environment/master/senzing-environment.py).
   Example:

    1. :pencil2: Specify where to download file.
       Example:

        ```console
        export SENZING_DOWNLOAD_FILE=~/senzing-environment.py
        ```

    1. Download file.
       Example:

        ```console
        curl -X GET \
          --output ${SENZING_DOWNLOAD_FILE} \
          https://raw.githubusercontent.com/Senzing/senzing-environment/master/senzing-environment.py
        ```

    1. Make file executable.
       Example:

        ```console
        chmod +x ${SENZING_DOWNLOAD_FILE}
        ```

1. Run the command to create additional files in the Senzing repository for Docker support.
   Example:

   ```console
   ${SENZING_DOWNLOAD_FILE} add-quickstart-support-macos --project-dir ${SENZING_PROJECT_DIR}
   ```

## Install Senzing

1. Install on macOS via dockerized `yum`.
   Example:

    ```console
    sudo ${SENZING_PROJECT_DIR}/docker-bin/senzing-yum.sh
    ```



## Run demonstration

1. Start Entity search webapp.
   Example:

    ```console
    sudo ${SENZING_PROJECT_DIR}/docker-bin/senzing-quickstart-demo.sh
    ```

   On first use, the Docker image will be automatically downloaded from
   [DockerHub](https://hub.docker.com/) and cached in the workstation's local Docker repository.

1. View [Entity search webapp](http://localhost:8251/).
    1. Search for "Robert Jones"
