---
title: git
date: 2018-10-12
---

## git repo

### Permission denied

```
$ git update-index --chmod=+x <files>
$ git commit
```

## git patch

### git format patch

$ git show $(git rev-list -1 --before="2021-12-26" HEAD):arm/lib/systemd/system/openvpn-client@.service

$ git cat-file -p 6a3452e7:arm/lib/systemd/system/openvpn-client@.service
$ git show 6a3452e7:arm/lib/systemd/system/openvpn-client@.service

## git branch

### git branch rename

```
git branch -m <OLD> <NEW>
git fetch origin
git branch -u origin/<NEW> <NEW>
git remote set-head origin -a
```

### git commands

git 的命令分低级命令 （称为“plumbing”) 和高级命令（称为“porcelain”），
低级命令的名字一般是两个单词，高级命令则一般是一个单词。

低级命令，直接操作 git 核心的对象如 tree，commit 以及 index 等
高级命令是面向最终用户的，是对 git 命令的包装，提供一些方便的功能比如统计 log。

git 命令可以写成 "git-cmd" 或者 "git cmd"，前者在 PATH 中寻找 "git-cmd"
这个命令并执行之，后者则是执行 git 命令，传入后面的 cmd 等参数，git 这个
程序在 exec-path 中寻找 git-cmd 并执行之，这个 exec-path 可以通过命令行
选项 --exec-path=XXX 或者 GIT_EXEC_PATH 环境变量设置，在安装 git 时它内部
也会保存一个缺省的 exec-path。这个路径列表的语法跟 PATH 一致。git 的这种
exec-path 机制能够让它很方便的加入更多的命令。

- git init-db               # 在当前目录下创建 git 库 (.git)
- git-update-index          # 更新 index, 把文件写入库中

git merge --no-commit "msg" HEAD test
这个命令的参数语法比较怪异。--no-commit 是让 git 不要马上
提交，这样可以检查一下合并结果是否正确，由于这段时间主干上
没有修改，所以这个合并其实就是 fast forward，直接将
master 指向 test 分支的 HEAD，不会创建新的 commit。

如果不是 fast forward，可以用 git diff 检查一下然后再 git commit；如果合并后有冲突，git 会把冲突标记写入文件，
这个时候打开这个文件编辑之，解决冲突后用 git-update-index
更新 index，然后 git commit。


#### Error 500

tail -f apps/gitlab/htdocs/log/production.log
Started GET "/users/sign_in" for 10.10.50.201 at 2016-01-06 15:27:29 +0800
Processing by SessionsController#new as HTML
Completed 500 Internal Server Error in 101ms (ActiveRecord: 3.3ms)

ActionView::Template::Error (Inconsistent indentation: 2 tabs used for indentation, but the rest of the document was indented using 2 spaces.):
    20:    %h3 builds a networking operating system™, for software-defined networking
    21:
    22:    %p
    23:     a Linux-based operating system (OS) that transforms a white box switch into a tunable platform, helping customers build differentiated services while eliminating hardware lock in.
    24:     extensive support for traditional switching and routing protocols with a rich Layer-2 and Layer-3 protocol stack, command-line configuration, automation, and support for full SDN programmability.
    25:
    26:     - if extra_sign_in_text.present?
  app/views/layouts/devise.html.haml:23
  app/controllers/sessions_controller.rb:15:in `new'

#### Must in htdocs path?

/opt/gitlab8/apps/gitlab/htdocs/app/views# RAILS_ENV=production bundle exec rake assets:precompile
(in /opt/gitlab8/apps/gitlab/htdocs)

### How does Git calculate the SHA1 digest for a blog object

SHA1 is not a simple 40 bit sha1 result of the file.

$ git hash-object foo.txt
f70f10e4db19068f79bc43844b49f3eece45c4e8

$ openssl sha1 foo.txt
SHA1(foo.txt)= 7d157d7c000ae27db146575c08ce30df893d3a64

$ echo -n hello | git hash-object --stdin
b6fc4c620b67d95f953a5c1c1230aaab5db5a1b0

$ printf 'blob 5\0hello' > test.txt
$ openssl sha1 test.txt
SHA1(test.txt)= b6fc4c620b67d95f953a5c1c1230aaab5db5a1b0

sha1("blob " + filesize + "\0" + data)

Note that "\0" is the NULL.

For example, the hash of an empty file:

sha1("blob 0\0") = "e69de29bb2d1d6434b8b29ae775ad8c2e48c5391"

$ touch empty
    git hash-object empty
e69de29bb2d1d6434b8b29ae775ad8c2e48c5391

Another example:

sha1("blob 7\0foobar\n") = "323fae03f4606ea9991df8befbb2fca795e648fa"

$ echo "foobar" > foo.txt
    git hash-object foo.txt
323fae03f4606ea9991df8befbb2fca795e648fa

Here is a Python implementation:

from hashlib import sha1
def githash(data):
    s = sha1()
    s.update("blob %u\0" % len(data))
    s.update(data)
    return s.hexdigest()

echo -en "blob ${#CONTENTS}\0$CONTENTS" | sha1sum

As a result if a file moves from one repository to another the SHA1 for the file remains the same as its contents have not changed.

- How the SHA-1 is generated for a commit
    - git cat-file -p HEAD # Same to `git cat-file commit HEAD`
    - git rev-parse HEAD

    (echo -n "commit"; echo -n `git cat-file -p HEAD | wc -c`; printf "\000"; git cat-file -p HEAD) | sha1sum

- blob object

    - git rev-parse HEAD:Makefile

(echo -n "blob "; echo -n `git cat-file -p HEAD:Makefile | wc -c`; printf "\000"; git cat-file -p HEAD:Makefile) | sha1sum

- tree object

    * git cat-file -p HEAD^{tree} # Not equal to `git cat-file tree HEAD^{tree}`
    * git rev-parse HEAD^{tree}

(echo -n "tree "; echo -n `git cat-file tree HEAD^{tree} | wc -c`; printf "\000"; git-cat file tree HEAD^{tree}) | sha1sum

### How to diff one file to an arbitrary version in Git?

git diff master~20:pom.xml pom.xml

. to compare your current pom.xml to the one from master 20 revisions ago through the first parent. You can replace master~20, of course, with the object name (SHA1sum) of a commit or any of the many other ways of specifying a revision.

Note that this is actually comparing the old pom.xml to the version in your working tree, not the version committed in master. If you want that, then you can do the following instead:

git diff master~20:pom.xml master:pom.xml

git diff <revision> <path>


https://www.kernel.org/pub/software/scm/git/docs/git-rev-parse.html#_specifying_revisions

Here is a perl script that prints out git diff commands for a given file as found in a git log command.

e.g.

git log pom.xml | perl gldiff.pl 3 pom.xml

Yields:

git diff 5cc287:pom.xml e8e420:pom.xml
git diff 3aa914:pom.xml 7476e1:pom.xml
git diff 422bfd:pom.xml f92ad8:pom.xml

which could then be cut N pasted in a shell window session or piped to /bin/sh.

Notes:

    the number (3 in this case) specifies how many lines to print
    the file (pom.xml in this case) must agree in both places (you could wrap it in a shell function to provide the same file in both places) or put it in a bin dir as a shell script

Code:

### gldiff.pl
use strict;

my $max  = shift;
my $file = shift;

die "not a number" unless $max =~ m/\d+/;
die "not a file"   unless -f $file;

my $count;
my @lines;

while (<>) {
    chomp;
    next unless s/^commit\s+(.*)//;
    my $commit = $1;
    push @lines, sprintf "%s:%s", substr($commit,0,6),$file;
    if (@lines == 2) {
    printf "git diff %s %s\n", @lines;
    @lines = ();
    }
    last if ++$count >= $max *2;


### Changing git commit message after push (given that no one pulled from remote)

    git commit --amend -m "New commit message"

The --force-with-lease option is the safest, because it will abort if there are any upstream changes.

    git push --force-with-lease <repository> <branch>

It should be noted that if you use push --force with mutiple refs, they will ALL be modified as a result.

    Note that --force applies to all the refs that are pushed, hence using it with push.default set to matching or with multiple push destinations configured with remote.*.push may overwrite refs other than the current branch (including local refs that are strictly behind their remote counterpart).

    To force a push to only one branch, use a + in front of the refspec to push
    git push <repository> +<branch>

The -f / --force option means "this command will delete data, and I know what I'm doing." Before you type -f at any command prompt you should reflect for a moment to think about what data this command will delete and make sure that you actually want to delete it.



### git clone

```
$ git clone https://github.com/git/git
Cloning into 'git'...
POST git-upload-pack (gzip 41165 to 20747 bytes)
remote: Enumerating objects: 316947, done.
remote: Counting objects: 100% (330/330), done.
remote: Compressing objects: 100% (132/132), done.
remote: Total 316947 (delta 212), reused 294 (delta 198), pack-reused 316617
Receiving objects: 100% (316947/316947), 173.39 MiB | 133.00 KiB/s, done.
Resolving deltas: 100% (236590/236590), done.
Submodule 'sha1collisiondetection' (https://github.com/cr-marcstevens/sha1collisiondetection.git) registered for path 'sha1collisiondetection'
Cloning into '/home/aaron/git/sha1collisiondetection'...
fatal: unable to access 'https://github.com/cr-marcstevens/sha1collisiondetection.git/': Operation timed out after 300002 milliseconds with 0 out of 0 bytes received
fatal: clone of 'https://github.com/cr-marcstevens/sha1collisiondetection.git' into submodule path '/home/aaron/git/sha1collisiondetection' failed
Failed to clone 'sha1collisiondetection'. Retry scheduled
Cloning into '/home/aaron/git/sha1collisiondetection'...
remote: Enumerating objects: 892, done.
remote: Counting objects: 100% (3/3), done.
remote: Compressing objects: 100% (3/3), done.
remote: Total 892 (delta 0), reused 1 (delta 0), pack-reused 889
Receiving objects: 100% (892/892), 610.37 KiB | 1.83 MiB/s, done.
Resolving deltas: 100% (567/567), done.
Submodule path 'sha1collisiondetection': checked out '855827c583bc30645ba427885caa40c5b81764d2'
Submodule path 'sha1collisiondetection': checked out '855827c583bc30645ba427885caa40c5b81764d2'
```

### git config

```
git config --local status.showUntrackedFiles no
```

## git stash

### Stash untracked files as well

```
$ stash --include-untracked
$ stash -u
```

### How to stash only part of the files

Let's say we have made changes to two files (X and Y) and we would like to stash one of them (X)

```
$ git add Y
$ git stash --keep-index
$ git reset HEAD Y
```

### Undo last commit

```
$ git reset --soft HEAD~

$ git commit ...
$ git reset --soft HEAD^
$ edit
$ git add ....
$ git commit -c ORIG_HEAD
```

### Undo git reset

```
$ git reset HEAD~

$ git reset HEAD@{1}

$ git reflog    # to list the history of HEAD
```

### git bisect - finding bugs

* Notice a bug that you recall was working earlier. (but apparently there were no automated tests checking it)
* Task: find the change that broke it

* Find an old commit where it was still working.
* Binary search the commit since then to locate the breaking change.

Preferably write an automated test that can verify the feature. Put it in a separate test file in the workspace.


```
$ git checkout master
$ git bisect start
$ git bisect bad
$ git checkout sha1-that-is-known-to-be-good
$ git bisect good
...
```
