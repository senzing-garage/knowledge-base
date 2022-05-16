# Senzing Community GitHub Processes


## Standards used

1. [GitHub flow](https://guides.github.com/introduction/flow/)
1. [Keep a Changelog](https://keepachangelog.com/en/1.0.0/)
1. [Markdown rules](https://github.com/DavidAnson/markdownlint/blob/main/doc/Rules.md)
1. [Semantic Versioning](https://semver.org/spec/v2.0.0.html)

## Code changes

### Create an issue

1. **Why?**
   The issue is the basis of all provenance.
   It identifies *why* code is being changed and
   ties together branches, pull requests, and merges.
1. Input:
    1. **Title:** Concise description of the issue.
    1. **Write:** Detailed description of the issue.
    1. **Assignees:** Individual(s) responsible for completing the issue.
       Can remain unassigned in the "Backlog" and "On deck".
       Needs to be assigned when "In Progress".
    1. **Labels:** Used to identify issue as a member of 0 or more groups
       "Triage" will be added automatically and can be removed if no triage is needed.
    1. **Projects:** Used to track progress of issue in a team Kanban project board.
1. Examples:
    1. In https://github.com/Senzing/stream-loader/issues/231
        1. "mentions" - See other related issues and whether they are open or closed
        1. "commits" - by clicking on an abbreviated "commit SHA", the change is shown.
        1. "build status" - by clicking on the "x" or "check", you can see the checks that were performed
        1. , "labels", "github-actions", "merges", "comments"


### Create a branch

1. Branch name format:  `issue-000`.`[your-name]`.`[anything-you-want]`
1. **Why a branch?**
   The main branch is protected.
   The assumption is that the main branch always deployable
   (i.e. it is never broken).
   The only way to modify the main branch
   is to have an approved Pull Request merged in.
1. **Why a branch name format?**
   This is about "provenance":
    1. What is the work for? ("issue-000")
    1. Who owns the branch?  ("dockter")
   *Example branch name:*  `issue-50.dockter.1`

### Commit to branch

1. Commit frequently.
   Unless a better commit message is appropriate, commit messages like these can be used:
    1. "#00 Savepoint"
    1. "#00 WIP"  - for Work-in-Progress
   Later these commits will be "squashed" together.
   **Why?**  It prevents disaster, allows better undoing, and let's others know of your progress.

1. Comments start with `<issue-number>`

### Create a Pull Request

1. Review your changes
1. Assign a reviewer
1. Make "Assignees" yourself.
   **Why?**
   By making yourself an assignee,
   it tells the reviewer that you will merge request into the main branch
   and delete your "issue" branch.
   It also makes it easier to find what branches have been approve by viewing
   [Pull requests > Assigned](https://github.com/pulls/assigned)

### Review Pull Request

### Automated testing

### Merge Pull Request

### Close issue

1. As a closing comment, add

    ```text
    Pull requests:

    1. https://github.com/Senzing/xxx/pull/50
    1. https://github.com/Senzing/xxx/pull/51
    1. https://github.com/Senzing/xxx/pull/52
    ```

   **Why?**
   This adds a "mention" into the pull request.
   If someone lands on a Pull Request, they can instantly find the issue that is associated to it.
   They can also see if the issue is "closed" or still "open".

### Delete branch

### Semantic versioning

### Kanban board
