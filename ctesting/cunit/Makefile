.PHONEY: test

CC = gcc
CLAGS = -Wall -Werror
CUNIT_LIB_DIR=/usr/local/lib

OBJS = program.o test.o

test_executable: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lcunit -o test
test.o: test.c
	$(CC) $(CFLAGS) -c test.c
program.o: program.c
	$(CC) $(CFLAGS) -c program.c
clean:
	rm $(OBJS) test

test: test_executable
	LD_LIBRARY_PATH=$(CUNIT_LIB_DIR) ./test