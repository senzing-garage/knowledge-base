# Senzing and Jupyter on macOS

## Contents

1. [Expectations](#expectations)
    1. [Space](#space)
    1. [Time](#time)
    1. [Background knowledge](#background-knowledge)
1. [Preparation](#preparation)
    1. [Prerequisite software](#prerequisite-software)
    1. [Clone repository](#clone-repository)
    1. [Create SENZING_DIR](#create-senzing_dir)
1. [Tutorial](#tutorial)

## Expectations

### Space

This repository and demonstration require 7 GB free disk space.

### Time

Budget 2 hours to get the demonstration up-and-running, depending on CPU and network speeds.

### Background knowledge

This repository assumes a working knowledge of:

1. [Docker](https://github.com/Senzing/knowledge-base/blob/master/WHATIS/docker.md)
1. [Jupyter](https://github.com/Senzing/knowledge-base/blob/master/WHATIS/jupyter.md)

## Preparation

### Prerequisite software

The following software programs need to be installed:

1. [Docker](https://github.com/Senzing/knowledge-base/blob/master/HOWTO/install-docker.md)
1. [Jupyter Notebooks](https://github.com/Senzing/knowledge-base/blob/master/HOWTO/install-jupyter-notebooks.md)

### Clone repositories

1. Set these environment variable values:

    ```console
    export GIT_ACCOUNT=senzing
    export GIT_REPOSITORY=docker-jupyter
    ```

1. Follow steps in [clone-repository](https://github.com/Senzing/knowledge-base/blob/master/HOWTO/clone-repository.md).

1. Set these environment variable values:

    ```console
    export GIT_ACCOUNT=docktermj
    export GIT_REPOSITORY=jupyter-examples
    ```

1. Follow steps in [clone-repository](https://github.com/Senzing/knowledge-base/blob/master/HOWTO/clone-repository.md).



### Create SENZING_DIR

1. If you do not already have an `/opt/senzing` directory on your local system, visit
[HOWTO - Create SENZING_DIR](https://github.com/Senzing/knowledge-base/blob/master/HOWTO/create-senzing-dir.md).

## Tutorial

### Native Jupyter Notesbooks

1. Start Jupyter:

    ```console
    cd ~/senzing.git/jupyter-jupyter/notebooks
    jupyter notebook
    ```

1. Open senzing-utilities / senzing-license.ipynb

1. Click "Run" button multiple times

1. You'll see an error on `from G2Product import G2Product`
    1. Reason: Senzing API isn't supported on macOS.
    1. So, we have to find a way to run it on Linux on macOS
    1. Answer: Docker
    
1. However, Jupyter Notebooks can be used to develop python programs that do not access the Senzing API.
    1. Examples:
        1. Analyze / Graph JSON, CSV
        2. Transform or generate data

### Docker-based Jupyter Notebooks
