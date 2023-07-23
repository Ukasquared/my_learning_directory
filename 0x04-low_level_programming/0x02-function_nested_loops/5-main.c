#include "main.h"
/**
* Author: Ukasquared
* main - to print out sign of a number
* Return: 0 on success
*/

int main(void)
{
	int n;
	n = print_sign(98);
	_putchar(',');
	_putchar(' ');
	_putchar(n + '0');
	_putchar('\n');
	n = print_sign(0);
	_putchar(',');
	_putchar(' ');
	_putchar(n + '0');
	_putchar('\n');
	n = print_sign(0xff);
	_putchar(',');
	_putchar(' ');
	_putchar(n + '0');
	_putchar('\n');
	n = print_sign(-1);
	_putchar(',');
	_putchar(' ');
	_putchar(n + '0');
	_putchar('\n');
	return (0);
}
