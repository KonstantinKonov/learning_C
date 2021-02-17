CC=gcc
LD=gcc
OPT=-Wall
GDB=-g
TARGET=binary_tree_recursion
LIBS=-lm

all: $(TARGET).o
	$(LD) $(OPT) $(TARGET).o -o $(TARGET)

$(TARGET).o: $(TARGET).c
	$(CC) -c $(TARGET).c -o $(TARGET).o

clean:
	rm $(TARGET).o
