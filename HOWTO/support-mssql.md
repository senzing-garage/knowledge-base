# Support MS SQL

## Specify MS SQL driver location

1. Determine where to store MS SQL drivers.
   Examples:

    ```console
    export SENZING_OPT_MICROSOFT_DIR=~/opt-microsoft
    ```

    ```console
    export SENZING_OPT_MICROSOFT_DIR=${SENZING_VOLUME}/opt-microsoft
    ```

## Install MS SQL drivers

1. Run container.
   Example:

    ```console
    docker run \
      --env ACCEPT_EULA=Y \
      --rm \
      --volume ${SENZING_OPT_MICROSOFT_DIR}:/opt/microsoft \
      senzing/apt:1.0.0 -y install msodbcsql17
    ```

## Set parameter for docker run

1. Construct parameter for `docker run`.
   Example:

    ```console
    export SENZING_OPT_MICROSOFT_DIR_PARAMETER="--volume ${SENZING_OPT_MICROSOFT_DIR}:/opt/microsoft"
    ```
