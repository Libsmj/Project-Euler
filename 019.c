#include <stdio.h>
#include <stdlib.h>
/*
You are given the following information, but you may prefer to do some research for yourself.

1 Jan 1900 was a Monday.
Thirty days has September,
April, June and November.
All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.
A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
*/

int main(int argc, char** argv) {
	printf("Problem 19 - Counting Sundays\n");
	
	// weekday 1 == Sunday, 7 == Saturday
	int weekday = 2;
	int day = 1;
	int month = 1;
	int year = 1900;
	
	int first_sundays = 0;

	while (year < 2001) {
		if ((weekday == 1) == day && year > 1900) {
#ifdef debug
			printf("%d : %d : %d\n", month, day, year);
#endif
			first_sundays++;
		}
		// Check if end of the year
		if (++day == 32 && month == 12) {
			day = 1;
			month = 1;
			year++;
		}
		// Check if end of the month
		else if (day == 32) {
			day = 1;
			month++;
		}
		else if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11)) {
			day = 1;
			month++;
		}			// Leap year
		else if (day == 30 && month == 2) {
			day = 1;
			month++;
		}
		else if (day == 29 && month == 2 && ((year % 4) != 0 || year == 1900)) {
			day = 1;
			month++;
		}
		// Check if end of the week
		if (++weekday == 8) {
			weekday = 1;
		}
	}
	printf("%d\n", first_sundays);

	return 0;
}
