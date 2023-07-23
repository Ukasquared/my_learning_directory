#include <stdio.h>
/**
* Author: Ukasquared
* Main - prints alphabet in lowercase and uppercase
* Return: 0
*/

int main(void)
{
	int a;
	char ch;

	for (a = 48; a < 58; a++)
		putchar(a);
	for (ch = 'a'; ch < 'g'; ch++)
		putchar(ch);
	putchar('\n');
}

