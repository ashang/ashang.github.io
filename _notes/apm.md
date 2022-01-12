
Elastic APM ships with support for Java, Go, Node.js, Python, Ruby, .NET, and Real User Monitoring (JavaScript) for multiple-page and single-page applications — with more languages on the way. Plus, with support for open standards like Jaeger and OpenTelemetry, sending data from existing instrumented apps to Elastic APM is a breeze.

Deploy Metricbeat on all your Linux, Windows, and Mac hosts, connect it to Elasticsearch and voila: you get system-level CPU usage, memory, file system, disk IO, and network IO statistics, as well as top-like statistics for every process running on your systems. From CPU to memory, Redis to NGINX, and much more, Metricbeat is a lightweight way to send system and service statistics.

Metricbeat comes with internal modules that collect metrics from services like Apache, Jolokia, NGINX, MongoDB, MySQL, PostgreSQL, Prometheus, and more. Installation is easy, requiring absolutely zero dependencies. Just enable the modules you want in the configuration file.


Filebeat comes with internal modules (Apache, Cisco ASA, Microsoft Azure, NGINX, MySQL, and more) that simplify the collection, parsing, and visualization of common log formats down to a single command. They achieve this by combining automatic default paths based on your operating system, Elasticsearch Ingest Node pipeline definitions, and Kibana dashboards. Plus, a few Filebeat modules ship with pre-configured machine learning jobs.


# The Blockbridge Container Storage Interface (CSI) driver delivers persistent, secure, multi-tenant, cluster-accessible storage for Kubernetes. Deploy the Blockbridge CSI driver in your Kubernetes cluster using standard kubectl commands.


Supported K8s Environments

    Rancher 2.4+
        Mirantis Kubernetes Engine 3.1+ (formerly Docker EE)


https://www.blockridge.com/


# Traefik is a modern HTTP reverse proxy and load balancer that makes deploying microservices easy.

Traefik integrates with your existing infrastructure components (Docker, Swarm mode, Kubernetes, Marathon, Consul, Etcd, Rancher, Amazon ECS, ...) and configures itself automatically and dynamically.

Pointing Traefik at your orchestrator should be the only configuration step you need.

Traefik v2 - Example usage

Enable docker provider and web UI:

## traefik.yml

# Docker configuration backend
providers:
  docker:
    defaultRule: "Host(`{{ trimPrefix `/` .Name }}.docker.localhost`)"

# API and dashboard configuration
api:
  insecure: true

Start Traefik:

docker run -d -p 8080:8080 -p 80:80 \
-v $PWD/traefik.yml:/etc/traefik/traefik.yml \
-v /var/run/docker.sock:/var/run/docker.sock \
traefik:v2.5

Start a backend server, named test:

docker run -d --name test traefik/whoami

And finally, you can access to your whoami server throught Traefik, on the domain name test.docker.localhost:

# $ curl --header 'Host:test.docker.localhost' 'http://localhost:80/'
$ curl test.docker.localhost
Hostname: 390a880bdfab
IP: 127.0.0.1
IP: 172.17.0.3
GET / HTTP/1.1
Host: test.docker.localhost
User-Agent: curl/7.65.3
Accept: */*
Accept-Encoding: gzip
X-Forwarded-For: 172.17.0.1
X-Forwarded-Host: test.docker.localhost
X-Forwarded-Port: 80
X-Forwarded-Proto: http
X-Forwarded-Server: 7e073cb54211
X-Real-Ip: 172.17.0.1

The web UI http://localhost:8080 will give you an overview of the routers, services, and middlewares.



#



53% of users abandon a website that takes more than 3 seconds to load.


Blackfire is a full continuous observability solution (monitoring, profiling, and automated performance testing tool). It can be used on Integration, Staging, and Production environments. Blackfire supports PHP and Python.

Welcome to Blackfire, your Code Performance Observability Solution.

Blackfire helps to improve web applications’ performance at each step of its
lifecycle: from development to test, staging and production.



Blackfire lifecycle

It offers a unique blend of monitoring, often called APM, and profiling
features.

Across all of your sites and testing pipelines, get actionable reports and
insights, which help you fix issues.

Blackfire supports PHP and Python monitoring and profiling. It also supports
Go profiling.
Consul




# Consul is a datacenter runtime that provides service discovery, configuration, and orchestration.

Consul is a distributed, highly-available, and multi-datacenter aware tool for
service discovery, configuration, and orchestration. Consul enables rapid
deployment, configuration, and maintenance of service-oriented architectures
at massive scale. For more information, please see:



Consul and Docker

Consul has several moving parts so we'll start with a brief introduction to Consul's architecture and then detail how Consul interacts with Docker. Please see the Consul Architecture guide for more detail on all these concepts.

Each host in a Consul cluster runs the Consul agent, a long running daemon that can be started in client or server mode. Each cluster has at least 1 agent in server mode, and usually 3 or 5 for high availability. The server agents participate in a consensus protocol, maintain a centralized view of the cluster's state, and respond to queries from other agents in the cluster. The rest of the agents in client mode participate in a gossip protocol to discover other agents and check them for failures, and they forward queries about the cluster to the server agents.

Applications running on a given host communicate only with their local Consul agent, using its HTTP APIs or DNS interface. Services on the host are also registered with the local Consul agent, which syncs the information with the Consul servers. Doing the most basic DNS-based service discovery using Consul, an application queries for foo.service.consul and gets a randomly shuffled subset of all the hosts providing service "foo". This allows applications to locate services and balance the load without any intermediate proxies. Several HTTP APIs are also available for applications doing a deeper integration with Consul's service discovery capabilities, as well as its other features such as the key/value store.

These concepts also apply when running Consul in Docker.
You'll run a single Consul agent container on each host, running alongside the Docker daemon. You'll also need to configure some of the agents as servers (at least 3 for a basic HA setup). Consul should always be run with --net=host in Docker because Consul's consensus and gossip protocols are sensitive to delays and packet loss, so the extra layers involved with other networking types are usually undesirable and unnecessary. We will talk more about this below.

We don't cover Consul's multi-datacenter capability here, but as long as --net=host is used, there should be no special considerations for Docker.
Using the Container

We chose Alpine as a lightweight base with a reasonably small surface area for security concerns, but with enough functionality for development, interactive debugging, and useful health, watch, and exec scripts running under Consul in the container. As of Consul 0.7, the image also includes curl since it is so commonly used for health checks.

Consul always runs under dumb-init, which handles reaping zombie processes and forwards signals on to all processes running in the container. We also use gosu to run Consul as a non-root "consul" user for better security. These binaries are all built by HashiCorp and signed with our GPG key, so you can verify the signed package used to build a given base image.

Running the Consul container with no arguments will give you a Consul server in development mode. The provided entry point script will also look for Consul subcommands and run consul as the correct user and with that subcommand. For example, you can execute docker run consul members and it will run the consul members command inside the container. The entry point also adds some special configuration options as detailed in the sections below when running the agent subcommand. Any other command gets exec-ed inside the container under dumb-init.

The container exposes VOLUME /consul/data, which is a path where Consul will place its persisted state. This isn't used in any way when running in development mode. For client agents, this stores some information about the cluster and the client's health checks in case the container is restarted. For server agents, this stores the client information plus snapshots and data related to the consensus algorithm and other state like Consul's key/value store and catalog. For servers it is highly desirable to keep this volume's data around when restarting containers to recover from outage scenarios. If this is bind mounted then ownership will be changed to the consul user when the container starts.

The container has a Consul configuration directory set up at /consul/config and the agent will load any configuration files placed here by binding a volume or by composing a new image and adding files. Alternatively, configuration can be added by passing the configuration JSON via environment variable CONSUL_LOCAL_CONFIG. If this is bind mounted then ownership will be changed to the consul user when the container starts.

Since Consul is almost always run with --net=host in Docker, some care is required when configuring Consul's IP addresses. Consul has the concept of its cluster address as well as its client address. The cluster address is the address at which other Consul agents may contact a given agent. The client address is the address where other processes on the host contact Consul in order to make HTTP or DNS requests.

You will to tell Consul what its cluster address is when starting so that it binds to the correct interface and advertises a workable interface to the rest of the Consul agents. You'll see this in the examples below as the -bind=<external ip> argument to Consul.

The entry point also includes a small utility to look up a client or bind address by interface name. To use this, set the CONSUL_CLIENT_INTERFACE and/or CONSUL_BIND_INTERFACE environment variables to the name of the interface you'd like Consul to use and a -client=<interface ip> and/or -bind=<interface ip> argument will be computed and passed to Consul at startup.
Running Consul for Development

$ docker run -d --name=dev-consul -e CONSUL_BIND_INTERFACE=eth0 consul

This runs a completely in-memory Consul server agent with default bridge networking and no services exposed on the host, which is useful for development but should not be used in production. For example, if that server is running at internal address 172.17.0.2, you can run a three node cluster for development by starting up two more instances and telling them to join the first node.

$ docker run -d -e CONSUL_BIND_INTERFACE=eth0 consul agent -dev -join=172.17.0.2
... server 2 starts
$ docker run -d -e CONSUL_BIND_INTERFACE=eth0 consul agent -dev -join=172.17.0.2
... server 3 starts

Then we can query for all the members in the cluster by running a Consul CLI command in the first container:

$ docker exec -t dev-consul consul members
Node          Address          Status  Type    Build  Protocol  DC
579db72c1ae1  172.17.0.3:8301  alive   server  0.6.3  2         dc1
93fe2309ef19  172.17.0.4:8301  alive   server  0.6.3  2         dc1
c9caabfd4c2a  172.17.0.2:8301  alive   server  0.6.3  2         dc1

Remember that Consul doesn't use the data volume in this mode - once the container stops all of your state will be wiped out, so please don't use this mode for production. Running completely on the bridge network with the development server is useful for testing multiple instances of Consul on a single machine, which is normally difficult to do because of port conflicts.

Development mode also starts a version of Consul's web UI on port 8500. This can be added to the other Consul configurations by supplying the -ui option to Consul on the command line. The web assets are bundled inside the Consul binary in the container.
Running Consul Agent in Client Mode

$  docker run -d --net=host -e 'CONSUL_LOCAL_CONFIG={"leave_on_terminate": true}' consul agent -bind=<external ip> -retry-join=<root agent ip>
==> Starting Consul agent...
==> Starting Consul agent RPC...
==> Consul agent running!
         Node name: 'linode'
        Datacenter: 'dc1'
            Server: false (bootstrap: false)
       Client Addr: 127.0.0.1 (HTTP: 8500, HTTPS: -1, DNS: 8600, RPC: 8400)
      Cluster Addr: <external ip> (LAN: 8301, WAN: 8302)
    Gossip encrypt: false, RPC-TLS: false, TLS-Incoming: false
             Atlas: <disabled>
...

This runs a Consul client agent sharing the host's network and advertising the external IP address to the rest of the cluster. Note that the agent defaults to binding its client interfaces to 127.0.0.1, which is the host's loopback interface. This would be a good configuration to use if other containers on the host also use --net=host, and it also exposes the agent to processes running directly on the host outside a container, such as HashiCorp's Nomad.

The -retry-join parameter specifies the external IP of one other agent in the cluster to use to join at startup. There are several ways to control how an agent joins the cluster, see the agent configuration guide for more details on the -join, -retry-join, and -atlas-join options.

Note also we've set leave_on_terminate using the CONSUL_LOCAL_CONFIG environment variable. This is recommended for clients to and will be defaulted to true in Consul 0.7 and later, so this will no longer be necessary.

At startup, the agent will read config JSON files from /consul/config. Data will be persisted in the /consul/data volume.

Here are some example queries on a host with an external IP of 66.175.220.234:

$ curl http://localhost:8500/v1/health/service/consul?pretty
[
    {
        "Node": {
            "Node": "linode",
            "Address": "66.175.220.234",
...

$ dig @localhost -p 8600 consul.service.consul
; <<>> DiG 9.9.5-3ubuntu0.7-Ubuntu <<>> @localhost -p 8600 consul.service.consul
; (2 servers found)
;; global options: +cmd
;; Got answer:
;; ->>HEADER<<- opcode: QUERY, status: NOERROR, id: 61616
;; flags: qr aa rd; QUERY: 1, ANSWER: 1, AUTHORITY: 0, ADDITIONAL: 0
;; WARNING: recursion requested but not available

;; QUESTION SECTION:
;consul.service.consul.         IN      A

;; ANSWER SECTION:
consul.service.consul.  0       IN      A       66.175.220.234
...

If you want to expose the Consul interfaces to other containers via a different network, such as the bridge network, use the -client option for Consul:

docker run -d --net=host consul agent -bind=<external ip> -client=<bridge ip> -retry-join=<root agent ip>
==> Starting Consul agent...
==> Starting Consul agent RPC...
==> Consul agent running!
         Node name: 'linode'
        Datacenter: 'dc1'
            Server: false (bootstrap: false)
       Client Addr: <bridge ip> (HTTP: 8500, HTTPS: -1, DNS: 8600, RPC: 8400)
      Cluster Addr: <external ip> (LAN: 8301, WAN: 8302)
    Gossip encrypt: false, RPC-TLS: false, TLS-Incoming: false
             Atlas: <disabled>
...

With this configuration, Consul's client interfaces will be bound to the bridge IP and available to other containers on that network, but not on the host network. Note that we still keep the cluster address out on the host network for performance. Consul will also accept the -client=0.0.0.0 option to bind to all interfaces.
Running Consul Agent in Server Mode

$ docker run -d --net=host -e 'CONSUL_LOCAL_CONFIG={"skip_leave_on_interrupt": true}' consul agent -server -bind=<external ip> -retry-join=<root agent ip> -bootstrap-expect=<number of server agents>

This runs a Consul server agent sharing the host's network. All of the network considerations and behavior we covered above for the client agent also apply to the server agent. A single server on its own won't be able to form a quorum and will be waiting for other servers to join.

Just like the client agent, the -retry-join parameter specifies the external IP of one other agent in the cluster to use to join at startup. There are several ways to control how an agent joins the cluster, see the agent configuration guide for more details on the -join, -retry-join, and -atlas-join options. The server agent also consumes a -bootstrap-expect option that specifies how many server agents to watch for before bootstrapping the cluster for the first time. This provides an easy way to get an orderly startup with a new cluster. See the agent configuration guide for more details on the -bootstrap and -bootstrap-expect options.

Note also we've set skip_leave_on_interrupt using the CONSUL_LOCAL_CONFIG environment variable. This is recommended for servers and will be defaulted to true in Consul 0.7 and later, so this will no longer be necessary.

At startup, the agent will read config JSON files from /consul/config. Data will be persisted in the /consul/data volume.

Once the cluster is bootstrapped and quorum is achieved, you must use care to keep the minimum number of servers operating in order to avoid an outage state for the cluster. The deployment table in the consensus guide outlines the number of servers required for different configurations. There's also an adding/removing servers guide that describes that process, which is relevant to Docker configurations as well. The outage recovery guide has steps to perform if servers are permanently lost. In general it's best to restart or replace servers one at a time, making sure servers are healthy before proceeding to the next server.
Exposing Consul's DNS Server on Port 53

By default, Consul's DNS server is exposed on port 8600. Because this is cumbersome to configure with facilities like resolv.conf, you may want to expose DNS on port 53. Consul 0.7 and later supports this by setting an environment variable that runs setcap on the Consul binary, allowing it to bind to privileged ports. Note that not all Docker storage backends support this feature (notably AUFS).

Here's an example:

$ docker run -d --net=host -e 'CONSUL_ALLOW_PRIVILEGED_PORTS=' consul -dns-port=53 -recursor=8.8.8.8

This example also includes a recursor configuration that uses Google's DNS servers for non-Consul lookups. You may want to adjust this based on your particular DNS configuration. If you are binding Consul's client interfaces to the host's loopback address, then you should be able to configure your host's resolv.conf to route DNS requests to Consul by including "127.0.0.1" as the primary DNS server. This would expose Consul's DNS to all applications running on the host, but due to Docker's built-in DNS server, you can't point to this directly from inside your containers; Docker will issue an error message if you attempt to do this. You must configure Consul to listen on a non-localhost address that is reachable from within other containers.

Once you bind Consul's client interfaces to the bridge or other network, you can use the --dns option in your other containers in order for them to use Consul's DNS server, mapped to port 53. Here's an example:

$ docker run -d --net=host -e 'CONSUL_ALLOW_PRIVILEGED_PORTS=' consul agent -dns-port=53 -recursor=8.8.8.8 -bind=<bridge ip>

Now start another container and point it at Consul's DNS, using the bridge address of the host:

$ docker run -i --dns=<bridge ip> -t ubuntu sh -c "apt-get update && apt-get install -y dnsutils && dig consul.service.consul"
...
;; ANSWER SECTION:
consul.service.consul.  0       IN      A       66.175.220.234
...

In the example above, adding the bridge address to the host's /etc/resolv.conf file should expose it to all containers without running with the --dns option.
Service Discovery with Containers

There are several approaches you can use to register services running in containers with Consul. For manual configuration, your containers can use the local agent's APIs to register and deregister themselves, see the Agent API for more details. Another strategy is to create a derived Consul container for each host type which includes JSON config files for Consul to parse at startup, see Services for more information. Both of these approaches are fairly cumbersome, and the configured services may fall out of sync if containers die or additional containers are started.

If you run your containers under HashiCorp's Nomad scheduler, it has first class support for Consul. The Nomad agent runs on each host alongside the Consul agent. When jobs are scheduled on a given host, the Nomad agent automatically takes care of syncing the Consul agent with the service information. This is very easy to manage, and even services on hosts running outside of Docker containers can be managed by Nomad and registered with Consul. You can find out more about running Docker under Nomad in the Docker Driver guide.

Other open source options include Registrator from Glider Labs and ContainerPilot from Joyent. Registrator works by running a Registrator instance on each host, alongside the Consul agent. Registrator monitors the Docker daemon for container stop and start events, and handles service registration with Consul using the container names and exposed ports as the service information. ContainerPilot manages service registration using tooling running inside the container to register services with Consul on start, manage a Consul TTL health check while running, and deregister services when the container stops.




https://engineeringblog.yelp.com/2016/01/dumb-init-an-init-for-docker.html



# https://github.com/Yelp/dumb-init
 A minimal init system for Linux containers


# Arista Container Tracer is a software extension for Arista EOS that gives
administrators visibility into the containerized workloads attached to the
network. This tool combines the extensibility of the Arista EOS software
platform with container monitoring to make visibility and troubleshooting of
containerized workloads possible in a Docker environment.



#  $ docker volume create -d simplivity -o help

$ sudo docker volume create -d simplivity --name <vol_name>



    To set permissions of root directory of a file system:

    $ docker volume create -d simplivity --name <volume-name> -o
    fsMode=<octal-number-specified-in-chmod>

        To set ownership of root directory of a file system:

        $ docker volume create -d simplivity --name <volume-name> -o
        fsOwner=<UserId>:<GroupId>




# PaaSTA is an opinionated platform that uses a few un-opinionated tools. It
requires a non-trivial amount of infrastructure to be in place before it works
completely:

    Docker for code delivery and containment
        Mesos / Kubernetes for code execution and scheduling (runs Docker
        containers)
            Marathon for managing long-running services
                Tron for running things on a timer (nightly batches)
                    SmartStack / Envoy for service registration and discovery
                        Sensu for monitoring/alerting
                            Jenkins (optionally) for continuous deployment





# Wireshark

FROM ubuntu

RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install wireshark -y

CMD ["wireshark"]



run this container inside any docker host and you will be able to view all
traffic between docker containers.

This container can be executed in both local or remote machine.
Running in your own host:

$ docker run -ti --net=host --privileged -v $HOME:/root:ro -e
XAUTHORITY=/root/.Xauthority -e DISPLAY=$DISPLAY manell/wireshark
Running in a remote host:

First, ssh into the remote machine.

$ ssh -X user@host

Then, just run the same command.

$ docker run -ti --net=host --privileged -v $HOME:/root:ro -e
XAUTHORITY=/root/.Xauthority -e DISPLAY=$DISPLAY manell/wireshark





# https://minidcos.readthedocs.io/en/latest/dcos-docker-cli.html



https://minidcos.readthedocs.io/en/latest/dcos-vagrant-cli.html


https://docs.d2iq.com/mesosphere/dcos/2.2/tutorials/dcos-101/


#
What is Mesos? A distributed systems kernel

Mesos is built using the same principles as the Linux kernel, only at a
different level of abstraction. The Mesos
kernel runs on every machine and provides applications (e.g., Hadoop, Spark,
Kafka, Elasticsearch) with API’s for
resource management and scheduling across entire datacenter and cloud
environments.




# https://docs.docker.com/get-started/

to:

    Build and run an image as a container
        Share images using Docker Hub
            Deploy Docker applications using multiple containers with a
            database
                Running applications using Docker Compose



docker run -d -p 80:80 docker/getting-started

https://docs.docker.com/develop/develop-images/dockerfile_best-practices/




Docker builds images automatically by reading the instructions from a
Dockerfile -- a text file that contains all commands, in order, needed to
build a given image. A Dockerfile adheres to a specific format and set of
instructions which you can find at Dockerfile reference.

A Docker image consists of read-only layers each of which represents a
Dockerfile instruction. The layers are stacked and each one is a delta of the
changes from the previous layer. Consider this Dockerfile:

# syntax=docker/dockerfile:1
FROM ubuntu:18.04
COPY . /app
RUN make /app
CMD python /app/app.py

Each instruction creates one layer:

    FROM creates a layer from the ubuntu:18.04 Docker image.
        COPY adds files from your Docker client’s current directory.
            RUN builds your application with make.
                CMD specifies what command to run within the container.

                When you run an image and generate a container, you add a new
                writable layer (the “container layer”) on top of the
                underlying layers. All changes made to the running container,
                such as writing new files, modifying existing files, and
                deleting files, are written to this writable container layer.


https://docs.docker.com/storage/storagedriver/

https://docs.docker.com/develop/dev-best-practices/


https://docs.docker.com/develop/develop-images/build_enhancements/

https://docs.docker.com/develop/develop-images/image_management/


apt-cache madison docker-ce

 sudo apt-get install docker-ce=<VERSION_STRING>
 docker-ce-cli=<VERSION_STRING> containerd.io

  curl -fsSL https://get.docker.com -o get-docker.sh

   DRY_RUN=1 sh ./get-docker.sh


 sudo apt-get purge docker-ce docker-ce-cli containerd.io





    Create the docker group.

     sudo groupadd docker

     Add your user to the docker group.

      sudo usermod -aG docker $USER



 verify that Docker containers can resolve an internal hostname by pinging it.

  docker run --rm -it alpine ping -c4 <my_internal_host>


# Docker limit



Edit the /etc/default/grub file. Add or edit the GRUB_CMDLINE_LINUX line to
add the following two key-value pairs:

GRUB_CMDLINE_LINUX="cgroup_enable=memory swapaccount=1"

Save and close the file.

Update GRUB.

 sudo update-grub



https://docs.docker.com/get-started/02_our_app/


https://medium.com/airbnb-engineering/smartstack-service-discovery-in-the-cloud-4b8a080de619#.m0x2ks9ja

https://sensuapp.org/



# Traefik is an open-source Edge Router that makes publishing your services a
fun and easy experience. It receives requests on behalf of your system and
finds out which components are responsible for handling them.

What sets Traefik apart, besides its many features, is that it automatically
discovers the right configuration for your services. The magic happens when
Traefik inspects your infrastructure, where it finds relevant information and
discovers which service serves which request.

Traefik is natively compliant with every major cluster technology, such as
Kubernetes, Docker, Docker Swarm, AWS, Mesos, Marathon, and the list goes on;
and can handle many at the same time. (It even works for legacy software
running on bare metal.)

With Traefik, there is no need to maintain and synchronize a separate
configuration file: everything happens automatically, in real time (no
restarts, no connection interruptions). With Traefik, you spend time
developing and deploying new features to your system, not on configuring and
maintaining its working state.





#
BUILD
DOCKER RUN

docker run -d \
--name wireshark \
--network host \
--cap-add=NET_ADMIN \
-e DISPLAY \
-e XAUTHORITY='/xauthority' \
-v ${HOME}:/home/wireshark \
-v /tmp/.X11-unix/:/tmp/.X11-unix/ \
-v ${XAUTHORITY}:/xauthority:ro \
alexandreoda/wireshark

DOCKER COMPOSE

version: "2.0"

services:
  wireshark:
    container_name: wireshark
    image: alexandreoda/wireshark
    restart: "no"
    network_mode: host
    privileged: false
    cap_add:
      - NET_ADMIN
    environment:
      - DISPLAY
      - XAUTHORITY='/xauthority'
    volumes:
      - "${HOME}:/home/wireshark"
      - "/tmp/.X11-unix/:/tmp/.X11-unix/"
      - "${XAUTHORITY}:/xauthority:ro"
      - "/etc/localtime:/etc/localtime:ro"




https://gitlab.com/oda-alexandre/wireshark/

https://gitlab.com/oda-alexandre/wireshark/-/pipelines



https://traefik.io/


# HTTPD


Create a Dockerfile in your project

FROM httpd:2.4
COPY ./public-html/ /usr/local/apache2/htdocs/

Then, run the commands to build and run the Docker image:

$ docker build -t my-apache2 .
$ docker run -dit --name my-running-app -p 8080:80 my-apache2

Visit http://localhost:8080 and you will see It works!
Without a Dockerfile

If you don't want to include a Dockerfile in your project, it is sufficient to do the following:

$ docker run -dit --name my-apache-app -p 8080:80 -v "$PWD":/usr/local/apache2/htdocs/ httpd:2.4

Configuration

To customize the configuration of the httpd server, first obtain the upstream default configuration from the container:

$ docker run --rm httpd:2.4 cat /usr/local/apache2/conf/httpd.conf > my-httpd.conf

You can then COPY your custom configuration in as /usr/local/apache2/conf/httpd.conf:

FROM httpd:2.4
COPY ./my-httpd.conf /usr/local/apache2/conf/httpd.conf

SSL/HTTPS

If you want to run your web traffic over SSL, the simplest setup is to COPY or mount (-v) your server.crt and server.key into /usr/local/apache2/conf/ and then customize the /usr/local/apache2/conf/httpd.conf by removing the comment symbol from the following lines:

...
#LoadModule socache_shmcb_module modules/mod_socache_shmcb.so
...
#LoadModule ssl_module modules/mod_ssl.so
...
#Include conf/extra/httpd-ssl.conf
...

The conf/extra/httpd-ssl.conf configuration file will use the certificate files previously added and tell the daemon to also listen on port 443. Be sure to also add something like -p 443:443 to your docker run to forward the https port.

This could be accomplished with a sed line similar to the following:

RUN sed -i \
        -e 's/^#\(Include .*httpd-ssl.conf\)/\1/' \
        -e 's/^#\(LoadModule .*mod_ssl.so\)/\1/' \
        -e 's/^#\(LoadModule .*mod_socache_shmcb.so\)/\1/' \
        conf/httpd.conf




# Alpine Linux is a Linux distribution built around musl libc and BusyBox. The image is only 5 MB in size and has access to a package repository that is much more complete than other BusyBox based images. This makes Alpine Linux a great image base for utilities and even production applications. Read more about Alpine Linux here and you can see how their mantra fits in right at home with Docker images.

logo
How to use this image
Usage

Use like you would any other base image:

FROM alpine:3.14
RUN apk add --no-cache mysql-client
ENTRYPOINT ["mysql"]

This example has a virtual image size of only 36.8MB. Compare that to our good friend Ubuntu:

FROM ubuntu:20.04
RUN apt-get update \
    && apt-get install -y --no-install-recommends mysql-client \
    && rm -rf /var/lib/apt/lists/*
ENTRYPOINT ["mysql"]

This yields us a virtual image size of about 145MB image.




https://www.etalabs.net/compare_libcs.html


https://hub.docker.com/_/nextcloud

https://hub.docker.com/_/haproxy


# https://hub.docker.com/r/linuxserver/wireshark


LSIO CI

Wireshark is the world’s foremost and widely-used network protocol analyzer. It lets you see what’s happening on your network at a microscopic level and is the de facto (and often de jure) standard across many commercial and non-profit enterprises, government agencies, and educational institutions. Wireshark development thrives thanks to the volunteer contributions of networking experts around the globe and is the continuation of a project started by Gerald Combs in 1998.

wireshark
Supported Architectures

Our images support multiple architectures such as x86-64, arm64 and armhf. We utilise the docker manifest for multi-platform awareness. More information is available from docker here and our announcement here.

Simply pulling lscr.io/linuxserver/wireshark should retrieve the correct image for your arch, but you can also pull specific arch images via tags.





https://hub.docker.com/r/corfr/tcpdump



docker run --name teamspeak -p 30033:30033 -p 9987:9987/udp -p 10011:10011 dpilichiewicz/teamspeak


https://blog.cloudflare.com/how-we-use-hashicorp-nomad/

https://nomadproject.io/downloads/



#

-d --net=host -v /opt/bro/logs:/opt/bro/logs -v /opt/bro/spool:/opt/bro/spool




https://bitwarden.com/help/article/install-on-premise/

https://bitwarden.com/help/hosting/



https://github.com/hashicorp/nomad/blob/main/website/content/docs/nomad-vs-kubernetes/




 docker run -d -p 80:80 docker/getting-started


https://medium.com/@saschagrunert/demystifying-containers-part-i-kernel-space-2c53d6979504



youtube: https://docs.docker.com/get-started/






# CPU


Retrieve CPU Affinity of Running Process

If a process is already running and if you want to retrieve the CPU affinity
properties of the process, use taskset in the following format.

# taskset -p <pid>

If for example, to check the CPU affinity of a process with PID 5504, use the
following syntax.

# taskset -p 5504
pid 5504's current affinity mask: f

The CPU affinity is represented as a bitmask, with the lowest order bit
corresponding to the first logical CPU and the highest order bit corresponding
to the last logical CPU. In the example above, the CPU affinity is printed out
in hexadecimal as 0x0f. In binary, it will be ‘00001111’. This means that
the process can run in 4 different CPU cores (from 0 to 3).

If you find the bitmask confusing, you can get taskset to print a numerical
list of processors instead of the bitmask by using the following syntax.

# taskset -cp 5504
pid 5504's current affinity mask: 0-3

Set CPU Affinity of Running Process

To assign the CPU cores for a process, use one of the following formats. The
first is using bitmask, the second is using processor list.

# taskset -p <bitmask> <pid>

# taskset -cp <cpu-list> <pid>

To assign PID 5504 to CPU cores 0 and 3, using bitmask, use the following
syntax.

# taskset -p 0x09 5504
pid 5504's current affinity mask: f
pid 5504's new affinity mask: 9

To specify processor list, use the following syntax.

# taskset -cp 0,3 5504
pid 5504's current affinity mask: 0-3
pid 5504's new affinity mask: 0,3

Launch a Process on Specific CPU Cores

To launch a process and “bond” the process to a specific set of CPU cores,
use one of the two formats below.

# taskset -p <bitmask> /path/to/program

# taskset -cp <cpu-list> /path/to/program

Dedicate / Restrict CPU Core to Process

Even if you assign CPU cores to a process using taskset, it does not mean the
assigned CPU cores will not be used to run other processes. The Linux
scheduler will use all CPU cores for scheduling tasks. To prevent the Linux
scheduler from scheduling any user-space threads on a CPU core, the
“isolcpus” kernel boot parameter has to be used to isolate the CPU core.

Once a CPU core is isolated, the Linux scheduler will not use the CPU core to
run any user-space processes. The isolated CPUs will not participate in load
balancing, and will not have tasks running on them unless explicitly assigned.
You can manually assign processes to be run on the isolated CPU cores using
taskset.

To isolate the 1st and 3rd CPU cores (CPU numbers start from 0) on your
system, add the following to the kernel command line during boot:

isolcpus=1,3

If you are on GRUB2, and if you want to make the entries permanent, modify the
value of GRUB_CMDLINE_LINUX parameter in the /etc/default/grub file.





