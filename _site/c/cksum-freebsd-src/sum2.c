#ifndef lint
#if 0
static char sccsid[] = "@(#)sum2.c	8.1 (Berkeley) 6/6/93";
#endif
#endif /* not lint */
#include <sys/cdefs.h>

#include <sys/types.h>

#include <unistd.h>
#include <stdint.h>

#include "extern.h"

int
csum2(int fd, uint32_t *cval, off_t *clen)
{
	uint32_t lcrc;
	int nr;
	off_t total;
	u_char *p;
	u_char buf[8192];

	/*
	 * Draft 8 POSIX 1003.2:
	 *
	 *   s = sum of all bytes
	 *   r = s % 2^16 + (s % 2^32) / 2^16
	 * lcrc = (r % 2^16) + r / 2^16
	 */
	lcrc = total = 0;
	while ((nr = read(fd, buf, sizeof(buf))) > 0)
		for (total += nr, p = buf; nr--; ++p)
			lcrc += *p;
	if (nr < 0)
		return (1);

	lcrc = (lcrc & 0xffff) + (lcrc >> 16);
	lcrc = (lcrc & 0xffff) + (lcrc >> 16);

	*cval = lcrc;
	*clen = total;
	return (0);
}
