# What is Portainer

> Making Docker Management Easy.
> Build and manage your Docker environments with ease today.
> -- *[Portainer site](https://www.portainer.io/)*

## Examples

1. Launch Portainer locally.
   Example:

    ```console
    sudo docker run \
       --detach \
       --name portainer \
       --publish 9170:9000 \
       --restart always \
       --volume /var/run/docker.sock:/var/run/docker.sock \
       --volume /opt/portainer:/data \
       portainer/portainer
    ```

1. Windows.
   Example:

    ```console
    docker run --name portainer --publish 9170:9000 --volume //var/run/docker.sock:/var/run/docker.sock --volume C:\tmp\portainer-data:/data  portainer/portainer
    ```

   Reference: [StackOverflow](https://stackoverflow.com/questions/36765138/bind-to-docker-socket-on-windows)

1. Can be viewed at [localhost:9170](http://localhost:9170), since 9170 was the published port.

## Sites

1. [Website](https://www.portainer.io/)
    1. [Overview](https://www.portainer.io/overview/)
1. [Demo](http://demo.portainer.io/) (username: admin and password: tryportainer)
1. [Documentation](https://portainer.readthedocs.io/en/stable/)
1. [Ports used in Demonstrations](../lists/ports-used-in-demonstrations.md)
