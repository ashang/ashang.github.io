

blacklisting the sctp kernel module.

> Red Hat Enterprise Linux 4 and 5
> Add the following entries to the end of the /etc/modprobe.conf file:
> install sctp /bin/true
> 
> The sctp module cannot be unloaded from a running kernel if the module is
> already loaded; therefore, the above changes for /etc/modprobe.conf on Red Hat
> Enterprise Linux 4 and 5 require a reboot to take effect.
> 
> Red Hat Enterprise MRG
> Add the following entries to the end of the /etc/modprobe.conf file:
> install sctp /bin/true    
