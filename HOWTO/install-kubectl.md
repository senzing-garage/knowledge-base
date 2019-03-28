# Install kubectl

## Overview

Instructions for installing [kubectl](https://kubernetes.io/docs/reference/kubectl/overview/).

For detailed installation, see [Kubernetes documentation](https://kubernetes.io/docs/tasks/tools/install-kubectl/).

[Latest version](https://storage.googleapis.com/kubernetes-release/release/stable.txt)

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

1. Latest version

    ```console
    export KUBECTL_VERSION=$(curl -s https://storage.googleapis.com/kubernetes-release/release/stable.txt)

    curl -LO https://storage.googleapis.com/kubernetes-release/release/${KUBECTL_VERSION}/bin/linux/amd64/kubectl
    chmod +x ./kubectl
    sudo mv ./kubectl /usr/local/bin/kubectl
    ```

### macOS

### Windows

## Test

## References

1. [Install and Set Up kubectl](https://kubernetes.io/docs/tasks/tools/install-kubectl/)
1. [Install the Kubernetes CLI](https://docs.docker.com/ee/ucp/user-access/kubectl/)
