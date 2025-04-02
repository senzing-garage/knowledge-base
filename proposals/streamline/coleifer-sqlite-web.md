# View SQLite database

The following instructions bring up a docker containiner running the
[sqlite-web](https://github.com/coleifer/sqlite-web)
web app.
This web app allows browsing of SQLite database contents.

## Linux/macOS

1. To identify the directory storing the SQLite database files,
   copy/modify/paste the following:

   ```console
   export SENZING_MY_DEMO_1="/tmp/my-demo-1"
   ```

1. To run the docker container,
   copy/paste the following:

   ```console
   docker run \
   --env SQLITE_DATABASE="G2C.db" \
   --interactive \
   --publish 8080:8080 \
   --rm \
   --tty \
   --volume ${SENZING_MY_DEMO_1}:/data \
   coleifer/sqlite-web
   ```

1. To see "sqlite-web", visit
   [localhost:8080](http://localhost:8080)

## Windows

1. To identify the directory storing the SQLite database files,
   copy/modify/paste the following:

   ```console
   set SENZING_MY_DEMO_1="C:\\Users\\username\\my-demo-1"
   ```

1. To run the docker container,
   copy/paste the following:

   ```console
   docker run ^
   --env SQLITE_DATABASE="G2C.db" ^
   --interactive ^
   --publish 8080:8080 ^
   --rm ^
   --tty ^
   --volume  %SENZING_MY_DEMO_1%:/data ^
   coleifer/sqlite-web
   ```

1. To see "sqlite-web", visit
   [localhost:8080](http://localhost:8080)
