/**
* Author: Ukasquared
* main: program to check if a number is positive or negative
* Return: 0 on success
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int b, c;

	srand(time(NULL));
	b = rand();
	printf("the random number: %d\n", b);
	printf("the rand_max: %d\n", RAND_MAX);
	c = b - RAND_MAX / 2;
	printf("%d\n", c);
	if(c < 0)
		printf("%d is negative\n", c);
	else if(c > 0)
		printf("%d is positive\n", c);
	else
		printf("%d is Zero\n", c);
}
