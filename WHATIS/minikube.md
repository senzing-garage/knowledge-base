# What is minikube

## Install

Instructions for installing [minikube].

1. [github.com/kubernetes/minikube]
   1. [Releases]

### CentOS

### Ubuntu

1. [minikube start] has installation instructions for multiple platforms.
1. [Ubuntu]

   ```console
   curl -LO https://storage.googleapis.com/minikube/releases/latest/minikube-linux-amd64
   sudo install minikube-linux-amd64 /usr/local/bin/minikube
   ```

1. Example for a specific release:

   ```console
   curl -LO https://storage.googleapis.com/minikube/releases/v1.2.0/minikube-linux-amd64
   sudo install minikube-linux-amd64 /usr/local/bin/minikube
   ```

1. For more information, visit [minikube start]

### macOS

1. Visit [minikube start]

### Windows

1. Visit [minikube start]

## Test

1. Start the cluster

   ```console
   minikube start
   ```

## Troubleshooting

1. VirtualBox does not come up.
   1. Use minikube's `--vm-driver` option to specify a different driver.
      See [References](#references) > Drivers

## References

1. Drivers
   1. [Driver plugin installation](https://github.com/kubernetes/minikube/blob/master/docs/drivers.md)
   1. [Switching from Minikube with VirtualBox to KVM](https://medium.com/@nieldw/switching-from-minikube-with-virtualbox-to-kvm-2f742db704c9)

[github.com/kubernetes/minikube]: https://github.com/kubernetes/minikube
[minikube]: https://kubernetes.io/docs/tasks/tools/install-minikube/
[minikube start]: https://minikube.sigs.k8s.io/docs/start/
[Releases]: https://github.com/kubernetes/minikube/releases
[Ubuntu]: https://kubernetes.io/docs/tasks/tools/install-minikube/#linux
