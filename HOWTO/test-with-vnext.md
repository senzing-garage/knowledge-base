# HOWTO - Test VNext


## Docker senzing stack

1. Create a docker-based Senzing installer.
   **NOTE:** By running the command using `--build-arg SENZING_ACCEPT_EULA` you consent to the Senzing EULA.
   Example:

    ```console
    sudo docker build \
      --build-arg SENZING_ACCEPT_EULA=I_ACCEPT_THE_SENZING_EULA \
      --build-arg SENZING_APT_INSTALL_PACKAGE=senzingapi \
      --build-arg SENZING_APT_REPOSITORY=https://senzing-staging-apt.s3.amazonaws.com/senzingstagingrepo_1.0.0-1_amd64.deb \
      --build-arg SENZING_DATA_VERSION=3.0.0 \
      --tag senzing/installer-staging:3.0.0 \
      https://github.com/senzing/docker-installer.git
    ```

1. :pencil2: Identify a new directory for the Senzing installation.
   Example:

    ```console
    export SENZING_VOLUME=~/senzing-3.0.0
    ```
