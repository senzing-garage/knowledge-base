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

## Install

### CentOS

### Ubuntu

1. [Ubuntu](https://kubernetes.io/docs/tasks/tools/install-minikube/#linux)

    ```console
    curl -Lo minikube https://storage.googleapis.com/minikube/releases/latest/minikube-linux-amd64 \
      && chmod +x minikube \
      && sudo cp minikube /usr/local/bin/ \
      && rm minikube
    ```

1. Example for a specific release:

    ```console
    curl -Lo minikube https://storage.googleapis.com/minikube/releases/v1.0.0/minikube-linux-amd64 \
     && chmod +x minikube \
     && sudo cp minikube /usr/local/bin/ \
     && rm minikube
    ```

### macOS

### Windows

## Test
