---
layout: post
title: "Dropping Privileges in Python"
date: 2005-12-19 18:30
comments: true
categories: 
---

When writing a small Python web application using the lightweight [CherryPy](http://www.cherrypy.org/) framework, I needed the server to run on port 80.  Of course running a server as `root` is enough to scare even the hardest sysadmin, so I obviously wanted it to drop privs immediately upon startup, once it had opened the default http port.  I wrote the function below to drop privs and switch to a new user and group (usually `nobody/nogroup`).  It is self-contained, should work with anything - there is nothing specific to any system.  If you find it useful of have any suggestions to improve it, please leave a comment.

To use this within Cherrypy, set the port to 80 in the cherrypy config file, then add the following before your server start:

{% highlight python %}
cpg.server.onStartServerList = [drop_privileges]

## drop_privileges.py

import logging

log = logging.getLogger('server')
logging.basicConfig()
logging.root.setLevel(level=logging.INFO)

# ...

def drop_privileges(uid_name='nobody', gid_name='nogroup'):

    import os, pwd, grp

    starting_uid = os.getuid()
    starting_gid = os.getgid()

    starting_uid_name = pwd.getpwuid(starting_uid)[0]

    log.info('drop_privileges: started as %s/%s' % \
             (pwd.getpwuid(starting_uid)[0],
              grp.getgrgid(starting_gid)[0]))

    if os.getuid() != 0:
        # We're not root so, like, whatever dude
        log.info(&quot;drop_privileges: already running as '%s'&quot;%starting_uid_name)
        return

    # If we started as root, drop privs and become the specified user/group
    if starting_uid == 0:

        # Get the uid/gid from the name
        running_uid = pwd.getpwnam(uid_name)[2]
        running_gid = grp.getgrnam(gid_name)[2]

        # Try setting the new uid/gid
        try:
            os.setgid(running_gid)
        except OSError, e:
            log.error('Could not set effective group id: %s' % e)

        try:
            os.setuid(running_uid)
        except OSError, e:
            log.error('Could not set effective user id: %s' % e)

        # Ensure a very convervative umask
        new_umask = 077
        old_umask = os.umask(new_umask)
        log.info('drop_privileges: Old umask: %s, new umask: %s' % \
                 (oct(old_umask), oct(new_umask)))

    final_uid = os.getuid()
    final_gid = os.getgid()
    log.info('drop_privileges: running as %s/%s' % \
             (pwd.getpwuid(final_uid)[0],
              grp.getgrgid(final_gid)[0]))

# Test it
if __name__ == '__main__':
    drop_privileges()
{% endhighlight %}

## Archived Comments

AUTHOR: Dan C
DATE: 12/30/2005 11:54:37 PM
Thanks
Hey thanks, this function was exactly what I was looking for! (made me realise I should've been able to code it myself too :-). I'm running Cherrypy on an embedded system (crazy, I know!) so I want to minimise memory overheads, therefore no Apache or lighttpd with FCGI or anything -- I'm just serving everything from the Python HTTP server. I really wanted it to drop privileges so it's not running as root ...

The only problem is, Cherrypy calls the onStartServerList functions *before* it starts the HTTP server i.e. before it binds to the socket. I can't figure out how to get around it without editing the code for the HTTP server ... any ideas?

AUTHOR: gavinb
DATE: 01/31/2006 12:21:04 PM
Socket binding CherryPy
Hi Dan,

Glad it helped! I've been using this code successfully for a while to run a private server on port 80.  I went to the CherryPy code to check on the order as you mentioned, and verified that (in at least version 2.0) it calls the onServerStartList functions after it binds to the socket.  I checked both the regular server class and the PooledThreadServer class.

It's possible that in v2.1 (I haven't upgraded yet) they have changed the order of initialisation and binding.  And things are different again now that 2.2 is using WSGI.  I suggest you send your question to the cherrypy mailing list.

Best - G

AUTHOR: Dwayne Litzenberger
DATE: 11/02/2007 12:36:27 PM
What about os.setgroups()?
You missed something: os.setgroups([]).  Look:
>>> import os
>>> os.setgid(1000)
>>> os.setuid(1000)
>>> os.getgroups()
[0]
>>> os.system("id")
uid=1000(dwon) gid=1000(dwon) groups=0(root)
>>>
-----

COMMENT:
AUTHOR: Anonymous
DATE: 08/06/2008 02:59:35 AM
A slight change to make this prettier:
To get the current userid name:

pwd.getpwuid(os.getuid()).pw_name

is better than

pwd.getpwuid(os.getuid())[0]

Marius.
