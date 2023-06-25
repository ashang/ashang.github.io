Notes
================

There are different operation modes when we mention commands.
Here is a summary of them and how to switch among them.

Because of the differences of some serial connections, in some cases you need to press "Enter" to get the prompts, such as going to ONIE prompt or Linux shell prompt.
It's hard to have a better solution now. Suggest to add an additional "Enter" step for automation.

1. ONIE
- Prompt as: "ONIE:/ # "
- Potential additional "Enter" to continue.
- Onie commands usually have an "onie-" prefix, other commands are provided by busybox as a limited Linux system.
- The default user is root, password is empty.

2. NOS Login prompt
- Prompt as: "HOSTNAME login: "
- Potential additional "Enter" to continue.
- Before log-in to NOS, you get the "XX" Login prompt
- You can log in with user name and password.

3. NOS CLI
- Prompt as: "XX "
- After log-in to NOS, you get the NOS CLI.
- To exit NOS, run "exit" and press <Enter> again. Then you go to NOS login prompt.
- To enter the Linux shell, run "> start shell sh" from NOS CLI.
- To exit Linux shell, run "exit" and press <Enter> again. An alternative is 'Ctrl-D'.

4. NOS configuration mode
- Prompt as: "username@HOSTNAME> "
- You can configure the NOS in this mode.
- To enter the configuration CLI, run "configure"
- To exit from configuration CLI, run "exit".
- Run "commit" to have your configuration take effects.

5. Linux shell
- Prompt as: "username@HOSTNAME:~$ "
- You can run Linux system commands in Linux shell.
- To enter the Linux shell, run "> start shell sh" from NOS CLI.
- To exit Linux shell, run "exit" and press <Enter> again. An alternative is 'Ctrl-D'.
- Potential additional "Enter" to continue.

Checkpoints
================

- Checking in ONIE
ONIE:/ # onie-sysinfo
ONIE:/ # onie-syseeprom
ONIE:/ # diff /etc/machine-build.conf /etc/machine.conf
ONIE:/ # cat /etc/machine.conf

- Checking NOS installation
ONIE:/ # onie-nos-install http://10.10.50.22/build/x86/onie-installer-D-LinkOS-4.4.0.1-dec0be5c01-dlink-x86.bin

- Checking NOS Login
HOSTNAME login: username
Password: 
  - Potential additional "Enter" to continue.

- Checking NOS CLI
username@HOSTNAME> show system os
username@HOSTNAME> show system hwinfo
username@HOSTNAME> show system name
username@HOSTNAME> show version
username@HOSTNAME> show spanning-tree mstp bridge

- Checking NOS configuration mode
username@HOSTNAME> configure
username@HOSTNAME# exit
  - Additional "commit" is needed to have configuration take effects.

- Checking Linux shell
  - Potential additional "Enter" to continue.
username@HOSTNAME> start shell sh
username@HOSTNAME:~$ hostname
username@HOSTNAME:~$ cat /etc/lsb-release
username@HOSTNAME:~$ cat /etc/picos/branding
