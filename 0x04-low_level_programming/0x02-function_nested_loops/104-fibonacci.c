#include "main.h"
/**
* main - prints the first 98 Fibonacci number starting 
* with 1 and 2
*
* Return: 0
*/

int main(void)
{
	unsigned long int fib1, fib2, fib3;
	int i;
	
	fib1 = 0;
	fib2 = 1;
	for (i = 0; i < 98; i++)
	{
		fib3 = fib1 + fib2;
		printf("%lu", fib3);
		fib1 = fib2;
		fib2 = fib3;
		if(i < 97)
			printf(", ");
	}
	printf("\n");
	return (0);
} 
