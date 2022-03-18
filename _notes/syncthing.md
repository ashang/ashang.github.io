# Syncthing

Syncthing is a decentralized file synchronization.

The creation, modification or deletion of files on one machine will automatically be replicated to your other devices.

Syncthing does not upload your data to the cloud but exchanges your data across your machines as soon as they are online at the same time.

Homepage: https://www.syncthing.net/

## Install

Add the release PGP key

```shell
curl -s https://syncthing.net/release-key.txt | sudo apt-key add -
```

Add the "release" channel to APT sources

```shell
echo "deb http://apt.syncthing.net/ syncthing release" | sudo tee /etc/apt/sources.list.d/syncthing.list
```

Update and install syncthing:

```shell
# apt-get update
# apt-get install syncthing
```

## Conf files

```shell
$ cat /etc/ufw/applications.d/syncthing
[syncthing]
title=Syncthing
description=Syncthing file synchronisation
ports=22000/tcp|21027/udp

[syncthing-gui]
title=Syncthing-GUI
description=Syncthing web gui
ports=8384/tcp
```

## Interface

Access via web <http://127.0.0.1:8384/>

```log
[monitor] 15:07:20 INFO: Starting syncthing
[start] 15:07:20 INFO: Generating ECDSA key and certificate for syncthing...
[SYNMT] 15:07:20 INFO: syncthing v0.14.30 "Dysprosium Dragonfly" (go1.8.3 linux-amd64) portage@andromeda.sabayon.org 2017-07-05 19:02:47 UTC [noupgrade]
[SYNMT] 15:07:20 INFO: My ID: SYNMT4S-3ISAQVA-
[SYNMT] 15:07:21 INFO: Single thread SHA256 performance is 287 MB/s using minio/sha256-simd (282 MB/s using crypto/sha256).
[SYNMT] 15:07:21 INFO: Hashing performance with weak hash is 239.67 MB/s
[SYNMT] 15:07:22 INFO: Hashing performance without weak hash is 279.87 MB/s
[SYNMT] 15:07:22 INFO: Default folder created and/or linked to new config
[SYNMT] 15:07:22 INFO: Defaults saved. Edit /path/to/.config/syncthing/config.xml to taste or use the GUI
[SYNMT] 15:07:22 INFO: Weak hash enabled, as it has an acceptable performance impact.
[SYNMT] 15:07:22 INFO: Ready to synchronize "Default Folder" (default) (readwrite)
[SYNMT] 15:07:22 INFO: Send rate is unlimited, receive rate is unlimited
[SYNMT] 15:07:22 INFO: Rate limits do not apply to LAN connections
[SYNMT] 15:07:22 INFO: Using discovery server https://discovery-v4-2.syncthing.net/v2/?id=DVU36WY-H3LVZHW-
...
[SYNMT] 15:07:22 INFO: Using discovery server https://discovery-v6-4.syncthing.net/v2/?id=LYXKCHX-VI3NYZR-
[SYNMT] 15:07:22 INFO: TCP listener ([::]:22000) starting
[SYNMT] 15:07:22 INFO: Completed initial scan (rw) of "Default Folder" (default)
[SYNMT] 15:07:22 INFO: Loading HTTPS certificate: open /path/to/.config/syncthing/https-cert.pem: no such file or directory
[SYNMT] 15:07:22 INFO: Creating new HTTPS certificate
[SYNMT] 15:07:23 INFO: GUI and API listening on 127.0.0.1:8384
[SYNMT] 15:07:23 INFO: Access the GUI via the following URL: http://127.0.0.1:8384/
[SYNMT] 15:07:23 INFO: Device SYNMT4S-3ISAQVA-
[SYNMT] 15:07:33 INFO: Detected 0 NAT devices
[SYNMT] 15:07:40 INFO: c.S.listenerSupervisor: Failed service 'dynamic+https://relays.syncthing.net/endpoint' (1.000000 failures of 2.000000), restarting: true, error: "{dynamic+https://relays.syncthing.net/endpoint dynamic+https://relays.syncthing.net/endpoint} returned unexpectedly", stacktrace: [unknown stack trace]
[SYNMT] 15:08:52 INFO: Joined relay relay://138.201.
[SYNMT] 15:11:53 INFO: model@0xc4200a8900 Adding folder dl
[SYNMT] 15:11:53 INFO: Ready to synchronize dl (readwrite)
[SYNMT] 15:11:59 INFO: Completed initial scan (rw) of dl
^C
[monitor] 15:13:28 INFO: Signal 2 received; exiting
```

```log
$ syncthing
[start] 14:37:42 INFO: syncthing v1.12.1-ds1 "Fermium Flea" (go1.16.5 linux-amd64) debian@debian 2021-07-23 20:27:51 UTC
[start] 14:37:42 INFO: Archiving a copy of old config file format at: /aaron/.config/syncthing/config.xml.v21
[SYNMT] 14:37:43 INFO: My ID: SYNMT4S-
[SYNMT] 14:37:44 INFO: Single thread SHA256 performance is 431 MB/s using minio/sha256-simd (363 MB/s using crypto/sha256).
[SYNMT] 14:37:44 INFO: Hashing performance is 362.44 MB/s
[SYNMT] 14:37:44 INFO: Running database migration 1...
...
[SYNMT] 14:37:44 INFO: Running database migration 15...
[SYNMT] 14:37:44 INFO: Compacting database after migration...
[SYNMT] 14:37:45 INFO: Starting deadlock detector with 20m0s timeout
[SYNMT] 14:37:45 INFO: Overall send rate is unlimited, receive rate is unlimited
[SYNMT] 14:37:45 INFO: Using discovery mechanism: global discovery server https://discovery.syncthing.net/v2/?noannounce&id=LYXKCHX-VI3NYZR-
[SYNMT] 14:37:45 INFO: Using discovery mechanism: global discovery server https://discovery-v4.syncthing.net/v2/?nolookup&id=LYXKCHX-VI3NYZR-
[SYNMT] 14:37:45 INFO: Ready to synchronize default (sendreceive)
[SYNMT] 14:37:45 INFO: Ready to synchronize dl (sendreceive)
[SYNMT] 14:37:45 INFO: QUIC listener ([::]:22000) starting
[SYNMT] 14:37:45 WARNING: Error on folder default: folder path missing
[SYNMT] 14:37:45 INFO: Failed initial scan of sendreceive folder default
[SYNMT] 14:37:45 INFO: Relay listener (dynamic+https://relays.syncthing.net/endpoint) starting
[SYNMT] 14:37:45 INFO: TCP listener ([::]:22000) starting
[SYNMT] 14:37:45 WARNING: Error on folder dl: folder path missing
[SYNMT] 14:37:45 INFO: Failed initial scan of sendreceive folder dl
[SYNMT] 14:37:45 INFO: Using discovery mechanism: global discovery server https://discovery-v6.syncthing.net/v2/?nolookup&id=LYXKCHX-VI3NYZR-
[SYNMT] 14:37:45 INFO: Using discovery mechanism: IPv4 local broadcast discovery on port 21027
2022/03/15 14:37:45 connection doesn't allow setting of receive buffer size. See https://github.com/lucas-clemente/quic-go/wiki/UDP-Receive-Buffer-Size for details.
[SYNMT] 14:37:45 INFO: Using discovery mechanism: IPv6 local multicast discovery on address [ff12::8384]:21027
[SYNMT] 14:37:45 INFO: GUI and API listening on 127.0.0.1:8384
[SYNMT] 14:37:45 INFO: Access the GUI via the following URL: http://127.0.0.1:8384/
[SYNMT] 14:37:45 INFO: My name is
[SYNMT] 14:37:45 INFO: Cleaned away old file config.xml.v20
[SYNMT] 14:37:55 INFO: quic://0.0.0.0:22000 detected NAT type: Symmetric NAT
[SYNMT] 14:37:59 INFO: Detected 3 NAT services
[SYNMT] 14:40:24 INFO: Joined relay relay://42.192.
[SYNMT] 14:40:36 INFO: Ready to synchronize default (sendreceive)
[SYNMT] 14:40:36 INFO: Restarted folder default (sendreceive)
[SYNMT] 14:40:36 WARNING: Error on folder default: folder path missing
[SYNMT] 14:40:36 INFO: Failed initial scan of sendreceive folder default
[SYNMT] 14:40:36 INFO: Ready to synchronize dl (sendreceive)
[SYNMT] 14:40:36 INFO: Restarted folder dl (sendreceive)
[SYNMT] 14:40:36 WARNING: Error on folder dl: folder path missing
[SYNMT] 14:40:36 INFO: Failed initial scan of sendreceive folder dl
[SYNMT] 14:42:05 INFO: GUI and API listening on 127.0.0.1:8384
[SYNMT] 14:42:05 INFO: Access the GUI via the following URL: https://127.0.0.1:8384/
^C
[monitor] 15:22:28 INFO: Signal 2 received; exiting
[SYNMT] 15:22:28 INFO: TCP listener ([::]:22000) shutting down
[SYNMT] 15:22:28 INFO: QUIC listener ([::]:22000) shutting down
[SYNMT] 15:22:28 INFO: Relay listener (dynamic+https://relays.syncthing.net/endpoint) shutting down
[SYNMT] 15:22:28 INFO: Disconnected from relay relay://42.192.
[SYNMT] 15:22:28 INFO: Exiting
```

## Trouble shooting

```log
127.0.0.1:8384 uses an invalid security certificate.
 
The certificate is not trusted because it is self-signed.
 
Error code: MOZILLA_PKIX_ERROR_SELF_SIGNED_CERT
```

```
Your connection is not private

Attackers might be trying to steal your information from 127.0.0.1 (for example, passwords, messages or credit cards). Learn more

NET::ERR_CERT_AUTHORITY_INVALID

This server could not prove that it is 127.0.0.1; its security certificate is not trusted by your computer's operating system. This may be caused by a misconfiguration or an attacker intercepting your connection.

Proceed to 127.0.0.1 (unsafe)

```