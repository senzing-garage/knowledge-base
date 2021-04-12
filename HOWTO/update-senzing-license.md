# How to update Senzing license

## AWS Cloudformation

When deploying a Senzing Cloudformation, the
[SenzingLicenseAsBase64](http://hub.senzing.com/aws-cloudformation-ecs-poc-simple/#senzinglicenseasbase64)
value is used to upload and create the initial license.
It is only used at deployment time.
If the license needs to be updated after deployment,
use the following method.

### Locate the local copy of the g2.lic file

**NOTE:** The `g2.lic` file is a binary file.  It is not a Base64 encoded file.

1. :pencil2: Identify the location of the `g2.lic` file on the local workstation.
   Example:

    ```console
    export SENZING_G2_LICENCE_FILE=/etc/opt/senzing/g2.lic
    ```

### Determine SSHD container host

1. In the
   [AWS Elastic Container Service console](https://console.aws.amazon.com/ecs/home?#/clusters),
   choose the cluster of interest.
1. In the cluster, choose the "Tasks" tab.
1. In the "Tasks" tab, choose the value in the "Task" column for the "Task Definition" containing "-task-definition-sshd:".
1. In the "Task" page, "Details" tab, "Network" section, use the value of **Public IP** or **Private IP**,
   depending on your configuration, for the next step.

1. :pencil2: Using the IP address, set the following environment variable:

    ```console
    export SENZING_SSHD_HOST=nn.nn.nn.nn
    ```

### Determine SSHD container user and password

1. In the
   [AWS CloudFormation console](https://console.aws.amazon.com/cloudformation/home)
   choose the stack of interest.
1. For the chosen Stack, select the "Outputs" tab.
1. The **SshPassword** and **SshUsername** values will be used.
1. :pencil2: Using the **SshUsername** value, set the following environment variables.
   Example:

    ```console
    export SENZING_SSHD_USER=root
    ```

### Copy g2.lic to AWS EFS

1. Copy the local `g2.lic` file to the Cloudformation's mounted Elastic File System via the sshd container.
   Example:

    ```console
    scp ${SENZING_G2_LICENCE_FILE} ${SENZING_SSHD_USER}@${SENZING_SSHD_HOST}:/etc/opt/senzing/g2.lic
    ```

1. When prompted for a password, use the value of **SshPassword** discovered in the prior section.

### Drain tasks using old license

1. In the
   [AWS Elastic Container Service console](https://console.aws.amazon.com/ecs/home?#/clusters),
   choose the cluster of interest.
1. In the cluster, choose the "Tasks" tab.
1. Stop all of the tasks containing the following in their "Tasks Definitions"
    1. `-task-definition-stream-loader:`
    1. `-task-definition-api-server:`
    1. `-task-definition-redoer:`
   The "service" will restart all of these tasks using the new license.
