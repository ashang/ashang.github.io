


# intro

The lack of good multithreading support is a known problem of all Ruby
virtual machines. This is the main reason why when running Ruby applications
on production they usually use a Ruby application server in conjunction with
another web server. As Ruby does not play well with multiple connections they run
many instances of Ruby application server and use for example, Apache as a load
balancer for forwarding requests to those instances and as a web server for giving
static content (images, CSS files, and so on). The most documented option for this
category is Apache plus Mongrel, the combination which, for example, was used by
Twitter before the company moved first to Unicorn and then to Java. But the best
combination, according to many benchmark results, is Nginx plus Thin or Unicorn.


But in fact this configuration uses not only a web server and an application server
but also a load balancer. A web server needs to support the reverse proxy mode to be
able to act as a load balancer. For Apache, this mode can be provided by mod_proxy,
Nginx, and Lighttpd have built-in proxies. In addition, a good idea is to use some
software for monitoring Unicorn/Thin instances, for example, Monit.




You perhaps got the feeling that the just discussed category is for advanced usage
and for high loaded services? Yes, it is in a way. The most commonly used, easy-
to-install and best documented is the third category: a web server running a Ruby
application using the Passenger module (also known as mod_rails) or the FastCGI
module. The Passenger module is in fact another Ruby application server. The
difference between it and Unicorn/Thin is that it usually runs as a module of a web
server and not as a standalone server (while the last is possible). The problem with
the Passenger is that it does not work with Windows. Also, the Passenger module
is not available for Lighttpd. Thus, Lighttpd uses FastCGI for running Redmine
instead. FastCGI, which is actually a protocol name, can be also used under
Apache and Nginx.

However, the Passenger is more popular. It is used, for example, by BitNami
Redmine stack and TurnKey Redmine appliances (systems for easy deployment
of Redmine). In addition it is suitable not only for small and middle-sized
websites but can be used for high-loaded web services as well. Thus, for example,
Ruby-on-Rails framework recommends using Passenger in flavor of other options
( http://rubyonrails.org/deploy ).

When run under a web server the Passenger creates at least two processes—itself
and an application. This can be a problem if it is used on cheap OpenVZ powered
VPS hosting where memory amount used by an application is very critical. This
is where FastCGI helps: when run with FastCGI Redmine occupies at least one
process (application).

In case you still don't feel sure about which option to choose, let's summarize:
- If you plan to use Redmine for a heavy-loaded forge site you should think
about using Nginx with Unicorn/Thin and possibly HAProxy.
- For all other cases or if you are just unsure go with Apache or Nginx and the
Passenger module.



# installation

apache2-
passenger-alias.conf and apache2-passenger-host.conf. The former should be
used if you want to run Redmine under some URL path for example,
www.yourdomain.com/redmine . The latter should be used if you want to
run Redmine under subdomain or as the primary application on your domain.


## Path

The installed Redmine conforms to FHS (Filesystem Hierarchy Standard),
that is, configuration files are located in /etc/redmine , Redmine itself in
/usr/share/redmine , cache in /var/cache/redmine , logs in /var/log/
redmine , and so on. That is, any administrator, who is aware of FHS
(even if he/she is not aware of Redmine), will be able to understand the
Redmine file structure, and system tools, such as log analyzers, will
be able to pick up and process Redmine files.



## RubyGems and Bundler
Redmine comes with Bundler support. Bundler is a Ruby Gem dependency
manager which is in some way similar to the Debian/Ubuntu package manager
used in the previous topic. In other words, Bundler simplifies the deployment
process by checking and ensuring that all dependencies are installed.



When you run the Bundler, it fetches gems from www.RubyGems.org and tries to
install them failing only in case of missing system libraries (not gems, the Bundler
can resolve only gem dependencies). This way, by such errors, you can determine
what system libraries are missing.



Now we need to initialize Redmine state files:

    $ rake generate_secret_token

After that initialize the Redmine database with the commands:

    $ RAILS_ENV=production rake db:migrate
    $ RAILS_ENV=production rake redmine:load_default_data

The first command initializes the database structure and the second command
inserts initial data (such as trackers, administrator account, and so on) to the
database. The second command will also ask you the language of the initial data.
Redmine distribution does not include the directory for plugins' static files so it
needs to be created:

    $ mkdir public/plugin_assets


# Configuration

https://github.com/thorin/redmine_local_avatars


Enable REST web service
For third-party tools integration Redmine provides REST API which can be turned
on by this checkbox. For example, Redmine REST API is used by the Redmine Mylyn
Connector and the RedmineApp for iPhone. If you do not use or do not plan to use
any external Redmine tools it is safe to uncheck this option.


## Mail

The delivery_method option accepts the following values: :sendmail , :smtp ,
:async_sendmail , and :async_smtp . The :async_sendmail and :async_smtp
methods deliver e-mails in separate threads thus not making users wait for the
delivery to complete. So asynchronous delivery methods should be used on
installations involving sending many e-mails, when a SMTP server is slow or
hardly accessible or if you experience slow loading of pages which send e-mails
(for example, on issue changes, wiki page additions, changes, and so on).





Configuring reminding e-mails
Redmine issues have optional due date attribute. Would it not be cool to be notified
about the issue due date in advance? So let's do it?
Redmine ships with a special rake task which can be used to generate notifications
about upcoming issues due dates. The name of this task is redmine:send_
reminders . It accepts the following options:
•   days (defaults to 7): The number of days before a due date
•   tracker (all trackers are used if not specified): The numerical (internal)
tracker ID
•   project (all projects are used if not specified): The identifier (which is used
in URL) of the project
•   users (all users are notified if not specified): The numerical IDs of users to
notify separated by comma
The syntax of the command to run the redmine:send_reminders task is:
$ rake redmine:send_reminders days=7 tracker=1 project= mastering-redmine
users=1,5 RAILS_ENV=production
Let's configure our Redmine to remind all users about issues due dates a day before
they are due but not on weekends. Let's use cron for this.
•   We will need to put into cron the following command for Mondays,
Tuesdays, Wednesdays, and Thursdays:
rake redmine:send_reminders days=1 RAILS_ENV=production
•   And the following command for Fridays:
rake redmine:send_reminders days=3 RAILS_ENV=production
•   Now open crontab using the following command:
$ crontab -e




You may need to specify a different user using -u option:
$ sudo crontab -u www-data -e
If you are not sure whether your current user account can be used just try
running the rake task manually first.
•   This command will open an editor. Now add the following two lines:
0 10 * * 1-4 /usr/bin/rake -f /usr/share/redmine/Rakefile
redmine:send_reminders days=1 RAILS_ENV=production
0 10 * * 5 /usr/bin/rake -f /usr/share/redmine/Rakefile
redmine:send_reminders days=3 RAILS_ENV=production
•   Use which rake to determine the path to the rake tool





Selecting days before due date
This task will generate reminder e-mails for all issues, due dates of which
are due in the next number of days, that is, if you specify 7 days, users
will get notifications about issues due in 6 days and in 1 day. Running
such a task (with days=7) everyday can really bother your users so that's
why we select 1 day. In other words, you should execute the task once
in the same number of days (for example, if you use days=7 execute the
task only on Mondays).


## Receiving e-mails
While the e-mail invention predates the Internet invention e-mail is still one of the
primary electronic ways to communicate. Thus, having a public issue tracker for my
projects I still keep getting e-mails from users describing issues. That's why, perhaps,
email integration is one of the essential features of modern issue trackers. And
Redmine does have it.
If you had a look at the Redmine directory structure you might notice the extra
directory containing different scripts and a sample plugin. Despite of what you
could think these files are not, in fact, extra tools but one of the most important
features of Redmine (well, except the sample plugin). We will review all these tools
in this chapter. Right now we start with the rdm-mailhandler.rb . Probably you
already guessed from its name that this is the tool that implements e-mail receiving
for Redmine.

In addition to the rdm-mailhandler.rb , Redmine comes with two rake tasks which
also can be used for receiving emails namely redmine:email:receive_imap and
redmine:email:receive_pop3 .

The difference between these two primary solutions is in the method by which these
tools are invoked. The rdm-mailhandler.rb was designed to be launched on a mail
server by for example, Postfix, while rake tasks were designed to fetch e-mails from
a mail server remotely. Of course, the tool launched by a mail server on receiving
an e-mail is better for several reasons: first, it gets executed only when an email
comes, that is, it does not work for nothing and, second, Redmine gets an e-mail
immediately after it comes to a mail server, that is, without any delay. But the tool
which fetches e-mail from a remote mail server also find its consumer especially if a
remote mail server is for example, Gmail, and therefore there is no way to install the
former tool there.


So for the preceding sample e-mail, we can specify "These are attributes:" here to
remove attributes from issue description or note text. Of course, the delimiters
should be negotiated with customers.
I believe the two hyphens line is essential to have here as it is often used
to delimit message body from signature.
If one specifies other e-mail addresses in To or CC field and if these e-mails are
registered in Redmine (there are accounts with these e-mails) the corresponding
users will be added to issue watchers. However, watchers are not added
from replies.
If the e-mail has attachments these attachments will be added to an issue or to a
forum message. Of course, the size limit specified in General tab at Administration
| Settings is applied to such attachments as well.



## Fetching e-mails through web service

Having read the title you, perhaps, asked yourself: What web service? Yes, we need
the web service to receive e-mail messages which are sent by the rdm-mailhandler.
rb tool. This web service needs to be enabled before we proceed. To do this go to
the Administration area using the link in the top-left menu, then open the Settings
section and click on the Incoming emails tab:
Check the Enable WS for incoming emails option and then click on the Generate a
key link. After that Redmine will generate a web service key for you. Click on Save.

Now copy the rdm-mailhandler.rb tool to your mail server and place it into /usr/
local/sbin . Please note that you may need to install Ruby on the mail server to be
able to run this tool.
Let's now discuss arguments for this tool which should be used on the mail server.
The mandatory arguments are url and key :
•   The url argument should be set to Redmine's home page URL, for example,
http://redmine.packtpub.com .
•   The key argument should be set to the key we have generated above.
Also the following optional arguments are available:
•   The unknown-user option accepts values such as, ignore (the default),
accept , and create . With the default ignore value, all e-mail messages
which come from an e-mail that is not listed in Redmine (if it is not specified
as an e-mail in any account) will be ignored. If the accept value is set, issues
created from such e-mail messages will be authored by Anonymous user.
And, finally, if the create value was specified new user accounts will
be created.
•   The project option can be set to the identifier of the project in which issues
will be created. If this option is not set, the project identifier should be
explicitly set in the e-mail message body.
•   The tracker option can be set to the name of the tracker, which will be used
for newly created issues.
•   The status option can be specified to set a different initial status for issues
created from received e-mails.
•   The category option can be used to set the category for issues, which will be
created from e-mails.
•   The priority option can be used to set a different priority for issues, which
are created from incoming e-mails.
•   And, finally, the allow-override option can be used to limit which issue
attributes can be specified in the e-mail message body. Here, the issue
attributes are actually the previously listed five options: project , tracker ,
status , category , and priority .
So the tool should be executed in the following way:
/usr/local/sbin/rdm-mailhandler.rb --unknown-user create --project
mastering-redmine --url http://redmine.packtpub.com --key mvF868NBavZZVWinIejC


he rest depends on what mail server you are using. As we just can't review all the
available mail servers in this book let's assume you use Postfix and it is configured to
use a plain text file for aliases, for example /etc/aliases . If you don't use it, please
consult your system administrator on how to do this for your configuration (we need
to forward messages intended for a particular email to the standard input of the
rdm-mailhandler.rb ).
Open the /etc/aliases file and add the following line:
issues: "|/usr/local/sbin/rdm-mailhandler.rb --unknown-user
create --allow-override=project,tracker,status,category,priority
--project mastering-redmine --url http://redmine.packtpub.com --key
mvF868NBavZZVWinIejC"
Here issues is the username part of the e-mail address (full address can be for
example, issues@packtpub.com ).




# Scrum backlogs, Kanban board, burndown charts

# Selecting a web server and an application server

Redmine as a Ruby-on-Rails web application should be run under a web server.
This can be an independent web server such as Apache, Nginx, or Lighttpd running
Ruby-on-Rails using either Passenger, FastCGI, or a dedicated Ruby web server such
as Unicorn or Thin.
A big options list, isn't it? Actually these are not all the possible options.
Redmine can also be used with JRuby under a Java virtual machine, can be run
under standalone Passenger, under Mongrel, under WEBrick, and more. But the
above options were chosen by practical use and, therefore, are most commonly
used. So we review only them here. They can be divided into three categories:
•   Dedicated Ruby web server
•   Dedicated Ruby web server plus for example, Nginx as a load balancer
•   Separate web server with for example, Passenger module




    https://github.com/koppen/redmine_github_hook



