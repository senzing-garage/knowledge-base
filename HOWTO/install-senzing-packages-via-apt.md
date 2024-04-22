# HOWTO - Install Senzing Packages via Apt

These instructions are only intended as a cheatsheet for developers.
There are alternate ways to do many of these actions that may or may not be documented here.

## Installing the repo package

### Senzing version 3.9.X and below

```console
wget https://senzing-staging-apt.s3.amazonaws.com/senzingstagingrepo_1.0.1-1_all.deb
sudo apt install ./senzingstagingrepo_1.0.1-1_all.deb
sudo apt update
```

### Senzing version 3.10.X and above

```console
wget https://senzing-staging-apt.s3.amazonaws.com/senzingstagingrepo_2.0.0-1_all.deb
sudo apt install ./senzingstagingrepo_2.0.0-1_all.deb
sudo apt update
```

### Validating the repo package install

1. Check the sources
   ```console
   grep ^ /etc/apt/sources.list /etc/apt/sources.list.d/*
   ```

## Listing Senzing packages

### List all available Senzing packages

```console
sudo apt list | grep senzing
```

### List all available versions of a specific package

```console
sudo apt list -a <SENZING_PACKAGE>
```

Ex.
```console
sudo apt list -a senzingapi-runtime
```

### List installed senzing packages

```console
sudo apt list --installed | grep senzing
```

## Installing Senzing packages

### Installing the latest version of a package

```console
sudo apt install <SENZING_PACKAGE>
```

Ex. 
```console
sudo apt install senzingapi-runtime
```

### Installing a specific Senzing package version 

#### Installing a specific MAJOR.MINOR.PATCH version

```console
sudo apt install <SENZING_PACKAGE>=<MAJOR>.<MINOR>.<PATCH>*
```

NOTE: This will install the latest version of a particular `MAJOR`.`MINOR`.`PATCH` version.
Apt will use the latest build version
Ex. 
If there are two senzingapi-runtime versions available:

```console
senzingapi-runtime/unknown 3.9.0-24071 amd64
senzingapi-runtime/unknown 3.9.0-24068 amd64
```

The following command would install the higher version: `3.9.0-24071`

```console
sudo apt install senzingapi-runtime=3.9.0*
```

#### Installing a specific MAJOR.MINOR.PATCH-BUILD_NUMBER version

```console
sudo apt install <SENZING_PACKAGE>=<MAJOR>.<MINOR>.<PATCH>-<BUILD_NUMBER>
```

Ex.
```console
sudo apt install senzingapi-runtime=3.9.0-24068
```

### Restricting Install versions via Apt preferences

1. Create a preferences file for the respective package.
   ``` console
   touch /etc/apt/preferences.d/<SENZING_PACKAGE>
   ```
   Ex.
   ``` console
   touch /etc/apt/preferences.d/senzingapi-runtime
   ```
1. Update the file to indicate which versions should be pinned.

   Ex. restrict the highest major version:

   ```console
   Package: <SENZING_PACKAGE>
   Pin: version <MAJOR_VERSION>.*
   Pin-Priority: 999
   ```

   Ex. restrict the highest major and minor version:

   ```console
   Package: <SENZING_PACKAGE>
   Pin: version <MAJOR_VERSION>.<MINOR_VERSION>.*
   Pin-Priority: 999
   ```

   Ex. restrict `senzingapi-runtime` to major version 3.
   This will prevent apt from installing any major version greater than 3.
   ```console
   Package: senzingapi-runtime
   Pin: version 3.*
   Pin-Priority: 999
   ```

See [Ubuntu documentation] or [Stack Exchange] for more details.

## Listing package dependencies

```console
sudo apt show <SENZING_PACKAGE>
```

Ex. 
```console
sudo apt show senzingapi-runtime
```

[Stack Exchange]: https://askubuntu.com/questions/547550/apt-mark-holding-a-package-to-a-major-version-not-a-specific-minor
[Ubuntu documentation]: https://help.ubuntu.com/community/PinningHowto
