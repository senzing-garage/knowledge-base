# Senzing template refactor

This task applies the best practices codified in a template repository to the current repository.

If no $ARGUMENTS specified, determine the `repository-template` in the following manner:

1. If the file `.github/workflows/go-test-linux.yaml` exists, the `repository-template` value is `template-go`.
1. Else if the file `.github/workflows/pytest-linux.yaml` exists, the `repository-template` value is `template-python`.
1. Else if the file `Dockerfile` exists, the `repository-template` value is `template-docker`.
1. Otherwise, the `repository-template` value  is `template-repository`.

The `github-organization` value is the GitHub organization of the current repository.

Follow these steps:

1. Confirm the detected `repository-template` value with the user.
1. The `repository-template-url` has the form <https://github.com/senzing-garage/`repository-template`>
1. Compare the current repository with the repository at the `repository-template-url`.
1. Update files to conform to the files in the `repository-template`.
    1. Rename reference from `repository-template` value to the current repository name.
    1. If `github-organization` is not `senzing-garage`, modify URLs:
        - From <https://github.com/senzing-garage>
        - To <https://github.com/`github-organization`>
1. If `.claude/CLAUDE.md` does not exist,
    1. Use `/init` to create a new `.claude/CLAUDE.md`.
1. If `.claude/commands/senzing.md` does not exist,
    1. Create `.claude/commands/senzing.md`  based on the `repository-template`.
1. If `.claude/commands/senzing-code-review.md` exists,
    1. Ask the user if it can be deleted it.
    1. If user answers in the affirmative, delete `.claude/commands/senzing-code-review.md`.
1. If `.claude/settings.json` does not exist,
    1. Create `.claude/settings.json` based on the `repository-template`.
1. In `github/` directory,
    1. Update GitHub Action workflows with appropriate changes from the `repository-template`.
    1. Add `cooldown:` key/value were appropriate.
    1. Add `timeout-minutes:` key/value were appropriate.
    1. Add `fail-fast:` key/value were appropriate.
    1. Capitalize the `name:` values to match what is in the `repository-template`.
1. In `.gitignore`,
    1. Make sure `.claude/settings.local.json` is listed.
    1. Change `.DS_STORE` to `.DS_Store`.
1. In `.vscode/settings.json`,
    1. Copy JSON key/value pairs from template into current repository.
1. In `CHANGELOG.md`,
    1. Update header and footer information.
1. In `SECURITY.md`,
    1. Update the "Version | Supported" table, update the columns to reflect the latest versioned release of the current repository.
1. Update the following files in the current repository:
    1. `.github/dependabot.yml`
    1. `docs/README.md`
    1. `CODE_OF_CONDUCT.md`
    1. `CONTRIBUTING.md`
    1. `LICENSE`
1. Do not commit code in local repository.
1. Do not commit code to GitHub.
