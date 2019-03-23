# Install Senzing App

## Overview

The Senzing App is a desktop application for loading and viewing entity resolution.

### Contents

1. [Install](#install)
    1. [CentOS](#centos)
    1. [Ubuntu](#ubuntu)
    1. [macOS](#macos)
    1. [Windows](#windows)
1. [Test](#test)

## Install

### CentOS

Senzing App does not run on CentOS.

### Ubuntu

Senzing App does not run on Ubuntu.

### macOS

#### Download the Senzing App for macOS

##### macOS download via web browser

1. Visit [senzing.com](https://senzing.com/).
1. Click on Our Technology > [Senzing App](https://senzing.com/senzing-app/).
1. Click on the "Free Download" button.
1. Choose your platform:
    1. [macOS](https://s3.amazonaws.com/public-read-access/SenzingComDownloads/Senzing_macOS.dmg)

##### macOS download via curl command

1. Download [Senzing_macOS.dmg](https://s3.amazonaws.com/public-read-access/SenzingComDownloads/Senzing_macOS.dmg). Example:

    ```console
    curl -X GET --output %HOMEPATH%\Downloads\Senzing_macOS.dmg https://s3.amazonaws.com/public-read-access/SenzingComDownloads/Senzing_macOS.dmg
    ```

#### Run macOS installer

### Windows

#### Download the Senzing App for Windows

##### Windows download via web browser

1. Visit [senzing.com](https://senzing.com/).
1. Click on Our Technology > [Senzing App](https://senzing.com/senzing-app/).
1. Click on the "Free Download" button.
1. Choose your platform:
    1. [Windows](https://s3.amazonaws.com/public-read-access/SenzingComDownloads/Senzing.msi)

##### Windows download via curl command

1. Download [Senzing.msi](https://s3.amazonaws.com/public-read-access/SenzingComDownloads/Senzing.msi). Example:

    ```console
    curl -X GET --output %HOMEPATH%\Downloads\Senzing.msi https://s3.amazonaws.com/public-read-access/SenzingComDownloads/Senzing.msi
    ```

#### Run Windows installer

1. Run installer.  Example:

    ```console
    cd %HOMEPATH%\Downloads
    Senzing.msi
    ```

## Test
