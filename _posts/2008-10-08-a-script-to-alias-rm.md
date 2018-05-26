---
author: aaronshang
comments: true
date: 2008-10-08 05:57:00+00:00
layout: post
link: https://aaronshang.wordpress.com/2008/10/08/a-script-to-alias-rm/
slug: a-script-to-alias-rm
title: a script to alias rm
wordpress_id: 945
---

# This is used as a shell script for alias as 'rm', say, <br></br># name it del.sh, then alias rm='del.sh'<br></br># Aaron is gradually improving it, in the process of learning bash.<br></br># suggestions welcomed to aaronshang@gmail<br></br> #<br></br># usage: <br></br># create a dir for backup: MYSAV=/$HOME/.local/share/Trash/<br></br># remove: $ rm files<br></br># restore: $ rm -r files<br></br># use \rm to call original rm.<br></br>#<br></br># I had tried to use (dirname $myfile) to replace (pwd) to save two cd,<br></br> # but dirname is relative to current working dir, not absolute dir.<br></br><br></br># mv -f $(basename $myfile) ${MYSAV}/$(find $(pwd) -maxdepth 1 -name $(basename $myfile)  |tr "/" "=")==`date +%Y-%m-%d-% H-%M-%S`<br></br> <br></br>## then must be on next line of if<br></br><br></br>MYSAV=/$HOME/.local/share/Trash/<br></br><br></br>##(($#==0)) && { echo "No parameters!";exit 1; }<br></br>## ??<br></br>##  1==0: not found<br></br><br></br>case "$1" in<br></br>-r)<br></br> <br></br>cd $MYSAV<br></br>for i in $(echo $*|awk '{$1="";print}')<br></br>do<br></br>	myfile=$(\ls |grep "\<"$i"\>"|tail -1)<br></br>	file=$(echo ${myfile%%==*}|tr "=" "/" |tr "^" " ")<br></br> 	mv $myfile "${file%/*}/${file##*/}"<br></br>done <br></br>;;<br></br><br></br>*)<br></br>#for myfile in "$*"<br></br>for myfile in $*<br></br>do<br></br>	if test -e "$myfile"<br></br>		then<br></br>			cd $(dirname "$myfile")<br></br>			mv -f "$(basename "$myfile")" ${MYSAV}/$(echo $(pwd)/$(basename "$myfile") \<br></br> 				|tr "/" "=" |tr " " "^")==$(date +%Y-%m-%d-%H-%M-%S)<br></br>			cd -<br></br>    else<br></br>		echo "$myfile:No such file or directory!"<br></br>    fi<br></br>done <br></br><br></br>;;<br></br>esac<br></br>#exit 0<br></br> <br></br><br></br># ==== Bug records <br></br>#Bug: Failed if files not exist<br></br><br></br>#Bug: Failed if filename contains space <br></br>#Fixed: for myfile in "$*", and add "" for all myfile instances and change spaces to ^ <br></br> <br></br>#Bug: Failed for multi files if add "$*", <br></br>#Fix: just because "" in for myfile in "$*" above, get rid of <br></br><br></br>#Fix: I have to remove spaces before using this script:<br></br># alias rmspace='rename  '\''y/\ /_/'\'' '<br></br> # script rename is from perl <br></br><br></br># Bug: error if the restored is a dir<br></br># rm -r xxx<br></br>#2==0: not found<br></br>#mv: rename =home=xxx-...11-04-17 to /home/xxx/intro_files: No such file or directory<br></br>

![]()
