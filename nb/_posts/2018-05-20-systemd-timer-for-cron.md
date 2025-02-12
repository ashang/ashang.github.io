
```sh
*/5 * * * * rsync -avPAXl --exclude=.cache/ ~/ code:o302/
```


    Jobs can have dependencies (Can depend on other systemd services).
    Timer units are logged to the systemd journal.
    You can easily run a job independent of it's timer.
    Timer units can have a nice value or use cgroups for resource management.
    Systemd timer units can be triggered by events like boot and hardware changes.
    Can be easily disabled or enabled using systemctl.
    Timer units can use real time or monotonic time.


$ sudo systemd-analyze verify /etc/systemd/system/my-rsync.*

$ sudo systemctl daemon-reload

$ sudo systemctl start my-rsync.timer

$ sudo systemctl enable my-rsync.timer

$ sudo systemctl disable --now automated-backup.timer

$ sudo systemctl enable --now automated-backup.timer

$ sudo journalctl -u my-rsync


For each timer file, a matching unit file must exist, describing the unit to activate when the timer elapses. By default, a service by the same name as the timer (except for the suffix) is activated.



    Timer units automatically gain a Before= dependency on the service they are supposed to activate.


```conf
[Unit]
Description="to rsync home"

[Service]
ExecStart=rsync -avPAXl --exclude=.cache/ ~/ code:o302/
#Type=oneshot
#ExecStart=/usr/bin/ionice -c 3 /usr/bin/nice -n 19 /usr/bin/clamscan –recursive –infected –exclude-dir=’^/sys|^/dev’ / \
#User=root
# MemoryLimit=100M
#Nice=19
#IOSchedulingClass=2
#IOSchedulingPriority=7



```

```conf
[Unit]
Description="Timer to back up the home directory"

[Timer]
OnBootSec=3min
OnUnitActiveSec=1h
Unit=my-rsync.service
#OnCalendar=*-*-* 03:00:00
#OnCalendar=03:00:00
#OnCalendar=Mon *-*-10 *:*:00
#OnCalendar=2022-6,7,8-1,15 01:15:00
#RandomizedDelaySec=7200
#Persistent=true

[Install]
WantedBy=multi-user.target
```

## what if your system is not running at the scheduled timer



Persistent= takes care of missed timer triggers. What if your server is shutdown during night? Well, the backup would never trigger at all. Setting it to true allows systemd run it on the next boot in such cases. This way you know in one way or another, the timer’s task will be run. Its usage is simple, you just do this:
Persistent=true


## what if your task is not completed at the next scheduled timer






Say you need to run your tasks around 7 AM for the morning but you want to allow a small delay of max 15 minutes, you would do like this:
RandomizedDelaySec=900

That should be enough for delays. Sometimes even milliseconds delays are enough to prevent unintended spikes.


systemctl status *timer

[Unit]
Description=Logs system statistics to the systemd journal
Wants=myMonitor.timer

[Service]
Type=oneshot
ExecStart=/usr/bin/free
ExecStart=free
ExecStart=/usr/bin/lsblk
ExecStart=lsblk

[Install]
WantedBy=multi-user.target





journalctl -S today -u myMonitor.service
journalctl -S today -f -u myMonitor.service



$ systemd-analyze calendar 2038-03-03
  Original form: 2038-03-03
Normalized form: 2038-03-03 00:00:00
    Next elapse: Wed 2038-03-03 00:00:00 CST
       (in UTC): Tue 2038-03-02 16:00:00 UTC
       From now: 15 years 11 months left


## User units

User units can be utilized to enable adding jobs without privileged access. They work the exact same as normal units, but are placed in ~/.config/systemd/user





investigating a job that is suspected to have crashed the server 2 reboots ago. The admin can get granular access through a command like journalctl –boot=-2 –unit=thejob.service.










ExecStart should be assigned to the appropriate command. Full paths to the executable are usually necessary, which is why we specify /usr/bin/curl here, not just curl.
Assuming that the command executes then finishes, I set Type=oneshot. This signals to systemd that the service is not to be considered "dead" just because it finishes.



Timer


What if the server is shutdown or disconnected for maintenance or server/network failure? It would be a crying shame if, when the server comes back online, the message of the day has yesterday's weather! So we use Persistent=true so that the service is triggered on next boot if it was supposed to have run in the interim offline period. Leave this line out if this is not desired, as the default is false.
Assuming we have a bunch of timers running with OnCalendar=daily, we are at risk of a dogpile of services running at midnight and affecting system performance. We could change daily to a specific time, of course. In this instance, though, I set RandomizedDelaySec to 3600. Don't see the 3600 number? That is because systemd time span abbreviations allow us to denote 3600 seconds as 1h for obvious reasons. The end result is that systemd will randomly choose a launch time within 1 hour of midnight. If we do the same with other daily timers, there will be harmony and balance and we will therefore sleep better at night.
In the [Install] section, we let systemd know that the system timers.target Wants this timer. That way, upon reboot, when the timers.target starts, it will bring this and other associated timers online as well. That doesn't mean the associated services are triggered; rather, it just means that the timers are activated at boot. Fun fact: the timers.target also works in user scoped systemd timers.



systemctl list-timers motd*

systemctl list-timers --all



Midnight in your timezone on the first day of every year: *-01-01 00:00:00 (this could also be written yearly)
8am daily on the U.S. East Coast: *-*-* 08:00:00 America/New_York
Yeah, you can leave the off the seconds: *-*-* 08:00 America/New_York
Just weekdays at 2am: Mon..Fri *-*-* 02:00 America/New_York
Every Sunday at 10pm: Sun *-*-* 22:00 America/New_York





OnUnitActiveSec= and OnUnitInactiveSec= are interesting. They trigger the service the specified time after the service was last activated or deactivated, respectively.






The one big caveat with user services: they don't necessarily run at boot. Instead, they run at login. There is a nice workaround, though. If you want your user services and timers to run at boot, not just login, you can make a particular user "linger". Then things work even when the user has not explicitly logged in. To do this:


sudo loginctl enable-linger my_username



https://www.freedesktop.org/software/systemd/man/systemd.time#Parsing%20Time%20Spans

https://www.freedesktop.org/software/systemd/man/systemd.timer.html#


https://www.freedesktop.org/software/systemd/man/systemd.timer.html




OnClockChange=, OnTimezoneChange=

    These options take boolean arguments. When true, the service unit will be triggered when the system clock (CLOCK_REALTIME) jumps relative to the monotonic clock (CLOCK_MONOTONIC), or when the local system timezone is modified. These options can be used alone or in combination with other timer expressions (see above) within the same timer unit. These options default to false.



RemainAfterElapse=

    Takes a boolean argument. If true, a timer will stay loaded, and its state remains queryable even after it elapsed and the associated unit (as configured with Unit=, see above) deactivated again. If false, an elapsed timer unit that cannot elapse anymore is unloaded once its associated unit deactivated again. Turning this off is particularly useful for transient timer units. Note that this setting has an effect when repeatedly starting a timer unit: if RemainAfterElapse= is on, starting the timer a second time has no effect. However, if RemainAfterElapse= is off and the timer unit was already unloaded, it can be started again, and thus the service can be triggered multiple times. Defaults to true.


