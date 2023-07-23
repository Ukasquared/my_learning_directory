#include <stdio.h>
void print_fun(int);

int main()
{
	int r = 24;
	print_fun(r);
}

void print_fun(int r)
{
	if(r / 2)
		print_fun(r / 2);
	printf("%d\n", r);
}

