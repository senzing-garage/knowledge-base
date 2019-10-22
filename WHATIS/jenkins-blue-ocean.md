# What is Jenkins Blue Ocean

> Blue Ocean puts Continuous Delivery in reach of any team
> without sacrificing the power and sophistication of Jenkins.
> -- *[Jenkins Blue Ocean site](https://jenkins.io/projects/blueocean/)*

## Examples

1. Launch Jenkins Blue Ocean locally.
   Example:

    ```console
    sudo docker run \
      --detach \
      --name jenkins-blue-ocean \
      --user root \
      --rm \
      --publish 9176:8080 \
      --publish 50000:50000 \
      --volume jenkins-data:/var/jenkins_home \
      --volume /var/run/docker.sock:/var/run/docker.sock \
      jenkinsci/blueocean
    ```

1. Can be viewed at [localhost:9176](http://localhost:9176), since 9176 was the published port.

## Sites

1. [Website](https://jenkins.io/projects/blueocean/)
1. [Documentation](https://jenkins.io/doc/book/blueocean/)
    1. [Getting Started](https://jenkins.io/doc/book/blueocean/getting-started/)
1. [Ports used in Demonstrations](../lists/ports-used-in-demonstrations.md#9176)
