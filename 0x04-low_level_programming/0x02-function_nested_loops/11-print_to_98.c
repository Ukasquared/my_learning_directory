#include "main.h"
/**
* Author: Ukasquared
* print_to_98 - print all natural numbers
* @n: first number to be printed
* Return: 0 on success
*/

void print_to_98(int n)
{
	if(n <= 98)
	{
		for (; n < 98; n++)
			printf("%d,  ", n);
	}else if(n > 98)
	{
		for (; n > 98; n--)
			printf("%d,  ", n);
	}
	printf("%d\n", 98);
}
