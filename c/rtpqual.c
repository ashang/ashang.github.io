/*
 * Simple Multiprotocol Multicast Signal Quality Meter
 *
 * (c) Pittsburgh Supercomputing Center, Matthew B Mathis, 1993.
 * minor modifications by Alan Crosswell, 2004, to add SSM.
 *
 * THIS SOFTWARE IS CURRENTLY UNDER DEVELOPMENT.
 *
 * This has only been tested with nv 3.1.  Vat is not supported....
 * If someone would be kind enough to write getVATseq(...) it would be much
 * appreciated.
 */

/*
Usage: rtpqual [[<source>@]<group> [<port> [<format>]]]

Each output row presents the statistics from one transmitter.

Column one is the seconds part of the system time
	such that loss events can be correlated with other events.
Statistics from the current second are displayed in columns 2-6:
	data packets received,
	(presumed) lost data packets,
	percentage loss, 
	late data (and any non-sequenced control) packets,
	  (Currently only checks for out of sequence, but not excessive delay)
	bytes received (data, late data and control).
The next 5 columns are cumulative totals for this transmitter
	(except k Bytes instead of Bytes).

If there is more than one transmitter, cumulative total statistics are
displayed for each every minute.

BUGS: Delay variance is not instrumented.

Each line appears only when there is input in a new second, therefor it is not
possible to see the last second of a transmission.
*/

#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <netdb.h>


#define MAXB 1500
#define K 1024
#define HEADER_FUDGE 40

#define DEFAULT_GROUP	"224.2.1.1"
#define DEFAULT_PORT	"4444"
#define DEFAULT_FORMAT	"rtp"

#define NOERROR(val,msg) {if (((int)(val)) < 0) {perror(msg);exit(1);}}
#define NOTNULL(val,msg) {if (!(val)) {fprintf(stderr,msg);exit(1);}}

#define DO_SENDERS(x) {if (senders) {x = senders; do {
#define UNTIL_SENDERS(x) x = x->next; } while (x != senders);}}

struct senderstat {
  struct senderstat *next;		/* circular list */
  int flags;
  struct sockaddr_in from;
  char from_name[20];			/* precomputed fromname */
  int seq;				/* low byte of the sequence # */
  int spkts, slost, lpkts, bytes;	/* stats - this second */
  int Tspkts, Tslost, Tlpkts, Tbytes;	/* stats - totals for this sender */
};
struct senderstat *findfrom();
struct senderstat* senders=0;

int Tspkts, Tslost, Tlpkts, Tbytes;	/* stats - grand totals */

unsigned int getRTPseq();		/* Crack nv/RTP */

main(argc, argv)
char *argv[];
{
  unsigned char buff[MAXB];
  struct sockaddr_in from;
  struct senderstat *ss, *s;
  struct timeval now;
  char *source, *name, *form, *p, *port;
  int assumed=0;
  int fd, len, i, fromlen, tick;
  int d, minute, first, sq;
  unsigned int (*getseq)();
  int f1, f2;

  /* XXX "parse" the arguments, and we use the term loosly.... */
  name = (argc>1) ? argv[1]:DEFAULT_GROUP;
  port = (argc>2) ? argv[2]:DEFAULT_PORT;
  form = (argc>3) ? argv[3]:DEFAULT_FORMAT;
  if (argc < 4) {
    printf("Defaulting to: %s %s %s %s\n", argv[0], name, port, form);
  }
  if (p = strchr(name,'@')) {	/* look for SSM source@group */
    source = name;
    name = p;
    ++name;
    *p = '\0';
  } else {
    source = NULL;
  }
  if (!strcmp(form, "rtp"))	/* XXX */
    getseq = getRTPseq;
  else { 
    printf("Currently only rtp is supported\n");
    exit(1);
  }

  fd = (source) ? openSSM(source,name,port) : openMC(name, port);

  gettimeofday(&now, 0);
  tick=now.tv_sec;

  for (;;) {
    fromlen =  sizeof(from);
    NOERROR(len = recvfrom(fd, buff, MAXB, 0, &from, &fromlen),"recvfrom");

    /* display stats if this is a new second. */
    gettimeofday(&now, 0);
    if (tick != now.tv_sec) {
      int cmin = tick/60;
      if (cmin != minute) {
	minute = cmin;
	printf("Report from: %s %s %s %s at %s",
	       argv[0], name, port, form, ctime(&now.tv_sec) );
/*
dd ddd  dd  %dd  dd dddddd |dddddd dddd  %dd dddd ddddddd s*/
	printf("\
T Pkts Loss  %% Late Bytes |  Pkts  Loss  %%  Late     kB Sender\n");
	if (senders && (senders->next != senders)) {
	  f1 = (Tspkts+Tslost)?Tslost*100/(Tspkts+Tslost):0;
	  printf("\
                          |%6d %4d  %2d %4d %7d (All Senders)\n",
		 Tspkts, Tslost, f1, Tlpkts, Tbytes/K);
	}
      }
      first=1;
      DO_SENDERS(s) {
	Tspkts += s->spkts; s->Tspkts += s->spkts;
	Tslost += s->slost; s->Tslost += s->slost;
	Tlpkts += s->lpkts; s->Tlpkts += s->lpkts;
	Tbytes += s->bytes; s->Tbytes += s->bytes;
	if (s->flags) {
	  if (first) {
	    printf("%2d ",tick%60); first=0;
	  } else
	    printf("   ");
	  f1 = (s->spkts+s->slost)?s->slost*100/(s->spkts+s->slost):0;
	  f2 = (s->Tspkts+s->Tslost)?s->Tslost*100/(s->Tspkts+s->Tslost):0;
	  printf("\
%3d  %2d  %2d  %2d %6d |%6d %4d  %2d %4d %7d %s\n",
s->spkts, s->slost, f1, s->lpkts, s->bytes,
s->Tspkts, s->Tslost, f2, s->Tlpkts, s->Tbytes/K,
		 s->from_name);
	}
	s->flags = s->spkts = s->lpkts = s->slost = s->bytes = 0;
      } UNTIL_SENDERS(s);
    }

    /* tabulate current packet */
    tick = now.tv_sec;
    ss = findfrom(&from);
    sq = (getseq)(buff, len, ss);
    if (sq >= 0) {
      ss->flags = 1;
      ss->spkts++;
      if (ss->seq >=0) {
	if (0x80 & (sq - ss->seq - 1))
	  ss->lpkts++;			/* late */
	else {
	  ss->slost += 0xFF & ((unsigned int) (sq - ss->seq - 1));
	  ss->seq = sq;
	}
      } else
	ss->seq = sq;
    } else {
      ss->lpkts++;			/* non-sequenced */
    }
    ss->bytes += len + HEADER_FUDGE;
    senders = ss;
  }
}

unsigned int getRTPseq(b, l, s)
unsigned char *b;
int l;
struct senderstat *s;
{
  /* XXX We are clueless here, but this seems to work */
  /* XXX We should parse RTP options and update s->from_name.... */
  /* XXX if there is non-sequenced data, return(-1) */
  /* XXX */ return(b[3]);
}

struct senderstat *findfrom(f)
struct sockaddr_in *f;
{
  struct senderstat* s=0;
  unsigned char *fa = (unsigned char *) &f->sin_addr;

  DO_SENDERS(s) {
    if (!strncmp((char *)&f->sin_addr, (char *)&s->from.sin_addr,
		 sizeof(struct sockaddr_in)))	return(s);
  } UNTIL_SENDERS(s);
  
  NOTNULL(s = (struct senderstat *) malloc(sizeof(struct senderstat)),
	  "malloc\n");
  bzero(s, sizeof(struct senderstat));
  bcopy((char *)&f->sin_addr, (char *)&s->from.sin_addr,
	sizeof(struct sockaddr_in));
  sprintf(s->from_name, "%d.%d.%d.%d", fa[0], fa[1], fa[2], fa[3]);
  s->seq = -1;
  if (!senders) {
    s->next = s;
    senders = s;
  } else {
    s->next = senders->next;
    senders->next = s;
  }
  return (s);
}

int openMC(name, port)
char *name;
char *port;
{
  struct sockaddr_in sin;
  struct ip_mreq mreq;
  struct hostent *hp;
  int fd, one=1;

  bzero(&sin, sizeof(struct sockaddr_in));
  if (isdigit(*name)) {
    sin.sin_addr.s_addr = inet_addr(name);
  }
  else if (hp = gethostbyname(name)) {
    bcopy(hp->h_addr, (char *)&sin.sin_addr, hp->h_length);
  }
  else {
    printf("I Don't understand session name %s\n",name);
    exit(1);
  }
  sin.sin_family = AF_INET;
  sin.sin_port = htons(atoi(port)); /* xxx */

  if (!IN_MULTICAST(ntohl(sin.sin_addr.s_addr))) {
    printf("%s is not a multicast session\n", name);
    exit(1);
  }
  mreq.imr_multiaddr = sin.sin_addr;
  mreq.imr_interface.s_addr = INADDR_ANY;

  NOERROR(fd = socket(AF_INET, SOCK_DGRAM, 0), "socket");
  NOERROR(setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &one, sizeof(one)),
	  "SO_REUSEADDR");

  if (bind(fd, &sin, sizeof(sin)) == -1) {
    perror("Warning - Using INADDR_ANY because");
    sin.sin_addr.s_addr = INADDR_ANY;
    NOERROR(bind(fd, &sin, sizeof(sin)), "bind");
  }

  NOERROR(setsockopt(fd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq, sizeof(mreq)),
	  "IP_ADD_MEMBERSHIP");

  return(fd);
}

/* Following code by Stig Venaas <Stig.Venaas@uninett.no> in response
   to my posting on multicast-wg@internet2.edu.  Thanks, Stig! */

#ifndef MCAST_JOIN_SOURCE_GROUP
struct group_source_req {
    uint32_t                gsr_interface; /* interface index */
    struct sockaddr_storage gsr_group;     /* group address */
    struct sockaddr_storage gsr_source;    /* source address */
};
#define MCAST_JOIN_SOURCE_GROUP         46
#define MCAST_LEAVE_SOURCE_GROUP        47
#endif

int openSSM(source, group, port)
     char *source;
     char *group;
     char *port;
{
    int e, s, slevel;
    struct addrinfo hints, *res;
    struct group_source_req gsreq;

    /* Should be possible to use "0" for interface or take interface
       name as argument */
    gsreq.gsr_interface = if_nametoindex("eth0");

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;
    
    if ((e = getaddrinfo(source, NULL, &hints, &res))) {
	fprintf(stderr, "getaddrinfo failed: %s\n", gai_strerror(e));
	return -1;
    }

    /* We only use first value, a name might resolve to multiple */
    if ((s = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) < 0)
	return -1;

    memcpy(&gsreq.gsr_source, res->ai_addr, res->ai_addrlen);
    freeaddrinfo(res);

    if ((e = getaddrinfo(group, port, &hints, &res))) {
	fprintf(stderr, "getaddrinfo failed: %s\n", gai_strerror(e));
	return -1;
    }
    /* We only use first value, a name might resolve to multiple */
    slevel = res->ai_family == AF_INET ? IPPROTO_IP : IPPROTO_IPV6;
    memcpy(&gsreq.gsr_group, res->ai_addr, res->ai_addrlen);
    freeaddrinfo(res);

    if (bind(s, res->ai_addr, res->ai_addrlen) < 0)
	return -1;
    
    if (setsockopt(s, slevel, MCAST_JOIN_SOURCE_GROUP,
		   (char *)&gsreq, sizeof(gsreq)) == -1)
	return -1;
    return s;
}
