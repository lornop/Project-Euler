/*
Circular Primes
Problem 35

The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.
There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.
How many circular primes are there below one million?

*/

/* Libraries */
#include <stdio.h>

/* Function Prototypes */

void allDone(int);
void foundOne(int);
int primecheck(int);
int circlecheck(int);


/* Globals */
int primesFound         = 0;
int count               = 2;
int maxCount            = 1000000;


int main()
{
    while(count < maxCount){
        count ++;
        if (primecheck(count) == 1){
            if (circlecheck(count) == 1){
                foundOne(count);
            }
        }
    }

    allDone(primesFound);
    return 0;
}

/* Found all the circular primes up to a million */
void allDone(int num){
    printf("Found this many circular primes: %d \n", num);
}

/* Found a circular Prime*/
void foundOne(int prime){
    printf("Circular Prime found! : %d \n", prime);
    primesFound++;

}

/* Check if an int is prime. Return 0 (no) or 1 (yes) */
int primecheck(int check){
    if (check <= 1) return 0;
    if (check == 2) return 1;
    if (check % 2 == 0) return 0;

    int num = 3;
    int limit = num * num;     // store the square once

    while (limit <= check) {
        if (check % num == 0){
            return 0;
        } 
        num += 2;               //Skip even numbers
        limit = num * num;      // update once each iteration
    }

    return 1;
}


/* Rearange number and send it to primecheck() Return 0 (no) or 1 (yes) */
int circlecheck(int num){
    int circle = 0;
    //Do some iteration stuff

    if (primecheck(num) == 1){
        circle = 1;
        //Go to next iteration
    }
    else {
        circle = 0;
        return circle;
    }

    return circle;
}

