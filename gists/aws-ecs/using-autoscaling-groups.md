# docker-compose-on-aws-ecs

## WARNING: work in progress

## Contents

1. [Steps](#steps)
    1. [AWS metadata](#aws-metadata)
    1. [Identify project](#identify-project)
    1. [Create launch configuration](#create-launch-configuration)
    1. [Create auto-scaling-group-provider](#create-auto-scaling-group-provider)
    1. [Create default auto-scaling-group-provider](#create-default-auto-scaling-group-provider)
    1. [Create capacity provider](#create-capacity-provider)
    1. [Create default capacity provider](#create-default-capacity-provider)
    1. [Create cluster](#create-cluster)
1. [Cleanup](#cleanup)

## Steps

### AWS metadata

1. :pencil2: AWS metadata used by multiple CLI invocations.
   Example:

    ```console
    export AWS_REGION=us-east-1
    export AWS_AVAILABILITY_ZONE=us-east-1e
    export AWS_KEYPAIR=aws-default-key-pair
    ```

### Identify project

1. :pencil2: User determined prefix to AWS objects names.
   Example:

    ```console
    export AWS_PROJECT=project01
    ```

### Create launch configuration

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

1. Verify in AWS Console: [Launch Configurations](https://console.aws.amazon.com/ec2/autoscaling/home)

### Create auto-scaling-group-provider

1. References:
    1. [AWS CLI Command reference](https://docs.aws.amazon.com/cli/latest/index.html)
        1. [aws](https://docs.aws.amazon.com/cli/latest/reference/index.html#cli-aws)
           [autoscaling](https://docs.aws.amazon.com/cli/latest/reference/autoscaling/index.html#cli-aws-autoscaling)
           [create-auto-scaling-group](https://docs.aws.amazon.com/cli/latest/reference/autoscaling/create-auto-scaling-group.html)
        1. [aws](https://docs.aws.amazon.com/cli/latest/reference/index.html#cli-aws)
           [autoscaling](https://docs.aws.amazon.com/cli/latest/reference/autoscaling/index.html#cli-aws-autoscaling)
           [describe-auto-scaling-groups](https://docs.aws.amazon.com/cli/latest/reference/autoscaling/describe-auto-scaling-groups.html)

1. Create autoscaling group.
   Example:

    ```console
    aws autoscaling create-auto-scaling-group \
      --auto-scaling-group-name ${AWS_PROJECT}-auto-scaling-group-name \
      --availability-zones ${AWS_AVAILABILITY_ZONE} \
      --launch-configuration-name ${AWS_PROJECT}-launch-configuration-name \
      --max-size 2 \
      --min-size 1
    ```

1. Find autoscaling group ARN.
   Example:

    ```console
    export AWS_AUTO_SCALING_GROUP_ARN=$(aws autoscaling describe-auto-scaling-groups \
      --auto-scaling-group-name ${AWS_PROJECT}-auto-scaling-group-name \
      | jq --raw-output .AutoScalingGroups[0].AutoScalingGroupARN)
    ```

1. Verify in AWS Console: [Autoscaling](https://console.aws.amazon.com/ec2/autoscaling/home)

### Create default auto-scaling-group-provider

1. References:
    1. [AWS CLI Command reference](https://docs.aws.amazon.com/cli/latest/index.html)
        1. [aws](https://docs.aws.amazon.com/cli/latest/reference/index.html#cli-aws)
           [autoscaling](https://docs.aws.amazon.com/cli/latest/reference/autoscaling/index.html#cli-aws-autoscaling)
           [create-auto-scaling-group](https://docs.aws.amazon.com/cli/latest/reference/autoscaling/create-auto-scaling-group.html)
        1. [aws](https://docs.aws.amazon.com/cli/latest/reference/index.html#cli-aws)
           [autoscaling](https://docs.aws.amazon.com/cli/latest/reference/autoscaling/index.html#cli-aws-autoscaling)
           [describe-auto-scaling-groups](https://docs.aws.amazon.com/cli/latest/reference/autoscaling/describe-auto-scaling-groups.html)

1. Create autoscaling group.
   Example:

    ```console
    aws autoscaling create-auto-scaling-group \
      --auto-scaling-group-name ${AWS_PROJECT}-default-auto-scaling-group-name \
      --availability-zones ${AWS_AVAILABILITY_ZONE} \
      --launch-configuration-name ${AWS_PROJECT}-launch-configuration-name \
      --max-size 2 \
      --min-size 1
    ```

1. Find autoscaling group ARN.
   Example:

    ```console
    export AWS_DEFAULT_AUTO_SCALING_GROUP_ARN=$(aws autoscaling describe-auto-scaling-groups \
      --auto-scaling-group-name ${AWS_PROJECT}-default-auto-scaling-group-name \
      | jq --raw-output .AutoScalingGroups[0].AutoScalingGroupARN)
    ```

1. Verify in AWS Console: [Autoscaling](https://console.aws.amazon.com/ec2/autoscaling/home)

### Create capacity provider

1. References:
    1. [AWS CLI Command reference](https://docs.aws.amazon.com/cli/latest/index.html)
        1. [aws](https://docs.aws.amazon.com/cli/latest/reference/index.html#cli-aws)
           [ecs](https://docs.aws.amazon.com/cli/latest/reference/ecs/index.html#cli-aws-ecs)
           [create-capacity-provider](https://docs.aws.amazon.com/cli/latest/reference/ecs/create-capacity-provider.html)

1. Create capacity provider.
   Example:

    ```console
    aws ecs create-capacity-provider \
      --name  ${AWS_PROJECT}-capacity-provider \
      --auto-scaling-group-provider "autoScalingGroupArn=${AWS_AUTO_SCALING_GROUP_ARN},managedScaling={status=DISABLED,targetCapacity=1,minimumScalingStepSize=1,maximumScalingStepSize=1},managedTerminationProtection=DISABLED"
    ```

1. Verify in AWS Console: [????](http://nowhere.com)

### Create default capacity provider

1. References:
    1. [AWS CLI Command reference](https://docs.aws.amazon.com/cli/latest/index.html)
        1. [aws](https://docs.aws.amazon.com/cli/latest/reference/index.html#cli-aws)
           [ecs](https://docs.aws.amazon.com/cli/latest/reference/ecs/index.html#cli-aws-ecs)
           [create-capacity-provider](https://docs.aws.amazon.com/cli/latest/reference/ecs/create-capacity-provider.html)

1. Create capacity provider.
   Example:

    ```console
    aws ecs create-capacity-provider \
      --name  ${AWS_PROJECT}-default-capacity-provider \
      --auto-scaling-group-provider "autoScalingGroupArn=${AWS_DEFAULT_AUTO_SCALING_GROUP_ARN},managedScaling={status=DISABLED,targetCapacity=1,minimumScalingStepSize=1,maximumScalingStepSize=1},managedTerminationProtection=DISABLED"
    ```

1. Verify in AWS Console: [????](http://nowhere.com)

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
      --cluster-name ${AWS_PROJECT}-cluster-name \
      --capacity-providers ${AWS_PROJECT}-capacity-provider ${AWS_PROJECT}-default-capacity-provider  \
      --default-capacity-provider-strategy "capacityProvider=${AWS_PROJECT}-default-capacity-provider,weight=100,base=0"
    ```

1. Verify in AWS Console: [Clusters](https://console.aws.amazon.com/ecs/home)

## Cleanup

1. Cleanup.
   Example:

    ```console
    aws ecs delete-cluster \
      --cluster ${AWS_PROJECT}-cluster-name

    aws autoscaling delete-auto-scaling-group \
      --auto-scaling-group-name ${AWS_PROJECT}-default-auto-scaling-group-name \
      --force-delete

    aws autoscaling delete-auto-scaling-group \
      --auto-scaling-group-name ${AWS_PROJECT}-auto-scaling-group-name \
      --force-delete

    aws autoscaling delete-launch-configuration \
      --launch-configuration-name ${AWS_PROJECT}-launch-configuration-name
    ```

1. Verify in AWS Console.
    1. [Clusters](https://console.aws.amazon.com/ecs/home)
    1. [Autoscaling](https://console.aws.amazon.com/ec2/autoscaling/home)
    1. [Launch Configurations](https://console.aws.amazon.com/ec2/autoscaling/home)
