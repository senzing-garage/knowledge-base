# GitHub

## Public vs Private

Having code in "public" GitHub repositories offers advantages:

1. Free [GitHub Actions](https://docs.github.com/en/billing/managing-billing-for-github-actions/about-billing-for-github-actions)
1. Free [GitHub Packages](https://docs.github.com/en/packages/learn-github-packages/introduction-to-github-packages#about-billing-for-github-packages)

To promote "public" GitHub repositories, yet remove antiquated repositories,

1. All active repositories are "public".
1. Antiquated repositories are marked as publicly
   [deprecated](../../HOWTO/deprecate-a-github-repository.md).
1. After a GitHub repository has been publicly deprecated for over 1 year
   it may become "private".
1. The schedule for making deprecated repositories "private" is at
   [deprecated-repositories.md](../../lists/deprecated-repositories.md)

## Creating repository on GitHub

It's understood that over time practices improve on creation and maintenance of GitHub repositories.
The question becomes, "Where's the repository that shows the current best practices?"

To answer this question, a number of "template" repositories have been created to host the best practices
in GitHub repositories for particular projects:

1. General projects: [template-repository](https://github.com/Senzing/template-python)
1. Python projects: [template-python](https://github.com/Senzing/template-python)
1. Docker projects: [template-docker](https://github.com/Senzing/template-docker)
1. Go projects: [template-go](https://github.com/Senzing/template-go)

When
[creating a Senzing GitHub repository](https://github.com/Senzing/knowledge-base/blob/main/HOWTO/create-senzing-github-repository.md)
or updating an existing repository,
the appropriate "template" repository should be consulted.

## GitHub Actions

1. On pull requests opened or reopened by depend-a-bot:
    1. `add-dependabot-request-to-project-*.yaml`, by "team" topic, to add pull request to appropriate team Kanban board.
       Examples:
        1. [t-ast](https://github.com/Senzing/template-repository/blob/main/.github/workflows/add-dependabot-request-to-project-t-ast.yaml)
        1. [t-comm](https://github.com/Senzing/template-repository/blob/main/.github/workflows/add-dependabot-request-to-project-t-comm.yaml)
1. On issues opened or reopened:
    1. `add-issue-to-project-*.yaml`, by "team" topic, to add issue to appropriate team Kanban board.
       Examples:
        1. [t-ast](https://github.com/Senzing/template-repository/blob/main/.github/workflows/add-issue-to-project-t-ast.yaml)
        1. [t-comm](https://github.com/Senzing/template-repository/blob/main/.github/workflows/add-issue-to-project-t-comm.yaml)
    1. [add-triage-label.yaml](https://github.com/Senzing/template-repository/blob/main/.github/workflows/add-triage-label.yaml)
       to add the "triage" label to each new issue.
       This tag is to signal need for a discussion a the team scrum.
       If no discussion is needed, the "triage" label may be removed at any time.
1. On issues opened:
    1. [identify-customer.yaml](https://github.com/Senzing/template-repository/blob/main/.github/workflows/identify-customer.yaml)
       to add "customer" label to issue opened by GitHub users that is not in the Senzing organization.
       This is to aid in identifying customer issues in the KanBan board.

1. At Pull Request:
1. At
