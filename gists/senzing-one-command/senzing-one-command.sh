#!/usr/bin/env bash

# Usage / help.

USAGE="Bring up Senzing web application.
Usage:
    $(basename "$0") project-dir
Where:
    project-dir = Path to new or existing Senzing project
"

# Parse positional input parameters.

SENZING_PROJECT_DIR=$1

# Verify input.

if [ -z ${SENZING_PROJECT_DIR} ]; then
    echo "${USAGE}"
    echo "ERROR: Missing project-dir."
    exit 1
fi

# Synthesize variables.

SENZING_PROJECT_DIR_REALPATH=$(realpath ${SENZING_PROJECT_DIR})

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
SENZING_DATA_DIR=${SENZING_PROJECT_DIR_REALPATH}/data
SENZING_ETC_DIR=${SENZING_PROJECT_DIR_REALPATH}/etc
SENZING_G2_DIR=${SENZING_PROJECT_DIR_REALPATH}/g2
SENZING_PROJECT_NAME=$(basename "${SENZING_PROJECT_DIR_REALPATH}")
SENZING_VAR_DIR=${SENZING_PROJECT_DIR_REALPATH}/var

# Give user information.

echo "Project location: ${SENZING_PROJECT_DIR_REALPATH}"
echo ""

# Debug

# echo "export SENZING_DATA_DIR=${SENZING_DATA_DIR}"
# echo "export SENZING_ETC_DIR=${SENZING_ETC_DIR}"
# echo "export SENZING_G2_DIR=${SENZING_G2_DIR}"
# echo "export SENZING_PROJECT_DIR_REALPATH=${SENZING_PROJECT_DIR_REALPATH}"
# echo "export SENZING_PROJECT_NAME=${SENZING_PROJECT_NAME}"
# echo "export SENZING_VAR_DIR=${SENZING_VAR_DIR}"

# Prompt user.

read -p "Would you like to install updates?  <y|N> " PERFORM_UPDATES

# If requested, perform updates.

if [ ! -z ${PERFORM_UPDATES} ] && [ ${PERFORM_UPDATES^} == "Y" ]; then
    docker pull senzing/yum:latest
    docker pull senzing/init-container:latest
    docker pull senzing/web-app-demo:latest
fi

# If the project directory doesn't exist, create it.

if [ ! -d ${SENZING_PROJECT_DIR} ]; then
    mkdir -p ${SENZING_PROJECT_DIR}
fi

# If new project or update requested, install/update Senzing.

if [[ ( ! -e ${SENZING_G2_DIR}/g2BuildVersion.json ) \
       || (( ! -z ${PERFORM_UPDATES} ) \
           && ( ${PERFORM_UPDATES^} == "Y" )) \
   ]]; then

    # If symbolic links exist, remove them.

    if [ -e ${SENZING_G2_DIR} ]; then
        rm ${SENZING_G2_DIR}
    fi

    if [ -e ${SENZING_DATA_DIR} ]; then
        rm ${SENZING_DATA_DIR}
    fi

    # Download Senzing binaries.

#    sudo docker run \
#      --interactive \
#      --name ${SENZING_PROJECT_NAME}-yum \
#      --rm \
#      --tty \
#      --volume ${SENZING_PROJECT_DIR_REALPATH}:/opt/senzing \
#      senzing/yum:latest

    sudo docker run \
      --env SENZING_ACCEPT_EULA=I_ACCEPT_THE_SENZING_EULA \
      --interactive \
      --name ${SENZING_PROJECT_NAME}-yum \
      --rm \
      --tty \
      --volume ${SENZING_PROJECT_DIR_REALPATH}:/opt/senzing \
      --volume ~/Downloads:/data \
      senzing/yum -y localinstall /data/senzingapi-1.15.0-20106.x86_64.rpm /data/senzingdata-v1-1.0.0-19287.x86_64.rpm

    sudo chown -R $(id -u):$(id -g) ${SENZING_PROJECT_DIR_REALPATH}

    # Create symbolic links to timestamped directories.

    TIMESTAMP=$(date +%s)

    pushd ${SENZING_PROJECT_DIR_REALPATH}
    mv g2 g2.${TIMESTAMP}
    ln -s g2.${TIMESTAMP} g2

    mv data data-backup
    mv data-backup/1.0.0 data.${TIMESTAMP}
    rmdir data-backup
    ln -s data.${TIMESTAMP} data
    popd > /dev/null 2>&1

fi

# FIXME: If needed, update database.

# FIXME: If needed, update Senzing configuration

# If needed, initialize etc and var directories.

if [ ! -e ${SENZING_ETC_DIR} ]; then

    sudo docker run \
      --name ${SENZING_PROJECT_NAME}-init-container \
      --rm \
      --user 0 \
      --volume ${SENZING_DATA_DIR}:/opt/senzing/data \
      --volume ${SENZING_ETC_DIR}:/etc/opt/senzing \
      --volume ${SENZING_G2_DIR}:/opt/senzing/g2 \
      --volume ${SENZING_VAR_DIR}:/var/opt/senzing \
      senzing/init-container:latest > /dev/null 2>&1

    sudo chown -R $(id -u):$(id -g) ${SENZING_PROJECT_DIR_REALPATH}

fi

# Run web-app

echo "${SENZING_PROJECT_NAME}-quickstart running on http://localhost:8251"

sudo docker run \
  --name ${SENZING_PROJECT_NAME}-quickstart \
  --publish 8251:8251 \
  --rm \
  --user $(id -u):$(id -g) \
  --volume ${SENZING_DATA_DIR}:/opt/senzing/data \
  --volume ${SENZING_ETC_DIR}:/etc/opt/senzing \
  --volume ${SENZING_G2_DIR}:/opt/senzing/g2 \
  --volume ${SENZING_VAR_DIR}:/var/opt/senzing \
  senzing/web-app-demo:latest > /dev/null 2>&1
