# How to build senzing/phppgadmin docker image

The docker image, `senzing/phppgadmin`, is an updated version of
[dockage/phppgadmin](https://github.com/dockage/phppgadmin.git).

On hub.docker.com,
[dockage/phppgadmin](https://hub.docker.com/r/dockage/phppgadmin)
does not have the most recent version of
[github.com/phppgadmin/phppgadmin](https://github.com/phppgadmin/phppgadmin).

## Build docker image

1. Example:

    ```console
    git clone https://github.com/dockage/phppgadmin.git
    cd phppgadmin
    sudo docker build --tag="senzing/phppgadmin" .
    ```

## Push to GitHub

1. Example:

    ```console
    sudo docker push senzing/phppgadmin
    ```
