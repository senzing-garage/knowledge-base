#!/usr/bin/env bash

# Enumerate docker images to be processed

DOCKER_IMAGE_NAMES=(
  "senzing/web-app-demo:latest"
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
OUTPUT_FILE=${MY_HOME}/air-gap-senzing-environment-${OUTPUT_DATE}.tgz
OUTPUT_DIR_NAME=air-gap-senzing-environment-${OUTPUT_DATE}
OUTPUT_DIR=${MY_HOME}/${OUTPUT_DIR_NAME}
OUTPUT_LOAD_REPOSITORY_SCRIPT=${OUTPUT_DIR}/air-gap-senzing-environment-load-repository.sh
OUTPUT_LOAD_REGISTRY_SCRIPT=${OUTPUT_DIR}/air-gap-senzing-environment-load-registry.sh
mkdir ${OUTPUT_DIR}

# Write OUTPUT_LOAD_REPOSITORY_SCRIPT prolog.

cat <<EOT > ${OUTPUT_LOAD_REPOSITORY_SCRIPT}
#!/usr/bin/env bash

OK=0
NOT_OK=1

pip3 install ./parse-1.15.0-py3-none-any.whl

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
