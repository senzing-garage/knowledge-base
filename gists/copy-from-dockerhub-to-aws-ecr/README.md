# Copy images from DockerHub to AWS ECR

## Use AWS EC2 to copy docker images from DockerHub to AWS ECR

1. :pencil2: Identify your AWS "key pair".
   Example:

    ```console
    export AWS_KEY_NAME=MyKeyPair
    ```

1. :pencil2: Identify your local `.pem` file for the "key pair"
   Example:

    ```console
    export AWS_KEY_NAME_PEM=~/.ssh/my-sso.pem
    ```

1. Create AWS EC2 machine.

    ```console
    aws ec2 run-instances \
      --image-id ami-0c2b8ca1dad447f8a \
      --count 1 \
      --instance-type t2.micro
      --key-name ${AWS_KEY_NAME} \
      --security-group-ids sg-903004f8 \
      --subnet-id subnet-6e7f829e
    ```

**NOTE:** Need 32GB storage.

1. :pencil2: Login to AWS EC2

    ```console
    ssh -i ${AWS_KEY_NAME_PEM} ec2-user@ec2-54-162-110-105.compute-1.amazonaws.com
    ```

1. Become root.

    ```console
    sudo su -
    ```

1. Install and run docker.

    ```console
    sudo yum -y update
    yum -y install docker git
    ```

1. Restart and enable docker on restart.

    ```console
    systemctl restart docker.service
    sudo systemctl enable docker.service
    sudo systemctl enable containerd.service
    ```

1. Install latest `aws` CLI.

    ```console
    curl "https://awscli.amazonaws.com/awscli-exe-linux-x86_64.zip" -o "awscliv2.zip"
    unzip awscliv2.zip
    sudo ./aws/install
    ```

1. :pencil2: Use credentials from SSO Docker_Registry AWSPowerUserAccess

    ```console
    export AWS_ACCESS_KEY_ID=
    export AWS_SECRET_ACCESS_KEY=
    export AWS_SESSION_TOKEN=
    ```

1. Login to ECR.

    ```console
    aws ecr-public get-login-password --region us-east-1 | docker login --username AWS --password-stdin public.ecr.aws/d5v4a2g3
    ```

1. Install utility program.

    ```console
    mkdir ~/senzing.git
    cd ~/senzing.git
    git clone https://github.com/Senzing/aws-cloudformation-ecs-poc-simple.git
    git clone https://github.com/Senzing/knowledge-base.git
    ```

1. Run utility program

    ```console
    cd ~/senzing.git/aws-cloudformation-ecs-poc-simple/utils
    ./migrate-images-from-docker-hub.sh
    ```
