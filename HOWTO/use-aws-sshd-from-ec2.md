
# How to use the SSHD service when a public IP has not been created.

1. From AWS account that has SSHD service deployed
1. Goto EC2 in management console
1. Instances new -> launch instances
1. Select Ubuntu 20.04 LTS (free tier)
    - Select appropriate VPC and subnet
    - Enable auto assign public IP
    - Select appropriate security group.
    - Select a key pair to use (or create one)
    - Review and launch with everything else as default

1. If a key pair has been created
    - Download and chmod to 600

1. Get the public ip from the amazon console

1. Log into the EC2 ubuntu machine: (use the correct pem file and ip address)

    ```
    ssh -i ~/senzing.git/[pem file name].pem ubuntu@[public ip]
    ```

1. From the SSHD task that is running, collect the private IP address
1. Collect the root password for the SSHD task.

    ```
    export SENZING_SSHD_HOST=[Private IP address for SSHD task]
    export SENZING_SSHD_USERNAME=root
    export SENZING_SSHD_PASSWORD=[root password for SSHD task]

    ssh ${SENZING_SSHD_USERNAME}@${SENZING_SSHD_HOST}
    ```

1. This should open a cmdline prompt in the SSHD container where the G2 tools and psql can be used.

