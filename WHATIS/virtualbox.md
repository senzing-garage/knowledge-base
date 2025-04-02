# What is virtualbox

## Install

1. [Download]

### CentOS

1. [Download VirtualBox for Linux Hosts]
1. VirtualBox Guest Additions.

   ```console
   vagrant plugin install vagrant-vbguest
   ```

### Ubuntu

1. [Download VirtualBox for Linux Hosts]
1. Example: virtualbox 6.0 on Ubuntu 18.04

   ```console
   sudo apt-get update
   sudo apt-get upgrade

   wget -q https://www.virtualbox.org/download/oracle_vbox_2016.asc -O- | sudo apt-key add -
   wget -q https://www.virtualbox.org/download/oracle_vbox.asc -O- | sudo apt-key add -

   sudo add-apt-repository "deb [arch=amd64] http://download.virtualbox.org/virtualbox/debian $(lsb_release -cs) contrib"

   sudo apt-get update
   sudo apt-get install -y virtualbox-6.0
   ```

1. VirtualBox Guest Additions.

   ```console
   sudo apt-get install -y virtualbox-guest-additions-iso
   sudo vagrant plugin install vagrant-vbguest
   ```

### macOS

### Windows

## Test

1. Test

   ```console
   vboxmanage --version
   ```

## Troubleshooting

## References

1. [How to Install VirtualBox 6.0 on Ubuntu 18.04 LTS / 18.10 / CentOS 7]
1. [How to Install VirtualBox 5.2 on Ubuntu 16.04 LTS]
1. [Download VirtualBox for Linux Hosts]

[Download]: https://www.virtualbox.org/
[Download VirtualBox for Linux Hosts]: https://www.virtualbox.org/wiki/Linux_Downloads
[How to Install VirtualBox 5.2 on Ubuntu 16.04 LTS]: https://tecadmin.net/install-oracle-virtualbox-on-ubuntu/
[How to Install VirtualBox 6.0 on Ubuntu 18.04 LTS / 18.10 / CentOS 7]: https://www.linuxtechi.com/install-virtualbox6-ubuntu-18-04-centos-7/
