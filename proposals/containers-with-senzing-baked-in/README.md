# Proposals for Docker containers with Senzing baked-in

## Principles

1. Adhere to Semantic Versioning of Docker images
1. Adhere to Linux Filesystem Hierarchy Standard
1. Allow for User parameterization of Docker image build

## Senzing base image considerations

1. The image version needs to reflect the version of Senzing and the version of the `FROM`

## Senzing application image considerations

1. Version of repository artifact (e.g. `stream-loader.py`)
1. Version of dependencies.  (e.g. Senzing, pip installs, apt installs)
1. Version of `FROM` base.
    1. The underlying base will change to remove vulnerabilities

## Customer


1. Given this style of `Dockerfile`.
   Example:

    ```console
    ARG BASE_IMAGE=senzing/base-debian:3.1.0
    FROM ${BASE_IMAGE} AS builder
    :
    ```

1. Customers can build their own Docker images using any Senzing version they wish.
   Example:

    ```console
    sudo docker build \
      --build-arg BASE_IMAGE=senzing/base-debian:3.0.0 \
      :
    ```

