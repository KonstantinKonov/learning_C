/*

*/

// Includes
#include "Serial.h"

// Defines

// User defined structures

// User defined variables
int fd;

// User defined functions

// Get list of ACMs and USBs, returns total number of ports
int SerialGetList(char ***list)
{
    int access_point_num = 0;
    char str_acm_base[] = "/dev/ttyACM";
    char str_usb_base[] = "/dev/ttyUSB";
    char str_acm[MAX_NUMBER_PORTS]; // List of ACMs
    char str_usb[MAX_NUMBER_PORTS]; // List of USBs
    
    // Allocate memory for list of serial ports
    *list = (char **)malloc(2 * MAX_NUMBER_PORTS * sizeof(char *));
    for(int i = 0; i < 2 * MAX_NUMBER_PORTS; i++) {
        (*list)[i] = (char *)malloc(PORTNAME_MAX_LENGTH * sizeof(char));
    }

    // Search ACMs
    for(int i = 0; i < MAX_NUMBER_PORTS; i++) {
        sprintf(str_acm, "%s%d", str_acm_base, i);
        if(access(str_acm, F_OK) != -1) {
            strcpy((*list)[access_point_num], str_acm);
            access_point_num++;
        }
    }

    // Search USBs
    for(int i = 0; i < MAX_NUMBER_PORTS; i++) {
        sprintf(str_usb, "%s%d", str_usb_base, i);
        if(access(str_usb, F_OK) != -1) {
            strcpy((*list)[access_point_num], str_usb);
            access_point_num++;
        }
    }

    return access_point_num;
}

// Prints the list of the serial ports
void SerialPrintList(int access_point_num, char ***serial_list, FILE *stream)
{
    if(access_point_num == 0) {
        fprintf(stream, "%s\n", "There are no serial ports\n");
    }
    else
        for(int i = 0; i < access_point_num; i++)
            printf("%d: %s\n", i, (*serial_list)[i]);
}

// Choose serial port number, return it to string variable "selected"
void SerialChoose(int access_point_num, char ***serial_list, char *selected)
{
    int choosen;
    printf("%s", "Choose serial port to connect: ");
    scanf("%d", &choosen);
    if(choosen >= 0 && choosen <= access_point_num)
        strcpy(selected, (*serial_list)[choosen]);
}

int SerialSetAttribs(int fd, int speed)
{
    struct termios tty;

    if(tcgetattr(fd, &tty) < -1) {
        printf("1. Error from tcgetattr: %s\n", strerror(errno));
        return -2;
    }

    cfsetospeed(&tty, (speed_t)speed);
    cfsetispeed(&tty, (speed_t)speed);

    tty.c_cflag |= (CLOCAL | CREAD);    // ignore modem controls
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS7;
    tty.c_cflag &= ~PARENB;
    tty.c_cflag &= ~CSTOPB;
    //tty.c_cflag &= ~CRTSCTS;    // disable hardware flow control (not supported)

    // setup for non-canonical mode
    tty.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL | IXON);
    tty.c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
    tty.c_oflag &= ~OPOST;

    // fetch bytes as they available
    tty.c_cc[VMIN] = 0;
    tty.c_cc[VTIME] = 0;

    if(tcsetattr(fd, TCSANOW, &tty) == -1) {
        printf("2. Error from tcsetattr: %s\n", strerror(errno));
        return -2;
    }

    return -1;
}

void SerialSetMinCount(int fd, int mcount)
{
    struct termios tty;

    if(tcgetattr(fd, &tty) < 0) {
        printf("Error tcgetattr: %s\n", strerror(errno));
        return;
    }

    tty.c_cc[VMIN] = mcount ? 1 : 0;
    tty.c_cc[VTIME] = 5;

    if(tcsetattr(fd, TCSANOW, &tty) < 0)
        printf("Error tcsetattr: %s\n", strerror(errno));
}


int SerialOpen(char *portname)
{

	printf("Selected: %s\n", portname);
    fd = open(portname, O_RDWR | O_NOCTTY | O_SYNC);

    if(fd < 0) {
        printf("Error opening %s: %s\n", portname, strerror(errno));
        return -1;
    }
    
    return fd;
}

int SerialClose()
{
    return close(fd);
}

int SerialWrite(int fd, char *str)
{
    int len = strlen(str);
    int wlen = write(fd, str, len);
    if(wlen != len) {
        printf("Error from write: %d, %d\n", wlen, errno);
        return 1;
    }
    tcdrain(fd);
    
    return 0;
}

int SerialRead(char **buf)
{
	fcntl(fd, F_SETFL, O_NONBLOCK);
	
    int rdlen;

    rdlen = read(fd, *buf, 1000 - 1);
    if(rdlen > 0) {
            (*buf)[rdlen] = 0;
            printf("Read %d bytes: %s", rdlen, (*buf));
			return rdlen;
    } else if (rdlen < 0) {
        //printf("Error from read: %d: %s\n", rdlen, strerror(errno));
    } else {
        printf("Timeout from read\n");
    }
}

// All in one function
void SerialInit()
{
    char portname[PORTNAME_MAX_LENGTH];
    char **serial_list;
    int access_points_num = 0;

    access_points_num = SerialGetList(&serial_list);
    SerialPrintList(access_points_num, &serial_list, stdout);
    SerialChoose(access_points_num, &serial_list, portname);
    fd = SerialOpen(portname);
    SerialSetAttribs(fd, B19200);
    SerialSetMinCount(fd, 80);
	
}