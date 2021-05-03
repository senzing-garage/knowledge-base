# The core of Senzing

## Install Senzing

In this step, we'll use a docker container to
see how the Senzing RPM is installed.

1. Start a container.
   Example:

    ```console
    docker run \
      --interactive \
      --rm \
      --tty \
      centos /bin/bash
    ```

1. Inside the running container,
   install the YUM repository metadata.
   Example:

    ```console
    yum -y install \
      https://senzing-production-yum.s3.amazonaws.com/senzingrepo-1.0.0-1.x86_64.rpm
    ```

1. Inside the running container,
   install Senzing.
   Example:

    ```console
    yum -y install \
      senzingapi
    ```

1. :eyes: Notice that the instructions are very similar to the `Dockerfile` in the
   [senzing/docker-yum](https://github.com/Senzing/docker-yum) repository.

