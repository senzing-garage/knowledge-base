# What is Rancher

> Rancher is open-source software for delivering [Kubernetes](kubernetes.md)-as-a-Service.
> -- _[Rancher site]_

## Sites

1. [Rancher site]
   1. [Overview]
   1. [Documentation]
1. [github.com/rancher]

## Install

Instructions for installing: [Rancher site].

1. Option #1 [Full installation]
1. Option #2 [Manual Quick Start]
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

[Documentation]: https://rancher.com/docs/
[Full installation]: https://rancher.com/docs/rancher/v2.x/en/installation/
[github.com/rancher]: https://github.com/rancher
[Manual Quick Start]: https://rancher.com/docs/rancher/v2.x/en/quick-start-guide/deployment/quickstart-manual-setup/
[Overview]: https://rancher.com/what-is-rancher/overview/
[Rancher site]: https://rancher.com/
