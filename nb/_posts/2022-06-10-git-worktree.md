
```sh
$ git worktree add -b 4.3.0 ../4.3.0 4.3.0-alpha
Preparing worktree (new branch '4.3.0')
Updating files: 100% (76100/76100), done.
HEAD is now at 2b53e51178 ....

$ git worktree add ../4.3.0-alpha 4.3.0-alpha
Preparing worktree (checking out '4.3.0-alpha')
Updating files: 100% (76100/76100), done.
HEAD is now at 2b53e51178 ....
```

git diff-tree --no-commit-id --name-only -r HEAD~

git cat-file -p HEAD~:./README


$ git log --follow [file]

$ git diff [first-branch]...[second-branch]

$ git reset [commit]
