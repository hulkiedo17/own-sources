#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "header.h"

char* str_dup(const char *str)
{
	assert(str != NULL);

	size_t len = (size_t)0;
	char *buf = NULL;

	len = strlen(str) + 1;

	buf = calloc(len, sizeof(char));
	if(!buf)
		p_error("error: %s: allocation failed\n", __func__);

	memcpy(buf, str, len);

	return buf;
}
