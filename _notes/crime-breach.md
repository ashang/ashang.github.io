

CRIME（英語：Compression Ratio Info-leak Made Easy，意思为：压缩率使信息容易泄露）是一种可攻击安全隐患（Exploit），通过它可窃取启用数据压缩特性的HTTPS或SPDY协议传输的私密Web Cookie。[1][2]在成功解读身份验证Cookie后，攻击者可以实行会话劫持和发动进一步攻击。CRIME被分配为CVE-2012-4929。[3]




此漏洞立足于选择明文攻击配合数据压缩无意间造成的信息泄露，类似密码学家John Kelsey在2002年所述的方式。[4]它依赖于攻击者能观察浏览器发送的密文的大小，并在同时诱导浏览器发起多个精心设计的到目标网站的连接。攻击者会观察已压缩请求载荷的大小，其中包括两个浏览器只发送到目标网站的私密Cookie，以及攻击者创建的变量内容。当压缩内容的大小降低时，攻击者可以推断注入内容的某些部分与源内容的某些部分匹配，其中包括攻击者想要发掘的私密内容。使用分治法技术可以用较小的尝试次数解读真正秘密的内容，需要恢复的字节数会大幅降低。[2][5]

CRIME利用方法由安全研究人员Juliano Rizzo和Thai Duong创建，他们还创建了BEAST利用方法。[1]此利用方法在2012年ekoparty安全会议上完全展示。[6]Rizzo和Duong指出，CRIME是一种通用攻击，可以对众多协议进行有效攻击，包括但不限于SPDY（始终压缩请求头）、TLS（可能压缩记录）和HTTP（可能压缩响应）。

避免
CRIME可以被禁用压缩挫败，无论是在客户端的浏览器中禁用压缩，还是由网站根据TLS的协商特性阻止使用数据压缩。



缓解
截至2012年9月，针对SPDY和TLS层压缩的CRIME利用方法在最新版本的Chrome和Firefox浏览器中已做缓解


]nginx网页服务器从使用OpenSSL 1.0.0+的1.0.9/1.1.6（2011年10月/11月）和使用所有OpenSSL版本的1.2.2/1.3.2（2012年6月/7月）起不会受到此攻击。[8]

应注意的是，截至2013年12月，针对HTTP压缩的CRIME利用并未完全缓解。Rizzo和Duong已警告此漏洞的适用范围可能比SPDY和TLS压缩更加普遍。


。Rizzo和Duong已警告此漏洞的适用范围可能比SPDY和TLS压缩更加普遍。

BREACH
在2013年8月的Black Hat会议上，研究员Gluck、Harris和Prado宣布了一个CRIME利用方法的变体，它针对HTTP压缩，称之为BREACH（全称：Browser Reconnaissance and Exfiltration via Adaptive Compression of Hypertext的缩写，意为“通过自适应超文本压缩做浏览器侦听和渗透”）。它通过攻击网页服务器为减少网络流量内置的HTTP数据压缩来解读HTTPS私密信息。


