---
title: Rust notes
date: 2018-08-17
---

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
[ashang@i3 hello-rust]$ tree
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
[ashang@i3 hello-rust]$ tree
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


## librust-starship-module-config-derive-dev


## rustup

Rust is installed and managed by the rustup tool.

 In the Rust development environment, all tools are installed to the ~/.cargo/bin directory, and this is where you will find the Rust toolchain, including rustc, cargo, and rustup.



## Cargo: the Rust build tool and package manager

When you install Rustup you’ll also get the latest stable version of the Rust build tool and package manager, also known as Cargo. Cargo does lots of things:

    build your project with cargo build
    run your project with cargo run
    test your project with cargo test
    build documentation for your project with cargo doc
    publish a library to crates.io with cargo publish

To test that you have Rust and Cargo installed, you can run this in your terminal of choice:

cargo --version




Generating a new project

Let’s write a small application with our new Rust development environment. To start, we’ll use Cargo to make a new project for us. In your terminal of choice run:

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
A small Rust application

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


Once we save that, we can run our application by typing:

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




    Cargo：

- 创建、编译、运行及检查 Rust 项目：

cargo new <project_name>
cargo build  # compile.
cargo run  # compile & run.
cargo check  # check, but not compile into binary (faster than aboves).
cargo build --release  # building for release.
cargo update  # update all the dependent crates.
cargo doc --open





- Cargo.toml 配置文件格式：

[package]
name = "hello_cargo"
version = "0.1.0"
authors = ["Becavalier <yhorg@hotmail.com\>"]
edition = "2018"

[dependencies]


    Cargo.toml 配置文件使用 TOML（Tom’s Obvious, Minimal Language）格式；
    Rust 中“包”（package）内部的代码被称为 “crates”。


https://blog.rust-lang.org/2014/10/30/Stability.html

https://doc.rust-lang.org/nightly/rustc/platform-support.html

https://github.com/rust-lang/rust-by-example

https://doc.rust-lang.org/std/

https://doc.rust-lang.org/stable/rust-by-example/hello.html

https://www.yhspy.com/2021/03/23/%E3%80%8AThe-Rust-Programming-Language%E3%80%8B%E8%AF%BB%E4%B9%A6%E7%AC%94%E8%AE%B0%EF%BC%88%E7%AC%AC-1-6-%E7%AB%A0%EF%BC%89/

