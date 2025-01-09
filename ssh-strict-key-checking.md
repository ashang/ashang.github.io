

```sh
$ rsync ~/dpkg.x2 code:
sending incremental file list
dpkg.x2
        106,642 100%   70.45MB/s    0:00:00 (xfr#1, to-chk=0/1)

sent 106,770 bytes  received 35 bytes  71,203.33 bytes/sec
total size is 106,642  speedup is 1.00
01:36:50 ±|main ✗| aaron@x2:/aaron/proposal-async-await
$ rsync ~/dpkg.x2 10.10.50.12:
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@    WARNING: REMOTE HOST IDENTIFICATION HAS CHANGED!     @
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
IT IS POSSIBLE THAT SOMEONE IS DOING SOMETHING NASTY!
Someone could be eavesdropping on you right now (man-in-the-middle attack)!
It is also possible that a host key has just been changed.
The fingerprint for the ED25519 key sent by the remote host is
SHA256:8HijRnHGqYIh/9IpwMakdme909twxRjsTXqjwxBRCu0.
Please contact your system administrator.
Add correct host key in /aaron/.ssh/known_hosts to get rid of this message.
Offending ED25519 key in /aaron/.ssh/known_hosts:178
  remove with:
  ssh-keygen -f "/aaron/.ssh/known_hosts" -R "10.10.50.12"
Host key for 10.10.50.12 has changed and you have requested strict checking.
Host key verification failed.
rsync: connection unexpectedly closed (0 bytes received so far) [sender]
rsync error: unexplained error (code 255) at io.c(231) [sender=3.2.7]
01:37:03 ±|main ✗| aaron@x2:/aaron/proposal-async-await
$ rsync ~/dpkg.x2 10.10.50.12:
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@    WARNING: REMOTE HOST IDENTIFICATION HAS CHANGED!     @
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
IT IS POSSIBLE THAT SOMEONE IS DOING SOMETHING NASTY!
Someone could be eavesdropping on you right now (man-in-the-middle attack)!
It is also possible that a host key has just been changed.
The fingerprint for the ED25519 key sent by the remote host is
SHA256:8HijRnHGqYIh/9IpwMakdme909twxRjsTXqjwxBRCu0.
Please contact your system administrator.
Add correct host key in /aaron/.ssh/known_hosts to get rid of this message.
Offending ED25519 key in /aaron/.ssh/known_hosts:178
  remove with:
  ssh-keygen -f "/aaron/.ssh/known_hosts" -R "10.10.50.12"
Host key for 10.10.50.12 has changed and you have requested strict checking.
Host key verification failed.
rsync: connection unexpectedly closed (0 bytes received so far) [sender]
rsync error: unexplained error (code 255) at io.c(231) [sender=3.2.7]
01:37:07 ±|main ✗| aaron@x2:/aaron/proposal-async-await
$ sed -i 178d ~/.ssh/kn
known_hosts      known_hosts.old
01:37:07 ±|main ✗| aaron@x2:/aaron/proposal-async-await
$ sed -i 178d ~/.ssh/known_hosts
01:38:01 ±|main ✗| aaron@x2:/aaron/proposal-async-await
$ rsync ~/dpkg.x2 10.10.50.12:
The authenticity of host '10.10.50.12 (10.10.50.12)' can't be established.
ED25519 key fingerprint is SHA256:8HijRnHGqYIh/9IpwMakdme909twxRjsTXqjwxBRCu0.
This host key is known by the following other names/addresses:
    ~/.ssh/known_hosts:208: [hashed name]
    ~/.ssh/known_hosts:214: [hashed name]
Are you sure you want to continue connecting (yes/no/[fingerprint])? yes
Warning: Permanently added '10.10.50.12' (ED25519) to the list of known hosts.
sending incremental file list
dpkg.x2
        106,642 100%   70.45MB/s    0:00:00 (xfr#1, to-chk=0/1)

sent 106,770 bytes  received 35 bytes  42,722.00 bytes/sec
total size is 106,642  speedup is 1.00
```
