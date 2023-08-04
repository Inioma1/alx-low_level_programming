#include "main.h"

/**
 * 
 * #include "main.h" - This contains the function prototype.
 * @n: This points to the num to changed.
 * 
 * @index: An index of the bit to clear.
 * clear_bit - sets the value of a given bit to 0.
 * 
 */


int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}
