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

The process for creating a Senzing repository on GitHub is documented in
[create-senzing-github-repository.md](https://github.com/senzing-garage/knowledge-base/blob/main/HOWTO/create-senzing-github-repository.md).

It's understood that over time practices improve on creating and maintaining GitHub repositories.
The question becomes, "Where's the repository that shows the current best practices?"

To answer this question, a number of "template" repositories have been created to host the best practices
in GitHub repositories for particular project types:

1. General projects: [template-repository](https://github.com/senzing-garage/template-repository)
1. Python projects: [template-python](https://github.com/senzing-garage/template-python)
1. Docker projects: [template-docker](https://github.com/senzing-garage/template-docker)
1. Go projects: [template-go](https://github.com/senzing-garage/template-go)

When
[creating a Senzing GitHub repository](https://github.com/senzing-garage/knowledge-base/blob/main/HOWTO/create-senzing-github-repository.md)
or updating an existing repository,
the appropriate "template" repository should be consulted.

## Dependabot

Github's
[Dependabot](https://docs.github.com/en/code-security/dependabot)
is used to keep dependencies up-to-date.

Example use:

1. Python: [dependabot.yml](https://github.com/senzing-garage/template-python/blob/main/.github/dependabot.yml)
1. Docker: [dependabot.yml](https://github.com/senzing-garage/template-docker/blob/main/.github/dependabot.yml)
1. Go: [dependabot.yml](https://github.com/senzing-garage/template-go/blob/main/.github/dependabot.yml)
1. Java: [dependabot.yml](https://github.com/senzing-garage/senzing-api-server/blob/main/.github/dependabot.yml)
1. Npm:  [dependabot.yml](https://github.com/senzing-garage/entity-search-web-app/blob/main/.github/dependabot.yml)

## GitHub Actions

Note: Not all GitHub Actions are in each repository.
They are tailored to the type of project.

1. On **issue** opened:
    1. [identify-customer.yaml](https://github.com/senzing-garage/template-repository/blob/main/.github/workflows/identify-customer.yaml)
       adds "customer" label to issue opened by GitHub users that is not in the Senzing organization.
       This is to aid in identifying customer issues in the KanBan board.
1. On **issue** opened or reopened:
    1. `add-issue-to-project-*.yaml`, by "team" topic, adds issue to appropriate team Kanban board.
       Examples:
        1. [add-issue-to-project-t-ast.yaml](https://github.com/senzing-garage/template-repository/blob/main/.github/workflows/add-issue-to-project-t-ast.yaml)
        1. [add-issue-to-project-t-comm.yam](https://github.com/senzing-garage/template-repository/blob/main/.github/workflows/add-issue-to-project-t-comm.yaml)
    1. [add-triage-label.yaml](https://github.com/senzing-garage/template-repository/blob/main/.github/workflows/add-triage-label.yaml)
       adds the "triage" label to each new issue.
       This tag is to signal need for a discussion a the team scrum.
       If no discussion is needed, the "triage" label may be removed at any time.
1. On **push**:
    1. [pylint.yaml](https://github.com/senzing-garage/template-python/blob/main/.github/workflows/pylint.yaml) scans python files for adherance to
       [PEP 8](https://peps.python.org/pep-0008/) standards as well as good Python programming practices.
    1. [go-test.yaml](https://github.com/senzing-garage/template-go/blob/main/.github/workflows/go-test.yaml)
       runs `go test -v -p 1 ./...` which exectues all Go language Unit Tests.
1. On **push** of `M.m.P` tag - a semantic version release:
    1. [make-go-github-file.yaml](https://github.com/senzing-garage/template-go/blob/main/.github/workflows/make-go-github-file.yaml)
       creates a file usually placed in cmd/github.go containing versioning information for "next" version.
       Example: [github.go](https://github.com/senzing-garage/init-database/blob/main/cmd/github.go).
    1. [make-go-tag.yaml](https://github.com/senzing-garage/template-go/blob/main/.github/workflows/make-go-tag.yaml)
        makes a tag in the "Go version style" of `vM.m.P` using the same SHA as the `M.m.P` semantic version.
        This version style is used by the Go package management system.
        By doing this, we only create sematically versioned releases and let GitHub Actions make modifications
        for specific platforms.
    1. [make-github-release-assets.yaml](https://github.com/senzing-garage/senzing-tools/blob/main/.github/workflows/make-github-release-assets.yaml)
       creates installable DEB/RPM packages for a Go artifact.
       For example,
       [senzing-tools releases](https://github.com/senzing-garage/senzing-tools/releases).
1. On **push** of `vM.m.P` tag - a Go version identifier:
    1. [go-proxy-pull.yaml](https://github.com/senzing-garage/template-go/blob/main/.github/workflows/go-proxy-pull.yaml)
       "primes the pump" for users of the Go package system.
1. On **pull request** to `main` branch:
    1. [build-docker-container.yaml](https://github.com/senzing-garage/template-docker/blob/main/.github/workflows/build-docker-container.yaml)
       will verify that the `Dockerfile` can be successfully built into a Docker image.
       It does not test that the Docker image is correct.
1. On **pull request** opened or reopened by Dependabot:
    1. `add-dependabot-request-to-project-*.yaml`, by "team" topic, to add pull request to appropriate team Kanban board.
       Examples:
        1. [add-dependabot-request-to-project-t-ast.yaml](https://github.com/senzing-garage/template-repository/blob/main/.github/workflows/add-dependabot-request-to-project-t-ast.yaml)
        1. [add-dependabot-request-to-project-t-comm.yaml](https://github.com/senzing-garage/template-repository/blob/main/.github/workflows/add-dependabot-request-to-project-t-comm.yaml)
