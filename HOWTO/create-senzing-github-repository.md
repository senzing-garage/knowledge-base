# How to create Senzing GitHub repository

This is a checklist of what to set when creating a new GitHub Repository.

## Create repository

1. Visit [github.com/Senzing](https://github.com/Senzing)
1. Log in as an administrator
1. On [github.com/Senzing](https://github.com/Senzing), click the "New" button
    1. Enter "Respository Name"
        1. Use only lower-case letters, numbers, and hyphens.
        1. Avoid use of underscore.
        1. When appropriate, use prefixes to help in searching for repositories.
           Examples:
            - "docker-" for docker-based repositories
            - "mapper-" for mapper functions
    1. Choose :radio_button: Public
    1. Check :ballot_box_with_check: Initialize this repository with a README
    1. If appropriate, add .gitignore
    1. For "Add a license", choose "Apache License 2.0"
    1. Click "Create repository" button.

## Configure repository

1. On repository home page, in **Releases** section:
    1. Click "Create a new release" link.
    1. Tag version: 0.0.0
    1. Release title: 0.0.0
    1. Click "Publish release" button.
1. On repository home page, click "Settings" tab.
    1. Click "Branches" tab.
        1. Click "Add rule" button.
        1. Branch name pattern:  "main"
        1. Protect matching branches
            1. :ballot_box_with_check: Require pull request reviews before merging
                1. :ballot_box_with_check: Require approvals
                1. :ballot_box_with_check: Require review from Code Owners
        1. Click "Create" button
    1. Click "Collaborators & teams" tab.
        1. Click "Add teams" button.
            1. Type "Senzing engineering"
            1. Choose "Senzing/senzing-engineering"
            1. Choose a role: "Write"
            1. Click "Add Senzing/senzingeering to ..."
        1. Click "Add teams" button.
            1. Type "build"
            1. Choose "Senzing/build"
            1. Choose a role: "Admin"
            1. Click "Add Senzing/build to ..."
    1. Click "Security & analysis" tab.
        1. "Enable" Dependabot security updates
        1. In "Dependabot alerts":
            1. Search for "Senzing/senzing-engineering" and select.
            1. Click "Save changes" button
1. On repository home page, click "Insights" tab.
    1. Click on "Community Standards" tab.
        1. "Enable" Repository admins accept content reports.
            1. :ballot_box_with_check: Accept content reports from collaborators and prior contributors
1. On repository home page, click **About** gear
    1. Add Topics:
        1. `t-ast` for Api Server / Web App scrum
        1. `t-comm` for Community scrum
        1. `t-g2-python` for G2Python projects
        1. `t-gdev` for ????
        1. `t-unknown` if not known
1. On repository home page, click "Issues" tab.
    1. Click "New issue" button.
        1. Title:  "Initial content"
        1. Click "Submit new issue" button
1. On repository home page, click "Branch: main" button.
    1. Create new branch.
       Example:
       "issue-1.[your-name].1"

## Populate repository with Community Artifacts

1. On your workstation,
    1. :pencil2: Substituting the new repository name for `xxxx`,

        ```console
        git clone git@github.com:Senzing/xxxx.git
        cd xxxx
        git checkout issue-1.[your-name].1
        ```

    1. Populate the new repository with the "Community Artifacts" found in
       [github.com/Senzing/template-repository](https://github.com/Senzing/template-repository).
    1. Modify `CONTRIBUTING.md`
        1. `export GIT_REPOSITORY=<new-repository-name>`
    1. Modify `README.md`
        1. Use contents from `.github/README_TEMPLATE/demonstration/README.md`
    1. Delete `.github/README_TEMPLATE` directory.
    1. Delete `.github/workflows/examples` directory.
    1. Delete `.github/workflows` files that do not apply.
    1. Commit the branch.
    1. Merge `issue-1.[your-name].1` branch into main branch.
