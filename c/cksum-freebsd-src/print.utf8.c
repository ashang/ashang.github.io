#ifndef lint
#if 0
static char sccsid[] = "@(#)print.c	8.1 (Berkeley) 6/6/93";
#endif
#endif /* not lint */

#include <sys/cdefs.h>

#include <sys/types.h>

#include <stdio.h>
#include <stdint.h>

#include "extern.h"

void
pcrc(char *fn, uint32_t val, off_t len)
{
	(void)printf("%lu %jd", (u_long)val, (intmax_t)len);
	if (fn != NULL)
		(void)printf(" %s", fn);
	(void)printf("\n");
}

void
psum1(char *fn, uint32_t val, off_t len)
{
	(void)printf("%lu %jd", (u_long)val, (intmax_t)(len + 1023) / 1024);
	if (fn != NULL)
		(void)printf(" %s", fn);
	(void)printf("\n");
}

void
psum2(char *fn, uint32_t val, off_t len)
{
	(void)printf("%lu %jd", (u_long)val, (intmax_t)(len + 511) / 512);
	if (fn != NULL)
		(void)printf(" %s", fn);
	(void)printf("\n");
}
