# How to deprecate a GitHub repository

## Steps

### Change README.md

1. At the top of README, under the level-1 header, add a level-2 "Deprecated" header.
   Example:

    ```console
    ## :no_entry: Deprecated
    ```

1. Add a description of why repository was deprecated and what to do next.

1. Add "no maintenance" badge.
   Example:

    ```console
    [![No Maintenance Intended](http://unmaintained.tech/badge.svg)](http://unmaintained.tech/)
    ```

1. Pull changes to README.md into "main" branch.

### Change title

1. On `https://github.com/{account}/{repository}` page, click the title "Edit" button.
   Example:

    ```console
    :no_entry: [DEPRECATED] Please use https://github.com/{account}/{new-repository} instead.
    ```

### Topics

1. On `https://github.com/{account}/{repository}` page, click "Manage topics" link.
   Type the topics in and use the spacebar between topics.  (i.e. Don't just copy/paste the following)
   Example:

    ```console
    obsolete deprecated archived
    ```

### Branches

1. On `https://github.com/{account}/{repository}` page, see if there are any branches that need to be merged into "main" branch.

1. Delete unwanted branches.

### Pull requests

1. On `https://github.com/{account}/{repository}` page, see if there are any "Pull requests" that need to be merged into "main" branch.

### Release

1. On `https://github.com/{account}/{repository}` page, click "XX releases" link.
1. Create a final release version.

### Issues

1. On `https://github.com/{account}/{repository}` page, see if there are any issues that need to be closed.

### Archive

1. On `https://github.com/{account}/{repository}` page, click the "Settings" tab.
1. In "Options" pane, in the "Danger Zone", click "Archive this repository"

## Examples

1. [github.com/Senzing?q=docker-compose](https://github.com/Senzing?q=docker-compose)
    1. [github.com/Senzing/docker-compose-db2-demo](https://github.com/Senzing/docker-compose-db2-demo)
    1. [github.com/Senzing/docker-compose-mysql-demo](https://github.com/Senzing/docker-compose-mysql-demo)
    1. [github.com/Senzing/docker-compose-postgresql-demo](https://github.com/Senzing/docker-compose-postgresql-demo)

## References

1. [How To Deprecate A Repository on GitHub](https://medium.com/maintainer-io/how-to-deprecate-a-repository-on-github-8f0ceb9155e)
1. [Archiving repositories](https://github.blog/2017-11-08-archiving-repositories/)
1. StackOverflow:
    1. [https://stackoverflow.com/questions/44376628/standard-way-of-marking-a-github-organization-or-repository-as-deprecated](https://stackoverflow.com/questions/44376628/standard-way-of-marking-a-github-organization-or-repository-as-deprecated)
