---
author: aaronshang
comments: true
date: 2012-09-09 02:15:00+00:00
layout: post
link: https://aaronshang.wordpress.com/2012/09/09/case-insensitive-tab-completion-or-wild-expansion/
slug: case-insensitive-tab-completion-or-wild-expansion
title: case insensitive tab-completion or wild expansion
wordpress_id: 1029
---

  
To let wildcard expansion case insensitive, enable this in bashrc  
  


shopt -s nocaseglob  


  
To let tab-completion case insensitive, you can bind the completion-ignore-case option for bash:  
   


bind `echo set completion-ignore-case on`  


  
This will be effective immediately.  
  
  
Or add this in inputrc for readline;  
  


$ echo 'set completion-ignore-case On' >> ~/.inputrc   
 

  
Include the system inputrc file:  


include /etc/inputrc  


  
  
To show all binds:  


bind -p  


  
  
  
To let bash recognizes spelling mistakes, add this  in ~/.bashrc:  
   


shopt -s cdspell  


  
  
For tcsh / zsh users:  
  


set complete enhance  


  
  
Reference:  
[http://www.caliban.org/bash/index.shtml#completion](http://www.caliban.org/bash/index.shtml#completion)  
 [https://wiki.ubuntu.com/Spec/EnhancedBash](https://wiki.ubuntu.com/Spec/EnhancedBash)  
  
  
  
  

