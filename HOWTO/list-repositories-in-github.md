# How to list repositories in GitHub

## Overview

Get a list of repositories for a GitHub account.

## Instructions

1. :pencil2: Set environment variables. Example:

    ```console
    export GIT_ACCOUNT=senzing
    ```

1. Fetch repositories.  Example:

    ```console
    curl -s https://api.github.com/orgs/${GIT_ACCOUNT}/repos?per_page=9999 | jq --raw-output '.[]|.full_name'
    ```
