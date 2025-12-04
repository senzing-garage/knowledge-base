# Senzing fix issue

Follow these steps:

1. Determine which issue to work on.
    1. Use `gh issue list` to get issues.
    2. Ask user to choose an issue or quit.
    3. Use `gh issue view` to get the chosen issue details.
2. Create a new working branch.
    1. Use `git pull` to update the repository.
    2. Use `git checkout main` to make sure there are no uncommitted changes in the repository.
    3. Use `git checkout -b` to create a new local branch using the format "{issue-number}-{github-userid}-{next-available-whole-number}". Do not use existing branches.
    4. Use `git branch` to tell user the existing branches. Tell user the name of the newly created branch.
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
6. Commit code to GitHub.
    1. Ask user if they want to commit the branch locally.
    2. Remind user how to use `git push -u origin` to push the branch to GitHub.
