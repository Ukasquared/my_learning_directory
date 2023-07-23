#include "main.h"
/**
* Author: Ukasquared
* main  - check is argument is an alphabeth
* Return: 0 on success
*/

int main(void)
{
	int r;
	r = _isalpha(48);
	_putchar(r + '0');
/**	r = _isalpha('d');
	_putchar(r + '0');
	r = _isalpha(245);
	_putchar(r + '0');
	r = _isalpha('E');
	_putchar(r + '0');
*/
	_putchar('\n');
}
