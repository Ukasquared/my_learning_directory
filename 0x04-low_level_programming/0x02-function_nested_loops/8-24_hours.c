#include "main.h"
/**
* Author: Ukasquared
* jack_bauer - prints every minute of the day
* Return: 0 on success
*/

void jack_bauer(void)
{
	int m, n, p, q;
	
	for(m = 0; m < 3; m++)
	{
		for(n = 0; n <= 3; n++)
		{
			for(p = 0; p < 6; p++)
			{
				for(q = 0; q <= 9; q++)
				{
					_putchar(m + '0');
					_putchar(n + '0');
					_putchar(':');
					_putchar(p + '0');
					_putchar(q + '0');
					_putchar('\n');
				}
			}
		}
	}
}
