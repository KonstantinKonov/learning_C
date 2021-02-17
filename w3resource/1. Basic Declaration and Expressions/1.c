#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct date_of_birth {
	int day;
	int month;
	int year;
} date_of_birth;

typedef struct person {
	char *name;
	char *second_name;
	date_of_birth db;
	char *phone;
} person;

int number_of_persons = 0;

int validate_date(int day, int month, int year)
{
	if(year >= 1900 && year <= 9999)
    {
        //check month
        if(month >= 1 && month <= 12)
        {
            //check days
            if((day >= 1 && day <= 31) && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)) {
				return 0;
			}
            else if((day >= 1 && day <= 30) && (month == 4 || month == 6 || month == 9 || month == 11)) {
				return 0;
			}
            else if((day >= 1 && day <= 28) && (month == 2)) {
				return 0;
			}
            else if(day == 29 && month == 2 && (year % 400 == 0 ||(year % 4 == 0 && year % 100 != 0))) {
				return 0;
			}
            else {
				printf("Date is not valid\n");
				return 1;
			}
        }
        else
        {
			printf("Date is not valid\n");
			return 2;
        }
    }
    else
    {
		printf("Date is not valid\n");
		return 3;
    }
 
    return 0; 
}

int create_new_person(person **prsn) 
{
	// Name
	printf("Enter name:\n");
	char *name; size_t n = 0;
	getline(&name, &n, stdin);

	// Second name
	printf("Enter second name:\n");
	char *second_name; n = 0;
	getline(&second_name, &n, stdin);

	// Date of birth
	printf("Enter date of birth(dd.mm.yyyy):\n");
	char *date; n = 0;
	getline(&date, &n, stdin);
	int day; int month; int year; char delimiter[2] = "."; int counter = 0;
	char *token = strtok(date, delimiter);
	while( token != NULL && counter < 3) {
		switch(counter) {
			case 0:
			day = atoi(token);
			break;
			case 1:
			month = atoi(token);
			break;
			case 2:
			year = atoi(token);
			break;
			default:
			break;
		}
		token = strtok(NULL, delimiter);
		counter++;
	}

	// Check date
	if( validate_date(day, month, year) )
		exit(0);

	printf("Enter phone number:\n");
	char *phone; n = 0;
	getline(&phone, &n, stdin);

	// Memory allocation for a new person
	*prsn = (person *) realloc(*prsn, (number_of_persons + 1) * sizeof(person));
	(*prsn)[number_of_persons].name = (char *) malloc( (strlen(name) + 1) * sizeof(char));
	(*prsn)[number_of_persons].second_name = (char *) malloc( (strlen(second_name) + 1) * sizeof(char));
	(*prsn)[number_of_persons].phone = (char *) malloc( (strlen(phone) + 1) * sizeof(char));

	// Fill in data structure
	(*prsn)[number_of_persons].db.day = day;
	(*prsn)[number_of_persons].db.month = month;
	(*prsn)[number_of_persons].db.year = year;
	strcpy( (*prsn)[number_of_persons].name, name );
	strcpy( (*prsn)[number_of_persons].second_name, second_name );
	strcpy( (*prsn)[number_of_persons].phone, phone);
	number_of_persons++;

	return 0;
}

void print_addr_book(person *prsn) 
{
	for(int i = 0; i < number_of_persons; i++) {
		printf("%s", prsn[i].name);
		printf("%s", prsn[i].second_name);
		printf("%s", prsn[i].phone);
		printf("%2d.%2d.%4d\n", prsn[i].db.day, prsn[i].db.month, prsn[i].db.year);
	}
}

int main(int argc, char **argv)
{
	// array of persons
	person *prsn = NULL;
	create_new_person(&prsn);
	create_new_person(&prsn);

	print_addr_book(prsn);

	return 0;
}
