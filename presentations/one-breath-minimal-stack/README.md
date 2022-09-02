# One Breath: Minimal docker-compose stack

## AWS EC2

Deploy a clean AWS EC2 instance to be used in demonstrating the Senzing docker-compose stack.

1. **Application and OS Images (Amazon Machine Image):**
    1. Amazon Linux
1. **Instance type:**
    1. t2.2xlarge
1. **Network settings:**
    1. (*) Create security group
        1. [x] Allow SSH traffic from Anywhere
        1. [ ] Allow HTTPS traffic from internet
        1. [x] Allow HTTP traffic from internet
1. **Configure storage:**
    1. 40GIB of gp2
1. Click "Launch instance"

## Log into EC2 instance

1. :pencil2: SSH into AWS EC2 instance.
   Example:

    ```console
    ssh -i "/path/to/your.pem" ec2-user@ec2-nn-nnn-nnn-nnn.compute-1.amazonaws.com
    ```

## Prerequisites

Install non-Senzing pre-requisite software.

1. Condensed version of
   [How to install Docker on Amazon Linux 2](https://www.cyberciti.biz/faq/how-to-install-docker-on-amazon-linux-2/).
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

Download artifacts.

1. Download
   [docker-compose.yaml](https://github.com/Senzing/knowledge-base/blob/main/presentations/one-breath-minimal-stack/docker-compose.yaml)
   file.
   Example:

    ```console
    wget "https://raw.githubusercontent.com/Senzing/knowledge-base/main/presentations/one-breath-minimal-stack/docker-compose.yaml"

    ```

1. Download Docker images.
   Example:

    ```console
    docker-compose pull

    ```

## Run

Bring up a [Senzing stack](https://github.com/Senzing/docker-compose-demo#overview).

1. Run Senzing docker-compose stack.
   Example:

    ```console
    docker-compose up

    ```

## Use

1. Open web browser to AWS's assigned IP address.
1. Variations on the [Senzing stack](https://github.com/Senzing/docker-compose-demo#overview).
