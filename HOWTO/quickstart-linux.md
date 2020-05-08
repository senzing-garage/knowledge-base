# Quick Start for linux

Based on
[Quickstart Guide](https://senzing.zendesk.com/hc/en-us/articles/115002408867-Quickstart-Guide).

## Contents

1. [Prerequisites](#prerequisites)
1. [Install Senzing](#install-senzing)
    1. [Install Senzing using Yum](#install-senzing-using-yum)
    1. [Install Senzing using Apt](#install-senzing-using-apt)
1. [Create a Senzing project](#create-a-senzing-project)
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

1. The following software programs need to be installed:
    1. [docker](https://github.com/Senzing/knowledge-base/blob/master/HOWTO/install-docker.md)

## Install Senzing

Depending on the distribution of Linux, there are different ways of installing Senzing.

1. For installation on Red Hat, CentOS, openSuse and
   [others](https://en.wikipedia.org/wiki/List_of_Linux_distributions#RPM-based).
    1. Proceed to [Install Senzing using Yum](#install-senzing-using-yum)
1. For installation on Debian, Ubuntu and
   [others](https://en.wikipedia.org/wiki/List_of_Linux_distributions#Debian-based).
    1. Proceed to [Install Senzing using Apt](#install-senzing-using-apt)

### Install Senzing using Yum

1. Add the Senzing yum repository to the local workstation.
   Example:

    ```console
    sudo yum install https://senzing-production-yum.s3.amazonaws.com/senzingrepo-1.0.0-1.x86_64.rpm
    ```

1. :thinking: Install Senzing with `yum`.
   During the installation there will be prompts for acceptance.
   Some prompts are for the
   [Senzing End User License Agreement](https://senzing.com/end-user-license-agreement/) (EULA).
   Example:

    ```console
    sudo yum install senzingapi
    ```

1. Proceed to [Create a Senzing project](#create-a-senzing-project).

### Install Senzing using Apt

1. Add required system packages.
   Example:

    ```console
    sudo apt install apt-transport-https
    ```

1. Add the Senzing apt repository to the local workstation.
   Example:

    1. Download a `deb` package that will be used to add Senzing to the local apt repository.
       Example:

        ```console
        curl -X GET \
          --output ~/senzingrepo_1.0.0-1_amd64.deb
          https://senzing-production-apt.s3.amazonaws.com/senzingrepo_1.0.0-1_amd64.deb
        ```

    1. Add Senzing to the local apt repository.
       Example:

        ```console
        sudo apt install ~/senzingrepo_1.0.0-1_amd64.deb
        ```

    1. Update the local apt repository.
       Example:

        ```console
        sudo apt update
        ```

    1. The `deb` file is no longer needed.
       It may be deleted.
       Example:

        ```console
        rm  ~/senzingrepo_1.0.0-1_amd64.deb
        ```

1. :thinking: Install Senzing with `apt`.
   During the installation there will be prompts for acceptance.
   Some prompts are for the
   [Senzing End User License Agreement](https://senzing.com/end-user-license-agreement/)(EULA).
   Example:

    ```console
    sudo apt install senzingapi
    ```

## Create a Senzing project

1. Specify the location of the Senzing project on the host system.
   Example:

    ```console
    export SENZING_PROJECT_DIR=~/senzing-demo-project-1
    ```

1. Create the Senzing project.
   Example:

    ```console
    /opt/senzing/g2/python/G2CreateProject.py ${SENZING_PROJECT_DIR}
    ```

## Initialize Senzing project

These steps initialize the Senzing project by
installing configuration into the Senzing database and adding exemplar data.

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

1. Load example data.
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

1. Add python modules.
   Example:

   ```console
   sudo pip3 install parse
   ```

1. Run the command.
   Example:

   ```console
   ${SENZING_DOWNLOAD_FILE} add-quickstart-support --project-dir ${SENZING_PROJECT_DIR}
   ```

## Run demonstration

1. Start webapp demo.
   Example:

    ```console
    sudo ${SENZING_PROJECT_DIR}/docker-bin/senzing-quickstart-demo.sh
    ```

1. Verify the system works.
   View  [Entity search webapp](http://localhost:8251/)
    1. Search for "Robert Jones"
