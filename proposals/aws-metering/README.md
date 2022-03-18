# AWS Metering


## Assumptions

1. Senzing license is stored in the database.
1. The G2Engine looks for the license in the database,
   not as a file on individual filesystems.

## Process

1. Every "period" (say 24 hours), an AWS lambda function
   performs the following:
    1. Reports to AWS the number of records in DSRC_RECORD.
    1. If the customer is current on payment, a new
       unlimited license is generated with a lifespan of 2 periods
       (e.g. 48 hours) and inserted into the database.
    1. If the customer is not current on payment,
       no new license is generated.

## Billing

1. The billing is based on the number of records actually stored,
   not the "size" of the license.
   This will be reported to AWS every 24 hours.
   The price calculations will be done at the "AWS Marketplace"
   level, not the level of operational code.

## Holes in the architecture

1. A customer could copy the "unlimited, two-day license from one system to another.


