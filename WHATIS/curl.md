# What is curl

## Install

### CentOS

### Ubuntu

1. Update list of packages.
   Example:

    ```console
    sudo apt update
    ```

1. Install system package.
   Example:

    ```console
    sudo apt install curl
    ```

### macOS

### Windows

1. [Download](https://curl.se/windows/) to `%USERPROFILE%\Downloads`
1. Extract file
   1. If [7-Zip](./7-zip.md) is installed:

       ```console
       set CURL_VERSION=8.2.1_7
       "%ProgramFiles%\7-Zip\7z.exe" x %USERPROFILE%\Downloads\curl-%CURL_VERSION%-win64-mingw.zip
       ```

1. Copy file to `C:Windows`

    ```console
    set CURL_VERSION=8.2.1_7
    copy %USERPROFILE%\Downloads\curl-%CURL_VERSION%-win64-mingw\bin\curl.exe C:\Windows\curl.exe

    ```

## Test

1. Test

    ```console
    curl --version
    ```

## Troubleshooting

## References
