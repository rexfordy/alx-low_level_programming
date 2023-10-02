#include "main.h"
/**
 * read_textfile - read a textfile.
 * @filename: the textfile to read.
 * @letters: the number of characters  to read
 * Description: read a file
 * section header: the header of is main.h
 * Return: this return the number of chars read from the file.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fot, rd, wt;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	fot = open(filename, O_RDONLY, 600);
	if (fot == -1)
	{
		free(buffer);
		return (0);
	}
	rd = read(fot, buffer, letters);
	if (rd == -1)
	{
		free(buffer);
		return (0);
	}

	wt = write(STDOUT_FILENO, buffer, rd);
	if (wt == -1 || wt != rd)
	{
		return (0);
	}

	free(buffer);
	close(fot);
	return (wt);
}
