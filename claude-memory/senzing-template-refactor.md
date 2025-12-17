# Senzing template refactor

This task applies the best practices codified in a template repository to the current repository.

If no $ARGUMENTS specified, determine the `repository-template` in the following manner:

1. If the file `.github/workflows/go-test-linux.yaml` exists, the `repository-template` value is `template-go`.
1. Else if the file `.github/workflows/pytest-linux.yaml` exists, the `repository-template` value is `template-python`.
1. Else if the file `Dockerfile` exists, the `repository-template` value is `template-docker`.
1. Otherwise, the `repository-template` value  is `template-repository`.

Follow these steps:

1. Confirm the detected `repository-template` value with the user.
    1. The `repository-template-url` has the form <https://github.com/senzing-garage/`repository-template`>
1. Compare the current repository with the repository at the `repository-template-url`.
1. Update files to conform to the files in the `repository-template`.
    1. Rename reference from `repository-template` value to the current repository name.
1. Do not commit code in local repository.
1. Do not commit code to GitHub.
