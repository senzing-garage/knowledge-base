# GIST: Docker - Wrap senzing-api-server

## Overview

The
[Senzing API-server](https://github.com/Senzing/senzing-api-server)
uses mounted volumes for a Senzing installation in `/opt`, `/etc`, and `/var` directories.
If a
[baked-in](../../WHATIS/baked-in.md)
Senzing installation is desired, layers need to be added on top of the `senzing/senzing-api-server` docker image.

The following gist shows how to add layers with a Senzing installation.

## View Dockerfile

The [Dockerfile](Dockerfile) shows how to build upon `senzing/senzing-api-server`.

1. The `FROM` instruction refers to a Senzing docker image that does not have Senzing "baked in".
1. The Dockerfile essentially does an `apt` install of the Senzing package.

## Build Docker image

1. Run the following in the directory containing the Dockerfile.
   Replace `XXXX` with documented
   [SENZING_ACCEPT_EULA](https://github.com/Senzing/knowledge-base/blob/master/lists/environment-variables.md#senzing_accept_eula)
   value.

   Example:

    ```console
    docker build \
        --build-arg BASE_IMAGE=senzing/senzing-api-server:1.7.10 \
        --build-arg SENZING_ACCEPT_EULA=XXXX \
        --tag my/senzing-api-server:latest \
        .
    ```
