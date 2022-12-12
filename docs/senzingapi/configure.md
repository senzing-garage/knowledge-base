# Configure SenzingAPI

Once the Senzing API is
[installed](./install),
it needs to be configured for use by a client.

## SenzingAPI system configuration

### Move data directory

1. Move the "versioned" Senzing data to the system location.
   Example:

    ```console
      sudo mv /opt/senzing/data/3.0.0/* /opt/senzing/data/

    ```

### Client configuration

1. Create default system configuration for a client in `/et.
   Example:

    ```console
      sudo mkdir /etc/opt/senzing
      sudo cp /opt/senzing/g2/resources/templates/cfgVariant.json     /etc/opt/senzing
      sudo cp /opt/senzing/g2/resources/templates/customGn.txt        /etc/opt/senzing
      sudo cp /opt/senzing/g2/resources/templates/customOn.txt        /etc/opt/senzing
      sudo cp /opt/senzing/g2/resources/templates/customSn.txt        /etc/opt/senzing
      sudo cp /opt/senzing/g2/resources/templates/defaultGNRCP.config /etc/opt/senzing
      sudo cp /opt/senzing/g2/resources/templates/stb.config          /etc/opt/senzing

    ```
