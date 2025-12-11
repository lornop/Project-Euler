/*
Goldbach's Other Conjecture
Problem 46
It was proposed by Christian Goldbach that every odd composite number can be written as
the sum of a prime and twice a square.

9  = 7  + 2 × 1²
15 = 7  + 2 × 2²
21 = 3  + 2 × 3²
25 = 7  + 2 × 3²
27 = 19 + 2 × 2²
33 = 31 + 2 × 1²

It turns out that the conjecture was false.

What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?
*/

/* Libraries */
#include <stdio.h>

/* Function Prototypes */

int primecheck(int);
int composite(int);
void gotit(int);

/* Globals */
int primes[];
int numofprimes = 0;


int main()
{
    int number = 1;
    while(1){
        number ++;
        if (number % 2 == 0){
            continue;
        }
        else if (primecheck(number) == 1){   //If the number is prime
            primes[numofprimes] = number;
            numofprimes++;
        }
        else{
            if (composite(number) == 0){
                gotit(number);
                return 0;
            }
            continue;
        } 
    }

return 0;
}

/* Do the composite thing. take a prime, add 2* a square. If its equal to the 
number return 1. If its not, return 0 */
int composite(int num){
    int primenumber = 0;
    int square = 2;

    while (primenumber <= numofprimes){
        for (square; (square * square) < num; square++){
            if (num == (primes[primenumber] + (2 * (square * square)))){
                return 1;
            }
        }
        square = 2;
        primenumber++;
    }
    return 0;
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

/* Got the smallest composite */
void gotit(int num){
    printf("The smallest composite this doenst work for is: %d \n", num);
}

