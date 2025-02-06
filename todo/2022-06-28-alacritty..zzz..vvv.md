```sh
thread 'main' panicked at 'Failed to initialize any backend! Wayland status: NoCompositorListening X11 status: XOpenDisplayFailed', /build/.cargo/registry/src/github.com-1ecc6299db9ec823/winit-0.26.1/src/platform_impl/linux/mod.rs:619:9
note: run with `RUST_BACKTRACE=1` environment variable to display a backtrace
```


```sh
$ alacritty -vvv
Created log file at "/tmp/Alacritty-50297.log"
[0.000004943s] [INFO ] [alacritty] Welcome to Alacritty
[0.000038715s] [INFO ] [alacritty] Version 0.10.1 ()
[0.000048259s] [INFO ] [alacritty] Running on X11
[0.000969933s] [INFO ] [alacritty] Configuration files loaded from:
                                     "/aaron/.config/alacritty/alacritty.yml"
[0.019072590s] [TRACE] [crossfont] Number of fonts is 190
[0.019119986s] [TRACE] [crossfont] Got font path="/usr/share/fonts/TTF/Inconsolata-Regular.ttf", index=0
[0.019171132s] [DEBUG] [crossfont] Loaded Face Face { ft_face: Font Face: Regular, load_flags: NO_BITMAP | TARGET_LIGHT | TARGET_MONO | TARGET_LCD, render_mode: "Lcd", lcd_filter: 1 }
[0.021862329s] [DEBUG] [alacritty] Estimated DPR: 1
[0.021873636s] [DEBUG] [alacritty] Estimated window size: None
[0.021877063s] [DEBUG] [alacritty] Estimated cell size: 8 x 18
[0.056824894s] [INFO ] [alacritty] Device pixel ratio: 1
[0.061862496s] [INFO ] [alacritty] Initializing glyph cache...
[0.066805612s] [TRACE] [crossfont] Number of fonts is 190
[0.066843685s] [TRACE] [crossfont] Got font path="/usr/share/fonts/TTF/Inconsolata-Regular.ttf", index=0
[0.066887431s] [DEBUG] [crossfont] Loaded Face Face { ft_face: Font Face: Regular, load_flags: NO_BITMAP | TARGET_LIGHT | TARGET_MONO | TARGET_LCD, render_mode: "Lcd", lcd_filter: 1 }
[0.073523382s] [TRACE] [crossfont] Number of fonts is 201
[0.073561578s] [TRACE] [crossfont] Got font path="/usr/share/fonts/TTF/Inconsolata-Bold.ttf", index=0
[0.073606341s] [DEBUG] [crossfont] Loaded Face Face { ft_face: Font Face: Bold, load_flags: NO_BITMAP | TARGET_LIGHT | TARGET_MONO | TARGET_LCD, render_mode: "Lcd", lcd_filter: 1 }
[0.080164580s] [TRACE] [crossfont] Number of fonts is 198
[0.080194725s] [TRACE] [crossfont] Got font path="/usr/share/fonts/TTF/Inconsolata-Regular.ttf", index=0
[0.080202174s] [DEBUG] [crossfont] Loaded Face Face { ft_face: Font Face: Regular, load_flags: NO_BITMAP | TARGET_LIGHT | TARGET_MONO | TARGET_LCD, render_mode: "Lcd", lcd_filter: 1 }
[0.087119537s] [TRACE] [crossfont] Number of fonts is 208
[0.087154027s] [TRACE] [crossfont] Got font path="/usr/share/fonts/TTF/Inconsolata-Bold.ttf", index=0
[0.087162524s] [DEBUG] [crossfont] Loaded Face Face { ft_face: Font Face: Bold, load_flags: NO_BITMAP | TARGET_LIGHT | TARGET_MONO | TARGET_LCD, render_mode: "Lcd", lcd_filter: 1 }
[0.107004000s] [INFO ] [alacritty] ... finished initializing glyph cache in 0.045122115s
[0.107106342s] [INFO ] [alacritty] Cell size: 8 x 18
[0.107114376s] [INFO ] [alacritty] Padding: 0 x 3
[0.107117231s] [INFO ] [alacritty] Width: 800, Height: 600
[0.129550468s] [TRACE] [alacritty_terminal] Scaling RGB by 0.66 from Rgb { r: 203, g: 227, b: 231 } to Rgb { r: 133, g: 149, b: 152 }
[0.129580417s] [TRACE] [alacritty] Deriving dim colors from normal colors
[0.129583671s] [TRACE] [alacritty_terminal] Scaling RGB by 0.66 from Rgb { r: 16, g: 14, b: 35 } to Rgb { r: 10, g: 9, b: 23 }
[0.129586759s] [TRACE] [alacritty_terminal] Scaling RGB by 0.66 from Rgb { r: 255, g: 128, b: 128 } to Rgb { r: 168, g: 84, b: 84 }
[0.129589584s] [TRACE] [alacritty_terminal] Scaling RGB by 0.66 from Rgb { r: 149, g: 255, b: 164 } to Rgb { r: 98, g: 168, b: 108 }
[0.129592558s] [TRACE] [alacritty_terminal] Scaling RGB by 0.66 from Rgb { r: 255, g: 233, b: 170 } to Rgb { r: 168, g: 153, b: 112 }
[0.129595531s] [TRACE] [alacritty_terminal] Scaling RGB by 0.66 from Rgb { r: 145, g: 221, b: 255 } to Rgb { r: 95, g: 145, b: 168 }
[0.129598364s] [TRACE] [alacritty_terminal] Scaling RGB by 0.66 from Rgb { r: 201, g: 145, b: 225 } to Rgb { r: 132, g: 95, b: 148 }
[0.129601228s] [TRACE] [alacritty_terminal] Scaling RGB by 0.66 from Rgb { r: 170, g: 255, b: 228 } to Rgb { r: 112, g: 168, b: 150 }
[0.129603908s] [TRACE] [alacritty_terminal] Scaling RGB by 0.66 from Rgb { r: 203, g: 227, b: 231 } to Rgb { r: 133, g: 149, b: 152 }
[0.129608788s] [INFO ] [alacritty] PTY dimensions: 33 x 100
[0.131679139s] [INFO ] [alacritty] Initialisation complete
[0.135577005s] [DEBUG] [alacritty_terminal] Term::resize dimensions unchanged
[0.135617214s] [INFO ] [alacritty] Padding: 0 x 3
[0.135629265s] [INFO ] [alacritty] Width: 800, Height: 600
[0.162662914s] [DEBUG] [alacritty_terminal] New num_cols is 240 and num_lines is 56
[0.165806056s] [INFO ] [alacritty] Padding: 0 x 1
[0.165824311s] [INFO ] [alacritty] Width: 1920, Height: 1011
[0.305667053s] [TRACE] [alacritty_terminal] Setting mode: CursorKeys
[0.305688918s] [TRACE] [alacritty_terminal] Setting keypad application mode
[0.305693420s] [TRACE] [alacritty_terminal] Setting mode: BracketedPaste
[0.305698763s] [TRACE] [alacritty_terminal] Setting attribute: Bold
[0.305702451s] [TRACE] [alacritty_terminal] Setting attribute: Foreground(Named(Green))
[0.305707253s] [TRACE] [alacritty_terminal] Setting attribute: Bold
[0.305710314s] [TRACE] [alacritty_terminal] Setting attribute: Foreground(Named(Blue))
[0.305714454s] [TRACE] [alacritty_terminal] Setting attribute: Reset
[0.305717933s] [TRACE] [alacritty_terminal] Carriage return
[0.305721275s] [TRACE] [alacritty_terminal] Carriage return
[0.305723922s] [TRACE] [alacritty_terminal] Linefeed
[1.220451665s] [TRACE] [alacritty_terminal] Unsetting mode: BracketedPaste
[1.220546910s] [TRACE] [alacritty_terminal] Carriage return
[1.220573701s] [TRACE] [alacritty_terminal] Carriage return
[1.220592971s] [TRACE] [alacritty_terminal] Linefeed
[1.220618619s] [TRACE] [alacritty_terminal] Unsetting mode: CursorKeys
[1.220645099s] [TRACE] [alacritty_terminal] Unsetting keypad application mode
[1.220679005s] [TRACE] [alacritty_terminal] Carriage return
[1.220704107s] [TRACE] [alacritty_terminal] Linefeed
[1.220730011s] [TRACE] [alacritty_terminal] Setting mode: CursorKeys
[1.220754843s] [TRACE] [alacritty_terminal] Setting keypad application mode
[1.220778179s] [TRACE] [alacritty_terminal] Setting mode: BracketedPaste
[1.220804307s] [TRACE] [alacritty_terminal] Setting attribute: Bold
[1.220841877s] [TRACE] [alacritty_terminal] Setting attribute: Foreground(Named(Green))
[1.220888323s] [TRACE] [alacritty_terminal] Setting attribute: Bold
[1.220908773s] [TRACE] [alacritty_terminal] Setting attribute: Foreground(Named(Blue))
[1.220930309s] [TRACE] [alacritty_terminal] Setting attribute: Reset
[1.220954875s] [TRACE] [alacritty_terminal] Carriage return
[1.220978235s] [TRACE] [alacritty_terminal] Carriage return
[1.220999983s] [TRACE] [alacritty_terminal] Linefeed
[1.502161430s] [TRACE] [alacritty_terminal] Unsetting mode: BracketedPaste
[1.502282929s] [TRACE] [alacritty_terminal] Carriage return
[1.502318206s] [TRACE] [alacritty_terminal] Carriage return
[1.502340854s] [TRACE] [alacritty_terminal] Linefeed
[1.502365346s] [TRACE] [alacritty_terminal] Unsetting mode: CursorKeys
[1.502392174s] [TRACE] [alacritty_terminal] Unsetting keypad application mode
[1.502424236s] [TRACE] [alacritty_terminal] Carriage return
[1.502444324s] [TRACE] [alacritty_terminal] Linefeed
[1.502465094s] [TRACE] [alacritty_terminal] Setting mode: CursorKeys
[1.502489847s] [TRACE] [alacritty_terminal] Setting keypad application mode
[1.502516613s] [TRACE] [alacritty_terminal] Setting mode: BracketedPaste
[1.502544141s] [TRACE] [alacritty_terminal] Setting attribute: Bold
[1.502568177s] [TRACE] [alacritty_terminal] Setting attribute: Foreground(Named(Green))
[1.502603279s] [TRACE] [alacritty_terminal] Setting attribute: Bold
[1.502627255s] [TRACE] [alacritty_terminal] Setting attribute: Foreground(Named(Blue))
[1.502675720s] [TRACE] [alacritty_terminal] Setting attribute: Reset
[1.502699956s] [TRACE] [alacritty_terminal] Carriage return
[1.502721709s] [TRACE] [alacritty_terminal] Carriage return
[1.502742700s] [TRACE] [alacritty_terminal] Linefeed
[1.723975397s] [TRACE] [alacritty_terminal] Unsetting mode: BracketedPaste
[1.724053165s] [TRACE] [alacritty_terminal] Carriage return
[1.724080584s] [TRACE] [alacritty_terminal] Carriage return
[1.724097631s] [TRACE] [alacritty_terminal] Linefeed
[1.724124280s] [TRACE] [alacritty_terminal] Unsetting mode: CursorKeys
[1.724149920s] [TRACE] [alacritty_terminal] Unsetting keypad application mode
[1.724182011s] [TRACE] [alacritty_terminal] Carriage return
[1.724202573s] [TRACE] [alacritty_terminal] Linefeed
[1.725986661s] [TRACE] [alacritty_terminal] Going to: line=0, col=0
[1.726056582s] [TRACE] [alacritty_terminal] Clearing screen: Below
[1.758640007s] [INFO ] [alacritty] Goodbye
Deleted log file at "/tmp/Alacritty-50297.log"
```

