#include "main.h"

/**
* create_file - creates a file with the given name and writes the given text
* to it
*
* @filename: the name of the file to create
* @text_content: the text to write to the file
*
* Return: 1 on success, -1 on failure
*/
int create_file(const char *filename, char *text_content)
{
int fd, len = 0, w;

if (!filename)
return (-1);

fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
if (fd == -1)
return (-1);

if (text_content)
{
while (text_content[len] != '\0')
len++;
w = write(fd, text_content, len);
if (w == -1 || w != len)
{
close(fd);
return (-1);
}
}

close(fd);
return (1);
}
