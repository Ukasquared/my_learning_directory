#include "main.h"
/**
* Author: Ukasquared
* main - to print every minute of the day
* Return: 0 on success
*/

void jack_bauer(void)
{
	int a, b, tens_a, digit_a, tens_b, digit_b;
	for(a = 0; a < 24; a++)
	{
		for(b = 0; b < 60; b++)
		{
			tens_a = a / 10;
			digit_a = a % 10;
			tens_b = b / 10;
			digit_b = b % 10;
			_putchar(tens_a + '0');
			_putchar(digit_a + '0');
			_putchar(':');
			_putchar(tens_b + '0');
			_putchar(digit_b + '0');
			_putchar('\n');
		}
	}
}
