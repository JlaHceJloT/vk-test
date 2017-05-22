
GCC = gcc-4.7 -std=c99 -D_GNU_SOURCE

main: main.o list.o hashtable.o
	 $(GCC) main.o list.o hashtable.o -o main
	
list.o: list.c list.h
	$(GCC) -c list.c
	
hashtable.o: hashtable.c hashtable.h
	$(GCC) -c hashtable.c 
	 
clean:
	 rm -rf main *.o