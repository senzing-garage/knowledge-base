# docker-compose-on-aws-ecs

# WARNING: work in progress.

## Contents

1. [AWS metadata](#aws-metadata)
1. [Identify project](#identify-project)
1. []()
1. []()
1. []()


### AWS metadata

1. :pencil2: AWS metadata used by multiple CLI invocations.
   Example:

    ```console
    export AWS_REGION=us-east-1
    export AWS_KEYPAIR=aws-default-key-pair
    ```

### Identify project

1. :pencil2: XXX.
   Example:

    ```console
    export AWS_PROJECT=project01
    ```

### Create Launch configuration

1. References:
    1. [AWS CLI Command reference](https://docs.aws.amazon.com/cli/latest/index.html)
        1. [aws](https://docs.aws.amazon.com/cli/latest/reference/index.html#cli-aws)
           [autoscaling](https://docs.aws.amazon.com/cli/latest/reference/autoscaling/index.html#cli-aws-autoscaling)
           [create-launch-configuration](https://docs.aws.amazon.com/cli/latest/reference/autoscaling/create-launch-configuration.html)


1. Create launch configuration.
   Example:

    ```console
    aws autoscaling create-launch-configuration \
      --launch-configuration-name ${AWS_PROJECT}-launch-configuration-name \
      --image-id ami-09d95fab7fff3776c \
      --instance-type t2.micro \
      --key-name ${AWS_KEYPAIR}
    ```

1. AWS Console: [Launch Configurations](https://console.aws.amazon.com/ec2/autoscaling/home)

### Create auto-scaling-group-provider

1. References:
    1. [AWS CLI Command reference](https://docs.aws.amazon.com/cli/latest/index.html)
        1. [aws](https://docs.aws.amazon.com/cli/latest/reference/index.html#cli-aws)
           [autoscaling](https://docs.aws.amazon.com/cli/latest/reference/autoscaling/index.html#cli-aws-autoscaling)
           [create-auto-scaling-group](https://docs.aws.amazon.com/cli/latest/reference/autoscaling/create-auto-scaling-group.html)

1. XXx
   Example:

    ```console
    aws autoscaling create-auto-scaling-group \
      --auto-scaling-group-name ${AWS_PROJECT}-auto-scaling-group-name \
      --launch-configuration-name ${AWS_PROJECT}-launch-configuration-name \
      --min-size 1 \
      --max-size 2
    ```

### Create capacity provider

1. References:
    1. [AWS CLI Command reference](https://docs.aws.amazon.com/cli/latest/index.html)
        1. [aws](https://docs.aws.amazon.com/cli/latest/reference/index.html#cli-aws)
           [ecs](create-capacity-provider)
           [create-capacity](https://docs.aws.amazon.com/cli/latest/reference/ecs/create-capacity-provider.html)

1. XXx
   Example:

    ```console
    aws ecs create-capacity-provider \
      --name  ${AWS_PROJECT}-capacity-provider \
      --auto-scaling-group-provider XXXXX
    ```

### Create hello-world task

1. XXx
   Example:

    ```console
    aws ecs register-task-definition \
      --family mjd-test-task \
      --cluster-config senzing-example-config \
      --force \
      --instance-type t2.medium \
      --keypair ${AWS_KEY_NAME} \
      --size 2
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
