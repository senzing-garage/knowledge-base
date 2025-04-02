# Copy images from DockerHub to AWS ECR

## Use AWS EC2 to copy docker images from DockerHub to AWS ECR

### Launch EC2 instance

1. Use a "CFn Team Sandbox" account.

1. Create EC2 using
   [AWS EC2 management console](https://console.aws.amazon.com/ec2/v2/home?region=us-east-1#Instances:).

   1. On left-hand navigation, select "Instances"
   1. In upper-right, click "Launch instances".
   1. In "Step 1: Choose an Amazon Machine Image (AMI)"
      1. Select "Amazon Linux 2 AMI (HVM), SSD Volume Type - ami-04ad2567c9e3d7893 (64-bit x86)"
   1. In "Step 2: Choose an Instance Type"
      1. Select "t2.micro"
      1. Click "Next: Configure Instance Details"
   1. In "Step 3: Configure Instance Details"
      1. _Shutdown behavior:_ Terminate
      1. Click "Next: Add Storage"
   1. In "Step 4: Add storage"
      1. _Size:_ 32 (GiB)
      1. Click "Next: Add Tags"
   1. In "Step 5: Add Tags"
      1. Click "Next: Configure Security Group"
   1. In "Step 6: Configure Security Group"
      1. Select "(\*) Select and existing security group"
      1. Choose "Default" group
      1. Click "Review and Launch"
   1. In "Step 7: Review Instance launch"
      1. Click "Launch"

### Login to EC2 instance

1. :pencil2: Identify "Public IPv4 DNS"
   Information on [AWS EC2 Management console](https://console.aws.amazon.com/ec2/v2/home?region=us-east-1#Instances:)
   Example:

   ```console
   export AWS_ECS_HOSTNAME=ec2-18-207-150-41.compute-1.amazonaws.com
   ```

1. :pencil2: Identify your local `.pem` file for the "key pair".
   Example:

   ```console
   export AWS_KEY_NAME_PEM=~/.ssh/my-key-pair.pem
   ```

1. Login to AWS EC2.
   Example:

   ```console
   ssh -i ${AWS_KEY_NAME_PEM} ec2-user@${AWS_ECS_HOSTNAME}
   ```

### Prepare EC2 instance

1. Become root.
   Example:

   ```console
   sudo su -
   ```

1. Install and run docker.
   Example:

   ```console
   sudo yum -y update
   yum -y install docker git
   ```

1. Restart and enable docker on restart.
   Example:

   ```console
   systemctl restart docker.service
   sudo systemctl enable docker.service
   sudo systemctl enable containerd.service
   ```

1. Install latest `aws` CLI.
   Example:

   ```console
   curl "https://awscli.amazonaws.com/awscli-exe-linux-x86_64.zip" -o "awscliv2.zip"
   unzip awscliv2.zip
   sudo ./aws/install
   ```

1. Install utility program.
   Example:

   ```console
   mkdir ~/senzing.git
   cd ~/senzing.git
   git clone https://github.com/senzing-garage/aws-cloudformation-ecs-poc-simple.git
   git clone https://github.com/senzing-garage/knowledge-base.git
   ```

### Copy image to public ECR

1. :pencil2: Use credentials from _Docker_Registry_ > _AWSPowerUserAccess_.
   Example:

   ```console
   export AWS_ACCESS_KEY_ID=
   export AWS_SECRET_ACCESS_KEY=
   export AWS_SESSION_TOKEN=
   ```

1. Login to public ECR.
   Example:

   ```console
   aws ecr-public get-login-password --region us-east-1 \
     | docker login --username AWS --password-stdin public.ecr.aws/d5v4a2g3
   ```

1. Run utility program.
   Example:

   ```console
   cd ~/senzing.git/aws-cloudformation-ecs-poc-simple/utils
   ./migrate-images-from-docker-hub.sh
   ```

### Copy image to private ECR

1. :pencil2: Use credentials from _Docker_Registry_ > _AWSPowerUserAccess_.
   Example:

   ```console
   export AWS_ACCESS_KEY_ID=
   export AWS_SECRET_ACCESS_KEY=
   export AWS_SESSION_TOKEN=
   ```

1. Login to private ECR.
   Example:

   ```console
   aws ecr get-login-password --region us-east-1 \
     | docker login --username AWS --password-stdin 513176624027.dkr.ecr.us-east-1.amazonaws.com
   ```

1. Identify private ECR.
   Example:

   ```console
   export SENZING_PRIVATE_DOCKER_REGISTRY=513176624027.dkr.ecr.us-east-1.amazonaws.com
   ```

1. Run utility program.
   Example:

   ```console
   cd ~/senzing.git/aws-cloudformation-ecs-poc-simple/utils
   ./migrate-images-from-docker-hub.sh
   ```
