#include "main.h"


/**
 * #include "main.h" - This contains the function prototype.
 * 
 * Return: It returns 0 for big, 1 for little.
 * 
 * get_endianness - This checks if a particular machine is little or big. 
 * 
 */


int get_endianness(void)
{
	unsigned int a = 1;
	char *c = (char *) &a;

	return (*c);
}
