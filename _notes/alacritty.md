
Alacritty is a terminal emulator focused on simplicity and performance.

The simplicity goal means it does not have features such as tabs or splits, which can be provided by some window managers, or terminal multiplexers.

Alacritty is written in Rust and GPU-accelerated using OpenGL.


## Live config reload

By default alacritty will reload the configuration automatically when changes have been written into the file. This behavior can be disabled with the following invocation:

```
$ alacritty --no-live-config-reload
```

FILE ~/.config/alacritty/alacritty.yml
```
# Live config reload (changes require restart)
live_config_reload: false
```




## Notes on building alacritty

```
$ curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
$ sudo apt install cmake pkg-config libfreetype6-dev libfontconfig1-dev libxcb-xfixes0-dev
$ cargo build --release
    Updating crates.io index
error: failed to get `bitflags` as a dependency of package `alacritty v0.9.0-dev (/home/thpr/alacritty/alacritty)`

Caused by:
  failed to fetch `https://github.com/rust-lang/crates.io-index`

Caused by:
  network failure seems to have happened
  if a proxy or similar is necessary `net.git-fetch-with-cli` may help here
  https://doc.rust-lang.org/cargo/reference/config.html#netgit-fetch-with-cli

Caused by:
  SSL error: received early EOF; class=Ssl (16); code=Eof (-20)

$ proxychains cargo build --release
[proxychains] config file found: /home/aaron/.proxychains/proxychains.conf
[proxychains] preloading /usr/lib/x86_64-linux-gnu/libproxychains.so.4
    Updating crates.io index
warning: spurious network error (2 tries remaining): [35] SSL connect error (OpenSSL SSL_connect: SSL_ERROR_SYSCALL in connection to static.crates.io:443 )
warning: spurious network error (2 tries remaining): [28] Timeout was reached (download of `atty v0.2.14` failed to transfer more than 10 bytes in 30s)
warning: spurious network error (2 tries remaining): [28] Timeout was reached (failed to download any data for `ab_glyph_rasterizer v0.1.4` within 30s)
error: failed to download from `https://crates.io/api/v1/crates/cmake/0.1.45/download`

Caused by:
  [52] Server returned nothing (no headers, no data) (Empty reply from server)

# After many tries

$ cargo build --release
  Downloaded downcast-rs v1.2.0
  Downloaded dlib v0.4.2
  Downloaded dirs v3.0.2
  Downloaded andrew v0.3.1
  Downloaded slab v0.4.3
  Downloaded scopeguard v1.1.0
  Downloaded gl_generator v0.14.0
  Downloaded dtoa v0.4.8
  Downloaded dlib v0.5.0
  Downloaded wayland-egl v0.28.5
  Downloaded unicode-width v0.1.8
  Downloaded fnv v1.0.7
  Downloaded foreign-types-shared v0.3.0
  Downloaded foreign-types-macros v0.2.1
  Downloaded foreign-types v0.5.0
  Downloaded filetime v0.2.14
  Downloaded dirs-sys v0.3.6
  Downloaded libloading v0.7.0
  Downloaded libc v0.2.94
  Downloaded memchr v2.4.0
  Downloaded lock_api v0.4.4
  Downloaded freetype-rs v0.26.0
  Downloaded wayland-protocols v0.28.5
  Downloaded expat-sys v2.1.6
  Downloaded notify v4.0.16
  Downloaded freetype-sys v0.13.1
  Downloaded winit v0.24.0
  Downloaded x11-dl v2.18.5
  Downloaded x11-clipboard v0.5.1
  Downloaded adler32 v1.2.0
  Downloaded ab_glyph_rasterizer v0.1.4
  Downloaded miniz_oxide v0.3.7
  Downloaded net2 v0.2.37
  Downloaded nix v0.20.0
  Downloaded once_cell v1.7.2
  Downloaded parking_lot v0.11.1
  Downloaded parking_lot_core v0.8.3
  Downloaded png v0.16.8
  Downloaded proc-macro2 v1.0.26
  Downloaded regex-automata v0.1.9
  Downloaded ryu v1.0.5
  Downloaded serde_yaml v0.8.17
  Downloaded signal-hook v0.1.17
  Downloaded signal-hook-registry v1.3.0
  Downloaded scoped-tls v1.0.0
  Downloaded vec_map v0.8.2
  Downloaded unicode-xid v0.2.2
  Downloaded version_check v0.9.3
  Downloaded serde_derive v1.0.125
  Downloaded strsim v0.8.0
  Downloaded same-file v1.0.6
  Downloaded pkg-config v0.3.19
  Downloaded xcb v0.9.0
  Downloaded walkdir v2.3.2
  Downloaded vte v0.10.1
  Downloaded wayland-sys v0.28.5
  Downloaded bitflags v1.2.1
  Downloaded byteorder v1.4.3
  Downloaded cc v1.0.67
  Downloaded copypasta v0.7.1
  Downloaded glutin_glx_sys v0.1.7
  Downloaded glutin_egl_sys v0.1.5
  Downloaded glutin v0.26.0
  Downloaded iovec v0.1.4
  Downloaded inotify-sys v0.1.5
  Downloaded instant v0.1.9
  Downloaded inotify v0.7.1
  Downloaded xdg v2.2.0
  Downloaded base64 v0.13.0
  Downloaded calloop v0.6.5
  Downloaded ansi_term v0.11.0
  Downloaded itoa v0.4.7
  Downloaded cfg-if v0.1.10
  Downloaded atty v0.2.14
  Downloaded clap v2.33.3
  Downloaded lazycell v1.3.0
  Downloaded libloading v0.6.7
  Downloaded linked-hash-map v0.5.4
  Downloaded log v0.4.14
  Downloaded memmap2 v0.1.0
  Downloaded mio-extras v2.0.6
  Downloaded nix v0.18.0
  Downloaded osmesa-sys v0.1.2
  Downloaded owned_ttf_parser v0.6.0
  Downloaded quote v1.0.9
  Downloaded raw-window-handle v0.3.3
  Downloaded rusttype v0.9.2
  Downloaded shared_library v0.1.9
  Downloaded serde v1.0.125
  Downloaded smallvec v1.6.1
  Downloaded smithay-client-toolkit v0.12.3
  Downloaded servo-fontconfig v0.5.1
  Downloaded time v0.1.43
 Downloading 26 crates, remaining bytes: 3.5 MB
  Downloaded smithay-clipboard v0.6.3
warning: spurious network error (2 tries remaining): [28] Timeout was reached (download of `cmake v0.1.45` failed to transfer more than 10 bytes in 30s)
warning: spurious network error (2 tries remaining): [28] Timeout was reached (failed to download any data for `cfg-if v1.0.0` within 30s)
 Downloading 25 crates, remaining bytes: 3.1 MB
...
warning: spurious network error (2 tries remaining): [28] Timeout was reached (download of `crossfont v0.3.0` failed to transfer more than 10 bytes in 30s)
warning: spurious network error (2 tries remaining): [28] Timeout was reached (failed to download any data for `crc32fast v1.2.1` within 30s)
warning: spurious network error (2 tries remaining): [28] Timeout was reached (download of `lazy_static v1.4.0` failed to transfer more than 10 bytes in 30s)
warning: spurious network error (2 tries remaining): [28] Timeout was reached (failed to download any data for `khronos_api v3.1.0` within 30s)
warning: spurious network error (2 tries remaining): [28] Timeout was reached (download of `mio v0.6.23` failed to transfer more than 10 bytes in 30s)
warning: spurious network error (2 tries remaining): [28] Timeout was reached (failed to download any data for `maybe-uninit v2.0.0` within 30s)
warning: spurious network error (2 tries remaining): [28] Timeout was reached (download of `percent-encoding v2.1.0` failed to transfer more than 10 bytes in 30s)
warning: spurious network error (2 tries remaining): [28] Timeout was reached (failed to download any data for `nom v6.1.2` within 30s)
warning: spurious network error (2 tries remaining): [28] Timeout was reached (download of `serde_json v1.0.64` failed to transfer more than 10 bytes in 30s)
warning: spurious network error (2 tries remaining): [28] Timeout was reached (failed to download any data for `regex-syntax v0.6.24` within 30s)
warning: spurious network error (2 tries remaining): [28] Timeout was reached (download of `syn v1.0.71` failed to transfer more than 10 bytes in 30s)
warning: spurious network error (2 tries remaining): [28] Timeout was reached (failed to download any data for `servo-fontconfig-sys v5.1.0` within 30s)
warning: spurious network error (2 tries remaining): [28] Timeout was reached (download of `ttf-parser v0.6.2` failed to transfer more than 10 bytes in 30s)
warning: spurious network error (2 tries remaining): [28] Timeout was reached (failed to download any data for `textwrap v0.11.0` within 30s)
warning: spurious network error (2 tries remaining): [28] Timeout was reached (download of `vte_generate_state_changes v0.1.1` failed to transfer more than 10 bytes in 30s)
warning: spurious network error (2 tries remaining): [28] Timeout was reached (failed to download any data for `utf8parse v0.2.0` within 30s)
warning: spurious network error (2 tries remaining): [28] Timeout was reached (download of `wayland-commons v0.28.5` failed to transfer more than 10 bytes in 30s)
warning: spurious network error (2 tries remaining): [28] Timeout was reached (failed to download any data for `wayland-client v0.28.5` within 30s)
warning: spurious network error (2 tries remaining): [28] Timeout was reached (download of `wayland-scanner v0.28.5` failed to transfer more than 10 bytes in 30s)
warning: spurious network error (2 tries remaining): [28] Timeout was reached (failed to download any data for `wayland-cursor v0.28.5` within 30s)
warning: spurious network error (2 tries remaining): [18] Transferred a partial file (transfer closed with 47783 bytes remaining to read)
warning: spurious network error (2 tries remaining): [18] Transferred a partial file (transfer closed with 52547 bytes remaining to read)
warning: spurious network error (2 tries remaining): [56] Failure when receiving data from the peer (OpenSSL SSL_read: Connection reset by peer, errno 104)
  Downloaded cmake v0.1.45
  Downloaded percent-encoding v2.1.0
  Downloaded maybe-uninit v2.0.0
  Downloaded nom v6.1.2
  Downloaded serde_json v1.0.64
  Downloaded syn v1.0.71
  Downloaded regex-syntax v0.6.24
  Downloaded wayland-cursor v0.28.5
  Downloaded wayland-commons v0.28.5
  Downloaded utf8parse v0.2.0
  Downloaded vte_generate_state_changes v0.1.1
  Downloaded textwrap v0.11.0
  Downloaded ttf-parser v0.6.2
  Downloaded wayland-scanner v0.28.5
  Downloaded crc32fast v1.2.1
  Downloaded lazy_static v1.4.0
  Downloaded crossfont v0.3.0
  Downloaded cfg-if v1.0.0
  Downloaded wayland-client v0.28.5
  Downloaded yaml-rust v0.4.5
  Downloaded mio v0.6.23
  Downloaded xcursor v0.3.3
  Downloaded xml-rs v0.8.3
  Downloaded khronos_api v3.1.0
  Downloaded servo-fontconfig-sys v5.1.0
  Downloaded 119 crates (10.0 MB) in 12m 05s (largest was `freetype-sys` at 1.9 MB)
   Compiling libc v0.2.94
   Compiling proc-macro2 v1.0.26
   Compiling unicode-xid v0.2.2
   Compiling syn v1.0.71
   Compiling cfg-if v1.0.0
   Compiling pkg-config v0.3.19
   Compiling serde_derive v1.0.125
   Compiling serde v1.0.125
   Compiling log v0.4.14
   Compiling bitflags v1.2.1
   Compiling xml-rs v0.8.3
   Compiling lazy_static v1.4.0
   Compiling smallvec v1.6.1
   Compiling cfg-if v0.1.10
   Compiling cc v1.0.67
   Compiling khronos_api v3.1.0
   Compiling once_cell v1.7.2
   Compiling version_check v0.9.3
   Compiling memchr v2.4.0
   Compiling downcast-rs v1.2.0
   Compiling scoped-tls v1.0.0
   Compiling ttf-parser v0.6.2
   Compiling same-file v1.0.6
   Compiling nix v0.18.0
   Compiling slab v0.4.3
   Compiling ab_glyph_rasterizer v0.1.4
   Compiling xdg v2.2.0
   Compiling maybe-uninit v2.0.0
   Compiling lazycell v1.3.0
   Compiling scopeguard v1.1.0
   Compiling ryu v1.0.5
   Compiling unicode-width v0.1.8
   Compiling crc32fast v1.2.1
   Compiling linked-hash-map v0.5.4
   Compiling adler32 v1.2.0
   Compiling foreign-types-shared v0.3.0
   Compiling dtoa v0.4.8
   Compiling serde_json v1.0.64
   Compiling byteorder v1.4.3
   Compiling regex-syntax v0.6.24
   Compiling percent-encoding v2.1.0
   Compiling utf8parse v0.2.0
   Compiling strsim v0.8.0
   Compiling ansi_term v0.11.0
   Compiling vec_map v0.8.2
   Compiling base64 v0.13.0
   Compiling itoa v0.4.7
   Compiling fnv v1.0.7
   Compiling libloading v0.7.0
   Compiling libloading v0.6.7
   Compiling instant v0.1.9
   Compiling wayland-sys v0.28.5
   Compiling x11-dl v2.18.5
   Compiling servo-fontconfig-sys v5.1.0
   Compiling crossfont v0.3.0
   Compiling cmake v0.1.45
   Compiling walkdir v2.3.2
   Compiling nom v6.1.2
   Compiling lock_api v0.4.4
   Compiling textwrap v0.11.0
   Compiling yaml-rust v0.4.5
   Compiling owned_ttf_parser v0.6.0
   Compiling miniz_oxide v0.3.7
   Compiling dlib v0.4.2
   Compiling dlib v0.5.0
   Compiling freetype-sys v0.13.1
   Compiling expat-sys v2.1.6
   Compiling rusttype v0.9.2
   Compiling regex-automata v0.1.9
   Compiling quote v1.0.9
   Compiling nix v0.20.0
   Compiling net2 v0.2.37
   Compiling iovec v0.1.4
   Compiling memmap2 v0.1.0
   Compiling parking_lot_core v0.8.3
   Compiling shared_library v0.1.9
   Compiling dirs-sys v0.3.6
   Compiling signal-hook-registry v1.3.0
   Compiling inotify-sys v0.1.5
   Compiling raw-window-handle v0.3.3
   Compiling atty v0.2.14
   Compiling filetime v0.2.14
   Compiling time v0.1.43
   Compiling png v0.16.8
   Compiling andrew v0.3.1
   Compiling xcb v0.9.0
   Compiling wayland-scanner v0.28.5
   Compiling vte_generate_state_changes v0.1.1
   Compiling parking_lot v0.11.1
   Compiling osmesa-sys v0.1.2
   Compiling dirs v3.0.2
   Compiling xcursor v0.3.3
   Compiling inotify v0.7.1
   Compiling clap v2.33.3
   Compiling wayland-commons v0.28.5
   Compiling freetype-rs v0.26.0
   Compiling vte v0.10.1
   Compiling wayland-client v0.28.5
   Compiling wayland-protocols v0.28.5
   Compiling servo-fontconfig v0.5.1
   Compiling wayland-cursor v0.28.5
   Compiling wayland-egl v0.28.5
   Compiling foreign-types-macros v0.2.1
   Compiling alacritty_config_derive v0.1.0 (/home/thpr/alacritty/alacritty_config_derive)
   Compiling foreign-types v0.5.0
   Compiling serde_yaml v0.8.17
   Compiling gl_generator v0.14.0
   Compiling mio v0.6.23
   Compiling calloop v0.6.5
   Compiling smithay-client-toolkit v0.12.3
   Compiling mio-extras v2.0.6
   Compiling signal-hook v0.1.17
   Compiling x11-clipboard v0.5.1
   Compiling notify v4.0.16
   Compiling glutin_glx_sys v0.1.7
   Compiling glutin_egl_sys v0.1.5
   Compiling alacritty v0.9.0-dev (/home/thpr/alacritty/alacritty)
   Compiling alacritty_terminal v0.13.1-dev (/home/thpr/alacritty/alacritty_terminal)
   Compiling smithay-clipboard v0.6.3
   Compiling winit v0.24.0
   Compiling copypasta v0.7.1
   Compiling glutin v0.26.0
    Finished release [optimized + debuginfo] target(s) in 14m 55s

$ strip target/release/alacritty
$ mv target/release/alacritty ~/.local/bin/
#$ cp alacritty-completions.bash  ~/.bash_completion/alacritty
$ cp extra/completions/alacritty.bash "${XDG_CONFIG_HOME:-$HOME/.config}/bash_completion"


# Configuration file

Default config file

```
$HOME/.config/alacritty/alacritty.yml
```

# Install required tools

sudo apt-get install -y cmake libfreetype6-dev libfontconfig1-dev xclip

# Download, compile and install Alacritty
git clone https://github.com/jwilm/alacritty
cd alacritty
cargo install

# Add Man-Page entries

sudo mkdir -p /usr/local/share/man/man1

gzip -c alacritty.man | sudo tee /usr/local/share/man/man1/alacritty.1.gz > /dev/null

# Add shell completion for bash and zsh

mkdir -p ~/.bash_completion
cp alacritty-completions.bash ~/.bash_completion/alacritty

echo "source ~/.bash_completion/alacritty" >> ~/.bashrc

sudo cp alacritty-completions.zsh /usr/share/zsh/functions/Completion/X/_alacritty

# Copy default config into home dir

cp alacritty.yml ~/.alacritty.yml

# Create desktop file
cp Alacritty.desktop ~/.local/share/applications/

# Copy binary to path
sudo cp target/release/alacritty /usr/local/bin

# Use Alacritty as default terminal (Ctrl + Alt + T)

gsettings set org.gnome.desktop.default-applications.terminal exec 'alacritty'

kakposoe commented on Jan 29, 2019
Just a heads up. I was installing a fresh copy of ubuntu and installed cargo. I was unable to run cargo install within the alacritty1 directory as it is no longer supported. I ended up removing the cd into alacritty and used cargo install --path alacritty/ instead.
Other issues occured but were dealt with separately.


# Running alacritty on Windows 10

## This HOME config file is not sourced

    "%USERPROFILE%"\alacritty.yml

```
$ ~/alacritty.exe -v
Created log file at "C:\Windows\TEMP\Alacritty-30628.log"
[2020-04-11 07:31:10.562934600] [INFO] Welcome to Alacritty
[2020-04-11 07:31:10.564029000] [INFO] No configuration file found
[2020-04-11 07:31:10.627637200] [INFO] Device pixel ratio: 1
[2020-04-11 07:31:10.650279400] [INFO] Initializing glyph cache...
[2020-04-11 07:31:10.673779500] [INFO] ... finished initializing glyph cache in 0.0228039s
[2020-04-11 07:31:10.673779500] [INFO] Cell Size: 8 x 17
[2020-04-11 07:31:10.674200500] [INFO] Padding: 0 x 0
[2020-04-11 07:31:10.674200500] [INFO] Width: 1024, Height: 768
[2020-04-11 07:31:10.693876600] [INFO] PTY Dimensions: Line(45) x Column(128)
[2020-04-11 07:31:10.697992200] [INFO] Using ConPTY backend
[2020-04-11 07:31:10.697992200] [INFO] Initialisation complete
[2020-04-11 07:31:10.699987700] [INFO] Width: 1024, Height: 768
[2020-04-11 07:31:12.775665400] [INFO] Goodbye
Deleted log file at "C:\Windows\TEMP\Alacritty-30628.log"
```

This location is NOT working either.

    %APPDATA%\alacritty\alacritty.yml

This location is working.

    %APPDATA%\Roaming\alacritty\alacritty.yml


Or tell it the location.

    $ ./alacritty --config-file ~/alacritty.yml

## CJK contents can not show by default
CJK fonts must be added into settings

```
font:
  normal:
    family: KaiTi
  size: 12.0
```

## A winpty-agent is included in portable bundle.
```
$ ls -l Alacritty-v0.4.2-windows-portable*
-rw-r--r-- 1 aaron aaron 1988328 Apr  8 18:28 Alacritty-v0.4.2-windows-portable.zip

Alacritty-v0.4.2-windows-portable:
total 5740
-rwxr-xr-x 1 aaron aaron 5148160 Apr  8 18:28 alacritty.exe
-rwxr-xr-x 1 aaron aaron  727552 Apr  8 18:28 winpty-agent.exe

$ ./Alacritty-v0.4.2-windows-portable/winpty-agent.exe
Usage: C:\Users\aaron\Alacritty-v0.4.2-windows-portable\winpty-agent.exe controlPipeName flags mouseMode cols rows
Usage: C:\Users\aaron\Alacritty-v0.4.2-windows-portable\winpty-agent.exe controlPipeName --create-desktop

Ordinarily, this program is launched by winpty.dll and is not directly
useful to winpty users.  However, it also has options intended for
debugging winpty.

Usage: C:\Users\aaron\Alacritty-v0.4.2-windows-portable\winpty-agent.exe [options]

Options:
  --show-input [--with-mouse] [--escape-input]
                   Dump INPUT_RECORDs from the console input buffer
                   --with-mouse: Include MOUSE_INPUT_RECORDs in the dump
                       output
                   --escape-input: Direct the new Windows 10 console to use
                       escape sequences for input
  --version        Print the winpty version

```

## To change default shell

```
shell:
  program: 'c:\\Program Files\\Git\\bin\\bash.exe'
  #args:
  #  - --login
```


https://arslan.io/2018/02/05/gpu-accelerated-terminal-alacritty/

Alacritty is nothing but a terminal emulator. It does not have features that you'll generally find in an interactive terminal emulator. List all the things it does not have.

Multiple tabs
Preference Wizard
Package Manager(of any kind)
Built-in themes
No GUI settings window of any kind.
List of things it is.
Fast
Simple
Independent
Extensible
< 2.0 MB size
Alacritty is faster than any interactive terminal apps. It does not require extra setup or dependency to run. It can also apply settings from existing configuration files i.e. .bashrc, .profile etc.
Configurations
Color schemes: Open the alacritty.yml file located at ~/.config/alacritty/alacritty.yml

Font Size: In the config file, move to size: variable and change the value, make sure you add .0 decimal after the integer.
  # Point size
  size: 11.0
Line Height: In the config file, offset: variable have two sub variables x and y, where y can be called as line height and x as the letter spacing.
  offset:
    x: 0
    y: 0


https://github.com/alacritty/alacritty/blob/master/INSTALL.md

family: Source Code Pro
background_opacity: 0.9


## alacritty/challenger-deep.yml
```
https://raw.githubusercontent.com/challenger-deep-theme/alacritty/master/challenger-deep.yml
```

//https://github.com/alacritty/alacritty/wiki/Color-schemes

## https://wiki.archlinux.org/index.php/Alacritty


# Misc

## https://www.dictionary.com/browse/alacrity
```
alacrity[ uh-lak-ri-tee ]
noun
cheerful readiness, promptness, or willingness:
    We accepted the invitation with alacrity.
liveliness; briskness.
```

# Issue with tmux

```
$ alacritty
thread 'main' panicked at 'Failed to initialize any backend! Wayland status: NoCompositorListening X11 status: XOpenDisplayFailed', /home/aaron/.cargo/registry/src/github.com-1ecc6299db9ec823/winit-0.24.0/src/platform_impl/linux/mod.rs:605:9
note: run with `RUST_BACKTRACE=1` environment variable to display a backtrace
```
