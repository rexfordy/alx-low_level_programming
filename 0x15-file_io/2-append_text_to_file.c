#include "main.h"
/**
 * append_text_to_file - append a textfile
 * @filename: the textfile to write.
 * @text_content: the content of the textfile to write
 * Description: append content to a textfile
 * section header: the header is main.h
 * Return: 1 in success -1 in failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fot, _write, t; /* t : the number of bytes of the content */

	if (filename == NULL)
		return (-1);

	fot = open(filename, O_WRONLY | O_APPEND);
	if (fot == -1)
		return (-1);

	if (text_content)
	{
		while (text_content[t])
			t++;

		_write = write(fot, text_content, t);
		if (_write == -1)
			return (-1);
	}
	close(fot);
	return (1);
}
