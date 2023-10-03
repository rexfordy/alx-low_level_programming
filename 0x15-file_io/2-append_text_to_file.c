#include "main.h"
/**
* append_text_to_file - append a textfile
* @filename: the textfile to write.
* @text_content: the content to be write
* Description: append content of  a textfile
* section header: the header is main.h
* Return: 1 in success -1 in failure
*/
int append_text_to_file(const char *filename, char *text_content)
{
int fd, t, _write ; /* t : the number of bytes of the content */

if (filename == NULL)
return (-1);

fd = open(filename, O_WRONLY | O_APPEND);
if (fd == -1)
return (-1);

if (text_content)
{
while (text_content[t])
t++;

_write = write(fd, text_content, t);
if (_write == -1)
return (-1);
}
close(fd);
return (1);
}
