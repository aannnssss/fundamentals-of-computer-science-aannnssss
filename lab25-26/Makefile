CC=gcc
RM=rm -fr
CFLAGS=-g
OBJECTS=main.o list.o sort.o
EXECUTABLE=program

all: main.o list.o sort.o
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(OBJECTS)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c

sort.o: sort.c sort.h
	$(CC) $(CFLAGS) -c sort.c

clean:
	$(RM) $(EXECUTABLE) $(OBJECTS)
