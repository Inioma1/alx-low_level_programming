#include "main.h"

/**
 * 
 * #include "main.h" - This contains the function prototype.
 * 
 * @m: The second number.
 * flip_bits - This counts the number of bits to changed.
 * @n: The first number.
 * Return: It returns the number of bits to changed.
 */


unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, Count = 0;
	unsigned long int Current;
	unsigned long int exclusive = n ^ m;

	for (i = 63; i >= 0; i--)
	{
		Current = exclusive >> i;
		if (Current & 1)
			Count++;
	}
	return (Count);
}
