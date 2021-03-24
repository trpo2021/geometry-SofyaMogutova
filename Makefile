CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -MMD
all:geometry
geometry: main.o out.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c
	$(CC) -c $(CFLAGS) -o $@ $<

out.o: out.c
	$(CC) -c $(CFLAGS) -o $@ $<

-include out.d
