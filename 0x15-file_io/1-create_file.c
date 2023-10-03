#include "main.h"
/**
 * append_text_to_file - append a textfile
 * @filename: the textfile to write.
 * @text_content: the content of the textfile to write
 * Description: append content to a textfile
 * section header: the header is main.h
 * Return: 1 in success -1 in failure
 */
int create_file(const char *filename, char *text_content)
{
int fot, _write, t = 0; /* Initialize t to 0 */

if (filename == NULL)
return (-1);

fot = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0600);
if (fot == -1)
return (-1);
if (text_content != NULL)
{
while (text_content[t])
t++;
_write = write(fot, text_content, t);
if (_write == -1 || _write < t)
{
close(fot);
return (-1);
}
}
if (close(fot) == -1)
{
return (-1);
}
return (1);
}
