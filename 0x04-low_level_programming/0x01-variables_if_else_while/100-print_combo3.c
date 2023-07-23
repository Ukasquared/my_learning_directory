#include <stdio.h>
/**
* Author: Ukasquared
* Main - prints alphabet in lowercase and uppercase
* Return: 0
*/

int main(void)
{	int num, num2;

	for (num = 48; num < 57; num++)
	{
		for (num2 = 49; num2 < 58; num2++)
		{
			if(num2 > num && num != 57)
			{
				putchar(num);
				putchar(num2);
				putchar(',');
				putchar(' ');
			}
		}
	}
	putchar('\n');
}
