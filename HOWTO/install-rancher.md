# How to install Rancher

## Overview

Instructions for installing [Rancher](https://rancher.com/).

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

1. Option #1 [Full installation](https://rancher.com/docs/rancher/v2.x/en/installation/)
1. Option #2 [Manual Quick Start](https://rancher.com/docs/rancher/v2.x/en/quick-start-guide/deployment/quickstart-manual-setup/)
1. Simple example for Quick Start:

    ```console
    sudo docker run \
      --volume /opt/rancher:/var/lib/rancher \
      --publish 80:80 \
      --publish 443:443 \
      rancher/rancher:latest
    ```

### CentOS

### Ubuntu

### macOS

### Windows

## Test

## Troubleshooting

## References
