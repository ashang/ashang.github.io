
https://www.freecodecamp.org/chinese/news/how-the-golden-rule-of-react-components-can-help-you-write-better-code/



$ curl https://ifconfig.co/ip                                                                                                                                                                                    



https://lkml.org/lkml/2018/8/2/663

> From	Linus Torvalds <>
> Date	Thu, 2 Aug 2018 10:15:40 -0700
> Subject	Re: [GIT] Networking
> 	
> On Wed, Aug 1, 2018 at 9:37 PM David Miller <davem@davemloft.net> wrote:
> >
> > Fixes keep trickling in:
> 
> Pulled.
> 
> Btw, on an unrelated issue: I see that Jason actually made the pull
> request to have wireguard included in the kernel.
> 
> Can I just once again state my love for it and hope it gets merged
> soon? Maybe the code isn't perfect, but I've skimmed it, and compared
> to the horrors that are OpenVPN and IPSec, it's a work of art.
> 
>               Linus




WireGuard supports UDP, while OpenVPN supports both UDP and TCP. TCP offers more features like error checking and delivery reliability. On the flip side, the added complexity can sometimes make TCP slower. OpenVPN’s support for TCP has one advantage, though. 

When OpenVPN employs TCP, it uses port 443, the same port used by HTTPS, the protocol used by most websites. For this reason, most firewall deployments allow TCP 443. So, your OpenVPN connection should slip through most firewalls unless you’re dealing with an NGFW that does deep packet inspection.

## Remote Access WireGuard VPN

A remote access VPN setup consists of one or more remote devices and a device that acts as a VPN gateway on your network. In WireGuard jargon, this setup is also called Peer-to-Site. Peer(s) refers to the remote device(s), and site refers to your network. You usually use peer-to-site to provide users with secure remote access to your internal network.



https://techgenix.com/what-is-ipsec-internet-protocol-security/


https://techgenix.com/5-best-vpn-protocols/


http://10.10.50.50/-/snippets/171



IPsec (Internet Protocol Security) is a long-standing and widely adopted protocol suite used for securing network communication at the IP layer. It provides encryption, authentication, and integrity protection for IP packets. IPsec operates at the network layer of the OSI model and can be implemented using various encryption algorithms and key exchange protocols, such as IKE (Internet Key Exchange). IPsec is typically used for creating virtual private networks (VPNs) and securing traffic between networks or remote access connections.


# IPsec and WireGuard together

While IPsec and WireGuard are distinct protocols, they can coexist and even work together to provide secure communication. In fact, WireGuard can be encapsulated within an IPsec tunnel, allowing the benefits of both protocols to be leveraged. This approach is sometimes referred to as "WireGuard inside IPsec." By encapsulating WireGuard traffic within an IPsec tunnel, you can take advantage of IPsec's robustness and compatibility while benefiting from WireGuard's simplicity and efficiency.

This coexistence allows organizations to maintain their existing IPsec infrastructure while gradually adopting WireGuard for specific use cases or migrating to it entirely. However, it's worth noting that the specific implementation details and compatibility may vary depending on the network devices, operating systems, and VPN software being used. Free Research Preview. ChatGPT may produce inaccurate information about people, places, or facts. ChatGPT May 24 Version

IPsec within WireGuard: It is possible to encapsulate IPsec traffic within a WireGuard tunnel. This means that you can establish a WireGuard connection between two devices and then use IPsec to secure the traffic within that tunnel. This approach allows you to leverage the performance benefits of WireGuard while still benefiting from the robust security features of IPsec.

IPsec and WireGuard on separate tunnels: It is also possible to have separate tunnels—one for IPsec and another for WireGuard—between two devices. This could be useful if you have different types of traffic or specific network requirements that are better suited for either IPsec or WireGuard.
