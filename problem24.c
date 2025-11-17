/*
A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4.
If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. 
The lexicographic permutations of 0, 1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
*/

#include <stdio.h>
#include "problem24.h"
//**********************************************

//Functions
//int find_same_number_index(int, int);
//int add_permutation(int);



//Global Variables

__int32_t
million 				= 1000000,
permutation_count 		= 1,
digits[10] 				= {0,1,2,3,4,5,6,7,8,9},
permutation_array[10] 	= {0,1,2,3,4,5,6,7,8,9},
permutation_index 		= 9,
test_placeholder		= 0;

//**********************************************
//Start the Main loop

int main()
{
	
	while (permutation_count <= million)
	{
	__int32_t 
	temp_number_index,
	lowest_number_index;
		

		if ( (permutation_array[permutation_index] + 1) <= 9)
		{
			//find the indexes of swapping numbers
			temp_number_index = find_same_number_index((permutation_array[permutation_index] + 1), permutation_index + 1);
			//then swap them
			swap_digits_with_indexes(permutation_index, temp_number_index);

			//Run the algorithm to sort out the permutation
			do_Permutation(permutation_index);
			add_permutation();

		}
		
		else
		{
			permutation_index --;
		}

		if( (permutation_count >= million) || (permutation_index < 0) )
		{
			print_permutation();
			return 0;
		}



	}
	
	print_permutation;
	return 0;

}


// //Find array element that has the same number as the 
// int find_same_number_index(int x, int y){

// }

// //Add one to the total permutation count and return the new count
// int add_permutation(int permutation){
// 	permutation++;
// 	if (permutation == million){
// 		printf("The millionth Permutaion is = ");
// 		for (int x = 0; x < 10; x ++){
// 			printf(permutation_array[x]);
// 			exit(0);
// 		}
// 	}

// return permutation;

// }

