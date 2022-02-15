# using-debian-instead-of-console

The following instructions show how to use a `debian:11-slim` docker container
instead of the `senzing/console` container in the `senzing/console` Helm Chart.

## Obtain docker image

Load the `debian:11-slim` docker image into a private Docker registry.

1. :pencil2: Identify the source.
   Example:

    ```console
    export DOCKER_REPOSITORY=debian
    export DOCKER_TAG=11-slim
    ```

1. :pencil2: Identify the target.
   Example:

    ```console
    export DOCKER_REGISTRY_URL=my.docker-registry.com:5000
    ```

1. Pull from source registry, push to target registry.
   Example:

    ```console
    docker pull ${DOCKER_REPOSITORY}:${DOCKER_TAG}
    docker tag  ${DOCKER_REPOSITORY}:${DOCKER_TAG} ${DOCKER_REGISTRY_URL}/${DOCKER_REPOSITORY}:${DOCKER_TAG}
    docker push                               ${DOCKER_REGISTRY_URL}/${DOCKER_REPOSITORY}:${DOCKER_TAG}
    docker rmi                                ${DOCKER_REGISTRY_URL}/${DOCKER_REPOSITORY}:${DOCKER_TAG}
    ```

## senzing-debian.yaml

1. :pencil2: Create the following `.../helm-values/senzing-debian.yaml` file.
   Replace the `${...}` variables with actual values.
   Example:

    ```yaml
    main:

      containerSecurityContext:
        enabled: true
        privileged: true
        runAsGroup: 0
        runAsUser: 0

      image:
        registry: ${DOCKER_REGISTRY_URL}
        repository: ${DOCKER_REPOSITORY}
        tag: ${DOCKER_TAG}

      senzing:
        persistentVolumeClaim: senzing-persistent-volume-claim
    ```

## Helm install

1. Install chart using
   [helm install](https://helm.sh/docs/helm/helm_install/).
   Example:

    ```console
    helm install \
      ${DEMO_PREFIX}-senzing-debian \
      senzing/senzing-console \
      --namespace ${DEMO_NAMESPACE} \
      --values ${HELM_VALUES_DIR}/senzing-debian.yaml
    ```

## init-container update database only

Add `SENZING_SUBCOMMAND` so `senzing/init-container` docker container just updates the database.

1. `helm-values/senzing-init-container-postgresql-database.yaml`.
   Replace the `${...}` variables with actual values.
   Example:

    ```yaml
    main:

      containerSecurityContext:
        enabled: true
        privileged: true
        runAsGroup: 0
        runAsUser: 0

      extraEnvVars:
        - name: SENZING_SUBCOMMAND
          value: initialize-database

      image:
        registry: ${DOCKER_REGISTRY_URL}
        tag: ${SENZING_DOCKER_IMAGE_VERSION_INIT_CONTAINER}

      senzing:
        databaseUrl: "postgresql://postgres:postgres@${DEMO_PREFIX}-bitnami-postgresql:5432/G2"
        persistentVolumeClaim: senzing-persistent-volume-claim
    ```

## senzing-api-server with ingress

Deploy the `senzing/senzing-api-server` Helm Chart with an Ingress defined.
For more options, see `senzing/senzing-api-server`'s
[ingress:](https://github.com/Senzing/charts/blob/1d0b26c90858498c6e29c39ccf948c0959836f75/charts/senzing-api-server/values.yaml#L413-L510)

1. `helm-values/senzing-api-server-postgresql.yaml`.
   Replace the `${...}` variables with actual values.
   Example:

    ```yaml
    ingress:
        enabled: true

    main:

      autoscaling:
        enabled: true

      image:
        registry: ${DOCKER_REGISTRY_URL}
        tag: ${SENZING_DOCKER_IMAGE_VERSION_SENZING_API_SERVER}

      senzing:
        concurrency: 8
        engineConfigurationJson: >-
          {
            "PIPELINE": {
              "CONFIGPATH": "/etc/opt/senzing",
              "RESOURCEPATH": "/opt/senzing/g2/resources",
              "SUPPORTPATH": "/opt/senzing/data"
            },
            "SQL": {
              "BACKEND": "HYBRID",
              "CONNECTION": "postgresql://postgres:postgres@${DEMO_PREFIX}-bitnami-postgresql:5432:G2"
            }
          }
        persistentVolumeClaim: senzing-persistent-volume-claim
    ```

## entity-search-web-app with ingress

Deploy the `senzing/entity-search-web-app` Helm Chart with an Ingress defined.
For more options, see `senzing/entity-search-web-app`'s
[ingress:](https://github.com/Senzing/charts/blob/1d0b26c90858498c6e29c39ccf948c0959836f75/charts/senzing-entity-search-web-app/values.yaml#L386-L483)

1. `helm-values/senzing-entity-search-web-app.yaml`.
   Replace the `${...}` variables with actual values.
   Example:

    ```yaml
    ingress:
        enabled: true

    main:

      autoscaling:
        enabled: true

      image:
        registry: ${DOCKER_REGISTRY_URL}
        tag: ${SENZING_DOCKER_IMAGE_VERSION_ENTITY_SEARCH_WEB_APP}

      senzing:
        apiServerUrl: "http://${DEMO_PREFIX}-senzing-api-server"
    ```

## Secrets in stream-loader

1. `helm-values/senzing-stream-loader-kafka-postgresql.yaml`.
   Example:

    ```yaml
    main:

      args:
        - infinity

      autoscaling:
        enabled: false
        maxReplicas: 10
        minReplicas: 3
        targetCPU: 10
        targetMemory: 10

      command:
        - sleep

      extraVolumeMounts:
        - name: name-of-volume
          mountPath: "/etc/kafka-tls"
          readOnly: true

      extraVolumes:
        - name: name-of-volume
          secret:
            secretName: name-of-secret

      image:
        registry: ${DOCKER_REGISTRY_URL}
        tag: ${SENZING_DOCKER_IMAGE_VERSION_STREAM_LOADER}

      senzing:
        dataSource: TEST
        databaseUrl: "postgresql://postgres:postgres@${DEMO_PREFIX}-bitnami-postgresql:5432/G2"
        entityType: GENERIC
        kafkaBootstrapServerHost: "${DEMO_PREFIX}-bitnami-kafka"
        kafkaBootstrapServerPort: 9092
        kafkaTopic: senzing-kafka-topic
        logLevel: info
        monitoringPeriod: 60
        persistentVolumeClaim: senzing-persistent-volume-claim
        subcommand: kafka
        threadsPerProcess: 4
    ```
