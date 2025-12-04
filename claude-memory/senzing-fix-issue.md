# Senzing fix issue

Follow these steps:

1. Use `gh issue list` to get issues.
2. Ask user to choose an issue.
3. Use `gh issue view` to get the chosen issue details.
4. Use `git checkout -b` to create a new local branch using the format "{issue-number}-{github-userid}-{next-available-whole-number}".
5. Use `git branch` to list the branches.
6. Tell user the name of the newly created branch.
7. Understand the problem described.
8. Search the codebase for relevant files to implement the fix.
9. Write and run tests to verify the fix.
10. If unit tests exist, run unit tests.
11. Ask user if they want to locally commit the branch.
12. Remind user how to use `git push -u origin` to push the branch to GitHub.
