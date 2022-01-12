```
$ host -a bing.com
Trying "bing.com"
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 38287
;; flags: qr rd ra; QUERY: 1, ANSWER: 1, AUTHORITY: 0, ADDITIONAL: 0

;; QUESTION SECTION:
;bing.com.                      IN      ANY

;; ANSWER SECTION:
bing.com.               3593    IN      HINFO   "RFC8482" ""

Received 47 bytes from 10.10.50.10#53 in 17 ms
```


```
$ host -a bing.com.
Trying "bing.com"
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 49893
;; flags: qr rd ra; QUERY: 1, ANSWER: 9, AUTHORITY: 0, ADDITIONAL: 0

;; QUESTION SECTION:
;bing.com.                      IN      ANY

;; ANSWER SECTION:
bing.com.               3600    IN      HINFO   "RFC8482" ""
bing.com.               3600    IN      NS      ns1-204.azure-dns.com.
bing.com.               3600    IN      NS      dns2.p09.nsone.net.
bing.com.               3600    IN      NS      dns4.p09.nsone.net.
bing.com.               3600    IN      NS      ns3-204.azure-dns.org.
bing.com.               3600    IN      NS      ns4-204.azure-dns.info.
bing.com.               3600    IN      NS      dns3.p09.nsone.net.
bing.com.               3600    IN      NS      ns2-204.azure-dns.net.
bing.com.               3600    IN      NS      dns1.p09.nsone.net.

Received 271 bytes from 10.10.50.10#53 in 57 ms
```


主机名后面没有点，就认为是主机名，所以先添加search里的每一项依次组成FQDN（完全合格域名）来查询，完全合格域名查询未找到，就再认为主机名是完全合格域名来查询。

host
 -l参数：如果后面的domain允许allow-transfer时，则列出该domain所管理的所有主机数据。 

 
 主机名中有点（不是末尾有点），就认为是完全合格域名，先用它来查询，查询失败就把它当成是主机名来进行，添加search里的每一项组成FQDN（完全合格域名）来查询。

主机名中末尾有点，则认为是完全合格域名，只用它来查询（不会再添加search里的每一项）。查询次数会与search里项域名个数有关。


# NetworkManager 是最常见的自动配置网络和 DNS 的工具。比如在 Debian 和 Fedora 中它负责配置 /etc/resolv.conf。NetworkManager 可以和其他工具共存，即使禁用了所有其他管理 resolv.conf 的程序，NetworkManager 也会跳出来接管 resolv.conf。

可以将 NetworkManager 的主配置部分的选项 dns 设置为 none 来禁用其对 DNS 的管理功能：

$ echo -e "[main]\ndns=none" > /etc/NetworkManager/conf.d/no-dns.conf
$ systemctl restart NetworkManager.service


如果是 Debian 8.0 或 Ubuntu 15.04，并且启用了 IPv6，那么你可能会遇到 `resolvconf` 和 `rdnssd` 互相争夺 resolv.conf 控制器[1]的情况。两个服务都想控制这个文件，每隔几毫秒就会覆盖对方的配置，从而导致间歇性的 DNS 解析中断。可以直接禁用并立即停止这两个服务：

$ systemctl disable --now resolvconf.service rdnssd.service





systemd-resolved

如果是 Ubuntu 16.10 或更新的版本，则由 systemd-resolved 服务来管理 DNS，可以使用下面的命令来禁用并立即停止该服务：

$ systemctl disable --now systemd-resolved.service




domain mydomain.com这个用来指定本地的域名，在没有设置search的情况下，search默认为domain的值。这个值可以随便配，目前在我看来，domain除了当search的默认值外，没有其它用途。也就说一旦配置search，那domain就没用了。

search google.com baidu.com该选项可以用来指定多个域名，中间用空格或tab键隔开。




“domain”指定本地的網域名稱，如果查詢時的名稱沒有包含小數點，則會自動補上此處的網域名稱為字尾再送給DNS伺服器。 


需要注意的是當我們想嘗試多種在沒有包含小數點，於字尾補上所需要搜尋的網域名稱時，我們會在"search"中指定幾種組合給DNS伺服器，而不能在"domain"中指定。因為“domain”是指定本地的網域名稱，而搜尋時也以“domain”為優先嘗試，如果失敗之後才會嘗試"search"中的組合。 



 domain和search不能共存；如果同时存在，后面出现的将会被使用。



