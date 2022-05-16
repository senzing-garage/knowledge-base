# Senzing and Jupyter on macOS

## Contents

1. [Expectations](#expectations)
    1. [Space](#space)
    1. [Time](#time)
    1. [Background knowledge](#background-knowledge)
1. [Preparation](#preparation)
    1. [Prerequisite software](#prerequisite-software)
    1. [Clone repositories](#clone-repositories)
    1. [Install python libraries](#install-python-libraries)
    1. [Create SENZING_DIR](#create-senzing_dir)
1. [Tutorial](#tutorial)
    1. [Native Jupyter Notebooks](#native-jupyter-notebooks)
    1. [Native Jupyter Notebooks with Senzing](#native-jupyter-notebooks-with-senzing)
    1. [Docker-based Jupyter Notebooks](#docker-based-jupyter-notebooks)
    1. [Database access](#database-access)

## Expectations

### Space

This repository and demonstration require 7 GB free disk space.

### Time

Budget 4 hours to get the demonstration up-and-running, depending on CPU and network speeds.

### Background knowledge

This repository assumes a working knowledge of:

1. [Docker](https://github.com/Senzing/knowledge-base/blob/main/WHATIS/docker.md)
1. [Jupyter](https://github.com/Senzing/knowledge-base/blob/main/WHATIS/jupyter.md)

## Preparation

### Prerequisite software

The following software programs need to be installed:

1. [Docker](https://github.com/Senzing/knowledge-base/blob/main/HOWTO/install-docker.md)
1. [Jupyter Notebooks](https://github.com/Senzing/knowledge-base/blob/main/HOWTO/install-jupyter-notebooks.md)

### Clone repositories

1. Set these environment variable values:

    ```console
    export GIT_ACCOUNT=senzing
    export GIT_REPOSITORY=docker-jupyter
    ```

1. Follow steps in [clone-repository](https://github.com/Senzing/knowledge-base/blob/main/HOWTO/clone-repository.md).

1. Set these environment variable values:

    ```console
    export GIT_ACCOUNT=docktermj
    export GIT_REPOSITORY=jupyter-examples
    ```

1. Follow steps in [clone-repository](https://github.com/Senzing/knowledge-base/blob/main/HOWTO/clone-repository.md).

### Install python libraries

1. Install python libraries

    ```console
    cd ~/docktermj.git/jupyter-examples
    sudo pip install -r requirements.txt
    ```

### Create SENZING_DIR

1. If you do not already have an `/opt/senzing` directory on your local system, visit
[HOWTO - Create SENZING_DIR](https://github.com/Senzing/knowledge-base/blob/main/HOWTO/create-senzing-dir.md).

### Pull senzing/jupyter

1. To get a headstart on a 5 GB download,  we'll start pulling senzing/jupyter.

    ```console
    docker pull senzing/jupyter
    ```

## Tutorial

### Native Jupyter Notebooks

1. Start Jupyter:

    ```console
    cd ~/docktermj.git/jupyter-examples/notebooks
    jupyter notebook
    ```
  
1. Play around by diving into folders and launching Jupyter Notebooks, i.e. *.ipynb files. Examples:
    1. bokeh
        1. bokeh-notebooks/quickstart/quickstart.ipynb
        1. bokeh-notebooks/tutorial/00 - Introduction and Setup.ipynb
    1. D3
        1. D3-in-Jupyter-Notebook/BAR CHART IN D3.ipynb
        1. D3-in-Jupyter-Notebook/SCATTER PLOT.ipynb
    1. Operating environment
        1. etc/software-versions.ipynb

1. [A gallery of interesting Jupyter Notebooks](https://github.com/jupyter/jupyter/wiki/A-gallery-of-interesting-Jupyter-Notebooks)

### Native Jupyter Notebooks with Senzing

1. Start Jupyter:

    ```console
    cd ~/senzing.git/docker-jupyter/notebooks
    jupyter notebook
    ```

1. Open senzing-utilities / senzing-license.ipynb

1. Click "Run" button multiple times.

1. You'll see an error on `from G2Product import G2Product`
    1. Reason: Senzing API isn't supported on macOS.
    1. So, we have to find a way to run it on Linux on macOS.
        1. Answer: Docker

### Docker-based Jupyter Notebooks

1. For reference, detailed instructions are at
   [senzing/jupyter](https://github.com/Senzing/docker-jupyter).

1. Launch docker container using SQLite.
   `SHARED_DIR` is a host-based folder for use within Jupyter.
   Example:

    ```console
    export WEBAPP_PORT=8888
    export SENZING_DIR=/opt/senzing
    export SHARED_DIR=/tmp

    sudo docker run -it \
      --name senzing-jupyter \
      --publish ${WEBAPP_PORT}:8888 \
      --rm \
      --volume ${SHARED_DIR}:/notebooks/shared \
      --volume ${SENZING_DIR}:/opt/senzing \
      senzing/jupyter \
        start.sh jupyter notebook --NotebookApp.token=''
    ```

1. Open a web browser on `http://localhost:8888`.

1. Like before, open senzing-utilities / senzing-license.ipynb

1. Click "Run" button multiple times.

1. This time, there is no error on `from G2Product import G2Product`.
    1. Reason: The docker container is running Linux.
    1. Even though `/opt/senzing` is on the local workstation.

1. Try other Senzing notebooks:
    1. senzing-examples/python/*
    1. senzing-utilities

### Database access

1. For information on running docker images that can access PostgreSQL, MySQL, or DB2,
   see [github.com/senzing/docker-jupyter](https://github.com/Senzing/docker-jupyter).  
