# Install Senzing API

The Senzing API is packaged for installation in RPM and DEB file formats.

The following installation techniques will install Senzing in a manner
consistent with the Senzing Service Level Agreement (SLA).
Other methods of installation may not be supported by Senzing's SLA.

Once one of the following methods complete, the Senzing library will be installed
on the local system in the `/opt/senzing` directory.

1. [Apt](#apt)
1. [Yum](#yum)
1. [Docker](#docker)

## Apt

1. Use `apt` based installation for Debian, Ubuntu and
   [others](https://en.wikipedia.org/wiki/List_of_Linux_distributions#Debian-based).
   Example:

    ```console
    wget https://senzing-production-apt.s3.amazonaws.com/senzingrepo_1.0.0-1_amd64.deb
    sudo apt install ./senzingrepo_1.0.0-1_amd64.deb
    sudo apt update
    sudo apt install senzingapi

    ```

### Yum

1. Use `yum` based installation for Red Hat, CentOS, openSuse and
   [others](https://en.wikipedia.org/wiki/List_of_Linux_distributions#RPM-based).

    ```console
    sudo yum install https://senzing-production-yum.s3.amazonaws.com/senzingrepo-1.0.0-1.x86_64.rpm
    sudo yum install senzingapi

    ```

## Docker

This technique, although rarely used, can be handy if you are using MacOS, Windows, or cross-compiling.

1. Build Senzing installer Docker image.

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

## Next steps

One or more of the following may need to be done:

1. [Configure](./configure) a Senzing API system installation.
