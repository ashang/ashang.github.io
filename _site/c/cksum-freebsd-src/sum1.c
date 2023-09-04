#ifndef lint
#if 0
static char sccsid[] = "@(#)sum1.c	8.1 (Berkeley) 6/6/93";
#endif
#endif /* not lint */

#include <sys/cdefs.h>

#include <sys/types.h>

#include <unistd.h>
#include <stdint.h>

#include "extern.h"

int
csum1(int fd, uint32_t *cval, off_t *clen)
{
	int nr;
	u_int lcrc;
	off_t total;
	u_char *p;
	u_char buf[8192];

	/*
	 * 16-bit checksum, rotating right before each addition;
	 * overflow is discarded.
	 */
	lcrc = total = 0;
	while ((nr = read(fd, buf, sizeof(buf))) > 0)
		for (total += nr, p = buf; nr--; ++p) {
			if (lcrc & 1)
				lcrc |= 0x10000;
			lcrc = ((lcrc >> 1) + *p) & 0xffff;
		}
	if (nr < 0)
		return (1);

	*cval = lcrc;
	*clen = total;
	return (0);
}
