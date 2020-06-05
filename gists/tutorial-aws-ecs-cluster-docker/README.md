# tutorial-aws-ecs-cluster-docker

This is a copy/paste version of
[Tutorial: Creating a Cluster with an EC2 Task Using the Amazon ECS CLI](https://docs.aws.amazon.com/AmazonECS/latest/developerguide/ecs-cli-tutorial-ec2.html)

## Contents

1. [Install ECS CLI](#install-ecs-cli)

## Prerequisites

### Install ECS CLI

Follow steps at
[Configuring the Amazon ECS CLI](https://docs.aws.amazon.com/AmazonECS/latest/developerguide/ECS_CLI_installation.html).

1. References:
    1. [Installing the Amazon ECS CLI](https://docs.aws.amazon.com/AmazonECS/latest/developerguide/ECS_CLI_installation.html).
    1. [AWS](https://aws.amazon.com/)
       &gt; [Documentation](https://docs.aws.amazon.com/index.html)
       &gt; [Amazon ECS](https://docs.aws.amazon.com/ecs/index.html)
       &gt; [Developer Guide](https://docs.aws.amazon.com/AmazonECS/latest/developerguide/Welcome.html)
       &gt; [ecs-cli](https://docs.aws.amazon.com/AmazonECS/latest/developerguide/cmd-ecs-cli.html)

### Multi-factor authentication

1. Configure environment variables.
   See [How to set AWS multi-factor authentication credentials](../../HOWTO/set-aws-mfa-credentials.md).

## XXX

### Identify metadata

#### AWS metadata

1. :pencil2: XXX.
   Example:

    ```console
    export AWS_REGION=us-east-1
    export AWS_KEYPAIR=aws-default-key-pair
    ```

#### Identify project

1. :pencil2: XXX.
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

### Create cluster

1. References:
    1. [ecs-cli](https://docs.aws.amazon.com/AmazonECS/latest/developerguide/ECS_CLI_reference.html)
       [up](https://docs.aws.amazon.com/AmazonECS/latest/developerguide/cmd-ecs-cli-up.html)

1. Bring up and AWS Elastic Container Service (ECS) instance.
   Example:

    ```console
    ecs-cli up \
      --capability-iam \
      --cluster-config ${AWS_PROJECT}-config-name \
      --force \
      --instance-type t2.medium \
      --keypair ${AWS_KEYPAIR} \
      --size 2
    ```

1. Verify in AWS Console:
    1. [ec2](https://console.aws.amazon.com/ec2/v2/home)
        1. [instances](https://console.aws.amazon.com/ec2/v2/home?#Instances)
        1. [launch configurations](https://console.aws.amazon.com/ec2/autoscaling/home?#LaunchConfigurations)
        1. [auto scaling groups](https://console.aws.amazon.com/ec2/autoscaling/home?#AutoScalingGroups)
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


## Cleanup

## References

1. [AWS](https://aws.amazon.com/)
   &gt; [Documentation](https://docs.aws.amazon.com/index.html)
   &gt; [Amazon ECS](https://docs.aws.amazon.com/ecs/index.html)
   &gt; [Developer Guide](https://docs.aws.amazon.com/AmazonECS/latest/developerguide/Welcome.html)
