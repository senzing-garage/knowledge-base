# Tag Docker build

## Create a tagged version on DockerHub

1. :pencil2: Set environment variables.  Example:

    ```console
    export DOCKER_IMAGE=senzing/web-app-demo
    export DOCKER_VERSION=1.0.0
    ```

1. Delete image from local repository.  Example:

    ```console
    sudo docker rmi --force ${DOCKER_IMAGE}:latest
    ```

1. Pull latest image from DockerHub.  Example:

    ```console
    sudo docker pull ${DOCKER_IMAGE}:latest
    ```

1. Tag the image.  Example:

    ```console
    sudo docker tag ${DOCKER_IMAGE}:latest ${DOCKER_IMAGE}:${DOCKER_VERSION}
    ```

1. Push the new tagged image to DockerHub.  Example:

    ```console
    sudo docker push ${DOCKER_IMAGE}:${DOCKER_VERSION}
    ```

1. Cleanup.
   Remove the tagged image from local repository.
   Note: this will not remove the "latest" version from the local repository.
   Example:

    ```console
    sudo docker rmi ${DOCKER_IMAGE}:${DOCKER_VERSION}
    ```
