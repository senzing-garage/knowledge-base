# Senzing fix issue

Follow these steps:

1. Use `gh issue list` to get issues.
2. Ask user to choose an issue or quit.
3. Use `gh issue view` to get the chosen issue details.
4. Use `git pull` to update the repository.
5. Use `git checkout main` to make sure there are no uncommitted changes in the repository.
6. Use `git checkout -b` to create a new local branch using the format "{issue-number}-{github-userid}-{next-available-whole-number}".
7. Use `git branch` to tell user the existing branches. Tell user the name of the newly created branch.
8. Understand the problem described.
9. Search the codebase for relevant files to implement the fix.
10. Write and run tests to verify the fix.
11. If unit tests exist, run unit tests.
12. Ask user if they want to locally commit the branch.
13. Remind user how to use `git push -u origin` to push the branch to GitHub.
