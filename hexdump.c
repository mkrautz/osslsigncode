#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/**
 * Print a hexdump of a buffer
 *
 * @param   dat  Data buffer.
 * @param   len  Length of data buffer.
 *
 * @return  Nothing.
 */
void
hexdump(void *dat, int len)
{
	unsigned int i, j, rem, off = 0;
	char *p = dat;
	unsigned char c;

	if (len < 1)
		return;

	printf("[%.4u]  ", 0);

	for (i = 0; i < len; i++)
	{
		if (!(i % 16) && (i > 0))
		{
			/* only one space, since we already insert a space after the last character. */
			printf(" [");

			for (j = 16; j > 0; j--)
			{
				c = p[i-j];
				printf("%c", isprint(c) ? c : '.');
			}

			printf("]\n");
			printf("[%.4u]  ", i);
		}

		printf("%.2x ", p[i] & 0xff);
	}

	/*
	 * We cannot reach this if we were passed len=0, so the
	 * only case where i mod 16 = 0 is for i = 16.
	 */
	rem = i % 16;
	if (rem == 0) rem = 16;

	off = (16 - rem) * 3; /* chars on the line * 3 */

	for (j = 0; j < off; j++)
	{
		printf(" ");
	}

	printf(" [");

	for (j = 0; j < rem; j++)
	{
		c = p[i - rem + j];
		printf("%c", isprint(c) ? c : '.');
	}
	printf("]\n");
}

