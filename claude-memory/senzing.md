# Senzing

1. If no $ARGUMENTS specified, ask user to choose a subcommand from the following list:
    1. changelog-update - Update CHANGELOG.md
    1. code-review - Perform code review
    1. issue-fix-proposal - Propose a fix for a GitHub issue. Does not commit fix.

1. If subcommand is "changelog-update"
    1. Perform the steps specified by <https://raw.githubusercontent.com/senzing-garage/knowledge-base/refs/heads/main/claude-memory/senzing-changelog-update.md>
1. If subcommand is "code-review"
    1. Perform the steps specified by <https://raw.githubusercontent.com/senzing-factory/build-resources/refs/heads/main/claude/pr-prompt.md>
1. If subcommand is "fix-issue"
    1. Perform the steps specified by <https://raw.githubusercontent.com/senzing-garage/knowledge-base/refs/heads/main/claude-memory/senzing-issue-fix-proposal.md>
