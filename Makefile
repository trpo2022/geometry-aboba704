CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -MMD

all: bin/geometry
	
bin/geometry: obj/geometry.o
	gcc $(CFLAGS) -o $@ $^
	
obj/geometry.o: src/geometry/geometry.c
	gcc -c $(CFLAGS) $(CPPFLAGS) -o $@ $<
		
clean:
	rm bin/* obj/*