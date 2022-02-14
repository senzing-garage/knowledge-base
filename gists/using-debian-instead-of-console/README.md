# using-debian-instead-of-console

The following instructions show how to use a `debian:11-slim` docker container
instead of the `senzing/console` container.

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


## Copy

1. XXX
   Example:


    ```console
    main:

      args:
        - cp
        - -r
        - /opt/local-senzing/.
        - /opt/senzing

      containerSecurityContext:
        enabled: true
        privileged: true
        runAsGroup: 0
        runAsUser: 0

      image:
        registry: ${DOCKER_REGISTRY_URL}
        tag: ${SENZING_VERSION_SENZINGAPI}

      senzing:
        persistentVolumeClaim: senzing-persistent-volume-claim


    ```

 ### init-container

 1. Update the database
    Example:

     ```console
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
