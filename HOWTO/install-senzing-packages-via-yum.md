# HOWTO - Install Senzing Packages via Yum

These instructions are only intended as a cheatsheet for developers.
There are alternate ways to do many of these actions that may or may not be documented 

## Installing the repo package

### Senzing version 3.9.X and below

```console
sudo yum install https://senzing-staging-yum.s3.amazonaws.com/senzingstagingrepo-1.0.0-1.noarch.rpm
```

### Senzing version 3.10.X and above

```console
sudo yum install https://senzing-staging-yum.s3.amazonaws.com/senzingstagingrepo-2.0.0-1.noarch.rpm
```

### Validating the repo package install

1. Use yum to verify the repo package is installed
```console
sudo yum list installed | grep senzing
```

## Listing Senzing packages

### List all available Senzing packages

```console
sudo yum list available | grep senzing
```

### List all available versions of a specific package

```console
sudo yum list --showduplicates <SENZING_PACKAGE>
```

```console
sudo yum list --showduplicates senzingapi-runtime
```

### List installed Senzing packages

```console
sudo yum list installed | grep senzing
```

## Installing Senzing packages

### Installing the latest version of a package

```console
sudo yum install <SENZING_PACKAGE>
```

Example: 
```console
sudo yum install senzingapi-runtime
```

### Installing a specific Senzing package version 

#### Installing a specific MAJOR.MINOR.PATCH version

```console
sudo yum install <SENZING_PACKAGE>-<MAJOR>.<MINOR>.<PATCH>*
```

NOTE: This will install the latest version of a particular `MAJOR`.`MINOR`.`PATCH` version.
Yum will use the latest build version
Example: 
If there are two senzingapi-runtime versions available:

```console
senzingapi-runtime.x86_64                                          3.9.0-24068
senzingapi-runtime.x86_64                                          3.9.0-24071
```

The following command would install the higher version: `3.9.0-24071`

```console
sudo yum install senzingapi-runtime-3.9.0*
```

#### Installing a specific MAJOR.MINOR.PATCH-BUILD_NUMBER version

```console
sudo yum install <SENZING_PACKAGE>-<MAJOR>.<MINOR>.<PATCH>-<BUILD_NUMBER>
```

Example:
```console
sudo yum install senzingapi-runtime-3.9.0-24068
```

## Listing package dependencies

```console
sudo yum deplist <SENZING_PACKAGE>
```

Example: 
```console
sudo yum deplist senzingapi-runtime
```

## Removing Senzing packages

```console
sudo yum remove <SENZING_PACKAGE>
```

Example:
```console
sudo yum remove senzingapi-runtime
```
