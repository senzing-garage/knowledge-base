# How to install IBM Db2 client

## Overview

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

1. Visit [Download initial Version 11.1 clients and drivers](http://www-01.ibm.com/support/docview.wss?uid=swg21385217)
    1. Click on "[IBM Data Server Driver for ODBC and CLI (CLI Driver)](http://www.ibm.com/services/forms/preLogin.do?source=swg-idsoc97)" link.
    1. Select :radio_button:  "IBM Data Server Driver for ODBC and CLI (Linux AMD64 and Intel EM64T)"
    1. Click "Continue" button.
    1. Choose download method and click "Download now" button.

### CentOS

1. Download `ibm_data_server_driver_for_odbc_cli_linuxx64_v11.1.tar.gz` to `/opt/senzing/ibm_data_server_driver_for_odbc_cli_linuxx64_v11.1.tar.gz`.

1. Uncompress `.tar.gz` file.  Example:

    ```console
    sudo mkdir -p /opt/senzing/db2

    sudo tar \
      --extract \
      --owner=root \
      --group=root \
      --no-same-owner \
      --no-same-permissions \
      --directory=/opt/senzing/db2 \
      --file=/opt/senzing/ibm_data_server_driver_for_odbc_cli_linuxx64_v11.1.tar.gz
    ```

### Ubuntu

1. Download `ibm_data_server_driver_for_odbc_cli_linuxx64_v11.1.tar.gz` to `/opt/senzing/ibm_data_server_driver_for_odbc_cli_linuxx64_v11.1.tar.gz`.

1. Uncompress `.tar.gz` file.  Example:

    ```console
    sudo mkdir -p /opt/senzing/db2

    sudo tar \
      --extract \
      --owner=root \
      --group=root \
      --no-same-owner \
      --no-same-permissions \
      --directory=/opt/senzing/db2 \
      --file=/opt/senzing/ibm_data_server_driver_for_odbc_cli_linuxx64_v11.1.tar.gz
    ```

### macOS

### Windows

## Test

## Troubleshooting

## References
