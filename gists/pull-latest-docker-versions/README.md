# Pull latest docker versions

## Pull all docker containers at highest version

1. Get the versions of each docker image.
   Example:

    ```console
    source <(curl -X GET https://raw.githubusercontent.com/Senzing/knowledge-base/main/lists/docker-versions-latest.sh)
    ```

1. Pull images based on version
   Example:

    ```console
    curl -X GET https://raw.githubusercontent.com/Senzing/knowledge-base/main/lists/docker-image-names.json \
      | jq -r '. | to_entries[] | "\("docker pull "+.key +":"+ "${" + .value.environment_variable + "}")"' \
      | sh
    ```
