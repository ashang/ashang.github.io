

```sh
$ proxychains git fetch upstream
ProxyChains-3.1 (http://proxychains.sf.net)
/usr/lib/proxychains3/proxyresolv: 16: dig: not found
fatal: unable to access 'https://github.com/AntennaPod/AntennaPod/': Could not resolve host: github.com

$ sudo apt install bind9-dnsutils
```

* Allows TCP and DNS tunneling through proxies.
* Supports HTTP, SOCKS4 and SOCKS5 proxy servers.
* Different proxy types can be mixed in the same chain.
* Proxy chain: user-defined list of proxies chained together.

* Run any program through proxy server.
* Access the Internet from behind a restrictive firewall.
* Hide your IP
* Run SSH, telnet, wget, ftp, apt, vnc, nmap through proxy servers.
* Access Intranets (192.168.*.*/10.*.*.*) from outside through reverse proxy.



proxychains - a tool that forces any TCP connection made by any given application
to follow through proxy like TOR or any other SOCKS4, SOCKS5 or HTTP(S) proxy.
Supported auth-types: "user/pass" for SOCKS4/5, "basic" for HTTP.

proxyresolv - DNS resolving. Used to resolve host names via proxy or TOR.

 Indeed you can even access your home LAN from outside via reverse proxy if you set it.


 Use TOR network with SSH and friends.


Some cool features:

* Different chaining options supported
 random order from the list ( user defined length of chain ).
 exact order (as they appear in the list )
 dynamic order (smart exclude dead proxies from chain)

* You can use it with any application, even network scanners
 oh yes - you can make portscan via proxy (or chained proxies)
 for example with Nmap scanner (www.insecire.org/nmap).
 proxychains nmap -sT -PO -p 80 -iR (find some webservers through proxy)

* Really long chains supported with tunable timeouts.



