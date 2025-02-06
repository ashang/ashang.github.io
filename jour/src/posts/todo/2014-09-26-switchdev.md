
Documentation/networking/switchdev.txt


An Ethernet switch forwards Ethernet frames. It uses a forwarding database (FDB) to decide to which port(s) a frame has to be sent, based on the MAC address. There are timers to make sure the FDB stays up to date. Then came VLANs to isolate virtual networks from each other, and to assign priorities.

The kernel has been able to emulate a switch for a long time with a bridge. But everything is done by the CPU, so it’s not very efficient. Hardware switches have specialised memory for fast FDB lookup and high-bandwidth forwarding paths.


OpenWRT started to be able to configure the switch chips on commercial routers. Basically the OS configures the FDB in the switch – the frames never end up on the CPU. The vendor software isn’t usable because it’s hacky (nothing standardized, custom userspace programs). For different platforms, wildly different things have to be done. swconfig adds an abstraction layer (mostly in kernel, with a bit of userspace tooling). However, it was never upstreamed – when it was attempted, the competing DSA feature was being upstreamed as well.

DSA is based on Marvell chips but it’s pretty generic. DSA exposes each Ethernet port as an actual NIC. When ports are configured in a bridge, the kernel will configure the switching in hardware instead of using the software bridge. So the existing brctl etc. just work. The problem with it is that it is limited to MDIO only, other buses were not possible.

switchdev is a proper kernel subsystem that can be used on any bus, e.g. it can be created for a PCIe device. It is more generic than DSA – DSA was reconverted into a switchdev driver. DSA is now more or less the MDIO part of switchdev.

switchdev implements the FDB support, multicast routing, VLAN configuration.

DSA was for a long time the only switchdev device. Recently the Mellanox Switch X-2 was added (6.4Tbps total 32×32 100Gbps switch).

The interface can be found in include/linux/switchdev.h





In the switchdev approach, a standard Linux uses a specific driver model to integrate networking hardware into the standard Linux server environment. This driver then allows the Linux kernel itself to expose the hardware accelerated networking ports to be exposed as standard Linux interfaces. In such a design, ifconfig -a would show all the ethernet interfaces on the device , like eth30 or eth45. You would use the linux brctl (bridgecontrol) command to create switching configurations, ifconfig to add IP addresses to interfaces, route add to add routes, and so on. For the ASIC based ports, the forwarding rules will be pushed into the hardware and happen in line rate.





//

Switchdev is the name of the Linux kernel project that supports switch ASIC drivers in the Linux kernel. The in-kernel API to support hardware offload to switch ASIC drivers started with the name switchdev but soon it became apparent that many existing in-kernel networking APIs could be used. Though the project goes by the name switchdev, the effort to support switchdev is not limited to the switchdev API’s or hardware offload. Over the years, like many other subsystems in the Linux kernel, switchdev efforts are being leveraged in other use cases and hardware and vice versa. Switchdev evolution has also seeing the unification of in-kernel API across all networking hardware. Note that we are all still talking about in-kernel API for switch ASIC drivers and hardware: The user, control plane API remains the same Linux networking API that is uniform across all systems deploying/using Linux networking.





## Links

- https://blog.mellanox.com/2018/12/mellanox-spectrum-linux-switch-powered-by-switchdev/

