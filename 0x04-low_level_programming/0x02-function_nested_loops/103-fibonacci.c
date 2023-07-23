#include "main.h"
/**
* Author: Ukasquared
* main - program finds and prints even-valued terms in
* the fibonacci sequence
* Return: 0 on success
*/

int main(void)
{
	unsigned long int sum, i, fib1, fib2, fib3;
	sum = 0;
	fib1 = 0;
	fib2 = 1;
	
	for (i = 0; i < 4000000; i++)
	{
		fib3 = fib1 + fib2;
		if (fib3 % 2 == 0)
			sum += fib3;
		fib1 = fib2;
		fib2 = fib3;
	}
	printf("%lu\n", sum);
}
