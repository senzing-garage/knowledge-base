# How to make Docker images with updated Senzing

## Preparation

1. Verify version name.
    1. Senzing version: `M.m.P-?????`

## Update Docker images on Docker Hub

### Update Docker images on Docker Hub  - Phase 1

1. Find updated version of `debian` Docker image.
1. Update `properties` in
   [update-dockerfiles-step-1-example.json](https://github.com/Senzing/github-util/blob/main/update-dockerfiles-step-1-example.json)
1. Run

    ```console
    export GITHUB_ACCESS_TOKEN=ghp_....................................
    github-util.py update-dockerfiles --configuration-file update-dockerfiles-step-1-example.json
    ```

1. Update `senzingapi-runtime` version in `senzing/senzingapi-runtime`
   [Dockerfile](https://github.com/Senzing/senzingapi-runtime/blob/main/Dockerfile)
1. Review and accept Pull requests generated.
1. Create versioned releases (including changes to Dockerfile and CHANGELOG.md) of
    1. [senzing/senzingapi-runtime](https://github.com/Senzing/senzingapi-runtime)
    1. [senzing/docker-senzing-base](https://github.com/Senzing/docker-senzing-base)
    1. [senzing/docker-base-image-debian](https://github.com/Senzing/docker-base-image-debian)

### Update Docker images on Docker Hub - Phase 2

1. Find updated version of `senzing/senzingapi-runtime` Docker image.
1. Update `properties` in
   [update-dockerfiles-step-2-example.json](https://github.com/Senzing/github-util/blob/main/update-dockerfiles-step-2-example.json)
1. Run

    ```console
    export GITHUB_ACCESS_TOKEN=ghp_....................................
    github-util.py update-dockerfiles --configuration-file update-dockerfiles-step-2-example.json
    ```

1. Update `senzingapi-tools` version in `senzing/senzingapi-tools`
   [Dockerfile](https://github.com/Senzing/senzingapi-tools/blob/main/Dockerfile)
1. Create versioned releases (including changes to Dockerfile and CHANGELOG.md) of
    1. [senzing/senzingapi-tools](https://github.com/Senzing/senzingapi-tools)

### Update Docker images on Docker Hub - Phase 3

1. Find updated versions of
   `alpine`,
   `amazonlinux`,
   `busybox`,
   `debian`,
   `ibmcom/db2`,
   `jupyter minimal-notebook`,
   `lambda/python`,
   `node`,
   `senzing/senzing-base`
   `senzing/senzingapi-runtime`,
   `senzing/senzingapi-tools`
    Docker images.
1. Update `properties` in
   [update-dockerfiles-step-3-example.json](https://github.com/Senzing/github-util/blob/main/update-dockerfiles-step-3-example.json)
1. Run

    ```console
    export GITHUB_ACCESS_TOKEN=ghp_....................................
    github-util.py update-dockerfiles --configuration-file update-dockerfiles-step-3-example.json
    ```

1. Create versioned releases (including changes to Dockerfile and CHANGELOG.md) of the repositories
   listed in the `repositories` section of
   [update-dockerfiles-step-3-example.json](https://github.com/Senzing/github-util/blob/main/update-dockerfiles-step-3-example.json).

## Update Docker images on AWS Elastic Container Registry

1. ...
