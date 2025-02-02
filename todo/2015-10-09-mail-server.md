---
title: "Mail Server"
date: 2021-06-07T18:31:37+08:00
Description: ""
Categories: ""
draft: true
---


 COPYING for additional information.

The Courier IMAP server is a fast, scalable, enterprise IMAP server that uses Maildirs. Many E-mail service providers use the Courier IMAP server to easy handle hundreds of thousands of mail accounts. With its built-in IMAP and POP3 aggregation proxy, the Courier IMAP server has practically infinite horizontal scalability. In a proxy configuration, a pool of Courier servers service initial IMAP and POP3 connections from clients. They wait to receive the client's log in request, look up the server that actually holds this mail account's mailbox, and establish a proxy connection to the server, all in a single, seamless process. Mail accounts can be moved between different servers, to achieve optimum resource usage.

The only practical limitation on the Courier IMAP server is available network and I/O bandwidth. If you are new to the Courier IMAP server, this may sound a bit intimidating. But you do not need to tackle everything at once. Start by taking small, easy steps. Your first step will be to set up a small the Courier IMAP server server, using it like any other traditional IMAP service, on a single server. After you gain experience and become comfortable with Courier, you can then begin exploring its advanced features.

This is the same IMAP server that's included in the Courier mail server, but configured as a standalone IMAP server that can be used with other mail servers - such as Qmail, Exim, or Postfix - that deliver to maildirs. If you already have Courier installed, you do not need to download this version. If you install this version, you must remove it if you later install the entire Courier server.



----


How the Courier IMAP server stores its mail, and works with your mail server
IMAP servers provide access to existing mail, in existing mailboxes. IMAP servers are not involved in the mail delivery process. You'll still need to have your mail server software receive mail via SMTP and place it in recipients' mailboxes.

It does not matter to the Courier IMAP server which mail server you use: Sendmail, Postfix, or something else, as long as the mail gets delivered to the correct mailbox. The Courier IMAP server just reads mail from existing mail accounts, without needing to know how it gets there.

The Courier IMAP server uses "maildirs" to store its mail. Please note that this IMAP server does NOT use traditional mailbox files (/var/spool/mail, and derivatives), it was written and optimized for the specific purpose of providing IMAP access to Maildirs. Consult your mail server's documentation for help on how to get it to deliver mail in the "maildir" format.

"Maildir" is a directory-based mail storage format originally introduced in the Qmail mail server, and adopted as an alternative mail storage format by both Exim and Postfix. The Courier IMAP server is a popular combination with Qmail, Exim, and Postfix servers that are configured to use maildirs. The primary advantage of maildirs is that multiple applications can access the same Maildir simultaneously without requiring any kind of locking whatsoever. Maildir is a faster and more efficient way to store mail. It works particularly well over NFS, which has a long history of locking-related woes.

The Courier IMAP server implements several extensions to the basic Maildir mail storage format in order to support some additional features, such as folders and "soft" quotas. This is done in a way that's backwards compatible with the standard Maildir users (although, of course, they will ignore the additional features). Other software that understands and uses the same Maildir extensions is SqWebMail, and maildrop.


# Firewall
Shorewall
Not essential for an EC2 image. It is essential for a normal server. UFW is bundled with recent Ubuntu distributions, but I still prefer Shorewall for servers.

Basically at first you want to only allow SSH. Then SMTP and IMAP from your IP only.

When you are confident that the mail server is secure, you can open SMTP to the world. If you prefer you can also open IMAP to the world, unless you have a very small client IP range.

Later you may open web access to the webmail and admin gui. This you may also restrict to specific IPs.

SSH only
By default Shorewall in Ubuntu has an empty set up. You can find the default values for Shorewall in /usr/share/doc/shorwall-common/default-config. And examples in /usr/share/doc/shorwall-common/examples. We will create a basic set up.

First configure which network adapters we are accessing the net.
cp /usr/share/doc/shorewall-common/default-config/interfaces /etc/shorewall/
vi /etc/shorewall/interfaces
net     eth0            detect          dhcp,tcpflags,logmartians,nosmurfs
Then we will configure network zones
cp /usr/share/doc/shorewall-common/default-config/zones /etc/shorewall/
vi /etc/shorewall/zones
Add the firewall if not there and the internet as a zone.
fw	firewall
# loc 	ipv4
net     ipv4
Then if needed to specify hosts you can do it in this file. E.g. If you wanto specify what is your home IP etc.
cp /usr/share/doc/shorewall-common/default-config/hosts /etc/shorewall/
vi /etc/shorewall/hosts
# loc	eth0:192.168.0.0/24
Then set what is the default policy for firewall access.
cp /usr/share/doc/shorewall-common/default-config/policy /etc/shorewall/
vi /etc/shorewall/policy
$FW             net             ACCEPT
net             $FW             DROP            info
net             all             DROP            info
# The FOLLOWING POLICY MUST BE LAST
all             all             REJECT          info
For safety in case it goes down.
cp /usr/share/doc/shorewall-common/default-config/routestopped /etc/shorewall/
vi /etc/shorewall/routestopped
eth0            0.0.0.0                 routeback
You may put in a netmask of your ip range if you are more concerned.

Now for the main firewall rules. You can find predetermined macro rules for Shorewall in /usr/share/shorewall.
cp /usr/share/doc/shorewall-common/default-config/rules /etc/shorewall/
vi /etc/shorewall/rules
SSH/ACCEPT      net             $FW
Open for business
Once your server is working come back to this step and open up SMTP and Web access to others.

vi /etc/shorewall/rules
Ping/ACCEPT     net             $FW

# Permit all ICMP traffic FROM the firewall TO the net zone
ACCEPT          $FW             net             icmp

# mail lines
SMTP/ACCEPT     net             $FW
SMTPS/ACCEPT    net             $FW
Submission/ACCEPT       net             $FW
IMAP/ACCEPT     net             $FW
IMAPS/ACCEPT    net             $FW

#web
Web/ACCEPT      net             $FW
Firewall configuring is always risky business, as it is easy to lock yourself out. To test the setup syntax, run
shorewall check
Restart it with
/etc/init.d/shorewall restart
Then to switch it on during boot:
vi /etc/default/shorewall
startup=1
For more details on IP Tables and Shorewall, look up its website.

Return to top.

MTA
Postfix
You should put the name of your server in this file
sudo vi /etc/mailname
Could be something like smtp.domain.name, where domain name obviously is replaced with your domain name.

Now will open the main postfix configuration file:
sudo vi /etc/postfix/main.cf
Debian and Ubuntu already puts in some sensible default values in this file. You may need to comment some of them out if we put the same in as well.

First specify the name of your server.
# This is already done in /etc/mailname
#myhostname= mail.example.com
Next is the origin which is the domain appended to email from this machine, this can be your full servername, or domain name.
# myorigin=/etc/mailname
myorigin=example.com
Then decide what the greeting text will be. Enough info so it is useful, but not divelge everything to potential hackers.
smtpd_banner = $myhostname ESMTP $mail_name
Next you need to decide whether to send all outgoing mail via another SMTP server, or send them yourself. I send via my ISP's server, so it has to worry about the queing etc. If you send it yourself then you are not reliant on 3rd party server. But you may risk more exposure and accidentally be blocked by spam blockers. And it is more work for your server. Also many servers block dynamic dns hosts, so you may find your server gets rejected. However choose whichever you are comfortable with.
# leave blank to do it yourself
relayhost =
# or put it an accessible smtp server
relayhost = smtp.yourisp.com
Next is network details. You will accept connection from anywhere, and you only trust this machine
inet_interfaces = all
mynetworks_style = host
Next you can masquerade some outgoing addresses. Say your machine's name is mail.domain.com. You may not want outgoing mail to come from username@mail.example.com, as you'd prefer username@example.com. You can also state which domain not to masquerade. E.g. if you use a dynamic dns service, then your server address will be a subdomain. You can also specify which users not to masquerade.
# masquerade_domains = mail.example.com www.example.com !sub.dyndomain.com
# masquerade_exceptions = root
As we will be using virtual domains, these need to be empty.
local_recipient_maps =
mydestination =
Then will set a few numbers.
# how long if undelivered before sending warning update to sender
delay_warning_time = 4h
# will it be a permanent error or temporary
unknown_local_recipient_reject_code = 450
# how long to keep message on queue before return as failed.
# some have 3 days, I have 16 days as I am backup server for some people
# whom go on holiday with their server switched off.
maximal_queue_lifetime = 7d
# max and min time in seconds between retries if connection failed
minimal_backoff_time = 1000s
maximal_backoff_time = 8000s
# how long to wait when servers connect before receiving rest of data
smtp_helo_timeout = 60s
# how many address can be used in one message.
# effective stopper to mass spammers, accidental copy in whole address list
# but may restrict intentional mail shots.
smtpd_recipient_limit = 16
# how many error before back off.
smtpd_soft_error_limit = 3
# how many max errors before blocking it.
smtpd_hard_error_limit = 12
Now we can specify some restrictions. Be carefull that each setting is on one line only.
# Requirements for the HELO statement
smtpd_helo_restrictions = permit_mynetworks, warn_if_reject reject_non_fqdn_hostname,
		reject_invalid_hostname, permit
# Requirements for the sender details
smtpd_sender_restrictions = permit_mynetworks, warn_if_reject reject_non_fqdn_sender,
		reject_unknown_sender_domain, reject_unauth_pipelining, permit
# Requirements for the connecting server
smtpd_client_restrictions = reject_rbl_client sbl.spamhaus.org,
		reject_rbl_client blackholes.easynet.nl,
		reject_rbl_client dnsbl.njabl.org
# Requirement for the recipient address
smtpd_recipient_restrictions = reject_unauth_pipelining, permit_mynetworks,
		reject_non_fqdn_recipient, reject_unknown_recipient_domain,
		reject_unauth_destination, permit
		smtpd_data_restrictions = reject_unauth_pipelining
Further restrictions:
# require proper helo at connections
smtpd_helo_required = yes
# waste spammers time before rejecting them
smtpd_delay_reject = yes
disable_vrfy_command = yes
Next we need to set some maps and lookups for the virtual domains.
# not sure of the difference of the next two
# but they are needed for local aliasing
alias_maps = hash:/etc/postfix/aliases
alias_database = hash:/etc/postfix/aliases
# this specifies where the virtual mailbox folders will be located
virtual_mailbox_base = /var/spool/mail/virtual
# this is for the mailbox location for each user
virtual_mailbox_maps = mysql:/etc/postfix/mysql_mailbox.cf
# and their user id
virtual_uid_maps = mysql:/etc/postfix/mysql_uid.cf
# and group id
virtual_gid_maps =  mysql:/etc/postfix/mysql_gid.cf
# and this is for aliases
virtual_alias_maps = mysql:/etc/postfix/mysql_alias.cf
# and this is for domain lookups
virtual_mailbox_domains = mysql:/etc/postfix/mysql_domains.cf
# this is how to connect to the domains (all virtual, but the option is there)
# not used yet
# transport_maps = mysql:/etc/postfix/mysql_transport.cf
You need to set up an alias file. This is only used locally, and not by your own mail domains.
sudo cp /etc/aliases /etc/postfix/aliases
# may want to view the file to check if ok.
# especially that the final alias, eg root goes
# to a real person
sudo postalias /etc/postfix/aliases
Next you need to set up the folder where the virtual mail will be stored. This may have already been done by the apt-get. And also create the user whom will own the folders.
# to add if there is not a virtual user
sudo mkdir /var/spool/mail/virtual
sudo groupadd virtual -g 5000
sudo useradd virtual -u 5000 -g 5000
sudo chown -R virtual:virtual /var/spool/mail/virtual
Note: If using Amazon ec2 you may want to move the mail spool to /mnt or an EBS location. You will need to symlink correctly afterwards.

Return to top.
Postfix's MySQL configuration
Next we need to set up the files to access the lookups via the database. We will only set up a few now, and the rest later when/if needed:

Edit(create) how to find the users mailbox location
sudo vi /etc/postfix/mysql_mailbox.cf

user=mail
password=mailPASSWORD
dbname=maildb
table=users
select_field=maildir
where_field=id
hosts=127.0.0.1
additional_conditions = and enabled = 1
Create how to find the user id (this step I will eventualy remove)
sudo vi /etc/postfix/mysql_uid.cf

user=mail
password=mailPASSWORD
dbname=maildb
table=users
select_field=uid
where_field=id
hosts=127.0.0.1
Create how to find the group id. (this step I will eventualy remove)
sudo vi /etc/postfix/mysql_gid.cf

user=mail
password=mailPASSWORD
dbname=maildb
table=users
select_field=gid
where_field=id
hosts=127.0.0.1
Create how to find the email alias:
sudo vi /etc/postfix/mysql_alias.cf

user=mail
password=mailPASSWORD
dbname=maildb
table=aliases
select_field=destination
where_field=mail
hosts=127.0.0.1
additional_conditions = and enabled = 1
Create how to find the domains:
sudo vi /etc/postfix/mysql_domains.cf

user=mail
password=mailPASSWORD
dbname=maildb
table=domains
select_field=domain
where_field=domain
hosts=127.0.0.1
additional_conditions = and enabled = 1
As you can see the 3 first are very similar, only the select_field changes. If you specify an ip in hosts, (as opposed to 'localhost') then it will communicate over tcp and not the mysql socket. (chroot restriction). Actually you can avoid using separate uid and guid files as those details are the same for all, but I do anyway. Ps. remember to replace the password with your chosen mail user password.

Return to top.
No LOL

Database
MySQL
Now we will need to create the tables for thos lookups just specified. First you need to create a user to use in MySQL for mail only. Then you need to create the database, Take note of your chosen mail username and password. You will need the password you specified for root during MySQL package installation.

# If not already done (in package installation)...
mysqladmin -u root password new_password
# log in as root
mysql -u root -p
# then enter password for the root account when prompted
Enter password:
# then we create the mail database
create database maildb;
# then we create a new user: "mail"
GRANT SELECT,INSERT,UPDATE,DELETE,CREATE,DROP
ON maildb.* TO 'mail'@'localhost' IDENTIFIED by 'mailPASSWORD';
GRANT SELECT,INSERT,UPDATE,DELETE,CREATE,DROP
ON maildb.* TO 'mail'@'%' IDENTIFIED by 'mailPASSWORD';
exit;
Obviously replace mailPASSWORD with your chosen password!

Then you will need to create these tables:

aliases
domains
users
We will create more later on for further extensions, but only these are relevant now.
Log in to mysql as the new mail user
mysql -u mail -p maildb
# enter the newly created password
Enter password:
Then run this commands to create the tables:

CREATE TABLE `aliases` (
`pkid` smallint(3) NOT NULL auto_increment,
`mail` varchar(120) NOT NULL default '',
`destination` varchar(120) NOT NULL default '',
`enabled` tinyint(1) NOT NULL default '1',
PRIMARY KEY  (`pkid`),
UNIQUE KEY `mail` (`mail`)
) ;
CREATE TABLE `domains` (
`pkid` smallint(6) NOT NULL auto_increment,
`domain` varchar(120) NOT NULL default '',
`transport` varchar(120) NOT NULL default 'virtual:',
`enabled` tinyint(1) NOT NULL default '1',
PRIMARY KEY  (`pkid`)
) ;
CREATE TABLE `users` (
`id` varchar(128) NOT NULL default '',
`name` varchar(128) NOT NULL default '',
`uid` smallint(5) unsigned NOT NULL default '5000',
`gid` smallint(5) unsigned NOT NULL default '5000',
`home` varchar(255) NOT NULL default '/var/spool/mail/virtual',
`maildir` varchar(255) NOT NULL default 'blah/',
`enabled` tinyint(3) unsigned NOT NULL default '1',
`change_password` tinyint(3) unsigned NOT NULL default '1',
`clear` varchar(128) NOT NULL default 'ChangeMe',
`crypt` varchar(128) NOT NULL default 'sdtrusfX0Jj66',
`quota` varchar(255) NOT NULL default '',
`procmailrc` varchar(128) NOT NULL default '',
`spamassassinrc` varchar(128) NOT NULL default '',
PRIMARY KEY  (`id`),
UNIQUE KEY `id` (`id`)
) ;
The last few fields in the users table are not required, but useful if you extend later.

# To visualise the tables created:
describe aliases; describe domains; describe users;
# then quit mysql
exit;
Next is to edit the MySQL's my.cnf file. In Ubuntu/debian this is created by default. In Mandrake I had to manually create a blank one in /etc. But we need to configure it, so:
sudo vi /etc/mysql/my.cnf
In previous version you needed to comment out this line
#skip-networking
However in todays file the default is to bind the address to localhost, which is fine.
bind-address = 127.0.0.1
It is very useful at the start to log any SQL calls that makes it to MySQL. So enable this line:
log = /var/log/mysql/mysql.log
Then in a few weeks comment it out when everything is working, as it slows mysql down

Restart MySQL to make sure its picking up the new settings.
sudo /etc/init.d/mysql restart
Return to top.

Pop/IMAP
Courier IMAP
Please refer to previous edition for more explanations. But below is the details of what you need to change.

sudo vi /etc/courier/authdaemonrc
Change to mysql mode.
authmodulelist="authmysql"
Further down enable logging.
DEBUG_LOGIN=2
sudo vi /etc/courier/authmysqlrc
Changed user
MYSQL_USERNAME mail
Changed password to whichever you have chosen
MYSQL_PASSWORD mailPASSWORD
Changed database
MYSQL_DATABASE maildb
Changed users table
MYSQL_USER_TABLE users
Keep commented in crypt pw
MYSQL_CRYPT_PWFIELD crypt
Keep commented out clear pw
# MYSQL_CLEAR_PWFIELD clear
Added maildir
MYSQL_MAILDIR_FIELD concat(home,'/',maildir)
Added where clause
MYSQL_WHERE_CLAUSE enabled=1
Lastly you can have a look at the imapd file, but no changes is needed.
vi /etc/courier/imapd
Return to top.
Summary
You now have a basic mail server!
Before continuing to the advanced and secure mail server you must ensure the basic setup works. This will save you from loads of pain further on.
It is very easy to make typos, miss tiny steps, unclear steps or simple actual errors in this howto.

Insert stub data from data section

Apply advice from test section judicously

Ensure the mail server can receive email correctly first, then try sending.

Once you are positive the mail has been received, the mail folders have been automatically created,
only then you should test if you can actually read the emails before proceding

Ive created an EC2 bundle for this stage: flurdy-amis/ubuntu-mail-server-simple.

Return to top.


wrong evolution
Somewhere, something went terribly wrong
Advanced mail server
Now lets extend this setup with more useful content checks , security and user interfaces.

Content Checks (Anti spam & anti virus)
Amavisd-new
Amavisd ties together all the different ways of checking email content for spam and viruses.

The defaults are pretty good and also the ubuntu documentation is pretty clear, and recommended.

Here is a tweaked version of it:
Initially we will not enable spam or virus detection! This is so we can get amavis set up to receive, check and pass on emails before we go on and over-complicate it.

All of amavis' configuration files are in /etc/amavisd. They are now spread across several files in conf.d. Debian and Ubuntu defaults are now very sensible and spread into seperate files.
cd /etc/amavis/conf.d
01-debian defaults are fine.
Have a look at
less 05-domain_id
but dont change anything in it.

Have a look at
less 05-node_id
but dont change anything in it.

Have a look at
less 15-av_scanners
but dont change anything in it.

Edit content check file
sudo vi 15-content_filter_mode
Comment out both virus and spam scans. (Default).
# #@bypass_virus_checks_maps = (
#   \%bypass_virus_checks, \@bypass_virus_checks_acl, \$bypass_virus_checks_re);
# @bypass_spam_checks_maps = (
#   \%bypass_spam_checks, \@bypass_spam_checks_acl, \$bypass_spam_checks_re);
Have a look at
less 20-debian_defaults
but dont change anything in it.

25-amavis_helpers defaults are fine.
30-template-localization defaults are fine.
Edit user file
sudo vi 50-user
In the middle insert:
@local_domains_acl = qw(.);
$log_level = 2;
$syslog_priority = 'debug';
$sa_kill_level_deflt = 8.0; # triggers spam evasive actions
$final_spam_destiny       = D_PASS;
# $final_spam_destiny       = D_DISCARD;
We have not setup amavis to scan and pass along incomming email. Next we will setup postfix to talk to amavis.

vi /etc/postfix/master.cf
Append these lines to the end of the file (make sure they are not already present). (Note the -o lines have spaces in front of them.
amavis      unix    -       -       -       -       2       smtp
        -o smtp_data_done_timeout=1200
        -o smtp_send_xforward_command=yes
        -o disable_dns_lookups=yes
        -o max_use=20
127.0.0.1:10025 inet    n       -       -       -       -       smtpd
        -o content_filter=
        -o local_recipient_maps=
        -o relay_recipient_maps=
        -o smtpd_restriction_classes=
        -o smtpd_delay_reject=no
        -o smtpd_client_restrictions=permit_mynetworks,reject
        -o smtpd_helo_restrictions=
        -o smtpd_sender_restrictions=
        -o smtpd_recipient_restrictions=permit_mynetworks,reject
        -o smtpd_data_restrictions=reject_unauth_pipelining
        -o smtpd_end_of_data_restrictions=
        -o mynetworks=127.0.0.0/8
        -o smtpd_error_sleep_time=0
        -o smtpd_soft_error_limit=1001
        -o smtpd_hard_error_limit=1000
        -o smtpd_client_connection_count_limit=0
        -o smtpd_client_connection_rate_limit=0
        -o receive_override_options=no_header_body_checks,no_unknown_recipient_checks
Also add the following two lines immediately below the "pickup" transport service:
 -o content_filter=
        -o receive_override_options=no_header_body_checks
and then added to main.cf
sudo vi /etc/postfix/main.cf
content_filter = amavis:[127.0.0.1]:10024
Enable scanning by ClamAV of amavis' temporary files.
sudo adduser clamav amavis
This should be it to get amavis working. If emails are picked up by amavis and passed back to postfix then it looks okay. Next is to uncomment the anti virus and anti spam lines in
sudo vi 15-content_filter_mode
@bypass_virus_checks_maps = (
   \%bypass_virus_checks, \@bypass_virus_checks_acl, \$bypass_virus_checks_re);
@bypass_spam_checks_maps = (
   \%bypass_spam_checks, \@bypass_spam_checks_acl, \$bypass_spam_checks_re);
But do that after the next section (SpamAssassin).

When things are working we will turn down logging level, and start bouncing/discarding spam.
sudo vi /etc/amavis/conf.d/50-user
@local_domains_acl = qw(.);
$log_level = 1;
$syslog_priority = 'info';
$sa_kill_level_deflt = 8.0; # triggers spam evasive actions
#$final_spam_destiny       = D_PASS;
$final_spam_destiny       = D_DISCARD;
Return to top.
Anti-Spam
SpamAssassin
The default config of spam assassin is okay. You could refer to previous edition for more configuration options.

You do need to tell SpamAssassin to start smapd on boot.
vi /etc/default/spamassassin
ENABLED=1
One configuration option you could tweak is to enable Bayes and auto learning.
vi /etc/spamassassin/local.rf
I read your email
I read your email
Return to top.

Anti Virus
ClamAV
ClamAV does not need setting up. Configuration files are in /etc/clamav, but they are automatically generated, so do not edit.

By default freshclam, the daemon that updates the virus definition database, is run 24 times a day. That seems a little excessive, so I tend to set that to once a day.
sudo dpkg-reconfigure clamav-freshclam
It will also ask if you want it to be daemon (yes) and which server is closest to you.

If needed, the command below will redefine the configuration with a lot of questions. Not needed unless you need to configure.
sudo dpkg-reconfigure clamav-base
Return to top.
Postgrey
The default config of postgrey is okay. However you need to tell Postfix to use it.
sudo vi /etc/postfix/main.cf
And then edit the recipient restrictions:
smtpd_recipient_restrictions = reject_unauth_pipelining, permit_mynetworks, permit_sasl_authenticated,
		reject_non_fqdn_recipient, reject_unknown_recipient_domain, reject_unauth_destination,
		check_policy_service inet:127.0.0.1:10023, permit
You can tweak whitelisting in /etc/postgrey. You can tweak postgrey configuration by tweaking /etc/default/postgrey. E.g. delay, auto whitelisting, or reject message.
POSTGREY_OPTS="--inet=10023 --max-age=365"
Return to top.
You know have an advanced mail server. You can use this, but Id recommend continuing. However this is a good point to test the set up so far and to insert some data in the db.

Ive created an EC2 bundle for this stage: flurdy-amis/ubuntu-mail-server-spam.

Return to top.


no, i will not fix your computer
No, I will not fix your computer
Secure mail server
Stopping hackers, phishers, spammers, your boss and your neighbour from accessing your server or the traffic in between is important, and easily done.

Authentication
Normal email traffic between clients and servers are in open plain text. That includes passwords and content of emails.

SASL
SASL secures the actual authentication (login), by encoding the passwords so that it can not be easily intercepted. The rest of the emails are however in clear plain text.

This is a section I will revisit for the next edition! Meanwhile please refer to previous edition for more detail.

Encryption
TLS
Encrypting the traffic stops anyone else listening in on your email communications. And is very recommended. There are different types of communication to encrypt: The data traffic between your email applications and the server when you read emails or when you send emails, and communication between other email servers and your server.

For the encryption of reading emails, it is Courier you need to configure. For sending, and beetwen server encryption it is Postfix.

TLS in Postfix
To encrypt you need certificates. Ubuntu creates some for you for which you can use while setting up the server. However before you go live, it is recommended to create your own with your proper domain name etc. Please refer to previous edition for more detail.

vi /etc/postfix/main.cf
There are already some TLS settings in the default debian/ubuntu version of this file. I moved these to the end, for clarity, but that is up to you.
# TLS parameters
#smtp_use_tls = no
smtp_tls_security_level = may
#smtpd_use_tls=yes
smtpd_tls_security_level = may
#smtpd_tls_auth_only = no
smtp_tls_note_starttls_offer = yes
smtpd_tls_loglevel = 1
smtpd_tls_received_header = yes
smtpd_tls_session_cache_timeout = 3600s
tls_random_source = dev:/dev/urandom
smtpd_tls_cert_file=/etc/ssl/certs/ssl-cert-snakeoil.pem
smtpd_tls_key_file=/etc/ssl/private/ssl-cert-snakeoil.key
#smtpd_tls_session_cache_database = btree:${data_directory}/smtpd_scache
#smtp_tls_session_cache_database = btree:${data_directory}/smtp_scache
Next we have a look at the master.cf file.
vi /etc/postfix/master.cf
By default only the normal smtp service is enabled, which is fine. But I prefer to enable submission (port 587), so that clients can use it, and I can restrict them to TLS only. Also enabled smtps service (port 465), for some compatebility with some older clients (outlook express etc).

submission inet n       -       n       -       -       smtpd
  -o smtpd_sasl_auth_enable=yes
# if you do not want to restrict it encryption only, comment out next line
  -o smtpd_tls_auth_only=yes
# -o smtpd_tls_security_level=encrypt
#  -o header_checks=
#  -o body_checks=
  -o smtpd_client_restrictions=permit_sasl_authenticated,reject_unauth_destination,reject
  -o smtpd_sasl_security_options=noanonymous,noplaintext
  -o smtpd_sasl_tls_security_options=noanonymous
# -o milter_macro_daemon_name=ORIGINATING
smtps     inet  n       -       -       -       -       smtpd
  -o smtpd_tls_wrappermode=yes
  -o smtpd_sasl_auth_enable=yes
  -o smtpd_tls_auth_only=yes
  -o smtpd_client_restrictions=permit_sasl_authenticated,reject
  -o smtpd_sasl_security_options=noanonymous,noplaintext
  -o smtpd_sasl_tls_security_options=noanonymous
#  -o milter_macro_daemon_name=ORIGINATING
TLS in Courier
Again Ubuntu has created a certificate for you, but if you want to create your own, especially for a properly named server, then do this.
cd /etc/courier
openssl req -x509 -newkey rsa:1024 -keyout imapd.pem \
  -out imapd.pem -nodes -days 999
For more details review last edition.

Then you need to edit
vi /etc/courier/imapd-ssl
By default Ubuntu already points to you certificate
TLS_CERTFILE=/etc/courier/imapd.pem
Modify this if needed.

Also you if want to restrict IMAP users to SSL/TLS only toggle this setting to 1.
IMAP_TLS_REQUIRED=1


For maximum compatability it is not wise to restrict to TLS only for the traffic between servers. As this means not all valid emails sent by others can reach your server. However enabling them the option to encrypt is a good idea.

Be aware that the emails are not encrypted on your machine, nor on the server. For this type of client encryption, please refer to previous edition for more on GnuPG.

In some situations SASL and TLS do not play well together. Those situations are in combinations of storing encrypted passwords, using MD5 authentication over encrypted traffic. I recommend, insisting on TLS traffic with your authenticating clients, which then negates the need for SASL.

You know have an advanced secure mail server. Now is another good point to test the set up so far and to insert some data in the db.

Ive created an EC2 bundle for this stage: flurdy-amis/ubuntu-mail-server-secure.

Return to top.


Webmail
Using among others the https://help.ubuntu.com/community/Squirrelmail as an updated reference.

Alternative
If you prefer the prettier Roundcube, but less powerfull (at the moment), the follow the Roundcube section in the extention section.

Enable web access
You may need to enable web access in the firewall. Check the firewall configuration if this neccessary.

You need to copy a SquirrelMail configuration to apache.
sudo cp /etc/squirrelmail/apache.conf /etc/apache2/sites-available/squirrelmail
And enable with this:
sudo ln -s /etc/apache2/sites-available/squirrelmail /etc/apache2/sites-enabled/500-squirrelmail
Or as Florent recommends, use:
sudo a2ensite squirrelmail
You may accept the default apache configuration where squirrelmail is folder in all sites. But I prefer virtual hosting. But you dont need to do these next steps.
sudo vi /etc/apache2/sites-available/squirrelmail
Comment out the alias.
# alias /squirrelmail /usr/share/squirrelmail
Uncomment the virtual settings., and insert your servers name.
# users will prefer a simple URL like http://webmail.example.com

  DocumentRoot /usr/share/squirrelmail
  ServerName webmail.example.com
If you have apache SSL enabled in apache, then you can also uncomment the mod_rewrite section for further security.

Reload apache to activate changes. First test if ok.
sudo apache2ctl -t
Then reload it.
sudo /etc/init.d/apache2 reload
You can now go toyourdomain.com/squirrelmail/ or mail.yourdomain.com if you chose virtual host. This should show a squirrel mail page. Log in wont work yet though.

Start configuring squirrel mail.
sudo squirrelmail-configure
Initially change nothing. You can customize more afterwards. You can browse, and exit sub menues by typing R.

Type 2 to edit server settings. Type A to edit IMAP settings.

Type 8 to edit server software. Enter courier.
courier
Now they say using TLS over localhost is a waste of time. But I do anyway. Type 7 to edit secure IMAP. Type
Y
to enable it.

Type 5 to edit IMAP port. Enter
993
Type S to save your changes. Hit Enter.

Type Q to exit.

You can now go to yourdomain.com/squirrelmail/ or mail.yourdomain.com if you chose virtual host. This should show a squirrel mail page. Log in will now work. (Except you may not have defined users, check data section. And they may not have received an email which also means you can not view any IMAP info.)

Please refer to previous edition for more detail. E.g. creating address books and user preferences.

Return to top.
Administration
Enable web access
You may need to enable web access in the firewall. Check the firewall configuration if this neccessary.

You need to copy a phpMyAdmin configuration to apache.
sudo cp /etc/phpmyadmin/apache.conf /etc/apache2/sites-available/phpmyadmin
And enable with this:
sudo ln -s /etc/apache2/sites-available/phpmyadmin /etc/apache2/sites-enabled/400-phpmyadmin
Or as Florent recommends, use:
sudo a2ensite phpmyadmin
You may choose to restrict phpMyAdmin to a spefic virtual host. If so you need to, edit
sudo vi /etc/apache2/sites-available/phpmyadmin
and comment out the alias. And insert the alias into a virtual host configuration. For this example we are not.

Reload apache to activate changes. First test if ok.
sudo apache2ctl -t
Then reload it.
sudo /etc/init.d/apache2 reload
You can now go to http://yourdomain.com/phpmyadmin/, and login with the mail user. You can use it as it is, but I recommend securing it a bit more.

One simple way is adding apache's .htaccess login requirement.

Further restrictions can be restricting to a specific virtual host. Or renaming the folder. Purely ubfuscating, but simple.

Or using the example in the webmail section, and adding SSL requirement to the connection. Or disabel mysql root's access via phpMyAdmin.

Please refer to previous edition for example on htaccess, and mysql user restriction.

You know have a finished mail server. This is as far as the main guide goes. Hope it was clear enough to follow.

Now it is time to insert data, and to test how it works.

Feel free to extend it with my suggestions further down.

Ive created an EC2 bundle for this stage: flurdy-amis/ubuntu-mail-server-webmail.


Return to top.
Data
Add users and domains

Required domains and users

Example domains and users

Adding template

Common SQL

Add users and domains
So we got a fully set up mail server... Well no, there is no users, domains, no nothing!

Okay, first you need add some default data, some which are required, some which make sense.

Then we'll add your own users and domains.

Required domains and users
First the required domains for local mail

# Use phpMyAdmin or command line mysql
INSERT INTO domains (domain) VALUES
	('localhost'),
	('localhost.localdomain');
Then some default aliases. Some people say these are not needed, but I'd include them.

INSERT INTO aliases (mail,destination) VALUES
	('postmaster@localhost','root@localhost'),
	('sysadmin@localhost','root@localhost'),
	('webmaster@localhost','root@localhost'),
	('abuse@localhost','root@localhost'),
	('root@localhost','root@localhost'),
	('@localhost','root@localhost'),
	('@localhost.localdomain','@localhost');
Then a root user.

INSERT INTO users (id,name,maildir,crypt) VALUES
	('root@localhost','root','root/', encrypt('apassword') );
I see dumb people
Domains and users
Now lets add some proper data.

Say you want this machine to handle data for the fictional domains of "blobber.org", "whopper.nu" and "lala.com".

Then say this machine's name is "mail.blobber.org".

All email to lala.com is to be forwarded to whupper.nu.

INSERT INTO domains (domain) VALUES
	('blobber.org'),
	('mail.blobber.org'),
	('whopper.nu'),
	('lala.com');

INSERT INTO aliases (mail,destination) VALUES
	('@lala.com','@whupper.nu'),
	('@mail.blobber.org','@blobber.org'),
	('postmaster@whopper.nu','postmaster@localhost'),
	('abuse@whopper.nu','abuse@localhost'),
	('postmaster@blobber.org','postmaster@localhost'),
	('abuse@blobber.org','abuse@localhost');
You also have two users called "Xandros" and "Vivita".

INSERT INTO users (id,name,maildir,crypt) VALUES
	('xandros@blobber.org','xandros','xandros/', encrypt('apassword') ),
	('vivita@blobber.org','vivita','vivita/', encrypt('anotherpassword') );

INSERT INTO aliases (mail,destination) VALUES
	('xandros@blobber.org','xandros@blobber.org'),
	('vivita@blobber.org','vivita@blobber.org');
You want all mail for whooper.nu to go to xandros (catchall).

INSERT INTO aliases (mail,destination) VALUES
		('@whopper.nu','xandros@blobber.org');
There is also a "Karl" user, but he does want all mail forwarded to an external account.

INSERT INTO aliases (mail,destination) VALUES
	('karl@blobber.org','karl.vovianda@gmail.com');
So what does each of these lines actually do? Well the domains are pretty straight forward.

The users are as well, it requires four fields. ID is the email address of the user, and also its username when loggin in, described later on. NAME is optional description of the user. MAILDIR is the name of the folder inside /var/spool/mail/virtual. It must end in a /, otherwise it wont be used as a unix maildir format. CRYPT is the encrypted text password to use.

The alises are the interesting part. Lets start from a top down view to see how emails get delivered:

Say an email arrives addressed to "john@whopper.nu".

Postfix looks up domains and say whopper.nu is an domain it listens to.

Postfix then looks up aliases and searches for a row where the mail field matches "john@whopper.nu".

None does so it next searches for "@whopper.nu", which is the way to specify catch all others for that domain.

It finds one row and its destination is "xandros@blobber.org".

It then searches for "xandros@blobber.org" and finds one, which destination is the same as the mail, therefor it is the final destination.

It then tries to deliver this mail. The look up says blobber.org is a local mail so it looks up users for a matching id and delivers it to its maildir.

Lets try "julian.whippit@lala.com".

Postfix looks up domains and it is an domain it listens to.

First lookup does not find this user, but the next finds the catchall "@lala.com". But its destination is another catchall, "@blobber.org".

This means Postfix will look for "julian.whippit@blobber.org". This address is not found either, nor is a catchall for blobber.org. Therefor this address is not valid and the message will be bounced.

Any mail arriving for "karl@blobber.org" or "karl@lala.com", gets forward to an external address of "karl.vovianda@gmail.com". So forwarding is simple. I tend to use a subdomain for all my friends addresses as easily I forget what their real addresses are, and I use different email clients all the time.

I also added the required aliases of postmaster and abuse to blobber.org and whopper.nu. The catchall for lala.com means they are not required for that domain.
Another useful alias to add is root, as often you get admin mail from e.g cron jobs within those domains etc. Other often used aliases are info, sysadmin, support, sales, webmaster, mail, contact and all. But they are also honeypots for spam, so just include the ones you think you will need.

Adding template
So to add a new domain to the system, You do this, replacing the italics with relevant data:

INSERT INTO domains (domain) VALUES ('domain.tld');
INSERT INTO aliases (mail,destination) VALUES
	('@domain.tld','email@address'),
	('postmaster@domain.tld','email@address'),
	('abuse@domain.tld','email@address');
And to add a new user to the system, do this:

INSERT INTO users (id,name,maildir,clear) VALUES
	('email@address','short description','foldername/',encrypt('password'));
INSERT INTO aliases (mail,destination) VALUES
	('email@address','email@address');
Return to top.
Common SQL
A selection of useful sql statements, if you are not using an admin/manager program to maintain your email domains and users.

Find domains without a catchall

#Remember some might be disabled
SELECT dom.domain
FROM domains dom
LEFT JOIN aliases al
	ON CONCAT( '@', dom.domain ) = al.mail
WHERE al.mail is null
OR al.enabled = 0
ORDER BY dom.domain ASC
Find aliases for an invalid domain
SELECT al.*
FROM aliases al
LEFT JOIN domains dom
	ON dom.domain = SUBSTRING(al.mail,LOCATE('@',al.mail)+1)
WHERE dom.domain is null
OR dom.enabled = 0
ORDER BY al.mail ASC
Find all non local destination aliases
SELECT al.*
FROM aliases al
LEFT JOIN domains dom
	ON dom.domain = SUBSTRING(al.destination,LOCATE('@',al.destination)+1)
WHERE dom.domain is null
ORDER BY al.enabled, al.destination ASC, al.mail ASC
Find all aliases for a certain domain
SELECT al.*
FROM aliases al
WHERE SUBSTRING(al.mail,LOCATE('@',al.mail)+1) = 'domain.tld'
ORDER BY al.enabled, al.mail ASC
Find all aliases for a certain domains, checking if enabled for both domain and alias
select *
from domains d
join aliases a
  on a.mail like concat( '%','@',d.domain)
  and a.enabled = 1
where d.enabled = 1
and d.domain like '%foobar%'
order by d.domain,a.mail
Return to top.
Test

Common problems

Test strategy

Tail, tail and tail again

Switch off services

Switch debug on

Telnet is your friend

Can postfix receive?

Can postfix send?

Can courier read?

Common problems
Missed a step
If you mistakenly or intentially skipped past sections, you may have missed an important step in your configuration, which my guide pressumes you have followed.

Typo
99% of all problems is spelling errors or typos you entered while following this guide. Sorry, but it just happens. Often it can be trivial, such as a space at the end of the configuration line which was not expected etc. Or not understanding my example where it is a multi line entry.

Typo by me
Yes, I make a lot of mistakes. Nothing wrong in that, but I hope I have corrected most over time. Any new sections are however at risk... :)

Different application or configurations
It is obviously entirely up to you how you set up your system. But the more you deviate from this guide, the more likely incompatibilties or confusion will arrise.

Distrobution/version differences
If you run a different version or even distrobution to this guide, then some things will be different. Small issues, such as default values and significant things such as path differences etc. Some sections in this guide are not always thouroughly tested with every new release of Ubuntu, but these differences gets pointed out by people for me.

Walking before crawling
Don't try the full blown mail server before the basics are working.

Gamma rays and little goblins
Got to blame it on something or someone.

Return to top.

Test strategy
What steps to think of when testing.

Test early and frequently
It is very helpfull to test early in this set up, to establish if the first sections are working as expected.

So when you only have your very basic postfix and mysql up: Test it!
That way you know that bit worked and can rule it out of any future problems.
Don't wait till you complicated and mudded the water after amavis, courier etc is added.

By constantly testing if you can send and receive you can tick off and black box each section as working, and immidietly spot issues.

Isolate the problem
Testing how things work is often about isolating the problem first. So by using the steps of testing early above, you can see which step caused the problem.

Also if you can't log into your webmail it is often nothing to do with the webmail section that is causing the problem. Often postfix itself is broken etc.

Test in order
As part of the isolating the problem rule, you most of the time test in order, and test each section thus isolating the problem. This would then quickly isolate the problem when e.g. such as above issues of reading emails via the webmail. This would be in order:

Access: Can I get(ssh) to the box, and is there a firewall issue?

Database: Is the database up, do my application reach it?

Postfix: Can I send email by command line, do I receive emails via telnet?

Content checks: Do they cause a problem?

Courier: Can I read emails?

Webmail: And last but not least does the web integration work?

Simplify the system
Assisting in isolating the problem, you often have to disable options and applications. Such as turn of postgrey or content checks to make sure emails to get delivered.

Previous editions do have some more detail on how to achieve this

Return to top.

Tail, tail and tail again
Essential to monitor what actually happens, and tailing specifically the mail and mysql log.

/var/log/system.log

/var/log/mail.log

/var/log/mysql.log

/var/log/apache2/access.log

In one window:
tail -f /var/log/mail.log
And in another window:
tail -f /var/log/mysql.log
In a third or more do your actual configuration or testing.

Return to top.

Switch off services
previous edition 1

previous edition 2

The previous editions has detail on switching services off untill time to test them.
It also details locking down your server from spammers untill finished testing.

Return to top.

Switch debug on
Shorewall
You can also switch on more messages for when the firewall is rejecting connections. Add info to all REJECT, BOUNCE and DROP policies.
sudo vi /etc/shorewall/policy
such as:
net	all	DROP		info
MySQL
There is no point in tailing the mysql log if query debugging is not turned one.
By default it is not. However in this guide I do switch it on, in case that was missed switch it on now:
sudo vi /etc/mysql/my.cnf
Make sure this is not commented out
log = /var/log/mysql/mysql.log
Courier
As mentioned in the setup , switching on debugging for Courier is easy:
sudo vi /etc/courier/authdaemonrc
DEBUG_LOGIN=2
Amavis
You can also debug amavis:
sudo vi /etc/amavis/conf.d/50-user
And perhaps bump it up if already debugging:
$log_level = 2;
Return to top.

Telnet is your friend
When testing a mail server, telnet is alpha & omega. You use it to simulate real mail servers to test responses by your mail server.

First you test it on the server to exclude firewall and network issues.

Then you test it from another machine to simulate an actual other mail server.

Once these are working you can use proper email clients, however 99% I just use mutt locally when I need to test if a server is working.

Return to top.

Can postfix receive?
Lets assume:

You have followed my guide up to basic configuration at least

You have entered data into the database

The services MySQL and Postfix are running.

If testing a fuller stack, then amavis, postgrey, clamav-daemon, spamassassin etc must also be running.

Try this locally on the server first, then try from another machine once it is working locally.

Lets try and send a message to xandros@example.org (replace with your own user in this setup, or use postmaster@localhost) from you@example.com (again replace with a real email address you use that is not associated with this server.)
telnet localhost 25
# Open the hand shake with ehlo and the server name you are connecting from...
# Change mail.example.com to something valid eg your servername
EHLO mail.example.com
# The mail server will then dump out some details about its capabilities, e.g.
>250-mail.flurdy.net
>250-PIPELINING
>....
>....
# then say who is the sender of this email
MAIL FROM: <your@example.com>
> 250 Ok
# then say who the mail is for
RCPT TO: <xandros@example.org>
> 250 Ok
# then enter the keyword data
data
> 354 End data with <CR><LF>.<CR><LF></LF></CR></LF></CR>
# enter message bodyand end with a line with only a full stop.
blah blah blah
more blah
.
> 250 Ok; queued as QWKJDKASAS
# end the connection with
quit
> 221 BYE
If while you were doing this you were tailing the /var/log/mail.log you would see some activities and if any errors occured. (You should probably get some complaints about missing headers as we skipped most...)

If while you were doing this you were tailing the /var/log/mysql.log as well you really should have seen some activity otherwise you have a problem.

If you see any errors (or worse no activity) in these log files, this is what you need to fix! For common problems and solutions check the previous edition.


However if no errors popped up, and the folder /var/mail/virtual/xandros now exists then your server can receive emails!

Return to top.

Can postfix send?
You need to make sure you can first receive emails as above

The services MySQL and Postfix are running.

Basically you just tested that above, but we need double check if it can send out to other servers. Again we will first test locally, which should work, then remotely which introduces many possible problems.
telnet localhost 25
# Open the hand shake with ehlo and the server name you are connecting from...
# This time it has to be the name of your server
EHLO mail.example.org
# The mail server will then dump out some details about its capabilities, e.g.
>250-mail.flurdy.net
>250-PIPELINING
>....
>....
# then say who is the sender of this email, which is a local user
MAIL FROM: <xandros@example.org>
> 250 Ok
# then say who the mail is for which is an external address e.g. gmail etc.
RCPT TO: <you@example.com>
> 250 Ok
# then enter the keyword data
data
> 354 End data with <CR><LF>.<CR><LF></LF></CR></LF></CR>
# enter message bodyand end with a line with only a full stop.
blah blah blah
more blah
.
> 250 Ok; queued as QWKJDKASAS
# end the connection with
quit
> 221 BYE
We have to assume receiving works above so no need to tail mysql's logs. However if any rejection errors occured in the mail.log then you have an error.

However if no errors occured and you see in the log something like this:
Dec 17 10:25:45 servername postfix/smtp[12345]: 12345678: to=<you@example.com>, relay=127.0.0.1[127.0.0.1]:10024,
delay=15, delays=15/0.01/0.02/0.11, dsn=2.0.0, status=sent (250 2.0.0 Ok, id=12345-09, from MTA([127.0.0.1]:10025):
250 2.0.0 Ok: queued as 1234567)
Then the sending emails work!

Return to top.

Kill Bill
Can courier read emails
You need to make sure you can first receive emails as above

You need to make sure you can send emails as above

You need to make sure you have received an email and the folder /var/mail/virtual/xandros exists

The services MySQL, courier-authdaemon and courier-imap are running.

There is not too much you can test via telnet for courier. But you can check if it is up and you can connect to it.
telnet 127.0.0.1 10024
Trying 127.0.0.1...
Connected to 127.0.0.1.
Escape character is '^]'.
220 [127.0.0.1] ESMTP amavisd-new service ready
The rest you would have to test via a proper email IMAP client.

Return to top.
Intialize
Brief hints if you receive a ready setup machine (or EC2 AMI), and what then to check and to customize it to your setup.

Stop services

Restrict firewall

Change passwords

Check configurations

Set machine name

Certificates

Start and test services

Insert data

Reload postfix

Open firewall

Test

Stop services
First stop services so they wont accidentally do something.
sudo /etc/init.d/postfix stop
sudo /etc/init.d/courier-imap-ssl stop
sudo /etc/init.d/courier-imap stop
sudo /etc/init.d/courier-authdaemon stop
sudo /etc/init.d/mysql stop
sudo /etc/init.d/amavisd stop
sudo /etc/init.d/spamassassin stop
sudo /etc/init.d/clamav stop
Restrict firewall
Check what the firewall rules are.
vi /etc/shorewall/rules
Refer to the . Restrict to just SSH access for now.

Change passwords
Next the passwords needs to be changed. For both the system and mysql.

System passwords
Check which users are defined on the system.
cat /etc/passwd
Apart from all the system ones, there should probably be none (if EC2 AMI) or just your user if it is a standard Ubuntu install. If there are some users, you need to change their passwords.

SSH Access
Next we check whom got SSH access. If there was any users defined, check their home folders for ssh keys.
cat /home/username/.ssh/auth*
Remove any you do not expect to be there. Next check if and which specific users has been defined for SSH access in
vi /etc/ssh/sshd
Usually this is fine.

MySQL passwords
First you need to change the root mysql user. If none has been set do this
mysqladmin -u root password new_password
Otherwise do this and you will be prompted for the old password
mysqladmin -u root password new_password -p
Then the default mail user as well. If you know the old password
mysqladmin -u mail password new_password -p
Otherwise log into mysql as root:
mysql -u root -p
Enter new root password specified above, then:
update mysql.user set password=password('apassword') where user='mail';
flush privileges;
You may need to revisit the top of MySQL section to re-grant the mail use rights on the database.

If you do not know the old root password, you have to restart mysql without grant rights. Google it... :)

Update postfix mysql configuration files with the new password.
sudo vi /etc/postfix/mysql*
password=apassword
Update courier's authmysql file with the new password as well.
sudo vi /etc/courier/authmysqlrc
MYSQL_PASSWORD apassword
Check configurations
You should scan the postfix, courier, etc. configurations to check if they match what you expect.

Set machine name
Now you need to define your machine name, e.g. something like smtp.yourdomain.com. You need to define it in
sudo vi /etc/mailname
And then your domain name in
sudo vi /etc/postfix/main.cf
under the mydomain setting
myorigin=yourdomain.com
It could also be smart to check what the unix hostname is specified as
hostname
This can be reset by
sudo hostname smtp.yourdomain.com.
All though this does not have to be the same as your postfix mail server name. You may want to speficiy some hosts in hosts file as well,
sudo vi /etc/hosts
127.0.0.1 localhost.localdomain localhost
127.0.0.1 smtp.yourdomain.com smtp
Certificates
You could go along with the generated certificates (if they are there, default for Ubuntu). Or if you could create new ones with the correct machine name in them. Especially if this a mail server used by many, and authenticiy is important. Follow the TLS certificate instructions for Postfix and Courier.

Start and test services.
Next you need to start your mail services and test them.
sudo /etc/init.d/mysql start
sudo /etc/init.d/spamassassin start
sudo /etc/init.d/clamav start
sudo /etc/init.d/amavisd start
sudo /etc/init.d/postfix start
sudo /etc/init.d/courier-imap-ssl start
sudo /etc/init.d/courier-imap start
sudo /etc/init.d/courier-authdaemon start
So test tjenestene via testing section.

Insert data
Insert your mail domains, aliases and users using the data section.

Some times there are test data already in the database. Remove them. E.g.;
mysql -u mail -papassword maildb
delete from domains where domain = 'bar.com';
delete from aliases where mail = 'foo@bar.com';
Open firewall
Then open up the firewall, follow the world access bit in the firewall configuration. Voila. Up and running. Well we hope.

Return to top.
Extend
Kill Bill
Please refer to previous edition for how and why you can extend this mail server.

By now you should have a fully working system. No point extending and complicating it untill then. What next? There are many ways to extend the server, to create your own powerfull customized version.

Remote MX mail backup

Local file backup

Sender ID & SPF

Spam reporting

White/Black lists

PGP & S/MIME

Relocation notice

Pop-before-SMTP

Admin Software

Auto Reply

Block Addresses

Throttle Output

Mail Lists

Roundcube webmail

Sugestions?

Some of these sections can be brief as they are not core to this howto.

Remote MX mail backup
With MX backup loosing emails are unlikely.

Normally if someone sends an email destined for you, their server will try and connect to your server. If it can't reach your server for whatever reason ( it is down, dns issues, there is network problems, or just too busy ), the other server will back off and try again in a bit. How many and for how long it will try again is determined by the sending server. Some of them are not very patience, and it will report undelivered after only a few attempts. So you would have lost that email.

If you had specified a backup MX, this email may not have been lost. Upon first failure to connect to your server, the sender would see if there is any alternative server to send to. So it connects to your backup mx server. This server spools and queues your message and will try at intervals to send the message to you. It too will though eventually give up.

What is the difference? Simple, you (or whoever controls the backup mx ) is in control how long and often to try connecting to your machine. So if you have a reasonable values and your server is not down for weeks, no mail is lost.

How to implement it? First edit the DNS records again, and add a backup mx with a higher value.

# your server details
domain.tld	IN	MX	10	your.mailserver.name.tld
# new backup server
domain.tld	IN	MX	20	your.backupserver.name.tld
Now presuming the other backup mx is a postfix server identical to this, or you are backuing up someone else's server; Go into mysql and create this tables:
CREATE TABLE `backups` (
	`pkid` smallint(6) NOT NULL auto_increment,
	`domain` varchar(128) NOT NULL default '',
	`transport` varchar(128) NOT NULL default ':[]',
	`enabled` smallint(6) NOT NULL default '1',
	PRIMARY KEY  (`pkid`),
	UNIQUE KEY `domain` (`domain`)
);
Then still on the backup server, edit main.cf and add these:

relay_domains = mysql:/etc/postfix/mysql_backups.cf
transport_maps = mysql:/etc/postfix/mysql_transport.cf
You may choose to have this as the last line in the file, as you may use small cron jobs to modify this ip address, if you don't have a permanent static address. It should contain your IP addres, hence if you do not have a very static IP address, that you need to automatic editing if the postfix file.

proxy_interfaces = 1.2.3.4
If someone comes with a better way, then let me know.

Next create this file /etc/postfix/mysql_backups.cf

user=mail
password=apassword
dbname=maildb
table=backups
select_field=domain
where_field=domain
hosts=127.0.0.1
additional_conditions = and enabled = 1
Next create this file /etc/postfix/mysql_transport.cf

user=mail
password=apassword
dbname=maildb
table=backups
select_field=transport
where_field=domain
hosts=127.0.0.1
additional_conditions = and enabled = 1
You noticed I added a transport lookup. This is a field in both the domain and the backup tables. In domains it is used to determine how to deliver the email, ie either virtual (correct) or local (not used in this howto). When backing up servers, your also need to specify in the transport field how to connect to the correct servers.

Say you are backiup for a friends server, mail.friend.com, for the domains of friend1.com and friend2.com. So you should insert this into your backup table.

INSERT INTO backups (domain,transport)
VALUES ('friend1.com' , ':[mail.friend.com]' ),
('friend2.com' , ':[mail.friend.com]' );
The :[] tells to connect directly to this server, not doing any more look ups for valid MX servers.

This shouls now work fine. Further tweaking of the queue values, review these and modify as appropiate. Shorter warning times are good for the sender, so that they realise the email has not arrived yet, but may also be annoying. Tradeoffs.. Look in the first main.cf configurations for ways to do so.

Return to top.
Local file backup
Here is rough backup script to backup your configurations and mail folders. You may want to backup the folders seperatly as they can quickly grow to GBs. Adding this to a cronjob automates this process. Be aware that you should stop postfix and courier while backing up the mail folders. And that if they have grown large, that this may take some time.

tar czf mail-config.xxxxx.tgz /etc/postfic /etc/courier /etc/spamassassin /etc/clamav /etc/amavis /etc/mysql/my.cnf
tar czf mail-fold.xxxx.tgz /var/spool/mail/virtual
mysqldump -u mail -papassword -t maildb > data.sql
mysqldump -u mail -papassword -d maildb > schema.sql
tar czf mail-data.xxx.tgz schema.sql data.sql
tar cf mail.xxxxx.tar  mail-*.xxxxx.tgz
You may combine a full backup with a intermediate update of what has changed recently only.

tar --newer-mtime "2005-01-01"
Return to top.
Sender ID & SPF
Further security features is using Microsoft's Sender ID or Pobox's SPF. I'd use SPF as there is much argument over Sender ID.

spf.pobox.com

www.microsoft.com/mscorp/safety/technologies/senderid/

SPF should limit who can send mail on behalf of your domains, and is an open design. I do recommend SPF, with some reservations, detailed below.

While Microsoft is not always entirely evil, as sometimes they do nice things and make some useful software, I would prefer not to be locked into their Sender ID technology.

SPF configuration
The pobox site has some nice SPF generation tools to setup your SPF configuration. Probably best to use theirs.

But the way I have my setup, is generally one domain with detailed SPF, then all other domains just with an SPF alias to it. e.g:

Main domain DNS TXT field:

"v=spf1 a mx a:myserver.example.com include:aspmx.googlemail.com include:gmail.com ~all"
The important elements are:

I list the mail servers and websites associated with this domain (the a and mx bit).

I then specifically list the name of a server I may send mail from applications automatically using addresses within this domain.

As you can see I also use Google Apps with this domain, thus tell SPF to also allow all mail servers associated with google mail.

Then for most of the other domains I would use this DNS TXT field:

"v=spf1 a mx include:example.com ~all"
The important elements are:

I list the mail servers and websites associated with this domain

Then I tell SPF to also allow all mail servers associated with my main domain (example.com).

And for all these I use ~all!
Ps. Some domains I have added an even stricter SPF, as these are domains that will never send an email.

SPF problem
It is worth noting about SPF, that you should leave the decision to whether to reject or allow the email to the mail servers. Therefor using -all instead of ~all is not a good choice. Leave it to the SPAM scoring by the receiving server, like SpamAssasin does it. You then minimise the risk of false positives.

One of the reason I do discourage -all use, is that SPF has a distinct problem:
It does not like email forwarding or use of backup MX!

Consider this: Your address of lulu@hoopa.com sends a joke email to a few friends. One of these is trixie@bellbell.org.
Trixie's email address is actually an alias and forwards the email to her private webmail account on hotmailnot.com.

Now if your domain, hoopa.com, have a strict SPF set up, which only allows emails to be sent by its mail server. And you/the mail admin has added -all to the SPF, which tells other server to reject emails not from your server. This you think makes sense, spammers can not use your domain for spoof emails.

So what happens: bellbell.org receives the email from lulu, and possible checks the SPF, which is OK, and forwards it on to hotmailnot.com.
However if hotmailnot.com also checks SPF, it will receive the email from bellbell.org, check the SPF to see bellbell.org's mail server is allowed to send emails on behalf hoopa.com. SPF will say No!, and with the -all, hotmailnot.com email server will reject the email!

2nd scenario if lulu email trixie directly at hotmailnot.com, but hotmailnot.com main mail server was down, and email was sent to the backup mx server. When the main server came online again, and the backup spooled the email back to it, the SPF would again fail as the hoopa.com's SPF would not mention hotmailnot.com backup mx as an allowed mail server.

Solution:
Of course you can not list all possible forwarding / backup mx email server that your domain's users might at some point email!
I simple just use the ~all option. Which simple say it is not the expected server, but probably ok.
And if this is added to a scoring by the receiver, then the accumulated spam score might be enough to reject dodgy emails.

Return to top.
Spam reporting
todo
Reporting spam to Pyzor, Razor and SpamCop, for collaboration in spam fighting.

More detail on SpamCop is here.

pyzor.sourceforge.net

razor.sourceforge.net

Return to top.
White/Black Lists
todo
You can implement white and black lists to explicitly allow or block domains and users.

You have already visited the option of a blackhole list of known open relays in the postfix configuration.

You can implement further lists inside Postfix or SpamAssassin. Amavisd-new already has a few well known white/black listed items in its config files. SpamAssissin also as a feture to automaticly learn white lists.

Return to top.
PGP & S/MIME
Adding support for GnuPG and S/MIME increases indiviual security.

This is not implemented on the postfix server side, as this totally a client side option.

However SquirrelMail has a GnuPG option. It is a plugin that can be downloaded from their website. Which can then be enabled via SquirrelMail's config script.

Here is how to create a GnuPG key pair.

# check you have not already got a key
gpg --list-keys
# then create one
gpg --gen-key
To import GnuPG into Evolution; in your settings/preferences edit your account settings and add you private key under the security tab. The private key is found via listing the GnuPG keys as above, then it is the 8 characters after the "sub 1024g/" bit of you key.

To use GnuPG with Thunderbird you need to install EnigMail.

S/MIME is another way to encrypt and/or sign messages. You can create you own certificate or use known organizations like Thawte. (Thawte was originally set up by the Ubuntu founder)

Return to top.
Relocation notice
If people change addresses, a bounced message stating so if people send email to the old address is quite useful. To implement this in postfix, frst create a lookup table in the database.

CREATE TABLE `relocated` (
`pkid` smallint(6) NOT NULL auto_increment,
`oldadr` varchar(128) NOT NULL default '',
`newadr` varchar(128) NOT NULL default '',
`enabled` tinyint(1) NOT NULL default '1',
PRIMARY KEY  (`pkid`),
UNIQUE KEY `oldadr` (`oldadr`)
) ;
Then add this to /etc/postfix/main.cf

relocated_maps = mysql:/etc/postfix/mysql_relocated.cf
The create this file /etc/postfix/mysql_relocated.cf

user=mail
password=apassword
dbname=maildb
table=relocated
select_field=newadr
where_field=oldadr
hosts=127.0.0.1
Then if pete@domain1.com has changed address to pete.jones@another.org:

INSERT INTO relocated (oldadr,newadr)VALUES
('pete@domain1.com','pete.jones@another.org');
If anyone sends an email to pete@domain.com, they will get a message back stating he has changed address to pete.jones@another.org.

Return to top.
Pop-before-SMTP
If SASL didn't work, or you are using clients which dont support it, the Pop-Before-SMTP is an easy way around that issue, so that people externally can still securly send mail via your server.

Refer to my 2nd edition on Pop-before-SMTP setup.

Return to top.
Admin software
todo
Trying out a few admin software might make you life easier, if phpMyAdmin gets to crude. Quick search

More to come later.

Return to top.
Auto Reply
todo
Postfix have now features to auto reply to an email, while still delivering it to its alias.

Return to top.
Block Addresses
If you use catch alls, which are useful for some domains, then eventually some addresses will be target for spam. You can then either stop the catch all, or stop indivdual addresses.

By implementing a lookup and adding this restriction to smtpd_recipient_restrictions accomplises this.

check_recipient_access mysql:/etc/postfix/mysql_block_recip.cf,
smtpd_recipient_restrictions = permit_mynetworks, permit_sasl_authenticated, \
	check_recipient_access mysql:/etc/postfix/mysql_block_recip.cf, \
	reject_non_fqdn_recipient, reject_unauth_destination, \
	check_relay_domains
Beware of the order is important here, if any options says ok before check_recipient_access it will ignore it.

Next create mysql_block_recip.cf to lookup addresses. Either create a another table, or add a blocked field to aliases table.

Return to top.
Throttle Output
todo
For some users with restrictions on bandwidth, you may wish to control how much mail is sendt out. Postfix has long refused to implement these features, out of ideolocial beliefs that mail servers should not be restricted. However there are some ways around this. More to come later.

Return to top.
Mail Lists
Rich Brown has written a howto on adding Mailman, a mail list program, to my howto. Click here to read it.

Do note it is not part of my howto, so do not contact me regarding it. And although I think it is fine, I can't guarantee it will work.

If you do need assistance or need to talk about it, contact Rich via his howto or use the forums for this howto.

If you want a simple mailling list, it can be implemented by simply seperating aliases in the destination field in the aliases table with a comma.

INSERT INTO aliases (mail,destination) VALUES
( 'listof@domain.com' , 'john@ppp.com,vic@domain.com,jj@somewhere.tld' );
Return to top.
Google Apps / GMail
Currently writting this one...

I have for various reasons integrated some Google Apps hosted domains into my mail server. And you can still have good control over the addresses by using your server with Google Apps.

More information on Google Apps.

Why
Some already have their domain's email hosted with Google.

Some people prefer Google's web based interface.

Temporary Migrations.

Include Google's security features on top of yours.

How
Options
The easiest and simples solution is not to have a domain MXed to your server, and simply alias email to those domains. eg All email to joeblogs.co.uk hosted on your server are forwarded to joeblogs.com hosted with google.

You may set up your own server to simple be a mail server backup (mx) for a domain hosted with google. If you are the first priority in the MX details of the DNS, you still have some control, but not all will obey the priority listing. E.g. spammers, but some valid senders as well.

However the one I use and the option where you are most in control is to keep you server as the only MX server in the DNS. And only forward certain aliases onto Google after all your servers checks. Other aliases and user can just use your mail server if you prefer. I will explain how to do this in the next steps.

DNS
You only put your mail server as the mx for the domain in question. Google will complain about this, as it will not be able to verify that email is setup correctly. Ignore this as it will still accept emails.

MySQL tables
You setup you aliases as normal. However you domain table needs tweaking. This is because otherwise your server will just forward the email to itself. You can actually specify aliases in the domain table.

Example: Your domain is bloggs.com. Joe wants to use gmail. Mary does not.
to be done
to be done
Issues
There are some items you should consider when integrating Google Apps.

Privacy
First there is the privacy issue. This is the same as if you were using Google Apps only or GMail. Google can and will read your email. However probably not a person, but they will use it for commercial reasons, E.g. showing relevant ads. Some people really hate this part and refuse to use Google's mail products. However I trust them a little bit, and do use it.

Spam
If you forward spam, then consider your own servers reputation. Should be okay though.

SPF
If you use SPF for your domain, consider that both your server and google will receive and send mail on behalf of that domin.

Google internally
Be aware Google think they host you domain. So if others inside google, or using google hosted apps or GMail, if they email you, the email may not go via your email server, but directly to the Google Apps for your domain. That could be an issue if not all aliases you have use Google Apps. This needs to be tested more though. Especially as it may only be an issue if Google's servers are part of you domains MXs.

Return to top.
Maildrop, spam folder and vacation messaging
Villu have documented swapping in Maildrop for virtual transport and automatically deliverin spam to a spam folder. (And links to a post about vacation messaging)

Please read his post here.

Return to top.
Roundcube webmail client
As an alternative to SquirrelMail, Roundcube has a more modern feel to it. It is however not got the long testing track record of SquirrelMail, and is not yet a 1.0 release version. However if you prefer its very much more appealing interface then follow these easy steps:

You may optionally want to uninstall SquirrelMail:

sudo aptitude remove squirrelmail squirrelmail-locales
Then install Roundcube

sudo aptitude install roundcube roundcube-mysql
It will ask you if you want to configure its database access, answer yes, then select mysql. Then it will ask for the root mysql uses password, which it will create a roundcube mysql user and ask for its desired password.

This will create a symblink in /etc/apache2/conf.d/ to /etc/roundcube/apache.conf. Edit this file.

sudo vi /etc/roundcube/apache.conf
Depending on your setup you may want to move those Alias commands at the top to your virtual hosts configuration, or for this example enable them here for all hosts.

# Uncomment them to use it or adapt them to your configuration
Alias /roundcube/program/js/tiny_mce/ /usr/share/tinymce/www/
Alias /roundcube /var/lib/roundcube
Next edit the configuration file

sudo vi /etc/roundcube/main.inc.php
Modify these lines for added security and ease of log in:

$rcmail_config['default_host'] = 'ssl://localhost:993';

$rcmail_config['smtp_server'] = 'ssl://localhost';

$rcmail_config['smtp_port'] = 465;

# keep as default or change to your mail server name
$rcmail_config['smtp_helo_host'] = 'mail.example.com';

$rcmail_config['create_default_folders'] = TRUE;
There are other tweaks and security features you can enable such as:

$rcmail_config['sendmail_delay'] = 1;
But perhaps concentrate on getting the basics working firtst...

Save, exit and reload Apache to enable these aliases for Roundcube to work

sudo /etc/init.d/apache2 reload
Then go to your roundcube installation depending where and how you modified those Aliases, e.g. at http://mail.example.com/roundcube.
That should be it

You can obviously modify and tweak further. One thing that may be usefull is to have the Roundcube Apache Alias on different virtual hosts, and configure username_domain in main.inc.php to append different email addresses, or configure the default_host to different mail server depending on virtual host... More details on the Roundcube Wiki.

Return to top.
Suggestions?
If you have any suggestions to other ways of extending a postfix server, then fire off a mail to me via the contact form further down.
(Or rather, Id prefer that you write down the extension, and let me know the link! :))

Return to top.



Elastic Compute Cloud
Recommended ec2 books

Amazon Web Services Made Simple: Learn how A…
Donald Robin…
$17.99

Programming Amazon Web Services: S3, EC2, SQS, F…
James Murty …
$31.49

Postfix
Patrick Ben K…
$66.53

Postfix: The Definitive Guide
Kyle D. Dent …
$30.99
12>
Amazon.comPrivacy
Get Widget
Impressions

ec2 introduction, tips and hwotos

Using EC2 with this howto

Amazon EC2 Images: AMIs

EC2 Links

Impressions
Easy to use. Anyone can use, not just big companies. Very useful. Tools are command line but simple. Firefox extensions work well. Recommended.

I find it very usefull. Basically it is a colo hosting environment. Some may use it as for Saas, ie single scalable application in the cloud, but I use it as a hosting environment for complete servers.

ec2 introduction, tips and howtos
I have made a separate tips and howto on the use of ec2 for general server needs. Hope it will be useful for people.

How I use it for my mail servers
Different images to launch for different needs. Good way to scale backup MXs if needed. Can script backup to S3 of mail dirs etc.

Using EC2 with this howto
If you plan to use EC2 to follow this howto, then familiarise yourself with EC2 first. Check the links further down, e.g. my tips.

Once competent enough on EC2, launch the latest official Ubuntu ec2 image or one of Eric Hammond images. You can cheat by using my other images, but you should really know how the whole server was built by starting from the bottom.

When using EC2 images, be aware of security groups as they restricts access to your server on top of the firewall. Initially you will need SSH (22) access, quite soon you will need SMTP and IMAP ports opened, 25,143,465,587 and 993, and eventually webserver ports of 80 and 443. Read here for tips on securing AMIs.

Also do not terminate your instances without backing up your machine. This you can do by either create your own image. Or backup certain data if you got an image to instantiate from. Back up to S3 or your local machine. Create images only now and then. Backup configurations, database, maildirs more regularily.

Note: You may need to remove my ssh key from root or ubuntu user's authorized_keys2 file. They should not be present, but may be, so please check?

2nd Note: Spamhaus.org lists amazons ec2 ip ranges as dynamic, thus many mail servers will reject emails from it. (Including other people using this howto.) But Spamhaus has a simple web page to remove ips, which they link to in rejection messages. Simple look in your logs, click on the link on follow the instrucions: basically fill in your ip, email and state its for a mail server. Then Spamhaus will remove your IP from their database.

3rd Note: Amazon has extended this spam limitations, so if you have a busy mail server, follow their FAQ entry for removing mail throttling.

4th Note: This fix needs to applied to the instances buildt on an early 8.04 base. This is not a problem with the later Hammond or any Canonical based images.

4th Note: Images based on Canonical's offical Ubuntu 9.10 Karmic Koala to come soon...

Amazon EC2 Images: AMIs
Public AMIs to use as base:
( Images with strike through them are no longer recommended. Their are fine for experimenting and testing, but should not be used for permanent "live" servers )

AMI	Description	S3 Name	Ubuntu
version	Extended from
ami-1515f67c

Base install: Canonical's Official Ubuntu 9.10 Karmic 32bit US

canonical-cloud-us/ubuntu-karmic-9.10-i386-server-20091027.1

9.10 Karmic

ami-5059be39

Base install: Canonical's Official Ubuntu 8.10 Intrepid 32bit US

canonical-cloud-us/ubuntu-intrepid-20090422-i386

8.10 Intrepid

ami-c4f615ad

Base install: Alestic Ubuntu 8.04 LTS Hardy 32bit US

alestic/ubuntu-8.04-hardy-base-20091011

8.04 LTS Hardy

ami-ce44a1a7

Base install: Alestic Ubuntu 8.04 LTS Hardy 32bit US

alestic/ubuntu-8.04-hardy-base-20080430

8.04 LTS Hardy

ami-4132d428

Clean with all packages installed but no configuration

flurdy-amis/ubuntu-mail-server-clean-20090529-2

8.10 Intrepid

ami-5059be39 (Canonical)

ami-0f41a466

Clean with all packages installed but no configuration

flurdy-amis/ubuntu-mail-server-clean-080502-1

8.04 LTS Hardy

ami-ce44a1a7 (Old Alestic)

ami-eb39df82

Just mysql, postfix and courier configured

flurdy-amis/ubuntu-mail-server-basic-20090604-1

8.10 Intrepid

ami-4132d428 (Clean Canonical)

ami-8541a4ec

Just mysql, postfix and courier configured

flurdy-amis/ubuntu-mail-server-simple-080504-1

8.04 LTS Hardy

ami-0f41a466 (Clean Alestic)

ami-9941a4f0

Including anti spam and anti virus

flurdy-amis/ubuntu-mail-server-spam-080504-1

8.04 LTS Hardy

ami-8541a4ec (Simple)

ami-395fba50

Including TLS and SASL encryption and authentication

flurdy-amis/ubuntu-mail-server-secure-080527-2

8.04 LTS Hardy

ami-9941a4f0 (Spam)

ami-275fba4e

With webmail and admin enabled

flurdy-amis/ubuntu-mail-server-webmail-080527-1

8.04 LTS Hardy

ami-395fba50 (Secure)

ami-xxx

With back up mx

flurdy-amis/ubuntu-mail-server-backup-xxx

8.04 LTS Hardy

ami-275fba4e (Webmail)

ami-xxx

With back up mx only

flurdy-amis/ubuntu-mail-server-backup-only-xxx

8.04 LTS Hardy

ami-395fba50 (Secure)

If you have a comment or question about the ec2 images, please discuss it in the forums? If you notice a security problem, or I have not cleaned the images properly please let me know?

EC2 Links
Amazon web services (AWS)

Elastic Computing Cloud (EC2)

Simple Storage Service (S3)

AWS Cost Calculator

EC2 Resource Centre

EC2 Starter Guide

EC2 Firefox extension: Elasticfox

Elasticfox for Firefox 3

S3 Firefox extension: S3Fox

EC2 to S3 Admin Scripts

Eric Hammond 8.04 AMI

alestic, ubuntu ec2 images

Ubuntu ec2

Ubuntu Cloud

Ubuntu ec2 Starter Guide

My ec2 Tips and Howtos

Return to top.
Appendix
No fix computer
About author

Contact

Why

References

Software Links

Difference between Ubuntu versions

Download

Todo

Change Log

About author
Ivar Abrahamsen, an IT Senior Consultant from Norway. Specialising in developing and integrating middleware application systems. Mainly open source and Java based technology stack. Recently moved back to Oslo, Norway after 15 years in Manchester.

Return to top.
Contact
Remember I have stood on the shoulders of giants. I just ended up with a system that worked for me, and decided to document its evolution.

Before contacting, have you?:

Read this document properly? Followed it step by step?
(While we can not insist on the same setup for everyone, assistance is easier and more likely if less customised)

Applied the solutions provided in the test section?

Read the forums for solutions already posted?

Read the FAQ?

Tailed the mail.log? It usually tells you what the problem is!

Tailed the mysql.log? If nothing happens there it should indicate something...

Include a short dump of the mail.log with your post. (Remember to anonymise the servernames etc)

Forums
Use the Ubuntu forums! :)
Here is a thread on this specific mail server howto.

And another one by me which is also used..

Please participate in the forums.
If you see an issue you also have, contribute with more information.
And even better if it something you may know how to solve, please let people know.
And especially, if you post a problem, then solve it, let people know what the solution was! (and not just that you solved it...)

I am rubbish in replying to emails, and the forums are read and answered by people whom know a lot more about Postfix than me.

Questions sent to me directly may not be answered for a while or at all unfortunetly.

Return to top.
Consultancy and advice
Not to be rude, but to try and reduce the volume of emails I get please consider the following:

If you simply want advice please use the forum.

My references and the people whom follow the forums and the postfix mailling lists are much more knowledgable than me.

People whom follow the forums and the postfix mailling lists are much more likely to reply than me.

I am a firm believer in: Give a man a fish; you have fed him for today. Teach a man to fish; and you have fed him for a lifetime. (Playing far too much Civ was not all wasted..)

So if you have any questions, problems with using this guide, or any other issues with this guide, please use the forum.
Then it is also an available archive for others to find solutions in the future.

Any technical difference of opinion, please use the forum.

Interested in Postfix, or got a technical query about it? Considered the postfix mailling lists.

If you made / found an extensions to this tutorial, Fantastic! Please let me know, and Ill link to it. And shout at me, if I am slow in doing so. :)

Any clear technical mistakes by me in this guide, then let me know, but perhaps discuss it first in the forums?

If you find any spelling mistakes or broken links, please let me know.

Thank you messages are very appreciated however! Actually it makes my day. :)
(People whom buy a T-shirt of me makes my week.. ;p )

If you still want my advice or hire me:

You may hire me as a consultant via www.eray.co.uk.

You may hire me to set up a complete server for you via www.eray.co.uk.

In the end I am contactable via flurdy.com/contact :)
However :

Do remember my fishing analogy.
I do not appreciate people whom wants shortcuts and ask me to set their server up for them, especially for free.

Nor do I find it amusing when people have not even followed my suggested steps, and/or not tested properly and ignored the logs etc.

Email servers are important and potentially dangerous, so you really need to learn how it works, and how to tweak it.
Return to top.
I read your email
Why
Why your own mail server
Main reason: Because you can.
Other good reasons: Basically it leaves you in complete control, to expand, customize and tweak your mail server to your needs. You are not dependant on 3rd party providers, limited by their technology contraints or your budgets. With your own mail server you can add as many aliases, users and domain as you'd like, be as restrictive or open about security, virus, spam, file sizes etc as you prefer. And is it is well known, frequently updated, open source application stack, you can also trust the software you use.

Why I wrote this howto
When I set up my first email server I used a mix of other howtos on the net. And they were so helpfull that I though I would contribute back with my experience. And it has been useful as a recipe script for myself every time I need to install/update a server.

A less angelic reason is that back in 2003 I was setting up mail server for a few friends and collegues. Soon I was getting more request, and being a lazy programmer, I thought.. "Why don't I write a howto and let them do it themselves..." Soon it was listed on postfix.org and I was getting thousends of hits and lots of emails. (blessing in disguise)

Why I wrote this edition
Or rather why no new edition or updates for two years? Well basically no time or need to do so, so basically lazyness...
My last edition was written two years ago, and was pretty complete and thorough so my inclination to write a new one has been low, especially as my own mail server had not changed since then either.

But then my server started crashing so I upgraded it to Ubuntu 8.04 which went pretty smooth, but with a few tweaks. So time for another edition.

This time I expanded reliability to include the possibility of running backup mx servers using Amazon's Elastic Computing Cloud. Note, however this is an optional extra at the end.

Return to top.
References
Postfix howtos

Kyle's book

John Locke on TechRepublic

Hildebrandt's book

Hildebrandt's website

List-Petersen

Genco Yilmaz

Christop Haas

Nenzel & Peet

Peters

Matthews

Stepanov

Andy "Besy"

Meta Consultancy

New references

Postfix TLS

Postfix main.cf doc

saslauthd

Bypassing amavisd

Ubuntu Help: Squirrelmail

Return to top.
Software Links
Please refer to the previous edition for a list of urls and suiteable downloads. However most are unneccessary with decent package manager.

Difference between Ubuntu versions
I used to distinguish differences, which were available in a previous edition.

Download
Please refer to the previous edition for a complete lists of downloads that are available.

Change log
Brief list of latest changes.

2009-12-16: Expanded test section with text from older editions and new babble.

2009-11-25: Bumped to edition 9!
And added Roundcube as webmail client.

2009-11-11: Updated to work with 9.10 Karmic Koala.

2009-06-04: made basic server image available on ec2. based canonical's official ec2 ami.

2009-06-02: made clean server image available on ec2. based canonical's official ec2 ami.

2009-05-29: changed contact section.

2009-05-29: started 8th edition

Used to refer to all changes, but got too long. A previous edition contains such a list.

Return to top.
Todo
Populate some of the: Refer to previous edition...

Spell check!

Remove uid and guid

Copy across test sections from earlier

Merge test sections

Create backup mx AMI

Please refer to the previous edition for some old todos....

FAQ
There is not yet an extensive FAQ.

But please, most of the frequent questions have been asked and answered in the forums.
Most are also unneccessary as following the test section will have solved them.

Some question that frequently get sent to me, which first of all should have been asked in the forums and has been answered there many times, which then I tend to ignore are:

Squirrelmail does not allow me to log in
This is due to many things. Most are due to skipping too fast forward, ignoring test sections etc.

Answers:

Does postfix work?
No point trying to run before you can crawl. Send emails to recipients on your server, tail mail.log to see if everything is okay.
Often mysql is not configured properly, check the mysql logs for activity.

Have they ever received an email?
If not they can not log into squirrelmail as the email folders will not yet exist.

Does Courier work?
If it doesn't then you have still got some more setup to do.

If all above is okay, then it may be a problem with your Squirrelmail setup.
Check empty spaces in squirrelmail mysql setup. More details in test section.

Email folders do not exist
Mentioned many times in this guide and forums.

Answers:

Have they received an email?
If not they you can not log into squirrelmail as the email folders will not yet exist. When receiving their first email, postfix will create all the neccessary folders. If it does not your postfix setup is broken.

There is a program that creates the folders for you.
I do not recommend it, as basically your postfix setup is broken if no folders are created, and you better fix it instead.

