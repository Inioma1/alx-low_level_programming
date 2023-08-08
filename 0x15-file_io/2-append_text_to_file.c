#include "main.h"

/**
 * #include "main.h" - This contains the function (prototype),
 * apnd_text_to_file - This is used to apnd text at the end of a file,
 * @filename: The name of File to be created,
 * @text_content: The string to be added to the end of a txt file,
 * Return: -1, is returned if function fails
 */


int append_text_to_file(const char *filename, char *text_content)
{
	int a, b, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}

	a = open(filename, O_WRONLY | O_APPEND);
	b = write(a, text_content, length);

	if (a == -1 || b == -1)
		return (-1);

	close(a);

	return (1);
}
