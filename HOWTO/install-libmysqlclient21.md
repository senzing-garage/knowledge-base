# How to install libmysqlclient21

## Overview

Manual instructions for installing `libmysqlclient21` which is the database driver for MySQL.

This is done automatically by
[docker-init-container](https://github.com/Senzing/docker-init-container).
In particular the `database_initialization_mysql(...)` function of
[init-container.py](https://github.com/Senzing/docker-init-container/blob/master/init-container.py)

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
    ```

1. References:

### Ubuntu

1. Get the `*.deb` file.
   Example:

    ```console
    wget http://repo.mysql.com/apt/debian/pool/mysql-8.0/m/mysql-community/libmysqlclient21_8.0.20-1debian10_amd64.deb
    ```

1. Extract `libmysqlclient.so.21.1.20` from **deb** file.
   Example:

    ```console
    dpkg --fsys-tarfile libmysqlclient21_8.0.20-1debian10_amd64.deb | tar xOf - ./usr/lib/x86_64-linux-gnu/libmysqlclient.so.21.1.20  > /opt/senzing/g2/lib/libmysqlclient.so.21.1.20
    ```

1. Change file permissions.
   Example:

    ```console
    chmod 755 /opt/senzing/g2/lib/libmysqlclient.so.21.1.20
    ```

1. Make `libmysqlclient.so.21` soft link.
   Example:

    ```console
    cd /opt/senzing/g2/lib
    ln -s libmysqlclient.so.21.1.20 libmysqlclient.so.21
    ```

1. References:

### macOS

### Windows

## Test

## Troubleshooting

## References
