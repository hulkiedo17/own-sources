#ifndef HEADER_H
#define HEADER_H

// warnings.c
void p_warn(const char *fmt, ...);
void p_error(const char *fmt, ...);

// string.c
#define BUFFER_SIZE 512
char* read_file_descriptor(int fd);
char* read_file_stream(FILE *stream);

#endif /* HEADER_H */
