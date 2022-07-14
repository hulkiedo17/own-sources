.POSIX:

CC := gcc
CFLAGS := -Wall -Wextra -Werror -g -O0 -std=c11 -Wpedantic
SRC := ../io.c ../err.c ../str.c ../file.c test.c
EXEC := test

.PHONY: all
all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: clean
clean:
	rm -rf $(EXEC)

.PHONY: run
run:
	./$(EXEC)
