# What is GCC

GNU Compiler Collection (GCC)

## Install

### CentOS

### Ubuntu

### macOS

### Windows

1. Reference: [Installing the MinGW-w64 toolchain]
1. Prerequite software:
    1. [MSYS2](../WHATIS/msys2.md#windows)
1. Start `MSYS2`
    1. In "Type here to search", type "MSYS2".  Choose "MSYS2 MSYS"
1. In the `MSYS2` terminal, enter:

    ```console
    pacman -S --needed base-devel mingw-w64-x86_64-toolchain
    ```

1. Add `C:\msys64\mingw64\bin` to `Path` system variable.
   See [Add to the PATH on Windows 10 and Windows 11]

## Test

## Troubleshooting

## References

[Add to the PATH on Windows 10 and Windows 11]: https://www.architectryan.com/2018/03/17/add-to-the-path-on-windows-10/
[Installing the MinGW-w64 toolchain]: https://code.visualstudio.com/docs/cpp/config-mingw#_installing-the-mingww64-toolchain
