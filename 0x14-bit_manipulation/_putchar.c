#include "main.h"
#include <unistd.h>


/**
 * 
 * @c: A character to be printed.
 * _putchar - This writes the character c to stdout.
 * 
 * On error, -1 is returned, and error number is set appropriately.
 * Return: On success 1.
 */


int _putchar(char c)
{
	return (write(1, &c, 1));
}
