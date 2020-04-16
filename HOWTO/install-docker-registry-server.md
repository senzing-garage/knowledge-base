# How to install docker registry server

## Overview

For detailed installation, see
[https://docs.docker.com/registry/deploying/](https://docs.docker.com/registry/deploying/)

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

1. Example:

    ```console
    sudo yum install docker-registry

    sudo systemctl start docker-registry
    sudo systemctl enable docker-registry
    ```

1. References:
    1. [Setting Up a Private Docker Registry](http://www.informit.com/articles/article.aspx?p=2464012)

### Ubuntu

1. Example:

    ```console
    sudo apt-get update
    sudo apt-get install docker-registry

    sudo systemctl start docker-registry
    sudo systemctl enable docker-registry
    ```

1. To find configuration file, run:

    ```console
    $ ps -aux | grep docker-registry

    docker-+   950  0.0  0.0 1429396 9436 ?        Ssl  Feb08   0:21 /usr/bin/docker-registry serve /etc/docker/registry/config.yml
    ```

    In this example, `/etc/docker/registry/config.yml` is the configuration file.

1. References:
    1. [How to install docker-registry on Ubuntu 16.04 (Xenial Xerus)](https://www.howtoinstall.co/en/ubuntu/xenial/docker-registry)
    1. [Insecure registries](https://docs.docker.com/registry/insecure/)

### macOS

### Windows

## Test

## Troubleshooting

## References
