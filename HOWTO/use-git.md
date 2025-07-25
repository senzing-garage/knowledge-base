# Basic git operations on the command line

## Clone a Repository

To check-out a repository that you will be committing code to, it is best to clone it. A repository can be cloned into the current directory with the following command.

```console
git clone git@github.com:Senzing/knowledge-base.git
```

## See Current Status of Cloned Repository

This will list pending changelist as well as added/changed/deleted items

```console
git status
```

## Update Current Branch

```console
git pull
```

## Add an Item to the Pending Changelist

```console
git add <filename>
```

## See the Diff of Pending Changelist

```console
git diff
```

## Commit the Pending Changelist

Note: You want to make sure your repository is synced to github before committing your changelist to avoid a merge

```console
git commit
```

This will open a text editor for you to comment the changelist

You should now push this committed change to github so others can pull it

```console
git push
```

## See Local Branches in the Repository

This will show the branches of the repository you have checked out, and which branch is currently active locally

```console
git branch
```

## See All Remote Branches in the Repository

This will show all the remote branches available for checkout
first make sure you local repository is in sync with the origin:

```console
git fetch origin
```

then list branches:

```console
git branch -v -a
```

## Switch branches

```console
git checkout <branch_name>
```

You can also use

```console
git switch <branch_name>
```

## Create a new remote branch

First create the branch locally, then push it to github

```console
git checkout -b <branch_name>
git push origin <branch_name>
git branch --set-upstream-to=origin/<branch_name> <branch_name>
```

## Merge changes in main to current branch

In repositories created after October 2020, the "main" branch is used.

```console
GIT_CURRENT_BRANCH=$(git rev-parse --abbrev-ref HEAD)
git checkout main
git pull
git checkout ${GIT_CURRENT_BRANCH}
git merge origin/main
git push
```

## Merge changes in main to current branch

In repositories created before October 2020, the "master" branch is used.
However, they've since been migrated to "main" in May 2022.

```console
GIT_CURRENT_BRANCH=$(git rev-parse --abbrev-ref HEAD)
git checkout main
git pull
git checkout ${GIT_CURRENT_BRANCH}
git merge origin/main
git push
```

## Delete a remote branch

first delete it locally

```console
git branch -d <branch_name>
```

then delete it on github

```console
git push origin --delete <branch_name>
```

# Help! I tried to commit to main, now what?

No problem, we got you.
Make sure you are on the branch to which you have been committing.
`git log` to check how many commits you want to roll back.
undo the commits with git reset HEAD~N where “N” is the number of commits you want to undo.

eg, to undo one commit:

```console
git reset HEAD~1
```

now create your branch, switch to it, and continue on as if that didn't happen.
Do be sure to verify that you're only committing the changes you want with `git status`

# Help! Git is prompting me for my password, now what?

View the existing remote repository URL and verify it was cloned using `https://`:

```console
git remote -v
```

Example output:

```
git remote -v
origin	https://github.com:<ORGANIZATION>/<REPOSITORY_NAME>.git (fetch)
origin	https://github.com:<ORGANIZATION>/<REPOSITORY_NAME>.git (push)
```

Change the remote repository URL. 
Update the values for github organization and repository name in the following:

```console
git remote set-url origin git@github.com:<ORGANIZATION>/<REPOSITORY_NAME>.git
```

# One time configuration for your git command line

## set up globals

Set up your name and email

```console
git config --global user.name "Your Name"
git config --global user.email your_git_email@email.com
```

Prune deleted branches from your local when you pull

```console
git config --global fetch.prune true
```

## Block command line pushes that expose your personal email address

1. [Change the GitHub settings to keep your email address private]
2. [Set your email address in Git to the noreply email address generated by GitHub]
3. Test pushing a commit to validate settings changes.

## Sign commits locally

Prerequisite: [Install GnuPG]

NOTE: The following steps have been tested on OSX and Linux.<br />
If you encounter issues please refer to the respective GitHub documentation linked in the Additional Resources section below.

1. Generate a new GPG key.

   - NOTES
     - [Your GPG key must be associated with a GitHub verified email that matches your committer identity]
     - [Supported GPG Key Algorithms]

   1. Open Terminal / Git Bash.
   1. Generate a GPG key pair.

      ```console
      gpg --full-generate-key
      ```

      1. When prompted input the number corresponding to the kind of key and press `Enter`.
         - Recommended input: `ECC (sign and encrypt)`.
           - If using ECC, input the number corresponding to the elliptic curve and press `Enter`.
           - Recommended input: `Curve 25519`.
         - If ECC is unavailable you can use `RSA and RSA`.
           - Recommended key size: `4096`
      1. Input the length of time the key should be valid and press `Enter`.
         - Recommended input: `1y`.
      1. Verify your selections are correct.
      1. Input your name and press `Enter`.
      1. Input your email address and press `Enter`.
      1. Optionally input a comment and press `Enter`.
      1. Verify your selections, input `O` and press `Enter`.
      1. Type a secure passphrase.
         - NOTE: You will be prompted for this passphrase when running `git commit`<br />
           The default cache for this passphrase is typically 2 hours.<br />
           See links in additional details for changing default caching values.

   1. List the long form of the GPG keys.

      ```console
      gpg --list-secret-keys --keyid-format=long
      ```

   1. From the list of GPG keys, copy the long form of the GPG key ID you'd like to use.<br />
      In this example, the GPG key ID is `3AA5C34371567BD2`:

      ```console
      $ gpg --list-secret-keys --keyid-format=long
      /Users/hubot/.gnupg/secring.gpg
      ------------------------------------
      sec   4096R/3AA5C34371567BD2 2016-03-10 [expires: 2017-03-10]
      uid                          Hubot <hubot@example.com>
      ssb   4096R/4BB6D45482678BE3 2016-03-10
      ```

1. Configure Git to use the key generated in the previous step.

   1. Open Terminal / Git Bash.
   1. Unset any existing git signing key format.

      ```console
      git config --global --unset gpg.format
      ```

   1. Use the long form of the GPG key ID from Step 1.iv above to set your primary GPG signing key in Git.<br />
      In this example, the GPG key ID is `3AA5C34371567BD2`:

      ```console
      git config --global user.signingkey 3AA5C34371567BD2
      ```

   1. Configure Git to sign all commits by default.

      ```console
      git config --global commit.gpgsign true
      ```

1. Add the GPG key to GitHub.

   1. Open Terminal / Git Bash.
   1. Use the long form of the GPG key ID from Step 1.iv above to export your public GPG key.

      - Paste the text below, substituting in the GPG key ID you'd like to use.<br />
        In this example, the GPG key ID is `3AA5C34371567BD2`:

        ```console
         gpg --armor --export 3AA5C34371567BD2
         # Prints the GPG key ID, in ASCII armor format
        ```

   1. Copy your GPG key, beginning with `-----BEGIN PGP PUBLIC KEY BLOCK-----` and ending with `-----END PGP PUBLIC KEY BLOCK-----`.
   1. Login to the GitHub UI.
   1. In the upper-right corner of any page, click your profile photo, then click `Settings`.
   1. In the "Access" section of the sidebar, click `SSH and GPG keys`.
   1. Next to the "GPG keys" header, click `New GPG key`.
   1. In the `Title` field, type a name for your GPG key.
   1. In the `Key` field, paste the GPG key you copied in Step 3.iii above.
   1. Click `Add GPG key`.

1. [Checking your commit and tag signature verification status].
1. Optional: Use gpg-agent flags for configuring default caching for authentication or preset passphrase.
   - See links in Additional Resources below.

### Troubleshooting

Error:

```console
gpg: signing failed: No such file or directory

fatal: failed to write commit object
```
or 
```
Inappropriate ioctl for device
```

Ensure `GPG_TTY` is configured in the environment.
See [Configure TTY] for more details.

Error:

After migrating from one Mac to another, using the Apple migration tool. You may encounter a signing issue.

```console
error: gpg failed to sign the data:
gpg: Note: database_open 134217901 waiting for lock (held by 41497) ...
...
gpg: signing failed: Operation timed out

fatal: failed to write commit object
```

To fix this find the lock file and the remove it.

```console
ls -l ~/.gnupg/**/*.lock
rm <path to file>/<filename>.lock
```

### Additional Resources

- [Generate a new GPG key]
- [Configure git to use a gpg key]
- [Adding a GPG key to GitHub]
- [Checking your commit and tag signature verification status]
- [GPG Agent passphrase caching]

[Adding a GPG key to GitHub]: https://docs.github.com/en/authentication/managing-commit-signature-verification/adding-a-gpg-key-to-your-github-account
[Change the GitHub settings to keep your email address private]: https://docs.github.com/en/account-and-profile/setting-up-and-managing-your-personal-account-on-github/managing-email-preferences/blocking-command-line-pushes-that-expose-your-personal-email-address
[Checking your commit and tag signature verification status]: https://docs.github.com/en/authentication/troubleshooting-commit-signature-verification/checking-your-commit-and-tag-signature-verification-status#checking-your-commit-signature-verification-status
[Configure git to use a gpg key]: https://docs.github.com/en/authentication/managing-commit-signature-verification/telling-git-about-your-signing-key
[Configure TTY]: https://github.com/senzing-garage/knowledge-base/blob/main/WHATIS/gnupg.md#configure-tty
[Generate a new GPG key]: https://docs.github.com/en/authentication/managing-commit-signature-verification/generating-a-new-gpg-key
[Install GnuPG]: https://github.com/senzing-garage/knowledge-base/blob/main/WHATIS/gnupg.md
[Set your email address in Git to the noreply email address generated by GitHub]: https://docs.github.com/en/account-and-profile/setting-up-and-managing-your-personal-account-on-github/managing-email-preferences/setting-your-commit-email-address#setting-your-commit-email-address-in-git
[GPG Agent passphrase caching]: https://www.gnu.org/software/emacs/manual/html_node/pgg/Caching-passphrase.html
[Supported GPG Key Algorithms]: https://docs.github.com/en/authentication/managing-commit-signature-verification/generating-a-new-gpg-key#supported-gpg-key-algorithms
[Your GPG key must be associated with a GitHub verified email that matches your committer identity]: https://docs.github.com/en/authentication/troubleshooting-commit-signature-verification/using-a-verified-email-address-in-your-gpg-key
