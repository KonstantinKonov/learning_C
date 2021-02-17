/*

*/

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "choose_serial.h"

// Defines

// User defined structures

// User defined variables

// User defined functions
int get_serial_list(char **serial_list)
{
    int access_point_num = 0;
    char str_acm_base[100] = "/dev/ttyACM";
    char str_usb_base[100] = "/dev/ttyUSB";
    char str_acm[100];
    char str_usb[100];

    for(int i = 0; i < 1000; i++) {
        sprintf(str_acm, "%s%d", str_acm_base, i);
        if(access(str_acm, F_OK) != -1) {
            strcpy(serial_list[access_point_num], str_acm);
            access_point_num++;
        }
    }

    for(int i = 0; i < 1000; i++) {
        sprintf(str_usb, "%s%d", str_usb_base, i);
        if(access(str_usb, F_OK) != -1) {
            strcpy(serial_list[access_point_num], str_usb);
            access_point_num++;
        }
    }

    return access_point_num;
}

void print_serial_list(int access_point_num, char **serial_list)
{
    if(access_point_num == 0) {
        printf("%s\n", "There are no serial ports\n");
    }
    else
        for(int i = 0; i < access_point_num; i++)
            printf("%d: %s\n", i, serial_list[i]);
}

void choose_serial_port(int access_point_num, char **serial_list, char *selected)
{
    int choosen;
    printf("%s", "Choose serial port to connect: ");
    scanf("%d", &choosen);
    if(choosen >= 0 && choosen <= access_point_num)
        strcpy(selected, serial_list[choosen]);
}

void choose_serial(char *selected)
{
    char *serial_list[100];
    for(int i = 0; i < 100; i++)
        serial_list[i] = malloc(25);

    int access_point_num = get_serial_list(serial_list);
    print_serial_list(access_point_num, serial_list);
    choose_serial_port(access_point_num, serial_list, selected);
}