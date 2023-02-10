---
title: xfce4-terminal
tags: Tale
---

$ xfce4-terminal
Failed to connect to session manager: Failed to connect to the session manager: SESSION_MANAGER environment variable not defined



The client finds the network address of the SM in a system-dependent way. On POSIX systems an environment variable called SESSION_MANAGER will contain a list of network IDs. Each id will contain the transport name followed by a slash and the (transport-specific) address. A TCP/IP address would look like this:

tcp/hostname:portnumber

where the hostname is a fully qualified domain name. A Unix Domain address looks like this:

local/hostname:path



SESSION_MANAGER=local/clairissa:/tmp/.ICE-unix/7055




the SESSION_MANAGER is a variable that
points to a socket when running an Xsession.



$ echo $SESSION_MANAGER
local/boven:@/tmp/.ICE-unix/2067,unix/boven:/tmp/.ICE-unix/2067



