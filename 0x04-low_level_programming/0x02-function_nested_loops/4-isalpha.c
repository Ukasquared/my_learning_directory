#include "main.h"
/**
* Author: Ukasquared
* _isalpha - checks for alphabetic letters
* Return: 0 on success
*/

int _isalpha(int c)
{
	if(c >= 'A' && c <= 'Z')
	{
		if(c >= 'a' && c <= 'z')
			return (1);
		else
			return (0);
	}
	return (0);
}
