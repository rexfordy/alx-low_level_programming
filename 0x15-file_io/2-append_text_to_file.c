#include "main.h"
/**
 * append_text_to_file - append a textfile
 * @filename: the textfile to write.
 * @text_content: the content of the textfile to write
 * Description: append content to a textfile
 * section header: the header is main.h
 * Return: 1 in success -1 in failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fot, wt, no_cont; /* no_cont : the number of bytes of the content */

	if (filename == NULL)
		return (-1);

	fot = open(filename, O_WRONLY | O_APPEND);
	if (fot == -1)
		return (-1);

	if (text_content)
	{
		while (text_content[no_cont])
			no_cont++;

		wt = write(fot, text_content, no_cont);
		if (wt == -1)
			return (-1);
	}
	close(fot);
	return (1);
}
