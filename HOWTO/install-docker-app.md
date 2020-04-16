# How to install Docker App

## Overview

Instructions for installing [Docker App](https://docs.docker.com/engine/reference/commandline/app/).

For detailed installation, see [Docker docs](https://github.com/docker/app#installation).

### Contents

1. [Install](#install)
    1. [CentOS](#centos)
    1. [Ubuntu](#ubuntu)
    1. [macOS](#macos)
    1. [Windows](#windows)
1. [Test](#test)
1. [Troubleshooting](#troubleshooting)
1. [References](#references)

## Install

### CentOS

1. See [Linux or macOS](https://github.com/docker/app#linux-or-macos).

### Ubuntu

1. See [Linux or macOS](https://github.com/docker/app#linux-or-macos).

### macOS

1. See [Linux or macOS](https://github.com/docker/app#linux-or-macos).
1. After following instructions, a `docker-app` command can be created by doing

    ```console
    sudo cp /tmp/docker-app-standalone-darwin /usr/local/bin/docker-app
    ```

### Windows

1. See [Windows](https://github.com/docker/app#windows).

## Test

1. :thinking: Depending on how
   [docker app was installed](https://github.com/docker/app#installation),
   it may be invoked by either `docker app` or `docker-app`.
   Identify which invocation method is being used.

   **Example #1**  Docker App stand-alone.

    ```console
    export DOCKER_APP="docker-app"
    ```

   **Example #2**  Docker App CLI plugin.

    ```console
    export DOCKER_APP="docker app"
    ```

1. Test.

    ```console
    ${DOCKER_APP} version
    ```

## Troubleshooting

## References

1. Docker app
    1. [GitHub](https://github.com/docker/app)
    1. [Working with Docker App](https://docs.docker.com/app/working-with-app/)
    1. [CLI documentation](https://docs.docker.com/engine/reference/commandline/app/)
