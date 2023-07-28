#include "main.h"
/**
* more_numbers - function that prints 10 times the numbers
* from 0 to 14
*
* Return: 0 (success)
*/

void more_numbers(void)
{
	int a, b, i, j;

	for (i = 0; i <= 14; i++)
	{
		for (j = 0; j <= 14; j++)
		{
			if(j < 10)
			{
				_putchar(j + 48);
			}
			else
			{
				a = j / 10;
				b = j % 10;
				_putchar(a + 48);
				_putchar(b + 48);
			}
		}
		_putchar('\n');
	}
	_putchar('\n');
}
