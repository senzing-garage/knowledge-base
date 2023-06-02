# What is GnuPG

* <https://gnupg.org/index.html>

## Install

### CentOS

1. Install using **yum** (Most Linux distributions already have GnuPG installed)

    ```console
    sudo yum install gnupg
    ```
   - Set the following environment variable in whichever initialization file is used for shell invocations
      + ```console
           GPG_TTY=$(tty)
           export GPG_TTY
      ``` 

### macOS

1. [Install via brew](https://formulae.brew.sh/formula/gnupg)
	- `brew install gnupg`
   - Set the following environment variable in whichever initialization file is used for shell invocations
      + ```console
           GPG_TTY=$(tty)
           export GPG_TTY
      ``` 

### Ubuntu

1. Install via **apt-get**
   - `sudo apt-get install gnupg`
   - Set the following environment variable in whichever initialization file is used for shell invocations
      + ```console
           GPG_TTY=$(tty)
           export GPG_TTY
      ``` 
   
### Windows

1. Download and install the windows binary from [gnupg.org](https://gnupg.org/download/)

## Test

1. Test

   ```console
      gpg --version
   ```

 ## Troubleshooting

## References