# HOWTO - Install Senzing for Go Development

The following steps show how to install and configure Senzing for Go development.

## Install Senzing

This can be done by installing the Senzing package using `apt`, `yum`,
or a technique using Docker containers.
Once complete, the Senzing library will be installed in the `/opt/senzing` directory.
This is important as the compiling of the Go code expects Senzing to be in `/opt/senzing`.

- Using `apt`:

    ```console
    wget https://senzing-production-apt.s3.amazonaws.com/senzingrepo_1.0.0-1_amd64.deb
    sudo apt install ./senzingrepo_1.0.0-1_amd64.deb
    sudo apt update
    sudo apt install senzingapi

    ```

- Using `yum`:

    ```console
    sudo yum install https://senzing-production-yum.s3.amazonaws.com/senzingrepo-1.0.0-1.x86_64.rpm
    sudo yum install senzingapi

    ```

- Using Docker:

  This technique can be handy if you are using MacOS or Windows and cross-compiling.

    1. Build Senzing installer.

        ```console
        curl -X GET \
            --output /tmp/senzing-versions-stable.sh \
            https://raw.githubusercontent.com/Senzing/knowledge-base/main/lists/senzing-versions-stable.sh
        source /tmp/senzing-versions-stable.sh

        sudo docker build \
            --build-arg SENZING_ACCEPT_EULA=I_ACCEPT_THE_SENZING_EULA \
            --build-arg SENZING_APT_INSTALL_PACKAGE=senzingapi=${SENZING_VERSION_SENZINGAPI_BUILD} \
            --build-arg SENZING_DATA_VERSION=${SENZING_VERSION_SENZINGDATA} \
            --no-cache \
            --tag senzing/installer:${SENZING_VERSION_SENZINGAPI} \
            https://github.com/senzing/docker-installer.git#main

        ```

    1. Install Senzing.

        ```console
            curl -X GET \
                --output /tmp/senzing-versions-stable.sh \
                https://raw.githubusercontent.com/Senzing/knowledge-base/main/lists/senzing-versions-stable.sh
            source /tmp/senzing-versions-stable.sh

            sudo rm -rf /opt/senzing
            sudo mkdir -p /opt/senzing

            sudo docker run \
                --rm \
                --user 0 \
                --volume /opt/senzing:/opt/senzing \
                senzing/installer:${SENZING_VERSION_SENZINGAPI}

        ```

## Configure Senzing

1. Move the "versioned" Senzing data to the system location.
   Example:

    ```console
      sudo mv /opt/senzing/data/3.0.0/* /opt/senzing/data/

    ```

1. Create initial configuration.
   Example:

    ```console
    export SENZING_ETC_FILES=( \
        "cfgVariant.json" \
        "customGn.txt" \
        "customOn.txt" \
        "customSn.txt" \
        "defaultGNRCP.config" \
        "g2config.json" \
        "G2Module.ini" \
        "stb.config" \
    )

    sudo mkdir /etc/opt/senzing
    for SENZING_ETC_FILE in ${SENZING_ETC_FILES[@]}; \
    do \
        sudo --preserve-env cp /opt/senzing/g2/resources/templates/${SENZING_ETC_FILE} /etc/opt/senzing/${SENZING_ETC_FILE}
    done

    ```
