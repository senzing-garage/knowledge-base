# How to update Senzing images on Docker Store

## Overview

Instructions for updating Senzing Docker images on DockerHub. Example:

1. [store/senzing/senzing-package](https://hub.docker.com/_/senzing-package)
    1. [GitHub](https://github.com/Senzing/senzing-package)

### Contents

1. [Build image](#build-image)
1. [Determine docker tag](#determine-docker-tag)
1. [Tag and push docker image](#tag-and-push-docker-image)
1. [Certify image](#certify-image)
1. [Submit new image on Docker Store](#submit-new-image-on-docker-store)
1. [Certify image for Docker Store](#certify-image-for-docker-store)

## Build image

1. Build [senzing/senzing-package](https://github.com/Senzing/senzing-package#develop) docker image.
    1. Make sure to get the latest `Senzing_API.tgz`.
    1. To build clean, don't use cache.
       Example:

        ```console
        docker build \
          --no-cache \
          --tag senzing/senzing-package:latest \
          .
        ```

## Determine docker tag

1. Inspect Senzing API version inside of docker image.

    ```console
    sudo docker run \
      --env SENZING_SUBCOMMAND="package-version" \
      --rm \
      senzing/senzing-package
    ```

1. Look for Senzing API version in `message:` field of `senzing-50030131I` message.

1. :pencil2: Identify docker image tag.  Example:

    ```console
    export DOCKER_IMAGE_NAME="senzing/senzing-package"
    export DOCKER_IMAGE_TAG=1.9.19155
    ```

## Tag and push docker image

1. Push to DockerHub.
   Example:

    ```console
    sudo docker tag  ${DOCKER_IMAGE_NAME}:latest ${DOCKER_IMAGE_NAME}:${DOCKER_IMAGE_TAG}
    sudo docker push ${DOCKER_IMAGE_NAME}:${DOCKER_IMAGE_TAG}
    sudo docker rmi  ${DOCKER_IMAGE_NAME}:${DOCKER_IMAGE_TAG}
    ```

## Certify image

1. :pencil2: Docker credentials.
   Example:

    ```console
    export DOCKER_USER="my-docker-username"
    export DOCKER_PASSWORD="my-docker-password"
    ```

1. Run `inspectDockerImage`.
   Example:

    ```console
    inspectDockerImage -html ${DOCKER_IMAGE_NAME}:${DOCKER_IMAGE_TAG}
    ```

1. References:
    1. [Certify Docker images](https://docs.docker.com/docker-hub/publish/certify-images/)

## Submit new image on Docker Store

1. Log into [hub.docker.com](https://hub.docker.com/) as the userid owning `senzing/senzing-package`.
1. In upper-right, username drop-down, select "Publisher Center".
1. In "My Products", for "Senzing package installer", select "Actions" > "Edit Product"
1. Select "Plans & Pricing" > "Create New Plan"
1. In new plan:
    1. General Details
        1. **Plan Name:** Major.Minor.Patch
        1. **Description:** Copy from existing plan
        1. **Price/Month:** 0
        1. **Pull Requirements:** Subscribed users only
    1. Source Repositories & Tags
        1. **Namespace:** Senzing
        1. **Repository:** senzing-package
        1. **Tag:**  Major.Minor.Patch
    1. Certification
        1. :ballot_box_with_check: Certify this plan
        1. Save the **Product ID** value. It will be needed for
           [Certify image for Docker Store](#certify-image-for-docker-store)
           step.
    1. Resources
        1. **License Agreement:**
            1. :large_blue_circle: Paste Agreement
            1. Copy from existing plan.
        1. **Installation Instructions:** Copy from existing plan.
        1. **Release Notes:** {empty}
    1. At the top, click "Save" or "Submit For Review".

## Certify image for Docker Store

1. :pencil2: Identify the Product ID.
   Example:

    ```console
    export DOCKER_STORE_PRODUCT_ID=xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx
    ```

1. Using **Product ID** from above, re-run `inspectDockerImage` with `--product-id` parameter.
   Example:

    ```console
    inspectDockerImage \
      --product-id ${DOCKER_STORE_PRODUCT_ID} \
      ${DOCKER_IMAGE_NAME}:${DOCKER_IMAGE_TAG}
    ```
