#include <stdio.h>
/**
* Author: Ukasquared
* Main - prints alphabet in lowercase and uppercase
* Return: 0
*/

int main(void)
{
	int c;

	for (c = 122; c >= 97; c--)
		putchar(c);
	putchar('\n');
}
