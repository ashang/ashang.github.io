


wget https://musl.libc.org/releases/musl-1.2.3.tar.gz
tar -xvzf musl-1.2.3.tar.gz
cd musl-1.2.3

编译 musl 并生成 ld-musl-aarch64.so
使用以下命令编译 musl：

./configure --prefix=/opt/musl
make
sudo make install

安装完成后检查 ld-musl-aarch64.so
安装完成后，ld-musl-aarch64.so 会被放置在 /opt/musl/lib/ 目录下。你可以通过以下命令来检查：

ls /opt/musl/lib/

你应该能看到 ld-musl-aarch64.so 文件。

更新链接器路径
如果你想让系统默认使用 musl 作为 C 库，你可以更新 LD_LIBRARY_PATH 环境变量，或者为 musl 添加符号链接：

export LD_LIBRARY_PATH=/opt/musl/lib:$LD_LIBRARY_PATH

Debian 提供了 crossbuild-essential-arm64 包，里面包含了编译 ARM64 二进制文件所需的工具链。


