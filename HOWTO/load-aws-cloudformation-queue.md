# How to load AWS Cloudformation queue

## Overview

Instructions for deploying
[AWS Cloudformation ECS POC simple](https://github.com/Senzing/aws-cloudformation-ecs-poc-simple)
and loading the SQS queue from a local workstation.

### Contents

1. [OS](#os)
    1. [Windows](#windows)

## OS

### Windows

1. :pencil2: Identify where `cloudformation.yaml` file will be downloaded.
   Example:

    ```console
    SET SENZING_DOWNLOAD_FILE=\tmp\cloudformation.yaml
    ```

1. Download `cloudformation.yaml`.
   Example:

    ```console
    curl -X GET ^
      --output %SENZING_DOWNLOAD_FILE% ^
      https://raw.githubusercontent.com/Senzing/aws-cloudformation-ecs-poc-simple/main/cloudformation.yaml
    ```

1. :pencil2: Modify `cloudformation.yaml`.
    Change Mappings.Constants.Run.StreamProducer value to "No"
    Example:

     ```yaml
    Mappings:
      :
      Constants:
        :
        Run:
          :
          StreamProducer: No
     ```

1. Deploy `cloudformation.yaml`
    1. Visit
       [AWS Cloudformation management console](https://console.aws.amazon.com/cloudformation/home)
    1. Click "Create stack" drop-down > "With new resources (standard)".
    1. in "Create stack":
        1. Click "Upload a template file" button.
        1. Click "Choose file" button and locate the file specified by `SENZING_DOWNLOAD_FILE`.
        1. Click "Next" button.
    1. In "Specify stack details":
        1. Enter **Stack name**.
        1. Enter **Parameters**.
        1. Click "Next" button.
    1. In "Configure stack options":
        1. Click "Next" button.
    1. In "Review [stack-name]":
        1. Check "I acknowledge that AWS CloudFormation might create IAM resources".
        1. Click "Create stack" button.

1. Add data sources to Senzing configuration.
    1. In the Cloudformation "Outputs" tab, launch the **UrlXterm** URL.
    1. :pencil2: In the Xterm, run `G2ConfigTool.py` to add data sources.
       Example:

        ```console
        $ G2Command.py

        (g2cfg) addDataSource MY_FIRST_DATASOURCE_NAME
        (g2cfg) addDataSource MY_SECOND_DATASOURCE NAME
        (g2cfg) save
        ```

1. Install [stream-produer](https://github.com/Senzing/stream-producer).
    1. Install prerequisites.
       Example:

        ```console
        pip install -r https://raw.githubusercontent.com/Senzing/stream-producer/master/requirements.txt
        ```

    1. :pencil2: Specify location for `stream-producer.py`.
       Example:

        ```console
        SET SENZING_DOWNLOAD_FILE=\tmp\stream-producer.py
        ```

    1. Download `stream-producer.py`.
       Example:

        ```console
        curl -X GET ^
          --output %SENZING_DOWNLOAD_FILE% ^
          https://raw.githubusercontent.com/Senzing/stream-producer/master/stream-producer.py
        ```

1. Load SQS queue using
   [stream-produer](https://github.com/Senzing/stream-producer)

    1. :pencil2: Set AWS variables:
       Example:

        ```console
        SET AWS_ACCESS_KEY_ID=AAAAAAAAAAAAAAAAAAAA
        SET AWS_SECRET_ACCESS_KEY=aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
        SET AWS_DEFAULT_REGION=us-east-1
        ```

    1. :pencil2: Location of input file in CSV format.
       Example:

        ```console
        SET SENZING_INPUT_URL=\tmp\input-file.csv
        ```

    1. :pencil2: Set URL of
       [SQS queue](https://console.aws.amazon.com/sqs/v2/home)
       Example:

        ```console
        SET SENZING_SQS_QUEUE_URL="https://sqs.us-xxxx-1.amazonaws.com/000000000000/queue-name"
        ```

    1. :pencil2: Set subcommand for
       [stream-producer.py](https://github.com/Senzing/stream-producer)
       Example:

        ```console
        SET SENZING_SUBCOMMAND="csv-to-sqs"
        ```

    1. Read file and send to SQS queue.
       Example:

        ```console
        python stream-producer.py %SENZING_SUBCOMMAND% ^
            --input-url %SENZING_INPUT_URL% ^
            --sqs-queue-url %SENZING_SQS_QUEUE_URL%
        ```
