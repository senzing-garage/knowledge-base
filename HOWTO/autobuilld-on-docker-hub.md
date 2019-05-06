# Autobuild on DockerHub

## Enable Autobuild

1. Visit [Senzing repository list](https://cloud.docker.com/u/senzing/repository/list) on `cloud.dockter.com`
1. Choose docker repository
1. Choose "Build" tab
1. Click "Configure Automated Build" link
1. Build configurations
    1. Source repository
        1. **Select organization:** Senzing
        1. **Select repository:** [Choose matching GitHub repository]
    1. Autotest
        1. (*) Internal and External Pull Requests
    1. Repository links
        1. (*) Enable for Base image
    1. Click "Save and Build"

## References

1. [Set up Automated builds](https://docs.docker.com/docker-hub/builds/)
