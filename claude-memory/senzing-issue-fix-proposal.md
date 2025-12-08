# Senzing fix issue

Follow these steps:

1. Determine which issue to work on.
    1. Use `gh issue list` to get issues.
    2. Ask user to choose an issue or quit.
    3. Use `gh issue view` to get the chosen issue details.
2. Determine which branch to work in.
    1. Use `git pull`
        1. Update the local repository.
    2. Use `git branch`
        1. Ask user which branch to use or if a new branch should be created.
    3. If new branch should be created,
        1. Use `git checkout main`
            1. Make sure there are no uncommitted changes in the local repository.
            2. Quit if there are conflicts.
        2. Use `git checkout -b`
            1. Create a new unique local branch from `main`.
            2. New branch name has the format "{issue-number}-{github-userid}-{next-available-whole-number}".
            3. Tell user which branch was just created.
            4. Checkout new branch.
    4. Checkout branch chosen by user.
3. Develop code.
    1. Understand the problem described in the issue.
    2. Search the codebase for relevant files to fix the issue.
4. Test code.
    1. Write and run tests to verify the fix.
    2. If unit tests exist, run unit tests.
    3. Ensure code passes linting and type checking
5. Document fix.
    1. Create a descriptive commit message.
    2. Ask user if this is a new versioned release.
    3. If not a new versioned release, in `CHANGELOG.md`, update the "[Unreleased]" section with the fix description.
    4. If it is a new versioned release, in `CHANGELOG.md`, add a new "Patch version" section with the fix description using the following standards:
        1. <https://keepachangelog.com/en/1.0.0/>
        2. <https://semver.org/spec/v2.0.0.html>
6. Do not commit code in local repository.
7. Do not commit code to GitHub.
