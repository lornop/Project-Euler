/*
Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

    1634 = 14 + 64 + 34 + 44
    8208 = 84 + 24 + 04 + 84
    9474 = 94 + 44 + 74 + 44

As 1 = 14 is not a sum it is not included.

The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.

*/

/* Libraries */
#include <stdio.h>


/* Function Prototypes */
//Input a number and get the fifth power
int PowerFive(int);
void printSum(int);
void foundOne(int);
int getSumDigits(int);          //Lots going on in this one
int numPlaces(int);


/* Globals */
int maxNum      = 99999999;         //I don t really know what this should be....
int count       = 2;              //1 doesnt count so we are starting at 2
int totalSum    = 0;              //Keep track of the running total sum


int main()
{
    while(count < maxNum){
        if (getSumDigits(count) == count){
            foundOne(count);
        }
        count++;

    }
    printSum(totalSum);

    return 0;
}

/* Get Fifth Power of a number*/
int PowerFive(int number){
    int fifth = number; 
    for(int x = 0; x < 5; x++){
        fifth *= number;
    }
    return(fifth);
}

/*Print out the final sum*/
void printSum(int num){
    printf("The final sum of all the numbers is %d \n", num);
}

/*Print out the number we found and add it to the sum*/
void foundOne(int num){
    totalSum += num;
    printf("Found a Number: %d \n", num);
}

/*Get the sum of all fith powers of the digits. This will exit if the sum is greater than the number being checked*/
int getSumDigits(int num){
    int sum = 0;
    int tens = 1;
    for (int x = 0; x < numPlaces(num); x++){
        sum += (PowerFive(num / (tens) % 10));
        if(sum > num){
            break;
        }

        tens *= 10;
    }
    return(sum);
}


/*For calcualting how many digits we are using for the maxNum. Used in getSumDigits()*/
int numPlaces (int n) {
    if (n < 10) return 1;
    if (n < 100) return 2;
    if (n < 1000) return 3;
    if (n < 10000) return 4;
    if (n < 100000) return 5;
    if (n < 1000000) return 6;
    if (n < 10000000) return 7;
    if (n < 100000000) return 8;
    if (n < 1000000000) return 9;

}




/*	
    
    singledigits[0] = number / 1000000000 % 10;
	singledigits[1] = number / 100000000 % 10;
	singledigits[2] = number / 10000000 % 10;
	singledigits[3] = number / 1000000 % 10;
	singledigits[4] = number / 100000 % 10;
	singledigits[5] = number / 10000 % 10;
	singledigits[6] = number / 1000 % 10;
	singledigits[7] = number / 100 % 10;
	singledigits[8] = number / 10 % 10;
	singledigits[9] = number / 1 % 10;
    
*/