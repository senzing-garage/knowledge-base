# What is libmysqlclient21

## Install

Manual instructions for installing `libmysqlclient21` which is the database driver for MySQL.

This is done automatically by
[docker-init-container](https://github.com/senzing-garage/docker-init-container).
In particular the `database_initialization_mysql(...)` function of
[init-container.py](https://github.com/senzing-garage/docker-init-container/blob/main/init-container.py)

### CentOS

1. :pencil2: Identify a temporary work space.
   Example:

    ```console
    export TMP_DIR=/tmp/install-libmysqlclient
    ```

1. Create the temporary work space directory.
   Example:

    ```console
    mkdir -p ${TMP_DIR}
    ```

1. Get the `*.rpm` file.
   Example:

    ```console
    curl \
        --output ${TMP_DIR}/mysql-community-libs-8.0.21-1.el7.x86_64.rpm \
        https://repo.mysql.com/yum/mysql-8.0-community/el/7/x86_64/mysql-community-libs-8.0.21-1.el7.x86_64.rpm
    ```

1. Extract files from the RPM file.
   Example:

    ```console
    cd ${TMP_DIR}
    rpm2cpio ${TMP_DIR}/mysql-community-libs-8.0.21-1.el7.x86_64.rpm | cpio -idmv
    ```

1. Move file to `/opt/senzing/g2/lib`.
   Example:

    ```console
    mkdir -p /opt/senzing/g2/lib

    mv ${TMP_DIR}/usr/lib64/mysql/libmysqlclient.so.21.1.21 /opt/senzing/g2/lib/libmysqlclient.so.21.1.21
    chmod 755 /opt/senzing/g2/lib/libmysqlclient.so.21.1.21
    ```

1. Make a soft link.
   Example:

    ```console
    cd /opt/senzing/g2/lib
    ln -s libmysqlclient.so.21.1.21 libmysqlclient.so.21
    ```

1. ${TMP_DIR} can now be safely removed.

1. References:
    1. [Libmysqlclient.so.21 Download for Linux](https://pkgs.org/download/libmysqlclient.so.21)

### Ubuntu

1. Get the `*.deb` file.
   Example:

    ```console
    wget http://repo.mysql.com/apt/debian/pool/mysql-8.0/m/mysql-community/libmysqlclient21_8.0.20-1debian10_amd64.deb
    ```

1. :thinking: If needed, create directories.
   Example:

    ```console
    mkdir -p /opt/senzing/g2/lib
    ```

1. Extract `libmysqlclient.so.21.1.20` from **deb** file.
   Example:

    ```console
    dpkg --fsys-tarfile libmysqlclient21_8.0.20-1debian10_amd64.deb | tar xOf - ./usr/lib/x86_64-linux-gnu/libmysqlclient.so.21.1.20  > /opt/senzing/g2/lib/libmysqlclient.so.21.1.20
    ```

1. Change file permissions.
   Example:

    ```console
    chmod 755 /opt/senzing/g2/lib/libmysqlclient.so.21.1.20
    ```

1. Make `libmysqlclient.so.21` soft link.
   Example:

    ```console
    cd /opt/senzing/g2/lib
    ln -s libmysqlclient.so.21.1.20 libmysqlclient.so.21
    ```

1. References:

### macOS

### Windows

## Test

## Troubleshooting

## References
