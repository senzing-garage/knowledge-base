# What is docker registry server

## Overview

For detailed installation, see
[https://docs.docker.com/registry/deploying/]

## Install

### CentOS

1. Example:

    ```console
    sudo yum install docker-registry

    sudo systemctl start docker-registry
    sudo systemctl enable docker-registry
    ```

1. References:
    1. [Setting Up a Private Docker Registry]

### Ubuntu

1. Example:

    ```console
    sudo apt-get update
    sudo apt-get install docker-registry

    sudo systemctl start docker-registry
    sudo systemctl enable docker-registry
    ```

1. To find configuration file, run:

    ```console
    $ ps -aux | grep docker-registry

    docker-+   950  0.0  0.0 1429396 9436 ?        Ssl  Feb08   0:21 /usr/bin/docker-registry serve /etc/docker/registry/config.yml
    ```

    In this example, `/etc/docker/registry/config.yml` is the configuration file.

1. References:
    1. [How to install docker-registry on Ubuntu 16.04 (Xenial Xerus)]
    1. [Insecure registries]

### macOS

### Windows

## Test

## Troubleshooting

## References

[How to install docker-registry on Ubuntu 16.04 (Xenial Xerus)]: https://www.howtoinstall.co/en/ubuntu/xenial/docker-registry
[https://docs.docker.com/registry/deploying/]: https://docs.docker.com/registry/deploying/
[Insecure registries]: https://docs.docker.com/registry/insecure/
[Setting Up a Private Docker Registry]: http://www.informit.com/articles/article.aspx?p=2464012
