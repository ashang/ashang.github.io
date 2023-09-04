#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

static const char *header = 
	"HTTP/1.0 200 OK\nLast-Modified: Sat, 1 Nov 1980 08:30:15 GMT\nContent-type: image/gif\n\n";
static int header_len;

static const char gif[] =
	{ 0x47, 0x49, 0x46, 0x38, 0x39, 0x61, 0x01, 0x00, 0x01, 0x00, 0x80, 0x00, 0x00, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0x21, 0xf9, 0x04, 0x01, 0x00, 0x00, 0x01, 0x00, 0x2c, 0x00, 0x00, 0x00, 0x00,
	0x01, 0x00, 0x01, 0x00, 0x00, 0x02, 0x02, 0x4c, 0x01, 0x00, 0x3b };
static const int gif_len = 43;

void receive_header(int fd);

int main(int argc, char *argv[])
{
	int sock_listen, sock_conn, conaddr_len;
	struct sockaddr_in saddr;
	struct sockaddr conaddr_in;

	header_len = strlen(header);

	if (argc != 3) {
		printf("Usage: %s <IP Address> <TCP port>\n", argv[0]);
		exit(1);
	}

	if (inet_aton(argv[1], &saddr.sin_addr) == 0) {
		printf("Invalid IP address.\n");
		exit(1);
	}

	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(atoi(argv[2]));

	sock_listen = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (bind(sock_listen, (struct sockaddr *)&saddr, sizeof(saddr))) {
		perror("bind");
		exit(1);
	}

	if (listen(sock_listen, 4)) {
		perror("listen");
		exit(1);
	}

	if (fork() != 0) {
		exit(0);
	}

	close(0);
	close(1);
	close(2);

	while(1) {
		sock_conn = accept(sock_listen, &conaddr_in, &conaddr_len);
		receive_header(sock_conn);
		send(sock_conn, header, header_len, 0);
		send(sock_conn, gif, gif_len, 0);
		close(sock_conn);
	}
}

void receive_header(int fd)
{
	const int buffer_len = 1024;
	char ignore[buffer_len];
	recv(fd, ignore, buffer_len, 0);

}
