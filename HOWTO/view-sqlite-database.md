# View SQLite database

## Configuration

- **[SENZING_VAR_DIR](https://github.com/Senzing/knowledge-base/blob/master/lists/environment-variables.md#senzing_var_dir)**
- **[SQLITE_DATABASE](https://github.com/Senzing/knowledge-base/blob/master/lists/environment-variables.md#sqlite_database)**

## Using sqlite-web

1. :pencil2: Set environment variables.  Example:

    ```console
    export SENZING_VAR_DIR=/var/opt/senzing
    export SQLITE_DATABASE=G2C.db
    export SQLITE_WEB_PORT=8081
    ```

1. Run the docker container.  Example:

    ```console
    sudo docker run \
      --env SQLITE_DATABASE=${SQLITE_DATABASE} \
      --interactive \
      --publish ${SQLITE_WEB_PORT}:8080 \
      --rm \
      --tty \
      --volume ${SENZING_VAR_DIR}/sqlite:/data \
      coleifer/sqlite-web
    ```

1. The SQLite database can be viewed at
   [http://localhost:8081](http://localhost:8081).

1. References:
    1. [DockerHub](https://hub.docker.com/r/coleifer/sqlite-web)
    1. [GitHub](https://github.com/coleifer/sqlite-web)
