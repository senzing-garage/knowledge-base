# Senzing and Jupyter on macOS

## Contents

## Preparation

### Prerequisite software

The following software programs need to be installed:

1. [Jupyter Notebooks](https://github.com/Senzing/knowledge-base/blob/master/HOWTO/install-jupyter-notebooks.md)
1. [Docker](https://github.com/Senzing/knowledge-base/blob/master/HOWTO/install-docker.md)

### Create SENZING_DIR

1. If you do not already have an `/opt/senzing` directory on your local system, visit
[HOWTO - Create SENZING_DIR](https://github.com/Senzing/knowledge-base/blob/master/HOWTO/create-senzing-dir.md).

### Clone repository

1. Set these environment variable values:

    ```console
    export GIT_ACCOUNT=senzing
    export GIT_REPOSITORY=docker-jupyter
    ```

1. Follow steps in [clone-repository](https://github.com/Senzing/knowledge-base/blob/master/HOWTO/clone-repository.md).

1. After the repository has been cloned, be sure the following are set:

    ```console
    export GIT_ACCOUNT_DIR=~/${GIT_ACCOUNT}.git
    export GIT_REPOSITORY_DIR="${GIT_ACCOUNT_DIR}/${GIT_REPOSITORY}"
    ```

## Tutorial

### Native Jupyter Notesbooks

1. Start Jupyter:

    ```console
    cd ~
    
    jupyter notebook
    ```

1. Open senzing.git / docker-jupyter / notebooks / senzing-examples / python / senzing-getSummaryData.ipynb

1. Click "Run" button multiple times

1. You'll see an error on `from G2Audit import G2Audit`
    1. Reason: Senzing API isn't supported on macOS.
    1. So, we have to find a way to run it on Linux on macOS
    1. Answer: Docker
    
1. However, Jupyter Notebooks can be used to develop python programs that do not access the Senzing API.
    1. Examples:
        1. Analyze / Graph JSON, CSV
        2. Transform or generate data

### Docker-based Jupyter Notebooks
