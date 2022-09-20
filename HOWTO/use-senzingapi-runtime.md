# How to use senzingapi-runtime

## Synopsis

The
[senzing/senzingapi-runtime](https://hub.docker.com/r/senzing/senzingapi-runtime)
Docker image has the Senzing binaries "baked-in".
This Docker image and its corresponding
[senzingapi-runtime GitHub repository](https://github.com/Senzing/senzingapi-runtime)
can be used in a number of ways to simplify development using the Senzing SDK library.

## Overview

The

1.



## Simple inheritance


1. Use in a Dockerfile `FROM` instruction.
   Example:

    ```Dockerfile
    FROM senzing/senzingapi-runtime
    :
    ```

1. It's recommended to use a "pinned" version of the image.
   So in practice, it would look something more like:

    ```Dockerfile
    FROM senzing/senzingapi-runtime:3.2.0
    :
    ```

## Wrapping
