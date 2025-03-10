# 示例：使用 CMake 编译时指定路径
cmake -DCMAKE_PREFIX_PATH=/opt/homebrew/opt/tree-sitter \
      -DENABLE_TREE_SITTER=ON \
      /path/to/neovim-src


```sh
$ brew list tree-sitter
/opt/homebrew/Cellar/tree-sitter/0.25.3/.crates.toml
/opt/homebrew/Cellar/tree-sitter/0.25.3/.crates2.json
/opt/homebrew/Cellar/tree-sitter/0.25.3/bin/tree-sitter
/opt/homebrew/Cellar/tree-sitter/0.25.3/include/tree_sitter/api.h
/opt/homebrew/Cellar/tree-sitter/0.25.3/lib/libtree-sitter.0.25.dylib
/opt/homebrew/Cellar/tree-sitter/0.25.3/lib/pkgconfig/tree-sitter.pc
/opt/homebrew/Cellar/tree-sitter/0.25.3/lib/ (3 other files)
/opt/homebrew/Cellar/tree-sitter/0.25.3/sbom.spdx.json
```


## Homebrew

```sh
/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
```

## 安装go

```sh

brew update && brew upgrade
brew install go
brew install git
brew install mercurial // 可选安装
```

