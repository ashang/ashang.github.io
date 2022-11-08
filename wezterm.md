---
layout: page
title: wezterm
date: 2018-06-01
---

curl https://sh.rustup.rs -sSf | sh -s
git clone --depth=1 --branch=main --recursive https://github.com/wez/wezterm.git
cd wezterm
git submodule update --init --recursive
./get-deps
cargo build --release
cargo run --release --bin wezterm -- start

If you get an error about zlib then you most likely didn't initialize the submodules; take a closer look at the instructions!
Building without Wayland support on Unix systems

By default, support for both X11 and Wayland is included on Unix systems. If your distribution has X11 but not Wayland, then you can build WezTerm without Wayland support by changing the build invocation:

cargo build --release --no-default-features vendored-fonts

Building without X11 is not supported.

Run it via either cargo run --release --bin wezterm or target/release/wezterm


