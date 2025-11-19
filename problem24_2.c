/*
A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4.
If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. 
The lexicographic permutations of 0, 1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>


void add_permutation();
void print_permutation();
int checkdigits(uint64_t);


//Globals

uint64_t
million                 = 1000000,
permutation_count       = 0,
counter = 123456789;

int main(){
	while(1){
		if (checkdigits(counter) == 1){
			add_permutation();
			counter++;		
		}

		if (checkdigits(counter) == 0){
			counter++;		
		}
		
	}

}



//**************************************************************
int checkdigits(uint64_t number){
	//Trying something new
	//Going to check every digit and see if they are the same or not. Return 1 if they are differnt
	//which means its a new permutation. Return 0 if its they are some the same and its not a new permutation
	//then just increment the counter. Brute Force this MF



	int singledigits[10];
	int check = 0;

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

	while(check < 10){
		for(int x = (check +1); x < 10; x++){
			if(singledigits[check] == singledigits[x]){
				return(0);
				break;

			}
			
		}
		check++;
		
	}
	return(1);
}



//*Add One to the total Number of Permutations*********************************************
void add_permutation()
{
	permutation_count++;
	if (permutation_count == million){
		print_permutation();
	}
}

//*If the Total permutations is a million, stop and print it out*********************************************
void print_permutation()
{
	//If we are all done print out the millionth permutation
	printf("The %d th Permutation is : ", million);
	printf("%" PRIu64 "\n", counter);

    exit(0);
}