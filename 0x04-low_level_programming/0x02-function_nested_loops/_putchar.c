#include <unistd.h>
/**
* _putchar - writes the character c to standard output
* @c: The character that get replace by argument
* Return: 0 on success
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}
