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
int circlecheck(int);   //This one is big
int numPlaces(int);
int factorial(int);
void singledigits(int, int);
int digitsToInt(int);


/* Globals */
int primesFound         = 0;
int count               = 2;
int maxCount            = 1000000;
int digits[6];


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
    
    while ((num * num) <= check) {
        if (check % num == 0){
            return 0;
        } 
        num += 2;               //Skip even numbers
    }

    return 1;
}


/* Rearange number and send it to primecheck() Return 0 (no) or 1 (yes) */
int circlecheck(int num){
    int circle = 0;
    int check  = 0;
    int numDigits = numPlaces(num);
    int combos = factorial(numDigits) - 1;  //We have one already, its the one that got us in here
    singledigits(num, numDigits);           //break it into digits, and store in the array
    for (int x = numDigits; x >= 0; x--){   //if theres any even numbers, its not going to work
        if (digits[x] % 2 == 0) return 0;
    }

    //Do some iteration stuff
    for (combos; combos >= 0; combos--){
        //I need to do some combo stuff????


        if (primecheck(digitsToInt(numDigits)) == 1){
            circle = 1;
            //Go to next iteration
        }
        else {
            circle = 0;
            return circle;
        }
    }

    return circle;
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

/* Get Factorial for number of combinations we have to check */
int factorial(int x){
    int y = 1;
    for (x; x > 0; x--){
        y *= x;
    }
    return y;
}

/* Break a number into its digits and store in an array digits[6] */
void singledigits(int num, int x){
    int y = 1;
    for (x; x >= 0; x --){
        digits[x] = num / y % 10;
        y *= 10;
    }
}

/* Turn the array back into a normal int, input is numDigits */
int digitsToInt(int x){
    int y = 0;
    int z = 1;
    for (x; x >= 0; x--){
        y = digits[x] * z;
        z *= 10;
    }
    return y;
}
