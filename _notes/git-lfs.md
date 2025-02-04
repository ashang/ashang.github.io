

clean = git-lfs clean -- %f

    当文件被**添加（add）**到 Git 版本库时，Git 会执行 git-lfs clean -- %f。
    这个命令的作用是：用 Git LFS 处理大文件，把它转换为指针文件（pointer file），然后存储到 Git 仓库中，而不是直接存储原始大文件。

3. smudge = git-lfs smudge -- %f

    当文件被**检出（checkout）**到工作目录时，Git 会执行 git-lfs smudge -- %f。
    这个命令的作用是：把指针文件转换回原始的大文件，从 Git LFS 服务器下载实际内容，并替换指针文件。

4. process = git-lfs filter-process

    这个是 Git LFS v2 版本的过滤方式，相比 clean/smudge 方式，它更高效。
    filter-process 通过 单个进程 处理所有 LFS 相关的文件，而不是每次都新启动 clean 和 smudge 进程，提高性能。

5. required = true

    这个选项表示 Git 必须使用 Git LFS 来处理这些文件，否则 Git 操作（如 clone 或 pull）可能会失败。
    这样可以强制团队中的开发人员启用 Git LFS，避免意外提交大文件到 Git。


 [filter "lfs"]
+       clean = git-lfs clean -- %f
+       smudge = git-lfs smudge -- %f
+       process = git-lfs filter-process
+       required = true


