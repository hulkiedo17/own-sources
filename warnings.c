#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void warning(FILE *stream, const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	vfprintf(stream, fmt, ap);
	va_end(ap);
}

void fail(FILE *stream, const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	vfprintf(stream, fmt, ap);
	va_end(ap);

	exit(EXIT_FAILURE);
}
