# How to test docker images

## Overview

Test docker image(s).

References:

* [GitHub](https://github.com/docker/docker-bench-security)
* [DockerHub](https://hub.docker.com/r/docker/docker-bench-security)
* [Error codes](https://success.docker.com/api/asset/.%2Frefarch%2Fsecurity-best-practices%2FCIS_Docker_Community_Edition_Benchmark_v1.1.0.pdf)

## Test docker image

1. :pencil2: Set environment variables.  Example:

    ```console
    export BENCH_LOG_FILE_NAME=debian-9.scan
    export BENCH_TARGET_DOCKER_IMAGE=debian:9
    ```

1. Run the docker container.  Example:

    ```console
    sudo docker run \
        --cap-add audit_control \
        --env DOCKER_CONTENT_TRUST=$DOCKER_CONTENT_TRUST \
        --interactive \
        --label docker_bench_security \
        --net host \
        --pid host \
        --rm \
        --tty \
        --userns host \
        --volume /etc:/etc \
        --volume /usr/bin/docker-containerd:/usr/bin/docker-containerd \
        --volume /usr/bin/docker-runc:/usr/bin/docker-runc \
        --volume /usr/lib/systemd:/usr/lib/systemd \
        --volume /var/lib:/var/lib \
        --volume /var/run/docker.sock:/var/run/docker.sock \
        --volume ${PWD}:/output \
        docker/docker-bench-security \
            -b \
            -l /output/${BENCH_LOG_FILE_NAME} \
            -t ${BENCH_TARGET_DOCKER_IMAGE}
    ```

1. The `${BENCH_LOG_FILE_NAME}` file will be in the `${PWD}` directory.
