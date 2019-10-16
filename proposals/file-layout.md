# Senzing file layout

## Contents

1. [Background](#background)
1. [Projects](#projects)
1. [Tool chain considerations](#tool-chain-considerations)
1. [Questions](#questions)
1. [Issues](#issues)
1. [References](#references)

## Background

### Types of Senzing files

Senzing has directories of files that fit into the following categories:

1. Immutable files:
    1. `g2` directory. Frequent releases.
    1. `data` directory. Infrequent releases.
1. Configuration files:
    1. `etc` directory.
1. Mutable files:
    1. `var`directory.

The expectation is that `g2` and `data` directory contents are not modified by the user nor by processes.
If there are files that need to be customized or modified,
they are copied into either the `etc` directory or `var` directory and then modified.

### Configuration precedence

Processes look for configuration in the following priority order:

1. Command-line options
1. Environment variables
1. Configuration file
1. Defaults

With exception of "Defaults", all are optional.
Any combination can be used.
For instance, `FOO` can be specified as a command-line option and an environment variable.
In this case the value of `FOO` in the command-line option takes precedence over the value in the environment variable.

#### Command-line options

The highest configuration priority is given to a command-line option.
The command-line option over-rides an Environment variable, configuration-file value, and default value.
If a value is not specified on the command-line, then the pecking order is:
Environment variable; Configuration file; and finally default value.

1. Example:

    ```console
    senzing-program \
      --data-dir /path/to/data \
      --g2-dir /path/to/g2 \
      --etc-dir /path/to/etc \
      --var-dir /path/to/var
    ```

#### Environment variables

Optional environment values.

1. Example:

    ```console
    export SENZING_DATA_DIR=/path/to/data
    export SENZING_ETC_DIR=/path/to/etc
    export SENZING_G2_DIR=/path/to/g2
    export SENZING_VAR_DIR=/path/to/var
    ```

#### Configuration file

An optional configuration file can specify one or more configurations.

1. Examples:

    ```console
    senzing-program \
      --config-file /path/to/config-file.toml
    ```

    ```console
    senzing-program \
      --config-file /path/to/config-file.json
    ```

1. `/path/to/config-file.toml` contents.
    Example:

    ```console
    [senzing]
    dataDir = /path/to/data
    etcDir  = /path/to/etc
    g2Dir   = /path/to/g2
    varDir  = /path/to/var
    ```

1. `/path/to/config-file.json` contents.
    Example:

    ```json
    {
      "senzing": {
        "dataDir": "/path/to/data",
        "etcDir": "/path/to/etc",
        "g2Dir": "/path/to/g2",
        "varDir": "/path/to/var"
      }
    }
    ```

#### Default locations

**Note:** The following example will be modified with the introduction of "Projects".

1. Example:

    1. `data` directory
        1. `/opt/senzing/data`
    1. `etc` directory
        1. `${CURRENT_WORKING_DIRECTORY}/etc`
        1. `/etc/opt/senzing`
    1. `g2` directory
        1. `/opt/senzing/g2`
    1. `var` directory
        1. `${CURRENT_WORKING_DIRECTORY}/var`
        1. `/var/opt/senzing`

1. **Notes**
    1. The "data" directory refers to the directory containing actual data (e.g. `cnv.ibm`, `gnv.ibm`).
       It does not refer to the the directory that currently holds version subdirectories.

## Projects

Given that a Project is a specific set of (data, etc, g2, var),
the "Default locations" could be augmented to:

1. `data` directory
    1. `${SENZING_PROJECT_DIR}/data`
    1. `/opt/senzing/data`
1. `etc` directory
    1. `${SENZING_PROJECT_DIR}/etc`
    1. `${CURRENT_WORKING_DIRECTORY}/etc`
    1. `/etc/opt/senzing`
1. `g2` directory
    1. `${SENZING_PROJECT_DIR}/g2`
    1. `/opt/senzing/g2`
1. `var` directory
    1. `${SENZING_PROJECT_DIR}/var`
    1. `${CURRENT_WORKING_DIRECTORY}/var`
    1. `/var/opt/senzing`

Then, a Senzing project directory could be specified as a configuration option.

1. Command-line options.
   Example:

    ```console
    senzing-program \
      --project-dir /path/to/my-project
    ```

1. Environment variables.
   Example:

    ```console
    export SENZING_PROJECT_DIR=/path/to/my-project
    ```

1. Configuration file.
   Example:

    ```console
    senzing-program \
      --config-file /path/to/config-file.toml
    ```

   `/path/to/config-file.toml` contents.
   Example:

    ```console
    [senzing]
    projectDir = /path/to/my-project
    ```

1. Default.
   There is no default.
   Just like command-line options, environment variables and configuration files,
   if there is no `SENZING_PROJECT_DIR` specified, it is not factored into the configuration.
    1. Idea:  If a `<current-working-directory>/.senzing` directory is detected,
       code could consider `SENZING_PROJECT_DIR=<current-working-directory>`.

The configuration precedence now looks like this:

1. Command-line options
1. Environment variables
1. Configuration file
1. Project directory
1. Defaults

### Special cases

1. A command like:

    ```console
    senzing-program \
      --project-dir /path/to/my-project \
      --etc-dir /path/to/etc
    ```

   Means use the project directory for (data, g2, var) directories and `/path/to/etc` for the "etc" directory.
   This allows for flexible testing against multiple configurations.

1. Immutable files from `g2` or `data`.

   If there are files that may be modified by a user and place in either the  `etc` or `var` directores,
   the `senzing-program` needs to know to look in the `/etc` or `var` directory
   before looking in the `g2` or `data` directory.

   **Note** A "cascading" or merging of base files in `g2` and `etc` may be considered to keep only the
   specific customizations in the `etc` directory.  Loosely known as "Cascading Configuration Pattern".

### Create project

1. Layout of a project.

    ```console
    /path/to/my-project
    ├── .senzing
    │   └── project-history.json
    ├── data -> /opt/senzing/data-1.0.0/
    ├── etc
    │   ├── cfgVariant.json
    │   ├── customGn.txt
    │   ├── customOn.txt
    │   ├── customSn.txt
    │   ├── defaultGNRCP.config
    │   ├── g2config.json
    │   ├── G2Module.ini
    │   ├── G2Project.ini
    │   └── stb.config
    ├── g2 -> /opt/senzing/g2-1.12.0/
    ├── setupEnv
    └── var
        └── sqlite
            └── G2C.db
    ```

1. Creating a project.
    1. Make symlinks.
       **Note:** it is important that the source of the link (i.e. `ln -s <source> <link_name>`)
       is a directory created by the RPM installation.

        ```console
        cd /path/to/my-project
        ln -s /opt/senzing/data-1.0.0 data
        ln -s /opt/senzing/g2-1.12.0  g2
        ```

    1. `/opt/senzing/g2/resources/templates`
        1. Now also known as `/path/to/my-project/g2/resources/templates`.
        1. Copy specific templates to `/path/to/my-project/etc`
            1. Remove `.templates` suffix.
            1. Example:  Don't copy G2C.db.template to `/path/to/my-project/etc`.
        1. Copy `/opt/senzing/g2/resources/templates/G2C.db` to `/path/to/my-project/var/sqlite/G2C.db`
        1. Modify contents of "etc" files as needed.
    1. Copy `/opt/senzing/g2/setupEnv` to `/path/to/my-project/setupEnv` and modify contents as needed.
    1. Note: If a project always wanted to be on the latest installed version,
       the linking would be:

        ```console
        cd /path/to/my-project
        ln -s /opt/senzing/data data
        ln -s /opt/senzing/g2   g2
        ```

### Upgrade project

1. Determine a folder is a senzing project is done by detecting the `.senzing` directory.
1. When needed, update the following soft-links:
    1. `/path/to/my-project/data`
    1. `/path/to/my-project/g2`
1. Modify `setupEnv`
1. Modify `/path/to/my-project/.senzing/project-history.json` to keep pertinent history.

### Rollback project

1. Determine a folder is a senzing project is done by detecting the `.senzing` directory.
1. When needed, update the following soft-links:
    1. `/path/to/my-project/data`
    1. `/path/to/my-project/g2`
1. Modify `setupEnv`
1. Modify `/path/to/my-project/.senzing/project-history.json` to keep pertinent history.

### Detecting links

1. To determine if a `senzingdata` or `senzingapi` version is still needed,
   The following commands determine if the package is being linked by any project.
   Example:

    ```console
    find / -lname "*g2-1.12.0?"
    ```

    ```console
    find / -lname "*data-1.1.0?"
    ```

1. If a package is deleted in error, it can be recovered by a yum install.
   Example:

    ```console
    sudo yum install senzingapi-1.11.0
    ```

## Tool chain considerations

### Git

1. If a customer creates a git repository for their code,
   they should not include Senzing code in their repository.
   [Twelve factor: Codebase](https://12factor.net/codebase).
   > Multiple apps sharing the same code is a violation of twelve-factor.
1. By separating the specification of Senzing files from their actual locations,
   Git repositories do not need to imbed Senzing code.
   [Twelve factor: Dependencies](https://12factor.net/dependencies).
1. Git has brittle support for symlinks.
   Symlinks that point to "stable, absolute paths" will work.
   Example: ["g2" in git repository](https://github.com/docktermj/spike-symlink-test).
1. An "etc" directory can be separately versioned in a source code management system by a customer.
   A "var" directory can be snap-shotted, if needed.
   The "data" and "g2" directories can always be reinstalled.

### Docker

1. The proposal allows immutable volumes to be mounted Read Only for security and performance.
   `data` and `g2` can certainly be mounted Read Only.
1. Mounting volumes at `docker run` time allow for incremental development by allowing a developer
   to copy and modify one of the (data, etc, g2, var) directories, then test.
1. Allows the same docker image to be run at different versions of Senzing.

1. Installing Senzing onto volumes with docker.
   Example:

    ```console
    sudo docker run \
      --volume ${SENZING_OPT_DIR}:/opt/senzing \
      --volume ${SENZING_ETC_DIR}:/etc/opt/senzing \
      --volume ${SENZING_VAR_DIR}:/var/opt/senzing \
      senzing/yum
    ```

1. Initializing Senzing volumes with docker.
   Example:

    ```console
    sudo docker run \
      --volume ${SENZING_DATA_DIR}:/opt/senzing/data \
      --volume ${SENZING_ETC_DIR}:/etc/opt/senzing \
      --volume ${SENZING_G2_DIR}:/opt/senzing/g2 \
      --volume ${SENZING_VAR_DIR}:/var/opt/senzing \
      senzing/init-container
    ```

1. Using docker.
   Example:

    ```console
    sudo docker run \
      --volume ${SENZING_DATA_DIR}:/opt/senzing/data \
      --volume ${SENZING_ETC_DIR}:/etc/opt/senzing \
      --volume ${SENZING_G2_DIR}:/opt/senzing/g2 \
      --volume ${SENZING_VAR_DIR}:/var/opt/senzing \
      senzing/example
    ```

1. Using docker with `SENZING_OPT_DIR`.
   Example:

    ```console
    sudo docker run \
      --volume ${SENZING_OPT_DIR}:/opt/senzing \
      --volume ${SENZING_ETC_DIR}:/etc/opt/senzing \
      --volume ${SENZING_VAR_DIR}:/var/opt/senzing \
      senzing/example
    ```

1. Using docker with projects.
   Example:

    ```console
    sudo docker run \
      --env SENZING_PROJECT_DIR=/project \
      --volume ${SENZING_PROJECT_DIR}:/project \
      senzing/example
    ```

1. Using docker with ad-hoc mounting.
   Example:

    ```console
    sudo docker run \
      --env SENZING_DATA_VERSION_DIR=/my/tom/data \
      --env SENZING_ETC_DIR=/my/betty/etc \
      --env SENZING_G2_DIR=/my/oscar/g2 \
      --env SENZING_VAR_DIR=/my/susan/var \
      --volume /tmp/bob/senzing/data:/my/tom/data \
      --volume /tmp/mary/senzing/etc:/my/betty/etc \
      --volume /tmp/john/senzing/g2:/my/oscar/g2 \
      --volume /tmp/jane/senzing/var:/my/susan/var \
      senzing/example
    ```

### Kubernetes / OpenShift

1. Separate Persistent Volumes can be kept for different version of Senzing.
1. Separate Persistent Volumes for development, verification, and production.
1. Supports "rolling updates" and roll-backs.
1. If desired, the same docker images can be run with different Persistent Volumes to
   spread the load across different file systems.

### Jenkins

1. Jenkins jobs can reuse Senzing installations whether they be system, project, or ad-hoc installs.
1. Variation can be made in Jenkins runs by changing the "etc" directory, but keeping (data, g2, var) directories.
1. Only single versions of immutable files need to be kept on Jenkins server.
1. For regression testing we have a battery of docker images with different version of our "apps" baked in.
   We run them against different versions of senzing by adjusting the specification of the (data, etc, g2, var) directories.

### Twelve factor

1. The design needs to keep development, staging, and production as similar as possible.
   [Twelve Factor:  Dev/prod parity](https://12factor.net/dev-prod-parity)

## Questions

1. Is `PIPELINE.CONFIGPATH` always `${SENZING_ETC_DIR}`?
1. Is `PIPELINE.SUPPORTPATH` always `${SENZING_DATA_DIR}`?
1. Is `PIPELINE.RESOURCEPATH` always `${SENZING_G2_DIR}/resources`?

## Issues

1. The Senzing G2 code should verify that it's working with the correct level of Senzing Data at runtime.
    1. Not a foreign idea: The Senzing G2 code already verifies the correct level of the database schema.
1. A G2Project needs to separate (data, etc, g2, var) directories.
   Currently, it has (data, etc, var) directories, but obfuscates the "g2" directory.
   See [Create project](#create-project).
1. A stable path for the latest versions of `senzingdata` and `senzingapi`.
    1. Senzing client code may want to run with pinned and unpinned versions of Senzing.
    1. Unpinned versions want "latest" code.
    1. RPM installations.
       Example:

        ```console
        /
        └── opt
            └── senzing
                ├── data -> data-1.1.0/
                ├── data-1.0.0
                ├── data-1.1.0
                ├── g2 -> g2-1.12.0/
                ├── g2-1.11.0
                └── g2-1.12.0
        ```

1. RPM versioning needs to be cleaned up.
   Example:

    ```console
    # yum list senzingapi --showduplicates

    Available Packages
    senzingapi.x86_64    1.10.0-19190    senzing-production
    senzingapi.x86_64    1.10.0-19214    senzing-production
    senzingapi.x86_64    1.10.0-19224    senzing-production
    senzingapi.x86_64    1.10.0-19229    senzing-production
    senzingapi.x86_64    1.11.0-19246    senzing-production
    ```

    Alternatively:

    ```console
    /
    └── opt
        └── senzing
            ├── data -> data-1.1.0/
            ├── data-1.0.0
            ├── data-1.1.0
            ├── g2 -> g2-1.12.0-19287/
            ├── g2-1.10.0-19224
            ├── g2-1.10.0-19229
            ├── g2-1.11.0-19246
            └── g2-1.12.0-19287
    ```

## References

1. Linux Filesystem Hierarchy Standard
    1. [tldp.org](http://tldp.org/LDP/Linux-Filesystem-Hierarchy/html/)
    1. [Wikipedia](https://en.wikipedia.org/wiki/Filesystem_Hierarchy_Standard)
1. Layered configuration
    1. [Python LayeredConfig](https://layeredconfig.readthedocs.io/en/latest/usage.html#precedence)
1. TOML
    1. [Wikipedia](https://en.wikipedia.org/wiki/TOML)
1. Configuration packages
    1. [Viper](https://github.com/spf13/viper)
1. Cascading Configuration pattern
    1. [Cascading Configuration Design Pattern](https://fredtrotter.com/2017/12/05/cascading-configuration-design-pattern/)
    1. [Cascading Configuration Pattern](http://www.octodecillion.com/cascadeconfigpattern/)
1. Configuration precedence
    1. [StackOverflow: ...in what order](https://stackoverflow.com/questions/32272911/precedence-of-configuration-options-environment-registry-configuration-file-a)
    1. [AWS Elastic Beanstalk precedence](https://docs.aws.amazon.com/elasticbeanstalk/latest/dg/command-options.html#configuration-options-precedence)
    1. [Order of Precedence when Configuring ASP.NET Core](https://devblogs.microsoft.com/premier-developer/order-of-precedence-when-configuring-asp-net-core/) - see "Order of Precedence"
    1. [Hashicorp Consul Configuration](https://www.consul.io/docs/agent/options.html)
1. Symbolic links
    1. [Symbolic links in Git](https://www.mokacoding.com/blog/symliks-in-git/)
