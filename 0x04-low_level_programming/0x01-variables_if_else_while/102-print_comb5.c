#include <stdio.h>
/**
* Author: Ukasquared
* Main - prints all possible combination of tw0 two-digit number
* Return: 0
*/

int main(void)
{
	int a, b, c, d;
	for(a = 48; a < 58; a++)
	{
		for(b = 48; b < 58; b++)
		{
			for(c = 48; c < 58; c++)
			{
				for(d = 48; d < 58; d++)
				{
					putchar(' ');
					putchar(a);
					putchar(b);
					putchar(' ');
					putchar(c);
					putchar(d);
					putchar(',');
				}
			}
		}
	}
	putchar('\n');
}
