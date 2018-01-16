
## 


Logo representing Heartbleed. Security company Codenomicon gave Heartbleed both a name and a logo, contributing to public awareness of the issue.[1][2]

Heartbleed is a security bug in the OpenSSL cryptography library, which is a widely used implementation of the Transport Layer Security (TLS) protocol. It was introduced into the software in 2012 and publicly disclosed in April 2014. Heartbleed may be exploited regardless of whether the party is using a vulnerable OpenSSL instance for TLS as a server or a client. It results from improper input validation (due to a missing bounds check) in the implementation of the TLS heartbeat extension,[3] thus the bug's name derives from heartbeat.[4] The vulnerability is classified as a buffer over-read,[5] a situation where more data can be read than should be allowed.[6]

Heartbleed is registered in the Common Vulnerabilities and Exposures database as CVE-2014-0160.[5] The federal Canadian Cyber Incident Response Centre issued a security bulletin advising system administrators about the bug.[7] A fixed version of OpenSSL was released on April 7, 2014, on the same day Heartbleed was publicly disclosed.

As of May 20, 2014, 1.5% of the 800,000 most popular TLS-enabled websites were still vulnerable to Heartbleed.[8]

TLS implementations other than OpenSSL, such as GnuTLS, Mozilla's Network Security Services, and the Windows platform implementation of TLS, were not affected because the defect existed in the OpenSSL's implementation of TLS rather than in the protocol itself.[9]


History

The Heartbeat Extension for the Transport Layer Security (TLS) and Datagram Transport Layer Security (DTLS) protocols was proposed as a standard in February 2012 by RFC 6520.[10] It provides a way to test and keep alive secure communication links without the need to renegotiate the connection each time. In 2011, one of the RFC's authors, Robin Seggelmann, then a Ph.D. student at the Fachhochschule Münster, implemented the Heartbeat Extension for OpenSSL. Following Seggelmann's request to put the result of his work into OpenSSL,[11][12][13] his change was reviewed by Stephen N. Henson, one of OpenSSL's four core developers. Henson failed to notice a bug in Seggelmann's implementation, and introduced the flawed code into OpenSSL's source code repository on December 31, 2011. The flaw spread with the release of OpenSSL version 1.0.1 on March 14, 2012. Heartbeat support was enabled by default, causing affected versions to be vulnerable.[14][15][16]
Discovery

According to Mark J. Cox of OpenSSL, Neel Mehta of Google's security team secretly reported Heartbleed on April 1, 2014 11:09 UTC.[17]

The bug was named by an engineer at Codenomicon, a Finnish cybersecurity company that also created the bleeding heart logo and launched the domain heartbleed.com to explain the bug to the public.[18] According to Codenomicon, Google's security team reported Heartbleed to OpenSSL first, but both Google and Codenomicon discovered it independently.[14] Codenomicon reports April 3, 2014 as their date of discovery and their date of notification of NCSC-FI for vulnerability coordination.[14][19]

At the time of disclosure, some 17% (around half a million) of the Internet's secure web servers certified by trusted authorities were believed to be vulnerable to the attack, allowing theft of the servers' private keys and users' session cookies and passwords.[20][21][22][23][24] The Electronic Frontier Foundation,[25] Ars Technica,[26] and Bruce Schneier[27] all deemed the Heartbleed bug catastrophic. Forbes cybersecurity columnist Joseph Steinberg wrote:

    Some might argue that Heartbleed is the worst vulnerability found (at least in terms of its potential impact) since commercial traffic began to flow on the Internet.[28]

    A British Cabinet spokesman recommended that:

        People should take advice on changing passwords from the websites they use.

	    Most websites have corrected the bug and are best placed to advise what action, if any, people need to take.[29]

	    On the day of disclosure, the Tor Project advised:

	        If you need strong anonymity or privacy on the Internet, you might want to stay away from the Internet entirely for the next few days while things settle.[30]

		The Sydney Morning Herald published a timeline of the discovery on April 15, 2014, showing that some organizations had been able to patch the bug before its public disclosure. In some cases, it is not clear how they found out.[31]
		Bugfix and deployment

		Bodo Moeller and Adam Langley of Google prepared the fix for Heartbleed. The resulting patch was added to Red Hat's issue tracker on March 21, 2014.[32] Stephen N. Henson applied the fix to OpenSSL's version control system on 7 April.[33] The first fixed version, 1.0.1g, was released on the same day. As of June 21, 2014, 309,197 public web servers remained vulnerable.[34]
		Certificate renewal and revocation

		According to Netcraft, about 30,000 of the 500,000+ X.509 certificates which could have been compromised due to Heartbleed had been reissued by April 11, 2014, although fewer had been revoked.[35]

		By May 9, 2014, only 43% of affected web sites had reissued their security certificates. In addition, 7% of the reissued security certificates used the potentially compromised keys. Netcraft stated:

		    By reusing the same private key, a site that was affected by the Heartbleed bug still faces exactly the same risks as those that have not yet replaced their SSL certificates.[36]

		    eWeek said, "[Heartbleed is] likely to remain a risk for months, if not years, to come."[37]
		    Exploitation

		    The Canada Revenue Agency reported a theft of Social Insurance Numbers belonging to 900 taxpayers, and said that they were accessed through an exploit of the bug during a 6-hour period on April 8, 2014.[38] After the discovery of the attack, the agency shut down its website and extended the taxpayer filing deadline from April 30 to May 5.[39] The agency said it would provide anyone affected with credit protection services at no cost. On April 16, the RCMP announced they had charged an engineering student in relation to the theft with unauthorized use of a computer and mischief in relation to data.[40][41]

		    The UK parenting site Mumsnet had several user accounts hijacked, and its CEO was impersonated.[42] The site later published an explanation of the incident saying it was due to Heartbleed and the technical staff patched it promptly.[43]

		    Anti-malware researchers also exploited Heartbleed to their own advantage in order to access secret forums used by cybercriminals.[44] Studies were also conducted by deliberately setting up vulnerable machines. For example, on April 12, 2014, at least two independent researchers were able to steal private keys from an experimental server intentionally set up for that purpose by CloudFlare.[45][46] Also, on April 15, 2014, J. Alex Halderman, a professor at University of Michigan, reported that his honeypot server, an intentionally vulnerable server designed to attract attacks in order to study them, had received numerous attacks originating from China. Halderman concluded that because it was a fairly obscure server, these attacks were probably sweeping attacks affecting large areas of the Internet.[47]

		    In August 2014, it was made public that the Heartbleed vulnerability enabled hackers to steal security keys from Community Health Systems, the second-biggest for-profit U.S. hospital chain in the United States, compromising the confidentiality of 4.5 million patient records. The breach happened a week after Heartbleed was first made public.[48]
		    Possible prior knowledge and exploitation

		    Many major web sites patched the bug or disabled the Heartbeat Extension within days of its announcement,[49] but it is unclear whether potential attackers were aware of it earlier and to what extent it was exploited.

		    Based on examinations of audit logs by researchers, it has been reported that some attackers may have exploited the flaw for at least five months before discovery and announcement.[50][51] Errata Security pointed out that a widely used non-malicious program called Masscan, introduced six months before Heartbleed's disclosure, abruptly terminates the connection in the middle of handshaking in the same way as Heartbleed, generating the same server log messages, adding Two new things producing the same error messages might seem like the two are correlated, but of course, they aren't.[52]

		    According to Bloomberg News, two unnamed insider sources informed it that the United States' National Security Agency had been aware of the flaw since shortly after its appearance but‍—‌instead of reporting it‍—‌kept it secret among other unreported zero-day vulnerabilities in order to exploit it for the NSA's own purposes.[53][54][55] The NSA has denied this claim,[56] as has Richard A. Clarke, a member of the National Intelligence Review Group on Intelligence and Communications Technologies that reviewed the United States' electronic surveillance policy; he told Reuters on April 11, 2014 that the NSA had not known of Heartbleed.[57] The allegation prompted the American government to make, for the first time, a public statement on its zero-day vulnerabilities policy, accepting the recommendation of the review group's 2013 report that had asserted "in almost all instances, for widely used code, it is in the national interest to eliminate software vulnerabilities rather than to use them for US intelligence collection", and saying that the decision to withhold should move from the NSA to the White House.[58]
		    Behavior
		    A depiction of Heartbleed

		    The RFC 6520 Heartbeat Extension tests TLS/DTLS secure communication links by allowing a computer at one end of a connection to send a Heartbeat Request message, consisting of a payload, typically a text string, along with the payload's length as a 16-bit integer. The receiving computer then must send exactly the same payload back to the sender.

		    The affected versions of OpenSSL allocate a memory buffer for the message to be returned based on the length field in the requesting message, without regard to the actual size of that message's payload. Because of this failure to do proper bounds checking, the message returned consists of the payload, possibly followed by whatever else happened to be in the allocated memory buffer.

		    Heartbleed is therefore exploited by sending a malformed heartbeat request with a small payload and large length field to the vulnerable party (usually a server) in order to elicit the victim's response, permitting attackers to read up to 64 kilobytes of the victim's memory that was likely to have been used previously by OpenSSL.[59] Where a Heartbeat Request might ask a party to "send back the four-letter word 'bird'", resulting in a response of "bird", a "Heartbleed Request" (a malicious heartbeat request) of "send back the 500-letter word 'bird'" would cause the victim to return "bird" followed by whatever 496 characters the victim happened to have in active memory. Attackers in this way could receive sensitive data, compromising the confidentiality of the victim's communications. Although an attacker has some control over the disclosed memory block's size, it has no control over its location, and therefore cannot choose what content is revealed.
		    Affected OpenSSL installations

		    The affected versions of OpenSSL are OpenSSL 1.0.1 through 1.0.1f (inclusive). Subsequent versions (1.0.1g[60] and later) and previous versions (1.0.0 branch and older) are not vulnerable.[61] Installations of the affected versions are vulnerable unless OpenSSL was compiled with -DOPENSSL_NO_HEARTBEATS.[62][63]
		    Vulnerable program and function

		    The vulnerable program source files are t1_lib.c and d1_both.c and the vulnerable functions are tls1_process_heartbeat() and dtls1_process_heartbeat().[64][65]
		    Patch

		    The problem can be fixed by ignoring Heartbeat Request messages that ask for more data than their payload needs.

		    Version 1.0.1g of OpenSSL adds some bounds checks to prevent the buffer over-read. For example, the following test was introduced to determine whether a heartbeat request would trigger Heartbleed; it silently discards malicious requests.

		    if (1 + 2 + payload + 16 > s->s3->rrec.length) return 0; /* silently discard per RFC 6520 sec. 4 */

		    The version control system contains a complete list of changes.[33]
		    Impact

		    The data obtained by a Heartbleed attack may include unencrypted exchanges between TLS parties likely to be confidential, including any form post data in users' requests. Moreover, the confidential data exposed could include authentication secrets such as session cookies and passwords, which might allow attackers to impersonate a user of the service.[66]

		    An attack may also reveal private keys of compromised parties,[14][16][67] which would enable attackers to decrypt communications (future or past stored traffic captured via passive eavesdropping, unless perfect forward secrecy is used, in which case only future traffic can be decrypted if intercepted via man-in-the-middle attacks).

		    An attacker having gained authentication material may impersonate the material's owner after the victim has patched Heartbleed, as long as the material is accepted (for example, until the password is changed or the private key revoked). Heartbleed therefore constitutes a critical threat to confidentiality. However, an attacker impersonating a victim may also alter data. Indirectly, Heartbleed's consequences may thus go far beyond a confidentiality breach for many systems.[68]

		    A survey of American adults conducted in April 2014 showed that 60 percent had heard about Heartbleed. Among those using the Internet, 39 percent had protected their online accounts, for example by changing passwords or canceling accounts; 29 percent believed their personal information was put at risk because of the Heartbleed bug; and 6 percent believed their personal information had been stolen.[69]
		    Client-side vulnerability

		    Although the bug received more attention due to the threat it represents for servers,[70] TLS clients using affected OpenSSL instances are also vulnerable. In what The Guardian therefore dubbed Reverse Heartbleed, malicious servers are able to exploit Heartbleed to read data from a vulnerable client's memory.[71] Security researcher Steve Gibson said of Heartbleed that:

		        It's not just a server-side vulnerability, it's also a client-side vulnerability because the server, or whomever you connect to, is as able to ask you for a heartbeat back as you are to ask them.[72]

			The stolen data could contain usernames and passwords.[73] Reverse Heartbleed affected millions of application instances.[71] Some of the vulnerable applications are listed in the "Software applications" section below.
			Specific systems affected

			Cisco Systems has identified 78 of its products as vulnerable, including IP phone systems and telepresence (video conferencing) systems.[74]
			Websites and other online services

			An analysis posted on GitHub of the most visited websites on April 8, 2014 revealed vulnerabilities in sites including Yahoo!, Imgur, Stack Overflow, Slate, and DuckDuckGo.[75][76] The following sites have services affected or made announcements recommending that users update passwords in response to the bug:

			    Akamai Technologies[77]
			        Amazon Web Services[78]
				    Ars Technica[79]
				        Bitbucket[80]
					    BrandVerity[81]
					        Freenode[82]
						    GitHub[83]
						        IFTTT[84]
							    Internet Archive[85]
							        Mojang[86]
								    Mumsnet[42]
								        PeerJ[87]
									    Pinterest[88]
									        Prezi[89]
										    Reddit[90]
										        Something Awful[91]
											    SoundCloud[92]
											        SourceForge[93]
												    SparkFun[94]
												        Stripe[95]
													    Tumblr[96][97]
													        All Wikimedia Foundation wikis (including Wikipedia in all languages)[98][99]
														    Wunderlist[100]

														    The Canadian federal government temporarily shut online services of the Canada Revenue Agency (CRA) and several government departments over Heartbleed bug security concerns.[101][102]

														    Platform maintainers like the Wikimedia Foundation advised their users to change passwords.[98]

														    The servers of LastPass were vulnerable,[103] but due to additional encryption and forward secrecy, potential attacks were not able to exploit this bug. However, LastPass recommended that its users change passwords for vulnerable websites.[104]

														    The Tor Project recommended that Tor relay operators and hidden service operators revoke and generate fresh keys after patching OpenSSL, but noted that Tor relays use two sets of keys and that Tor's multi-hop design minimizes the impact of exploiting a single relay.[30] 586 relays later found to be susceptible to the Heartbleed bug were taken off-line as a precautionary measure.[105][106][107][108]

														    Game-related services including Steam, Minecraft, Wargaming.net, League of Legends, GOG.com, Origin, Sony Online Entertainment, Humble Bundle, and Path of Exile were affected and subsequently fixed.[109]
														    Software applications

														    Vulnerable software applications include:

														        Several Hewlett-Packard server applications, such as HP System Management Homepage (SMH) for Linux and Windows.[110]
															    Some versions of FileMaker 13[111]
															        LibreOffice 4.2.0 to 4.2.2 (fixed in 4.2.3)[112][113]
																    LogMeIn claimed to have "updated many products and parts of our services that rely on OpenSSL".[114]
																        Multiple McAfee products, in particular some versions of software providing anti-viral coverage for Microsoft Exchange, software firewalls, and McAfee Email and Web Gateways[115]
																	    MySQL Workbench 6.1.4 and earlier[116]
																	        Oracle MySQL Connector/C 6.1.0-6.1.3 and Connector/ODBC 5.1.13, 5.2.5-5.2.6, 5.3.2[116]
																		    Oracle Big Data Appliance (includes Oracle Linux 6)[116]
																		        Primavera P6 Professional Project Management (includes Primavera P6 Enterprise Project Portfolio Management)[116]
																			    WinSCP (FTP client for Windows) 5.5.2 and some earlier versions (only vulnerable with FTP over TLS/SSL, fixed in 5.5.3)[117]
																			        Multiple VMware products, including VMware ESXi 5.5, VMware Player 6.0, VMware Workstation 10 and the series of Horizon products, emulators and cloud computing suites[118]

																				Several other Oracle Corporation applications were affected.[116]
																				Operating systems/firmwares

																				Several GNU/Linux distributions were affected, including Debian[119] (and derivatives such as Linux Mint and Ubuntu[120]) and Red Hat Enterprise Linux[121] (and derivatives such as CentOS,[122] Oracle Linux 6[116] and Amazon Linux[123]), as well as the following operating systems and firmware implementations:

																				    Android 4.1.1, used in various portable devices.[124] Chris Smith writes in Boy Genius Report that just this one version of Android is affected but that it is a popular version of Android (Chitika claim 4.1.1 is on 50 million devices;[125] Google describe it as less than 10% of activated Android devices). Other Android versions are not vulnerable as they either have heartbeats disabled or use an unaffected version of OpenSSL.[126][127]
																				        Firmware for some AirPort base stations[128]
																					    Firmware for some Cisco Systems routers[74][129][130]
																					        Firmware for some Juniper Networks routers[130][131]
																						    IPCop 2.1.3 and some earlier versions (fixed in 2.1.4)[132]
																						        pfSense 2.1.0 and 2.1.1 (fixed in 2.1.2)[133]
																							    DD-WRT versions between and including 19163 and 23881 (fixed in 23882)[134]
																							        Western Digital My Cloud product family firmware[135]

																								Vulnerability testing services

																								Several services have been made available to test whether Heartbleed affects a given site. However, many services have been claimed to be ineffective for detecting the bug.[136] The available tools include:

																								    Tripwire SecureScan[137]
																								        AppCheck - static binary scan, from Codenomicon[138]
																									    Arbor Network's Pravail Security Analytics[139]
																									        Norton Safeweb Heartbleed Check Tool[140]
																										    Heartbleed testing tool by a European IT security company[141]
																										        Heartbleed Scanner by Italian cryptologist Filippo Valsorda[142]
																											    Heartbleed Vulnerability Test by Cyberoam[143]
																											        Critical Watch Free Online Heartbleed Tester[144]
																												    Metasploit Heartbleed scanner module[145]
																												        Heartbleed Server Scanner by Rehmann[146]
																													    Lookout Mobile Security Heartbleed Detector, an app for Android devices that determines the OpenSSL version of the device and indicates whether the vulnerable heartbeat is enabled[147]
																													        Heartbleed checker hosted by LastPass[148]
																														    Online network range scanner for Heartbleed vulnerability by Pentest-Tools.com[149]
																														        Official Red Hat offline scanner written in the Python language[150]
																															    Qualys SSL Labs' SSL Server Test[151] which not only looks for the Heartbleed bug, but can also find other SSL/TLS implementation errors.
																															        Browser extensions, such as Chromebleed[152] and FoxBleed[153]
																																    SSL Diagnos[154]
																																        CrowdStrike Heartbleed Scanner[155] - Scans routers, printers and other devices connected inside a network including intranet web sites.[156]
																																	    Netcraft Site Report[157] - indicates whether a website's confidentiality could be jeopardized due to a past exploitation of Heartbleed by checking data from Netcraft's SSL Survey to determine whether a site offered the heartbeat TLS Extension prior to the Heartbleed disclosure. The Netcraft Extensions for Chrome, Firefox and Opera[158] also perform this check, whilst looking for potentially compromised certificates.[159]

																																	    Other security tools have added support for finding this bug. For example, Tenable Network Security wrote a plugin for its Nessus vulnerability scanner that can scan for this fault.[160] The Nmap security scanner includes a Heartbleed detection script from version 6.45.[161]

																																	    Sourcefire has released Snort rules to detect Heartbleed attack traffic and possible Heartbleed response traffic.[162] Open source packet analysis software such as Wireshark and tcpdump can identify Heartbleed packets using specific BPF packet filters that can be used on stored packet captures or live traffic.[163]
																																	    Remediation

																																	    Vulnerability to Heartbleed is resolved by updating OpenSSL to a patched version (1.0.1g or later). OpenSSL can be used either as a standalone program, a dynamic shared object, or a statically-linked library; therefore, the updating process can require restarting processes loaded with a vulnerable version of OpenSSL as well as re-linking programs and libraries that linked it statically. In practice this means updating packages that link OpenSSL statically, and restarting running programs to remove the in-memory copy of the old, vulnerable OpenSSL code.

																																	    After the vulnerability is patched, server administrators must address the potential breach of confidentiality. Because Heartbleed allowed attackers to disclose private keys, they must be treated as compromised; keypairs must be regenerated, and certificates that use them must be reissued; the old certificates must be revoked. Heartbleed also had the potential to allow disclosure of other in-memory secrets; therefore, other authentication material (such as passwords) should also be regenerated. It is rarely possible to confirm that a system which was affected has not been compromised, or to determine whether a specific piece of information was leaked.[164]

																																	    Since it is difficult or impossible to determine when a credential might have been compromised and how it might have been used by an attacker, certain systems may warrant additional remediation work even after patching the vulnerability and replacing credentials. For example, signatures made by keys that were in use with a vulnerable OpenSSL version might well have been made by an attacker; this raises the possibility integrity has been violated, and opens signatures to repudiation. Validation of signatures and the legitimacy of other authentications made with a potentially compromised key (such as client certificate use) must be done with regard to the specific system involved.
																																	    Browser security certificate revocation awareness

																																	    Since Heartbleed threatened the privacy of private keys, users of a website which was compromised could continue to suffer from Heartbleed's effects until their browser is made aware of the certificate revocation or the compromised certificate expires.[165] For this reason, remediation also depends on users making use of browsers that have up-to-date certificate revocation lists (or OCSP support) and honour certificate revocations.
																																	    Root causes, possible lessons, and reactions

																																	    Although evaluating the total cost of Heartbleed is difficult, eWEEK estimated US$500 million as a starting point.[166]

																																	    David A. Wheeler's paper How to Prevent the next Heartbleed analyzes why Heartbleed wasn't discovered earlier, and suggests several techniques which could have led to a faster identification, as well as techniques which could have reduced its impact. According to Wheeler, the most efficient technique which could have prevented Heartbleed is an atypical test suite thoroughly performing what he calls negative testing, i.e. testing that invalid inputs cause failures rather than successes. Wheeler highlights that a single general-purpose test suite could serve as a base for all TLS implementations.[167]

																																	    According to an article on The Conversation written by Robert Merkel, Heartbleed revealed a massive failure of risk analysis. Merkel thinks OpenSSL gives more importance to performance than to security, which no longer makes sense in his opinion. But Merkel considers that OpenSSL should not be blamed as much as OpenSSL users, who chose to use OpenSSL, without funding better auditing and testing. Merkel explains that two aspects determine the risk that more similar bugs will cause vulnerabilities. One, the library's source code influences the risk of writing bugs with such an impact. Secondly, OpenSSL's processes affect the chances of catching bugs quickly. On the first aspect, Merkel mentions the use of the C programming language as one risk factor which favored Heartbleed's appearance, echoing Wheeler's analysis.[167][168]

																																	    On the same aspect, Theo de Raadt, founder and leader of the OpenBSD and OpenSSH projects, has criticized the OpenSSL developers for writing their own memory management routines and thereby, he claims, circumventing OpenBSD C standard library exploit countermeasures, saying "OpenSSL is not developed by a responsible team."[169][170] Following Heartbleed's disclosure, members of the OpenBSD project forked OpenSSL into LibreSSL.[171]

																																	    The author of the change which introduced Heartbleed, Robin Seggelmann,[172] stated that he missed validating a variable containing a length and denied any intention to submit a flawed implementation.[11] Following Heartbleed's disclosure, Seggelmann suggested focusing on the second aspect, stating that OpenSSL is not reviewed by enough people.[173] Although Seggelmann's work was reviewed by an OpenSSL core developer, the review was also intended to verify functional improvements, a situation making vulnerabilities much easier to miss.[167]

																																	    OpenSSL core developer Ben Laurie claimed that a security audit of OpenSSL would have caught Heartbleed.[174] Software engineer John Walsh commented:

																																	        Think about it, OpenSSL only has two [fulltime] people to write, maintain, test, and review 500,000 lines of business critical code.[175]

																																		The OpenSSL foundation's president, Steve Marquess, said "The mystery is not that a few overworked volunteers missed this bug; the mystery is why it hasn't happened more often."[176] David A. Wheeler described audits as an excellent way to find vulnerabilities in typical cases, but noted that "OpenSSL uses unnecessarily complex structures, which makes it harder to both humans and machines to review." He wrote:

																																		    There should be a continuous effort to simplify the code, because otherwise just adding capabilities will slowly increase the software complexity. The code should be refactored over time to make it simple and clear, not just constantly add new features. The goal should be code that is “obviously right”, as opposed to code that is so complicated that “I can’t see any problems”.[167]

																																		    LibreSSL made a big code cleanup, removing more than 90,000 lines of C code just in its first week.[177]

																																		    According to security researcher Dan Kaminsky, Heartbleed is sign of an economic problem which needs to be fixed. Seeing the time taken to catch this simple error in a simple feature from a "critical" dependency, Kaminsky fears numerous future vulnerabilities if nothing is done. When Heartbleed was discovered, OpenSSL was maintained by a handful of volunteers, only one of whom worked full-time.[178] Yearly donations to the OpenSSL project were about US$2,000.[179] The Heartbleed website from Codenomicon advised money donations to the OpenSSL project.[14] After learning about donations for the 2 or 3 days following Heartbleed's disclosure totaling US$841, Kaminsky commented "We are building the most important technologies for the global economy on shockingly underfunded infrastructure."[180] Core developer Ben Laurie has qualified the project as "completely unfunded".[179] Although the OpenSSL Software Foundation has no bug bounty program, the Internet Bug Bounty initiative awarded US$15,000 to Google's Neel Mehta, who discovered Heartbleed, for his responsible disclosure.[179]

																																		    Paul Chiusano suggested Heartbleed may have resulted from failed software economics.[181]

																																		    The industry's collective response to the crisis was the Core Infrastructure Initiative, a multimillion-dollar project announced by the Linux Foundation on April 24, 2014 to provide funds to critical elements of the global information infrastructure.[182] Founding backers include Amazon, Dell, Facebook, Fujitsu, Google, IBM, Intel, Microsoft, NetApp, Rackspace, VMware and The Linux Foundation. The initiative intends to allow lead developers to work full-time on their projects and to pay for security audits, hardware and software infrastructure, travel, and other expenses.[183] OpenSSL is a candidate to become the first recipient of the initiative's funding.[182]






## Heartbeat

heartbeat is a periodic signal generated by hardware or software to indicate normal operation or to synchronize other parts of a computer system.[1] Usually a heartbeat is sent between machines at a regular interval in the order of seconds. If the endpoint does not receive a heartbeat for a time —usually a few heartbeat intervals—, the machine that should have sent the heartbeat is assumed to have failed.[2]
Heartbeat protocol

A heartbeat protocol is generally used to negotiate and monitor the availability of a resource, such as a floating IP address. Typically when a heartbeat starts on a machine, it will perform an election process with other machines on the heartbeat network to determine which machine, if any, owns the resource. On heartbeat networks of more than two machines, it is important to take into account partitioning, where two halves of the network could be functioning but not able to communicate with each other. In a situation such as this, it is important that the resource is only owned by one machine, not one machine in each partition.

As a heartbeat is intended to be used to indicate the health of a machine, it is important that the heartbeat protocol and the transport that it runs on is as reliable as possible. Effecting a failover because of a false alarm may, depending on the resource, be highly undesirable. It is also important to react quickly to an actual failure, so again it is important that the heartbeat is reliable. For this reason it is often desirable to have heartbeat running over more than one transport; for instance, an Ethernet segment using UDP/IP, and a serial link.


## Keepalive

A keepalive (KA) is a message sent by one device to another to check that the link between the two is operating, or to prevent the link from being broken.

Contents

    1 Description
        2 TCP keepalive
	    3 Keepalive on higher layers
	        4 Other uses
		        4.1 HTTP keepalive
			    5 See also
			        6 References

				Description

				A keepalive signal is often sent at predefined intervals, and plays an important role on the Internet. After a signal is sent, if no reply is received the link is assumed to be down and future data will be routed via another path until the link is up again. A keepalive signal can also be used to indicate to Internet infrastructure that the connection should be preserved. Without a keepalive signal, intermediate NAT-enabled routers can drop the connection after timeout.

				Since the only purpose is to find links that don't work or to indicate connections that should be preserved, keepalive messages tend to be short and not take much bandwidth. However, their precise format and usage terms depend on the communication protocol.
				TCP keepalive

				Transmission Control Protocol (TCP) keepalives are an optional feature, and if included must default to off.[1] The keepalive packet contains null data. In an Ethernet network, a keepalive frame length is 60 bytes, while the server response to this, also a null data frame, is 54 bytes.[citation needed] There are three parameters[2] related to keepalive:

				    Keepalive time is the duration between two keepalive transmissions in idle condition. TCP keepalive period is required to be configurable and by default is set to no less than 2 hours.
				        Keepalive interval is the duration between two successive keepalive retransmissions, if acknowledgement to the previous keepalive transmission is not received.
					    Keepalive retry is the number of retransmissions to be carried out before declaring that remote end is not available.

					    Keepalive on higher layers

					    Since TCP keepalive is optional, various protocols (e.g. SMB[3] and TLS[4]) add a similar feature on top of it. This is also common for protocols which maintain a session over a connectionless protocol, e.g. OpenVPN over UDP.[5]
					    Other uses
					    HTTP keepalive
					    Main article: HTTP persistent connection

					    The Hypertext Transfer Protocol uses the keyword "Keep-Alive" in the "Connection" header to signal that the connection should be kept open for further messages (this is the default in HTTP 1.1, but in HTTP 1.0 the default was to use a new connection for each request/reply pair).[6] Despite the similar name, this function is entirely unrelated.


## References

- https://en.wikipedia.org/wiki/Heartbleed
- https://en.wikipedia.org/wiki/Watchdog_timer
- https://en.wikipedia.org/wiki/Keepalive
