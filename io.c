#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "header.h"

char* read_file_descriptor(int fd)
{
	if(fd <= 0)
		return NULL;
	/*int c;
	char *buffer = NULL;

	buffer = calloc(buffer_size, sizeof(char));
	if(!buffer)
		fail(stderr, "error: allocation failed\n");

	while(1)
	{

	}*/

	return NULL;
}

char* read_file_stream(FILE *stream)
{
	assert(stream != NULL);

	int c;
	size_t buffer_size = BUFFER_SIZE;
	size_t position = 0;
	char *buffer = NULL;

	buffer = calloc(buffer_size, sizeof(char));
	if(!buffer)
		fail(stderr, "error: allocation failed\n");

	while(1)
	{
		c = fgetc(stream);

		if(c == '\n')
		{
			buffer[position] = '\0';
			return buffer;
		}
		else if(c == EOF)
		{
			if(position != 0)
			{
				buffer[position] = '\0';
				return buffer;
			}

			free(buffer);
			return NULL;
		}

		buffer[position++] = c;

		if(position >= buffer_size)
		{
			buffer_size += BUFFER_SIZE;

			buffer = realloc(buffer, buffer_size);
			if(!buffer)
				fail(stderr, "error: allocation failed\n");
		}
	}
}
