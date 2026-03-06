/*
Large Non-Mersenne Prime
Problem 97

The first known prime found to exceed one million digits was discovered in 1999, and is a Mersenne prime of the form 2^6972593 − 1; 
it contains exactly 2,098,960 digits. Subsequently other Mersenne primes, of the form 2^p − 1, have been found which contain more digits.

However, in 2004 there was found a massive non-Mersenne prime which contains 2,357,207 digits:
28433 × 2^7830457 + 1.

Find the last ten digits of this prime number.
*/

/* Libraries */
#include <stdio.h>
#include <stdint.h>

/* Function Prototypes */
void printAnswer(__int128_t);
__int128_t square(__int128_t);
__int128_t chopper(__int128_t);

/* Globals */


int main()
{
    __int128_t primeNumber = 0;
    int thefactor = 28433;
    __int128_t maxexponent = 7830457;
    __int128_t exponent = 0;
    __int128_t exponentRemainder = 0;
    __int128_t prodOfSquares = 1;
    __int128_t squareVal = 1;


    exponentRemainder = maxexponent;

    while(exponentRemainder > 0){


        squareVal = 2;
        for (exponent = 1; (exponent * 2) < exponentRemainder; exponent *= 2){
            squareVal = square(squareVal);
        }

        prodOfSquares = chopper(prodOfSquares * squareVal);

        exponentRemainder = exponentRemainder - exponent;

    }

primeNumber = chopper(prodOfSquares * thefactor);
primeNumber++;
printAnswer(primeNumber);

return 0;
}

/* We got the answer, now print it */
void printAnswer(__int128_t answer){
    printf("The last ten digits are: %lld\n", answer);
    
}

/* Input a number and square it */
__int128_t square(__int128_t num){
    __int128_t answer = num * num;
    __int128_t ans = chopper(answer);
    return ans;
}


/* Chop the number down to 10 digits */
__int128_t chopper(__int128_t number){
    __int128_t chopped = number % 10000000000LL;
    return chopped;

}