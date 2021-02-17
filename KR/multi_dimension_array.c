#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day)
{
	int leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	for(int i = 1; i < month; i++)
		day += daytab[leap][i]; // 0: not leap; 1: leap

	return day; 
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	int i;
	for(i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
}

int main(int argc, char **argv)
{
	if(argc <= 2)
		return 0;
	else if( !strcmp(argv[1], "day") && argc == 4 ) {
		int yearday = atoi(argv[2]);
		int year = atoi(argv[3]);
		int month = 0, day = 0;
		month_day(year, yearday, &month, &day);
		printf("%02d.%02d.%04d\n", day, month, year);
	}
	else if( !strcmp(argv[1], "date") && argc == 5 ) {
		int day = atoi(argv[2]);
		int month = atoi(argv[3]);
		int year = atoi(argv[4]);
		printf("%d\n", day_of_year(year, month, day));
	}

	return 0;
}
