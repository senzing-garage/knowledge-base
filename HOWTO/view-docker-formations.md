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

1. Can be viewed at [localhost:9001](http://localhost:9001), since 9001 was the published port.
