# What is Oracle Instant client

> Free, light-weight, and easily installed Oracle Database tools, libraries and SDKs.
> -- _[Oracle Instant Client site]_

## Downloads

- [Downloads]

## Install

### Install on Ubuntu

The following is based on [Installing ODPI-C].

1. Download file.
   Example:

   ```console
   curl -X GET \
       --output /tmp/instantclient-basic-linux.zip \
       https://download.oracle.com/otn_software/linux/instantclient/2350000/instantclient-basic-linux.x64-23.5.0.24.07.zip

   ```

1. Make directories.
   Example:

   ```console
   sudo mkdir -p /opt/oracle

   ```

1. Extract Zip file.
   Example:

   ```console
   sudo unzip -d /opt/oracle /tmp/instantclient-basic-linux.zip

   ```

1. Make sure `libaio1` is installed.
   Example:

   ```console
   sudo apt-get install libaio1

   ```

1. :thinking: Update `LD_LIBRARY_PATH` to include the Oracle shared objects.
   Example:

   ```console
   export LD_LIBRARY_PATH=/opt/oracle/instantclient_21_5:$LD_LIBRARY_PATH

   ```

## References

- [Install Ubuntu Oracle Instant Client on Ubuntu]
- [Oracle Database Free Get Started]

[Downloads]: https://www.oracle.com/database/technologies/instant-client/downloads.html
[Install Ubuntu Oracle Instant Client on Ubuntu]: https://help.ubuntu.com/community/Oracle%20Instant%20Client
[Installing ODPI-C]: https://odpi-c.readthedocs.io/en/latest/user_guide/installation.html#linux
[Oracle Database Free Get Started]: https://www.oracle.com/database/free/get-started/
[Oracle Instant Client site]: https://www.oracle.com/database/technologies/instant-client.html
