#include "main.h"
#include <stdlib.h>

/**
 * #include "main.h" - This contains the function (prototype),
 * Read_txtFile: Reading a text file allows it print to STDOUT,
 * @filename: The name of the text file being read,
 * @letters: It signifys the number of letters to be read,
 * Return_C: The Number of bytes read and printed,
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *Buff;
	ssize_t ab;
	ssize_t c;
	ssize_t e;

	ab = open(filename, O_RDONLY);
	if (ab == -1)
		return (0);
	Buff = malloc(sizeof(char) * letters);
	e = read(ab, Buff, letters);
	c = write(STDOUT_FILENO, Buff, e);

	free(Buff);
	close(ab);
	return (c);
}
