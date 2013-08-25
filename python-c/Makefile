all: libhello.so

# Compiler
CC = gcc
CFLAGS = -Wall -Werror

# Object files
OBJS = hello.o

# Build shared library
libhello.so: $(OBJS)
	$(CC) -shared -o libhello.so $(OBJS)
hello.o: hello.c
	$(CC) $(CFLAGS) -c -fPIC hello.c
clean:
	rm hello.o libhello.so