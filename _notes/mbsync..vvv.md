gmail + outlook


connect to the IMAP server:

openssl s_client -crlf -connect outlook.office365.com:993 -quiet
depth=2 C = US, O = DigiCert Inc, OU = www.digicert.com, CN = DigiCert Global Root CA
verify return:1
depth=1 C = US, O = DigiCert Inc, CN = DigiCert Cloud Services CA-1
verify return:1
depth=0 C = US, ST = Washington, L = Redmond, O = Microsoft Corporation, CN = outlook.com
verify return:1
* OK The Microsoft Exchange IMAP4 service is ready. [UwBDADEAUABSADgAMABDAEEAMAAwADUAOAAuAGwAYQBtAHAAcgBkADgAMAAuAHAAcgBvAGQALgBvAHUAdABsAG8AbwBrAC4AYwBvAG0A]
Apparently i'm connected to the IMAP server, so now i try to authenticate. First i get the list of AUTH methods that the server accepts.

02 CAPABILITY
* CAPABILITY IMAP4 IMAP4rev1 AUTH=PLAIN AUTH=XOAUTH2 SASL-IR UIDPLUS MOVE ID UNSELECT CHILDREN IDLE NAMESPACE LITERAL+
02 OK CAPABILITY completed
So, i try to authenticate using PLAIN. As far as i understand i need to put the credentials in base64 format, so i use the command "base64" from my linux server in order to get. So, if my username is "user@mydomain.com" and my password is "mysecretpassword" i use this:

echo -en "\0user@mydomain.com\0mysecretpassword" | openssl base64
I get

AHVzZXJAbXlkb21haW4uY29tAG15c2VjcmV0cGFzc3dvcmQ=








## var stream = new MemoryStream();
var logger = new ProtocolLogger(stream, false);

using (var client = new MailKit.Net.Imap.ImapClient(logger))
{
    try
    {
        client.Connect("outlook.office365.com", 993, true);
        client.AuthenticationMechanisms.Remove("XOAUTH2");
        client.Authenticate(@"SVC_CubitDLE@lyse.no", @".whb----%RS*,H^");
        var inbox = client.Inbox;
        inbox.Open(FolderAccess.ReadWrite);
        var uids = await inbox.SearchAsync(SearchQuery.NotSeen);
    } catch (Exception exc){
        exc.Dump();
        stream.Position = 0;
        var reader = new StreamReader(stream);
        reader.ReadToEnd().Dump();
    }
}
I tried with and without the line client.AuthenticationMechanisms.Remove("XOAUTH2");.

The exception thrown is AuthenticationException with message LOGIN failed.

The log emitted in the steam is:

S: * OK The Microsoft Exchange IMAP4 service is ready. [UABSADAAUAAyADYANABDAEEAMAAxADkAOAAuAEYAUgBBAFAAMgA2ADQALgBQAFIATwBEAC4ATwBVAFQATABPAE8ASwAuAEMATwBNAA==]
C: E00000000 CAPABILITY
S: * CAPABILITY IMAP4 IMAP4rev1 AUTH=PLAIN AUTH=XOAUTH2 SASL-IR UIDPLUS ID UNSELECT CHILDREN IDLE NAMESPACE LITERAL+
S: E00000000 OK CAPABILITY completed.
C: E00000001 AUTHENTICATE PLAIN AFNWQ19DdWJpAAAAAAAAAAAAAAAAAAAASF4=
S: E00000001 NO AUTHENTICATE failed.
C: E00000002 LOGIN SVC_CubitDLE@lyse.no ".whb----%RS*,H^"
S: E00000002 NO LOGIN failed.
Any i




IMAPAccount gmail
Host imap.gmail.com
User redacted@gmail.com
Pass "redacte_pw"
Port 993
SSLType IMAPS
#from macowners club post https://macowners.club/posts/email-emacs-mu4e-macos/
SSLVersions TLSv1.2
AuthMechs PLAIN
SystemCertificates no
#end
#CertificateFile /etc/ssl/certs/ca-certificates.crt
CertificateFile ~/.maildir/certs/root-certificates.pem

IMAPStore gmail-remote
Account gmail

MaildirStore gmail-local
Subfolders Verbatim
Path ~/.maildir/gmailJG
Inbox ~/.maildir/gmailJG/Inbox

Channel gmail
Master :gmail-remote:
Slave :gmail-local:
Patterns * ![Gmail]* "[Gmail]/Sent Mail" "[Gmail]/Starred" "[Gmail]/All Mail" "[Gmail]/Trash"
Create Both
#macowners s# etup doesnt have above but instead..
# Create Near
# Sync All
# Expunge Both
#end
SyncState *
# to get root cert on mac...
#    Open the Application Keychain Access.app
#    Select System Roots in the sidebar
# Select all items listen here – ⌘ + a
# Export the items with ⇧ + ⌘ + e to the file ~/.maildir/certificates/root-certificates.pem
That's it. The code error gets hit from commenting out the AuthMechs line above (which the video of a unix install doesn't have). Adding the plain auth just gives a bad pw error.


##


imap.gmail.com

Requires SSL: Yes

Port: 993

Outgoing Mail (SMTP) Server	
smtp.gmail.com

Requires SSL: Yes

Requires TLS: Yes (if available)

Requires Authentication: Yes

Port for SSL: 465

Port for TLS/STARTTLS: 587



Server name: outlook.office365.com
Port: 995
Encryption method: TLS


Server name: outlook.office365.com
Port: 993
Encryption method: TLS


Server name: smtp.office365.com
Port: 587
Encryption method: STARTTLS

usziftejlsmsnoqk

imap.gmail.com

Requires SSL: Yes

Port: 993

Outgoing Mail (SMTP) Server	
smtp.gmail.com

Requires SSL: Yes

Requires TLS: Yes (if available)

Requires Authentication: Yes

Port for SSL: 465

Port for TLS/STARTTLS: 587

## App password

```sh
$ mbsync -V live
C: 0/1  B: 0/0  M: +0/0 *0/0 #0/0  S: +0/0 *0/0 #0/0
Channel live
Opening master store live-remote...
Resolving outlook.office365.com... ok
Connecting to outlook.office365.com (40.100.29.242:993)...
Opening slave store live-local...
Connection is now encrypted
Logging in...
Authenticating with SASL mechanism PLAIN...
IMAP command 'AUTHENTICATE PLAIN <authdata>' returned an error: NO AUTHENTICATE failed.
C: 1/1  B: 0/0  M: +0/0 *0/0 #0/0  S: +0/0 *0/0 #0/0
...
$ mbsync -V live
Reading configuration file mbsyncrc
C: 0/1  B: 0/0  M: +0/0 *0/0 #0/0  S: +0/0 *0/0 #0/0
Channel live
Opening master store live-remote...
Resolving outlook.office365.com... ok
Connecting to outlook.office365.com (52.98.74.178:993)...
Opening slave store live-local...
Connection is now encrypted
Logging in...
Authenticating with SASL mechanism PLAIN...
C: 0/1  B: 0/2  M: +0/0 *0/0 #0/0  S: +0/0 *0/0 #0/0
Opening master box INBOX...
Opening slave box INBOX...
Maildir notice: no UIDVALIDITY, creating new.
Loading master...
Loading slave...
slave: 1 messages, 0 recent
master: 5 messages, 5 recent
Synchronizing...
C: 0/1  B: 1/2  M: +1/1 *0/0 #0/0  S: +5/5 *0/0 #0/0
Opening master box Drafts...
Opening slave box Drafts...
Creating slave Drafts...
Maildir notice: no UIDVALIDITY, creating new.
Loading master...
master: 0 messages, 0 recent
Loading slave...
slave: 0 messages, 0 recent
Synchronizing...
C: 1/1  B: 2/2  M: +1/1 *0/0 #0/0  S: +5/5 *0/0 #0/0
```

