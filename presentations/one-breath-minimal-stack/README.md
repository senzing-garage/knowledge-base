# One Breath: Minimal docker-compose stack

## AWS EC2

1. **Application and OS Images (Amazon Machine Image):**
    1. Amazon Linux
1. **Instance type:**
    1. t2.large
1. **Network settings:**
    1. (*) Create security group
        1. [x] Allow SSH traffic from Anywhere
        1. [x] Allow HTTPS traffic from internet
        1. [x] Allow HTTP traffic from internet
1. **Configure storage:**
    1. 20GIB of gp2
1. Click "Launch instance"

## Log into EC2 instance

1. SSH.
   Example:

    ```console
    ssh -i "/path/to/your.pem" ec2-user@ec2-nn-nnn-nnn-nnn.compute-1.amazonaws.com
    ```

## Prerequisites

1. Condensed version of
   [How to install Docker on Amazon Linux 2](https://www.cyberciti.biz/faq/how-to-install-docker-on-amazon-linux-2/)
   Example:

    ```console
    sudo yum --assumeyes update
    sudo yum --assumeyes install docker python3-pip
    sudo usermod -a -G docker ec2-user
    id ec2-user
    newgrp docker
    sudo systemctl enable docker.service
    sudo systemctl start docker.service
    sudo pip3 install docker-compose

    ```

## Download

1. Example:

    ```console
    wget "https://raw.githubusercontent.com/Senzing/knowledge-base/main/presentations/one-breath-minimal-stack/docker-compose.yaml"

    ```

1. Download Docker images

    ```console
    docker-compose pull

    ```

1. Run Senzing docker-compose stack

    ```console
    docker-compose up

    ```
