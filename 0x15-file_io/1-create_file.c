#include "main.h"
/**
 * create_file - This writes a file
 * @filename: This is the file to write.
 * @text_content: This is the content to write
 * Description: This writes a file
 * section header: This is the header of this function which is main.h
 * Return: 1 in success -1 in failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd, _write, n; /* N/B: n: length of the content of the file */

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
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
