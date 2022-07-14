#ifndef HEADER_H
#define HEADER_H

// err.c
void p_warn(const char *fmt, ...);
void p_error(const char *fmt, ...);

// io.c
#define BUFFER_SIZE 512
//char* read_file_descriptor(int fd, size_t *readed);
char* read_file_stream(FILE *stream);

// str.c
#define LINE_SIZE 256
char* str_dup(const char *str);
char* fgets_own(char *s, int size, FILE *stream);
ssize_t getline_own(char **lineptr, size_t *n, int terminator, FILE *stream);

#endif /* HEADER_H */
