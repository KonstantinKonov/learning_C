CC = gcc
CFLAGS = -Wall -g -o 
SOURCES = main.c #lib/lib_array.c -lm 
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = main

all:
	$(CC) $(CFLAGS) $(EXECUTABLE) $(SOURCES) 

clean:
	find . -name "*.o" -type f -delete
	#rm $(OBJECTS)