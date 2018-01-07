---
author: aaronshang
comments: true
date: 2010-10-18 05:29:00+00:00
layout: post
link: https://aaronshang.wordpress.com/2010/10/18/invalid-command-authmysql-3/
slug: invalid-command-authmysql-3
title: Invalid command 'AuthMYSQL'
wordpress_id: 1046
---

$ sudo /etc/init.d/apache2 restart  
Syntax error on line 16 of /etc/apache2/conf.d/awstats.conf:  
Invalid command 'AuthMYSQL', perhaps misspelled or defined by a module not included in the server configuration  
Action 'configtest' failed.  
The Apache error log may have more information.  
   ...fail!  
  
  
$ sudo apt-get install libapache2-mod-auth-mysql  
  
  
$ sudo a2enmod auth_mysql  
Enabling module auth_mysql.  
Run '/etc/init.d/apache2 restart' to activate new configuration!  
  
  
$ sudo /etc/init.d/apache2 restart  
 * Restarting web server apache2                                                                                                                        [ OK ]  
  
  

