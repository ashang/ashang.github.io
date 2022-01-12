---
date: 2017-02-18
title: case insensitive tab-completion or wild expansion
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
  
  
  
  

