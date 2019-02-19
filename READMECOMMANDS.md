# Git Commands & Bash Commands

## Getting & Creating Projects
| Git Command  | Description |
| ------------- | ------------- |
| `git init`  | Initialize a local Git Repository |
| `git clone git@github.com:[username]/[RepositoryName].git`  | Create a local copy of a remote repository |

Make sure you are in the directory of the project 

## Committing Files
| Git Command | Description |
| `git status` | Check status |
| `git add .` | Stages all the files in the current directory |
| `git add *.[extension]` | Adds all files with the specific extension |
| `git add -A` | Add all new and changed files to the staging area |
| `git commit -m "[commit message]"` | Commit changes |
| `ls` | List files in the directory |
| `git rm -r [file-name.extension]` | Remove a file (or folder) |

## Branching & Merging
| Git Command | Description |
| `git branch` | List branches |
| `git branch -a` | List all branches (local and remote) |
| `git checkout -b [new branch]` | Creates and checks out new branch |
| `git checkout -b [new branch] [existing branch]` |  Renames branch on local |
| `git checkout [branch name]` | Switch branches |
| `git branch -d [branch name]` | Delete branch *cannot be in that branch during deletion* |
| `git push -u origin [branch name]` | Push changes to that branch |
| `git merge [branch name]` | Merge a branch into the active branch |
| `git merge [source branch] [target branch]` | Merge a branch into a target branch |
| `git stash` | Stash changes in a dirty working directory |
| `git stash clear` | Remove all stashed entries |

## Sharing & Updating Projects 
| Git Command | Description |
| `git push origin [branch name]` | Push a branch to your remote repository |
| `git push -u origin [branch name]` | Push changes to remote repository (and remember the branch) |
| `git push` | Push changes to remote repository (remembered branch) |
| `git push origin --delete [branch name]` | Delete a remote branch |
| `git pull` | Update local repository to the newest commit |
| `git pull origin [branch name]` | Pull changes from remote repository |

## Generate a new SSH key and adding it to the ssh-agent
(No need to enter username and password to SSH into your GitHub)
Provides authentication for your computer 
[Instructions](https://help.github.com/articles/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent/)

> Pull -> Make Changes -> Add -> Commit -> Push
> If you push to your branch -> Create a Pull Request -> Request must get reviewed -> After review it can get merged into master

| Terminal Command  | Description |
| ------------- | ------------- |
| `ls` | Lists the folder and file names in the current working directory |
| `cd` | Change Directory to the path specified |
| `.` | Current directory |
| `..` | Previous directory |
| `/` | Root of your system |
| `~` | Home directory |
| `mkdir [directory name]` | Make directory |
| `touch [file name]` | Create an empty file |
|   |   |
|   |   |
|   |   |
|   |   |
|   |   |
|   |   |
|   |   |
|   |   |
|   |   |
|   |   |
