# tutorial-aws-ecs-cluster-docker

This is a copy/paste version of
[Tutorial: Creating a Cluster with an EC2 Task Using the Amazon ECS CLI](https://docs.aws.amazon.com/AmazonECS/latest/developerguide/ecs-cli-tutorial-ec2.html)

## Contents

1. [Prerequisites](#prerequisites)
    1. [Install ECS CLI](#install-ecs-cli)
    1. [Multi-factor authentication](#multi-factor-authentication)
1. [Tutorial](#tutorial)
    1. [Identify metadata](#identify-metadata)
1. [Cleanup](#cleanup)
1. [References](#references)

## Prerequisites

### Install ECS CLI

To install `ecs-cli`, follow steps at
[Configuring the Amazon ECS CLI](https://docs.aws.amazon.com/AmazonECS/latest/developerguide/ECS_CLI_installation.html).

### Multi-factor authentication

:thinking: **Optional:** If multi-factor authentication is used to access AWS,
see [How to set AWS multi-factor authentication credentials](../../HOWTO/set-aws-mfa-credentials.md).

## Tutorial

### Identify metadata

#### AWS metadata

1. :pencil2: Set AWS metadata.
   Example:

    ```console
    export AWS_REGION=us-east-1
    export AWS_KEYPAIR=aws-default-key-pair
    ```

#### Identify project

1. :pencil2: Choose a prefix used in AWS object names.
   Example:

    ```console
    export AWS_PROJECT=project01
    ```

### Configure ECS CLI

1. References
    1. [ecs-cli](https://docs.aws.amazon.com/AmazonECS/latest/developerguide/ECS_CLI_reference.html)
       [configure](https://docs.aws.amazon.com/AmazonECS/latest/developerguide/cmd-ecs-cli-configure.html)

1. Create an AWS configuration.
   Example:

    ```console
    ecs-cli configure \
       --cluster ${AWS_PROJECT}-cluster \
       --config-name ${AWS_PROJECT}-config-name \
       --default-launch-type EC2 \
       --region ${AWS_REGION}
    ```

1. Configuration values are stored in `~/.ecs/config`.

    ```console
    cat ~/.ecs/config
    ```

### Create cluster

1. References:
    1. [ecs-cli](https://docs.aws.amazon.com/AmazonECS/latest/developerguide/ECS_CLI_reference.html)
       [up](https://docs.aws.amazon.com/AmazonECS/latest/developerguide/cmd-ecs-cli-up.html)

1. Bring up an AWS Elastic Container Service (ECS) instance.
   Example:

    ```console
    ecs-cli up \
      --capability-iam \
      --cluster-config ${AWS_PROJECT}-config-name \
      --force \
      --instance-type t2.micro \
      --keypair ${AWS_KEYPAIR} \
      --size 2
    ```

1. Verify in AWS Console:
    1. [ec2](https://console.aws.amazon.com/ec2/v2/home)
        1. [auto scaling groups](https://console.aws.amazon.com/ec2/autoscaling/home?#AutoScalingGroups)
        1. [cloudformation](https://console.aws.amazon.com/cloudformation/home?#/stacks)
        1. [instances](https://console.aws.amazon.com/ec2/v2/home?#Instances)
        1. [launch configurations](https://console.aws.amazon.com/ec2/autoscaling/home?#LaunchConfigurations)
    1. [ecs](https://console.aws.amazon.com/ecs/home)
        1. Select ${AWS_PROJECT}-cluster
        1. Click "Update Cluster" to update information.
        1. Click "ECS instances" tab.

### Create hello-world task

1. References:
    1. [ecs-cli](https://docs.aws.amazon.com/AmazonECS/latest/developerguide/ECS_CLI_reference.html)
       [compose](https://docs.aws.amazon.com/AmazonECS/latest/developerguide/cmd-ecs-cli-compose.html)
       [up](https://docs.aws.amazon.com/AmazonECS/latest/developerguide/cmd-ecs-cli-compose-up.html)

1. Deploy `docker-compose.yaml` file.
   Example:

    ```console
    ecs-cli compose \
      --cluster-config ${AWS_PROJECT}-config-name \
      --ecs-params ~/senzing.git/knowledge-base/gists/tutorial-aws-ecs-cluster-docker/ecs-params.yaml \
      --file ~/senzing.git/knowledge-base/gists/tutorial-aws-ecs-cluster-docker/docker-compose.yaml \
      --project-name ${AWS_PROJECT}-project-name \
      up \
      --create-log-groups \
      --launch-type EC2
    ```

1. Verify in AWS Console:
    1. [ecs](https://console.aws.amazon.com/ecs/home)
        1. Select ${AWS_PROJECT}-cluster
        1. Click "Update Cluster" to update information.
        1. Click "Tasks" tab.

### View tasks

:thinking: **Optional:** view the containers.

1. References:
    1. [ecs-cli](https://docs.aws.amazon.com/AmazonECS/latest/developerguide/ECS_CLI_reference.html)
       [ps](https://docs.aws.amazon.com/AmazonECS/latest/developerguide/cmd-ecs-cli-ps.html)

1. View containers.
   Example:

    ```console
    ecs-cli ps \
      --cluster-config ${AWS_PROJECT}-config-name
    ```

1. Verify in AWS Console:
    1. [ecs](https://console.aws.amazon.com/ecs/home)
        1. Select ${AWS_PROJECT}-cluster
        1. Click "Update Cluster" to update information.
        1. Click "Tasks" tab.

### Scale tasks

:thinking: **Optional:** view the containers.

1. References:
    1. [ecs-cli](https://docs.aws.amazon.com/AmazonECS/latest/developerguide/ECS_CLI_reference.html)
       [compose](https://docs.aws.amazon.com/AmazonECS/latest/developerguide/cmd-ecs-cli-compose.html)
       [scale](https://docs.aws.amazon.com/AmazonECS/latest/developerguide/cmd-ecs-cli-scale.html)

1. View  containers.
   Example:

    ```console
    ecs-cli compose \
      --cluster-config ${AWS_PROJECT}-config-name \
      --ecs-params ~/senzing.git/knowledge-base/gists/tutorial-aws-ecs-cluster-docker/ecs-params.yaml \
      --file ~/senzing.git/knowledge-base/gists/tutorial-aws-ecs-cluster-docker/docker-compose.yaml \
      --project-name ${AWS_PROJECT}-project-name \
      scale 2 \
      --cluster-config ${AWS_PROJECT}-config-name
    ```

1. View  containers.
   Example:

    ```console
    ecs-cli ps \
      --cluster-config ${AWS_PROJECT}-config-name
    ```

1. Verify in AWS Console:
    1. [ecs](https://console.aws.amazon.com/ecs/home)
        1. Select ${AWS_PROJECT}-cluster
        1. Click "Update Cluster" to update information.
        1. Click "Tasks" tab.

### Bring down

1. References:
    1. [ecs-cli](https://docs.aws.amazon.com/AmazonECS/latest/developerguide/ECS_CLI_reference.html)
       [compose](https://docs.aws.amazon.com/AmazonECS/latest/developerguide/cmd-ecs-cli-compose.html)
       [down](https://docs.aws.amazon.com/AmazonECS/latest/developerguide/cmd-ecs-cli-down.html)

1. View  containers.
   Example:

    ```console
    ecs-cli compose \
      --cluster-config ${AWS_PROJECT}-config-name \
      --ecs-params ~/senzing.git/knowledge-base/gists/tutorial-aws-ecs-cluster-docker/ecs-params.yaml \
      --file ~/senzing.git/knowledge-base/gists/tutorial-aws-ecs-cluster-docker/docker-compose.yaml \
      --project-name ${AWS_PROJECT}-project-name \
      down \
      --cluster-config ${AWS_PROJECT}-config-name
    ```

1. Verify in AWS Console:
    1. [ecs](https://console.aws.amazon.com/ecs/home)
        1. Select ${AWS_PROJECT}-cluster
        1. Click "Update Cluster" to update information.
        1. Click "Tasks" tab.

### Bring up service

1. References:
    1. [ecs-cli](https://docs.aws.amazon.com/AmazonECS/latest/developerguide/ECS_CLI_reference.html)
       [compose](https://docs.aws.amazon.com/AmazonECS/latest/developerguide/cmd-ecs-cli-compose.html)
       [service](https://docs.aws.amazon.com/AmazonECS/latest/developerguide/cmd-ecs-cli-compose-service.html)
       [up](https://docs.aws.amazon.com/AmazonECS/latest/developerguide/cmd-ecs-cli-compose-service-up.html)

1. Bring up service.
   Example:

    ```console
    ecs-cli compose \
      --cluster-config ${AWS_PROJECT}-config-name \
      --ecs-params ~/senzing.git/knowledge-base/gists/tutorial-aws-ecs-cluster-docker/ecs-params.yaml \
      --file ~/senzing.git/knowledge-base/gists/tutorial-aws-ecs-cluster-docker/docker-compose.yaml \
      --project-name ${AWS_PROJECT}-project-name \
      service up \
      --cluster-config ${AWS_PROJECT}-config-name
    ```

1. Verify in AWS Console:
    1. [ec2](https://console.aws.amazon.com/ec2/v2/home)
        1. [network interfaces](https://console.aws.amazon.com/ec2/v2/home?#NIC)
    1. [ecs](https://console.aws.amazon.com/ecs/home)
        1. Select ${AWS_PROJECT}-cluster
        1. Click "Update Cluster" to update information.
        1. Click "Services" tab.

### View Web App

1. Find ip address.
   Example:

    ```console
    ecs-cli ps \
      --cluster-config ${AWS_PROJECT}-config-name
    ```

1. Find in AWS Console:
    1. [ec2](https://console.aws.amazon.com/ec2/v2/home)
        1. [network interfaces](https://console.aws.amazon.com/ec2/v2/home?#NIC)

1. Open web browser to IP address.
   A "Simple PHP App" banner will be displayed.

## Cleanup

### Bring down service

1. References:
    1. [ecs-cli](https://docs.aws.amazon.com/AmazonECS/latest/developerguide/ECS_CLI_reference.html)
       [compose](https://docs.aws.amazon.com/AmazonECS/latest/developerguide/cmd-ecs-cli-compose.html)
       [service](https://docs.aws.amazon.com/AmazonECS/latest/developerguide/cmd-ecs-cli-compose-service.html)
       [rm](https://docs.aws.amazon.com/AmazonECS/latest/developerguide/cmd-ecs-cli-compose-service-rm.html)

1. Find ip address.
   Example:

    ```console
    ecs-cli compose \
      --cluster-config ${AWS_PROJECT}-config-name \
      --ecs-params ~/senzing.git/knowledge-base/gists/tutorial-aws-ecs-cluster-docker/ecs-params.yaml \
      --file ~/senzing.git/knowledge-base/gists/tutorial-aws-ecs-cluster-docker/docker-compose.yaml \
      --project-name ${AWS_PROJECT}-project-name \
      service rm \
      --cluster-config ${AWS_PROJECT}-config-name
    ```

### Bring down cluster

1. References:
    1. [ecs-cli](https://docs.aws.amazon.com/AmazonECS/latest/developerguide/ECS_CLI_reference.html)
       [down](https://docs.aws.amazon.com/AmazonECS/latest/developerguide/cmd-ecs-cli-down.html)

1. Find ip address.
   Example:

    ```console
    ecs-cli down \
      --force \
      --cluster-config ${AWS_PROJECT}-config-name
    ```

### Verify in AWS console

1. Verify in AWS Console:
    1. [ec2](https://console.aws.amazon.com/ec2/v2/home)
        1. [auto scaling groups](https://console.aws.amazon.com/ec2/autoscaling/home?#AutoScalingGroups)
        1. [cloudformation](https://console.aws.amazon.com/cloudformation/home?#/stacks)
        1. [instances](https://console.aws.amazon.com/ec2/v2/home?#Instances)
        1. [launch configurations](https://console.aws.amazon.com/ec2/autoscaling/home?#LaunchConfigurations)
        1. [network interfaces](https://console.aws.amazon.com/ec2/v2/home?#NIC)
    1. [ecs](https://console.aws.amazon.com/ecs/home)

## References

1. [Installing the Amazon ECS CLI](https://docs.aws.amazon.com/AmazonECS/latest/developerguide/ECS_CLI_installation.html).
1. [AWS](https://aws.amazon.com/)
   &gt; [Documentation](https://docs.aws.amazon.com/index.html)
   &gt; [Amazon ECS](https://docs.aws.amazon.com/ecs/index.html)
   &gt; [Developer Guide](https://docs.aws.amazon.com/AmazonECS/latest/developerguide/Welcome.html)
