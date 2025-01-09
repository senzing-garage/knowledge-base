# Sneak Peek of Senzing Playground

The Senzing Playground is a Docker container that is used to play with Senzing.

## Build

1. Build the docker image.

    ```console
    docker build --no-cache --pull --tag senzing/playground:latest https://github.com/senzing-garage/playground.git#main
    ```

## Run

1. Run the docker container.

    ```console
    docker run -it --name senzing-playground -p 8260:8260 -p 8261:8261 --rm senzing/playground
    ```

## Visit

1. Visit [localhost:8260].

[localhost:8260]: http://localhost:8260

## Video

1. [Using Jupyter notebooks in the Senzing Sandbox]

[Using Jupyter notebooks in the Senzing Sandbox]: <https://senzing.dockter.com/files/presentations/jupyter-sandbox.mp4>
