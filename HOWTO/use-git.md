# Basic git operations on the command line

## Clone a Repository

To check-out a repository that you will be committing code to, it is best to clone it.  A repository can be cloned into the current directory with the following command.

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

Note:  You want to make sure your repository is synced to github before commiting your changelist to avoid a merge

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

## Create a new remote branch

First create the branch locally, then push it to github

```console
git checkout -b <branch_name>
git push origin <branch_name>
git branch --set-upstream-to=origin/<branch_name> <branch_name>
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
