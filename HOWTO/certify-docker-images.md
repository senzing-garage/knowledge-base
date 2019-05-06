# Certify Docker images

## Dependencies

1. [docker-ee](../software/docker-ee.md)
1. [inspectDockerImage](../software/inspectDockerImage.md)

## Certify using local docker registry

1. :pencil2: Set environment variables.  Example:

    ```console
    export DOCKER_USER="<docker-username>"
    export DOCKER_PASSWORD="<docker-password>"
    export DOCKER_REGISTRY_URL=my.example.com:5000
    export DOCKER_REGISTRY_API_ENDPOINT="https://${DOCKER_REGISTRY_URL}"

    export DOCKER_IMAGE_NAMES=( \
      "docker/test" \
    )

    export GIT_TAG=latest
    ```

1. Inspect docker images on local docker registry.  Example:

    ```console
    for DOCKER_IMAGE_NAME in ${DOCKER_IMAGE_NAMES[@]}; \
    do \
      export NEW_IMAGE_NAME=${DOCKER_REGISTRY_URL}/${DOCKER_IMAGE_NAME}:${GIT_TAG}; \
      sudo docker tag ${DOCKER_IMAGE_NAME} ${NEW_IMAGE_NAME}; \
      sudo docker push ${NEW_IMAGE_NAME}; \
      sudo docker rmi  ${NEW_IMAGE_NAME}; \
      inspectDockerImage -html -insecure-skip-verify ${NEW_IMAGE_NAME}; \
    done
    ```

## References

1. [Certify Docker images](https://docs.docker.com/docker-hub/publish/certify-images/)
