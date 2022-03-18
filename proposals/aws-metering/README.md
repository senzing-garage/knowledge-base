# AWS Metering

## Assumptions

1. Senzing license is stored in the database.
1. The G2Engine looks for the license in the database,
   not as a file on individual filesystems.

## Process

1. Every "period" (say 24 hours), an AWS lambda function
   performs the following:
    1. The lambda function reports to AWS the number
       of records in DSRC_RECORD.
    1. The lambda requests a new unlimited license
       with a lifespan of 2 periods
       (e.g. 48 hours) and inserted into the database.
       If the customer is current on payment,
       the new license is created for the request.
       If the customer is not current on payment,
       no new license is returned to the request.
1. If the customer "kills" the lambda function,
   the license will expire in 2 periods.
   So it's in the customer's interest to keep the lambda function running.
1. The trick will be the secure request from the lambda function
   to the "license generator".
1. The license generator needs to receive the identity of the
   customer.  It then checks with AWS to see if the customer is
   "in good standing".   If the customer is in good standing,
   a new "2-period" unlimited license is returned to the request.

## Billing

1. The billing is based on the number of records actually stored,
   not the "size" of the license.
   This will be reported to AWS every 24 hours.
   The price calculations will be done at the "AWS Marketplace"
   level, not the level of operational code.

## Holes in the architecture

1. A customer could copy the "unlimited, two-day license" from one system to another.


