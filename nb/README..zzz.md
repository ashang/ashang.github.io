
`themes/_config.yml`为[Next主题](https://github.com/iissnan/hexo-theme-next)的配置文件，clone项目后需要将此文件覆盖到`themes/next/`目录下

    git sumbmodule init theme/next
    git sumbmodule update

# Run X in WSL

Just in case it is needed.

## X server
A local X Server is needed, here is example using [VcXsrv](https://sourceforge.net/projects/vcxsrv/).

The executables are `VcXsrv`/`XLaunch`.

## Enable WSL

In PowerShell,

    Enable-WindowsOptionalFeature -Online -FeatureName Microsoft-Windows-Subsystem-Linux

## Desktop
Go to the WSL, here is one Debian stable release.

The desktop environment example here is xfce4,

    $ sudo apt-get install xfce4
    
    $ export DISPLAY=localhost:0

Launch `VcXsrv` using display `-1`.

Then start X

    $ xfce4-session

It will start in `VcXsrv` now.

Or you may use `mate`, just

    $ sudo apt-get install mate    

and start with

    $ mate-session
    
 Or you would like to use just single window manager, here is some cases.
 - i3: install `i3`, start with `i3`
 - awesome: install `awesome`, start with `awesome`
 - xmonad: install `xmonad`, start with `xmonad`/`xmonad-session`
    
## Compiz

If you wanna try compiz.

    $ sudo apt-get install -y compiz compizconfig-settings-manager
    $ sudo ccsm

Then config options in `VcXsrv`.

Star compiz

    $ compiz

# jot

https://hiddentao.com/archives/2011/06/27/setting-up-a-simple-ubuntu-apt-repository

https://www.mobileread.com/forums/showthread.php?t=245888

https://www.mobileread.com/forums/showpost.php?p=3018678&postcount=62

https://www.mobileread.com/forums/showpost.php?p=3017838&postcount=422

https://forum.xda-developers.com/general/general/onyx-boox-afterglow-2-c67ml-custom-roms-t3820645

https://onyxboox.com/firmware

- http://www.bit.ly/2wYEyCB
- https://i.stack.imgur.com/zgNP2.jpg

https://www.mobileread.com/forums/showpost.php?p=3035388&postcount=120

http://www.joshblogs.com/2015/10/onyx-boox-c67ml-first-days.html

https://en.wikipedia.org/wiki/Onyx_Boox

https://www.google.com/search?client=firefox-b-d&q=Pseudo-terminal+will+not+be+allocated+because+stdin+is+not+a+terminal.

https://www.mobileread.com/forums/showthread.php?t=254042&page=2

https://alugha.com/videos/309a0ae5-8c43-11e9-a76d-07700ddb3447?lang=zho&utm_source=propellerAds&utm_medium=native_cpc&utm_campaign=sep_2019_media_traffic&utm_term=2616150&utm_content=lifenoggin_Which_Country_Has_The_Best_Technology_BID_4006127&PPAID=193862902216663040

http://www.szgotech.com/1/RK3026Rockusb_v3.6.zip

https://www.mobileread.com/forums/showthread.php?t=275863

https://www.mobileread.com/forums/showthread.php?t=284619

https://www.mobileread.com/forums/showthread.php?t=285397

https://keyring.debian.org/

https://eklitzke.org/using-gpg-agent-effectively

https://wikitech.wikimedia.org/wiki/Mailman

https://wikitech.wikimedia.org/wiki/Icinga

https://wikitech.wikimedia.org/wiki/Ganeti

https://github.com/kovidgoyal/kitty

中日好友来聚会

绵羊鱼鹿把家回

People,

fish deer sheep  
