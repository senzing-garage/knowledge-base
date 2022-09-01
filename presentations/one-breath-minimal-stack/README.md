# One Breath:   Minimal docker-compose stack

## AWS EC2

1. **Application and OS Images (Amazon Machine Image):**
    1. Amazon Linux
1. **Instance type:**
    1. t2.large
1. **Configure storage:**
    1. 20GIB of gp2
1. **Network settings:**
    1. [x] Allow SSH traffic from Anywhere
    1. [x] Allow HTTP traffic from internet

1. XX

    ```console
    ssh -i "~/.ssh/aws-mjd-sso.pem" ec2-user@ec2-34-201-252-185.compute-1.amazonaws.com
    ```

1, *NOTE:* Open ports

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

1. XXX
   Example:

    ```console
    export SENZING_VOLUME=~/my-senzing
    export PGADMIN_DIR=${SENZING_VOLUME}/pgadmin
    export POSTGRES_DIR=${SENZING_VOLUME}/postgres
    export RABBITMQ_DIR=${SENZING_VOLUME}/rabbitmq
    export SENZING_VAR_DIR=${SENZING_VOLUME}/var
    export SENZING_UID=$(id -u)
    export SENZING_GID=$(id -g)
    mkdir -p ${PGADMIN_DIR} ${POSTGRES_DIR} ${RABBITMQ_DIR} ${SENZING_VAR_DIR}
    chmod -R 777 ${SENZING_VOLUME}

    curl -X GET \
        --output ${SENZING_VOLUME}/docker-versions-stable.sh \
        https://raw.githubusercontent.com/Senzing/knowledge-base/main/lists/docker-versions-stable.sh
    source ${SENZING_VOLUME}/docker-versions-stable.sh

    curl -X GET \
        --output ${SENZING_VOLUME}/docker-compose.yaml \
        "https://raw.githubusercontent.com/Senzing/knowledge-base/main/presentations/one-breath-minimal-stack/docker-compose.yaml"
    cd ${SENZING_VOLUME}
    docker-compose pull

    cd ${SENZING_VOLUME}
    docker-compose up
    ```
