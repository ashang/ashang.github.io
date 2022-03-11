
> system_default = system_default_sect
# aaron@kali:/etc/ssl
$ more kali.cnf
# The configurations proposed here are only used if /etc/ssl/openssl.cnf has
# been modified so that ssl_sect.system_default points to one of them. The
# kali-tweaks tool lets you easily switch that configuration entry.
#
# By default a kali system should be configured for wide compatibility,
# to easily interact with servers using old vulnerable protocols.

[kali_wide_compatibility]
MinProtocol = SSLv3
CipherString = ALL@SECLEVEL=0

[kali_strong_security]
MinProtocol = TLSv1.2
CipherString = DEFAULT@SECLEVEL=2

