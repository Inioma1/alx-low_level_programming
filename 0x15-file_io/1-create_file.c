#include "main.h"

/**
 * #include "main.h" - This contains the function (prototype),
 * @text_content: This points to a string to write to a file,
 * @filename: The name of File to be created,
 * Return: -1, is returned if function fails,
 */

int create_file(const char *filename, char *text_content)
{
	int wd, a, length = 0;

	if (filename == NULL)

		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}

	wd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	a = write(wd, text_content, length);

	if (wd == -1 || a == -1)
		return (-1);

	close(wd);

	return (1);
}
