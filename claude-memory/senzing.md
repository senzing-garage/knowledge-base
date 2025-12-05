# Senzing

1. If no $ARGUMENTS specified, ask use to choose a subcommand from the following list:
    1. code-review - Perform code review
    1. fix-issue - Fix a GitHub issue
    1. versioned-release - Prepare for versioned release

1. If subcommand is "code-review"
    1. Perform the code review specified by <https://raw.githubusercontent.com/senzing-factory/build-resources/refs/heads/main/claude/pr-prompt.md>
1. If subcommand is "fix-issue"
    1. Perform the steps specified by <https://raw.githubusercontent.com/senzing-garage/knowledge-base/refs/heads/main/claude-memory/senzing-fix-issue.md>
1. If subcommand is "versioned-release"
    1. Perform the steps specified by <https://raw.githubusercontent.com/senzing-garage/knowledge-base/refs/heads/main/claude-memory/senzing-versioned-release.md>
