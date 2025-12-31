/*
Counting Sundays
Problem 19

You are given the following information, but you may prefer to do some research for yourself.

1 Jan 1900 was a Monday.

Thirty days has September,
April, June and November.
All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.

A leap year occurs on any year evenly divisible by 4, but not on a century unless
it is divisible by 400.

How many Sundays fell on the first of the month during the 
twentieth century (1 Jan 1901 to 31 Dec 2000)?

*/

/* Libraries */
#include <stdio.h>

/* Function Prototypes */

void answer(int);
int checkSunday(int, int);
int leapyear(int);
int howmanydays(int, int);


/* Globals */
int year = 1900;
int lastyear = 2000;
int monthsperyear = 12;
int month = 1;              //4, 6, 8 ,10 have 30. rest have 31. 2 has 28 or 29 on years divisible by 4
int dayspermonth = 30;      //1,3,5,7,9,11,12 have 31
int date = 1;
int daysperweek = 7;
int weekday = 2;
int sundays = 0;


int main(){
    while(year <= lastyear){
        while (month <= 12){
            dayspermonth = howmanydays(month, year);
             while(date <= dayspermonth){
                date++;
                weekday++;
                if (weekday > daysperweek){
                    weekday = 1;
                }
            }
            month++;
            date = 1;
            sundays += checkSunday(date, weekday);
        }
        month = 1;
        date = 1;
        year++;
    }
answer(sundays);
return 69;
}

/* we've finsihed couting all the sundays */
void answer(int suns){
    printf("The amount of Sundays is %d \n", suns);
}

/* Check if the 1st day of the month is a sunday */
int checkSunday(int daynum, int dayweek){
    if (year > 1900){
        if ((daynum == 1) && (dayweek == 1)){
                return 1;
            }
        else return 0;
    }
    else {
        return 0;
    }
}

/* Input the year to see if its a leapyear or not
A leap year occurs on any year evenly divisible by 4, 
but not on a century unless it is divisible by 400.
return 1 if it is, 0 if its not a leapyear*/
int leapyear(int yr){
    if (yr % 100 == 0){
        if(yr % 400 == 0){
            return 1;
        }
        return 0;
    }
    if (yr % 4 == 0){
        return 1;
    }
    return 0;
}

/* 4, 6, 8 ,10 have 30. 
2 has 28 or 29 on leapyears
1,3,5,7,9,11,12 have 31 

Thirty days has September,
April, June and November.
*/
int howmanydays(int mnth, int yr){
    switch (mnth){
        case 2: 
            return 28 + leapyear(yr);
            break;
        case 4:
            return 30;
            break;
        case 6:
            return 30;
            break;
        case 9:
            return 30;
            break;
        case 11:
            return 30;
            break;
        default:
            return 31;
            break;
    }
}
