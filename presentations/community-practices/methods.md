# Methods used in Community

## Development

1. [GitHub Flow](../../WHATIS/github-flow.md)
   1. [GitFlow](../../WHATIS/gitflow.md) for larger efforts
1. [Kanban](../../WHATIS/kanban.md)
1. [Application configuration](../../WHATIS/application-configuration.md)

## Architecture

1. [The Twelve-factor App](../../WHATIS/twelve-factor-app.md)
1. [Linux Hierarchical File standard](../../WHATIS/linux-filesystem-hierarchy-standard.md)
1. [cattle vs. pets](../../WHATIS/cattle-vs-pets.md)
1. [Software design patterns](../../WHATIS/software-design-patterns.md)

## Standards

1. Use standards.
   Examples:
    1. [Semantic versioning](../../WHATIS/semantic-versioning.md)
    1. [Linux Hierarchical File standard](../../WHATIS/linux-filesystem-hierarchy-standard.md)
    1. [RFC3339](https://datatracker.ietf.org/doc/html/rfc3339) - timestamps

## Documentation

1. Repository `README.md` files for repository-specific information.
1. [knowledge-base](https://github.com/Senzing/knowledge-base/) for information
   common to multiple repositories.
1. [knowledge-base](https://github.com/Senzing/knowledge-base/) for information
   independent of repositories.

1. Use current software methodologies.
   Examples:
    1. [GitHub Flow](../../WHATIS/github-flow.md)
    1. TODO: GitFlow
    1. [Kanban](../../WHATIS/kanban.md)

1. TODO: When in Rome code as the Romans

## Approaches

1. Design for customer infrastructures.
   Examples:
    1. Demonstration systems - for customer evaluation
    1. "Bare-metal" systems  (e.g. Linux/Debian/RedHat, Windows, MacOS, etc.)
    1. Cloud systems (e.g. Docker, Kubernetes, OpenShift, etc.)
    1. Air-gapped systems
    1. Log analysis - (e.g. ELK stacks, Datadog, Splunk, etc)

## Standard practices

By using standard practices, as Senzing grows, we look for professionals familiar with "standard practices"
so they don't have to learn "one-off" methods.
So instead of
> This is how it's done at Senzing.

it should be

> This is how it ought to be done everywhere.

## Independence of repositories

1. Each repository should have single focus
1. Each repository is independently versioned
