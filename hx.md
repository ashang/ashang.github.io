
```sh
$ time cargo install --path helix-term --locked
info: syncing channel updates for '1.65.0-x86_64-unknown-linux-gnu'
warning: Signature verification failed for 'https://static.rust-lang.org/dist/channel-rust-1.65.0.toml'
info: latest update on 2022-11-03, rust version 1.65.0 (897e37553 2022-11-02)
info: downloading component 'cargo'
info: downloading component 'clippy'
info: downloading component 'rust-docs'
info: downloading component 'rust-src'
info: downloading component 'rust-std'
info: downloading component 'rustc'
info: downloading component 'rustfmt'
info: installing component 'cargo'
info: installing component 'clippy'
info: installing component 'rust-docs'
info: installing component 'rust-src'
info: installing component 'rust-std'
info: installing component 'rustc'
info: installing component 'rustfmt'
error: binary `hx` already exists in destination as part of `hx v0.4.2`
Add --force to overwrite

real    0m43.072s       53.84%
user    0m15.526s
sys     0m7.668s

$ cargo uninstall hx
    Removing /home/thpr/.cargo/bin/hx

$ time cargo install --path helix-term --locked
  Installing helix-term v0.6.0 (/home/thpr/helix/helix-term)
    Updating crates.io index
error: failed to fetch `https://github.com/rust-lang/crates.io-index`

Caused by:
  network failure seems to have happened
  if a proxy or similar is necessary `net.git-fetch-with-cli` may help here
  https://doc.rust-lang.org/cargo/reference/config.html#netgit-fetch-with-cli

Caused by:
  SSL error: received early EOF; class=Ssl (16); code=Eof (-20)

real    2m8.411s        0.93%
user    0m0.938s
sys     0m0.261s

$ time proxychains cargo install --path helix-term --locked
[proxychains] config file found: /home/thpr/.proxychains/proxychains.conf
[proxychains] preloading /usr/lib/x86_64-linux-gnu/libproxychains.so.4
  Installing helix-term v0.6.0 (/home/thpr/helix/helix-term)
    Updating crates.io index
  Downloaded gix-diff v0.30.1
  Downloaded gix-glob v0.8.0
  Downloaded gix-chunk v0.4.2
  Downloaded serde_spanned v0.6.2
  Downloaded toml v0.7.4
  Downloaded log v0.4.19
  Downloaded gix-ignore v0.3.0
  Downloaded gix-quote v0.4.4
  Downloaded hex v0.4.3
  Downloaded percent-encoding v2.3.0
  Downloaded unicode-bom v2.0.2
  Downloaded gix-url v0.19.0
  Downloaded sha1_smol v1.0.0
  Downloaded serde_derive v1.0.164
  Downloaded which v4.4.0
  Downloaded signal-hook v0.3.15
  Downloaded ahash v0.8.3
  Downloaded unicode-general-category v0.6.0
  Downloaded ropey v1.6.0
  Downloaded tree-sitter v0.20.10
  Downloaded termini v1.0.0
  Downloaded serde_json v1.0.97
  Downloaded crossterm v0.26.1
  Downloaded url v2.4.0
  Downloaded unicode-linebreak v0.1.4
  Downloaded chardetng v0.1.17
  Downloaded unicode-segmentation v1.10.1
  Downloaded winnow v0.4.6
  Downloaded arc-swap v1.6.0
  Downloaded bitflags v2.3.2
  Downloaded toml_datetime v0.6.2
  Downloaded allocator-api2 v0.2.14
  Downloaded time v0.3.20
  Downloaded tempfile v3.6.0
  Downloaded either v1.8.1
  Downloaded toml_edit v0.19.9
  Downloaded cassowary v0.3.0
  Downloaded ahash v0.7.6
  Downloaded gix-command v0.2.5
  Downloaded signal-hook-mio v0.2.3
  Downloaded signal-hook-tokio v0.3.1
  Downloaded form_urlencoded v1.2.0
  Downloaded dunce v1.0.4
  Downloaded gix-revwalk v0.1.0
  Downloaded gix-bitmap v0.2.4
  Downloaded gix-validate v0.7.5
  Downloaded etcetera v0.8.0
  Downloaded io-close v0.3.7
  Downloaded content_inspector v0.2.4
  Downloaded serde_repr v0.1.12
  Downloaded smawk v0.3.1
  Downloaded gix-hashtable v0.2.1
  Downloaded gix-fs v0.2.0
  Downloaded smartstring v1.0.1
  Downloaded gix-utils v0.1.2
  Downloaded kstring v2.0.0
  Downloaded libloading v0.8.0
  Downloaded gix-commitgraph v0.16.0
  Downloaded str_indices v0.4.1
  Downloaded gix-path v0.8.1
  Downloaded gix-date v0.5.1
  Downloaded gix-mailmap v0.13.0
  Downloaded gix-actor v0.21.0
  Downloaded futures-executor v0.3.28
  Downloaded clru v0.6.1
  Downloaded btoi v0.4.3
  Downloaded time-macros v0.2.8
  Downloaded home v0.5.4
  Downloaded fuzzy-matcher v0.3.7
  Downloaded gix-sec v0.8.1
  Downloaded gix-config-value v0.12.1
  Downloaded time-core v0.1.0
  Downloaded gix-tempfile v6.0.0
  Downloaded gix-prompt v0.5.1
  Downloaded gix-attributes v0.13.1
  Downloaded gix-revision v0.15.2
  Downloaded gix-lock v6.0.0
  Downloaded gix-hash v0.11.2
  Downloaded gix-refspec v0.11.0
  Downloaded once_cell v1.18.0
  Downloaded gix-discover v0.19.0
  Downloaded gix-credentials v0.15.0
  Downloaded gix-traverse v0.27.0
  Downloaded anyhow v1.0.71
  Downloaded signal-hook-registry v1.4.1
  Downloaded miniz_oxide v0.6.2
  Downloaded flate2 v1.0.25
  Downloaded gix-features v0.30.0
  Downloaded slotmap v1.0.6
  Downloaded textwrap v0.16.0
  Downloaded gix-index v0.18.0
  Downloaded lsp-types v0.94.0
  Downloaded gix-worktree v0.19.0
  Downloaded fern v0.6.2
  Downloaded serde v1.0.164
  Downloaded gix-object v0.30.0
  Downloaded prodash v25.0.0
  Downloaded minimal-lexical v0.2.1
  Downloaded pulldown-cmark v0.9.3
  Downloaded gix-negotiate v0.2.1
  Downloaded nom v7.1.3
  Downloaded hashbrown v0.13.2
  Downloaded hashbrown v0.14.0
  Downloaded gix-config v0.23.0
  Downloaded gix-ref v0.30.0
  Downloaded gix-odb v0.47.0
  Downloaded imara-diff v0.1.5
  Downloaded gix-pack v0.37.0
  Downloaded chrono v0.4.26
  Downloaded regex v1.8.4
  Downloaded gix v0.46.0
  Downloaded idna v0.4.0
  Downloaded regex-syntax v0.7.2
  Downloaded tokio v1.28.2
  Downloaded libc v0.2.146
  Downloaded 115 crates (8.0 MB) in 2m 20s
   Compiling libc v0.2.146
   Compiling proc-macro2 v1.0.56
   Compiling unicode-ident v1.0.8
   Compiling autocfg v1.1.0
   Compiling quote v1.0.26
   Compiling memchr v2.5.0
   Compiling cfg-if v1.0.0
   Compiling once_cell v1.18.0
   Compiling version_check v0.9.4
   Compiling thiserror v1.0.40
   Compiling regex-automata v0.1.10
   Compiling smallvec v1.10.0
   Compiling crc32fast v1.3.2
   Compiling adler v1.0.2
   Compiling parking_lot_core v0.9.7
   Compiling io-lifetimes v1.0.10
   Compiling same-file v1.0.6
   Compiling hex v0.4.3
   Compiling scopeguard v1.1.0
   Compiling serde v1.0.164
   Compiling sha1_smol v1.0.0
   Compiling prodash v25.0.0
   Compiling rustix v0.37.15
   Compiling itoa v1.0.6
   Compiling home v0.5.4
   Compiling bitflags v1.3.2
   Compiling time-core v0.1.0
   Compiling log v0.4.19
   Compiling num_threads v0.1.6
   Compiling linux-raw-sys v0.3.4
   Compiling minimal-lexical v0.2.1
   Compiling fastrand v1.9.0
   Compiling bitflags v2.3.2
   Compiling signal-hook v0.3.15
   Compiling regex-syntax v0.7.2
   Compiling cc v1.0.79
   Compiling hashbrown v0.13.2
   Compiling miniz_oxide v0.6.2
   Compiling walkdir v2.3.3
   Compiling time-macros v0.2.8
   Compiling anyhow v1.0.71
   Compiling helix-loader v0.6.0 (/home/thpr/helix/helix-loader)
   Compiling tinyvec_macros v0.1.1
   Compiling static_assertions v1.1.0
   Compiling futures-core v0.3.28
   Compiling gix-utils v0.1.2
   Compiling pin-project-lite v0.2.9
   Compiling tinyvec v1.6.0
   Compiling percent-encoding v2.3.0
   Compiling unicode-bidi v0.3.13
   Compiling encoding_rs v0.8.32
   Compiling winnow v0.4.6
   Compiling serde_json v1.0.97
   Compiling unicode-bom v2.0.2
   Compiling ryu v1.0.13
   Compiling unicode-general-category v0.6.0
   Compiling bytes v1.4.0
   Compiling arc-swap v1.6.0
   Compiling either v1.8.1
   Compiling etcetera v0.8.0
   Compiling lock_api v0.4.9
   Compiling num-traits v0.2.15
   Compiling ahash v0.7.6
   Compiling tempfile v3.6.0
   Compiling indexmap v1.9.3
   Compiling ahash v0.8.3
   Compiling form_urlencoded v1.2.0
   Compiling tokio v1.28.2
   Compiling smartstring v1.0.1
   Compiling slotmap v1.0.6
   Compiling slab v0.4.8
   Compiling libloading v0.8.0
   Compiling str_indices v0.4.1
   Compiling allocator-api2 v0.2.14
   Compiling futures-task v0.3.28
   Compiling iana-time-zone v0.1.56
   Compiling smawk v0.3.1
   Compiling unicode-width v0.1.10
   Compiling flate2 v1.0.25
   Compiling kstring v2.0.0
   Compiling clru v0.6.1
   Compiling futures-util v0.3.28
   Compiling unicode-segmentation v1.10.1
   Compiling dunce v1.0.4
   Compiling ropey v1.6.0
   Compiling pin-utils v0.1.0
   Compiling aho-corasick v1.0.1
   Compiling unicase v2.6.0
   Compiling bstr v1.4.0
   Compiling nom v7.1.3
   Compiling aho-corasick v0.7.20
   Compiling thread_local v1.1.7
   Compiling helix-parsec v0.6.0 (/home/thpr/helix/helix-parsec)
   Compiling grep-matcher v0.1.6
   Compiling pulldown-cmark v0.9.3
   Compiling fnv v1.0.7
   Compiling syn v2.0.15
   Compiling termini v1.0.0
   Compiling tree-sitter v0.20.10
   Compiling unicode-normalization v0.1.22
   Compiling bytecount v0.6.3
   Compiling cassowary v0.3.0
   Compiling regex-syntax v0.6.29
   Compiling lazy_static v1.4.0
   Compiling fuzzy-matcher v0.3.7
   Compiling content_inspector v0.2.4
   Compiling fern v0.6.2
   Compiling gix-command v0.2.5
   Compiling chardetng v0.1.17
   Compiling encoding_rs_io v0.1.7
   Compiling time v0.3.20
   Compiling signal-hook-registry v1.4.1
   Compiling getrandom v0.2.9
   Compiling memmap2 v0.5.10
   Compiling num_cpus v1.15.0
   Compiling mio v0.8.6
   Compiling socket2 v0.4.9
   Compiling gix-sec v0.8.1
   Compiling which v4.4.0
   Compiling filetime v0.2.21
   Compiling io-close v0.3.7
   Compiling idna v0.4.0
   Compiling regex v1.8.4
   Compiling btoi v0.4.3
   Compiling parking_lot v0.12.1
   Compiling threadpool v1.8.1
   Compiling chrono v0.4.26
   Compiling grep-searcher v0.1.11
   Compiling hashbrown v0.12.3
   Compiling signal-hook-mio v0.2.3
   Compiling hashbrown v0.14.0
   Compiling crossterm v0.26.1
   Compiling globset v0.4.10
   Compiling imara-diff v0.1.5
   Compiling ignore v0.4.20
   Compiling grep-regex v0.1.11
   Compiling futures-executor v0.3.28
   Compiling unicode-linebreak v0.1.4
   Compiling thiserror-impl v1.0.40
   Compiling serde_derive v1.0.164
   Compiling tokio-macros v2.1.0
   Compiling serde_repr v0.1.12
   Compiling textwrap v0.16.0
   Compiling gix-hash v0.11.2
   Compiling gix-date v0.5.1
   Compiling gix-validate v0.7.5
   Compiling gix-path v0.8.1
   Compiling gix-chunk v0.4.2
   Compiling gix-quote v0.4.4
   Compiling gix-bitmap v0.2.4
   Compiling gix-config-value v0.12.1
   Compiling gix-actor v0.21.0
   Compiling gix-features v0.30.0
   Compiling gix-hashtable v0.2.1
   Compiling gix-mailmap v0.13.0
   Compiling gix-object v0.30.0
   Compiling gix-commitgraph v0.16.0
   Compiling gix-fs v0.2.0
   Compiling gix-glob v0.8.0
   Compiling gix-prompt v0.5.1
   Compiling gix-tempfile v6.0.0
   Compiling gix-ignore v0.3.0
   Compiling gix-attributes v0.13.1
   Compiling gix-lock v6.0.0
   Compiling gix-revwalk v0.1.0
   Compiling gix-diff v0.30.1
   Compiling gix-ref v0.30.0
   Compiling gix-traverse v0.27.0
   Compiling gix-revision v0.15.2
   Compiling gix-index v0.18.0
   Compiling gix-pack v0.37.0
   Compiling gix-negotiate v0.2.1
   Compiling gix-refspec v0.11.0
   Compiling gix-config v0.23.0
   Compiling gix-discover v0.19.0
   Compiling gix-worktree v0.19.0
   Compiling gix-odb v0.47.0
   Compiling tokio-stream v0.1.14
   Compiling signal-hook-tokio v0.3.1
   Compiling toml_datetime v0.6.2
   Compiling serde_spanned v0.6.2
   Compiling url v2.4.0
   Compiling toml_edit v0.19.9
   Compiling gix-url v0.19.0
   Compiling gix-credentials v0.15.0
   Compiling lsp-types v0.94.0
   Compiling gix v0.46.0
   Compiling toml v0.7.4
   Compiling helix-core v0.6.0 (/home/thpr/helix/helix-core)
   Compiling helix-term v0.6.0 (/home/thpr/helix/helix-term)
   Compiling helix-dap v0.6.0 (/home/thpr/helix/helix-dap)
   Compiling helix-vcs v0.6.0 (/home/thpr/helix/helix-vcs)
   Compiling helix-lsp v0.6.0 (/home/thpr/helix/helix-lsp)
   Compiling helix-view v0.6.0 (/home/thpr/helix/helix-view)
   Compiling helix-tui v0.6.0 (/home/thpr/helix/helix-tui)
    Finished release [optimized] target(s) in 6m 22s
  Installing /home/thpr/.cargo/bin/hx
   Installed package `helix-term v0.6.0 (/home/thpr/helix/helix-term)` (executable `hx`)

real    6m25.487s       449.15%
user    27m12.427s
sys     1m38.625s

$ hx -V
helix 23.05 (b33516fb)

$ ln -Ts $PWD/runtime ~/.config/helix/runtime
```
