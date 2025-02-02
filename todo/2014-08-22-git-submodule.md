


# Issues

```
git pull --rebase --recurse-submodules && git submodule update --init
fatal: not a git repository: /home/aaron/repo/.git/modules/subrepo
```

Cause: The repo had been moved.

Solution: Edit /path/to/repo/path/to/subrepo/.git, update to the current path.
