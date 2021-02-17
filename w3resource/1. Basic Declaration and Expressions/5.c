#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum months {Jan = 1, Feb = 2, Mar = 3, Apr = 4, May = 5, Jun = 6, Jul = 7, Aug = 8, Sep = 9, Oct = 10, Nov = 11, Dec = 12};
int days[2][13] = { {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} };
char *months_s[13] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

typedef struct {
    int day;
    int month;
    int year;
} date;

int date_to_day(date d)
{
    int day = 0;
    if( d.year % 4 == 0 && d.year % 400 != 0 )
        for(int i = 1; i < d.month; i++)
            day += days[1][i];
    else
        for(int i = 1; i < d.month; i++)
            day += days[0][i];

    day += d.day;
    return day;
}

date day_to_date(int day, int year)
{
    int month = 1;
    if( year % 4 == 0 && year % 400 != 0 )
        while( day / days[1][month] != 0 ) {
            day -= days[1][month];
            month++;
        }
    else
        while( day / days[0][month] != 0 ) {
            day -= days[0][month];
            month++;
        }
    date d;
    d.year = year;
    d.month = month;
    d.day = day;

    return d;
}

int main(int argc, char **argv)
{
    int day;
    int year;
    scanf("%d", &day);
    scanf("%d", &year);
    date d = day_to_date(day, year);

    printf("%d.%d.%d\n", d.day, d.month, d.year);
    printf("%d.%s.%d\n", d.day, months_s[d.month], d.year);

    int d_new = date_to_day(d);

    printf("%d\n", d_new);

    return 0;
}