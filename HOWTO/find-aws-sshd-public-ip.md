# How to find the SSHD container's public ip address in AWS

## Open ECS

From the AWS management console search for "ECS" in the search box at the top of the page.

![Open ECS](find-aws-sshd-public-ip/openECS.png "Open ECS")

## Select the Cluster

Select the appropriate cluster in the list of clusters by click it's name.

![Open cluster](find-aws-sshd-public-ip/openCluster.png "Open cluster")

## Selected the 'sshd' service

From the list of services, click the sshd service name.

![Open sshd service](find-aws-sshd-public-ip/openSshd.png "Open sshd service")

## Select the tasks tab

On the sshd service page select the tasks tab

![Open tasks tab](find-aws-sshd-public-ip/taskTab.png "Open tasks tab")

## Select the task id

On the tasks tab click the task id link, left hand column.

![Open task id link](find-aws-sshd-public-ip/taskIDLink.png "Open task id link")

## Find the public ip

On the task page, the public IP can be found in the network section

![Find task id](find-aws-sshd-public-ip/publicIP.png "Find task id")

