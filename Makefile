COMPILE=gcc

FLAGS= 	
#-W -Wall -ansi -pedantic
#SRC= data.c node.c list.c

OBJ=main.o obj/data.o  obj/node.o obj/list.o algorithms.o obj/annexe.o

exe:$(OBJ)
	$(COMPILE)  $(OBJ) -o exe

data.o:	data.c data.h
	$(COMPILE)   -c data.c -o data.o $(FLAGS)

main.o:	main.c data.h node.h
	$(COMPILE)   -c main.c -o main.o $(FLAGS)
node.o:	node.c node.h
	$(COMPILE)   -c node.c -o node.o $(FLAGS)

list.o:	list.c list.h
	$(COMPILE)   -c list.c -o list.o $(FLAGS)
algorithms.o: algorithms.h algorithms.c
	$(COMPILE)   -c algorithms.c -o algorithms.o $(FLAGS)

annexe.o:annexe.h annexe.c
	$(COMPILE)   -c annexe.c -o annexe.o $(FLAGS) 
clean:
	rm -f *.o
distclean: clean
	rm -f exe
