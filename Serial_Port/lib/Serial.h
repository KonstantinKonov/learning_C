#ifndef H_SERIAL
#define H_SERIAL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <termios.h>
#include <errno.h>
#include <fcntl.h>

#define DISPLAY_STRING
#define MAX_NUMBER_PORTS 100
#define PORTNAME_MAX_LENGTH 255

// Get list of ACMs and USBs, returns total number of ports
int SerialGetList(char ***);

// Prints the list of the serial ports
void SerialPrintList(int, char ***, FILE *);

// Choose serial port number, return it to string variable "selected"
void SerialChoose(int, char ***, char *);

// Set port attributes
int SerialSetAttribs(int, int);

// 
void SerialSetMinCount(int, int);

//
int SerialOpen(char *);

int SerialClose();

int SerialWrite(int, char *);

int SerialRead(char **);

// All in one function
void SerialInit();


#endif