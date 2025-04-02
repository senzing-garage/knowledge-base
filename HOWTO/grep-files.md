# How to grep files

## Projects

### Remove deleted links

1. Make a file (`/tmp/grep-deleted-files.txt`), listing the strings to look for.
   Example:

   ```console
   cat<<EOT > /tmp/grep-deleted-files.txt
   challenges/senzing-jupyter-notebook.md
   demonstrations/rest-api-server-on-windows.md
   demonstrations/senzing-jupyter-on-macos.md
   docs/senzingapi/configure.md
   docs/senzingapi/install.md
   education/community/04-aws-cloudformation.md
   gists/air-gap-senzing-environment/air-gap-senzing-environment.sh
   gists/air-gap-senzing-environment/parse-1.15.0-py3-none-any.whl
   gists/air-gap-senzing-environment/README.md
   gists/aws-ecs/README.md
   gists/aws-ecs/task-definitions/sleep360.json
   gists/aws-ecs/using-autoscaling-groups.md
   gists/clone-senzing-repositories/clone-senzing-repositories.sh
   gists/docker-air-gap-helper/docker-air-gap-helper.sh
   gists/docker-air-gap-helper/README.md
   gists/tutorial-aws-ecs-cluster-docker/docker-compose.yaml
   gists/tutorial-aws-ecs-cluster-docker/ecs-params.yaml
   gists/tutorial-aws-ecs-cluster-docker/README.md
   HOWTO/accept-eula.md
   HOWTO/build-docker-senzing-phppgadmin.md
   HOWTO/certify-docker-images.md
   HOWTO/configure-senzing-using-docker.md
   HOWTO/configure-senzing-using-docker.md
   HOWTO/configure-senzing.md
   HOWTO/create-senzing-dir.md
   HOWTO/find-senzing-api-version.md
   HOWTO/initialize-senzing-with-docker.md
   HOWTO/initialize-senzing.md
   HOWTO/install-aws-ecs-cli.md
   HOWTO/install-docker-app.md
   HOWTO/install-senzing-data.md
   HOWTO/install-senzingapi-in-air-gapped-enviroment.md
   HOWTO/install-tiller.md
   HOWTO/install-vmware-workstation.md
   HOWTO/migrate-senzing-in-cloudformation.md
   HOWTO/migrate-senzing-using-docker.md
   HOWTO/quickstart-linux.md
   HOWTO/quickstart-macos.md
   HOWTO/README.md
   HOWTO/setup-senzing-rest-api-development-environment-on-linux.md
   HOWTO/setup-senzing-rest-api-development-environment-on-windows.md
   HOWTO/support-docker-network.md
   HOWTO/support-docker-user.md
   HOWTO/tag-docker-build.md
   HOWTO/test-private-docker-registry.md
   HOWTO/test-with-latest.md
   HOWTO/test-with-v2.md
   HOWTO/update-senzing-api.md
   HOWTO/update-senzing-images-on-docker-hub.md
   HOWTO/update-senzing-license.md
   HOWTO/update-senzing-package-on-docker-store.md
   HOWTO/update-sql-files.md
   HOWTO/use-docker-with-system-install.md
   lists/terraform-dictionary.md
   WHATIS/senzing-api-tgz.md
   EOT

   ```

1. Search across all repositories.
   Example:

   ```console
   cd ~/senzing.git
   grep --recursive --ignore-case --file=/tmp/grep-deleted-files.txt

   ```

1. Search a single repository.
   Example:

   ```console
   cd ~/senzing.git/<repository-name>
   grep --recursive --ignore-case --file=/tmp/grep-deleted-files.txt

   ```

### Modify links

1. Make a file (`/tmp/grep-update-links.txt`), listing the strings to look for.
   Example:

   ```console
   cat<<EOT > /tmp/grep-update-links.txt
   WHATIS/aws-cli.md
   WHATIS/curl.md
   WHATIS/db2-client.md
   WHATIS/docker-compose.md
   WHATIS/docker-registry-server.md
   WHATIS/docker.md
   WHATIS/git.md
   WHATIS/helm.md
   WHATIS/java.md
   WHATIS/jq.md
   WHATIS/jupyter-notebooks.md
   WHATIS/kubectl.md
   WHATIS/libmysqlclient21.md
   WHATIS/make.md
   WHATIS/minikube.md
   WHATIS/minishift.md
   WHATIS/nodejs.md
   WHATIS/npm.md
   WHATIS/packer.md
   WHATIS/pip3.md
   WHATIS/python.md
   WHATIS/rancher.md
   WHATIS/vagrant.md
   WHATIS/virtualbox.md
   EOT

   ```

1. Search across all repositories.
   Example:

   ```console
   cd ~/senzing.git
   grep --recursive --ignore-case --file=/tmp/grep-update-links.txt

   ```

1. Search a single repository.
   Example:

   ```console
   cd ~/senzing.git/<repository-name>
   grep --recursive --ignore-case --file=/tmp/grep-update-links.txt

   ```
