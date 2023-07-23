#include "main.h"
/**
* Author: Ukasquared
* print_alphabeth - checks if the argument is lowercase
* @c: argument
* Return: 0 on success
*/

int _islower(int c)
{
	if(c >= 97 && c <= 122)
		return (1);
	else
		return (0);
}
