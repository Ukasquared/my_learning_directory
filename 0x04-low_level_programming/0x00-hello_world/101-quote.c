/**
* author: ukasquared
* main - prints a sentence to standard error
* Return: 0 on success
*/

#include <unistd.h>

int main()
{
	char* c;
	int count = 59;

	c = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";
	write(2, c, count);
	return (1);
}
