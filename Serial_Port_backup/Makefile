TARGET=main

# compiler
CC=gcc
DEBUG=-g
OPT=-O0
WARN=-Wall
PTHREAD=-pthread
LIBDIR=lib/
SRCDIR=src/

CCFLAGS=$(DEBUG) $(OPT) $(WARN) $(PTHREAD) -pipe

GTKLIB=`pkg-config --cflags --libs gtk+-3.0`

# linker
LD=gcc
LDFLAGS=$(PTHREAD) $(GTKLIB) -export-dynamic -lslope -lm

OBJS=main.o Serial.o

all: ${OBJS}
	${LD} -o ${TARGET} ${OBJS} $(LDFLAGS)

main.o: ${SRCDIR}main.c
	${CC} -c $(CCFLAGS) ${SRCDIR}main.c $(GTKLIB) -o main.o

Serial.o: ${LIBDIR}Serial.c
	${CC} -c ${LIBDIR}Serial.c -o Serial.o

clean:
	rm -f *.o ${TARGET}