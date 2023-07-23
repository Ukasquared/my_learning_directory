#include "main.h"
/**
* Author: Ukasquared
* main - to print the last digit of a number
* Return: 0 on success
*/

int main(void)
{
	int r;
	r = print_last_digit(98);
	_putchar(r + '0');
	_putchar('\n');
	r = print_last_digit(0);
	_putchar(r + '0');
	_putchar('\n');
	r = print_last_digit(-1024);
	_putchar(r + '0');
	_putchar('\n');
}

