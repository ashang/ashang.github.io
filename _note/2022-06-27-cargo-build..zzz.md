---
title: cargo
date: 2022-06-30
---

```sh
$ cargo install mdbook
    Updating crates.io index
  Downloaded mdbook v0.4.18
  Downloaded 1 crate (1.5 MB) in 3.84s
  Installing mdbook v0.4.18
  Downloaded atty v0.2.14
  Downloaded heck v0.3.3
  Downloaded http-body v0.4.5
  Downloaded inotify-sys v0.1.5
  Downloaded gitignore v1.0.7
  Downloaded lazy_static v1.4.0
  Downloaded termcolor v1.1.3
  Downloaded strum v0.21.0
  Downloaded string_cache v0.8.4
  Downloaded matches v0.1.9
  Downloaded memchr v2.5.0
  Downloaded headers v0.3.7
  Downloaded getrandom v0.2.7
  Downloaded string_cache_codegen v0.5.2
  Downloaded mio v0.8.4
  Downloaded precomputed-hash v0.1.1
  Downloaded phf_generator v0.10.0
  Downloaded pest_generator v2.1.3
  Downloaded block-buffer v0.10.2
  Downloaded bitflags v1.3.2
  Downloaded mime_guess v2.0.4
  Downloaded hashbrown v0.12.1
error: failed to compile `mdbook v0.4.18`, intermediate artifacts can be found at `/tmp/cargo-installjdkSPZ`

Caused by:
  failed to parse manifest at `/home/aaron/.cargo/registry/src/github.com-1ecc6299db9ec823/hashbrown-0.12.1/Cargo.toml`

Caused by:
  failed to parse the `edition` key

Caused by:
  this version of Cargo is older than the `2021` edition, and only supports `2015` and `2018` editions.
```
