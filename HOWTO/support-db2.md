# Support Db2

## Specify Db2 driver location

1. :pencil2: Determine where to store IBM Db2 drivers.
   Examples:

    ```console
    export SENZING_OPT_IBM_DIR=~/opt-ibm
    ```

    ```console
    export SENZING_VOLUME=/opt/my-senzing
    export SENZING_OPT_IBM_DIR=${SENZING_VOLUME}/opt-ibm
    ```

## Install Db2 drivers

1. Run container.
   Example:

    ```console
    docker run \
      --rm \
      --volume ${SENZING_OPT_IBM_DIR}:/opt/IBM \
      senzing/db2-driver-installer:1.0.0
    ```

## Set parameter for docker run

1. Construct parameter for `docker run`.
   Example:

    ```console
    export SENZING_OPT_IBM_DIR_PARAMETER="--volume ${SENZING_OPT_IBM_DIR}:/opt/ibm"
    ```
