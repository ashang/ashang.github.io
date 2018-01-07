---
author: aaronshang
comments: true
date: 2008-10-08 05:57:00+00:00
layout: post
link: https://aaronshang.wordpress.com/2008/10/08/a-script-to-alias-rm-2/
slug: a-script-to-alias-rm-2
title: a script to alias rm
wordpress_id: 891
---

# This is used as a shell script for alias as 'rm', say, <br># name it del.sh, then alias rm='del.sh'<br># Aaron is gradually improving it, in the process of learning bash.<br># suggestions welcomed to aaronshang@gmail<br> #<br># usage: <br># create a dir for backup: MYSAV=/$HOME/.local/share/Trash/<br># remove: $ rm files<br># restore: $ rm -r files<br># use \rm to call original rm.<br>#<br># I had tried to use (dirname $myfile) to replace (pwd) to save two cd,<br> # but dirname is relative to current working dir, not absolute dir.<br><br># mv -f $(basename $myfile) ${MYSAV}/$(find $(pwd) -maxdepth 1 -name $(basename $myfile)  |tr "/" "=")==`date +%Y-%m-%d-% H-%M-%S`<br> <br>## then must be on next line of if<br><br>MYSAV=/$HOME/.local/share/Trash/<br><br>##(($#==0)) &<br>## ??<br>##  1==0: not found<br><br>case "$1" in<br>-r)<br> <br>cd $MYSAV<br>for i in $(echo $*|awk '{$1="";print}')<br>do<br>	myfile=$(\ls |grep "\"|tail -1)<br>	file=$(echo ${myfile%%==*}|tr "=" "/" |tr "^" " ")<br> 	mv $myfile "${file%/*}/${file##*/}"<br>done <br>;;<br><br>*)<br>#for myfile in "$*"<br>for myfile in $*<br>do<br>	if test -e "$myfile"<br>		then<br>			cd $(dirname "$myfile")<br>			mv -f "$(basename "$myfile")" ${MYSAV}/$(echo $(pwd)/$(basename "$myfile") \<br> 				|tr "/" "=" |tr " " "^")==$(date +%Y-%m-%d-%H-%M-%S)<br>			cd -<br>    else<br>		echo "$myfile:No such file or directory!"<br>    fi<br>done <br><br>;;<br>esac<br>#exit 0<br> <br><br># ==== Bug records <br>#Bug: Failed if files not exist<br><br>#Bug: Failed if filename contains space <br>#Fixed: for myfile in "$*", and add "" for all myfile instances and change spaces to ^ <br> <br>#Bug: Failed for multi files if add "$*", <br>#Fix: just because "" in for myfile in "$*" above, get rid of <br><br>#Fix: I have to remove spaces before using this script:<br># alias rmspace='rename  '\''y/\ /_/'\'' '<br> # script rename is from perl <br><br># Bug: error if the restored is a dir<br># rm -r xxx<br>#2==0: not found<br>#mv: rename =home=xxx-...11-04-17 to /home/xxx/intro_files: No such file or directory<br>

![]()
