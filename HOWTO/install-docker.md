# Install Docker

## Overview

Instructions for installing [Docker](https://www.docker.com/).

For detailed installation, see [Docker docs](https://docs.docker.com/install/).

## Install

### CentOS

1. [CentOS](https://docs.docker.com/install/linux/docker-ce/centos/)

    ```console
    sudo yum -y install yum-utils device-mapper-persistent-data lvm2
    sudo yum-config-manager --add-repo https://download.docker.com/linux/centos/docker-ce.repo
    sudo yum -y install docker-ce
    sudo systemctl start docker
    sudo systemctl enable docker
    sudo docker run hello-world
    ```

### Ubuntu

1. [Ubuntu](https://docs.docker.com/install/linux/docker-ce/ubuntu/)

    ```console
    sudo apt-get update
    sudo apt -y install apt-transport-https ca-certificates curl software-properties-common
    curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
    sudo apt-get update
    sudo apt -y install docker.io
    sudo docker run hello-world
    ```
