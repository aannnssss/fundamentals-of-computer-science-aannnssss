CC=gcc
RM=rm -fr
CFLAGS=-g
OBJECTS=main.o vector.o matrix.o
EXECUTABLE=program

all: main.o vector.o matrix.o
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(OBJECTS)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

vector.o: vector.c vector.h
	$(CC) $(CFLAGS) -c vector.c

matrix.o: matrix.c matrix.h
	$(CC) $(CFLAGS) -c matrix.c

clean:
	$(RM) $(EXECUTABLE) $(OBJECTS)
