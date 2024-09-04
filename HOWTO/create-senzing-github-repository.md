# How to create Senzing GitHub repository

This is a checklist of what to set when creating a new GitHub Repository.

## Owner actions

1. Identify the GitHub Organization the repository will belong to.     
   - One of < `Senzing` | `senzing-factory`| `senzing-garage` >.
   - Will be henceforth referred to as `<ORG>` and should be substituted with a value from above.
   - ***NOTE***: There are slight differences between organization selections in this document.       
     Where applicable options will be listed for each organization. Please be sure to select the 
     options for the respective organization. 
1. Visit `github.com/<ORG>`
1. Log in as an administrator.
1. On `github.com/<ORG>`, click the `New` button under the `Repositories` header.
    1. Enter `Respository Name`
        1. Use only lower-case letters, numbers, and hyphens.
        1. Avoid use of underscore.
        1. When appropriate, use prefixes to help in searching for repositories.
           Examples:
            - `docker-` for docker-based repositories
            - `go-` for (non-command) go-based repositories
                - `go-...ing` - for cross-cutting concerns
            - `mapper-` for mapper functions
    1. Choose :radio_button: `Public` unless otherwise advised.
    1. Check :ballot_box_with_check: `Initialize this repository with: Add a README file`
    1. If appropriate, add `.gitignore`
    1. For `Choose a license`, choose `Apache License 2.0`
    1. Click `Create repository` button.
1. On repository home page, in **Releases** section:
    1. Click `Create a new release` link.
    1. `Tag version`: `0.0.0`
    1. `Release title`: `0.0.0`
    1. Click `Publish release` button.
1. On repository home page, click `Settings` tab.
    1. Click `Collaborators & teams` tab.
        1. Click `Add teams` button.
            1. Type one of the following for the respective organization into the test box and click to select:
               1. Senzing: `Senzing/build`
               1. senzing-factory: `senzing-factory/senzing-factory-admin`
               1. senzing-garage: `senzing-garage/senzing-garage-admin`
            1. Choose a role: `Admin`
            1. Click `Add <ORG>/<Team selection from above>`

## Admin actions

### Branch Protection Rules

1. On repository home page, click `Settings` tab.
    1. Click `Branches` tab.
    1. Click `Add classic branch protection rule`
        1. `Branch name pattern:`  `main`
        1. `Protect matching branches` section
            1. :ballot_box_with_check: `Require a pull request before merging`
                1. :ballot_box_with_check: `Require approvals`
                1. :ballot_box_with_check: `Require review from Code Owners`
        1. :ballot_box_with_check: `Require signed commits`
        1. Click `Create` button

### Collaborators & teams

1. On repository home page, click `Settings` tab.
    1. Click `Collaborators & teams` tab.
        1. For ***ALL*** organizations:
            1. Click `Add teams` button.
                1. Type `senzing-automation`
                1. Choose `<ORG>/senzing-automation`
                1. Choose a role: `Write`
                1. Click `Add <ORG>/senzing-automation`
            1. Click `Add teams` button.
                1. Type `senzing-devsecops`
                1. Choose `<ORG>/senzing-devsecops`
                1. Choose a role: `Write`
                1. Click `Add <ORG>/senzing-devsecops`
            1. Click `Add teams` button.
                1. Type `senzing-project-managers`
                1. Choose `<ORG>/senzing-project-managers`
                1. Choose a role: `Maintain`
                1. Click `Add senzing-project-managers`
        1. For Organization `Senzing`:
            1. Click `Add teams` button.
                1. Using the appropriate development team based on the list: https://github.com/orgs/Senzing/teams
                1. Choose the team that will be used in `.github/CODEOWNERS`
                1. Choose a role: `Write`
                1. Click `Add ... to this repository`
        1. For Organizations `senzing-factory`| `senzing-garage`:
            1. Click `Add teams` button.
                1. Type `senzing`
                1. Choose the team that will be used in `.github/CODEOWNERS`
                1. Choose a role: `Write`
                1. Click `Add ... to this repository`

### Code and security analysis

1. On repository home page, click `Settings` tab.
    1. Click `Code security and analysis` tab.
        1. In `Access to alerts`:
            1. Search for the team that will be used in `.github/CODEOWNERS` and select.
            1. Click `Save changes` button

### Link the project board

1. On the repository home page, click `Projects` tab.
    1. Click `Link a project`
    1. Select the respective project board for the repository.
        1. `Senzing` organization: `Senzing Github Organization Project`
        1. `senzing-factory` organization: `Factory`
        1. `senzing-garage` organization, one of:
            1. `App Server`
            1. `G2 Python`
            1. `Garage`
            1. `Garage Roadmap`

### Repository About

1. On repository home page, click **About** gear
    1. Add Topic relative to which project board will be linked to the repository:
        1. `senzing-app-server` for Api Server / Web App
        1. `senzing-github-organization-project` for all Senzing organization repositories
        1. `senzing-g2-python` for G2Python projects
        1. `senzing-garage` for Garage projects
        1. `senzing-devsecops` for all senzing-factory organization projects
        1. `senzing-unknown` if not known
    1. Add optional Topics relative to code sub-project.
       Examples:
        1. `golang` - for "Go" based projects
    1. Click `Save changes` button

### Initial content

1. On repository home page, click `Issues` tab.
    1. Click `New issue` button.
    1. Select any type of issue and select `Get started`
        1. `Title`:  `Initial content`
        1. `Add a description`: delete any default content in this text box.
        1. In the right side navigation select `assign yourself`.
        1. In the right side navigation select the respective project board.
        1. Click `Submit new issue` button.
1. On repository home page, click `Branch: main` button.
    1. Create new branch.
       Example:
       `1-[your-name]-1`
       ***NOTE***: Branch names should start with the respective issue number.

### Populate repository with Community Artifacts

1. On your workstation,
    1. :pencil2: Substituting the organization for `<ORG>` and the new repository name for `<REPO>`,

        ```console
        git clone git@github.com:<ORG>/<REPO>.git
        cd <REPO>
        git checkout 1-[your-name]-1
        ```

    1. Populate the new repository with the `Community Artifacts` found in
       [github.com/senzing-garage/template-repository](https://github.com/senzing-garage/template-repository).
    1. Modify `CONTRIBUTING.md`
        1. `export GIT_ACCOUNT=<ORG>`
        1. `export GIT_REPOSITORY=<new-repository-name>`
    1. Modify `.github/CODEOWNERS`
    1. Modify `.github/dependabot.yml`
    1. Modify `.project`
    1. Modify `./docs/README.md`
    1. Delete `.github/workflows` files that do not apply.
    1. Rename `add-to-project-garage-dependabot.yaml` and `add-to-project-garage.yaml` 
       with the appropriate project name. 
    1. Update the project variable and name of the workflow for the following:
        1. `add-to-project-<project>-dependabot.yaml`
        1. `add-to-project-<project>.yaml`
        1. `move-pr-to-done-dependabot.yaml`
    1. Commit the branch.
    1. Merge `1-[your-name]-1` branch into main branch.

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
               - Ex. type `lint` in the search bar and select `lint-workflows / Lint Workflows` and `lint-workflows / changes`. Both of these should be selected on ALL of our repositories. It is in the format `<workfow-name>/<job-name>`. Ignore any checks prefixed with `-->`.
               - TIPS:
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
    1. :black_square_button: `Allow merge commits`
    1. :ballot_box_with_check: `Allow squash merging`
    1. :ballot_box_with_check: `Allow rebase merging`
    1. :ballot_box_with_check: `Always suggest updating pull request branches`
    1. :ballot_box_with_check: `Allow auto-merge`
    1. :ballot_box_with_check: `Automatically delete head branches`

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
    1. Under `Require branches to be up to date before merging`, search for and select the required checks. Ex:
        - `build-docker-container`
        - `dependabot-approve-and-merge / dependabot-approve-and-merge`
        - `Go 1.20 - darwin`
        - `Go 1.20 - linux`
        - `Go 1.20 - windows`
        - `gofmt / gofmt`
        - `gosec`
    1. Click the matching search result in the drop down.
    1. Click `Save changes` at the bottom of the page.

[GitHub docs]: https://docs.github.com/en/repositories/configuring-branches-and-merges-in-your-repository/managing-protected-branches/about-protected-branches#require-status-checks-before-merging
[One time CODEOWNER token configuration]: https://github.com/senzing-garage/knowledge-base/blob/main/HOWTO/configure-github-organization.md
