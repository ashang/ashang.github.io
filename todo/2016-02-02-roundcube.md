

# SMTP Error (250): Authentication failed. 

replace :

   $config['smtp_user'] = '%u';

to below :

    $config['smtp_user'] = '';

explantions here : http://kb.odin.com/en/120036

//


Symptoms

Unable to send an email message using Roundcube webmail. The following error message occurs in Roundcube web interface:

SMTP Error (535): Authentication failed. 

Cause

Incorrect configuration settings.
Resolution

Change Roundcube configuration file in the following way:

    Log in to Webmail Service node (by default, webmail clients are installed on Plesk Automation Management node, but webmail can be deployed as a separate node, as described in documentation)

    Locate main.inc.php configuration file:

    # rpm -qa|grep roundcube|xargs rpm -ql|grep main.inc.php
    /usr/share/psa-roundcube/config/main.inc.php

    Change smtp_user value from the following:

    # grep smtp_user /usr/share/psa-roundcube/config/main.inc.php
    $rcmail_config['smtp_user'] = '%u';

to the one below:

    # grep smtp_user /usr/share/psa-roundcube/config/main.inc.php
    $rcmail_config['smtp_user'] = '';




