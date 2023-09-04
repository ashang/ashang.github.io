





Progress: [ 85%] [#######################################################################.............]
 Package configuration
 ────────────────────────────────────────────────────────────────────────────────────────────────────────
 ┌───────────────────────────────────────Get site passphrase──────────────────────────────────────────┐
 │ Tripwire uses two different keys for authentication and encryption of files. The site key is       │
 │ used to protect files that could be used across several systems. This includes the policy and      │
 │ configuration files.                                                                               │
 │                                                                                                    │
 │ You are being prompted for this passphrase either because no site key exists at this time or       │
 │ because you have requested the rebuilding of the policy or configuration files.                    │
 │                                                                                                    │
 │ Remember this passphrase; it is not stored anywhere!                                               │
 │                                                                                                    │
 │ Enter site-key passphrase:                                                                         │
 │ ┌────────────────────────────────────────────────────────────────────────────────────────────────┐ │
 │ │                                                                                                │ │
 ├─└────────────────────────────────────────────────────────────────────────────────────────────────┘─┤
 │                                             <  OK  >                                               │
 └────────────────────────────────────────────────────────────────────────────────────────────────────┘

 Package configuration
 ────────────────────────────────────────────────────────────────────────────────────────────────────────




                ┌────────────────────────Get site passphrase───────────────────────────┐
                │ Please repeat the site pass phrase to be sure you didn't mistype.    │
                │                                                                      │
                │ Repeat the site-key passphrase:                                      │
                │ ┌──────────────────────────────────────────────────────────────────┐ │
                │ │                                                                  │ │
                ├─└──────────────────────────────────────────────────────────────────┘─┤
                │                               <  OK  >                               │
                └──────────────────────────────────────────────────────────────────────┘















 ┌────↑(-)───────────────────────────────Get site passphrase──────────────────────────────────────────┐──
 │ The site passphrase you entered is incorrect.  If you think you mistyped it and would like to      │
 │ retry the current operation accept below.  If you can't remember the passphrase, decline below     │
 │ and the tripwire installation process will terminate gracefully.  When you remember the site       │
 │ passphrase continue the installation process by running                                            │
 │                                                                                                    │
 │   dpkg-reconfigure tripwire                                                                        │
 │                                                                                                    │
 │                                                                                                    │
 │ as root.                                                                                           │
 │                                                                                                    │
 │ If you have completely forgotten your site passphrase, generate a new site key with a new          │
 │ passphrase by running                                                                              │
 │                                                                                                    │
 │   twadmin -m G -S /etc/tripwire/site.key                                                           │
 ├────↓(+)────────────────────────────────────────────────────────────────────────────────────98%─────┤
 │                                             < E



                       ┌─────────────────Get site passphrase────────────────────┐
                       │ Your site passphrase is incorrect. Retry operation?    │
                       │                                                        │
                       │                                                        │
                       ├────────────────────────────────────────────────────────┤
                       │               < Y
