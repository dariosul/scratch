CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lglut -lGL -lGLU -lX11 -lm

spin: spin.c 
	$(CC) $< -o $@ $(LDFLAGS)

draw_rect: draw_rect.c
	$(CC) $< -o $@ $(LDFLAGS)

single_double: single_double.c
	$(CC) $< -o $@ $(LDFLAGS)
