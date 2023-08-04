#include "main.h"

/**
 * #include "main.h" - This contains the function prototype.
 * set_bit - sets a bit at a given index to 1.
 * @n: points to the number to changed.
 * Return: -1 for failure, 1 for success.
 */


int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}
