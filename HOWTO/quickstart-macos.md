# Quick Start for macOS

Based on
[Quickstart Guide](https://senzing.zendesk.com/hc/en-us/articles/115002408867-Quickstart-Guide).

## Contents

1. [Prerequisites](#prerequisites)
1. [Install Senzing](#install-senzing)
1. [Create a Senzing project](#create-a-senzing-project)
1. [Identify Senzing database](#identify-senzing-database)
1. [Initialize Senzing project](#initialize-senzing-project)
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

## Install Senzing

1. Identify system install location.
   **Note:** The system install location must be `/opt/senzing`.

    ```console
    export SENZING_VOLUME=/opt/senzing
    ```

1. :warning:
   **macOS** - [File sharing](https://github.com/Senzing/knowledge-base/blob/master/HOWTO/share-directories-with-docker.md#macos)
   must be enabled for `SENZING_VOLUME`.


1. Identify directories on the local host.
   Example:

    ```console
    export SENZING_DATA_DIR=${SENZING_VOLUME}/data
    export SENZING_G2_DIR=${SENZING_VOLUME}/g2
    ```

1. Install Senzing on macOS using Docker container running `yum`.
   During the installation there will be prompts for acceptance.
   Some prompts are for the
   [Senzing End User License Agreement](https://senzing.com/end-user-license-agreement/) (EULA).
   Example:

    ```console
    sudo docker run \
      --interactive \
      --rm \
      --tty \
      --volume ${SENZING_DATA_DIR}:/opt/senzing/data \
      --volume ${SENZING_G2_DIR}:/opt/senzing/g2 \
      senzing/yum
    ```

## Create a Senzing project

1. :pencil2: Specify the location of the Senzing project on the host system.
   Example:

    ```console
    export SENZING_PROJECT_DIR=~/senzing-demo-project-1
    ```

1. Create the Senzing project.
   Example:

    ```console
    /opt/senzing/g2/python/G2CreateProject.py ${SENZING_PROJECT_DIR}
    ```

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

1. Install system packages for PostgreSQL client.

    1. Yum-based install.
       Example:

        ```console
        sudo yum install postgresql-libs
        ```

    1. Apt-based install.
       Example:

        ```console
        sudo apt install libpq5
        ```

1. Edit `${SENZING_PROJECT_DIR}/etc/G2Module.ini`
   Example:

    ```console
    vi ${SENZING_PROJECT_DIR}/etc/G2Module.ini
    ```

1. :pencil2: Modify contents of `${SENZING_PROJECT_DIR}/etc/G2Module.ini`.
   Change the SQL.CONNECTION value to point to the PostgreSQL instance
   using the `username`, `password`, and `hostname` of the PostgreSQL instance.
   Example:

    ```ini
    [SQL]
       CONNECTION=postgresql://username:password@hostname:5432:G2/
    ```

   When complete, the entire file might look something like this:

    ```ini
    [PIPELINE]
     SUPPORTPATH=/home/username/senzing-demo-project-1/data
     CONFIGPATH=/home/username/senzing-demo-project-1/etc
     RESOURCEPATH=/home/username/senzing-demo-project-1/resources

    [SQL]
     CONNECTION=postgresql://postgres:postgres@10.1.1.102:5432:G2/
    ```

## Initialize Senzing project

These steps initialize the Senzing project by
installing configuration into the Senzing database and adding sample data.

1. Set environment variables
   Example:

    ```console
    cd ${SENZING_PROJECT_DIR}
    source setupEnv
    ```

1. :thinking: Prime the database.
   A prompt will be given, type "yes".
   Example:

    ```console
    python3 python/G2SetupConfig.py
    ```

1. Load sample data.
   Example:

    ```console
    python3 python/G2Loader.py -P
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
   ${SENZING_DOWNLOAD_FILE} add-quickstart-support --project-dir ${SENZING_PROJECT_DIR}
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
