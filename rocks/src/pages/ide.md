
## LSP

> Language Server Protocol, LSP, 一个开放的、基于JSON-RPC的网络传输协议，编辑器或集成开发环境（IDE）与提供特定编程语言特性的服务器之间交互时用这个协议。

LSP实现了将语法分析和实际语法处理事件（比如函数重命名、定义查找、实现查找）进行了分离为server和client

## DAP

> Debug Adapter Protocol, 用来对多种调试器进行抽象统一的适配层，将原有 IDE 和调试工具直接交互的模式更改为和 DAP 进行交互。该模式可以让 IDE 集成多种调试器变得更简单，且灵活性更好。

dap将调试这个步骤与编辑器进行解耦，标准化抽象协议，用于开发工具如何与具体调试器通信。

lint和format简单理解为语法的静态分析

## nvim

```text
├── init.lua
├── lua
│   ├── basic.lua
│   ├── colorscheme.lua
│   ├── dap
│   │   ├── config
│   │   │   ├── cppdbg.lua
│   │   │   ├── delve.lua
│   │   │   ├── js.lua
│   │   │   └── python.lua
│   │   ├── dap-config.lua
│   │   ├── dap-util.lua
│   │   ├── list.lua
│   │   └── setup.lua
│   ├── keybindings.lua
│   ├── lsp
│   │   ├── cmp.lua
│   │   ├── config
│   │   │   ├── clangd.lua
│   │   │   ├── emmet_ls.lua
│   │   │   ├── jsonls.lua
│   │   │   ├── rust_analyzer.lua
│   │   │   ├── sumneko_lua.lua
│   │   │   └── tailwindcss.lua
│   │   ├── default-config.lua
│   │   ├── list.lua
│   │   ├── setup.lua
│   │   └── ui.lua
│   ├── null-ts
```

```text

│   │   ├── list.lua
│   │   └── setup.lua
│   ├── plugin-config
│   │   ├── asynctasks.lua
│   │   ├── auto-save.lua
│   │   ├── bufferline.lua
│   │   ├── Comment.lua
│   │   ├── dashboard.lua
│   │   ├── gitsigns.lua
│   │   ├── impatient.lua
│   │   ├── indent-blankline.lua
│   │   ├── lualine.lua
│   │   ├── mason.lua
│   │   ├── noice.lua
│   │   ├── nvim-autopairs.lua
│   │   ├── nvim-colorizer.lua
│   │   ├── nvim-tree.lua
│   │   ├── nvim-treesitter-context.lua
│   │   ├── nvim-treesitter.lua
│   │   ├── project.lua
│   │   ├── symbols-outline.lua
│   │   ├── telescope.lua
│   │   ├── todo-comments.lua
│   │   ├── trouble.lua
│   │   ├── twilight.lua
│   │   └── zen-mode.lua
│   └── plugins.lua
└── plugin
    └── packer
```

```text
_compiled.lua

```

- init.lua是入口文件，
- lua是存放配置文件的目录，
- plugin目录为插件自动生成

1. null-ts（这是一个效果类似mason的插件，不过是用来调用mason安装的各类工具，例如我在这里使用了null-ts的format和lint）
2. plugin-config是插件配置的文件夹，需要自己手动配置的插件在这里面建立一个文件夹
3. plugins.lua是插件管理（这里负责安装插件）

- lsp、dap、null-ts配置规范化、模块化
- plugin管理采用packer，packer支持自举
- 支持类型大纲Outline
- 支持代码的定义跳转、函数的重命名、实现的列出
- 类似vscode的自动构建系统，一键构建程序，一键运行
- 除了使用lsp,还可以安装包裹lsp的插件
- 悬浮窗口（可以多窗口、后台运行）
- 通知消息现代化
- git支持
- 常见的文件格式化、静态分析（均可自行添加需要的功能）
- 悬浮取词翻译