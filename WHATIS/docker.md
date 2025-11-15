# What is Docker

> Docker is used to run software packages called containers.
> Containers are isolated from each other and bundle their own
> application, tools, libraries and configuration files;
> they can communicate with each other through well-defined channels.
> All containers are run by a single operating-system kernel
> and are thus more lightweight than virtual machines.
> Containers are created from images that specify their precise contents.
> Images are often created by combining and modifying standard
> images downloaded from public repositories.
> -- _[Wikipedia]_

## Sites

1. [Official Docker site]
   1. [Documentation]
   1. [What is a Container?]
1. [github.com/docker]

## Install

Instructions for installing can be found at the [Official Docker site].
For detailed installation, see [Docker docs].

### CentOS

There are a few methods to install `docker` on Ubuntu.

1. [Default yum install](#centos---default-yum-install)
1. [Docker Community Edition](#centos---docker-community-edition)

#### CentOS - Default yum install

1. Yum install Docker.
   Example:

   ```console
   sudo yum install docker
   ```

1. Start Docker.
   Example:

   ```console
   sudo systemctl start docker
   ```

1. **Optional:** Start Docker on reboot.
   Example:

   ```console
   sudo systemctl enable docker
   ```

#### CentOS - Docker Community Edition

:warning: This may be an out-dated method.

1. Uninstall old docker.
   Example:

   ```console
   sudo yum remove docker docker-common docker-selinux docker-engine
   ```

1. [CentOS]

   ```console
   sudo yum -y install yum-utils device-mapper-persistent-data lvm2
   sudo yum-config-manager --add-repo https://download.docker.com/linux/centos/docker-ce.repo
   sudo yum -y install docker-ce
   ```

1. Start Docker.
   Example:

   ```console
   sudo systemctl start docker
   ```

1. **Optional:** Start Docker on reboot.
   Example:

   ```console
   sudo systemctl enable docker
   ```

1. Fix for unable to prepare context.

   Error seen:

   ```console
   unable to prepare context: unable to 'git clone' to temporary context directory: error initializing submodules: usage: git submodule
   ```

   Fix:

   ```console
   sudo yum install https://centos7.iuscommunity.org/ius-release.rpm
   sudo yum swap git git2u
   ```

### Ubuntu

There a a few methods to install `docker` on Ubuntu.

1. [Default apt install](#ubuntu---default-apt-install)
1. [Docker Community Edition](#ubuntu---docker-community-edition)

#### Ubuntu - Default apt install

1. Apt install Docker.
   Example:

   ```console
   sudo apt install docker.io
   ```

1. Proceed to [Test](#test)

#### Ubuntu - Docker Community Edition

:warning: This may be an out-dated method.

1. [Ubuntu]

   ```console
   sudo apt-get update

   sudo apt-get install \
       apt-transport-https \
       ca-certificates \
       curl \
       software-properties-common

   curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -

   sudo add-apt-repository \
      "deb [arch=amd64] https://download.docker.com/linux/ubuntu \
      $(lsb_release -cs) \
      stable"

   sudo apt-get update

   sudo apt-get install docker-ce
   ```

1. Proceed to [Test](#test)

#### Ubuntu - Past edition

1. Past version
   Example:

   ```console
   sudo apt-get update
   sudo apt -y install apt-transport-https ca-certificates curl software-properties-common
   curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
   sudo apt-get update
   sudo apt -y install docker.io
   ```

1. Proceed to [Test](#test)

### macOS

1. [Install Docker Desktop for Mac]
   1. Open Docker.dmg
   1. Drag Docker to Applications

1. Go to "Applications" and double-click on "Docker"
   1. Check the menu bar for the Docker icon

1. Test
   1. Open Terminal

   ```console
   docker --version
   docker-compose --version
   docker-machine --version
   docker run hello-world
   ```

1. Proceed to [Test](#test)

### Windows

1. **Caveat:** Requires Windows Pro.
1. [Install Docker Desktop for Windows]
   1. Run `Docker%20for%20%Windows%20Installer.exe`
1. Proceed to [Test](#test)

## Test

1. Test

   ```console
   sudo docker --version
   sudo docker run hello-world
   ```

## Troubleshooting

## References

[CentOS]: https://docs.docker.com/install/linux/docker-ce/centos/
[Docker docs]: https://docs.docker.com/install/
[Documentation]: https://docs.docker.com
[github.com/docker]: https://github.com/docker
[Install Docker Desktop for Mac]: https://docs.docker.com/docker-for-mac/install/
[Install Docker Desktop for Windows]: https://docs.docker.com/docker-for-windows/install/
[Official Docker site]: https://www.docker.com/
[Ubuntu]: https://docs.docker.com/install/linux/docker-ce/ubuntu/
[What is a Container?]: https://www.docker.com/resources/what-container
[Wikipedia]: https://en.wikipedia.org/wiki/Docker_(software)
