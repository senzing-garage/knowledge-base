#!/usr/bin/env bash

# Get stable docker version numbers.

curl -X GET \
    --output /tmp/docker-versions-stable.sh \
    https://raw.githubusercontent.com/Senzing/knowledge-base/main/lists/docker-versions-stable.sh
source /tmp/docker-versions-stable.sh

# Enumerate docker images to be processed.

DOCKER_IMAGE_NAMES=(
    "bitnami/kafka:${SENZING_DOCKER_IMAGE_VERSION_BITNAMI_KAFKA:-latest}"
    "bitnami/rabbitmq:${SENZING_DOCKER_IMAGE_VERSION_BITNAMI_RABBITMQ:-latest}"
    "bitnami/zookeeper:${SENZING_DOCKER_IMAGE_VERSION_BITNAMI_ZOOKEEPER:-latest}"
    "coleifer/sqlite-web:${SENZING_DOCKER_IMAGE_VERSION_SQLITE_WEB:-latest}"
    "confluentinc/cp-kafka:${SENZING_DOCKER_IMAGE_VERSION_CONFLUENTINC_CP_KAFKA:-latest}"
    "dpage/pgadmin4:${SENZING_DOCKER_IMAGE_VERSION_DPAGE_PGADMIN4:-latest}"
    "obsidiandynamics/kafdrop:${SENZING_DOCKER_IMAGE_VERSION_OBSIDIANDYNAMICS_KAFDROP:-latest}"
    "senzing/adminer:${SENZING_DOCKER_IMAGE_VERSION_ADMINER:-latest}"
    "senzing/apt:${SENZING_DOCKER_IMAGE_VERSION_APT:-latest}"
    "senzing/configurator:${SENZING_DOCKER_IMAGE_VERSION_CONFIGURATOR:-latest}"
    "senzing/data-encryption-aes256cbc-sample:${SENZING_DOCKER_IMAGE_VERSION_DATA_ENCRYPTION_AES256CBC_SAMPLE:-latest}"
    "senzing/db2-driver-installer:${SENZING_DOCKER_IMAGE_VERSION_DB2_DRIVER_INSTALLER:-latest}"
    "senzing/entity-search-web-app-console:${SENZING_DOCKER_IMAGE_VERSION_ENTITY_SEARCH_WEB_APP_CONSOLE:-latest}"
    "senzing/entity-search-web-app:${SENZING_DOCKER_IMAGE_VERSION_ENTITY_SEARCH_WEB_APP:-latest}"
    "senzing/file-loader:${SENZING_DOCKER_IMAGE_VERSION_FILE_LOADER:-latest}"
    "senzing/ibm-db2:${SENZING_DOCKER_IMAGE_VERSION_IBM_DB2:-latest}"
    "senzing/init-container:${SENZING_DOCKER_IMAGE_VERSION_INIT_CONTAINER:-latest}"
    "senzing/init-postgresql:${SENZING_DOCKER_IMAGE_VERSION_INIT_POSTGRESQL:-latest}"
    "senzing/postgresql-client:${SENZING_DOCKER_IMAGE_VERSION_POSTGRESQL_CLIENT:-latest}"
    "senzing/redoer:${SENZING_DOCKER_IMAGE_VERSION_REDOER:-latest}"
    "senzing/resolver:${SENZING_DOCKER_IMAGE_VERSION_RESOLVER:-latest}"
    "senzing/senzing-api-server:${SENZING_DOCKER_IMAGE_VERSION_SENZING_API_SERVER:-latest}"
    "senzing/senzing-base:${SENZING_DOCKER_IMAGE_VERSION_SENZING_BASE:-latest}"
    "senzing/senzing-console-slim:${SENZING_DOCKER_IMAGE_VERSION_SENZING_CONSOLE_SLIM:-latest}"
    "senzing/senzing-console:${SENZING_DOCKER_IMAGE_VERSION_SENZING_CONSOLE:-latest}"
    "senzing/senzing-poc-server:${SENZING_DOCKER_IMAGE_VERSION_SENZING_POC_SERVER:-latest}"
    "senzing/senzing-tools:${SENZING_DOCKER_IMAGE_VERSION_SENZING_TOOLS:-latest}"
    "senzing/senzingapi-runtime:${SENZING_DOCKER_IMAGE_VERSION_SENZINGAPI_RUNTIME:-latest}"
    "senzing/senzingapi-tools:${SENZING_DOCKER_IMAGE_VERSION_SENZINGAPI_TOOLS:-latest}"
    "senzing/sshd:${SENZING_DOCKER_IMAGE_VERSION_SSHD:-latest}"
    "senzing/stream-loader:${SENZING_DOCKER_IMAGE_VERSION_STREAM_LOADER:-latest}"
    "senzing/stream-logger:${SENZING_DOCKER_IMAGE_VERSION_STREAM_LOGGER:-latest}"
    "senzing/stream-producer:${SENZING_DOCKER_IMAGE_VERSION_STREAM_PRODUCER:-latest}"
    "senzing/web-app-demo:${SENZING_DOCKER_IMAGE_VERSION_WEB_APP_DEMO:-latest}"
    "senzing/xterm:${SENZING_DOCKER_IMAGE_VERSION_XTERM=:-latest}"
    "senzing/yum:${SENZING_DOCKER_IMAGE_VERSION_YUM:-latest}"
)

# Return codes.

OK=0
NOT_OK=1

# Pull images from DockerHub.

for DOCKER_IMAGE_NAME in ${DOCKER_IMAGE_NAMES[@]};
do
  echo "Pulling ${DOCKER_IMAGE_NAME} from DockerHub."
  docker pull ${DOCKER_IMAGE_NAME}
done

# Make output variables.

MY_HOME=~
OUTPUT_DATE=$(date +%s)
OUTPUT_FILE=${MY_HOME}/docker-air-gap-helper-${OUTPUT_DATE}.tgz
OUTPUT_DIR_NAME=docker-air-gap-helper-${OUTPUT_DATE}
OUTPUT_DIR=${MY_HOME}/${OUTPUT_DIR_NAME}
OUTPUT_LOAD_REPOSITORY_SCRIPT=${OUTPUT_DIR}/docker-air-gap-load-repository.sh
OUTPUT_LOAD_REGISTRY_SCRIPT=${OUTPUT_DIR}/docker-air-gap-load-registry.sh
mkdir ${OUTPUT_DIR}

# Write OUTPUT_LOAD_REPOSITORY_SCRIPT prolog.

cat <<EOT > ${OUTPUT_LOAD_REPOSITORY_SCRIPT}
#!/usr/bin/env bash

OK=0
NOT_OK=1

# pip3 install ./parse-1.15.0-py3-none-any.whl

EOT
chmod +x ${OUTPUT_LOAD_REPOSITORY_SCRIPT}

# Write OUTPUT_LOAD_REGISTRY_SCRIPT prolog.

cat <<EOT > ${OUTPUT_LOAD_REGISTRY_SCRIPT}
#!/usr/bin/env bash

OK=0
NOT_OK=1

if [[ -z "\${DOCKER_REGISTRY_URL}" ]]; then
  echo "Error: DOCKER_REGISTRY_URL is not set."
  exit \${NOT_OK}
fi

EOT
chmod +x ${OUTPUT_LOAD_REGISTRY_SCRIPT}


# docker save ${DOCKER_IMAGE_NAMES[@]} --output ${OUTPUT_FILE}
# exit ${OK}

# Save Docker images and scripts to output directory.

for DOCKER_IMAGE_NAME in ${DOCKER_IMAGE_NAMES[@]};
do

  # Do a "docker save" to make a file from docker image.

  DOCKER_OUTPUT_FILENAME=$(echo ${DOCKER_IMAGE_NAME} | tr "/:" "--")-${OUTPUT_DATE}.tar
  echo "Creating ${OUTPUT_DIR}/${DOCKER_OUTPUT_FILENAME}"
  docker save ${DOCKER_IMAGE_NAME} --output ${OUTPUT_DIR}/${DOCKER_OUTPUT_FILENAME}

  # Add commands to OUTPUT_LOAD_REPOSITORY_SCRIPT to load file into local repository.

  echo "docker load --input ${DOCKER_OUTPUT_FILENAME}" >> ${OUTPUT_LOAD_REPOSITORY_SCRIPT}

  # Add commands to OUTPUT_LOAD_REGISTRY_SCRIPT to push to private registry.

  echo "" >> ${OUTPUT_LOAD_REGISTRY_SCRIPT}
  echo "docker tag ${DOCKER_IMAGE_NAME} \${DOCKER_REGISTRY_URL}/${DOCKER_IMAGE_NAME}" >> ${OUTPUT_LOAD_REGISTRY_SCRIPT}
  echo "docker push \${DOCKER_REGISTRY_URL}/${DOCKER_IMAGE_NAME}" >> ${OUTPUT_LOAD_REGISTRY_SCRIPT}
  echo "docker rmi \${DOCKER_REGISTRY_URL}/${DOCKER_IMAGE_NAME}" >> ${OUTPUT_LOAD_REGISTRY_SCRIPT}

done

# Save individual files to output directory.

curl -X GET \
  --output ${OUTPUT_DIR}/senzing-environment.py \
  https://raw.githubusercontent.com/Senzing/senzing-environment/main/senzing-environment.py
chmod +x ${OUTPUT_DIR}/senzing-environment.py

curl -X GET \
  --output ${OUTPUT_DIR}/parse-1.15.0-py3-none-any.whl \
  https://raw.githubusercontent.com/Senzing/knowledge-base/main/gists/air-gap-senzing-environment/parse-1.15.0-py3-none-any.whl

# Compress results.

tar -zcvf ${OUTPUT_FILE} --directory ${MY_HOME} ${OUTPUT_DIR_NAME}

# Epilog

echo "Done."
echo "    Output file: ${OUTPUT_FILE}"
echo "    Which is a compressed version of ${OUTPUT_DIR}"

exit ${OK}
