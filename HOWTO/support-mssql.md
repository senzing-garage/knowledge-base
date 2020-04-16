# How to support MS SQL

## Configuration

- **[SENZING_OPT_MICROSOFT_DIR](https://github.com/Senzing/knowledge-base/blob/master/lists/environment-variables.md#senzing_opt_microsoft_dir)**
- **[SENZING_VOLUME](https://github.com/Senzing/knowledge-base/blob/master/lists/environment-variables.md#senzing_volume)**

## Specify MS SQL driver location

1. :pencil2: Determine where to store MS SQL drivers.
   Examples:

    1. **Example #1:**

        ```console
        export SENZING_OPT_MICROSOFT_DIR=~/opt-microsoft
        ```

    1. **Example #2:**

        ```console
        export SENZING_VOLUME=/opt/my-senzing
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
    export SENZING_OPT_MICROSOFT_DIR_PARAMETER="--volume ${SENZING_OPT_MICROSOFT_DIR}:/opt/microsoft --env ODBCSYSINI=/opt/microsoft/msodbcsql17/etc"
    ```

## References

1. GitHub project for [senzing/apt](https://github.com/Senzing/docker-apt)
