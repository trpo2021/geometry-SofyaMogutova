CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -MMD
CC = gcc
all: geometry
out: geometry.o out.o
	$(CC) $(CFLAGS) -o $@ $^

geometry.o: geometry.c
	$(CC) -c $(CFLAGS) -o $@ $<

out.o: out.c out.h
	$(CC) -c $(CFLAGS) -o $@ $<

-include geometry.d out.d
