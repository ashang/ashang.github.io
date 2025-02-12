most modern software applications are multi-container

Another issue with containers is that they are ephemeral in nature, hence you shouldn’t have any strict dependencies on particular containers. Even when containers get individual IP addresses and ports, that isn’t much help when an individual container goes offline. With Kontena, you launch services instead of containers. Kontena will then manage and scale the individual containers that are part of a service.


## Kontena Grid

The grid is the outermost container of the Kontena system. It provides an overlay network using Weave and OpenVPN to allow inter-service communications across hosts. Out of the box — at least at the time of the release of Kontena, as Docker is currently working on a networking solution — Docker didn’t provide means for cross-host communication. Containers on the same machine can communicate with each other using Docker links, but having containers communicate across hosts has been far more ad-hoc, hence the need for an overlay tool such as Weave. The VPN component is useful as well as it allows you to connect directly to the Kontena master to do administration. Put simply, the grid allows you to treat all your nodes as if the they are on the same local network.
