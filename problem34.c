/*
Digit Factorials  
Problem 34

145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

Find the sum of all numbers which are equal to the sum of the factorial of their digits.

Note: As 1! = 1 and 2! = 2 are not sums they are not included.

*/

/* Libraries */
#include <stdio.h>

/* Function Prototypes */

int factorialgetter(int);               //input an int and get its factorial
int numPlaces(int);                     //Calculate how many digits are in a number
void printSum(int);                     //Finished, now print out the sum
void foundOne(int);                     //When we found one, print it and add to the total
int getSum(int);                        //Enter an int and get the sum of its digits facorials

/* Globals */

int maxNum                  = 2600000;              //9! is 362880 so 7 times that is just over 2.5 mil
int totalSum                = 0;                    //Store the sum of all required factorials
int factorials[10];                         //store all the factorials for 0-9 so we only do it once
int count = 3;                              //Start going. 1 and 2 dont count


int main()
{

    for (int x = 0; x < 10; x++){               //Calculate factorials for 0 - 9 and store them
        factorials[x] = factorialgetter(x);
    }

    while(count < maxNum){
        if(count == getSum(count)){
            foundOne(count);
        }

        count++;
    }
    printSum(totalSum);
    return 0;
}

/* Functions */

/* Get factorials */
int factorialgetter(int num){
    int sum = num;
    for (int x = (num - 1); x > 0; x--){
        sum *= x;
    }
    if(num < 2){            //So i guess 0! and 1! are both 1. I had 0! as 0
        sum = 1;
    }
    return(sum);
}

/* For calcualting how many digits we are using */
int numPlaces(int n){
    if (n < 10) return 1;
    if (n < 100) return 2;
    if (n < 1000) return 3;
    if (n < 10000) return 4;
    if (n < 100000) return 5;
    if (n < 1000000) return 6;
    if (n < 10000000) return 7;
    if (n < 100000000) return 8;
    if (n < 1000000000) return 9;
    return 10;
}

/* Print out the final sum of all the found numbers*/
void printSum(int sum){
    printf("The sum of all the numbers is : %d \n", sum);
}

/* When we find a match, add it to the total and print it out*/
void foundOne(int fact){
    printf("Found one: %d \n", fact);
    totalSum += fact;
}

/* Input a number and then get the sum of digit factorials*/
int getSum(int number){
    int digitsum = 0;
    int tens = 1;
    for (int x = 0; x < numPlaces(number); x++){
        digitsum += factorials[number / (tens) % 10];
        tens *= 10;
    }
    return(digitsum);
}