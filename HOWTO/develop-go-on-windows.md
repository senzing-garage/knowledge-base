# How to develop Go on Windows

## Synopsis

The following are examples showing how to develop Go programs for Senzing on Windows.

## Overview

## Prepare Windows environment

1. The following steps require Windows 10 version 1803 or higher.

1. Prerequisite software:
    1. [7-Zip](../WHATIS/7-zip.md)
    1. [git](./WHATIS/git.md#windows)
    1. [curl]()

1. Install Senzing API.
   Example:

    ```console
    curl --output senzingapi.zip https://public-read-access.s3.amazonaws.com/staging/SenzingAPI_3.7.0.zip
    7z x -y -o"C:\Program Files" senzingapi.zip
    ren "C:\Program Files\senzing" "senzing2"
    ren "C:\Program Files\senzing2" "Senzing"
    ```

## Prepare Development environment

1. Prerequisite software
    1. [VS Code]()
