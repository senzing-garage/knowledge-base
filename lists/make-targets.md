# make-targets

## Targets

### clean

1. Synopsis:
    1. Delete all files created by any of the Makefile targets.

### default

1. Synopsis:
    1. The first target in a `Makefile`.
    1. Used to direct which action is taken by default.
    1. Suggestion: Default action is to print [Help](#help)

### docker-build

1. Synopsis:
    1. Build the Docker image
    1. `docker build ...`

### docker-build-development-cache

1. Synopsis:
    1. Build a docker image that caches layers.
    1. This assumes that [docker-build](#docker-build) does a `docker rmi ...` before building

### docker-rmi-for-build

1. Synopsis:
    1. Does a `docker rmi --force ...` for all images build by [docker-build](#docker-build).

### docker-rmi-for-build-development-cache

1. Synopsis:
    1. Does a `docker rmi --force ...` for all images build by [docker-build-development-cache](#docker-build-development-cache).

### help

1. Synopsis:
    1. Prints "help"
    1. Lists makefile targets.
