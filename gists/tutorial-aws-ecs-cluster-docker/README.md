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

### Create hello-world task

1. References:
    1. [ecs-cli](https://docs.aws.amazon.com/AmazonECS/latest/developerguide/ECS_CLI_reference.html)
       [compose](https://docs.aws.amazon.com/AmazonECS/latest/developerguide/cmd-ecs-cli-compose.html)
       up

1. XXx
   Example:

    ```console
    ecs-cli compose up \
      --cluster-config ${AWS_PROJECT}-config-name \
      --create-log-groups \
      --ecs-params ~/senzing.git/knowledge-base/gists/tutorial-aws-ecs-cluster-docker/ecs-params.yaml \
      --file ~/senzing.git/knowledge-base/gists/tutorial-aws-ecs-cluster-docker/docker-compose.yaml \
      --project-name ${AWS_PROJECT}-project-name
    ```

### Create AWS Elastic File System instance

1. References:

    - [aws efs create-file-system reference](https://docs.aws.amazon.com/cli/latest/reference/efs/create-file-system.html)

1. Bring up and AWS Elastic Container Service (ECS) instance.
   Example:

    ```console
    aws efs create-file-system \
      --creation-token senzing-g2-volume \
      --region ${AWS_REGION}
    ```

## Deploy docker-compose file to cluster

1. Deploy docker-compose file.
   Example:

    ```console
    ecs-cli compose up \
      --cluster-config senzing-example-config \
      --create-log-groups \
      --file ~/senzing.git/docker-compose-demo/resources/postgresql/docker-compose-rabbitmq-postgresql.yaml \
      --file ~/senzing.git/docker-compose-demo/resources/postgresql/ecs-params.yaml
    ```

## View Containers

1. XXX
   Example:

    ```console
    ecs-cli ps \
      --cluster-config senzing-example-config
    ```

## Bring down

1. XXX
   Example:

    ```console
    ecs-cli compose down \
      --cluster-config senzing-example-config
    ```

    ```console
    ecs-cli down \
      --cluster-config senzing-example-config
    ```

## Create service

1. XXX
   Example:

    ```console
    ecs-cli compose service up \
      --cluster-config senzing-example-config
    ```


## clean up

1. XXX
   Example:

    ```console
    ecs-cli compose service rm \
      --cluster-config senzing-example-config
    ```

1. XXX
   Example:

    ```console
    ecs-cli compose service rm \
      --cluster-config senzing-example-config
    ```


## References

1. [AWS](https://aws.amazon.com/)
   &gt; [Documentation](https://docs.aws.amazon.com/index.html)
   &gt; [Amazon ECS](https://docs.aws.amazon.com/ecs/index.html)
   &gt; [Developer Guide](https://docs.aws.amazon.com/AmazonECS/latest/developerguide/Welcome.html)
