# docker-air-gap-helper

##  Creating the tar gzipped file

The following steps are performed on an internet-connected system.
They will not work on an air-gapped system.

1. Get a local copy of
   [docker-air-gap-helper.sh](docker-air-gap-helper.sh).
   Example:

    1. :pencil2: Specify where to download file.
       Example:

        ```console
        export MY_DOCKER_AIR_GAP_HELPER=~/docker-air-gap-helper.sh
        ```

    1. Download file.
       Example

        ```console
        curl -X GET \
          --output ${MY_DOCKER_AIR_GAP_HELPER} \
          https://raw.githubusercontent.com/Senzing/knowledge-base/master/gists/docker-air-gap-helper/docker-air-gap-helper.sh
        ```

1. Modify the `DOCKER_IMAGE_NAMES` in the local copy of
   [docker-air-gap-helper.sh](docker-air-gap-helper.sh)
   (e.g. `MY_DOCKER_AIR_GAP_HELPER`)
   to add or delete docker images to be pulled from DockerHub (docker.io).
1. Run `docker-air-gap-helper.sh`.
   Example:

    ```console
    ${MY_DOCKER_AIR_GAP_HELPER}
    ```

1. This produces the following output:
    1. A directory in the form `~/docker-air-gap-helper-nnnnnnnnnn.tgz` where `nnnnnnnnnn` is the Unix Timestamp of creation.
    1. A file in the form `~/docker-air-gap-helper-nnnnnnnnnn.tgz` which is a tar-gzipped version of the directory.
1. The `~/docker-air-gap-helper-nnnnnnnnnn.tgz` is what is transferred to the air-gapped system.

## On air-gapped system
