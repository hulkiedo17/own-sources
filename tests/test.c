#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header.h"

int main(void)
{
	size_t line_count = 0;
	char *buffer = NULL;
	FILE *fp = NULL;

	fp = fopen("test.txt", "r");
	if(fp == NULL)
		fail(stderr, "cannot open file\n");

	while((buffer = read_file_stream(fp)) != NULL)
	{
		fprintf(stdout, "%zd\t%s\n", ++line_count, buffer);
		free(buffer);
		buffer = NULL;
	}

	fclose(fp);
	return EXIT_SUCCESS;
}
