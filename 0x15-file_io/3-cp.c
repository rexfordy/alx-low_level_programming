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
	int src_fot, d_fot;
	int rd, cl_src, cl_d;
	char buffer[1024];

	if (argc > 3 || argc < 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	src_fot = open(*(argv + 1), O_RDONLY);
	if (src_fot == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", *(argv + 1));
		exit(98);
	}
	d_fot = open(*(argv + 2), O_TRUNC | O_CREAT | O_WRONLY, 0664);
	while ((rd = read(src_fot, buffer, 1024)) > 0)
	{
		if (d_fot == -1 || (write(d_fot, buffer, rd) != rd))
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", *(argv + 2));
			exit(99);
		}
	}
	if (rd < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", *(argv + 1));
		exit(98);
	}
	cl_src = close(src_fot);
	if (cl_src < 0)
		dprintf(STDERR_FILENO, "Error: Can't close fot %i\n", src_fot), exit(100);
	cl_d = close(d_fot);
	if (cl_d < 0)
		dprintf(STDERR_FILENO, "Error: Can't close fot %i\n", d_fot), exit(100);
	return (0);
}
