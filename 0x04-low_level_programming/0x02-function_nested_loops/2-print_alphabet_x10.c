#include "main.h"
/**
* Author: Ukasquared
* print_alphabeth - to print out alphabeth in lowercase 10 times
* Return: 0 on success
*/

void print_alphabet_x10(void)
{
	int i, j;

	for(j = 0; j <= 10; j++)
	{
		for(i = 97; i < 123; i++)
		{
			_putchar(i);
		}
		_putchar('\n');
	}
}
