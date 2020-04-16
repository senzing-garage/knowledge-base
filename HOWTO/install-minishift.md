# How to install minishift

## Overview

Instructions for installing [minishift](https://www.okd.io/minishift/).

1. [github.com/minishift/minishift](https://github.com/minishift/minishift)
    1. [Releases](https://github.com/minishift/minishift/releases)

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

1. [Preparing to Install Minishift](https://docs.okd.io/latest/minishift/getting-started/preparing-to-install.html)
1. [Ubuntu](https://docs.okd.io/latest/minishift/getting-started/installing.html)
    1. Visit [minishift releases](https://github.com/minishift/minishift/releases)
    1. Download `minishift-MM.mm.pp-linux-amd64.tgz`
    1. Uncompress `minishift-MM.mm.pp-linux-amd64.tgz`
    1. Make file executable.
       Example:

        ```console
        chmod +x minishift
        ```

    1. Move file to `/usr/local/bin`.
       Example:

        ```console
        sudo mv minishift /usr/local/bin/
       ```

### macOS

### Windows

## Quickstart

1. [Minishift Quickstart](https://docs.okd.io/latest/minishift/getting-started/quickstart.html)

## Test

1. Start the cluster

    ```console
    minishift start
    ```

## References
