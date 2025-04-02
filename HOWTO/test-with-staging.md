# HOWTO - Test with staging

## Run stack

1. Bring up docker-compose stack.

   ```console
   export SENZING_VOLUME=~/senzing-staging
   export SENZING_VAR_DIR=${SENZING_VOLUME}/var
   export PGADMIN_DIR=${SENZING_VAR_DIR}/pgadmin
   export POSTGRES_DIR=${SENZING_VAR_DIR}/postgres
   export RABBITMQ_DIR=${SENZING_VAR_DIR}/rabbitmq
   rm -rf ${SENZING_VOLUME:-/tmp/nowhere}
   mkdir -p ${PGADMIN_DIR} ${POSTGRES_DIR} ${RABBITMQ_DIR}
   chmod -R 770 ${SENZING_VOLUME}
   chmod -R 777 ${PGADMIN_DIR} ${POSTGRES_DIR} ${RABBITMQ_DIR}
   curl -X GET \
       --output ${SENZING_VOLUME}/docker-compose.yaml \
       https://raw.githubusercontent.com/Senzing/docker-compose-demo/main/resources/postgresql/docker-compose-rabbitmq-postgresql.yaml
   curl -X GET \
       --output ${SENZING_VOLUME}/docker-versions-staging.sh \
       https://raw.githubusercontent.com/Senzing/knowledge-base/main/lists/docker-versions-staging.sh
   source ${SENZING_VOLUME}/docker-versions-staging.sh
   cd ${SENZING_VOLUME}
   sudo --preserve-env docker-compose pull
   sudo --preserve-env docker-compose up

   ```

1. Bring docker-compose stack down.

   ```console
   cd ${SENZING_VOLUME}
   sudo --preserve-env docker-compose down

   ```

1. To clean up everything, simply delete the ${SENZING_VOLUME} directory.
