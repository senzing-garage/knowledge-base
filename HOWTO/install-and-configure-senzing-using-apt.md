# How to install and configure using apt

The following instructions are meant to be "copy-and-paste"
to install and configure Senzing Engine for repository projects.

This process requires the following files:

1. `${GIT_REPOSITORY_DIR}/src/apt-packages.txt`
1. `${GIT_REPOSITORY_DIR}/requirements.txt`

## APT installs

1. Run:

   ```console
   sudo xargs apt -y install < ${GIT_REPOSITORY_DIR}/src/apt-packages.txt
   ```

## PIP installs

1. Run:

   ```console
   sudo pip3 install -r ${GIT_REPOSITORY_DIR}/requirements.txt
   ```
