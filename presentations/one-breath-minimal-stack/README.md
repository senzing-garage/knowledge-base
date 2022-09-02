# One Breath: Minimal docker-compose stack

## Non-Senzing

A few preparatory steps are needed before working with Senzing.
The steps create an AWS EC2 instance, install `docker` and `docker-compose`.

### AWS EC2

Deploy a clean AWS EC2 instance to be used in demonstrating the Senzing docker-compose stack.
*Note:* An AWS EC2 instance is not needed.
The demonstration can be run on a local machine,
but the network speeds may not be as fast for downloading.

1. In [AWS EC2 console](https://us-east-2.console.aws.amazon.com/ec2/home):
    1. **Application and OS Images (Amazon Machine Image):**  Amazon Linux
    1. **Instance type:** t2.2xlarge
    1. **Key pair (login):** Choose or create a Key Pair
    1. **Network settings:**
        1. :radio_button: Create security group
            1. [x] Allow SSH traffic from Anywhere
            1. [ ] Allow HTTPS traffic from internet
            1. [x] Allow HTTP traffic from internet
    1. **Configure storage:** 40GIB of gp2
    1. Click "Launch instance" button
1. :pencil2: SSH into AWS EC2 instance.
   Example:

    ```console
    ssh -i "/path/to/your.pem" ec2-user@ec2-nn-nnn-nnn-nnn.compute-1.amazonaws.com
    ```

### Prerequisites

Install non-Senzing pre-requisite software,
`docker` and `docker-compose`.
*Note:* The instructions would be different for other operating systems.

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

## Senzing

After the preparatory steps are complete,
Senzing can be downloaded and run.

### Download

Download artifacts.

1. Download
   [docker-compose.yaml](https://github.com/Senzing/knowledge-base/blob/main/presentations/one-breath-minimal-stack/docker-compose.yaml)
   file.
   Example:

    ```console
    wget "https://raw.githubusercontent.com/Senzing/knowledge-base/main/presentations/one-breath-minimal-stack/docker-compose.yaml"

    ```

1. :thinking: **Optional:** An optional step to download Docker images quicker.
   Example:

    ```console
    docker-compose pull

    ```

### Run

Bring up a [Senzing stack](https://github.com/Senzing/docker-compose-demo#overview).

1. Run Senzing docker-compose stack.
   Example:

    ```console
    docker-compose up

    ```

## Use

1. Open web browser to AWS's assigned IP address.
