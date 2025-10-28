# HOWTO - Install Senzing for Go Development

The following steps show how to install and configure Senzing for Go development.

## Install Senzing

### Install Senzing - Linux

This can be done by installing the Senzing package using `apt`, `yum`,
or a technique using Docker containers.
Once complete, the Senzing library will be installed in the `/opt/senzing` directory.
This is important as the compiling of the Go code expects Senzing to be in `/opt/senzing`.

#### Install Senzing - Linux - Using apt

- Using `apt`:

  ```console
  wget https://senzing-production-apt.s3.amazonaws.com/senzingrepo_1.0.0-1_amd64.deb
  sudo apt install ./senzingrepo_1.0.0-1_amd64.deb
  sudo apt update
  sudo apt install senzingapi
  ```

#### Install Senzing - Linux - Using yum

- Using `yum`:

  ```console
  sudo yum install https://senzing-production-yum.s3.amazonaws.com/senzingrepo-1.0.0-1.x86_64.rpm
  sudo yum install senzingapi
  ```

#### Install Senzing - Linux - Using docker - staging

1. Build a docker container for determining staging versions.

    ```console
    docker build \
    --build-arg SENZING_APT_REPOSITORY_URL=https://senzing-staging-apt.s3.amazonaws.com/senzingstagingrepo_2.0.1-1_all.deb \
    --no-cache \
    --tag senzing/apt-staging:latest \
    https://github.com/senzing-garage/docker-apt.git#main
    ```

1. Locate recent version.

    ```console
    docker run --rm senzing/apt-staging list -a | grep senzing
    docker run --rm senzing/apt-staging list -a senzingsdk-poc
    ```

1. :pencil2: Specify package and version.

   Example:

    ```console
    export SENZING_PACKAGE=senzingsdk-poc
    export SENZING_PACKAGE_VERSION="4.1.1-25295"
    ```

1. Build a docker container for installing.

    ```console
    docker build \
        --build-arg ACCEPT_EULA=Y \
        --build-arg SENZING_ACCEPT_EULA=I_ACCEPT_THE_SENZING_EULA \
        --build-arg SENZING_APT_INSTALL_PACKAGE="${SENZING_PACKAGE}=${SENZING_PACKAGE_VERSION}" \
        --build-arg SENZING_APT_REPOSITORY_URL=https://senzing-staging-apt.s3.amazonaws.com/senzingstagingrepo_2.0.1-1_all.deb \
        --no-cache \
        --tag senzing/installer-${SENZING_PACKAGE}-staging:${SENZING_PACKAGE_VERSION} \
        https://github.com/senzing-garage/docker-installer.git#main
    ```

1. Install to specific directory.

    ```console
    export SENZING_OPT_SENZING_DIR=/opt/${SENZING_PACKAGE}-${SENZING_PACKAGE_VERSION}
    sudo mkdir -p ${SENZING_OPT_SENZING_DIR}

    docker run \
        --rm \
        --user 0 \
        --volume ${SENZING_OPT_SENZING_DIR}:/opt/senzing \
        senzing/installer-${SENZING_PACKAGE}-staging:${SENZING_PACKAGE_VERSION}
    ```

1. Copy to static directory.

    ```console
    sudo rm -rf /opt/senzing
    sudo mkdir  /opt/senzing
    sudo cp -R  /opt/${SENZING_PACKAGE}-${SENZING_PACKAGE_VERSION}/* /opt/senzing
    diff -r     /opt/${SENZING_PACKAGE}-${SENZING_PACKAGE_VERSION}   /opt/senzing
    cat /opt/senzing/er/szBuildVersion.json
    ```

#### Configure Senzing - Linux

1. :pencil2: Move the "versioned" Senzing data to the system location.
   Example:

   ```console
     sudo mv /opt/senzing/data/4.0.0/* /opt/senzing/data/
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

### Install Senzing - Darwin

The following instructions install senzing into a macOS `${HOME}/senzing` directory.

#### Install Senzing - Darwin - production

1. :pencil2: Specify the production version.

    Example:

    ```console
    export SENZING_VERSION="4.1.0.25279"
    ```

1. Download the `.dmg` file.

    ```console
    curl --output /tmp/senzingsdk-production-${SENZING_VERSION}.dmg https://public-read-access.s3.amazonaws.com/MacOS_SDK/senzingsdk_${SENZING_VERSION}.dmg
    ```

1. Install the `.dmg` file.

    ```console
    export SENZING_PATH=${HOME}/senzing

    hdiutil attach /tmp/senzingsdk-production-${SENZING_VERSION}.dmg
    rm -rf ${SENZING_PATH}
    mkdir -p ${SENZING_PATH}
    cp -R /Volumes/SenzingSDK/senzing/* ${SENZING_PATH}
    cat ${SENZING_PATH}/er/szBuildVersion.json
    hdiutil detach /Volumes/SenzingSDK
    ```

#### Install Senzing - Darwin - staging

1. :pencil2: Specify the staging version.

    Example:

    ```console
    export SENZING_STAGING_VERSION="4.1.1.25300"
    ```

1. Download the `.dmg` file.

    ```console
    curl --output /tmp/senzingsdk-staging-${SENZING_STAGING_VERSION}.dmg https://senzing-staging-osx.s3.amazonaws.com/senzingsdk_${SENZING_STAGING_VERSION}.dmg
    ```

1. Install the `.dmg` file.

    ```console
    export SENZING_PATH=${HOME}/senzing

    hdiutil attach /tmp/senzingsdk-staging-${SENZING_STAGING_VERSION}.dmg
    rm -rf ${SENZING_PATH}
    mkdir -p ${SENZING_PATH}
    cp -R /Volumes/SenzingSDK/senzing/* ${SENZING_PATH}
    cat ${SENZING_PATH}/er/szBuildVersion.json
    hdiutil detach /Volumes/SenzingSDK
    ```

1. References:
    1. [github-action-install-senzing-sdk]

[github-action-install-senzing-sdk]: https://github.com/senzing-factory/github-action-install-senzing-sdk/blob/main/darwin/install-senzing.sh
