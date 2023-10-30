#include "main.h"

/**
 * append_text_to_file - this appends text at the end of a file
 * @filename: the filename.
 * @text_content: the content added.
 *
 * Return: 1 if the file exists. -1 if the fails does not exist
 * or if it fails.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	int n;
	int r_write;

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);

	if (fd == -1)
		return (-1);

	if (text_content)
	{
		for (n = 0; text_content[n]; n++)
			;

		r_write = write(fd, text_content, n);

		if (r_write == -1)
			return (-1);
	}

	close(fd);

	return (1);
}
