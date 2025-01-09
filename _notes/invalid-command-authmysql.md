---
date: 2018-09-04
title: Invalid command 'AuthMYSQL'
---

# /etc/init.d/apache2 restart  
Syntax error on line 16 of /etc/apache2/conf.d/awstats.conf:  
Invalid command 'AuthMYSQL', perhaps misspelled or defined by a module not included in the server configuration  
Action 'configtest' failed.  
The Apache error log may have more information.  
   ...fail!  
  
  
# apt-get install libapache2-mod-auth-mysql  
  
  
# a2enmod auth_mysql  
Enabling module auth_mysql.  
Run '/etc/init.d/apache2 restart' to activate new configuration!  
  
  
# /etc/init.d/apache2 restart  
 * Restarting web server apache2                                                                                                                        [ OK ]  
  
  

