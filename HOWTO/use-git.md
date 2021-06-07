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
git checkout master
git pull
git checkout ${GIT_CURRENT_BRANCH}
git merge origin/master
git push
```

## Merge changes in master to current branch

In repositories created before October 2020, the "master" branch is used.

```console
GIT_CURRENT_BRANCH=$(git rev-parse --abbrev-ref HEAD)
git checkout master
git pull
git checkout ${GIT_CURRENT_BRANCH}
git merge origin/master
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

# Help!  I tried to commit to main, now what?

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
