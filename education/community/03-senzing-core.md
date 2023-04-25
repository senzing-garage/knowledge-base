# The core of Senzing

This exercise will be done in a docker container.
Please realize that when the docker container is exited,
everything goes away.

## Install Senzing

In this step, we'll use a docker container to
see how the Senzing RPM is installed on a Linux system.

1. Start a container.
   Example:

    ```console
    docker run \
      --interactive \
      --rm \
      --tty \
      ubuntu /bin/bash
    ```

1. Inside the running container,
   install the YUM repository metadata.
   Example:

    ```console
    apt update
    apt install -y wget
    wget https://senzing-production-apt.s3.amazonaws.com/senzingrepo_1.0.1-1_amd64.deb
    apt install -y ./senzingrepo_1.0.1-1_amd64.deb
    apt update
    apt install senzingapi
    ```

1. Inside the running container,
   install Senzing.
   Example:

    ```console
    yum -y install \
      senzingapi
    ```

   :warning: This step download about 6GB worth of data.
   So it may take a while, depending on your network speed.

1. :eyes: Notice that the instructions are very similar to the `Dockerfile` in the
   [senzing/docker-yum](https://github.com/Senzing/docker-yum) repository.
   For a Debian/Ubuntu install, look at the
   [senzing/docker-apt](https://github.com/Senzing/docker-apt)
   `Dockerfile`.

## Viewing Senzing files

Everything installed by the RPM is in `/opt/senzing`.

1. `/opt/senzing/data`
    1. This was actually installed via the `senzingdata-vX` package.
    1. It is almost 2GB of data that doesn't change often.
       That is, it's usually not updated when there is a new release of `senzingapi` package.
    1. This is a versioned directory.  For instance, there may be `/opt/senzing/1.0.0` and `/opt/senzing/2.0.0` directories.
    1. The directories contain static models of data used by Senzing.
1. `/opt/senzing/g2`
    1. This directory is installed via the `senzingapi` package.
    1. The version of Senzing can be seen in `cat /opt/senzing/g2/g2BuildVersion.json`

        ```console
        cat /opt/senzing/g2/g2BuildVersion.json
        ```

1. `/opt/senzing/g2/bin`
    1. Binary executables
1. `/opt/senzing/g2/lib`
    1. Linux "shared objects" including Senzing binaries ("libg2*") as well as dependencies.
    1. This directory is usually part of the `LD_LIBRARY_PATH`.
       Can be seen in [senzing/docker-senzing-base](https://github.com/Senzing/docker-senzing-base) Dockerfile.
    1. `g2.jar` is a Java wrapper over the C API.
    1. `jre` is for Java plugins.
1. `/opt/senzing/g2/python`
    1. Python bindings for C API and Python-based Senzing utility programs.
    1. `opt/senzing/g2/python/demo` has sample data.  (Not sure why it's here and not `/opt/senzing/g2/resources/xxxx`
1. `/opt/senzing/g2/resources`
    1. `/opt/senzing/g2/resources/config` is a set files for updating Senzing configuration from release to release.
    1. `/opt/senzing/g2/resources/schema` has files for database creation and updating.
    1. `/opt/senzing/g2/resources/templates` has "template" files.
        1. `G2C.db.template` is an example SQLite database.
        1. Other template files that can be instantiated using `envsubst`.

## Install Senzing files on a local system

1. Download the RPM to your local system.
    1. See [senzing/docker-yumdownloader](https://github.com/Senzing/docker-yumdownloader)

1. Assuming the RPM is in your `~/Downloads` directory, create a bash script like the following.
   Modify the `SENZING_API_RPM` and `SENZING_DATA_RPM` variables to match the files downloaded by the "yumdownloader".
   Then, run the bash script.

    ```bash
    #!/usr/bin/env bash

    # Verify that sudo and docker are active.

    sudo -p "sudo access is required.  Please enter your password:  " docker info >> /dev/null 2>&1

    # User Variables

    export SENZING_API_RPM=senzingapi-2.5.0-21104.x86_64.rpm
    export SENZING_DATA_RPM=senzingdata-v2-2.0.0-1.x86_64.rpm

    # Variables

    export SENZING_VOLUME=/opt/my-senzing
    export SENZING_DATA_DIR=${SENZING_VOLUME}/data
    export SENZING_DATA_VERSION_DIR=${SENZING_DATA_DIR}/1.0.0
    export SENZING_ETC_DIR=${SENZING_VOLUME}/etc
    export SENZING_G2_DIR=${SENZING_VOLUME}/g2
    export SENZING_VAR_DIR=${SENZING_VOLUME}/var
    export SENZING_ACCEPT_EULA=I_ACCEPT_THE_SENZING_EULA

    # Remove old directory

    sudo rm -rf ${SENZING_VOLUME}

    # Install via docker senzing/yum

    sudo docker run \
      --env SENZING_ACCEPT_EULA=${SENZING_ACCEPT_EULA} \
      --rm \
      --volume ${SENZING_DATA_DIR}:/opt/senzing/data \
      --volume ${SENZING_G2_DIR}:/opt/senzing/g2 \
      --volume ${SENZING_ETC_DIR}:/etc/opt/senzing \
      --volume ${SENZING_VAR_DIR}:/var/opt/senzing \
      --volume ~/Downloads:/data \
      senzing/yum -y localinstall \
        /data/${SENZING_API_RPM} \
        /data/${SENZING_DATA_RPM}
    ```

1. After the bash script has run, the files will be in `/opt/my-senzing`.
