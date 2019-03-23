# Install Helm

## Overview

Instructions for installing [Helm](https://helm.sh).

### Contents

1. [Install](#install)
    1. [CentOS](#centos)
    1. [Ubuntu](#ubuntu)
    1. [macOS](#macos)
    1. [Windows](#windows)
1. [Test](#test)
1. [References](#references)

## Install

### CentOS

### Ubuntu

1. Download "Linux amd64" from [https://github.com/helm/helm/releases/tag/v2.12.3](https://github.com/helm/helm/releases/tag/v2.12.3)
1. Example:

    ```console
    tar -xzvf helm-v2.12.3-linux-amd64.tar.gz
    mv /home/senzing/Downloads/linux-amd64/helm /usr/local/bin
    cd /usr/local/bin
    mv helm helm-2.12.3
    ln -s helm-2.12.3 helm
    ```

### macOS

### Windows

## Test

## References

1. [How to Create Your First Helm Chart](https://docs.bitnami.com/kubernetes/how-to/create-your-first-helm-chart/)
