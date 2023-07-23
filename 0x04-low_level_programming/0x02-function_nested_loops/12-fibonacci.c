#include "main.h"
/**
* Author: Ukasquared
* main - prints the first fibonacci numbers starting with 1 and 2
* Return: 0 on success
*/

int main(void)
{
	int i, c, a, b;
	
	a = 1;
	b = 2;
	for (i = 0; i < 51; i++)
	{
		c = a + b;
		printf("%d", c);
		a = b;
		b = c;
	}
	
