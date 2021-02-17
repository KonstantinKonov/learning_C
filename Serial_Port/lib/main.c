#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include "Serial.h"

void *ReadFunction(void *var)
{
    while(1) {
        char *buf = (char *)malloc(100*sizeof(char));
        SerialRead(&buf);

        if(strlen(buf) != 0) 
            printf("%s", buf);
        
        usleep(100000); 
    }
}

int main()
{
    char **serial_list;
    int access_points_num = SerialGetList(&serial_list);

    printf("Number of serial ports: %d\n", access_points_num);
    for(int i = 0; i < access_points_num; i++)
        printf("Serial ports: %s\n", serial_list[i]);

    printf("Choose serial port:\n");
    for(int i = 0; i < access_points_num; i++)
        printf("%d: %s\n", i, serial_list[i]);
    int choosen;
    scanf("%d", &choosen);

    char portname[100];
    strcpy(portname, serial_list[choosen]);
    int fd = SerialOpen(portname);
    SerialSetAttribs(fd, B19200);
    SerialSetMinCount(fd, 80);

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, ReadFunction, NULL);
    pthread_join(thread_id, NULL);

    while(1){};
}