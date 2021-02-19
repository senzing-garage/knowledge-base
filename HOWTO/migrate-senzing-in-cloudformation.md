# How to migrate Senzing in AWS Cloudformation

## Contents

1. [Log into SSHD container](#log-into-sshd-container)
1. [Upgrade Senzing binaries](#upgrade-senzing-binaries)
1. [Upgrade database configuration](#upgrade-database-configuration)
1. [Upgrade Senzing configuration](#upgrade-senzing-configuration)

## Log into SSHD container

1. :pencil2: Identify CloudFormation Stack.
   Example:

    ```console
    export SENZING_AWS_CLOUDFORMATION_STACK_NAME=my-stack
    ```

1. Set environment variables.
   Example:

    ```console
    export SENZING_AWS_ECS_CLUSTER_NAME=${SENZING_AWS_CLOUDFORMATION_STACK_NAME}-cluster

    export SENZING_AWS_CLOUDFORMATION_DIR=~/${SENZING_AWS_CLOUDFORMATION_STACK_NAME}
    mkdir ${SENZING_AWS_CLOUDFORMATION_DIR}

    aws cloudformation describe-stacks \
        --stack-name ${SENZING_AWS_CLOUDFORMATION_STACK_NAME} \
        > ${SENZING_AWS_CLOUDFORMATION_DIR}/describe-stacks.json

    aws cloudformation describe-stack-resources \
        --stack-name ${SENZING_AWS_CLOUDFORMATION_STACK_NAME} \
        > ${SENZING_AWS_CLOUDFORMATION_DIR}/describe-stack-resources.json

    aws ecs list-tasks \
        --cluster ${SENZING_AWS_ECS_CLUSTER_NAME} \
        --family ${SENZING_AWS_CLOUDFORMATION_STACK_NAME}-task-definition-sshd \
        > ${SENZING_AWS_CLOUDFORMATION_DIR}/list-tasks-sshd.json

    export SENZING_AWS_ARN_SSHD=$(jq --raw-output ".taskArns[0]" ${SENZING_AWS_CLOUDFORMATION_DIR}/list-tasks-sshd.json)

    aws ecs describe-tasks \
        --cluster ${SENZING_AWS_ECS_CLUSTER_NAME} \
        --tasks ${SENZING_AWS_ARN_SSHD} \
        > ${SENZING_AWS_CLOUDFORMATION_DIR}/describe-tasks-sshd.json

    export SENZING_AWS_NETWORK_INTERFACE_ID=$(jq --raw-output '.tasks[0].attachments[0].details[] | select(.name=="networkInterfaceId").value' ${SENZING_AWS_CLOUDFORMATION_DIR}/describe-tasks-sshd.json)

    aws ec2 describe-network-interfaces \
        --network-interface-ids ${SENZING_AWS_NETWORK_INTERFACE_ID} \
        > ${SENZING_AWS_CLOUDFORMATION_DIR}/describe-network-interfaces-sshd.json

    export SENZING_AWS_SSHD_HOST=$(jq --raw-output ".NetworkInterfaces[0].Association.PublicIp" ${SENZING_AWS_CLOUDFORMATION_DIR}/describe-network-interfaces-sshd.json)
    export SENZING_AWS_SSHD_USERNAME=root
    export SENZING_AWS_SSHD_PASSWORD=$(jq --raw-output '.Stacks[0].Outputs[] | select(.OutputKey=="SshPassword").OutputValue' ${SENZING_AWS_CLOUDFORMATION_DIR}/describe-stacks.json)
    ```

1. Show environment variables.
   Example:

    ```console
    echo "Host: ${SENZING_AWS_SSHD_HOST}"
    echo "Username: ${SENZING_AWS_SSHD_USERNAME}"
    echo "Password: ${SENZING_AWS_SSHD_PASSWORD}"
    ```

1. Login to SSHD container.
   Use the value of `${SENZING_AWS_SSHD_PASSWORD}` as the password.
   Example:

    ```console
    ssh ${SENZING_AWS_SSHD_USERNAME}@${SENZING_AWS_SSHD_HOST}
    ```

## Upgrade Senzing binaries

The following commands are performed inside the SSHD container.

1. Backup prior Senzing installation
   Example:

    ```console
    export SENZING_OLD_VERSION=$(jq --raw-output ".BUILD_VERSION" /opt/senzing/g2/g2BuildVersion.json)
    export SENZING_OLD_DIR="/var/opt/senzing/backup-senzing-${SENZING_OLD_VERSION}"
    mkdir ${SENZING_OLD_DIR}

    cp -R /opt/senzing/g2 ${SENZING_OLD_DIR}/g2
    cp -R /opt/senzing/data ${SENZING_OLD_DIR}/data
    cp -R /etc/opt/senzing ${SENZING_OLD_DIR}/etc
    ```

1. Add Senzing package repository.
   Example:

    ```console
    apt update

    curl \
        --output /senzingrepo_1.0.0-1_amd64.deb \
        https://senzing-production-apt.s3.amazonaws.com/senzingrepo_1.0.0-1_amd64.deb

    apt -y install \
        /senzingrepo_1.0.0-1_amd64.deb

    apt update
    ```

1. Upgrade Senzing API.
   Example:

    ```console
    apt -y install senzingapi
    ```

   When prompted, accept the license terms and conditions.

## Upgrade database configuration

The following commands are performed inside the SSHD container.

1. Upgrade database configuration.
   Example:

    ```console
    /opt/senzing/g2/bin/g2dbupgrade \
        -c /etc/opt/senzing/G2Module.ini \
        -a
    ```

## Upgrade Senzing configuration

The following commands are performed inside the SSHD container.

:thinking: This step may not be required when upgrading.
Review the upgrade files in `/opt/senzing/g2/resources/config/` to see if an upgrade is required.

1. :pencil2: Identify Senzing configuration file.
   Example:

    ```console
    export SENZING_CONFIG_FILE=/opt/senzing/g2/resources/config/g2core-config-upgrade-n.nn-to-n.nn.gtc
    ```

1. Upgrade Senzing configuration.
   Example:

    ```console
    /opt/senzing/g2/python/G2ConfigTool.py \
        -c /etc/opt/senzing/G2Module.ini \
        -f ${SENZING_CONFIG_FILE}
    ```
