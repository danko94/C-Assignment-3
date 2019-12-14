CC=gcc
OBJECTS_MAIN=main.o

FLAGS= -Wall -g

all: isort txtfind
isort: shift.c
	$(CC) $(FLAGS) shift.c -o isort
txtfind: cat.c
	$(CC) $(FLAGS) cat.c -o txtfind


.PHONY: all clean

clean:
	rm -f isort txtfind