#!/usr/bin/env bash

# Enumerate docker images to be processed

DOCKER_IMAGE_NAMES=(
  "bitnami/kafka:2.8.0"
  "bitnami/rabbitmq:3.8.17"
  "bitnami/zookeeper:3.6.3"
  "coleifer/sqlite-web:latest"
  "ibmcom/db2:11.5.5.1"
  "mysql:5.7"
  "obsidiandynamics/kafdrop:3.27.0"
  "phpmyadmin/phpmyadmin:5.1.1"
  "postgres:11.12.0"
  "senzing/adminer:1.0.0"
  "senzing/apt:1.0.4"
  "senzing/db2-driver-installer:1.0.2"
  "senzing/entity-search-web-app:2.2.3"
  "senzing/init-container:1.6.9"
  "senzing/jupyter:1.3.0"
  "senzing/mysql-init:latest"
  "senzing/phppgadmin:1.0.0"
  "senzing/postgresql-client:1.0.0"
  "senzing/redoer:1.3.7"
  "senzing/resolver:1.3.2"
  "senzing/senzing-api-server:2.6.1"
  "senzing/senzing-console:1.0.1"
  "senzing/senzing-debug:1.3.5"
  "senzing/sshd:1.2.0"
  "senzing/stream-loader:1.7.6"
  "senzing/stream-logger:1.1.2"
  "senzing/stream-producer:1.4.1"
  "senzing/web-app-demo:2.1.1"
  "senzing/xterm:1.1.0"
  "senzing/yum:1.1.4"
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
