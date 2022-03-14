---
title: Git
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

你会发现 `README.md` 同时处于暂存区和非暂存区。实际上，是否处于暂存区是对于更改而言的，而不是对于文件而言的，所以对 `README.md` 的前一次更改已被纳入暂存区，而后一次更改还没有。如果这时候执行 `git commit` 命令，只有处于暂存区的更改会被提交，而非暂存区的更改，则不会被提交。

Git 给了一条提示，执行 `git add README.md` 就可以将非暂存区的更改放入暂存区了。

???+note "一次性将所有更改放入暂存区"
    `git add` 命令会将对指定的文件的更改放入暂存区中。

    在多数情况下，用户更期望一次性将所有更改都放入暂存区中，这时候可以应用 `git add -A` 命令。该命令会将所有更改（包括未被纳入版本跟踪的文件，不包括被忽略的文件）放入暂存区。

    如果只需更新已被纳入版本跟踪的文件，而不将未纳入版本跟踪的文件加入暂存区，可以使用 `git add -u`。

???+note "忽略文件"
    有些时候我们并不希望将一些文件（如可执行文件等）纳入到版本跟踪中。这时候可以在仓库根目录下创建 `.gitignore` 文件，在该文件里写下想要忽略的文件。Git 将不会将这些文件纳入到版本跟踪中。

    例如，`*.exe` 将自动忽略仓库里的所有扩展名为 `.exe` 的文件。

现在将非暂存区的文件加入暂存区，将所有更改一并提交（commit）。

```bash
$ git add README.md
$ git commit # 接下来会弹出编辑器页面，你需要写下 commit 信息
[master (root-commit) f992763] initial commit
 1 file changed, 2 insertions(+)
 create mode 100644 README.md
```

现在重点观察一下这一次 commit 的信息。

`master` 表示当前位于 `master` 分支（关于分支的问题，下文将会详细介绍），`b13c84e` 表示本次提交的 SHA-1 校验和的前几位，后面则是本次提交的信息。

需要特别关注的是这里的 SHA-1 校验码，每个校验码都与某个时刻仓库的一个快照相对应。利用这一特性我们可以访问历史某个时刻的仓库快照，并在该快照上进行更改。

接下来两行则详细说明了本次更新涉及的文件更改。

另外，commit 过程中可以利用几个参数来简化提交过程：

- `-a`：在提交前将所有已跟踪的文件的更改放入暂存区。需要注意的是未被跟踪的文件（新创建的文件）不会被自动加入暂存区，需要用 `git add` 命令手动添加。
- `-m`：该参数后跟提交信息，表示以该提交信息提交本次更改。例如 `git commit -m "fix: typo"` 会创建一条标题为 `fix: typo` 的 commit。

### 查看提交记录

使用 `git log` 命令可以查看仓库的提交历史记录。

可以看到，提交历史里记录了每次提交时的 SHA-1 校验和，提交的作者，提交时间和 commit 信息。

```bash
$ git log
commit ae9dd3768a405b348bc6170c7acb8b6cb5fe333e (HEAD -> master)
Author: OI Wiki <oi-wiki@example.com>
Date:   Sun Sep 13 00:30:18 2020 +0800

    feat: update README.md

commit f99276362a3c260d439364c505a7a06859f34bf9
Author: OI Wiki <oi-wiki@example.com>
Date:   Sun Sep 13 00:06:07 2020 +0800

    initial commit
```

## 分支管理

为什么版本管理中需要分支管理呢？答案主要有两点：

1. 直接更改主分支不仅会使历史记录混乱，也可能会造成一些危险的后果。
2. 通过分支，我们可以专注于当前的工作。如果我们需要完成两个不同的工作，只需开两个分支即可，两个分支间的工作互不干扰。

在 Git 中，简单来说，分支就是指向某个快照的指针。每次提交时，Git 都会为这次提交创建一个快照，并将当前分支的指针移动到该快照。

另外还有一个 HEAD 指针，它指向当前所在的分支。

切换分支的过程，简单来说就是将 HEAD 指针，从指向当前所在的分支，改为指向另外一个分支。在这一过程中，Git 会自动完成文件的更新，使得切换分支后仓库的状态与目标分支指向的快照一致。

### 分支的创建

利用 `git branch` 命令可以创建分支，`git switch` 命令可以切换分支，`git switch -c` 命令可以创建分支并切换到这个新分支。

```bash
$ git switch -c dev # 创建一个叫做 dev 的新分支并切换当前分支到 dev
Switched to branch 'dev'
$ git branch # 查看分支列表
  master
* dev
```

`dev` 前面的星号代表该仓库的当前分支为 `dev`，接下来对这个仓库的更改都将记录在这个分支上。

试着创建一个新文件 `aplusb.cpp`。

```bash
$ vim aplusb.cpp
$ git add aplusb.cpp
$ git commit -m "feat: add A+B Problem code"
[dev 5da093b] feat: add A+B Problem code
 1 file changed, 7 insertions(+)
 create mode 100644 aplusb.cpp
```

现在切换回 `master` 分支，这时候文件夹中没有了 `aplusb.cpp`，一切都回到了刚刚创建 `dev` 分支时的状态。这时候可以在 `master` 分支上继续完成其他的工作。

```bash
$ git switch master
Switched to branch 'master'
$ vim README.md # 对 README 做些小改动
$ git commit -a -m "feat: update README.md"
[master 5ca15f0] feat: update README.md
 1 file changed, 1 insertion(+), 1 deletion(-)
```

下面用一张图来解释刚才的操作过程。

![](./images/git1.png)

`master` 分支被标红，表明在这几次操作后，它是当前分支（即 HEAD 指向的位置）。

- 最开始时 `master` 指向 `ae9dd37` 这一快照。
- 接下来在 `master` 所在的位置创建了一个新的 dev 分支，该分支一开始和 master 指向相同位置。
- 在 `dev` 分支上作了一些更改（创建了 `aplusb.cpp`），进行了一次提交，本次提交后，`dev` 分支指向 `5da093b` 这一快照。
- 切换回 `master` 分支后，因为 `master` 分支还指向 `ae9dd37`，还没有创建 `aplusb.cpp`，因此仓库中没有这一文件。
- 接下来在 `master` 分支上进行更改（更新了 `README.md`），进行了一次提交，`master` 分支指向了 `5ca15f0` 这一快照。

### 分支的合并

当一个分支上的工作已经完成，就可以将这些工作合并到另外一个分支上去。

还是接着上面这个例子，`dev` 分支的工作已经完成，通过 `git merge` 命令可以将该分支合并到当前分支（`master`）上：

```bash
$ git merge dev
Merge made by the 'recursive' strategy.
 aplusb.cpp | 7 +++++++
 1 file changed, 7 insertions(+)
 create mode 100644 aplusb.cpp
```

![](./images/git2.png)

这次合并具体是怎么执行的呢？

在合并之前，`master` 指向 `5ca15f0`，而 `dev` 指向 `5da093b`，这两个状态并不在一条链上。

Git 会找到这两个状态的最近公共祖先（在上图中是 `ae9dd37`），并对这三个快照进行一次合并。三个快照合并的结果作为一个新的快照，并将当前分支指向这一快照。

合并过程本身也是一次提交，不过与常规提交不同的是，合并提交有不止一个前驱提交，它是多个提交状态合并后的结果。

在合并完成后，`dev` 分支就完成了它的使命，这时候可以利用下面的命令删除 `dev` 分支：

```bash
$ git branch -d dev # 对于未合并的分支，可以使用 -D 参数强制删除
```

不过合并过程并非总是这么顺利，在某些情况下，合并过程可能会出现冲突，这个问题接下来会讲到。

### 解决合并冲突

如果在两个分支中，对同一个文件的同一部分进行了不同的更改，Git 就无法自动合并这两个分支，也就是发生了合并冲突。

接着上面的例子，假如你在合并后的 `master` 分支的基础上，新开了一个 `readme-refactor` 分支，准备重写一份自述文件。但因为一些疏忽，你同时更改了 `readme-refactor` 和 `master` 分支的自述文件。

刚开始自述文件是这样的：

```markdown
# This is a test repo.

This repo includes some c++ codes.
```

在 `readme-refactor` 分支下的自述文件是这样的：

```markdown
# Code Library

This repo includes some c++ codes.
```

在 `master` 分支下的自述文件是这样的：

```markdown
# This is a code library.

This repo includes some c++ codes.
```

这时候运行 `git merge readme-refactor` 命令，Git 提示出现了合并冲突。

执行一下 `git status` 命令，可以查看是哪些文件引发了冲突。

```bash
$ git status
On branch master
You have unmerged paths.
  (fix conflicts and run "git commit")

Unmerged paths:
  (use "git add <file>..." to mark resolution)

    both modified:      README.md

no changes added to commit (use "git add" and/or "git commit -a")
```

如何解决冲突？对于每个发生了合并冲突的文件，Git 都会在这些文件中加入标准的冲突解决标记。比如这个例子中的 `README.md` 文件，打开后它长这个样子：

```markdown
<<<<<< HEAD
# This is a code library.
======
# Code Library
>>>>>> readme-refactor

This repo includes some c++ codes.
```

`======` 作为分界线将两个分支的内容隔开，`<<<<<< HEAD` 标记和 `======` 之间的部分是 HEAD 指针（`master` 分支）的内容，而 `======` 和 `>>>>>> readme-refactor` 标记之间的部分是 `readme-refactor` 分支的内容。

通过编辑文本来处理冲突，删除这些冲突标记，保存文件，将这些文件纳入暂存区后提交，就可以解决合并冲突了。

```bash
$ git add README.md # 将发生冲突的文件纳入暂存区
$ git commit
[master fe92c6b] Merge branch readme-refactor into master
```

### 其他合并方式

默认情况下，Git 采用 Merge（合并）的方式合并两个分支。使用该方法将分支 B 并入分支 A 时，会将 B 分支的所有 commit 并入 A 分支的提交历史中。

除此以外，Git 还提供了两种合并分支的方式：Squash（压缩）和 Rebase（变基）。

#### Squash（压缩）

使用 Squash 方式将分支 B 并入分支 A 时，在 B 分支上的所有更改会被合并为一次 commit 提交到 A 分支。

在 `git merge` 中加入 `--squash` 参数即可使用 Squash 方式进行分支合并。

```bash
git merge <branch> --squash
```

需要注意的是，在执行上述命令后，Git 只会将 B 分支的所有更改存入 A 分支的缓冲区内，接下来还需要执行一次 `git commit` 命令完成合并工作。

使用 Squash 方式合并可以简化 commit 记录，但是会丢失具体到每一次 commit 的信息（每次 commit 的提交者，每次 commit 的更改等等），只留下合并为一个整体的信息（每次 commit 的提交者会以 "Co-authored-by" 的形式在提交信息中列出）。但如果是在 GitHub 上进行 Squash and Merge，原有的信息都可以在 Pull Request 中查看。

#### Rebase（变基）

使用 Rebase 方式将分支 B 并入分支 A 时，在 B 分支上的每一次 commit 都会单独添加到 A 分支，而不再像 Merge 方式那样创建一个合并 commit 来合并两个分支的内容[^note4]。

首先，切换到 B 分支，接下来将 B 分支变基到 A 分支：

```bash
git checkout B
git rebase A
```

现在切回到 A 分支，再执行一次 `git merge` 命令，即可完成将 B 分支的内容合并到 A 分支的工作。

```bash
git checkout A
git merge B
```

使用 Rebase 完成合并可以让提交历史线性化，在适当的场景下正确地使用 Rebase 可以达到比 Merge 更好的效果。但是这样做会改变提交历史，在进行 Rebase 时和 Rebase 后再进行相关合并操作时都会增加出现冲突的可能，如果操作不当可能反而会使提交历史变得杂乱。因此，如果对 Rebase 操作没有充分的了解，不建议使用。

## 管理远程仓库

在本地完成更改后，你可能会需要将这些更改推送到 GitHub 等 Git 仓库托管平台上。托管在这些平台上的仓库就归属于远程仓库的范畴——你可以从这些仓库中获取信息，也可以将你作出的更改推送到远程仓库上。与其他人的协作往往离不开远程仓库，因此学会管理远程仓库很有必要。

### 远程仓库的查看

使用 `git remote` 命令可以查看当前仓库的远程仓库列表。

如果当前仓库是克隆来的，那么应该会有一个叫做 origin 的远程仓库，它的链接就是克隆时用的链接。

```bash
$ git remote
origin
```

如果要查看某个远程仓库的详细信息的话，可以这样操作：

```bash
$ git remote show origin
* remote origin
  Fetch URL: git@github.com:OI-wiki/OI-wiki.git
  Push  URL: git@github.com:OI-wiki/OI-wiki.git
  HEAD branch: master
  Remote branches:
    git             tracked
    master          tracked
  ...

```

### 远程仓库的配置

执行 `git remote add <name> <url>` 命令可以添加一个名字为 `name`，链接为 `url` 的远程仓库。

执行 `git remote rename <oldname> <newname>` 可以将名字为 `oldname` 的远程仓库改名为 `newname`。

执行 `git remote rm <name>` 可以删除名字为 `name` 的远程仓库。

执行 `git remote get-url <name>` 可以查看名字为 `name` 的远程仓库的链接。

执行 `git remote set-url <name> <newurl>` 可以将名字为 `name` 的远程仓库的链接更改为 `newurl`。

### 从远程仓库获取更改

在远程仓库中，其他人可能会推送一些更改，执行 `git fetch` 命令可以将这些更改获取到本地。

```bash
$ git fetch <remote-name> # 获取 <remote-name> 的更改
```

需要注意的是，`git fetch` 命令只会获取远程仓库的更改，而不会将这些更改合并到本地仓库中。如果需要将这些更改进行合并，可以使用 `git pull` 命令。在默认情况下，`git pull` 相当于 `git fetch` 后 `git merge FETCH_HEAD`。

```bash
$ git pull <remote-name> <branch> # 获取 <remote-name> 的更改，然后将这些更改合并到 HEAD
```

### 将更改推送到远程仓库

当你完成了一些更改之后，使用 `git push` 命令可以将这些更改推送到远程仓库。

```bash
$ git push <remote> <from>:<to> # 将本地 <from> 分支的更改推送至 <remote> 的 <to> 分支
```

根据远程仓库的要求，可能会要求你输入远程仓库账户的用户名和密码。

需要注意的是，你的更改能成功推送，需要满足两个条件：你拥有向这个仓库（分支）的写入权限，且你的这个分支比远程仓库的相应分支新（可以理解为没有人在你进行更改的这段时间进行了推送）。当远程分支有当前分支没有的新更改时，可以执行 `git pull` 命令完成合并再提交。

如果你需要强制将本地分支的更改推送到远程仓库的话，可以加入 `-f` 参数。此时 **远程仓库的提交历史会被本地的提交历史覆盖**，因此该命令应谨慎使用。更好的选择是使用 `--force-with-lease` 参数，该参数仅在远程仓库没有更新时才会进行覆盖。需要注意的是，此处“更新”是相对于上一次 fetch 而言的，如果使用了 VS Code 提供的 Auto Fetch 功能，可能会没有注意到更新而使 `--force-with-lease` 和 `-f` 一样危险。

### 追踪远程分支

通过将一个本地分支设定为追踪远程分支，可以方便地查看本地分支与远程分支的差别，并能简化与远程分支交互时的操作。

在开始追踪前，你需要先执行 `git fetch <remote-name>` 将远程仓库的信息抓取到本地。

接下来执行 `git switch <remote-branch>`，会在本地自动创建名字为 `<remote-branch>` 的新分支，并设定该分支自动追踪相应的远程分支。

???+note
    需要注意，只有当本地不存在该分支，且恰好只有一个远程分支的名字与该分支匹配时，Git 才会自动创建该分支且设定其追踪相应的远程分支。

这时候执行 `git status` 命令，会提示当前分支与远程分支之间的差别。

因为设定了本地分支追踪的远程分支，向远程分支推送的命令也被简化了。只需要执行 `git push` 命令，在本地分支上作出的更改就能被推送至其追踪的远程分支。

对于本地已有的分支，设定其对应的远程追踪分支也很容易。只需在当前分支下执行 `git branch -u <remote-name>/<remote-branch>`，就可以设定当前的本地分支追踪 `<remote-name>/<remote-branch>` 这一远程分支。

### 使用 ssh 连接

与 HTTP(S) 相比，使用 ssh 连接到远程仓库更为方便安全。

在使用 ssh 连接到远程仓库之前，需要先在本地添加 ssh 密钥。接下来需要将本地添加的 ssh 密钥的 **公钥** 上传到远程仓库账户。

考虑到本文主要是给 **OI Wiki** 的贡献者提供一个使用 Git 的教程，这里直接给出 [GitHub Docs 提供的教程](https://docs.github.com/cn/github/authenticating-to-github/connecting-to-github-with-ssh)，供各位读者参考。

完成以上步骤后，你就可以通过 ssh 连接到远程仓库了。下面就是一条通过 ssh 连接 clone **OI Wiki** 仓库的命令：

```bash
$ git clone git@github.com:OI-wiki/OI-wiki.git
```

将更改推送至远程仓库的过程与使用 HTTP(S) 连接类似。但使用 ssh 连接可以免去验证远程仓库帐号密码的过程。

## 外部链接

- [Git Reference](https://git-scm.com/docs)
- [Pro Git Book](https://git-scm.com/book/zh/v2)
- [Learn Git Branching](https://learngitbranching.js.org/)

## 参考资料与注释

[^note1]: 在某些地方（比如 [LFS 官网](https://git-lfs.github.com/)）又被称作 Git Large File Storage（大文件存储）。它在将项目托管到平台上时，用文本指针代替音频、视频、图像、数据集等大文件的原始文件，从而加快传输速度。对移动应用程序开发人员、游戏工程师以及任何需要大文件构建软件的人，该功能都极为实用。若想进一步了解该功能，可以参考 [Atlassian 官方介绍 Git LFS 的译文](https://www.cnblogs.com/cangqinglang/p/13097777.html)。

[^note2]: 但是，Git for Windows 对 Vim 的描述是“虽然强大，但是可能会难以使用。用户界面反人类，键位映射卡手。Git 使用 Vim 作为默认编辑器只是出于历史原因，强烈推荐换用一个 UI 设计现代化的编辑器。”，并给“难以使用”加上了 [Stack Overflow 每年帮助一百万名开发者退出 Vim](https://stackoverflow.blog/2017/05/23/stack-overflow-helping-one-million-developers-exit-vim/) 的页面链接。

[^note3]: 事实上 Git 还有一个针对系统上每一个用户及系统上所有仓库的通用配置文件，该配置文件覆盖范围最广，等级在用户配置文件之上。因为该配置实践中较少使用，这里不再展开。

[^note4]: [Pro Git Book](https://git-scm.com/book/zh/v2/Git-%E5%88%86%E6%94%AF-%E5%8F%98%E5%9F%BA) 中提供了可视化的 Rebase 过程图，借助图片读者可以更好地理解 Rebase 的机制。

### 常用命令

| 功能                      | 命令                                  |
|:--------------------------|:--------------------------------------|
| 添加文件/更改到暂存区     | git add filename                      |
| 添加所有文件/更改到暂存区 | git add .                             |
| 提交                      | git commit -m msg                     |
| 从远程仓库拉取最新代码    | git pull origin master                |
| 推送到远程仓库            | git push origin master                |
| 查看配置信息              | git config --list                     |
| 查看文件列表              | git ls-files                          |
| 比较工作区和暂存区        | git diff                              |
| 比较暂存区和版本库        | git diff --cached                     |
| 比较工作区和版本库        | git diff HEAD                         |
| 从暂存区移除文件          | git reset HEAD filename               |
| 查看本地远程仓库配置      | git remote -v                         |
| 回滚                      | git reset --hard 提交SHA              |
| 强制推送到远程仓库        | git push -f origin master             |
| 修改上次 commit           | git commit --amend                    |
| 推送 tags 到远程仓库      | git push --tags                       |
| 推送单个 tag 到远程仓库   | git push origin [tagname]             |
| 删除远程分支              | git push origin --delete [branchName] |
| 远程空分支（等同于删除）  | git push origin :[branchName]         |

### Q&A

#### 如何解决gitk中文乱码，git ls-files 中文文件名乱码问题？

在~/.gitconfig中添加如下内容

```
[core]
   quotepath = false
[gui]
   encoding = utf-8
[i18n]
   commitencoding = utf-8
[svn]
   pathnameencoding = utf-8
```

参考 <http://zengrong.net/post/1249.htm>

#### 如何处理本地有更改需要从服务器合入新代码的情况？

```
git stash
git pull
git stash pop
```

#### 如何合并 fork 的仓库的上游更新？

```
git remote add upstream https://upstream-repo-url
git fetch upstream
git merge upstream/master
```

#### 如何通过 TortoiseSVN 带的 TortoiseMerge.exe 处理 git 产生的 conflict？
* 将 TortoiseMerge.exe 所在路径添加到 `path` 环境变量。
* 运行命令 `git config --global merge.tool tortoisemerge` 将 TortoiseMerge.exe 设置为默认的 merge tool。
* 在产生 conflict 的目录运行 `git mergetool`，TortoiseMerge.exe 会跳出来供你 resolve conflict。

  > 也可以运行 `git mergetool -t vimdiff` 使用 `-t` 参数临时指定一个想要使用的 merge tool。

#### 不想跟踪的文件已经被提交了，如何不再跟踪而保留本地文件？

`git rm --cached /path/to/file`，然后正常 add 和 commit 即可。

#### 如何不建立一个没有 parent 的 branch？

```
git checkout --orphan newbranch
```

此时 `git branch` 是不会显示该 branch 的，直到你做完更改首次 commit。比如你可能会想建立一个空的 gh-pages branch，那么：

```
git checkout --orphan gh-pages
git rm -rf .
// add your gh-pages branch files
git add .
git commit -m "init commit"
```

#### submodule 的常用命令

**添加 submodule**

```
git submodule add git@github.com:philsquared/Catch.git Catch
```

这会在仓库根目录下生成如下 .gitmodules 文件并 clone 该 submodule 到本地。

```
[submodule "Catch"]
path = Catch
url = git@github.com:philsquared/Catch.git
```

**更新 submodule**

```
git submodule update
```

当 submodule 的 remote 有更新的时候，需要

```
git submodule update --remote
```

**删除 submodule**

在 .gitmodules 中删除对应 submodule 的信息，然后使用如下命令删除子模块所有文件：

```
git rm --cached Catch
```

**clone 仓库时拉取 submodule**

```
git submodule update --init --recursive
```

#### 删除远程 tag

```
git tag -d v0.0.9
git push origin :refs/tags/v0.0.9
```

或

```
git push origin --delete tag [tagname]
```

#### 清除未跟踪文件

```
git clean
```

可选项：

| 选项                    | 含义                             |
|-------------------------|----------------------------------|
| -q, --quiet             | 不显示删除文件名称               |
| -n, --dry-run           | 试运行                           |
| -f, --force             | 强制删除                         |
| -i, --interactive       | 交互式删除                       |
| -d                      | 删除文件夹                       |
| -e, --exclude <pattern> | 忽略符合 <pattern> 的文件        |
| -x                      | 清除包括 .gitignore 里忽略的文件 |
| -X                      | 只清除 .gitignore 里忽略的文件   |

#### 忽略文件属性更改

因为临时需求对某个文件 chmod 了一下，结果这个就被记为了更改，有时候这是想要的，有时候这会造成困扰。

```
git config --global core.filemode false
```

参考：[How do I make Git ignore file mode (chmod) changes?](http://stackoverflow.com/questions/1580596/how-do-i-make-git-ignore-file-mode-chmod-changes)

#### patch

将未添加到暂存区的更改生成 patch 文件：

```
git diff > demo.patch
```

将已添加到暂存区的更改生成 patch 文件：

```
git diff --cached > demo.patch
```

合并上面两条命令生成的 patch 文件包含的更改：

```
git apply demo.patch
```

将从 HEAD 之前的 3 次 commit 生成 3 个 patch 文件：

（HEAD 可以换成 sha1 码）

```
git format-patch -3 HEAD
```

生成 af8e2 与 eaf8e 之间的 commits 的 patch 文件：

（注意 af8e2 比 eaf8e 早）

```
git format-patch af8e2..eaf8e
```

合并 format-patch 命令生成的 patch 文件：

```
git am 0001-Update.patch
```

与 `git apply` 不同，这会直接 add 和 commit。

#### 只下载最新代码

```
git clone --depth 1 git://xxxxxx
```

这样 clone 出来的仓库会是一个 shallow 的状态，要让它变成一个完整的版本：

```
git fetch --unshallow
```

或

```
git pull --unshallow
```

#### 基于某次 commit 创建分支

```sh
git checkout -b test 5234ab
```

表示以 commit hash 为 `5234ab` 的代码为基础创建分支 `test`。

#### 恢复单个文件到指定版本

```sh
git reset 5234ab MainActivity.java
```

恢复 MainActivity.java 文件到 commit hash 为 `5234ab` 时的状态。
