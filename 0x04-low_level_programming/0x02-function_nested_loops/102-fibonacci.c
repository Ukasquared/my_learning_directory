#include "main.h"
/**
* Author: Ukasquared
* main - prints the first Fibonacci numbers
* Return: 0 on success
*/

int main(void)
{
	unsigned int a, b, count, sum;

	a = 1;
	b = 2;
	printf("%u, %u, ", a, b);
	for( count = 0; count < 48; count++)
	{
		sum = a + b;
		printf("%u", sum);
		// update a and b
		a = b;
		b = sum;
		if(count == 47)
			printf("\n");
		else
			printf(", ");
	}
	return (0);
}
