


Error code: SSL_ERROR_RX_RECORD_TOO_LONG


about:config

search tls

security.tls.version.enable-deprecated

true

## Self-signed certificate

On a site with a self-signed certificate you will see the error code ERROR_SELF_SIGNED_CERT and the following error description, after you click on Advanced on the error page:
The certificate is not trusted because it is self-signed.

A self-signed certificate that wasn't issued by a recognized certificate authority is not trusted by default. Self-signed certificates can make your data safe from eavesdroppers, but say nothing about who the recipient of the data is. This is common for intranet websites that aren't available publicly and you may bypass the warning for such sites.
Bypassing the warning
Warning: You should never add a certificate exception for a legitimate major website or sites where financial transactions take place – in this case an invalid certificate can be an indication that your connection is compromised by a third party.

If the website allows it, you can bypass the warning in order to visit the site, even thought its certificate is not being trusted by default:

    On the warning page, click Advanced.
    Click Accept the Risk and Continue. 


## Apache conf



    Error code: ssl_error_rx_record_too_long

    This usually means the implementation of SSL on your server is not correct. The error is usually caused by a server side problem which the server administrator will need to investigate.

    Below are some things we recommend trying.

        Ensure that port 443 is open and enabled on your server. This is the standard port for https communications.

        If SSL is using a non-standard port then FireFox 3 can sometimes give this error. Ensure SSL is running on port 443.

        If using Apache2 check that you are using port 443 for SSL. This can be done by setting the ports.conf file as follows

        Listen 80
        Listen 443 https

        Make sure you do not have more than one SSL certificate sharing the same IP. Please ensure that all SSL certificates utilise their own dedicated IP.

        If using Apache2 check your vhost config. Some users have reported changing <VirtualHost> to _default_ resolved the error.


