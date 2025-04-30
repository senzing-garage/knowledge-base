# Bad-Guy Hunting

## Prerequisites

1. Make sure the
   [prerequisites](../README.md#prerequisites)
   are installed.
1. Make sure Docker is running.

## Download database and start Senzing gRPC service

1. Download the pre-populated Sqlite database
   [G2C.db](https://raw.githubusercontent.com/senzing-garage/knowledge-base/main/proposals/streamline/bad-guy-hunting/G2C.db).

1. :pencil2:
   To identify the directory containing the
   [G2C.db](https://raw.githubusercontent.com/senzing-garage/knowledge-base/main/proposals/streamline/bad-guy-hunting/G2C.db) file,
   copy/modify/paste the following into the terminal window:

   ```console
   set SENZING_MY_DEMO_10="C:\\Users\\username\\my-demo-10"

   ```

1. Run a Senzing gRPC service using Docker.
   Notice that the `--volume` must point to the directory of the database files you wish to use.
   For more information on `docker run` parameters,
   visit [docker run](https://docs.docker.com/engine/reference/commandline/run/).

   Copy/paste the following into the terminal window:

   ```console
   docker run ^
       --name senzing-my-demo-10 ^
       --publish 8260:8260 ^
       --publish 8261:8261 ^
       --pull always ^
       --rm ^
       --volume %SENZING_MY_DEMO_10%:/tmp/sqlite ^
       senzing/demo-quickstart

   ```

## Start bad-guy hunting

TODO: Describe bad-guy hunting using:

1. [http://localhost:8260/entity-search](http://localhost:8260/entity-search).
1. [http://localhost:8260/xterm](http://localhost:8260/xterm).
1. Interactive python (`python3` command)

## Next steps

1. [Try Senzing's Hello World](../README.md)
1. [Use Senzing's Truth Set data - Windows](../use-senzings-truth-set-data-windows.md)
1. [Map and load your own data - Windows](../map-and-load-your-own-data-windows.md)
1. [Experience Entity Resolution Record-by-Record - Windows](../experience-entity-resolution-record-by-record-windows.md)
1. Bad-Guy Hunting
