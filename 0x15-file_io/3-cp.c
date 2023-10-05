#include "main.h"
/**
 * main - copy a textfile.
 * @argc: the number of args in the textfile
 * @argv: the Args in the textfile.
 * Description: copy a textfile
  * Return: 0 in success.
 */
int main(int argc, char *argv[])
{
	int source_fd, destn_fd;
	int read_new, close_source, close_destn;
	char buffer[1024];

	if (argc > 3 || argc < 3)
	{
		dprintf(STDERR_FILENO, "Use: cp file_from file_to\n");
		exit(97);
	}
	source_fd = open(*(argv + 1), O_RDONLY);
	if (source_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error Message: Unable to read from file %s\n", *(argv + 1));
		exit(98);
	}
	destn_fd = open(*(argv + 2), O_TRUNC | O_CREAT | O_WRONLY, 0664);
	while ((read_new = read(source_fd, buffer, 1024)) > 0)
	{
		if (destn_fd == -1 || (write(destn_fd, buffer, read_new) != read_new))
		{
			dprintf(STDERR_FILENO, "Error Message: Unable to write to %s\n", *(argv + 2));
			exit(99);
		}
	}
	if (read_new < 0)
	{
		dprintf(STDERR_FILENO, "Error Message: Unable to read from file %s\n", *(argv + 1));
		exit(98);
	}
	close_source = close(source_fd);
	if (close_source < 0)
		dprintf(STDERR_FILENO, "Error Message: Unable to close fd %i\n", source_fd), exit(100);
	close_destn = close(destn_fd);
	if (close_destn < 0)
		dprintf(STDERR_FILENO, "Error Message: Unable to close fd %i\n", destn_fd), exit(100);
	return (0);
}
