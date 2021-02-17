#compiler
CC=gcc
DEBUG=-g
OPT=-O0
WARN=-Wall
PTHREAD=-pthread

CCFLAGS=$(DEBUG) $(OPT) $(WARN) $(PTHREAD)

#linker
LD=gcc

LDFLAGS=$(PTHREAD) -lm

#target & libs
TARGET=main
TARGET_DIR=src
LIBS=fifo
LIBS_DIR=lib
OBJ_DIR=obj
BIN_DIR=bin

OBJS=$(TARGET).o $(LIBS).o

all: $(OBJ_DIR)/$(TARGET).o $(OBJ_DIR)/$(LIBS).o
	#if not exist bin, obj -> create bin, obj
	$(LD) -o $(BIN_DIR)/$(TARGET) $(OBJ_DIR)/$(TARGET).o $(OBJ_DIR)/$(LIBS).o $(LDFLAGS)  
	./$(BIN_DIR)/$(TARGET)

$(OBJ_DIR)/$(TARGET).o: $(TARGET_DIR)/$(TARGET).c
	$(CC) -c $(CCFLAGS) $(TARGET_DIR)/$(TARGET).c -o $(OBJ_DIR)/$(TARGET).o

$(OBJ_DIR)/$(LIBS).o: $(LIBS_DIR)/$(LIBS).c
	$(CC) -c $(CCFLAGS) $(LIBS_DIR)/$(LIBS).c -o $(OBJ_DIR)/$(LIBS).o

clean:
	rm $(OBJ_DIR)/*.o
	rm $(BIN_DIR)/*
