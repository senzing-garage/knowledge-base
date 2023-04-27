# What is Rancher

> Rancher is open-source software for delivering [Kubernetes](kubernetes.md)-as-a-Service.
> -- *[Rancher site](https://rancher.com/)*

## Sites

1. [Official site](https://rancher.com)
    1. [Overview](https://rancher.com/what-is-rancher/overview/)
    1. [Documentation](https://rancher.com/docs/)
1. [github.com/rancher](https://github.com/rancher)

## Install

Instructions for installing [Rancher](https://rancher.com/).

1. Option #1 [Full installation](https://rancher.com/docs/rancher/v2.x/en/installation/)
1. Option #2 [Manual Quick Start](https://rancher.com/docs/rancher/v2.x/en/quick-start-guide/deployment/quickstart-manual-setup/)
1. Simple example for Quick Start:

    ```console
    sudo docker run \
      --volume /opt/rancher:/var/lib/rancher \
      --publish 80:80 \
      --publish 443:443 \
      rancher/rancher:latest
    ```

### CentOS

### Ubuntu

### macOS

### Windows

## Test

## Troubleshooting

## References
