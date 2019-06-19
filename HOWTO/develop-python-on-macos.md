# Develop python on macOS

## Overview

The following is an example showing how to develop python scripts for
Senzing on macOS with the help of a Docker container.

The goal is to allow a user to use their macOS
Integrated Development Environment (IDE) on macOS natively,
but test the running of the scripts in a Linux Docker container.

## Steps

### Create SENZING_DIR

1. If you do not already have an `/opt/senzing` directory on your local system, visit
[HOWTO - Create SENZING_DIR](https://github.com/Senzing/knowledge-base/blob/master/HOWTO/create-senzing-dir.md).

1. Identify SENZING_DIR.
   Example:

    ```console
    export SENZING_DIR=/opt/senzing
    ```

### Identify the python scripts directory

1. Identify the directory that holds the python scripts.
   This can be a new or existing directory.
   Example:

    ```console
    export MY_DATA_DIR=~/example-senzing-python-project
    ```

1. If the directory doesn't exist, create the directory.
   Example:

    ```console
    mkdir -p ${MY_DATA_DIR}
    ```

### Example python script

1. Optional. For testing purposes, a test python script can be created.
   Example:

    ```console
    cat <<EOT > ${MY_DATA_DIR}/example-python.py
    #!/usr/bin/env python

    import os
    import json
    import sys

    debug = False

    # Establish directories and paths

    senzing_directory = os.environ.get("SENZING_DIR", "/opt/senzing")
    senzing_python_directory = "{0}/g2/python".format(senzing_directory)
    g2module_ini_pathname = "{0}/G2Module.ini".format(senzing_python_directory)

    # Add python directory to System Path

    sys.path.append(senzing_python_directory)

    # Initialize Senzing G2 modules.

    from G2Product import G2Product
    g2_product = G2Product()
    g2_product.init('pyG2Product', g2module_ini_pathname, debug)

    version_string = g2_product.version()
    version_dictionary = json.loads(version_string)
    print(json.dumps(version_dictionary, sort_keys=True, indent=4))
    EOT
    ```

### Run Docker container

1. Run the docker container using a SQLite database.
   Example:

   ```console
    sudo docker run \
      --interactive \
      --rm \
      --tty \
      --volume ${SENZING_DIR}:/opt/senzing \
      --volume ${MY_DATA_DIR}:/data \
      senzing/senzing-base
   ```

1. To use other databases, see
   [senzing/docker-senzing-base](https://github.com/Senzing/docker-senzing-base#run-docker-container).

### Run python scripts inside container

1. The `${MY_DATA_DIR}/example-python.py` script sitting on macOS
   is accessible as `/data/example-python.py` inside the running container.
   It can be run inside the container.
   Example:

    ```console
    $ cd /data

    $ python example-python.py
    {
        "BUILD_DATE": "2019-06-04",
        "BUILD_NUMBER": "2019_06_04__02_00",
        "COMPATIBILITY_VERSION": {
            "CONFIG_VERSION": "2"
        },
        "VERSION": "1.9.19155"
    }
    ```

### Modify python code

1. Because the files in the docker container at `/data` are actually on macOS at ${MY_DATA_DIR},
   they can be edited on macOS and run inside the Docker container.
