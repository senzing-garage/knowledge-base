# View docker formations

## Portainer

1. Can be viewed at [localhost:9000](http://localhost:9000)

    ```console
    docker run \
       --detach \
       --volume /var/run/docker.sock:/var/run/docker.sock \
       --volume /opt/portainer:/data portainer/portainer \
       --publish 9000:9000 \
       --restart always
    ```
