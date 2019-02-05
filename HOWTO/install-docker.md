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

1. Fix for unable to prepare context.

    Error seen:

    ```console
    unable to prepare context: unable to 'git clone' to temporary context directory: error initializing submodules: usage: git submodule
    ```

    Fix:

    ```console
    sudo yum install https://centos7.iuscommunity.org/ius-release.rpm
    sudo yum swap git git2u
    ```

### Ubuntu

1. [Ubuntu](https://docs.docker.com/install/linux/docker-ce/ubuntu/)

    ```console
    sudo apt-get update

    sudo apt-get install \
        apt-transport-https \
        ca-certificates \
        curl \
        software-properties-common

    curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -

    sudo add-apt-repository \
       "deb [arch=amd64] https://download.docker.com/linux/ubuntu \
       $(lsb_release -cs) \
       stable"

    sudo apt-get update

    sudo apt-get install docker-ce
    ```

1. Past version

    ```console
    sudo apt-get update
    sudo apt -y install apt-transport-https ca-certificates curl software-properties-common
    curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
    sudo apt-get update
    sudo apt -y install docker.io
    sudo docker run hello-world
    ```

### macOS

1. Update [Homebrew](https://brew.sh) packages:

    ```console
    brew update
    brew upgrade
    ```

1. Install docker.

    ```console
    brew cask install virtualbox
    brew cask install docker
    ```

### Windows
