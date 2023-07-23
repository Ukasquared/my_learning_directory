#include "main.h"
/**
* Author: Ukasquared
* main - to print the 9 times table
* Return: 0 on success
*/

void times_table(void)
{
	int a, b, result, tens, digit;
	for( a = 0; a <= 9; a++)
	{
		for( b = 0; b <= 9; b++)
		{
			result = a * b;
			if(result < 10)
				_putchar(result + '0');
			else
			{
				tens = result / 10;
				digit = result % 10;
				_putchar(tens + '0');
				_putchar(digit + '0');
			}
			if(b < 9)
			{
			_putchar(',');
			_putchar(' ');
			}
		}
		_putchar('\n');
	}
}
