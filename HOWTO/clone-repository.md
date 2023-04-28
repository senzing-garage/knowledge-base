# How to clone repository

## Prerequisite software

The following software programs need to be installed.

### git

1. [Install Git](https://github.com/Senzing/knowledge-base/blob/main/WHATIS/git.md)
1. Test

    ```console
    git --version
    ```

## Set environment variables for repository

:warning:  If sent here from another web page,
the next two environment variables are probably set.

1. :pencil2: If not already set, set environment variables for
   GitHub organization/account and the name of the repository.
   Example:

    ```console
    export GIT_ACCOUNT=senzing
    export GIT_REPOSITORY=name-of-repository
    ```

1. Synthesize environment variables.

    ```console
    export GIT_ACCOUNT_DIR=~/${GIT_ACCOUNT}.git
    export GIT_REPOSITORY_DIR="${GIT_ACCOUNT_DIR}/${GIT_REPOSITORY}"
    ```

## Determine URL of git repository

:thinking: Git repositories can be cloned via SSH or HTTPS.
For anonymous access, use HTTPS.
Perform one of the following commands to set `GIT_REPOSITORY_URL`.

### URL for HTTPS

1. Use this example for anonymous access.

    ```console
    export GIT_REPOSITORY_URL="https://github.com/${GIT_ACCOUNT}/${GIT_REPOSITORY}.git"
    ```

### URL for SSH

1. Use this example to log in with GitHub credentials.

    ```console
    export GIT_REPOSITORY_URL="git@github.com:${GIT_ACCOUNT}/${GIT_REPOSITORY}.git"
    ```

## Perform clone repository

1. :thinking: Create parent directories.
   Choose one method.
    1. Linux.
       Example:

        ```console
        mkdir --parents ${GIT_ACCOUNT_DIR}
        ```

    1. macOS.
       Example:

        ```console
        mkdir -p ${GIT_ACCOUNT_DIR}
        ```

1. Get repository.
   Example:

    ```console
    cd  ${GIT_ACCOUNT_DIR}
    git clone  --recurse-submodules ${GIT_REPOSITORY_URL}
    ```
