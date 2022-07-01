#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../header.h"

int main(void)
{
	size_t line_count = (size_t)0;
	char *buffer = NULL;
	FILE *fp = NULL;

	char *filename = str_dup("test.txt");

	fp = fopen(filename, "r");

	free(filename); // avoiding memory leak

	if(!fp)
		p_error("cannot open file\n");

	while((buffer = read_file_stream(fp)) != NULL)
	{
		fprintf(stdout, "%zd\t%s\n", ++line_count, buffer);

		free(buffer);
		buffer = NULL;
	}

	fclose(fp);
	return EXIT_SUCCESS;
}
