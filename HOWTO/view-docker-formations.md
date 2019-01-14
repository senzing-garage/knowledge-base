# View docker formations

## Portainer

1. [Website](https://www.portainer.io/)
    1. [Overview](https://www.portainer.io/overview/)
1. [Demo](http://demo.portainer.io/) (username: admin and password: tryportainer)
1. [Documentation](https://portainer.readthedocs.io/en/stable/)
1. Launch Portainer locally

    ```console
    docker run \
       --detach \
       --name portainer \
       --publish 9001:9000 \
       --restart always \
       --volume /var/run/docker.sock:/var/run/docker.sock \
       --volume /opt/portainer:/data \
       portainer/portainer
    ```

1. Can be viewed at [localhost:9001](http://localhost:9001)

## Docker compose UI

1. [Website](http://francescou.github.io/docker-compose-ui/)
1. [GitHub](https://github.com/francescou/docker-compose-ui)
1. Launch Docker Compose UI locally

    ```console
    docker run \
        --name docker-compose-ui \
        --publish 5001:5000 \
        --volume /var/run/docker.sock:/var/run/docker.sock \
        --workdir /opt/docker-compose-projects/ \
        francescou/docker-compose-ui:1.13.0
    ```
