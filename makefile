#definitions for constants
CC = gcc
CFLAGS = -o

make: main.c moveLogic.c boardLogic.c turnDeclaration.h moveLogic.h boardLogic.h
	$(CC) $(CFLAGS) main main.c boardLogic.c moveLogic.c

clean:
	rm -f *.o *.exe
#.o file is an object file that gets compiled together with the main file,an    d will help the program compile faster. Want to only recompile code that cha    nged
