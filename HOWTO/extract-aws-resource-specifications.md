# How to extract AWS resource specifications

[Former2](https://github.com/iann0036/former2) creates templates
from existing AWS resources.
It can be used to reverse engineer an AWS Cloudformation.

Although Former2 can also be run on the internet at
[former2.com](https://former2.com/),
you may want to run it locally.

## Running Former2 locally

1. Clone repository.
   Example:

    ```console
    mkdir ~/misc.git
    cd ~/misc.git
    git clone https://github.com/iann0036/former2.git
    ```

1. Run docker-compose formation.
   Example:

    ```console
    cd ~/misc.git/former2
    docker-compose up
    ```

1. Former2 can be viewed at
   [localhost](http://localhost)

## Extracting

At this point, access
[former2.com](https://former2.com/) on the internet
or locally at
[localhost](http://localhost).

1. In upper-right, select the appropriate AWS region.
1. In left-hand navigation, expand **Setup**
    1. Under **Setup**, select **Introduction**
        1. Add the browser helper for the specific browser.
    1. Under **Setup**, select **Credentials**
        1. Enter your AWS credentials
        1. If successful, **Logged in as:** will show your account.
    1. Under **Setup**, select **Settings**
        1. Turn **Enable Related Resources** on.
        1. Other changes are optional.
1. In upper-right, click green **Scan Account** button.
    1. There may be some errors for access errors.
       In general, they may be ignored.
1. Select Resources to extract.
    1. In left-hand navigation, select **Dashboard**
        1. Choose AWS resources to extract.
    1. In left-hand navigation, select **Search**
        1. Search for AWS resources to extract.
        1. Example: "taskdefinition"
1. In upper-left, click blue **Generate** button.
    1. The result will be a CloudFormation template with the selected AWS resource specifications.
    1. The contents can be copied and pasted into a text file to be shared.
