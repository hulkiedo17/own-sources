#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include "header.h"

/*char* read_file_descriptor(int fd, size_t *length)
{
	//if(fd <= 0)
	//	return NULL;

	int c;
	size_t len = BUFFER_SIZE;
	size_t pos = 0;
	ssize_t res = 0;
	char *buf = NULL;

	buf = calloc(len, sizeof(char));
	if(!buf)
		p_error("error: %s: allocation failed\n", __func__);

	printf("DEBUG: rfd1\n");

	while((res = read(fd, &c, 1)) > 0)
	{
		//printf("DEBUG: res = %zu\n", res);
		//printf("DEBUG: c = \'%c\'\n\n", c);
		if(c == '\n')
		{
			printf("DEBUG: pos = %zd, c = \'%c\'\n", pos, c);
			buf[pos] = '\0';
			*length = pos;
			return buf;
		}

		buf[pos++] = c;

		printf("DEBUG: pos = %zd\n", pos);

		if(pos >= len)
		{
			len += BUFFER_SIZE;
			buf = realloc(buf, len);
			if(!buf)
				p_error("error: %s: allocation failed\n", __func__);
		}
	}

	printf("DEBUG: rfd2\n");

	free(buf);
	*length = 0;
	return NULL;
}*/

char* read_file_stream(FILE *stream)
{
	assert(stream != NULL);

	int c;
	size_t len = BUFFER_SIZE;
	size_t pos = 0;
	char *buf = NULL;

	buf = calloc(len, sizeof(char));
	if(!buf)
		p_error("error: %s: allocation failed\n", __func__);

	while(1)
	{
		c = fgetc(stream);

		if(c == '\n')
		{
			buf[pos] = '\0';
			return buf;
		}
		else if(c == EOF)
		{
			if(pos != 0)
			{
				buf[pos] = '\0';
				return buf;
			}

			free(buf);
			return NULL;
		}

		buf[pos++] = c;

		if(pos >= len)
		{
			len += BUFFER_SIZE;
			buf = realloc(buf, len);
			if(!buf)
				p_error("error: %s: allocation failed\n", __func__);
		}
	}
}
