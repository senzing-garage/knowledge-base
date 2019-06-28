# Install minikube

## Overview

Instructions for installing [minikube](https://kubernetes.io/docs/tasks/tools/install-minikube/).

1. [github.com/kubernetes/minikube](https://github.com/kubernetes/minikube)
    1. [Releases](https://github.com/kubernetes/minikube/releases)

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

### Ubuntu

1. [Ubuntu](https://kubernetes.io/docs/tasks/tools/install-minikube/#linux)

    ```console
    curl -Lo minikube https://storage.googleapis.com/minikube/releases/latest/minikube-linux-amd64
    chmod +x minikube
    sudo mv minikube /usr/local/bin/
    ```

1. Example for a specific release:

    ```console
    curl -Lo minikube https://storage.googleapis.com/minikube/releases/v1.2.0/minikube-linux-amd64
    chmod +x minikube
    sudo cp minikube /usr/local/bin/ && rm minikube
    ```

### macOS

### Windows

## Test

1. Start the cluster

    ```console
    minikube start
    ```

## Troubleshooting

1. VirtualBox does not come up.
    1. Use minikube's `--vm-driver` option to specify a different driver.
       See [References](#references) > Drivers

## References

1. Drivers
    1. [Driver plugin installation](https://github.com/kubernetes/minikube/blob/master/docs/drivers.md)
    1. [Switching from Minikube with VirtualBox to KVM](https://medium.com/@nieldw/switching-from-minikube-with-virtualbox-to-kvm-2f742db704c9)
