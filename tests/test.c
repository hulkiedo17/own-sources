#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "../header.h"

static char *file = NULL;

void read_stream_test1(void)
{
	printf("[TEST] read_stream_test\n");

	size_t line_count = 0;
	char *line = NULL;
	FILE *fp = NULL;

	fp = open_file_stream(file, "r");

	if(!fp)
		p_error("cannot open file\n");

	while((line = read_file_stream(fp)) != NULL)
	{
		fprintf(stdout, "%zd\t%s\n", ++line_count, line);

		free(line);
		line = NULL;
	}

	fclose(fp);
	printf("[END TEST] read_stream_test\n\n");
}

void read_stream_test2(void)
{
	printf("[TEST] read_stream_test\n");

	const size_t buffer_size = 512;
	size_t line_count = 0;
	char buffer[buffer_size];
	FILE *fp = NULL;

	fp = open_file_stream(file, "r");

	while(fgets_own(buffer, buffer_size, fp) != NULL)
	{
		printf("%zd\t%s", ++line_count, buffer);
	}

	fclose(fp);
	printf("[END TEST] read_stream_test\n\n");
}

void read_stream_test3(void)
{
	printf("[TEST] read_stream_test\n");

	size_t len = 0;
	size_t line_count = 0;
	ssize_t read = -1;
	char *line = NULL;
	FILE *fp = NULL;

	fp = open_file_stream(file, "r");

	while((read = getline_own(&line, &len, '\n', fp)) != -1)
	{
		printf("%zd-%zu\t%s", ++line_count, read, line);
	}

	free(line);
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
	file = str_dup("test.txt");

	read_stream_test1();

	read_stream_test2();

	read_stream_test3();
	
	//read_descriptor_test();

	free(file);
	return EXIT_SUCCESS;
}
