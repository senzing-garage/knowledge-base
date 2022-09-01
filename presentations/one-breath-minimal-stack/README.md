# One Breath:   Minimal docker-compose stack

## AWS EC2

1. *Application and OS Images (Amazon Machine Image):*  Amazon Linux
1. *Instance type:*

1. XX

    ```console
    ssh -i "~/.ssh/aws-mjd-sso.pem" ec2-user@ec2-34-201-252-185.compute-1.amazonaws.com
    ```

## Prerequisites

1. Condensed version of
   [How to install Docker on Amazon Linux 2](https://www.cyberciti.biz/faq/how-to-install-docker-on-amazon-linux-2/)
   Example:

    ```console
    sudo yum update
    sudo yum install docker python3-pip
    sudo usermod -a -G docker ec2-user
    id ec2-user
    newgrp docker
    sudo systemctl enable docker.service
    sudo systemctl start docker.service
    sudo pip3 install docker-compose
    ```
