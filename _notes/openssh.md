
```
$ ssh gw@10.0.1.1
OpenSSH_8.8p1, OpenSSL 1.1.1m  14 Dec 2021
debug1: Reading configuration data /home/aaron/.ssh/config
debug1: Reading configuration data /etc/ssh/ssh_config
debug1: Connecting to 10.0.1.1 [10.0.1.1] port 22.
debug1: Connection established.
debug1: identity file /home/aaron/.ssh/id_rsa type 0
debug1: identity file /home/aaron/.ssh/id_rsa-cert type -1
debug1: identity file /home/aaron/.ssh/id_dsa type -1
debug1: identity file /home/aaron/.ssh/id_dsa-cert type -1
debug1: identity file /home/aaron/.ssh/id_ecdsa type -1
debug1: identity file /home/aaron/.ssh/id_ecdsa-cert type -1
debug1: identity file /home/aaron/.ssh/id_ecdsa_sk type -1
debug1: identity file /home/aaron/.ssh/id_ecdsa_sk-cert type -1
debug1: identity file /home/aaron/.ssh/id_ed25519 type 3
debug1: identity file /home/aaron/.ssh/id_ed25519-cert type -1
debug1: identity file /home/aaron/.ssh/id_ed25519_sk type -1
debug1: identity file /home/aaron/.ssh/id_ed25519_sk-cert type -1
debug1: identity file /home/aaron/.ssh/id_xmss type -1
debug1: identity file /home/aaron/.ssh/id_xmss-cert type -1
debug1: Local version string SSH-2.0-OpenSSH_8.8
debug1: Remote protocol version 2.0, remote software version SSHD
debug1: compat_banner: no match: SSHD
debug1: Authenticating to 10.0.1.1:22 as 'gw'
debug1: load_hostkeys: fopen /home/aaron/.ssh/known_hosts2: No such file or directory
debug1: load_hostkeys: fopen /etc/ssh/ssh_known_hosts: No such file or directory
debug1: load_hostkeys: fopen /etc/ssh/ssh_known_hosts2: No such file or directory
debug1: SSH2_MSG_KEXINIT sent
debug1: SSH2_MSG_KEXINIT received
debug1: kex: algorithm: diffie-hellman-group-exchange-sha256
debug1: kex: host key algorithm: (no match)
Unable to negotiate with 10.0.1.1 port 22: no matching host key type found. Their offer: ssh-rsa,ssh-dss
zsh: exit 255   ssh -v -o VisualHostKey=yes -o ServerAliveInterval=30
```

```
$ ssh gw@10.0.1.1
OpenSSH_6.6.1, OpenSSL 1.0.1e 11 Feb 2013
debug1: Reading configuration data /home/aaron/.ssh/config
debug1: Reading configuration data /etc/ssh/ssh_config
debug1: /etc/ssh/ssh_config line 19: Applying options for *
debug1: Connecting to 10.0.1.1 [10.0.1.1] port 22.
debug1: Connection established.
debug1: identity file /home/aaron/.ssh/id_rsa type -1
debug1: identity file /home/aaron/.ssh/id_rsa-cert type -1
debug1: identity file /home/aaron/.ssh/id_dsa type -1
debug1: identity file /home/aaron/.ssh/id_dsa-cert type -1
debug1: identity file /home/aaron/.ssh/id_ecdsa type -1
debug1: identity file /home/aaron/.ssh/id_ecdsa-cert type -1
debug1: identity file /home/aaron/.ssh/id_ed25519 type 4
debug1: identity file /home/aaron/.ssh/id_ed25519-cert type -1
debug1: Enabling compatibility mode for protocol 2.0
debug1: Local version string SSH-2.0-OpenSSH_6.6.1p1 Debian-4~bpo70+1
debug1: Remote protocol version 2.0, remote software version SSHD
debug1: no match: SSHD
debug1: SSH2_MSG_KEXINIT sent
debug1: SSH2_MSG_KEXINIT received
debug1: kex: server->client aes128-ctr hmac-md5 none
debug1: kex: client->server aes128-ctr hmac-md5 none
debug1: SSH2_MSG_KEX_DH_GEX_REQUEST(1024<3072<8192) sent
debug1: expecting SSH2_MSG_KEX_DH_GEX_GROUP
debug1: SSH2_MSG_KEX_DH_GEX_INIT sent
debug1: expecting SSH2_MSG_KEX_DH_GEX_REPLY
debug1: Server host key: RSA 1e:98:be:20:70:92:f6:b8:51:c3:89:56:50:3b:ef:ce
debug1: checking without port identifier
The authenticity of host '[10.0.1.1]:22 ([10.0.1.1]:22)' can't be established.
RSA key fingerprint is 1e:98:be:20:70:92:f6:b8:51:c3:89:56:50:3b:ef:ce.
+--[ RSA 1024]----+
| ...             |
|  . .            |
|   +             |
|o++ o. . .       |
|++.= .o S        |
| .+ +  o         |
| o..... .        |
|  o.o. .         |
| .   E.          |
+-----------------+
Are you sure you want to continue connecting (yes/no)? yes
Warning: Permanently added '[10.0.1.1]:22' (RSA) to the list of known hosts.
debug1: ssh_rsa_verify: signature correct
debug1: SSH2_MSG_NEWKEYS sent
debug1: expecting SSH2_MSG_NEWKEYS
debug1: SSH2_MSG_NEWKEYS received
debug1: Roaming not allowed by server
debug1: SSH2_MSG_SERVICE_REQUEST sent
debug1: SSH2_MSG_SERVICE_ACCEPT received
debug1: Authentications that can continue: password
debug1: Next authentication method: password
gw@10.0.1.1's password:
debug1: Authentication succeeded (password).
Authenticated to 10.0.1.1 ([10.0.1.1]:22).
debug1: channel 0: new [client-session]
debug1: Entering interactive session.
debug1: Sending environment.
debug1: Sending env LC_PAPER = en_GB.UTF-8
debug1: Sending env LC_ADDRESS = en_GB.UTF-8
debug1: Sending env LC_MONETARY = en_GB.UTF-8
debug1: Sending env LC_NUMERIC = en_GB.UTF-8
debug1: Sending env LC_ALL = en_US.UTF-8
debug1: Sending env LC_TELEPHONE = en_GB.UTF-8
debug1: Sending env LC_IDENTIFICATION = en_GB.UTF-8
debug1: Sending env LANG = en_US.utf8
debug1: Sending env LC_MEASUREMENT = en_GB.UTF-8
debug1: Sending env LC_TIME = en_GB.UTF-8
debug1: Sending env LC_NAME = en_GB.UTF-8
m610# debug1: client_input_channel_req: channel 0 rtype keepalive@openssh.com reply 1

m610#
```

# /etc/ssh/ssh_config

```
#	$OpenBSD: ssh_config,v 1.35 2020/07/17 03:43:42 dtucker Exp $

# This is the ssh client system-wide configuration file.  See
# ssh_config(5) for more information.  This file provides defaults for
# users, and the values can be changed in per-user configuration files
# or on the command line.

# Configuration data is parsed as follows:
#  1. command line options
#  2. user-specific file
#  3. system-wide file
# Any configuration value is only changed the first time it is set.
# Thus, host-specific definitions should be at the beginning of the
# configuration file, and defaults at the end.

# Site-wide defaults for some commonly used options.  For a comprehensive
# list of available options, their meanings and defaults, please see the
# ssh_config(5) man page.

# Host *
#   ForwardAgent no
#   ForwardX11 no
#   PasswordAuthentication yes
#   HostbasedAuthentication no
#   GSSAPIAuthentication no
#   GSSAPIDelegateCredentials no
#   BatchMode no
#   CheckHostIP yes
#   AddressFamily any
#   ConnectTimeout 0
#   StrictHostKeyChecking ask
#   IdentityFile ~/.ssh/id_rsa
#   IdentityFile ~/.ssh/id_dsa
#   IdentityFile ~/.ssh/id_ecdsa
#   IdentityFile ~/.ssh/id_ed25519
#   Port 22
#   Ciphers aes128-ctr,aes192-ctr,aes256-ctr,aes128-cbc,3des-cbc
#   MACs hmac-md5,hmac-sha1,umac-64@openssh.com
#   EscapeChar ~
#   Tunnel no
#   TunnelDevice any:any
#   PermitLocalCommand no
#   VisualHostKey no
#   ProxyCommand ssh -q -W %h:%p gateway.example.com
#   RekeyLimit 1G 1h
#   UserKnownHostsFile ~/.ssh/known_hosts.d/%k
```
