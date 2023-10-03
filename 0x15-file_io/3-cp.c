#include "main.h"
/**
 * main - copy a textfile.
 * @argc: the number of args in the file
 * @argv: the Args.
 * Description: copy a textfile
  * Return: 0 in success otherwise.
 */
int main(int argc, char *argv[])
{
	int source_fd, destination_fd;
	int _read, _close_source, _close_destination;
	char buffer[1024];

	if (argc > 3 || argc < 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	source_fd = open(*(argv + 1), O_RDONLY);
	if (source_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", *(argv + 1));
		exit(98);
	}
	destination_fd = open(*(argv + 2), O_TRUNC | O_CREAT | O_WRONLY, 0664);
	while ((_read = read(source_fd, buffer, 1024)) > 0)
	{
		if (destination_fd == -1 || (write(destination_fd, buffer, _read) != _read))
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", *(argv + 2));
			exit(99);
		}
	}
	if (_read < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", *(argv + 1));
		exit(98);
	}
	_close_source = close(source_fd);
	if (_close_source < 0)
		dprintf(STDERR_FILENO, "Error: Can't close fd %i\n", source_fd), exit(100);
	_close_destination = close(destination_fd);
	if (_close_destination < 0)
		dprintf(STDERR_FILENO, "Error: Can't close fd %i\n", destination_fd), exit(100);
	return (0);
}
