#include "main.h"
/**
* Author: Ukasquared
* main - computes and prints the sum of all the
	multiples of 3 or 5 below 1024
* Return: 0 on success
*/

int main(void)
{
	int i, sum;
	sum = 0;
	for (i = 0; i < 1024; i++)
	{
		if(i % 3 == 0 || i % 5 == 0)
			sum += i;
	}
	printf("%d\n", sum);
	return (0);
}
