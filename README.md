# own-sources
my own implementations of standard library functions and more.

## sources list

| File | Description |
| --- | --- |
| /tests/test.c | test file that uses all functions |
| header.h | declarations for all functions from all source files in this repo (used by test.c). |
| err.c | warning and error output functions. |
| io.c | i/o functions |
| str.c | string manipulation functions |
| file.c | functions for work with files |

## test

to compile and run test, go to tests/ directory, and type this:

```shell
$ make
$ make run
```
