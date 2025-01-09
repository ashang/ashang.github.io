

>Tripwire uses a pair of keys to sign various files, thus ensuring their unaltered state.  By accepting here, you will be prompted
>for the passphrase for the first of those keys, the site key, during the installation.  You are also agreeing to create a site
>key if one doesn't exist already.  Tripwire uses the site key to sign files that may be common to multiple systems, e.g. the
>configuration & policy files.  See twfiles(5) for more information.
>
>Unfortunately, due to the Debian installation process, there is a period of time where this passphrase exists in a unencrypted
>format. Were an attacker to have access to your machine during this period, he could possibly retrieve your passphrase and use it
>at some later point.
>
>If you would rather not have this exposure, decline here.  You will then need to create a site key, configuration file & policy
>file by hand.  See twadmin(8) for more information.
>
>Do you wish to create/use your site key passphrase during installation?
>
>                                        <Yes>                                          <No>

>Tripwire keeps its configuration in a encrypted database that is
>generated, by default, from /etc/tripwire/twcfg.txt
>
>Any changes to /etc/tripwire/twcfg.txt, either as a result of a change
>in this package or due to administrator activity, require the
>regeneration of the encrypted database before they will take effect.
>
>Selecting this action will result in your being prompted for the site
>key passphrase during the post-installation process of this package.
>
>Rebuild Tripwire configuration file?
>
>                   <Yes>                       <No>
>



>Tripwire uses two different keys for authentication and encryption of files.  The site key is used to protect files that could be used across several systems.  This includes the policy and configuration files.
>
>You are being prompted for this passphrase either because no site key exists at this time or because you have requested the rebuilding of the policy or configuration files.
>
>Remember this passphrase; it is not stored anywhere!
>
>Enter site-key passphrase:
>
>
>        <Ok>
>
