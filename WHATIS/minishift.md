# What is minishift

## Install

Instructions for installing [minishift].

1. [github.com/minishift/minishift]
    1. [Releases]

### CentOS

### Ubuntu

1. [Preparing to Install Minishift]
1. [Ubuntu]
    1. Visit [minishift releases]
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

1. [Minishift Quickstart]

## Test

1. Start the cluster

    ```console
    minishift start
    ```

## References

[github.com/minishift/minishift]: https://github.com/minishift/minishift
[minishift]: https://www.okd.io/minishift/
[Minishift Quickstart]: https://docs.okd.io/latest/minishift/getting-started/quickstart.html
[minishift releases]: https://github.com/minishift/minishift/releases
[Preparing to Install Minishift]: https://docs.okd.io/latest/minishift/getting-started/preparing-to-install.html
[Releases]: https://github.com/minishift/minishift/releases
[Ubuntu]: https://docs.okd.io/latest/minishift/getting-started/installing.html
