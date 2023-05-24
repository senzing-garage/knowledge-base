# GitHub actions

In this document are ideas pertaining to the implementation of GitHub Actions.

## Aspects to consider

### Updating Github Actions YAML files via Dependabot

1. Dependabot can be configured to create Pull Requests to update `.github/workflows/github-actions.yaml files
   with newer versions of the Github Action. Examples:
    1. [Dependabot configuration](https://github.com/Senzing/template-repository/blob/main/.github/dependabot.yml)
    1. [Dependabot created pull request](https://github.com/Senzing/template-repository/pull/37)
1. This is triggered by a versioned release of the repository containing the GitHub Action.
1. If more than one GitHub Action is contained in a repository, it's possible that repositories are notified for
   GitHub Action version updates, when the version of the GitHub Action they are using is not updated.
    1. For instance,  if a single repository holds GitHub actions for both Python and Go languages,
       then the go users would be notified of an update when there are changes to the Python GitHub Actions.

### Creating a GitHub Action that can be published

The
[GitHub Actions Marketplace](https://github.com/marketplace?type=actions)
sets the standard for crafting GitHub Actions.

    1. GitHub's [About publishing actions](https://docs.github.com/en/actions/creating-actions/publishing-actions-in-github-marketplace#about-publishing-actions) has these requirements (and more):

>>> - The action must be in a public repository.
>>> - Each repository must contain a single action.

## References

1. GitHub
    1. [Automate your workflow from idea to production](https://github.com/features/actions)
    1. [About custom actions](https://docs.github.com/en/actions/creating-actions/about-custom-actions)
    1. [About publishing actions](https://docs.github.com/en/actions/creating-actions/publishing-actions-in-github-marketplace#about-publishing-actions)
