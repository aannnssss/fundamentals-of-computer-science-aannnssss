CC=gcc
RM=rm -fr
CFLAGS=-g
OBJECTS=tree.o
EXECUTABLE=program

all: tree.o
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(OBJECTS) -lm

tree.o: tree.c tree.h
	$(CC) $(CFLAGS) -c tree.c

clean:
	$(RM) $(EXECUTABLE) $(OBJECTS)
