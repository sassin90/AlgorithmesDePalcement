COMPILE=gcc

FLAGS= 	
#-W -Wall -ansi -pedantic
#SRC= data.c node.c list.c

OBJ=main.o data.o  node.o list.o algorithms.o 

exe:$(OBJ)
	$(COMPILE)  $(OBJ) -o exe


clean:
	rm -f *.o
distclean: clean
	rm -f exe
