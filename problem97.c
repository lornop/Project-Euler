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
void printAnswer(int64_t);
int64_t square(int64_t);
int64_t chopper(int64_t);

/* Globals */
int64_t primeNumber = 0;
int64_t squares[25];


int main()
{
    int thefactor = 28433;
    int maxexponent = 7830457;
    squares[0] = 0;
    squares[1] = 2;

    for (int x = 2; squares[x] < maxexponent; x++){
        squares[x] = square(squares[x-1]);
    }

    
return 0;
}

/* We got the answer, now print it */
void printAnswer(int64_t answer){
    printf("The last ten digits are: %d\n", answer);
    
}

/* Input a number and square it */
int64_t square(int64_t num){
    int64_t answer = num * num;
    answer = chopper(answer);
    return answer;
}


/* Chop the number down to 10 digits */
int64_t chopper(int64_t number){
    int64_t chopped = number % 10000000000LL;
    return chopped;

}