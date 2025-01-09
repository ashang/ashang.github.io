---
date: 2017-05-11
title: cp-mv-diff-behavior-in-coreutils
---

  
  


If you aliased mv and cp, and would use "-f" with them, the behavior for them are different.

  


$ alias mv

alias mv='mv -i'

  


$ alias cp

alias cp='cp -i -R -P --preserve=all'

  


GNU coreutils 8.5

  


 

$ man cp

 

       -f, --force              if an existing destination file cannot be opened, remove it and try again (redundant if the -n option is used)

 

        -i, --interactive              prompt before overwrite (overrides a previous -n option)

 

        -n, --no-clobber              do not overwrite an existing file (overrides a previous -i option)

 

$ man mv

 

       -f, --force              do not prompt before overwriting

 

       -i, --interactive              prompt before overwrite

 

       -n, --no-clobber              do not overwrite an existing file

 

       If you specify more than one of -i, -f, -n, only the final one takes effect.

  

 

  
  


  

