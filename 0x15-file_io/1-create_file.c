#include "main.h"
/**
 * create_file - write a textfile
 * @filename: the textfile to write.
 * @text_content: the content of the textfile to write
 * Description: write  a filefile
 * section header: the header of is main.h
 * Return: 1 in success -1 in failure
 */
int create_file(const char *filename, char *text_content)
{
	int fot, _write, t; /* t: is the len of the content */

	if (filename == NULL)
		return (-1);

	fot = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0600);
	if (fot == -1)
		return (-1);

	if (text_content != NULL)
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
