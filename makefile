PROGRAM=buscar
CC=g++
CFLAGS=-Wall -Werror -Wconversion

all: $(PROGRAM)

$(PROGRAM): main.o funciones.o
	$(CC) $(CFLAGS) main.o funciones.o -o $(PROGRAM)

main.o: main.cpp funciones.h
	$(CC) $(CFLAGS) -c main.cpp

funciones.o: funciones.cpp
	$(CC) $(CFLAGS) -c funciones.cpp

remove: *.o
	rm *.o

debug: main.o funciones.o
	$(CC) $(CFLAGS) main.o funciones.o -o $(PROGRAM) -g