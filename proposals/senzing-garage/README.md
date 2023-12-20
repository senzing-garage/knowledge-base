# Proposal for migrating non-customer-oriented repositories

## Proposed result

| Repository | [Senzing](https://github.com/senzing) | [senzing-garage](https://github.com/senzing-garage) | [senzing-factory](https://github.com/senzing-factory) | Description | Notes |
|------------|:-------:|:----------------:|:---------------:|-------------|-------|
| [awesome](https://github.com/Senzing/awesome) | :white_check_mark: ||| Curated list of awesome software and resources for Senzing, The First Real-Time AI for Entity Resolution. | Needs to be massively updated|
| [aws-cloudformation-database-cluster](https://github.com/Senzing/aws-cloudformation-database-cluster) || :white_check_mark: || AWS Cloudformation with VPC and Senzing database cluster | |
| [aws-cloudformation-dev-rest](https://github.com/Senzing/aws-cloudformation-dev-rest) || :white_check_mark: || AWS Cloudformation for developers using Senzing HTTP REST API | |
| [aws-cloudformation-ecs-senzing-stack-basic](https://github.com/Senzing/aws-cloudformation-ecs-senzing-stack-basic) || :white_check_mark: || AWS Cloudformation demonstrating a Senzing stack that can be used with aws-cloudformation-database-cluster. | |
| [aws-cloudformation-ecs](https://github.com/Senzing/aws-cloudformation-ecs) || :white_check_mark: || :no_entry: [DEPRECATED] Contains deprecated AWS Cloudformation templates | |
| [aws-cloudformation-performance-testing](https://github.com/Senzing/aws-cloudformation-performance-testing) || :white_check_mark: || Senzing AWS performance testing project. | |
| [aws-cloudformation-webapp-demo](https://github.com/Senzing/aws-cloudformation-webapp-demo) || :white_check_mark: || Senzing WebApp demo for AWS. | |
| [aws-lambda-cognito-authorizer](https://github.com/Senzing/aws-lambda-cognito-authorizer) || :white_check_mark: || Lambda function for authorizing via AWS Cognito | |
| [aws-lambda-self-signed-certificate](https://github.com/Senzing/aws-lambda-self-signed-certificate) || :white_check_mark: || Creates a self-signed SSL certificate for AWS demonstrations. | |
| [aws-marketplace-evaluation](https://github.com/Senzing/aws-marketplace-evaluation) | :question: ||| AWS Marketplace offering. | Not sure about this. |
| [azure-template-aks-poc-simple](https://github.com/Senzing/azure-template-aks-poc-simple) || :white_check_mark: || An Azure ARM template for bringing up Senzing on Kubernetes (AKS) | |
| [bizname-research](https://github.com/Senzing/bizname-research) || :white_check_mark: || [Research] Determine language/country origin of business name | Current research |
| [build-resources](https://github.com/Senzing/build-resources) ||| :white_check_mark: | Collection of utilities to aid with build process | |
| [charts](https://github.com/Senzing/charts) || :white_check_mark: || Helm Charts for use with Kubernetes, OpenShift, and Rancher. | |
| [check-self](https://github.com/Senzing/check-self) || :white_check_mark: || Checks environment | |
| [code-snippets](https://github.com/Senzing/code-snippets) | :white_check_mark: ||| Task based code snippet examples. | |
| [community-map](https://github.com/Senzing/community-map) || :white_check_mark: || :construction: [Under construction] A visual representation of the Senzing Community. | |
| [community-roadmap](https://github.com/Senzing/community-roadmap) || :white_check_mark: || A peek into the future of the Senzing Community. | |
| [compressedfile](https://github.com/Senzing/compressedfile) | :white_check_mark: ||| Distributed with Senzing API package | |
| [configurator](https://github.com/Senzing/configurator) || :white_check_mark: || Web service for configuring Senzing. | |
| [connector-neo4j](https://github.com/Senzing/connector-neo4j) | :white_check_mark: ||| Transform Senzing data into Neo4j graph database. | |
| [data-encryption-aes256cbc-sample](https://github.com/Senzing/data-encryption-aes256cbc-sample) | :white_check_mark: ||| This is a sample encryption plugin, for use with the G2 engine to encrypt sensitive data in the data repository. | |
| [data-mart-replicator](https://github.com/Senzing/data-mart-replicator) | :white_check_mark: ||| :construction: Data mart | |
| [demo-entity-search](https://github.com/Senzing/demo-entity-search) || :white_check_mark: || A CLI tool for demonstrating entity searching | |
| [discussions](https://github.com/Senzing/discussions) | :white_check_mark: ||| Repository that supports GitHub Discussions. | |
| [docker-adminer](https://github.com/Senzing/docker-adminer) || :white_check_mark: || Dockerfile wrapping `adminer`, a database viewer. | |
| [docker-apt](https://github.com/Senzing/docker-apt) || :white_check_mark: || Dockerfile wrapping `apt-get`, a package manager. | |
| [docker-aptdownloader](https://github.com/Senzing/docker-aptdownloader) || :white_check_mark: || Dockerfile wrapping `apt-get install --download-only`. | |
| [docker-base-image-debian](https://github.com/Senzing/docker-base-image-debian) || :white_check_mark: || A base docker image for Senzing processes built on Debian. | |
| [docker-compose-air-gapper](https://github.com/Senzing/docker-compose-air-gapper) || :white_check_mark: || Create a TGZ bundle for air-gapped environments based on docker-compose.yaml | |
| [docker-compose-demo](https://github.com/Senzing/docker-compose-demo) || :white_check_mark: || Demonstrate Senzing stack using `docker-compose`. | |
| [docker-db2-driver-installer](https://github.com/Senzing/docker-db2-driver-installer) || :white_check_mark: || Install DB2 client drivers on mounted volumes. | |
| [docker-hello-world](https://github.com/Senzing/docker-hello-world) || :white_check_mark: || Dockerfile for testing docker formations. | |
| [docker-ibm-db2](https://github.com/Senzing/docker-ibm-db2) || :white_check_mark: || Dockerfile wrapping `ibmcom/db2` docker image. | |
| [docker-init-container](https://github.com/Senzing/docker-init-container) || :white_check_mark: || Dockerfile used to initialize Senzing artifacts. | |
| [docker-installer](https://github.com/Senzing/docker-installer) || :white_check_mark: || Dockerfile use to install Senzing in a non-root container. | |
| [docker-mysql-init](https://github.com/Senzing/docker-mysql-init) || :white_check_mark: || Dockerfile for initializing mysql database with a one-time command. | |
| [docker-python-demo](https://github.com/Senzing/docker-python-demo) || :white_check_mark: || Dockerfile demonstrating simple Flask app using Senzing. | |
| [docker-senzing-base](https://github.com/Senzing/docker-senzing-base) || :white_check_mark: || Dockerfile used in FROM statements. | |
| [docker-senzing-console](https://github.com/Senzing/docker-senzing-console) || :white_check_mark: || Docker-based console enabled for interacting with Senzing programs. | |
| [docker-sshd](https://github.com/Senzing/docker-sshd) || :white_check_mark: || Dockerfile wrapping `sshd`. | |
| [docker-terraform-aws](https://github.com/Senzing/docker-terraform-aws) || :white_check_mark: || :construction: [Under construction] | |
| [docker-test-layers](https://github.com/Senzing/docker-test-layers) || :white_check_mark: || A Repository for testing contents of Docker layers | |
| [docker-test](https://github.com/Senzing/docker-test) || :white_check_mark: || Used in Spikes. Not for production. | |
| [docker-web-app-demo](https://github.com/Senzing/docker-web-app-demo) | :white_check_mark: ||| Dockerfile combining Senzing API server and Senzing Entity WebApp. | |
| [docker-wrap-image-with-db2](https://github.com/Senzing/docker-wrap-image-with-db2) || :white_check_mark: || Wrap a Docker image with enablement for Db2 database | |
| [docker-wrap-image-with-mssql](https://github.com/Senzing/docker-wrap-image-with-mssql) || :white_check_mark: || Wrap a Docker image with enablement for MS SQL database | |
| [docker-wrap-image-with-mysql](https://github.com/Senzing/docker-wrap-image-with-mysql) || :white_check_mark: || Wrap a Docker image with enablement for MySQL database | |
| [docker-wrap-image-with-senzing-apt](https://github.com/Senzing/docker-wrap-image-with-senzing-apt) || :white_check_mark: || Wrap an existing docker image with the Senzing package. | |
| [docker-wrap-image-with-senzing-data](https://github.com/Senzing/docker-wrap-image-with-senzing-data) || :white_check_mark: || Add /opt/senzing/data to a base image. | |
| [docker-xterm](https://github.com/Senzing/docker-xterm) || :white_check_mark: || Web-based X-terminal. | |
| [docker-yum](https://github.com/Senzing/docker-yum) || :white_check_mark: || Dockerfile wrapping `yum`, a package manager. | |
| [dockerhub-util](https://github.com/Senzing/dockerhub-util) ||| :white_check_mark: | Utilities for working with hub.docker.com registry | |
| [dumpstack](https://github.com/Senzing/dumpstack) | :white_check_mark: ||| Distributed with Senzing API package | |
| [elasticsearch](https://github.com/Senzing/elasticsearch) | :white_check_mark: ||| Using G2 engine with ElasticSearch indexing engine. | |
| [entity-search-web-app-console](https://github.com/Senzing/entity-search-web-app-console) || :white_check_mark: || A side-car for the Entity Search Web App | |
| [entity-search-web-app](https://github.com/Senzing/entity-search-web-app) | :white_check_mark: ||| A lightweight http server providing a web UI for entity search through the senzing api server. | |
| [evaluate](https://github.com/Senzing/evaluate) || :white_check_mark: || Information for evaluating Senzing at <http://senzing.com/evaluate> | |
| [explain](https://github.com/Senzing/explain) || :white_check_mark: || A CLI tool for explaining errors | |
| [file-loader](https://github.com/Senzing/file-loader) || :white_check_mark: || Utility to load mapped JSON data and process redo records after loading. | |
| [g2-python](https://github.com/Senzing/g2-python) | :white_check_mark: ||| Tools found at g2/python in the SenzingAPI package. | May no longer be needed. |
| [g2-sdk-go-base](https://github.com/Senzing/g2-sdk-go-base) | :white_check_mark: ||| An SDK for calling the Senzing C library locally. | |
| [g2-sdk-go-grpc](https://github.com/Senzing/g2-sdk-go-grpc) | :white_check_mark: ||| An SDK for calling the Senzing C library via gRPC network requests. | |
| [g2-sdk-go-mock](https://github.com/Senzing/g2-sdk-go-mock) | :white_check_mark: ||| A mock object for the <https://github.com/Senzing/g2-sdk-go> interface. | |
| [g2-sdk-go](https://github.com/Senzing/g2-sdk-go) | :white_check_mark: ||| Senzing's Go Software Development Kit (SDK) | |
| [g2-sdk-java](https://github.com/Senzing/g2-sdk-java) | :white_check_mark: ||| Java SDK hosted on MvnRepository. | |
| [g2-sdk-json-type-definition](https://github.com/Senzing/g2-sdk-json-type-definition) || :white_check_mark: || [Spike] Codify JSON structure | |
| [g2-sdk-proto](https://github.com/Senzing/g2-sdk-proto) | :white_check_mark: ||| Proto files for the G2 Software Development Kit | |
| [g2-sdk-python-grpc](https://github.com/Senzing/g2-sdk-python-grpc) | :white_check_mark: ||| An SDK for calling the Senzing C library via gRPC network requests. | |
| [g2-sdk-python-next](https://github.com/Senzing/g2-sdk-python-next) | :white_check_mark: ||| [Development] Forthcoming major revision of Senzing Python SDK | |
| [g2-sdk-python](https://github.com/Senzing/g2-sdk-python) | :white_check_mark: ||| Senzing Python SDK V3 | |
| [g2anon](https://github.com/Senzing/g2anon) | :white_check_mark: ||| Python SDK for G2Anonymizer | |
| [g2audit](https://github.com/Senzing/g2audit) | :white_check_mark: ||| Distributed with Senzing API package | |
| [g2command](https://github.com/Senzing/g2command) | :white_check_mark: ||| Distributed with Senzing API package | |
| [g2configtables](https://github.com/Senzing/g2configtables) | :white_check_mark: ||| Distributed with Senzing API package | |
| [g2configtool](https://github.com/Senzing/g2configtool) | :white_check_mark: ||| Distributed with Senzing API package | |
| [g2createinstance](https://github.com/Senzing/g2createinstance) | :white_check_mark: ||| Create a per-user instance of Senzing in a new folder with the specified name. | |
| [g2createproject](https://github.com/Senzing/g2createproject) | :white_check_mark: ||| Distributed with Senzing API package | |
| [g2database](https://github.com/Senzing/g2database) | :white_check_mark: ||| Distributed with Senzing API package | |
| [g2explorer](https://github.com/Senzing/g2explorer) | :white_check_mark: ||| Distributed with Senzing API package | |
| [g2export](https://github.com/Senzing/g2export) | :white_check_mark: ||| Distributed with Senzing API package | |
| [g2iniparams](https://github.com/Senzing/g2iniparams) | :white_check_mark: ||| Distributed with Senzing API package | |
| [g2loader](https://github.com/Senzing/g2loader) | :white_check_mark: ||| Distributed with Senzing API package | |
| [g2module](https://github.com/Senzing/g2module) | :white_check_mark: ||| Python SDK for G2 | |
| [g2paths](https://github.com/Senzing/g2paths) | :white_check_mark: ||| Distributed with Senzing API package | |
| [g2project](https://github.com/Senzing/g2project) | :white_check_mark: ||| Distributed with Senzing API package | |
| [g2s3](https://github.com/Senzing/g2s3) | :white_check_mark: ||| Distributed with Senzing API package | |
| [g2search](https://github.com/Senzing/g2search) | :white_check_mark: ||| Reads formatted search records, calls Senzing, and outputs for analysis | |
| [g2setupconfig](https://github.com/Senzing/g2setupconfig) | :white_check_mark: ||| Distributed with Senzing API package | |
| [g2snapshot](https://github.com/Senzing/g2snapshot) | :white_check_mark: ||| Distributed with Senzing API package | |
| [g2updateproject](https://github.com/Senzing/g2updateproject) | :white_check_mark: ||| Distributed with Senzing API package | |
| [git-action-slack-notification](https://github.com/Senzing/git-action-slack-notification) ||| :white_check_mark: | GitHub Action for notifying Slack | |
| [github-action-add-issue-to-project](https://github.com/Senzing/github-action-add-issue-to-project) ||| :white_check_mark: | A GitHub Action for adding an issue to projects. | |
| [github-action-docker-buildx-build](https://github.com/Senzing/github-action-docker-buildx-build) ||| :white_check_mark: | GitHub Action for using Docker buildx command | |
| [github-action-identify-customer](https://github.com/Senzing/github-action-identify-customer) ||| :white_check_mark: | A GitAction for determining if a customer submitted the issue. | |
| [github-action-install-senzing-api](https://github.com/Senzing/github-action-install-senzing-api) ||| :white_check_mark: | GitHub Action for installing Senzing API | |
| [github-action-make-go-github-file](https://github.com/Senzing/github-action-make-go-github-file) ||| :white_check_mark: | Make a version.go file | |
| [github-action-make-go-tag](https://github.com/Senzing/github-action-make-go-tag) ||| :white_check_mark: | From the Semantic Version, create a v0.0.0 tag for the Go module version | |
| [github-util](https://github.com/Senzing/github-util) ||| :white_check_mark: | Works with GitHub metadata. | |
| [go-cmdhelping](https://github.com/Senzing/go-cmdhelping) || :white_check_mark: || Helpers for using cobra and viper | |
| [go-common](https://github.com/Senzing/go-common) || :white_check_mark: || Reusable, small components. | |
| [go-databasing](https://github.com/Senzing/go-databasing) || :white_check_mark: || Database routines | |
| [go-grpcing](https://github.com/Senzing/go-grpcing) || :white_check_mark: || Go package of gRPC helpers | |
| [go-logging](https://github.com/Senzing/go-logging) || :white_check_mark: || A reusable logging framework. | |
| [go-messaging](https://github.com/Senzing/go-messaging) || :white_check_mark: || Message creation | |
| [go-observing](https://github.com/Senzing/go-observing) || :white_check_mark: || Observer software design pattern | |
| [go-queueing](https://github.com/Senzing/go-queueing) || :white_check_mark: || Queue routines | |
| [go-rest-api-service](https://github.com/Senzing/go-rest-api-service) || :white_check_mark: || [in-progress] Go package implementation of API server | |
| [go-sdk-abstract-factory](https://github.com/Senzing/go-sdk-abstract-factory) || :white_check_mark: || An abstract factory for objects of the <https://github.com/Senzing/g2-sdk-go> interface. | |
| [governor-postgresql-transaction-id](https://github.com/Senzing/governor-postgresql-transaction-id) | :white_check_mark: ||| Governor plugin for PostgreSQL transaction IDs. | |
| [ibm-openshift-guide](https://github.com/Senzing/ibm-openshift-guide) || :white_check_mark: || Demonstrate Senzing stack using OpenShift and IBM Db2. | |
| [images](https://github.com/Senzing/images) | :white_check_mark: ||| Images used across repositories. | |
| [init-database](https://github.com/Senzing/init-database) || :white_check_mark: || Initialize database with Senzing schema and configuration | |
| [init-mssql](https://github.com/Senzing/init-mssql) || :white_check_mark: || Initialize an MS SQL database with Senzing schema and configuration | |
| [init-mysql](https://github.com/Senzing/init-mysql) || :white_check_mark: || Initialize a MySQL database with Senzing schema and configuration | |
| [init-postgresql](https://github.com/Senzing/init-postgresql) || :white_check_mark: || Initialize a PostgreSQL database with Senzing schema and configuration | |
| [keystore-generator](https://github.com/Senzing/keystore-generator) || :white_check_mark: || Generates SSL keys | |
| [knowledge-base](https://github.com/Senzing/knowledge-base) || :white_check_mark: || HOWTOs, tasks, explanations, and more knowledge. | |
| [kubernetes-demo](https://github.com/Senzing/kubernetes-demo) || :white_check_mark: || Demonstrate Senzing stack using Kubernetes. | |
| [libpostal-data](https://github.com/Senzing/libpostal-data) | :white_check_mark: ||| Information about libpostal work done by Senzing. | |
| [libpostal](https://github.com/Senzing/libpostal) | :white_check_mark: ||| A C library for parsing/normalizing street addresses around the world. Powered by statistical NLP and open geo data. | |
| [load](https://github.com/Senzing/load) || :white_check_mark: || A CLI tool for loading records | |
| [mapper-base](https://github.com/Senzing/mapper-base) | :white_check_mark: ||| Base functions used to map a variety of formats to a Senzing-acceptable format. | |
| [mapper-csv](https://github.com/Senzing/mapper-csv) | :white_check_mark: ||| Exemplar artifacts (files) that can be used in other Senzing repositories. | |
| [mapper-dnb](https://github.com/Senzing/mapper-dnb) | :white_check_mark: ||| Map DNB format to Senzing format. | |
| [mapper-dowjones](https://github.com/Senzing/mapper-dowjones) | :white_check_mark: ||| Map Dow Jones Watchlist format to Senzing format. | |
| [mapper-icij](https://github.com/Senzing/mapper-icij) | :white_check_mark: ||| Map ICIJ format to Senzing format. | |
| [mapper-leie](https://github.com/Senzing/mapper-leie) | :white_check_mark: ||| Map US HHS LEIE to Senzing format. | |
| [mapper-nomino](https://github.com/Senzing/mapper-nomino) | :white_check_mark: ||| Map Nomino format to Senzing format. | |
| [mapper-npi](https://github.com/Senzing/mapper-npi) | :white_check_mark: ||| Map NPPES NPI Registry to Senzing format. | |
| [mapper-ofac](https://github.com/Senzing/mapper-ofac) | :white_check_mark: ||| Map OFAC to Senzing format. | |
| [mapper-open-ownership](https://github.com/Senzing/mapper-open-ownership) | :white_check_mark: ||| Map Open Ownership Register into Senzing format | |
| [mapper-opensanctions](https://github.com/Senzing/mapper-opensanctions) | :white_check_mark: ||| Map Open Sanctions into Senzing format. | |
| [mapper-safegraph](https://github.com/Senzing/mapper-safegraph) | :white_check_mark: ||| Map SafeGraph format to Senzing format. | |
| [mapper-sayari-spark](https://github.com/Senzing/mapper-sayari-spark) | :white_check_mark: ||| Map Sayari's global corporate data into Senzing format using Spark. | |
| [mapper-sayari](https://github.com/Senzing/mapper-sayari) | :white_check_mark: ||| Map Sayari's global corporate data into Senzing format. | |
| [move](https://github.com/Senzing/move) || :white_check_mark: || A CLI tool for moving data | |
| [mssql-performance](https://github.com/Senzing/mssql-performance) | :white_check_mark: ||| Tips for working with Senzing on MS SQL | |
| [observe](https://github.com/Senzing/observe) || :white_check_mark: || A CLI tool for observing | |
| [openshift-demo](https://github.com/Senzing/openshift-demo) || :white_check_mark: || Demonstrate Senzing stack using `minishift`. | |
| [performance-general](https://github.com/Senzing/performance-general) | :white_check_mark: ||| Tips about improving the performance of Senzing | |
| [postgresql-client](https://github.com/Senzing/postgresql-client) || :white_check_mark: || A psql client that waits for the database to be ready before uploading SQL file. | |
| [postgresql-performance](https://github.com/Senzing/postgresql-performance) | :white_check_mark: ||| Tweaks to PostgreSQL and the Senzing DDL | |
| [rabbitmq-performance](https://github.com/Senzing/rabbitmq-performance) | :white_check_mark: ||| Tweeks to RabbitMQ | |
| [redoer](https://github.com/Senzing/redoer) || :white_check_mark: || Perform Senzing Redo operations. | |
| [resolver](https://github.com/Senzing/resolver) || :white_check_mark: || Ephemeral Senzing entity-resolution. | |
| [rest-api-client-java](https://github.com/Senzing/rest-api-client-java) | :white_check_mark: ||| :construction: [Under construction] - Client built from OpenAPI specification. | |
| [rest-api-client-ng](https://github.com/Senzing/rest-api-client-ng) | :white_check_mark: ||| Angular TypeScript interfaces, and classes for interacting with the senzing-api-server. | |
| [risk-score-calculator](https://github.com/Senzing/risk-score-calculator) | :white_check_mark: ||| Risk scorer. | |
| [sdk-components-ng](https://github.com/Senzing/sdk-components-ng) | :white_check_mark: ||| A collection of UI components to interface with the Senzing Rest API server. | |
| [senzing-api-server](https://github.com/Senzing/senzing-api-server) | :white_check_mark: ||| Server of Senzing REST API. | |
| [senzing-commons-java](https://github.com/Senzing/senzing-commons-java) | :white_check_mark: ||| Java classes used in multiple Senzing projects | |
| [senzing-data-encryption-specification](https://github.com/Senzing/senzing-data-encryption-specification) | :white_check_mark: ||| This is the interface for creating encryption plugins, to work with the G2 engine to encrypt sensitive data in the data repository. | |
| [senzing-entity-specification](https://github.com/Senzing/senzing-entity-specification) | :white_check_mark: ||| Complete Senzing Entity Specification and Attribute Dictionary. | |
| [senzing-listener-example](https://github.com/Senzing/senzing-listener-example) | :white_check_mark: ||| Example use of Senzing listener framework | |
| [senzing-listener](https://github.com/Senzing/senzing-listener) | :white_check_mark: ||| Listener framework. | |
| [senzing-poc-server](https://github.com/Senzing/senzing-poc-server) | :white_check_mark: ||| Senzing API Server plus management APIs. | |
| [senzing-rest-api-specification](https://github.com/Senzing/senzing-rest-api-specification) | :white_check_mark: ||| OpenAPI specification of Senzing REST API. | |
| [senzing-tools](https://github.com/Senzing/senzing-tools) || :white_check_mark: || An aggregation of Senzing tools | |
| [senzing-tutorial-in-python](https://github.com/Senzing/senzing-tutorial-in-python) || :white_check_mark: || Work in progress | |
| [senzing-with-chatgpt-notebook](https://github.com/Senzing/senzing-with-chatgpt-notebook) || :white_check_mark: || [Spike] ChatGPT and Jupyter Notebook integration | |
| [senzing-with-chatgpt-plugin](https://github.com/Senzing/senzing-with-chatgpt-plugin) || :white_check_mark: || [Spike] ChatGPT integration | |
| [senzing.github.io](https://github.com/Senzing/senzing.github.io) | :white_check_mark: ||| Organization site at <http://hub.senzing.com> | |
| [senzingapi-runtime](https://github.com/Senzing/senzingapi-runtime) | :white_check_mark: ||| Dockerfile with senzingapi-runtime binaries baked-in | |
| [senzingapi-tools](https://github.com/Senzing/senzingapi-tools) | :white_check_mark: ||| Base image using senzingapi-tools DEB file | |
| [senzinggo](https://github.com/Senzing/senzinggo) | :white_check_mark: ||| Quickly and easily start the Senzing REST API server, demo web app & Swagger in containers. | |
| [serve-chat](https://github.com/Senzing/serve-chat) || :white_check_mark: || Spike for HTTP API for chat service | |
| [serve-grpc](https://github.com/Senzing/serve-grpc) || :white_check_mark: || A gRPC server of the <https://github.com/Senzing/g2-sdk-proto> protocol | |
| [serve-http](https://github.com/Senzing/serve-http) || :white_check_mark: || A CLI tool for serving HTTP | |
| [stream-loader](https://github.com/Senzing/stream-loader) || :white_check_mark: || Python tool for loading Senzing Engine from RabbitMQ, Kafka, or AWS SQS. | |
| [stream-logger](https://github.com/Senzing/stream-logger) || :white_check_mark: || A utility for dumping the contents of a stream to a log. | |
| [stream-producer](https://github.com/Senzing/stream-producer) || :white_check_mark: || Produce a stream from different input formats. | |
| [subway-map](https://github.com/Senzing/subway-map) || :white_check_mark: || <http://hub.senzing.com/subway-map> site | |
| [support](https://github.com/Senzing/support) || :white_check_mark: || <http://hub.senzing.com/support> site | |
| [template-docker](https://github.com/Senzing/template-docker) ||| :white_check_mark: | Best practices for creating a "docker-*" repository. | |
| [template-go](https://github.com/Senzing/template-go) ||| :white_check_mark: | Best practices for creating a "go-" repository. | |
| [template-python](https://github.com/Senzing/template-python) ||| :white_check_mark: | Best practices for creating a "python-*" repository. | |
| [template-repository](https://github.com/Senzing/template-repository) ||| :white_check_mark: | Best practices for creating repository. | |
| [test-ground](https://github.com/Senzing/test-ground) || :white_check_mark: || An area for testing ideas.  May be wiped out at any time. | |
| [truth-sets](https://github.com/Senzing/truth-sets) | :white_check_mark: ||| Distributed with Senzing API package | |
| [validate](https://github.com/Senzing/validate) || :white_check_mark: || A CLI tool for validating data | |
| [video](https://github.com/Senzing/video) || :white_check_mark: || Videos available at <http://senzing.com/video> | |

## Ramifications

1. Links between repositories need to be updated.
1. Not sure a Kan-Ban board can span GitHub organizations for scrum.
1. GitHub Actions may need to be updated.
