#include "main.h"

/**
 * create_file - Creates a file and writes text to it.
 * @filename: Pointer to the name of the file to create.
 * @text_content: Pointer to the string to write to the file.
 *
 * Return: On success, returns 1. On failure, returns -1.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, w, len = 0;

	if (filename == NULL)
		return (-1);

	/* Calculate the length of the text_content */
	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	/* Open the file with appropriate flags and permissions */
	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	/* Write text_content to the file */
	w = write(fd, text_content, len);
	if (w == -1)
	{
		close(fd);
		return (-1);
	}

	/* Close the file */
	close(fd);

	return (1);
}
