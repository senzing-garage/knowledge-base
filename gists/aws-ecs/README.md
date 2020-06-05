# docker-compose-on-aws-ecs

## WARNING: work in progress

## Contents

1. [Steps](#steps)
    1. [AWS metadata](#aws-metadata)
    1. [Identify project](#identify-project)
    1. [Create cluster](#create-cluster)
1. [Cleanup](#cleanup)

## Steps

### AWS metadata

1. :pencil2: AWS metadata used by multiple CLI invocations.
   Example:

    ```console
    export AWS_AVAILABILITY_ZONE=us-east-1e
    export AWS_IMAGE_ID=ami-0d592b9373fad0e2c
    export AWS_INSTANCE_TYPE=t2.micro
    export AWS_KEYPAIR=aws-default-key-pair
    export AWS_REGION=us-east-1
    ```

### Identify project

1. :pencil2: User determined prefix to AWS objects names.
   Example:

    ```console
    export AWS_PROJECT=project01
    ```

### Create cluster

1. References:
    1. [AWS CLI Command reference](https://docs.aws.amazon.com/cli/latest/index.html)
        1. [aws](https://docs.aws.amazon.com/cli/latest/reference/index.html#cli-aws)
           [ecs](https://docs.aws.amazon.com/cli/latest/reference/ecs/index.html#cli-aws-ecs)
           [create-cluster](https://awscli.amazonaws.com/v2/documentation/api/latest/reference/ecs/create-cluster.html)

1. Create cluster.
   Example:

    ```console
    aws ecs create-cluster \
      --cluster-name ${AWS_PROJECT}-cluster
    ```

1. Verify in AWS Console:
    1. [ecs](https://console.aws.amazon.com/ecs/home)

### Create EC2

1. References:
    1. [AWS CLI Command reference](https://docs.aws.amazon.com/cli/latest/index.html)
        1. [aws](https://docs.aws.amazon.com/cli/latest/reference/index.html#cli-aws)
           [ec2](https://docs.aws.amazon.com/cli/latest/reference/ec2/index.html)
           [run-instances](https://docs.aws.amazon.com/cli/latest/reference/ec2/run-instances.html)

1. Try launching the image.
   Example:

    ```console
    aws ec2 run-instances \
      --image-id ${AWS_IMAGE_ID} \
      --instance-type ${AWS_INSTANCE_TYPE} \
      --key-name ${AWS_KEYPAIR} \
      --tag-specifications "ResourceType=instance,Tags=[{Key=Name,Value=${AWS_PROJECT}-ecs-instance}]"
    ```

1. Verify in AWS Console:
    1. [ec2](https://console.aws.amazon.com/ec2/v2/home)


### Add container agent to ECS

1. References:
    1. [AWS CLI Command reference](https://docs.aws.amazon.com/cli/latest/index.html)
        1. [aws](https://docs.aws.amazon.com/cli/latest/reference/index.html#cli-aws)
           [ec2](https://docs.aws.amazon.com/cli/latest/reference/ec2/index.html)
           [update-container-agent](https://docs.aws.amazon.com/cli/latest/reference/ecs/update-container-agent.html)


1. XXX
   Example:

    ```console
    aws ecs update-container-agent \
      --cluster ${AWS_PROJECT}-cluster \
      --container-instance i-0ec696ba080c8f80c
    ```

### List container instances

1. References:
    1. [AWS CLI Command reference](https://docs.aws.amazon.com/cli/latest/index.html)
        1. [aws](https://docs.aws.amazon.com/cli/latest/reference/index.html#cli-aws)
           [ecs](https://docs.aws.amazon.com/cli/latest/reference/ecs/index.html#cli-aws-ecs)
           [list-container-instances](https://docs.aws.amazon.com/cli/latest/reference/ecs/list-container-instances.html)

1. Try launching the image.
   Example:

    ```console
    aws ecs list-container-instances \
      --cluster ${AWS_PROJECT}-cluster
    ```

1. Verify in AWS Console:
    1. [Ec2](https://console.aws.amazon.com/ec2/v2/home)
    1. [cluster ECS Instances](https://console.aws.amazon.com/ecs/home?#/clusters/mjd05-cluster/containerInstances)

## Cleanup

1. Cleanup.
   Example:

    ```console
    aws ecs delete-cluster \
      --cluster ${AWS_PROJECT}-cluster-name

    ```

1. Verify in AWS Console.
    1. [Clusters](https://console.aws.amazon.com/ecs/home)


## References

1. [Tutorial: Creating a Cluster with an EC2 Task Using the AWS CLI](https://docs.aws.amazon.com/AmazonECS/latest/developerguide/ECS_AWSCLI_EC2.html)
