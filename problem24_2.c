/*
A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4.
If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. 
The lexicographic permutations of 0, 1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
*/
#include <stdio.h>
#include <stdlib.h>


void DoPermutation(__int32_t element);
__int32_t find_lowest_number(__int32_t number, __int32_t index);
void swap_digits_with_indexes(__int32_t first_index, __int32_t second_index);
void add_permutation();
void print_permutation();


//Globals
__int32_t
million                 = 1000000,
permutation_count       = 0,
permutation_array[10]   = {0,1,2,3,4,5,6,7,8,9},
permutations_per_digit  = 0,
arrayindex              = 10,
workingindex            = 9,
counter = 123456789;




int main(){
    while (workingindex >= 0){
		DoPermutation(workingindex);
		if (permutation_array[workingindex] == 9){
			workingindex--;
			swap_digits_with_indexes(workingindex, 9);
			
		}
        
    }
    
    


return 0;
}


//**************************************************************
void DoPermutation(__int32_t element){
    
    //If we have sorted to the last digit, then we are done and can add one to the permutation
    if (element > 9){
        add_permutation();
		
    }

    if (element < 9){

              
		DoPermutation(element +1);
    }

	if (element == 9){
		DoPermutation(element +1);
	}

}



//*find the a lower nunber in the array than the number entered. returns the index of the lowest number******
__int32_t find_lowest_number(__int32_t number, __int32_t index)
{
	__int32_t low_num_index = index;
	for (index; index <=9; index++)
	{
		if (permutation_array[index] < number)
		{
			number = permutation_array[index];
			low_num_index = index;
		}
	}
	return low_num_index;
}

//*Swap two digits in the array around based on their indexs*********************************************
void swap_digits_with_indexes(__int32_t first_index, __int32_t second_index)
{
	__int32_t
	first_digit = permutation_array[first_index],
	second_digit = permutation_array[second_index];

	permutation_array[second_index] = first_digit;
	permutation_array[first_index] = second_digit;

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
	printf("The %d th Permutation is : ", permutation_count);
	for (int i = 0; i < 10; i++)
	{
		printf("%d", permutation_array[i]);
	}
	printf("\n");
    exit(0);
}