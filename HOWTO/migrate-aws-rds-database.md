# How to migrate an AWS RDS database

## Cloudformation

### Snapshot databases in old cloudformation

1. Visit [AWS RDS Console](https://console.aws.amazon.com/rds/home?#databases:).
1. Identify the 3 databases from the "old" cloudformation:
    1. ${OldStackName}-aurora-senzing-core-cluster
    1. ${OldStackName}-aurora-senzing-libfeat-cluster
    1. ${OldStackName}-aurora-senzing-res-cluster
1. For each database:
    1. In **DB identifier** column, select database.
    1. In "RDS > Databases > [database]" page, on upper-right, drop-down the "Actions" button, select "Take snapshot".
    1. In **Take DB snapshot**:
        1. **Snapshot name:** ${StackName}-aurora-senzing-XXXX-cluster
        1. In lower-right, click "Take snapshot" button

### Delete databases from new cloudformation

1. Visit [AWS RDS Console](https://console.aws.amazon.com/rds/home?#databases:).
1. Identify the 3 databases from the "new" cloudformation:
    1. ${NewStackName}-aurora-senzing-core-cluster
    1. ${NewStackName}-aurora-senzing-libfeat-cluster
    1. ${NewStackName}-aurora-senzing-res-cluster
1. For each database:
    1. In **DB identifier** column, select database.
    1. In "RDS > Databases > [database]" page, on upper-right, drop-down the "Actions" button, select "Delete".
    1. Create final snapshot?  Select ":large_blue_circle: No".
    1. Check ":ballot_box_with_check: I acknowledge that upon cluster deletion, automated backups, including system snapshots and point-in-time recovery, will no longer be available."
    1. Click "Delete DB Cluster" button.

### Create new databases

1. Visit [AWS RDS Console](https://console.aws.amazon.com/rds/home?#databases:).
1. Wait until databases from "new" cloudformation have been deleted.
1. On left-hand navigation bar, choose "Snapshots".
1. Identify the 3 shapshots from the "old" cloudformation:
    1. ${OldStackName}-aurora-senzing-core-cluster
    1. ${OldStackName}-aurora-senzing-libfeat-cluster
    1. ${OldtackName}-aurora-senzing-res-cluster
1. For each snapshot:
    1. Select the snapshot.
    1. Actions > Restore snapshot
    1. In **Restore snapshot**:
        1. In **Db specifications**:
            1. Engine: Amazon Aurora with PostgreSQL compatibility
            1. Capacity type: :large_blue_circle: Serverless
        1. In **Settings**:
            1. DB instance identifier: ${NewStackName}-aurora-senzing-XXXX,
               where XXXX is `core`, `libfeat`, or `res` to match snapshot name.
                1. :warning: Use the **New** stack name
                1. :warning: **TRICKY:** Truncate the "-cluster" from the original database name
                   because AWS adds a `-cluster` suffix.
        1. In **Connectivity**:
            1. Virtual private cloud (VPC): ${NewStackName}-ec2-vpc
            1. Subnet group: ${NewStackName}-db-subnet
            1. VPC security group:
                1. :large_blue_circle: Choose existing
                1. Existing VPC security groups
                    1. Choose ${NewStackName}-Ec2SecurityGroupInternal-XXXXXXXXXXX
                    1. Delete "default"
            1. Expand "Additional configuration"
                1. Check ":ballot_box_with_check: Data API"
        1. In **Capacity settings**:
            1. Expand "Additional scaling configuration"
                1. Check ":ballot_box_with_check: Force scaling the capacity to the specified values when the timeout is reachedI"
                1. :thinking: Optional: Check ":ballot_box_with_check: Pause compute capacity after consecutive minutes of inactivity"
        1. At bottom-right, click "Restore DB cluster" button

### Modify new databases

1. Visit [AWS RDS Console](https://console.aws.amazon.com/rds/home?#databases:)
1. Wait until databases from "new" cloudformation have been created.
1. Identify the 3 databases from the "new" cloudformation:
    1. ${NewStackName}-aurora-senzing-core-cluster
    1. ${NewStackName}-aurora-senzing-libfeat-cluster
    1. ${NewStackName}-aurora-senzing-res-cluster
1. For each database:
    1. In **DB identifier** column, select database.
    1. In "RDS > Databases > [database]" page, on upper-right, click "Modify" button.
    1. In **Modify DB cluster: ${NewStackName}-aurora-senzing-XXXX-cluster**
        1. In **Settings**
            1. New master password: [Enter value of *DatabasePassword* from cloudformation "Outputs" tab]
            1. Confirm password: [Enter value of *DatabasePassword* from cloudformation "Outputs" tab]
            1. :warning: Verify that the password has no leading or trailing spaces.
        1. At bottom-right, click "Continue" button
    1. In **Modify DB cluster: ${NewStackName}-aurora-senzing-XXXX-cluster**
        1. In **Scheduling of modifications**
            1. :thinking: :large_blue_circle: Apply immediately
        1. At bottom-right, click "Modify cluster" button



## Misc

1. In **Settings**
    1. DB cluster identifier:  ${StackName}-aurora-senzing-core-cluster
    1. New master password:  [senzing password
1. In **Capacity settings**
    1. Expand "Additional Scaling Configuration"
        1. Check ":ballot_box_with_check: Force scaling the capacity to the specified values when the timeout is reached"
1. In **Connectivity**
    1. VPC security group:  ${StackName}-Ec2SecurityGroupInternal-XXXXXXXXXXXX
1. In **Additional configuration**
    1. DB cluster parameter group: ${StackName}-rdsdbclusterparametergroup-xxxxxxxxxxxx


1. VPC: ${StackName}-ec2-vpc
1. Subnet group: ${StackName}-db-subnet
1. VPC security group: ${StackName}-Ec2SecurityGroupInternal-XXXXXXXXXXXX
1. Subnets:
    1. ${StackName}-ec2-subnet-private-1
    1. ${StackName}-ec2-subnet-private-2
