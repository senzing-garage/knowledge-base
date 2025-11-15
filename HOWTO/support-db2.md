# How to support Db2

## Configuration

- **[SENZING_OPT_IBM_DIR](https://github.com/senzing-garage/knowledge-base/blob/main/lists/environment-variables.md#senzing_opt_ibm_dir)**
- **[SENZING_VOLUME](https://github.com/senzing-garage/knowledge-base/blob/main/lists/environment-variables.md#senzing_volume)**

## Specify Db2 driver location

1. :pencil2: Determine where to store IBM Db2 drivers.
   Examples:
   1. **Example #1:** A `SENZING_VOLUME` based approach.

      ```console
      export SENZING_VOLUME=/opt/my-senzing
      export SENZING_OPT_IBM_DIR=${SENZING_VOLUME}/opt-ibm
      ```

   1. **Example #2:** Direct specification.

      ```console
      export SENZING_OPT_IBM_DIR=~/opt-ibm
      ```

## Install Db2 drivers

1. Run container.
   Example:

   ```console
   docker run \
     --rm \
     --volume ${SENZING_OPT_IBM_DIR}:/opt/IBM \
     senzing/db2-driver-installer:1.0.1
   ```

## Set parameter for docker run

1. Construct parameter for `docker run`.
   Example:

   ```console
   export SENZING_OPT_IBM_DIR_PARAMETER="--volume ${SENZING_OPT_IBM_DIR}:/opt/IBM"
   ```

## References

1. GitHub project for [senzing/db2-driver-installer](https://github.com/senzing-garage/docker-db2-driver-installer)
