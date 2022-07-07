#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
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
