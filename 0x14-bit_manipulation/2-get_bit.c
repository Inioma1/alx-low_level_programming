#include "main.h"

/**
 * #include "main.h" - This contains the function prototype.
 * 
 * @n: Number to search for.
 * @index: index of the bit.
 * 
 * get_bit - returns the value of a bit.
 * 
 * Return: value of the bit.
 */


int get_bit(unsigned long int n, unsigned int index)
{
	int bit_value;

	if (index > 63)
		return (-1);

	bit_value = (n >> index) & 1;

	return (bit_value);
}
