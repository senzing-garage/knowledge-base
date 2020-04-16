# How to install Docker

## Overview

Instructions for installing [Docker](https://www.docker.com/).

For detailed installation, see [Docker docs](https://docs.docker.com/install/).

### Contents

1. [Install](#install)
    1. [CentOS](#centos)
    1. [Ubuntu](#ubuntu)
    1. [macOS](#macos)
    1. [Windows](#windows)
1. [Test](#test)
1. [Troubleshooting](#troubleshooting)
1. [References](#references)

## Install

### CentOS

1. Uninstall old docker.
   Example:

    ```console
    sudo yum remove docker docker-common docker-selinux docker-engine
    ```

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

1. [Install Docker Desktop for Mac](https://docs.docker.com/docker-for-mac/install/)
    1. Open Docker.dmg
    1. Drag Docker to Applications

1. Go to "Applications" and double-click on "Docker"
    1. Check the menu bar for the Docker icon

1. Test
    1. Open Terminal

    ```console
    docker --version
    docker-compose --version
    docker-machine --version
    docker run hello-world
    ```

### Windows

1. **Caveat:** Requires Windows Pro.
1. [Install Docker Desktop for Windows](https://docs.docker.com/docker-for-windows/install/)
    1. Run `Docker%20for%20%Windows%20Installer.exe`

## Test

1. Test

    ```console
    sudo docker --version
    sudo docker run hello-world
    ```

## Troubleshooting

## References
