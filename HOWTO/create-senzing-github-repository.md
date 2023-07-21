# How to create Senzing GitHub repository

This is a checklist of what to set when creating a new GitHub Repository.

## Owner actions

1. Visit [github.com/Senzing](https://github.com/Senzing)
1. Log in as an administrator
1. On [github.com/Senzing](https://github.com/Senzing), click the `New` button
    1. Enter `Respository Name`
        1. Use only lower-case letters, numbers, and hyphens.
        1. Avoid use of underscore.
        1. When appropriate, use prefixes to help in searching for repositories.
           Examples:
            - `docker-` for docker-based repositories
            - `go-` for (non-command) go-based repositories
                - `go-...ing` - for cross-cutting concerns
            - `mapper-` for mapper functions
    1. Choose :radio_button: `Public`
    1. Check :ballot_box_with_check: `Initialize this repository with a README`
    1. If appropriate, add `.gitignore`
    1. For `Add a license`, choose `Apache License 2.0`
    1. Click `Create repository` button.
1. On repository home page, in **Releases** section:
    1. Click `Create a new release` link.
    1. `Tag version`: `0.0.0`
    1. `Release title`: `0.0.0`
    1. Click `Publish release` button.
1. On repository home page, click `Settings` tab.
    1. Click `Collaborators & teams` tab.
        1. Click `Add teams` button.
            1. Type `build`
            1. Choose `Senzing/build`
            1. Choose a role: `Admin`
            1. Click `Add Senzing/build to ...`

## Admin actions

### Branch Protection Rules

1. On repository home page, click `Settings` tab.
    1. Click `Branches` tab.
        1. `Branch name pattern:`  `main`
        1. `Protect matching branches` section
            1. :ballot_box_with_check: `Require a pull request before merging`
                1. :ballot_box_with_check: `Require approvals`
                1. :ballot_box_with_check: `Require review from Code Owners`
        1. Click `Create` button

### Collaborators & teams

1. On repository home page, click `Settings` tab.
    1. Click `Collaborators & teams` tab.
        1. Click `Add teams` button.
            1. Type `Senzing engineering`
            1. Choose `Senzing/senzing-engineering`
            1. Choose a role: `Write`
            1. Click `Add Senzing/senzingeering to ...`
        1. Click `Add teams` button.
            1. Type `Senzing`
            1. Choose the team that will be used in `.github/CODEOWNERS`
            1. Choose a role: `Write`
            1. Click `Add ... to this repository`

### Code and security analysis

1. On repository home page, click `Settings` tab.
    1. Click `Code security and analysis` tab.
        1. In `Access to alerts`:
            1. Search for `Senzing/senzing-engineering` and select.
            1. Click `Save changes` button

### Repository About

1. On repository home page, click **About** gear
    1. Add Topic relative to which Scrum manages the repository:
        1. `t-ast` for Api Server / Web App scrum
        1. `t-comm` for Community scrum
        1. `t-g2-python` for G2Python projects
        1. `t-gdev` for ????
        1. `t-devsecops` for DevOps
        1. `t-unknown` if not known
    1. Add optional Topics relative to code sub-project.
       Examples:
        1. `golang` - for "Go" based projects
    1. Click `Save` button

### Initial content

1. On repository home page, click `Issues` tab.
    1. Click `New issue` button.
        1. `Title`:  `Initial content`
        1. Click `Submit new issue` button
1. On repository home page, click `Branch: main` button.
    1. Create new branch.
       Example:
       `issue-1.[your-name].1`

### Populate repository with Community Artifacts

1. On your workstation,
    1. :pencil2: Substituting the new repository name for `xxxx`,

        ```console
        git clone git@github.com:Senzing/xxxx.git
        cd xxxx
        git checkout issue-1.[your-name].1
        ```

    1. Populate the new repository with the `Community Artifacts` found in
       [github.com/Senzing/template-repository](https://github.com/Senzing/template-repository).
    1. Modify `CONTRIBUTING.md`
        1. `export GIT_REPOSITORY=<new-repository-name>`
    1. Modify `.github/CODEOWNERS`
    1. Modify `.github/dependabot.yml`
    1. Delete `.github/workflows` files that do not apply.
    1. Commit the branch.
    1. Merge `issue-1.[your-name].1` branch into main branch.

### Branch Protection

1. On repository home page, click `Settings` tab.
1. Click `Branches` tab.
1. Edit `main` branch.
1. `Protect matching branches` section
    1. :ballot_box_with_check: `Require a pull request before merging`
        1. :ballot_box_with_check: `Require approvals`
        1. :ballot_box_with_check: `Require review from Code Owners`
    1. :ballot_box_with_check: `Require status checks to pass before merging`.
        1. :ballot_box_with_check: `Require branches to be up to date before merging`.
            1. Search and add *ALL* required status checks for the respective repository.
            - Search for the job name of the respective workflow.
            - Jobs to be added must have been run within the past 7 days against the respective repository.
            - See [GitHub docs] for more details.
    1. :ballot_box_with_check: `Require signed commits`
    1. :ballot_box_with_check: `Do not allow bypassing the above settings`
    1. Click `Save changes` at the bottom of the page.

### Pages

1. On repository home page, click `Settings` tab.
    1. Click `Pages` tab.
        1. In `Build and deployment` section:
            1. **Source:** `Deploy from a branch`
            1. Branch
                1. **Select branch:** `main`
                1. **Select folder:** `/docs`
            1. Click `Save` button
        1. In `Custom domain` section:
            1. :ballot_box_with_check: Enforce HTTPS

### Dependabot Automation Configuration

Additional settings changes required for auto merging dependabot pull requests.
Requires Admin access.

#### Prerequsites

[One time CODEOWNER token configuration].

#### Enable Auto Merge

1. On repository home page, click `Settings` tab.
1. In `Pull Requests` section
    1. :ballot_box_with_check: `Allow auto-merge`

#### Allow GitHub Actions to create and approve pull requests

1. On repository home page, click `Settings` tab.
1. In left side navigation bar, click `Actions` > `General`.
    1. :ballot_box_with_check: `Allow GitHub Actions to create and approve pull requests`
    1. Click `Save` button.

#### Add Dependabot Required Status Check

Perform the following steps after the dependabot actions have been performed.
There will be no searchable items at the time of repository creation unless
the status check has been performed within the last 7 day.

1. On repository home page, click `Settings` tab.
1. In left side navigation bar, select `Branches` tab.
1. Select `Edit` for the `main` branch protection rule.
    1. Under `Require branches to be up to date before merging`, search for and select
        - `dependabot-approve-and-merge / dependabot-approve-and-merge`
    1. Click the matching search result in the drop down.
    1. Click `Save changes` at the bottom of the page.

#### References

1. [GitHub docs](https://docs.github.com/en/repositories/configuring-branches-and-merges-in-your-repository/managing-protected-branches/about-protected-branches#require-status-checks-before-merging)
1. [One time CODEOWNER token configuration](https://github.com/Senzing/knowledge-base/blob/main/HOWTO/configure-github-organization.md)
