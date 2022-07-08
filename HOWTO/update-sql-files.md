# How to update sql files

## Synopsis

Periodically the following files need to be updated:

1. [g2core-schema-postgresql-create.sql](https://github.com/Senzing/postgresql-client/blob/main/rootfs/opt/senzing/g2/resources/schema/g2core-schema-postgresql-create.sql)
1. [insert-senzing-configuration.sql](https://github.com/Senzing/postgresql-client/blob/main/rootfs/app/insert-senzing-configuration.sql)

## Procedure

### Create docker-compose stack

1. Create docker-compose stack.
    1. Use [HOWTO/test-with-latest.md](https://github.com/Senzing/knowledge-base/blob/main/HOWTO/test-with-latest.md).

### Compare g2core-schema-postgresql-create.sql

1. Compare `g2core-schema-postgresql-create.sql` files.
   Example:

    ```console
    curl -X GET \
        --output /tmp/senzing-versions-latest.sh \
        https://raw.githubusercontent.com/Senzing/knowledge-base/main/lists/senzing-versions-latest.sh
    source /tmp/senzing-versions-latest.sh
    export SENZING_VOLUME=~/senzing-${SENZING_VERSION_SENZINGAPI}

    export SOURCE_FILE=${SENZING_VOLUME}/g2/resources/schema/g2core-schema-postgresql-create.sql
    export TARGET_FILE=~/senzing.git/postgresql-client/rootfs/opt/senzing/g2/resources/schema/g2core-schema-postgresql-create.sql
    diff ${SOURCE_FILE} ${TARGET_FILE}
    ```

### Compare insert-senzing-configuration.sql

1. Using pgAdmin from the docker-compose stack:
    1. Select: Servers > senzing > Databases > G2 > Schemas > public > Tables > sys_cfg
    1. Right-click > Backup...
    1. General
        1. Filename: sys_cfg.sql
        1. Format: Plain
    1. Data/Objects
        1. Only data: On
        1. Blobs: Off
    1. Options
        1. Use Column Inserts: On
        1. Use Insert Commands: On
    1. Click "Backup" button

1. Using `diff`.   Not really effective, though.
   Example:

    ```console
    export SOURCE_FILE=${SENZING_VOLUME}/var/pgadmin/postgres_postgres.com/sys_cfg.sql
    export TARGET_FILE=~/senzing.git/postgresql-client/rootfs/app/insert-senzing-configuration.sql
    diff ${SOURCE_FILE} ${TARGET_FILE}
    ```

1. A better strategy is to compare the JSON by "beautifying" it via
    [jsonlint.com](https://jsonlint.com/) or `jq`.
    Then compare the "before" and "after" using a file comparison tool.

1. If there is a difference in `sys_cfg.config_data`, then the `sys_vars` will also have to be checked.
