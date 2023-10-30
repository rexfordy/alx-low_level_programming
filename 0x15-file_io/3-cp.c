#include "main.h"
/**
 * main - This copy a file.
 * @argc: This is the number of args
 * @argv: This is the Args.
 * Description: This copy a file
  * Return: 0 in success.
 */
int main(int argc, char *argv[])
{
	int s_fd, d_fd;
	int _read, _close_src, _close_dest;
	char buffer[1024];

	if (argc > 3 || argc < 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	s_fd = open(*(argv + 1), O_RDONLY);
	if (s_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error:Can't read from file %s\n", *(argv + 1));
		exit(98);
	}
	d_fd = open(*(argv + 2), O_TRUNC | O_CREAT | O_WRONLY, 0664);
	while ((_read = read(s_fd, buffer, 1024)) > 0)
	{
		if (d_fd == -1 || (write(d_fd, buffer, _read) != _read))
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", *(argv + 2));
			exit(99);
		}
	}
	if (_read < 0)
	{
		dprintf(STDERR_FILENO, "Alert:Can't read from file %s\n", *(argv + 1));
		exit(98);
	}
	_close_src = close(s_fd);
	if (_close_src < 0)
		dprintf(STDERR_FILENO, "Alert: Can't close fd %i\n", s_fd), exit(100);
	_close_dest = close(d_fd);
	if (_close_dest < 0)
		dprintf(STDERR_FILENO, "Alert: Can't close fd %i\n", d_fd), exit(100);
	return (0);
}
