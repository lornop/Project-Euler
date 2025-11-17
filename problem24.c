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
// //Run The Permutation
// void do_Permutation(__int32_t high_index);

// //Add another permutation to the total
// void add_permutation();

// //Find the same numbers index. input is the number, and the starting index. Returns Index
// __int32_t find_same_number_index(__int32_t, __int32_t);

// //print the digits of the permutation
// void print_permutation();

// //Swap digits based on the input indexes
// void swap_digits_with_indexes(__int32_t, __int32_t);

// //Find the lowest number in the array Starting Number, Starting Index. Returns index of lowest number
// __int32_t find_lowest_number(__int32_t, __int32_t);




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



