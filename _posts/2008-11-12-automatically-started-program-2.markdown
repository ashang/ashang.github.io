---
author: aaronshang
comments: true
date: 2008-11-12 09:52:00+00:00
layout: post
link: https://aaronshang.wordpress.com/2008/11/12/automatically-started-program-2/
slug: automatically-started-program-2
title: automatically started program
wordpress_id: 880
---

Another program would be moved out from my automatically started list

I put my often used programs into $HOME/.xinitrc, to make them  
automatically started by DM at booting, here is the end of this  
.xinitrc：

export IME=scim  
export GTK_IM_MODULE=$IME  
export XMODIFIERS=@im=$IME  
export QT_IM_MODULE=$IME  
exec scim -d &  
exec stardict &  
exec VirtualBox &  
exec firefox &

export TERM=xfce4-terminal  
exec $TERM &

# finally start the window manager  
unset WINDOW_MANAGER STARTUP

exec skype &  
export WINDOWMANAGER=xfce4-session

exec $WINDOWMANAGER  
exec qterm &

# call failsafe  
exit 0

  
One of my often used programs that had been moved out of this list is  
thunderbird (mutt before this), because I had been used to Gmail as my  
mail reader.

For important or useful emails, I would tidy them up and archive them  
in time, both stored in local and remote storage.

Another program that had been moved out is stardict. One reason is  
that I have to install it in different distros I work with, and copy  
those dics to $HOME/.stardict/dic. Another reason is the alternates I  
had found.

One alternate is the web version of this dict, which have enough dics  
can be self customized:  
[http://www.stardict.org/](http://www.stardict.org/)

Another alternate is Google's dict, with powerful functions such as  
translating, look-up, and searching for words:  
[http://www.google.com/dictionary](http://www.google.com/dictionary)  
This is my default page for native language:  
[http://www.google.com/dictionary?aq=f&langpair=en|zh-CN](http://www.google.com/dictionary?aq=f&langpair=en|zh-CN)  
in short, it is:  
[http://www.google.cn/dictionary](http://www.google.cn/dictionary)

Which is the next? scim, i think.  
But I have to choose one alternate, will try and decide one.

Then what next? skype, but not until gmail chat can do voice and video.

![](https://blogger.googleusercontent.com/tracker/4041220-8159324769840527184?l=ashang.blogspot.com)
