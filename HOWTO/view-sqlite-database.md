# View SQLite database

## Using sqlite-web

1. :pencil2: Set environment variables.  Example:

    ```console
    export SENZING_DIR=/opt/senzing
    ```

1. Run the docker container.  Example:

    ```console
    sudo docker run \
      --env SQLITE_DATABASE="G2C.db" \
      --interactive \
      --publish 8080:8080 \
      --rm \
      --tty \
      --volume ${SENZING_DIR}/g2/sqldb:/data \
      coleifer/sqlite-web
    ```

1. References:
    1. [DockerHub](https://hub.docker.com/r/coleifer/sqlite-web)
    1. [GitHub](https://github.com/coleifer/sqlite-web)
