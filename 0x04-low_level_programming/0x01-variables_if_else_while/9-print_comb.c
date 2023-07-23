#include <stdio.h>
/**
* Author: Ukasquared
* Main - prints alphabet in lowercase and uppercase
* Return: 0
*/

int main(void)
{
	int a;
	
	for (a = 48; a < 58; a++)
	{
		putchar(a);
		if(a != 57)
		{
			putchar(',');
			putchar(' ');
		}
	}
	putchar('\n');
}
