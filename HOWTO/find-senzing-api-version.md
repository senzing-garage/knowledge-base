# How to find Senzing API version

## Via curl

1. Example:

    ```console
    curl -X GET \
      --silent \
      https://s3.amazonaws.com/public-read-access/SenzingComDownloads/Senzing-API-Version.json \
      | jq -r '. | .VERSION'
    ```
