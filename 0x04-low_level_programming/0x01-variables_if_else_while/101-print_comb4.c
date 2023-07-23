#include <stdio.h>
/**
* Author: Ukasquared
* Main - prints all possible different
* combination of digits
* Return: 0
*/

int main(void)
{
	int m, n, v;
	for(m = 48; m < 56; m++)
	{
		for(n = 49; n < 57; n++)
		{
			for(v = 50; v < 58; v++)
			{
				if(v > n && n > m)
				{
					putchar(m);
					putchar(n);
					putchar(v);
				
					if(m != 55)
					{	
						putchar(',');
						putchar(' ');
					}
				}
			}
		}
	}
	putchar('\n');
}
