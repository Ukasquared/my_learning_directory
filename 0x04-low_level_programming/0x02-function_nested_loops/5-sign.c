#include "main.h"
/**
* Author: Ukasquared
* print_sign  - to print out sign of a number
* Return: 0 on success
*/

int print_sign(int c)
{
	if(c > 0)
	{
		_putchar('+');
		return (1);
	} else if(c == 0)
	{
		_putchar(c);
		return (0);
	} else
	{
		_putchar('-');
		return (-1);
	}
}
	
