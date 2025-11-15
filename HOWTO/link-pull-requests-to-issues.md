# Developer Guide: Linking PRs to Issues

## TL;DR

Reference issues with `#` prefix anywhere in your PR or commits, and they'll automatically link after merge!

## How to Reference Issues

### ✅ Correct - Will Link

**Same Repository Issues:**

_In PR Title:_

```bash
Fix authentication bug (#42)
Add feature requested in #99
```

_In PR Description:_

```bash
This PR addresses #42 by refactoring the auth flow.
Closes #99
```

_In Commit Messages:_

```bash
git commit -m "Fix login redirect, resolves #42"
git commit -m "Refactor auth service (#42)"
git commit -m "Add tests for #42 and #99"
```

**Cross-Repository Issues:**

_In PR Title:_

```bash
Fix bug reported in platform-team/auth-service#123
Addresses issue from acme-corp/api#99
```

_In PR Description:_

```bash
This fixes the issue reported in external-org/web-app#42
Related to infrastructure-team/deployment#15
```

_In Commit Messages:_

```bash
git commit -m "Fix cross-service bug other-team/api-service#123"
git commit -m "Implement fix for platform/auth#99 and platform/db#100"
```

**Mixed (Same + Cross Repository):**

```bash
git commit -m "Fix #42 and external-org/shared-lib#99"
```

### ❌ Incorrect - Won't Link

**Missing # prefix:**

```bash
Fix bug 42          # Just a number, not a GitHub issue
Update issue 99     # Won't match
```

**Invalid cross-repository format:**

```bash
Fix repo#42         # Missing owner/org
Fix org/42          # Missing # prefix
```

**Version numbers (safe - won't match):**

```bash
Update to version 1.2.3    # Good! Won't link
Bump dependencies to 4.5.6  # Good! Won't link
```

## Multiple Issues

You can reference multiple issues, and they'll all be linked:

```bash
git commit -m "Fix #42, #99, and #100"
```

Result after merge:

```bash
Resolves #42
Resolves #99
Resolves #100
```

## Keywords (Optional)

While not required, using keywords makes intent clearer:

- `Fixes #42`
- `Resolves #42`
- `Closes #42`
- `Addresses #42`
- `Related to #42`

All will link the same way after merge!

## What Happens After Merge

1. 🤖 Workflow runs automatically
2. 🔍 Scans your PR title, description, and all commit messages
3. 📝 Finds all `#<number>` references
4. ✏️ Adds them to PR description as `Resolves #<number>`
5. 🔗 GitHub links them in the Development sidebar
6. ✅ Issues stay open (you close them manually when ready)

## Best Practices

### ✅ Do:

- Reference issues early (in commits or PR description)
- Use meaningful commit messages with issue numbers
- Reference multiple related issues if applicable

### ❌ Don't:

- Worry about auto-closing issues (it won't happen after merge)
- Use issues numbers without `#` prefix
- Add "Resolves" manually (workflow does it for you)

## FAQ

**Q: Will the issue auto-close?**  
A: No! Since the linking happens _after_ merge, the issue won't auto-close.

**Q: What if I forget to reference an issue?**  
A: No problem! The workflow fails gracefully. You can manually link later.

**Q: Can I reference issues from other repositories?**  
A: Yes! Use `owner/repo#42` format, but this may require custom regular expression pattern.

**Q: What if my commit message mentions a number that's not an issue?**  
A: As long as it doesn't have a `#` prefix, it won't match. Version numbers like `1.2.3` are safe!

**Q: Do I need to reference issues in every commit?**  
A: No! Reference it anywhere (title, description, or any commit).

## Examples from Real Workflows

### Example 1: bugfix

```bash
# PR title: "Fix login redirect loop"
git commit -m "Identify root cause of #42"
git commit -m "Implement fix for redirect loop (#42)"
git commit -m "Add regression tests"

# After merge, PR description shows: "Resolves #42"
```

### Example 2: Feature with Multiple Issues

```bash
# PR description: "Implements dark mode (closes #99)"
git commit -m "Add theme toggle UI"
git commit -m "Implement dark theme styles (#99)"
git commit -m "Fix contrast issues from #100"

# After merge, PR description shows:
# "Resolves #99"
# "Resolves #100"
```

### Example 3: No Issue Reference

```bash
# PR title: "Update dependencies"
git commit -m "Bump packages to latest"
git commit -m "Update lockfile"

# After merge: No change (workflow skips gracefully)
# Output: "No issue numbers found - this is expected"
```

## Checking Workflow Results

After your PR merges, check the Actions tab to see:

- ✅ What issues were found
- ✅ Where they were found (title/description/commits)
- ✅ Whether the PR description was updated

Look for: `Actions` → `Link Issues After Merge` → View logs
