CC = gcc
CFLAGS = -Wall -g -o 
SOURCES = main.c gnuplot_i/gnuplot_i.c -lgsl -lgslcblas -lm -lpthread
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = main

all:
	$(CC) $(CFLAGS) $(EXECUTABLE) $(SOURCES) 

clean:
	find . -name "*.o" -type f -delete
	#rm $(OBJECTS)