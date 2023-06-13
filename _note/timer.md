---
title: timer
---


You do not want an [Install] section in a .service file that is triggered by a .timer file.



The systemd-analyze command will ensure our OnCalendar value is correct.

$ systemd-analyze calendar '*-* zz*:00/3:00'
Failed to parse calendar specification '*-* zz*:00/3:00': Invalid argument
Advantages to systemd timers over cron
As we’ve seen a systemd timer has more moving parts than a simple entry in the crontab file. However, by using systemd we have some advantages:

Timers can be examined and viewed by all users on the system and are not tied to a specific user
Timers can have complex dependencies based on the systemd dependency tree. Thus, we can trigger a timer based on services, boot-up, startups, how long services have been active or inactive.
Through systemctl and journalctl we can more easily debug our timers
The events that the timer can trigger on are more advanced than just every X seconds. Timers can delay randomly, use realtime clocks, trigger off timezone changes, and even wake the system on trigger.



[🔴] ╰─λ× sudo systemctl enable plocate-updatedb.service
The unit files have no installation config (WantedBy=, RequiredBy=, Also=,
Alias= settings in the [Install] section, and DefaultInstance= for template
units). This means they are not meant to be enabled using systemctl.

Possible reasons for having this kind of units are:
• A unit may be statically enabled by being symlinked from another unit's
  .wants/ or .requires/ directory.
• A unit's purpose may be to act as a helper for some other unit which has
  a requirement dependency on it.
• A unit may be started when needed via activation (socket, path, timer,
  D-Bus, udev, scripted systemctl call, ...).
• In case of template units, the unit is meant to be enabled with some
  instance name specified.






[🔴] ╰─λ× sudo systemctl enable plocate-updatedb.service
The unit files have no installation config (WantedBy=, RequiredBy=, Also=,
Alias= settings in the [Install] section, and DefaultInstance= for template
units). This means they are not meant to be enabled using systemctl.

Possible reasons for having this kind of units are:
• A unit may be statically enabled by being symlinked from another unit's
  .wants/ or .requires/ directory.
• A unit's purpose may be to act as a helper for some other unit which has
  a requirement dependency on it.
• A unit may be started when needed via activation (socket, path, timer,
  D-Bus, udev, scripted systemctl call, ...).
• In case of template units, the unit is meant to be enabled with some
  instance name specified.






# systemd-run --on-active="12h 30m" --unit someunit.service


