


基于域的消息认证，报告和一致性（DMARC，Domain-based Message Authentication, Reporting and Conformance）是一套以SPF及DKIM為基礎的電子郵件認證機制，可以檢測及防止偽冒身份、對付網路釣魚或垃圾電郵。

網域管理員可以在域名系统公佈相關政策，讓外界得知旗下域名的電子郵件提供何種方式（SPF及/或DKIM）認證身份，以及如果寄件者身份未能百分之百確認時，收件者可以如何處理郵件（放進雜件箱或直接回絕）及回報。回報機制可以讓網域管理員了解是否有第三者正在偽冒其網域身份寄出電郵。



Domain-based Message Authentication, Reporting, and Conformance (DMARC) is a standard email authentication method. DMARC helps mail administrators prevent hackers and other attackers from spoofing their organization and domain. Spoofing is a type of attack in which the From address of an email message is forged. A spoofed message appears to be from the impersonated organization or domain.




DMARC prevents spoofing & phishing
Spammers can spoof your domain or organization to send fake messages that impersonate your organization. DMARC tells receiving mail servers what to do when they get a message that appears to be from your organization, but doesn't pass authentication checks, or doesn’t meet the authentication requirements in your DMARC policy record. Messages that aren't authenticated might be impersonating your organization, or might be sent from unauthorized servers.

DMARC is always used with these two email authentication methods or checks:

Sender Policy Framework (SPF) lets the domain owner authorize IP addresses that are allowed to send email for the domain. Receiving servers can verify that messages appearing to come from a specific domain are sent from servers allowed by the domain owner.
Domain Keys Identified Mail (DKIM) adds a digital signature to every sent message. Receiving servers use the signature to verify messages are authentic, and weren't forged or changed during transit.



