#include "main.h"
/**
* Author: Ukasquared
* print_last_digit - function that prints the last digit of a number
* Return: 0 on success
*/

int print_last_digit(int p)
{
	int m, n;

	n = -1;
	if(p < 0)
		m = (p * n) % 10;
	else
		m = p % 10;
	return (m);
}
