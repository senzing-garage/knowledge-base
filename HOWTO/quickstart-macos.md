# Quick Start for macOS

## Contents

1. [Prerequisites](#prerequisites)
1. [Identify Senzing database](#identify-senzing-database)
1. [Identify Senzing project](#identify-senzing-project)
1. [Add Docker support](#add-docker-support)
1. [EULA](#eula)
1. [Install Senzing](#install-senzing)
1. [Configure Senzing](#configure-senzing)
1. [Load Senzing model](#load-senzing-model)
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
    1. [docker](https://github.com/Senzing/knowledge-base/blob/master/HOWTO/install-docker.md#macos)

        1. Verify sufficient resources.
            1. Docker desktop > "Preferences..." > "Resources" > "Advanced"
                1. **CPUs:** 4
                1. **Memory:** 4 GB
                1. **Swap:** 1 GB
                1. **Disk image size:** 60 GB
            1. Docker desktop > "Preferences..." > "Kubernetes"
                1. Uncheck "Enable Kubernetes"
            1. Click "Apply & Restart"
        1. Verify.
           Example:

            ```console
            sudo docker run hello-world
            ```

    1. [curl](https://github.com/Senzing/knowledge-base/blob/master/HOWTO/install-curl.md#macos)
        1. Verify.
           Example:

            ```console
            curl --version
            ```

## Identify Senzing database

:thinking: **Optional, but recommended:**
By default, an SQLite database is used by the Quickstart instructions.
The system runs better with a PostgreSQL database.
If a PostgreSQL database is not desired, proceed to
[Add Docker support](#add-docker-support).

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

## Identify Senzing project

1. :pencil2: Specify the location of the Senzing project on the host system.
   Example:

    ```console
    export SENZING_PROJECT_DIR=~/senzing-demo-project-1
    ```

## Add Docker support

These steps add files to the `${SENZING_PROJECT_DIR}/docker-bin` directory that are used to bring up Docker containers.

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
    ${SENZING_DOWNLOAD_FILE} add-docker-support-macos --project-dir ${SENZING_PROJECT_DIR}
    ```

## EULA

:thinking: **Optional:** To use the Senzing code, you must agree to the Senzing End User License Agreement (EULA).
The EULA is located at [https://senzing.com/end-user-license-agreement](https://senzing.com/end-user-license-agreement/).
To improve automation, an environment variable may be set to accept the EULA.
If no environment variable is set, the installer will prompt for the EULA acceptance before installing.
If manual acceptance is preferred, proceed to [Install Senzing](#install-senzing).

1. :warning: This step is intentionally tricky and not simply copy/paste.
   This ensures that you make a conscious effort to accept the EULA.
   Example:

    <pre>export SENZING_ACCEPT_EULA="&lt;the value from <a href="https://github.com/Senzing/knowledge-base/blob/master/lists/environment-variables.md#senzing_accept_eula">this link</a>&gt;"</pre>

## Install Senzing

These steps install Senzing in the `${SENZING_PROJECT_DIR}/g2` and `${SENZING_PROJECT_DIR}/data` directories.

1. Install on macOS via dockerized `yum` job.
   Once the job is done, the container will exit.
   **Note:**  If the `SENZING_ACCEPT_EULA` environment variable is not set correctly,
   the installation will prompt for EULA acceptance.
   Example:

    ```console
    sudo --preserve-env ${SENZING_PROJECT_DIR}/docker-bin/senzing-yum.sh
    ```

## Configure Senzing

These steps create and configure `${SENZING_PROJECT_DIR}/docker-etc` and `${SENZING_PROJECT_DIR}/var` directories.

1. Start an initialization job Docker container.
   Once the job is done, the container will exit.
   Example:

    ```console
    sudo ${SENZING_PROJECT_DIR}/docker-bin/senzing-init-container.sh
    ```

## Load Senzing model

These steps load the Senzing Model with sample data.

1. Start a Senzing X-Term Docker container.
   Example:

    ```console
    sudo ${SENZING_PROJECT_DIR}/docker-bin/senzing-xterm.sh
    ```

1. :thinking: There are 2 methods of creating a terminal inside the Docker container.

    1. **Method #1:** Senzing X-term is viewable at
       [localhost:8254](http://localhost:8254).

    1. **Method #2:** "ssh" into running Docker container.
       Example:

        ```console
        sudo ${SENZING_PROJECT_DIR}/docker-bin/senzing-xterm-shell.sh
        ```

1. :thinking: **Optional:** In Senzing X-term, specify if the Senzing model data should be deleted.

   :warning: The use of the `-P` parameter will purge the database before new data is ingested.
   If you want to keep the existing Senzing model data, ***don't*** set `SENZING_PURGE`.
   Example:

    ```console
    export SENZING_PURGE="-P"
    ```

1. In Senzing X-term, load sample data.
   Example:

    ```console
    G2Loader.py ${SENZING_PURGE} -c /etc/opt/senzing/G2Project.ini
    ```

## Run demonstration

These steps show the sample data in a web application.

1. Start Senzing entity search webapp Docker container.
   Example:

    ```console
    sudo ${SENZING_PROJECT_DIR}/docker-bin/senzing-quickstart-demo.sh
    ```

1. Senzing entity search webapp is viewable at
   [localhost:8251](http://localhost:8251/).
    1. Search for "Robert Jones"
