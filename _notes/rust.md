---
title: Rust notes
date: 2018-08-17
---

https://doc.rust-lang.org/stable/rust-by-example/hello/print.html

https://doc.rust-lang.org/stable/rust-by-example/meta/doc.html

## Macro

```rust
// This is a simple macro named `say_hello`.
macro_rules! say_hello {
    // `()` indicates that the macro takes no argument.
    () => {
        // The macro will expand into the contents of this block.
        println!("Hello!");
    };
}

fn main() {
    // This call will expand into `println!("Hello");`
    say_hello!()
}
```

## The most loved language

Rust 不容许空指针、悬垂指针和数据竞争，这些问题在编译阶段就无法通过。

Rust 语言的吉祥物是一只螃蟹 Ferris，因为 Rust 开发者有一个名字，叫 Rustacean，因为这个是从甲壳纲动物这个单词 Crustacean [krʌ’steʃən]，去掉了首字母 C 演变而来的。因为这里面包含 Rust 这四个字母。

Go 有一个高效的垃圾收集器，但 Rust 有静态内存管理。

Go 有很好的并发支持，但 Rust 有可证明的正确并发性。

Go 有接口，但 Rust 有特性和其他零成本的抽象。

Go 对 HTTP 和相关协议有很好的支持，并且，编写一个令人满意的 Web 服务并不需要很长的时间。在我的个人项目中，Go 被证明是 Node.js 的很好替代方案，尤其是在我想要比编写惯用的 JavaScript 更明确地确定不同组件之间的接口的情况下。

除此之外，它还有强大的工具，可用来诊断并发性和性能问题，而且交叉编译使得 Go 在任何平台上部署都变得轻而易举。

Go 以提供了一组有限的内置语言功能而感到自豪。这使得 Go 易于学习，更重要的是，它确保了 Go 项目即使在规模不断扩大的情况下，代码仍然可以理解。Go 的创造者喜欢称之为一种“无聊”的语言。虽然我们可以争论这种语言是否可以使用一种或两种额外的东西，但事实证明，迫使人们“少花钱多办事”的想法是非常成功的。

Go 不希望在同一个目录中有未使用的变量或导入、属于不同包的文件等等。它甚至曾经抱怨在 GOPATH 之外保存的项目（谢天谢地，现在不再是这样了）。

Go 也不希望在代码中留有任何“指纹”，因此它通过 go fmt 强制转换成单一的、通用的代码风格。

----

一个项目里，httpclient竟然出现了四种。

打接口请求响应日志，竟然不知道用拦截器。

打错误日志竟然不打上下文信息，每个人一种日志风格，千奇百怪。

许多重要的中间流程，居然不打日志。

idea、eclipse、myeclipse的配置文件竟然全部传到项目里去了。

该公司混了两年的程序员，跟快递公司做查询接口，竟然不知道加密运单号。

所有服务间通讯，都没有设requestId，导致跟踪会话很困难。

一个没什么qps的边缘接口，居然做消费者生产者+阻塞队列的异步模式。

不知道异步会增加维护成本，提高测试难度吗？

而且，任务队里没有考虑持久化，赶上发布，丢了好多任务。

读取一个小小的xml和exc配置文件，居然用流式解析，没见过这么二逼的，真是醉了。

做优化全靠拍脑门拍大腿，难道不会用excel分析日志，用jprofile扫项目？

一个100以内的常数集合遍历，他也要写个优化算法进去，算法跟业务还搅在一起，一团乱麻。

有枚举他不用，非要在每个页面上，把枚举值挨个儿写死，知道后面改代码多么费劲吗？

欺骗性的变量名，里面存储的是AES加密的，变量名后缀却写成了DES；里面存的是小写字母，却写成upperStr。

他们用mysql来做审计系统，出报表，有个报表要跑8分钟。

原来是有人用字符串来存多值（逗号分隔），sql里写了like，导致没有利用到索引。

为什么不用pg，pg在sql编程方面，功能更丰富，更适合做统计，它本身就支持数组。

整个项目都是几个初创程序员加班加点熬出来的，我知道你看过《代码大全》、《程序员修炼之道》、《Unix 编程艺术》，你对上面的准则信手拈来，你可否翻开床头柜上的这几本书，看看它们的出版时间呢？

## Lifetimes

- Rust allows one and only one owner of memory
- Rust allows multiple references
- Lifetimes enforce a piece of memory is still valid for a reference

Usage
Function

fn test_ref_1<'a>(param_1: &'a Vec<i32>) -> &'a Vec<i32> {
    param_1
}

fn test_ref_2<'a, 'b>(param_1: &'a Vec<i32>, param_2: &'b Vec<i32>) -> &'a Vec<i32> {
    param_1
}

fn test_ref_3<'a, 'b: 'a>(param_1: &'a Vec<i32>, param_2: &'b Vec<i32>) -> &'a Vec<i32> {
    param_1
}

Struct

struct SomeObject<'a, T> {
    some_data: Vec<T>,
    some_ref: &'a Vec<T>,
}

When to use Lifetimes?

    Lifetimes don’t apply because there are no reference inputs or output.

fn test_1(param_1: Vec<f64>) -> Vec<f64> {
    param_1
}

    Lifetimes aren’t an issue because there is no reference output.

fn test_2(param_1: &Vec<f64>) -> Vec<f64> {
    param_1.clone()
}

    Lifetimes aren’t an issue because there is no reference inputs.

fn test_3(param_1: Vec<f64>) -> &Vec<f64> {
    &param_1
}

    Lifetimes aren’t sure for param_1 and param_2

fn test_4<'a>(param_1: &'a Vec<f64>, param_2: &'a Vec<f64>) -> &'a Vec<f64> {
    &param_1
}

fn test_5<'a, 'b>(param_1: &'a Vec<f64>, param_2: &'b Vec<f64>) -> &'a Vec<f64> {
    &param_1
}

Static

    “Static” means a lifetime that lasts the entire program
    “Constants” are static by their nature

cargo build --target x86_64-unknown-linux-musl.

RUSTFLAGS="-C linker=~/x-tools/x86_64-unknown-linux-gnu/bin/x86_64-unknown-linux-gnu-gcc" cargo build --release

install Termux from FDroid. Don’t install it from Google Play. The version in Google Play store is outdated and will not receive any updates until the author has figured a way to target newer Android APIs. Once you’ve done that, open Termux and install proot-distro and use it to install Fedora 33 (check other distributions it supports by proot-distro list)
1
2

pkg install proot-distro
proot-distro install fedora-33

Now we can log into the proot environment and it is Fedora!
1
2
3
4

proot-distro login fedora-33
# the commands below are executed in fedora proot
dnf update
dnf install mate-session-manager mate-desktop mate-themes mate-terminal pluma caja marco glibc-langpack-en firefox

Now you’ve installed some packages for MATE desktop environment and should be ready to have a basic graphical desktop up running. Not so fast yet… Android doesn’t have an X11 server nor a wayland compositor. We then have two choices here:

    VNC/RDP remote desktop
    “Remote” X11

I’m going for the second option here. Mainly because all the VNC clients on Android I’ve tried so far don’t have perfect experience (albeit perfectly usable). To do that, install “XServer XSDL” from Google Play store on the same Android device. Launch it and configure the screen resolution if you need, then we can head back to Termux task and tell Fedora to start a MATE session with a “remote” X server.
1
2

export DISPLAY=localhost:0 PULSE_SERVER=tcp:localhost:4713
mate-session

Remember to acquire wakelock for Termux in the notification area, otherwise Android might kill Termux process to save battery. Now you can head to the XServer XSDL task again, wait for a couple of seconds and you should be greeted by a MATE session (as shown in the screenshot below).
Logging as a Non-root User

You might be struck down by a number of applications that refuse to run in privileged mode (by default, proot logins as root). To solve that and login as a non-root user, you need the good old friends useradd and usermod commands to create a new user in the proot environment:
1
2
3

useradd -m user1  # create a new user with login ID user1
groups root  # check what groups we might need to add
usermod -aG aid_inet user1  # add aid_inet group to user1

Now in the future when you want to login as this user, you can do:
1

proot-distro login fedora-33 --user user1

However it seems that some configuration files are not correctly sorted so you might not be able to use sudo to gain root privilege. The workaround would be to execute those commands in another Termux tab as root.
Locale and Timezone

The system is up running now but it’s been really configured as a bare minimal OS. You might find quite a few things out of the place. Here we’re going to correct the locale and the timezone.

The locale would’ve been configured to the fallback “C”. To make it worse, there is no language pack installed for glibc by default (in the Setup section, we installed English language pack ourselves). Once you’ve installed the language pack you need (and potentially the fonts required), you should be able to see a good candidate in the output of locale -a, pick one and set the LANG environment variable in .bashrc, for example, setting it to British English:
1

export LANG="en_GB.utf8"

Now let’s look at the timezone which is UTC by default, that’s fine on the CLI but might be confusing in a graphical desktop environment. To fix that, run tzselect and edit .bashrc file to add the environment variable for TZ:
1

export TZ="Europe/London"

For example, this sets the timezone to London, UK.
Conclusion







adb shell ime set com.google.android.inputmethod.latin/com.android.inputmethod.latin.LatinIME




----

https://github.com/rust-lang/www.rust-lang.org/

Rust is all about reliability, performance, and security.

# Overview

- 函数式
- 並行式
- 过程式
- 面向对象

# 内存安全

為了提供記憶體安全，它的設計不允許空指標和懸空指標 [25] [26]。 指針只能透過固定的初始化形態來建構，而所有這些形態都要求它們的輸入已經分析過了 [27]。Rust 有一個檢查指標生命期間和指標凍結的系統，可以用來預防在 C++ 中許多的型別錯誤，甚至是用了智慧指標功能之後會發生的型別錯誤。

# 内存管理

Rust 1.0 已不再使用垃圾回收器，而是全面改用基于引用计数的智能指针来管理内存。

# Type

型別系統直接地模仿了 Haskell 語言的类型类概念，並把它稱作「traits」，可以把它看成是一種特设多态。Rust 的作法是透過在宣告型別變數（type variable）的時候，在上面加上限制條件。至於 Haskell 的高階型別變數（Higher-kinded polymorphism）則還未支援。

型別推導也是 Rust 提供的特性之一，使用 let 語法宣告的變數可以不用宣告型別，亦不需要初始值來推斷型別。但如果在稍後的程式中從未指派任何值到該變數，編譯器會發出編譯時（compile time）錯誤 [28]。 函數可以使用泛型化參數（generics），但是必須綁定 Trait。沒有任何方法可以使用方法或運算子，又不宣告它們的型別，每一項都必確明確定義。

Rust 的物件系統是基於三樣東西之上的，即實作（implementation）、Trait 以及結構化資料（如 struct）。實作的角色類似提供 Class 關鍵字的程式語言所代表的意義，並使用 impl 關鍵字。繼承和多型則透過 Trait實現，它們使得方法（method）可以在實作中被定義。結構化資料用來定義欄位。實作和（trait）都無法定義欄位，並且只有（trait）可以提供繼承，藉以躲避C++的「鑽石繼承問題」（菱型缺陷）。

# Hello World

fn main() {
    println!("Hello, World!");
}

階乘

下面是三個不同版本的階乘函數，分別以遞迴、迴圈和反覆運算器的方法寫成：

// 這個函數的 if-else 語句中展示了 Rust 中可選的隱式返回值，可用於寫出更像函數式程式設計風格的代碼
// 與 C++ 和其他類似的語言不同，Rust 中的 if-else 結構不是語句而是運算式，有返回值
fn recursive_factorial(n: u32) -> u32 {
    if n <= 1 {
        1
    } else {
        n * recursive_factorial(n - 1)
    }
}

fn iterative_factorial(n: u32) -> u32 {
    // 變數用`let`定義，`mut`關鍵字使得變數可以變化
    let mut i = 1u32;
    let mut result = 1u32;
    while i <= n {
        result *= i;
        i += 1;
    }
    result // 顯式返回值，與上一個函數不同
}

fn iterator_factorial(n: u32) -> u32 {
    // 反覆運算器有多種用於變換的函數
    // |accum, x| 定義了一個匿名函數
    // 內聯展開等優化方法會消去區間和 fold，使本函數的運行效率和上一個函數相近
    (1..n + 1).fold(1, |accum, x| accum * x)
}

fn main() {
    println!("Recursive result: {}", recursive_factorial(10));
    println!("Iterative result: {}", iterative_factorial(10));
    println!("Iterator result: {}", iterator_factorial(10));
}

併發

一個簡單的 Rust 併發示例：

use std::thread;

// 這個函數將創建十個同時併發運行的執行緒
// 若要驗證這一點，可多次運行這個程式，觀察各執行緒輸出順序的隨機性
fn main() {
    // 這個字串是不可變的，因此可以安全地同時被多個執行緒訪問
    let greeting = "Hello";

    let mut threads = Vec::new();
    // `for`迴圈可用於任何實現了`iterator`特性的類型
    for num in 0..10 {
        threads.push(thread::spawn(move || {
            // `println!`是一個可以靜態檢查格式字串類型的巨集
            // Rust 的巨集是基於結構的（如同 Scheme）而不是基於文本的（如同 C）
            println!("{} from thread number {}", greeting, num);
        }));
    }

    // 收集所有執行緒，保證它們在程式退出前全部結束
    for thread in threads {
        thread.join().unwrap();
    }
}
```


```
下面的代码在 Rust 1.3 中测试通过。
Hello World

fn main() {
    println!("Hello, World!");
}

階乘

下面是三個不同版本的階乘函數，分別以遞迴、迴圈和反覆運算器的方法寫成：

// 這個函數的 if-else 語句中展示了 Rust 中可選的隱式返回值，可用於寫出更像函數式程式設計風格的代碼
// 與 C++ 和其他類似的語言不同，Rust 中的 if-else結構不是語句而是運算式，有返回值
fn recursive_factorial(n: u32) -> u32 {
    if n <= 1 {
        1
    } else {
        n * recursive_factorial(n - 1)
    }
}

fn iterative_factorial(n: u32) -> u32 {
    // 變數用`let`定義，`mut`關鍵字使得變數可以變化
    let mut i = 1u32;
    let mut result = 1u32;
    while i <= n {
        result *= i;
        i += 1;
    }
    result // 顯式返回值，與上一個函數不同
}

fn iterator_factorial(n: u32) -> u32 {
    // 反覆運算器有多種用於變換的函數
    // |accum, x| 定義了一個匿名函數
    // 內聯展開等優化方法會消去區間和 fold，使本函數的運行效率和上一個函數相近
    (1..n + 1).fold(1, |accum, x| accum * x)
}

fn main() {
    println!("Recursive result: {}", recursive_factorial(10));
    println!("Iterative result: {}", iterative_factorial(10));
    println!("Iterator result: {}", iterator_factorial(10));
}

併發

一個簡單的 Rust 併發示例：

use std::thread;

// 這個函數將創建十個同時併發運行的執行緒
// 若要驗證這一點，可多次運行這個程式，觀察各執行緒輸出順序的隨機性
fn main() {
    // 這個字串是不可變的，因此可以安全地同時被多個執行緒訪問
    let greeting = "Hello";

    let mut threads = Vec::new();
    // `for`迴圈可用於任何實現了`iterator`特性的類型
    for num in 0..10 {
        threads.push(thread::spawn(move || {
            // `println!`是一個可以靜態檢查格式字串類型的巨集
            // Rust 的巨集是基於結構的（如同 Scheme）而不是基於文本的（如同 C）
            println!("{} from thread number {}", greeting, num);
        }));
    }

    // 收集所有執行緒，保證它們在程式退出前全部結束
    for thread in threads {
        thread.join().unwrap();
    }
}

```

# 内存安全
## 空指针
## 悬垂指针
## 数据竞争

# Get started

```bash
curl https://sh.rustup.rs -sSf | sh
info: downloading installer

Welcome to Rust!

This will download and install the official compiler for the Rust programming
language, and its package manager, Cargo.

It will add the cargo, rustc, rustup and other commands to Cargo's bin
directory, located at:

  /as/.cargo/bin

This path will then be added to your PATH environment variable by modifying the
profile file located at:

  /as/.profile

You can uninstall at any time with rustup self uninstall and these changes will
be reverted.

Current installation options:

   default host triple: x86_64-unknown-linux-gnu
     default toolchain: stable
  modify PATH variable: yes

1) Proceed with installation (default)
2) Customize installation
3) Cancel installation
1

info: syncing channel updates for 'stable-x86_64-unknown-linux-gnu'
info: downloading component 'rustc'
  9.7 MiB /  35.9 MiB ( 27 %) 147.2 KiB/s ETA: 182 s                error: component download failed for rustc-x86_64-unknown-linux-gnu
info: caused by: could not download file from 'https://static.rust-lang.org/dist/2017-01-31/rustc-1.15.0-x86_64-unknown-linux-gnu.tar.gz' to '/as/.rustup/tmp/xhgfgryisvn69mj6_file
info: caused by: error during download
info: caused by: [28] Timeout was reached (Operation too slow. Less than 10 bytes/sec transferred the last 30 seconds)
rustup: command failed: /tmp/tmp.oF6vd1RryK/rustup-init


...

info: syncing channel updates for 'stable-x86_64-unknown-linux-gnu'
142.1 KiB / 142.1 KiB (100 %) 127.2 KiB/s ETA:   0 s
info: downloading component 'rustc'
 35.9 MiB /  35.9 MiB (100 %) 167.2 KiB/s ETA:   0 s
info: downloading component 'rust-std'
 49.2 MiB /  49.2 MiB (100 %) 441.6 KiB/s ETA:   0 s
info: downloading component 'cargo'
  4.4 MiB /   4.4 MiB (100 %) 192.0 KiB/s ETA:   0 s
info: installing component 'rustc'
info: installing component 'rust-std'
info: installing component 'cargo'
info: default toolchain set to 'stable'

  stable installed - rustc 1.15.0 (10893a9a3 2017-01-19)

Rust is installed now. Great!

To get started you need Cargo's bin directory in your PATH environment
variable. Next time you log in this will be done automatically.

To configure your current shell run source $HOME/.cargo/env


# Hello Rust
```
$ curl -sSf https://static.rust-lang.org/rustup.sh | sh
```

```
~/.cargo/bin/cargo new hello-rust --bin
```

```
cd hello-rust/
$ tree
├── Cargo.toml
└── src
    └── main.rs
```

```
# Cargo.toml
[package]
name = "hello-rust"
version = "0.1.0"
authors = ["Aaron Shang <aaronshang@gmail.com>"]

[dependencies]
```

```
# src/main.rs

fn main() {
    println!("Hello, world!");
}
```


```
~/.cargo/bin/cargo build
$ tree
.
├── Cargo.lock
├── Cargo.toml
├── src
│   └── main.rs
└── target
    └── debug
        ├── build
        ├── deps
        │   └── hello_rust-79029cc8d2d35ec6
        ├── examples
        ├── hello-rust
        └── native
```

```
./target/debug/hello-rust
~/.cargo/bin/cargo run
```


```
~/.cargo/bin/cargo clean
```

# Install

curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh

$ curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
info: downloading installer

Welcome to Rust!

This will download and install the official compiler for the Rust
programming language, and its package manager, Cargo.

It will add the cargo, rustc, rustup and other commands to
Cargo's bin directory, located at:

  /home/aaron/.cargo/bin

This can be modified with the CARGO_HOME environment variable.

Rustup metadata and toolchains will be installed into the Rustup
home directory, located at:

  /home/aaron/.rustup

This can be modified with the RUSTUP_HOME environment variable.

This path will then be added to your PATH environment variable by
modifying the profile files located at:

  /home/aaron/.profile
/home/aaron/.bash_profile

You can uninstall at any time with rustup self uninstall and
these changes will be reverted.

Current installation options:


   default host triple: x86_64-unknown-linux-gnu
     default toolchain: stable
               profile: default
  modify PATH variable: yes

1) Proceed with installation (default)
2) Customize installation
3) Cancel installation

info: profile set to 'default'
info: default host triple is x86_64-unknown-linux-gnu
info: updating existing rustup installation


Rust is installed now. Great!

To get started you need Cargo's bin directory ($HOME/.cargo/bin) in your PATH
environment variable. Next time you log in this will be done
automatically.

To configure your current shell run source $HOME/.cargo/env

# Links
- https://zhuanlan.zhihu.com/p/101118828
- https://www.tuicool.com/articles/ZBf6ZnF






Rust 的异步⽣态：重点介绍 Tokio（运⾏时、框架以及⼯具链）

----

1. Rust?

    在 Go 上的尝试
        Sonic，Frugal

    性能和安全的结合
        接近 C 性能和编译时保证内存安全
        举例：AWS， Discord

2. Rust 服务开发实战

    项⽬背景
        代理服务
        技术栈：Tokio，Thrift
    成本和收益（投⼊产出）
        数据
    如何优化
        编译优化
        ⽕焰图
        观测组件：Console，Metrics




----


curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh

rustup

Rust is installed and managed by the rustup tool.

 In the Rust development environment, all tools are installed to the ~/.cargo/bin directory, and this is where you will find the Rust toolchain, including rustc, cargo, and rustup.

## Cargo: the Rust build tool and package manager

When you install Rustup you’ll also get the latest stable version of the Rust build tool and package manager, also known as Cargo. Cargo does lots of things:

    build your project with cargo build
    run your project with cargo run
    test your project with cargo test
    build documentation for your project with cargo doc
    publish a library to crates.io with cargo publish

Generating a new project

cargo new hello-rust

This will generate a new directory called hello-rust with the following files:

hello-rust
|- Cargo.toml
|- src
  |- main.rs

Cargo.toml is the manifest file for Rust. It’s where you keep metadata for your project, as well as dependencies.

src/main.rs is where we’ll write our application code.

cargo new generates a "Hello, world!" project for us! We can run this program by moving into the new directory that we made and running this in our terminal:

cargo run

You should see this in your terminal:

$ cargo run
   Compiling hello-rust v0.1.0 (/Users/ag_dubs/rust/hello-rust)
    Finished dev [unoptimized + debuginfo] target(s) in 1.34s
     Running `target/debug/hello-rust`
Hello, world!

Adding dependencies

Let’s add a dependency to our application. You can find all sorts of libraries on crates.io, the package registry for Rust. In Rust, we often refer to packages as “crates.”

In this project, we’ll use a crate called ferris-says.

In our Cargo.toml file we’ll add this information (that we got from the crate page):

[dependencies]
ferris-says = "0.2"

Now we can run:

cargo build

...and Cargo will install our dependency for us.

You’ll see that running this command created a new file for us, Cargo.lock. This file is a log of the exact versions of the dependencies we are using locally.

To use this dependency, we can open main.rs, remove everything that’s in there (it’s just another example), and add this line to it:

use ferris_says::say;

This line means that we can now use the say function that the ferris-says crate exports for us.

Now let’s write a small application with our new dependency. In our main.rs, add the following code:

use ferris_says::say; // from the previous step
use std::io::{stdout, BufWriter};

fn main() {
    let stdout = stdout();
    let message = String::from("Hello fellow Rustaceans!");
    let width = message.chars().count();

    let mut writer = BufWriter::new(stdout.lock());
    say(message.as_bytes(), width, &mut writer).unwrap();
}

cargo run

Assuming everything went well, you should see your application print this to the screen:

----------------------------
< Hello fellow Rustaceans! >
----------------------------
              \
               \
                 _~^~^~_
             \) /  o o  \ (/
               '_   -   _'
               / '-----' \

cargo new <project_name>
cargo build  # compile.
cargo run  # compile & run.
cargo check  # check, but not compile into binary (faster than aboves).
cargo build --release  # building for release.
cargo update  # update all the dependent crates.
cargo doc --open

[package]
name = "hello_cargo"
version = "0.1.0"
authors = ["Becavalier <yhorg@hotmail.com\>"]
edition = "2018"

[dependencies]

https://blog.rust-lang.org/2014/10/30/Stability.html

https://doc.rust-lang.org/nightly/rustc/platform-support.html

https://github.com/rust-lang/rust-by-example

https://doc.rust-lang.org/std/

https://doc.rust-lang.org/stable/rust-by-example/hello.html


https://www.yhspy.com/2021/03/23/%E3%80%8AThe-Rust-Programming-Language%E3%80%8B%E8%AF%BB%E4%B9%A6%E7%AC%94%E8%AE%B0%EF%BC%88%E7%AC%AC-1-6-%E7%AB%A0%EF%BC%89/


----


       --add-gnu-debuglink=path-to-file
           Creates a .gnu_debuglink section which contains a reference to path-to-file and adds it to the output file.  Note: the file at path-to-file must exist.
           Part of the process of adding the .gnu_debuglink section involves embedding a checksum of the contents of the debug info file into the section.

           If the debug info file is built in one location but it is going to be installed at a later time into a different location then do not use the path to the
           installed location.  The --add-gnu-debuglink option will fail because the installed file does not exist yet.  Instead put the debug info file in the
           current directory and use the --add-gnu-debuglink option without any directory components, like this:

                    objcopy --add-gnu-debuglink=foo.debug

           At debug time the debugger will attempt to look for the separate debug info file in a set of known locations.  The exact set of these locations varies
           depending upon the distribution being used, but it typically includes:

           "* The same directory as the executable."
           "* A sub-directory of the directory containing the executable"
               called .debug

           "* A global debug directory such as /usr/lib/debug."

           As long as the debug info file has been installed into one of these locations before the debugger is run everything should work correctly.




