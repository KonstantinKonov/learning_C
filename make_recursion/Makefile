CC=gcc
CCFLAGS=-Wall
LD=gcc
LDFLAGS=-Wall
MAKE=make
TARGET=main
OBJ=get_version/getv.o to_up/to_up.o

$(TARGET): make_getv make_to_up $(TARGET).o
	$(LD) $(LDFLAGS) -o $(TARGET) $(OBJ) $(TARGET).o

$(TARGET).o: $(TARGET).c
	$(CC) $(CCFLAGS) -c $^

make_getv: 
	$(MAKE) -C get_version getv.o

make_to_up:
	$(MAKE) -C to_up to_up.o

run:
	./$(TARGET)

clean:
	rm -f *.o $(TARGET)
	$(MAKE) -C get_version clean
	$(MAKE) -C to_up clean


