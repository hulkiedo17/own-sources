#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "../header.h"

void read_stream_test(void)
{
	printf("[TEST] read_stream_test\n");

	size_t line_count = (size_t)0;
	char *line = NULL;
	char *file = NULL;
	FILE *fp = NULL;

	file = str_dup("test.txt");

	fp = fopen(file, "r");

	free(file); // avoiding memory leak

	if(!fp)
		p_error("cannot open file\n");

	while((line = read_file_stream(fp)) != NULL)
	{
		fprintf(stdout, "%zd\t%s\n", ++line_count, line);

		free(line);
		line = NULL;
	}

	fclose(fp);
	printf("[END TEST] read_stream_test\n");
}

/*void read_descriptor_test(void)
{
	printf("[TEST] read_descriptor_test\n");

	int fd = 0;
	size_t readed = 0;
	size_t line_count = 0;
	char *file = NULL;
	char *line = NULL;

	file = str_dup("test2.txt");

	fd = open(file, O_RDONLY, 0644);

	free(file); // avoiding memory leak

	if(fd == -1)
		p_error("cannot open file\n");

	while((line = read_file_descriptor(fd, &readed)) != NULL)
	{
		// you can use 'size_t readed' in some cases.
		fprintf(stdout, "%zd\t%s\n", ++line_count, line);

		free(line);
		line = NULL;
	}

	close(fd);
	printf("[END TEST] read_descriptor_test\n");
}*/

int main(void)
{
	read_stream_test();
	//read_descriptor_test();
	return EXIT_SUCCESS;
}
