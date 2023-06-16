CC = gcc 
CFLAGS = -g 
OBJ = main.o tree.o  
PROG = program 
 
build: main.o tree.o  
	$(CC) $(CFLAGS) -o $(PROG) $(OBJ) 
 
main.o: main.c 
	$(CC) $(CFLAGS) -c main.c 
 
tree.o: tree.c tree.h 
	$(CC) $(CFLAGS) -c tree.c 
 
clean: 
	rm $(PROG) $(OBJ)

