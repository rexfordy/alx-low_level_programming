#include "main.h"
/**
 * append_text_to_file - This appends a file
 * @filename: This is the file to write.
 * @text_content: This is the content to write
 * Description: This appends content to a file
 * section header: This is the header of this function which is main.h
 * Return: 1 in success -1 in failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, _write, n; /*N/B: n is the no. of bytes of content of the file */

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (text_content)
	{
		while (text_content[n])
			n++;

		_write = write(fd, text_content, n);
		if (_write == -1)
			return (-1);
	}
	close(fd);
	return (1);
}
