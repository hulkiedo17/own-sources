#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include "header.h"

FILE* open_file_stream(const char *filename, const char *mode)
{
	assert(filename != NULL);
	assert(mode != NULL);

	FILE *fp = NULL;

	fp = fopen(filename, mode);
	if(!fp)
		p_error("cannot open file\n");

	return fp;
}
