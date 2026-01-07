/*
Reciprocal Cycles
Problem 26
A unit fraction contains 1 in the numerator. The decimal representation 
of the unit fractions with denominators 2 to 10 are:

1/2 = 0.5
1/3 = 0.(3)
1/4 = 0.25
1/5 = 0.2
1/6 = 0.1(6)
1/7 = 0.(142857)
1/8 = 0.125
1/9 = 0.(1)
1/10 = 0.1

Here, 0.1(6) means 0.166666… and has a 1-digit recurring cycle. 
It can be seen that 1/7 has a 6-digit recurring cycle.

Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
*/

/* Libraries */
#include <stdio.h>

/* Function Prototypes */

void printresult (int, int);
int longdivision (int);

/* Globals */

int main()
{
    /* Variables */
    int max = 1000;     //The largest value of d we are seaching to
    int d = 2;          //Current value of d
    int digits = 0;     //Number of digits for the current d
    int maxd = 0;       //The value of d with the most digits
    int maxdigits = 0;  //Number of digits for the longest d
    

    /* Main Loop */
    while (d < max){
        //digits = longdivision(d);
        digits = cycle_length(d);

        if (digits > maxdigits){
            maxd = d;
            maxdigits = digits;
        }
        d++;
    }

    printresult (maxd, maxdigits);
    return 0;
}


/*  Print out the resulting denominator and how many digits it was 
    printresult(result, length);  */
void printresult (int result, int length){
    printf("\nThe longest cycle is for 1/%d and it is %d digits long.\n", result, length);
}


/*  Take the number and do long division. Return how many digits the quotient is 
    length longdivision(d);  */
int longdivision(int number){
    int position = 0;
    int x = 10;
    int quotientarray[999][2];

    while(1){
        
        //If the number and remainder are 0
        if((x == 0) && (quotientarray[position][0] == 0)){
            return 0;
        }

        //If the remainder is < number
        if((x < number) && (x != 0)){
            x *= 10;
            quotientarray[position][0] = 0;
            quotientarray[position][1] = 0;
            position++;
        }
        

        //If the remainder is > number
        if(x >= number){
            quotientarray[position][0] = x / number;
            quotientarray[position][1] = x % number;
            x = quotientarray[position][1] * 10;
        

            //Do some checking
            for (int length = 0; length < position; length++){
                if(quotientarray[length][0] == quotientarray[position][0]){
                    if (quotientarray[length][1] == quotientarray[position][1]){
                        return position - length;
                    }
                }
            }
            //Add a position. We need to initialize the next resouce in the array, or its the last value still. 
            position++;
            quotientarray[position][0] = 0;
            quotientarray[position][1] = 0;
        }   
    }
}


int cycle_length(int d)
{
    int seen[1000];     // seen[r] = the position where remainder r was first seen
    int remainder;
    int position = 0;

    // Mark all remainders as "not seen yet"
    for (int i = 0; i < d; i++)
    {
        seen[i] = -1;
    }

    remainder = 1 % d;

    // Keep dividing until remainder repeats or becomes 0
    while (remainder != 0 && seen[remainder] == -1)
    {
        seen[remainder] = position;        // remember where we saw this remainder
        remainder = (remainder * 10) % d;  // do next step of long division
        position++;
    }

    // If remainder becomes 0, decimal terminates → no repeating cycle
    if (remainder == 0)
    {
        return 0;
    }

    // Otherwise, we found a repeated remainder → calculate cycle length
    return position - seen[remainder];
}
