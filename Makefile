CC = gcc
CFLAGS = -lm -Wall -Wextra -Werror
CPPFLAGS = -I .src -MP -MMD
HEADER = .src/libgeometry/out.h
all: geometry
geometry: .src/geometry/geometry.o .src/libgeometry/out.o
	$(CC) $(CFLAGS) -o $@ $^

geometry.o: .src/geometry/geometry.c $(HEADER)
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

out.o: .src/libgeometry/out.c .src/libgeometry/out.h
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

.PHONY: clean
clean:
	rm -rf *.o geometry
