---
layout: post
title: "A real Python logging example"
date: 2005-03-15 10:56
comments: true
categories: 
---

For some reason, all the examples of the configuration files for the Python logging framework are artificial ones, with names like `handler01, handler02` and so on.  This makes it a little difficult to figure out how to apply it to a real world example.  So after a bit of fiddling around, here is a real example of using the Python `logging` module in a non-trivial application (ie. with multiple hierarchical modules) with an associated configuration file.

The Python logging framework is extremely useful and powerful, but the documentation is somewhat lacking.  It is dead easy to use in its simplest form:

{% highlight python %}
import os
import math
import logging

def frobnicate(foo, baz):
    logging.info('Processing %s' % foo)
    if baz < 0:
        logging.warning('This could get complex!')
    return math.sqrt(baz * math.pi)

logging.basicConfig()
{% endhighlight %}

So you really do nothing more than import the module, then make logging calls with the appropriate severity level.  But if you have a project with lots of different modules, and you want more control over how things are handled, what do you do?

The first thing is to get a logger instance for each module.  You can use the same name as the module hierarchy, which gives you a lot of flexibility.  Thus, at the top of each module, we have something like:

{% highlight python %}
import logging
log = logging.getLogger('pi.basil.gui.widgets')
{% endhighlight %}

The `logging.getLogger()` call will return us a logger for just that module, which we can then use throughout.  Thus:

{% highlight python %}
class CalibrationCanvas:
 
    #... some stuff
 
    def _on_draw(self):
 
        log.debug('ImageCanvas._on_draw')
        # do some funky stuff
        glBegin()
        # ...
 
    def _update(self, model):
        if not model:
            log.warning('update: No model specified')
{% endhighlight %}

So note the use of the logging instance `log` instead of `logging`.  By using a different `Logger` for each module, we have very fine-grained control.

It is important to use the right severity levels when you write you log calls.  I tend to use `INFO` for generally useful stuff that I like to see traced while developing, but not at runtime, while I reserve `DEBUG` for the extra detailed information that is only useful when something is going wrong.  The `WARNING` and lower I always have on at runtime, and in production are sent to an operator console.

So now we need to set up the logging configuration.  Don't bother trying to do this programmatically (although you could) - use a configuration file.  This is the part that isn't documented so well.  Here is a snippet from a real file:

{% highlight ini %}
[formatters]
keys: detailed,simple
 
[handlers]
keys: console,syslog
 
[loggers]
keys: root,gui,engine
 
[formatter_simple]
format: %(name)s:%(levelname)s:  %(message)s
 
[formatter_detailed]
format: %(name)s:%(levelname)s %(module)s:%(lineno)d:  %(message)s
 
[handler_console]
class: StreamHandler
args: []
formatter: simple
 
[handler_syslog]
class: handlers.SysLogHandler
args: [('myhost.mycorp.net', handlers.SYSLOG_UDP_PORT), handlers.SysLogHandler.LOG_USER]
formatter: detailed
 
[logger_root]
level: INFO
handlers: syslog
 
[logger_gui]
level: WARNING
qualname: pi.basil.gui
handlers: console
 
[logger_engine]
level: INFO
qualname: pi.basil
handlers: console
{% endhighlight %}

A few notes: First, you must list all of the loggers, formatters and handlers in a section up front.  This is a bit odd, since each has their own section with a unique name anyway, but it appears to be due to a limitation of the `ConfigParser`.  So if you have formatters called `root` and `engine`, you must declare them in a section:

{% highlight ini %}
[formatters]
keys: simple,detailed
{% endhighlight %}

Then the details of each formatter are supplied like this:

{% highlight ini %}
[formatter_simple]
format: %(name)s:%(levelname)s:  %(message)s
{% endhighlight %}

And so on, for each instance of each type.

Second, be careful not to add any spaces in the comma-separated list of keys (I think this is a bug) as you can end up with a Logger with a leading space in the name.  So 'keys:root,db,gui' is not the same as 'keys:root, db, gui'.

Third, I have configured one of the handlers above to send logging information to a separate host using the SysLog facility.  Note that you will need to make sure `syslogd` is listening for remote calls for this to work, as it does not by default.  Under Debian, this involved adding the "-r" option to the SYSLOGD settings at the top of `/etc/init.d/sysklogd`.  Also note there are security implications for doing this, so some careful firewall rules are appropriate here.

The trick is the `qualname` setting - this allows us to specify different loggers, and associate the name that we use to get a logger instance with particular settings in the config file.  So the `root` logger above is the default for the system, but we have separate settings for the engine and GUI components.  This `qualname` corresponds to the `getLogger()` call in our code.

The configuration file is loaded at app startup time like this:

{% highlight python %}
    def main():

        # ...

        import logging.config
        logging.config.fileConfig('logging_basil.conf')
{% endhighlight %}

Once you get the hang of it, the logging framework can save you a lot of time and effort, and you will be able to stop the bad habit of adding `print` statements all over the place, only to forget them or have to come back later and remove them.  The logging calls become a part of the code, you leave them in for production code, and can turn up the level of detail for diagnosing problems.  Fortunately, the performance penalty for leaving the logging code in is *very* small, and it is definitely worth a few extra cycles for that peace of mind.

## Archived Comments

AUTHOR: Anonymous
DATE: 08/02/2005 07:00:29 AM

Typo in config file
Thanks for clearing up this mistery! I encountered a small typo in the config file. In section
 [logger_root]
 level: INFO
 handlers: root
the handlers value should be syslog instead of root.

Joost van Lawick
joost@lawick.nl

AUTHOR: Chris Lambacher
DATE: 03/17/2006 09:07:37 AM
You are missing an closing pre tag
After the first code block you are missing a closing pre tag.  It makes the article kind of hard to read.

AUTHOR: gavinb
DATE: 06/07/2006 11:40:57 AM
d'oh
Thanks, fixed!

AUTHOR: Pokerbot
DATE: 08/21/2007 03:23:32 PM
it must be difficult being a
it must be difficult being a python logging - do they wrap around the logs or swallow them in order to move them?

AUTHOR: Kirk Strauser
DATE: 12/25/2007 05:17:45 AM
Reason for listing all the elements
A few notes: First, you must list all of the loggers, formatters and handlers in a section up front. This is a bit odd, since each has their own section with a unique name anyway, but it appears to be due to a limitation of the ConfigParser.

That's not so odd when you consider larger deployments where many applications are configured from the same config file.  This is the case in my company where a master "mycompany.conf" holds all settings used throughout our entire codebase.  In theory, you could run every piece of our software on your own system just by tweaking that one file.  With this setup, the logger details will occupy just one tiny corner; it's not as if the whole config file is dedicated to it.

AUTHOR: dramenbejs
DATE: 05/07/2008 11:07:44 PM

The font configured for the PRE tag in this article is too small: 0.8em.
It forces me to process the article by hand to read it.
Why you don't leave it on the default settings, which are at least readable?
    