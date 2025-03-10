---
title: systemd-notify
date: 2022-03-03
---





How can I configure a systemd service to restart periodically?


ystemd version >= 229, there is an option called RuntimeMaxSec, which terminates
the service after it has been running for the given period of time.

e.g.
 create a file named /etc/systemd/system/foo.service.d/periodic-restart.conf.

[Service]
Restart=always
RuntimeMaxSec=604800


 systemctl show foo.service | grep RuntimeMax





----


/etc/systemd/system/notify-email@.service

[Unit]
Description=Sent email

[Service]
Type=oneshot
ExecStart=/usr/bin/bash -c '/usr/bin/systemctl status %i | /usr/bin/mailx -Ssendwait -s "[SYSTEMD_%i] Fail" your_admin@company.blablabla'

[Install]
WantedBy=multi-user.target



At others services add:

[Unit]
OnFailure=notify-email@%i.service




----


/etc/systemd/system/unit-status-mail@.service” (yes the file name contains “@.” with nothing in between):

[Unit]
Description=Unit Status Mailer Service
After=network.target

[Service]
Type=simple
ExecStart=/bin/unit-status-mail.sh %I "Hostname: %H" "Machine ID: %m" "Boot ID: %b"





“/bin/unit-status-mail.sh”

#!/bin/bash
MAILTO="root"
MAILFROM="unit-status-mailer"
UNIT=$1

EXTRA=""
for e in "${@:2}"; do
  EXTRA+="$e"$'\n'
done

UNITSTATUS=$(systemctl status $UNIT)

sendmail $MAILTO <<EOF
From:$MAILFROM
To:$MAILTO
Subject:Status mail for unit: $UNIT

Status report for unit: $UNIT
$EXTRA

$UNITSTATUS
EOF

echo -e "Status mail sent to: $MAILTO for unit: $UNIT"
Remember to make the script executable, “chmod +x /bin/unit-status-mail.sh”.

Test
You can try the unit-status-mail script out by running:

/bin/unit-status-mail.sh sitename-drupal-cron


----


