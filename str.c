#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys/types.h>
#include "header.h"

char* str_dup(const char *str)
{
	assert(str != NULL);

	char *buf = NULL;

	buf = calloc(strlen(str) + 1, sizeof(char));
	if(!buf)
		p_error("error: %s: allocation failed\n", __func__);

	memcpy(buf, str, strlen(str));

	return buf;
}

char* fgets_own(char *s, int size, FILE *stream)
{
	int c;
	char *p = s;

	if(s == NULL || size <= 0)
		return NULL;

	if(ferror(stream))
		return NULL;

	while(--size > 0 && (c = getc(stream)) != EOF)
		if((*p++ = c) == '\n')
			break;

	if(c == EOF && (p == s || ferror(stream)))
		return NULL;

	*p = '\0';
	return s;
}

ssize_t getline_own(char **lineptr, size_t *n, int terminator, FILE *stream)
{
	char *p;
	char *line;
	size_t size;
	size_t copy;

	if(lineptr == NULL || n == NULL || stream == NULL)
		return -1;

	if(ferror(stream))
		return -1;

	// make sure we have a line buffer to start with
	if(*lineptr == NULL || *n < 2)
	{
		line = realloc(*lineptr, LINE_SIZE);
		if(line == NULL)
			return -1;

		*lineptr = line;
		*n = LINE_SIZE;
	}

	line = *lineptr;
	size = *n;

	copy = size;
	p = line;

	while(1)
	{
		size_t len;

		while(--copy > 0)
		{
			int c = getc(stream);
			if(c == EOF)
				goto lose;
			else if((*p++ = c) == terminator)
				goto win;
		}

		// need to enlarge the line buffer
		len = p - line;
		size *= 2;
		line = realloc(line, size);
		if(line == NULL)
			goto lose;

		*lineptr = line;
		*n = size;

		p = line + len;
		copy = size - len;
	}

lose:
	if(p == *lineptr)
		return -1;
win:
	*p = '\0';
	return p - *lineptr;
}

