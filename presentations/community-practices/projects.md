# Projects

## Projects with scrum

| Github Project                                           | Github Team                                                                    | GitHub Topic                                                                                     | Notes                             |
| -------------------------------------------------------- | ------------------------------------------------------------------------------ | ------------------------------------------------------------------------------------------------ | --------------------------------- |
| [Community](https://github.com/orgs/Senzing/projects/2)  | [Senzing community](https://github.com/orgs/Senzing/teams/senzing-community)   | [t-comm](https://github.com/search?q=org%3ASenzing%20topic%3At-comm&type=repositories)           | Not delivered by DEB/RPM.         |
| [gdev](https://github.com/orgs/Senzing/projects/9)       | [Senzing Gdev](https://github.com/orgs/Senzing/teams/senzing-gdev)             | [t-gdev](https://github.com/search?q=org%3ASenzing%20topic%3At-gdev&type=repositories)           |                                   |
| [g2-python](https://github.com/orgs/Senzing/projects/8)  | [g2-python](https://github.com/orgs/Senzing/teams/g2-python)                   | [t-g2-python](https://github.com/search?q=org%3ASenzing%20topic%3At-g2-python&type=repositories) | Delivered in DEB/RPM at g2/python |
| [app-server](https://github.com/orgs/Senzing/projects/6) | [Senzing App Server](https://github.com/orgs/Senzing/teams/senzing-app-server) | [t-ast](https://github.com/search?q=org%3ASenzing%20topic%3At-ast&type=repositories)             |                                   |

## Other

1. [GitHub Projects](https://github.com/orgs/Senzing/projects?type=classic)
1. [GitHub Teams](https://github.com/orgs/Senzing/teams)

## Senzing core

1. The "core" Senzing API code is not part of the Senzing Community.
1. This code is delivered in the DEB/RPM in these locations:
   1. `/opt/senzing/g2/bin`
   1. `/opt/senzing/g2/lib`
   1. `/opt/senzing/g2/g2.jar`
1. (Almost) all repositories are independently versioned.
   1. The only Senzing Community repository that is in "lock-step" with the
      SenzingAPI package (DEB/RPM) version is
      [g2-python](https://github.com/senzing-garage/g2-python).
      This is because the contents of the repository are delivered with the
      SenzingAPI package.
