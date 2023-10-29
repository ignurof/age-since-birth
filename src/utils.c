#include <stdio.h>
#include "utils.h"
#include <time.h>


void handle_app_exit(int* should_app_close)
{
	char close_option = 'n';

	printf("Retry %s ? (y) / (n)\n", APP_NAME);
	// Every scanf after the first requires whitespace
	// To change the value of close_option variable,
	// we need to pass the pointer address as C is pass by value as default,
	// so to edit the close_option variable value we need the memory pointer address.
	int close_option_input = scanf(" %c", &close_option);
	// Here we can just display the value as we don't want to edit it.
	printf("close_option_input: %i\n", close_option_input);

	if(close_option == 'n')
	{
		// Need to "dereference" the pointer to change value located at memory address.
		// a pointer tag (*) on a pointer address variable dereferences the pointer.
		*should_app_close = 1;
	}

	printf("Restarting...\n");
}

int validate_date(int date_birth_input)
{
	//TODO: Validation that checks for a VALID date input
	if(date_birth_input < 19000101 || date_birth_input > 20500101)
	{
		printf("Invalid date input!\n");
		return 0;
	}

	return 1;
}

time_object handle_time_conversion(void)
{
	// How to use time:
	// man mktime, man difftime
	time_t time_result = time(NULL);

	time_object to;
	to.year = -1;
	to.month = -1;
	to.day_in_month = -1;
	to.week_day = -1;
	to.day_in_year = -1;
	to.hour = -1;
	to.min = -1;
	to.sec = -1;

	if(time_result != (time_t)(-1))
	{
		struct tm time_struct = *localtime(&time_result);
		
		to.year = 1900 + time_struct.tm_year;
		to.month = 1 + time_struct.tm_mon;
		to.day_in_month = time_struct.tm_mday;
		to.week_day = time_struct.tm_wday;
		to.day_in_year = time_struct.tm_yday;
		to.hour = time_struct.tm_hour;
		to.min = time_struct.tm_min;
		to.sec = time_struct.tm_sec;
	}

	return to;
}
