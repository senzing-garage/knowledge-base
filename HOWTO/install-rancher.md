# Install Rancher

## Overview

Instructions for installing [Rancher](https://rancher.com/).

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
