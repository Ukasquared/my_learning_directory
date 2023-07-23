/**
* Author
* Main - find the last digit in a number
* Return: 0 on success
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	int b, c, mod;

	srand(time(NULL));
	b = rand();
	c = b - RAND_MAX / 2;
	mod = c % 10;
	printf("The last digit of %d is %d ", c, mod);
	if(mod > 5)
		puts("and is greater than 5");
	else if(mod == 0)
		puts("and is 0");
	else if(mod < 6 && mod != 0)
		puts("and is less than 6 and not 0");
}
