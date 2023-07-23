#include "main.h"
/**
* _isdigit - check for a digt (0 theough 9)
*
* Return: 0 (success)
*/

int _isdigit(int c);
{
	if(c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}
