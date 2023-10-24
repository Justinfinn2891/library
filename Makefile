CC = g++
CFLAGS = -g -Wall -Wextra

default: library

TARGET = library

all:library

library: library.o main.o
	$(CC) $(CFLAGS) -o library library.o main.o

library.o: library.cpp library.h
	$(CC) $(CFLAGS) -c library.cpp

main.o: main.cpp library.h
	$(CC) $(CFLAGS) -c main.cpp

clean:$(RM) *.o *~ 
