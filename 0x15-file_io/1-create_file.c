#include "main.h"

/**
 * create_file - This creates a file
 * @filename: the filename.
 * @text_content: the content written in the file.
 *
 * Return: 1 if it success. -1 if it fails.
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	int n;
	int r_write;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (fd == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	for (n = 0; text_content[n]; n++)
		;

	r_write = write(fd, text_content, n);

	if (r_write == -1)
		return (-1);

	close(fd);

	return (1);
}
