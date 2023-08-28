# How to develop Go on Windows

## Synopsis

The following are examples showing how to develop Go programs for Senzing on Windows.

## Overview

## Install Senzing API

1. The following steps require Windows 10 version 20H2 or higher.

1. Install Senzing API.
   In a Command Prompt, "Run as administrator".
   Example:

    ```console
    mkdir C:\Temp
    cd C:\Temp
    curl --output senzingapi.zip https://public-read-access.s3.amazonaws.com/staging/SenzingAPI_3.7.0.zip
    tar -x -C "C:\Program Files" -f senzingapi.zip
    ren "C:\Program Files\senzing" "senzing2"
    ren "C:\Program Files\senzing2" "Senzing"
    ```

## Prepare Development environment

1. Prerequisite software
    1. [MSYS2](../WHATIS/msys2.md#windows)
    1. [gcc](../WHATIS/gcc.md#windows)
    1. [git](../WHATIS/git.md#windows)
    1. [go](../WHATIS/go.md#install)
    1. [make](../WHATIS/make.md#windows)
    1. [Visual Studio Code](../WHATIS/visual-studio-code.md#windows)

1. Create directory for Senzing repositories.
   Example:

    ```console
    mkdir %HOMEPATH%\senzing.git
    ```
