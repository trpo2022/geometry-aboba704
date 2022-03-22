all: geometry
geometry: geometry.c
	gcc -Wall -Werror -o geometry.exe geometry.c
clean:
	rm geometry.exe
run:
	./geometry.exe
