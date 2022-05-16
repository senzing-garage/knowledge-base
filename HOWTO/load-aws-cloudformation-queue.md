# How to load AWS Cloudformation queue

## Overview

Instructions for deploying
[AWS Cloudformation ECS POC simple](https://github.com/Senzing/aws-cloudformation-ecs-poc-simple)
and loading the SQS queue from a local workstation.

### Contents

1. [Launch Cloudformation template](#launch-cloudformation-template)
1. [Load SQS](#load-sqs)
    1. [Load SQS from Linux or macOS](#load-sqs-from-linux-or-macos)
    1. [Load SQS from Windows](#load-sqs-from-windows)
1. [Manual Cloudformation template Launch](#manual-cloudformation-template-launch)

## Launch Cloudformation template

1. Launch Cloudformation template.
    1. Visit [AWS Cloudformation with Senzing template](https://console.aws.amazon.com/cloudformation/home#/stacks/new?stackName=senzing-poc&templateURL=https://s3.amazonaws.com/public-read-access/aws-cloudformation-ecs-poc-simple/cloudformation.yaml)
        1. In lower-right, click on "Next" button.
        1. If access error,
           see [Manual Cloudformation template Launch](#manual-cloudformation-template-launch)
           to load Cloudformation template.
           Then proceed to next step.
    1. In **Specify stack details**
        1. In **Stack name**
            1. Stack name: senzing-poc
        1. In **Parameters**
            1. In **Acknowledge insecure system**
                1. Read, understand, and agree to the nature of the security in the deployment.
            1. In **Senzing installation**
                1. Accept the End User Licence Agreement
        1. In **Options**
            1. For "Optional: Would you like to have sample data imported?", select "No".
        1. Other parameters are optional.
        1. In lower-right, click "Next" button.
    1. In **Configure stack options**
        1. In lower-right, click "Next" button.
    1. In **Review senzing-poc**
        1. Near the bottom, in **Capabilities**
            1. Check ":ballot_box_with_check: I acknowledge that AWS CloudFormation might create IAM resources."
        1. In lower-right, click "Create stack" button.
    1. Visit [AWS CloudFormation console](https://console.aws.amazon.com/cloudformation/home).
        1. Make sure correct AWS region is selected.
    1. Wait until "senzing-poc" status is `CREATE_COMPLETE`.
        1. Senzing formation takes about 15 minutes to fully deploy.
        1. May have to hit the refresh button a few times to get updated information.

1. Add data sources to Senzing configuration.
    1. In the Cloudformation "Outputs" tab, launch the **UrlXterm** URL.
    1. :pencil2: In the Xterm, run `G2ConfigTool.py` to add data sources.
       Example:

        ```console
        $ G2ConfigTool.py

        (g2cfg) addDataSource MY_DATA_SOURCE
        (g2cfg) addEntityType MY_ENTITY_TYPE
        (g2cfg) save
        ```

1. The next steps are done from your local workstation.
   Depending on your workstation operating system, visit:
    1. [Load SQS from Docker](#load-sqs-from-docker)
    1. [Load SQS from Linux or macOS](#load-sqs-from-linux-or-macos)
    1. [Load SQS from Windows](#load-sqs-from-windows)

## Load SQS

### Load SQS from Docker

1. Get latest docker image.
   Example:

    ```console
    docker pull senzing/stream-producer:latest
    ```

1. :pencil2: Set AWS variables.
   Example:

    ```console
    export AWS_ACCESS_KEY_ID=AAAAAAAAAAAAAAAAAAAA
    export AWS_SECRET_ACCESS_KEY=aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
    export AWS_DEFAULT_REGION=us-xxxx-1
    ```

1. :pencil2: Identify file to be loaded into Senzing.
   Example:

    ```console
    export SENZING_INPUT_FILE=/path/to/my/example.json
    ```

1. :pencil2: Set default `DATA_SOURCE` and `ENTITY_TYPE` values.
   Example:

    ```console
    export SENZING_DEFAULT_DATA_SOURCE=MY_DATA_SOURCE
    export SENZING_DEFAULT_ENTITY_TYPE=MY_ENTITY_TYPE
    ```

1. :pencil2: Set URL of [SQS queue](https://console.aws.amazon.com/sqs/v2/home)
   Example:

    ```console
    export SENZING_SQS_QUEUE_URL="https://sqs.us-xxxx-1.amazonaws.com/000000000000/senzing-poc-sqs-queue"
    ```

1. :pencil2: Set `stream-producer.py` subcommand.
   Example:

    ```console
    export SENZING_SUBCOMMAND=json-to-sqs
    ```

1. Run docker container.
   Example:

    ```console
    docker run \
      --env AWS_ACCESS_KEY_ID=${AWS_ACCESS_KEY_ID} \
      --env AWS_DEFAULT_REGION=${AWS_DEFAULT_REGION} \
      --env AWS_SECRET_ACCESS_KEY=${AWS_SECRET_ACCESS_KEY} \
      --env SENZING_DEFAULT_DATA_SOURCE=${SENZING_DEFAULT_DATA_SOURCE} \
      --env SENZING_DEFAULT_ENTITY_TYPE=${SENZING_DEFAULT_ENTITY_TYPE} \
      --env SENZING_INPUT_URL="/data/${SENZING_INPUT_FILE##*/}" \
      --env SENZING_SQS_QUEUE_URL=${SENZING_SQS_QUEUE_URL} \
      --env SENZING_SUBCOMMAND=${SENZING_SUBCOMMAND} \
      --interactive \
      --rm \
      --tty \
      --volume ${SENZING_INPUT_FILE%\/*}:/data \
      senzing/stream-producer
    ```

### Load SQS from Linux or macOS

1. Install [stream-producer](https://github.com/Senzing/stream-producer).
    1. Install prerequisites.
       Example:

        ```console
        pip3 install -r https://raw.githubusercontent.com/Senzing/stream-producer/main/requirements.txt
        ```

    1. :pencil2: Specify location for `stream-producer.py`.
       Example:

        ```console
        export SENZING_DOWNLOAD_FILE=/tmp/stream-producer.py
        ```

    1. Download `stream-producer.py`.
       Example:

        ```console
        curl -X GET \
          --output ${SENZING_DOWNLOAD_FILE} \
          https://raw.githubusercontent.com/Senzing/stream-producer/main/stream-producer.py
        ```

1. Load SQS queue using
   [stream-producer](https://github.com/Senzing/stream-producer).

    1. :pencil2: Set AWS variables:
       Example:

        ```console
        export AWS_ACCESS_KEY_ID=AAAAAAAAAAAAAAAAAAAA
        export AWS_SECRET_ACCESS_KEY=aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
        export AWS_DEFAULT_REGION=us-xxxx-1
        ```

    1. :pencil2: Identify file to be loaded into Senzing.
       Example:

        ```console
        export SENZING_INPUT_URL=file:///path/to/my/example.json
        ```

    1. :pencil2: Set default `DATA_SOURCE` and `ENTITY_TYPE` values.
       Example:

        ```console
        export SENZING_DEFAULT_DATA_SOURCE=MY_DATA_SOURCE
        export SENZING_DEFAULT_ENTITY_TYPE=MY_ENTITY_TYPE
        ```

    1. :pencil2: Set URL of
       [SQS queue](https://console.aws.amazon.com/sqs/v2/home)
       Example:

        ```console
        export SENZING_SQS_QUEUE_URL="https://sqs.us-xxxx-1.amazonaws.com/000000000000/senzing-poc-sqs-queue"
        ```

    1. :pencil2: Set subcommand for
       [stream-producer.py](https://github.com/Senzing/stream-producer)
       Example:

        ```console
        export SENZING_SUBCOMMAND="json-to-sqs"
        ```

    1. Read file and send to SQS queue.
       Example:

        ```console
        python /tmp/stream-producer.py ${SENZING_SUBCOMMAND} \
            --default-data-source ${SENZING_DEFAULT_DATA_SOURCE} \
            --default-entity-type ${SENZING_DEFAULT_ENTITY_TYPE} \
            --input-url ${SENZING_INPUT_URL} \
            --sqs-queue-url ${SENZING_SQS_QUEUE_URL}
        ```

### Load SQS from Windows

1. Install [stream-producer](https://github.com/Senzing/stream-producer).
    1. Install prerequisites.
       Example:

        ```console
        pip install -r https://raw.githubusercontent.com/Senzing/stream-producer/main/requirements.txt
        ```

    1. :pencil2: Specify location for `stream-producer.py`.
       Example:

        ```console
        SET SENZING_DOWNLOAD_FILE=C:\tmp\stream-producer.py
        ```

    1. Download `stream-producer.py`.
       Example:

        ```console
        curl -X GET ^
          --output %SENZING_DOWNLOAD_FILE% ^
          https://raw.githubusercontent.com/Senzing/stream-producer/main/stream-producer.py
        ```

1. Load SQS queue using
   [stream-producer](https://github.com/Senzing/stream-producer).

    1. :pencil2: Set AWS variables:
       Example:

        ```console
        SET AWS_ACCESS_KEY_ID=AAAAAAAAAAAAAAAAAAAA
        SET AWS_SECRET_ACCESS_KEY=aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
        SET AWS_DEFAULT_REGION=us-xxxx-1
        ```

    1. :pencil2: Identify file to be loaded into Senzing.
       Example:

        ```console
        SET SENZING_INPUT_URL=C:\tmp\input-file.csv
        ```

    1. :pencil2: Set default `DATA_SOURCE` and `ENTITY_TYPE` values.
       Example:

        ```console
        SET SENZING_DEFAULT_DATA_SOURCE=MY_DATA_SOURCE
        SET SENZING_DEFAULT_ENTITY_TYPE=MY_ENTITY_TYPE
        ```

    1. :pencil2: Set URL of
       [SQS queue](https://console.aws.amazon.com/sqs/v2/home)
       Example:

        ```console
        SET SENZING_SQS_QUEUE_URL="https://sqs.us-xxxx-1.amazonaws.com/000000000000/senzing-poc-sqs-queue"
        ```

    1. :pencil2: Set subcommand for
       [stream-producer.py](https://github.com/Senzing/stream-producer)
       Example:

        ```console
        SET SENZING_SUBCOMMAND="json-to-sqs"
        ```

    1. Read file and send to SQS queue.
       Example:

        ```console
        python C:\tmp\stream-producer.py %SENZING_SUBCOMMAND% ^
            --default-data-source %SENZING_DEFAULT_DATA_SOURCE% ^
            --default-entity-type %SENZING_DEFAULT_ENTITY_TYPE% ^
            --input-url %SENZING_INPUT_URL% ^
            --sqs-queue-url %SENZING_SQS_QUEUE_URL%
        ```

## Manual Cloudformation template Launch

### Windows - Manual Cloudformation template launch

1. :pencil2: Identify the `cloudformation.yaml` to be downloaded.
   Example:

    ```console
    SET SENZING_CLOUDFORMATION_URL=https://raw.githubusercontent.com/Senzing/aws-cloudformation-ecs-poc-simple/main/cloudformation.yaml
    ```

1. :pencil2: Identify where `cloudformation.yaml` file will be downloaded.
   Example:

    ```console
    SET SENZING_DOWNLOAD_FILE=C:\tmp\cloudformation.yaml
    ```

1. Download `cloudformation.yaml`.
   Example:

    ```console
    curl -X GET --output %SENZING_DOWNLOAD_FILE% %SENZING_CLOUDFORMATION_URL%
    ```

1. Visit
   [AWS Cloudformation management console](https://console.aws.amazon.com/cloudformation/home)
1. Click "Create stack" drop-down > "With new resources (standard)".
1. In "Create stack":
    1. Click "Upload a template file" button.
    1. Click "Choose file" button and locate the file specified by `SENZING_DOWNLOAD_FILE`.
    1. Click "Next" button.
1. Return to instructions for **Specify stack details**.
