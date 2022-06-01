# HOWTO - Build Docker Senzing installer

Perform once per new Senzing version:

1. To use the Senzing code, you must agree to the End User License Agreement (EULA).

   :warning: This step is intentionally tricky and not simply copy/paste.
   This ensures that you make a conscious effort to accept the EULA.
   Example:

    <pre>export SENZING_ACCEPT_EULA="&lt;the value from <a href="https://github.com/Senzing/knowledge-base/blob/main/lists/environment-variables.md#senzing_accept_eula">this link</a>&gt;"</pre>

1. Build a Docker image which will be used to install Senzing.
   Example:

    ```console
    curl -X GET \
        --output /tmp/senzing-versions-latest.sh \
        https://raw.githubusercontent.com/Senzing/knowledge-base/main/lists/senzing-versions-latest.sh

    source /tmp/senzing-versions-latest.sh

    sudo docker build \
      --build-arg SENZING_ACCEPT_EULA=${SENZING_ACCEPT_EULA} \
      --build-arg SENZING_APT_INSTALL_PACKAGE=senzingapi=${SENZING_VERSION_SENZINGAPI_BUILD} \
      --build-arg SENZING_DATA_VERSION=${SENZING_VERSION_SENZINGDATA} \
      --no-cache \
      --tag senzing/installer:${SENZING_VERSION_SENZINGAPI} \
      https://github.com/senzing/docker-installer.git#main
    ```
