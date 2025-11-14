# Issue Reference Format Guide

Quick reference for all supported ways to link issues in PRs and commits.

## Supported Formats

| Format | Example | Description | Links To |
|--------|---------|-------------|----------|
| `#N` | `#42` | Same repo issue | Current repository issue #42 |
| `owner/repo#N` | `acme/api#99` | Cross-repo (user) | acme/api repository issue #99 |
| `org/repo#N` | `platform/auth#123` | Cross-repo (org) | platform/auth repository issue #123 |

## Validation Rules

### ✅ Valid Patterns

```
#123                          → Links to #123 (same repo)
acme-corp/web-app#42         → Links to acme-corp/web-app#42
my-org/backend-api#99        → Links to my-org/backend-api#99
user_name/my-repo#15         → Links to user_name/my-repo#15
org-name/repo-name#1         → Links to org-name/repo-name#1
```

### ❌ Invalid Patterns (Won't Match)

```
42                           → Missing # prefix
#                            → No number
repo#42                      → Missing owner/org
/repo#42                     → Missing owner/org
owner/#42                    → Missing repo
owner/repo                   → Missing #number
owner/repo#                  → Missing number
```

## Where to Use

You can reference issues in **any** of these locations:

1. **PR Title**
   ```
   Fix authentication bug (#42)
   Integrate with auth-team/service#99
   ```

2. **PR Description**
   ```markdown
   This PR fixes #42 by refactoring the login flow.
   
   Also addresses issues from external-org/shared-lib#15
   ```

3. **Commit Messages**
   ```bash
   git commit -m "Fix #42 and platform/db#99"
   git commit -m "Implement feature requested in other-team/api#123"
   ```

## Character Rules

### Owner/Org Name (before `/`)
- Letters: `a-z`, `A-Z`
- Numbers: `0-9`
- Special: `_` (underscore), `-` (hyphen)
- Examples: `my-org`, `user_name`, `acme-corp`, `team123`

### Repository Name (after `/`)
- Same rules as owner/org
- Examples: `web-app`, `api_service`, `backend-v2`, `tool123`

### Issue Number (after `#`)
- Only digits: `0-9`
- Examples: `#1`, `#42`, `#9999`

## Common Scenarios

### Internal Team Issues
```bash
# All in same org
git commit -m "Fix #42 (this repo)"
git commit -m "Update per platform-team/auth#99"
git commit -m "Sync with infrastructure/deploy#123"
```

### External Dependencies
```bash
# Issues from external organizations
git commit -m "Fix compatibility with facebook/react#12345"
git commit -m "Work around vuejs/core#999"
```

### Mixed References
```bash
# Combine same-repo and cross-repo
git commit -m "Fix #42, #43, and external-org/api#99"
```

## Deduplication

The workflow automatically deduplicates references:

**Input (multiple commits):**
```bash
git commit -m "Start work on #42"
git commit -m "Continue #42"
git commit -m "Fix other-team/api#99"
git commit -m "Complete #42"
```

**Output (PR description):**
```
Resolves #42
Resolves other-team/api#99
```

## What Won't Match (Safe)

These patterns are **safe** and won't create false links:

```
Version 1.2.3                    → Version number
Port 8080                        → Port number
Bug 42                           → Missing # prefix
Issue 123 fixed                  → Missing # prefix
PR 42 merged                     → Missing # prefix
Ticket ABC-123                   → Not a number after potential #
192.168.1.1                      → IP address
```

## Edge Cases

### Multiple Issues in One Line
```bash
git commit -m "Fix #42, #99, and platform/auth#123"
```
✅ Finds all three: `#42`, `#99`, `platform/auth#123`

### Issue Numbers in Parentheses
```bash
git commit -m "Add feature (closes #42)"
```
✅ Finds: `#42`

### Issue in URL (Not Recommended)
```bash
git commit -m "See https://github.com/org/repo/issues/42"
```
❌ Won't match (no `#` or `org/repo#` format)
💡 Use: `See org/repo#42` instead

### Hashtags (Safe)
```bash
git commit -m "Update docs #backend #api"
```
❌ Won't match (no digits after `#`)
✅ Safe! Won't create false links

## Best Practices

1. **Be explicit**: Use full `owner/repo#N` format for cross-repo references
2. **Avoid ambiguity**: Don't rely on URLs, use the shorthand format
3. **Reference early**: Add issue references in early commits or PR description
4. **Use keywords**: Make intent clear with "Fixes", "Closes", "Resolves", etc.
5. **Check logs**: Review workflow output to confirm issues were found

## Testing Your References

Before merging, you can test if your references will be detected:

1. Look at your PR title
2. Look at your PR description  
3. Look at your commit messages
4. Apply these regex patterns:
   - Same repo: `#\d+`
   - Cross repo: `[a-zA-Z0-9_-]+/[a-zA-Z0-9_-]+#\d+`

If you find matches, the workflow will too!
