# What is GnuPG

- <https://gnupg.org/index.html>

## Install

### CentOS

1. Install using **yum** (Most Linux distributions already have GnuPG installed)
   ```console
   sudo yum install gnupg
   ```
   - [Configure TTY]

### macOS

1. [Install via brew]
   ```console
   brew install gnupg
   ```
   - [Configure TTY]

### Ubuntu

1. Install via **apt-get**
   ```console
   sudo apt-get install gnupg
   ```
   - [Configure TTY]

### Windows

1. Download and install the windows binary from [gnupg.org]

### Configure TTY

[It is important that this environment variable always reflects the output of the tty command. For W32 systems this option is not required.]

1. Set the following environment variable in whichever initialization file is used for shell invocations
   ```
   GPG_TTY=$(tty)
   export GPG_TTY
   ```

## Test

1. Test
   ```console
   gpg --version
   ```

## Troubleshooting

## References

[Configure TTY]: https://github.com/senzing-garage/knowledge-base/blob/56-skern/WHATIS/gnupg.md#configure-tty
[gnupg.org]: https://gnupg.org/download/
[It is important that this environment variable always reflects the output of the tty command. For W32 systems this option is not required.]: https://www.gnupg.org/documentation/manuals/gnupg/Invoking-GPG_002dAGENT.html
[Install via brew]: https://formulae.brew.sh/formula/gnupg
