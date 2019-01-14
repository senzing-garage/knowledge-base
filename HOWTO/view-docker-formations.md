# View docker formations

## Portainer

1. [Website](https://www.portainer.io/)
1. [Demo](http://demo.portainer.io/) username: admin and password: tryportainer 
1. [Documentation](https://portainer.readthedocs.io/en/stable/)
1. Launch Portainer locally

    ```console
    docker run \
       --detach \
       --volume /var/run/docker.sock:/var/run/docker.sock \
       --volume /opt/portainer:/data \
       --publish 9000:9000 \
       --restart always \
       portainer/portainer
    ```

1. Can be viewed at [localhost:9000](http://localhost:9000)
