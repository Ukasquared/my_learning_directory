#include <stdio.h>
/**
* Author: Ukasquared
* Main - prints alphabet in lowercase and uppercase
* Return: 0
*/

int main(void)
{
	int c;

	for (c = 97; c <= 122; c++)
	{
		if(c != 101 && c != 131)
			putchar(c);
	}
	putchar('\n');
}
