/*
Number Letter Counts 
Problem 17

If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3+3+5+4+4=19 letters 
used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters
and 115 (one hundred and fifteen) contains 20 letters. 
The use of "and" when writing out numbers is in compliance with British usage.
*/


#include <stdio.h>
#include <string.h>

/* FUNCTION PROTOTYPES */
int GetSize(int);
void ParseNumberToArray(int);
int DigitToCount(void);



/* GLOBALS */
int number              = 1;
int count               = 0;
int singledigits[4]        ;

int main()
    {while(number <= 1000){
        ParseNumberToArray(number);
        count += DigitToCount();
        number++;
    }
    printf("The number of letters is: %d \n", count);
    return 0;
}

/* FUNCTIONS */
//Enter an int and get an int for the number of letters in
int GetSize(int numeral){
    switch (numeral)
    {
    case 100:
        return(7);  //hundred
        break;
    case 1000:
        return(8);  //thousand
        break;
    case 1:
        return(3);
        break;
    case 2:
        return(3);
        break;
    case 3:
        return(5);
        break;
    case 4:
        return(4);
        break;
    case 5:
        return(4);
        break;
    case 6:
        return(3);
        break;
    case 7:
        return(5);
        break;
    case 8:
        return(5);
        break;
    case 9:
        return(4);
        break;
    case 10:
        return(strlen("ten"));
        break;
    case 11:
        return(strlen("eleven"));
        break;
    case 12:
        return(strlen("twelve"));
        break;
    case 13:
        return(strlen("thirteen"));
        break;
    case 14:
        return(strlen("fourteen"));
        break;
    case 15:
        return(strlen("fifteen"));
        break;
    case 16:
        return(strlen("sixteen"));
        break;
    case 17:
        return(strlen("seventeen"));
        break;
    case 18:
        return(strlen("eighteen"));
        break;
    case 19:
        return(strlen("nineteen"));
        break;
    case 20:
        return(strlen("twenty"));
        break;
    case 30:
        return(strlen("thirty"));
        break;
    case 40:
        return(strlen("forty"));
        break;
    case 50:
        return(strlen("fifty"));
        break;
    case 60:
        return(strlen("sixty"));
        break;
    case 70:
        return(strlen("seventy"));
        break;
    case 80:
        return(strlen("eighty"));
        break;
    case 90:
        return(strlen("ninety"));
        break;

        
    default:
        break;
    }

}

//Take the number and convert each digit to an array element
void ParseNumberToArray(int number){

    singledigits[0] = number / 1000 % 10;
	singledigits[1] = number / 100 % 10;
	singledigits[2] = number / 10 % 10;
	singledigits[3] = number / 1 % 10;
}

//Start going through the array elements and count up letters and return the result
int DigitToCount(){
    int total =0;

    if(singledigits[0] != 0){   //Thousands digit
        total += GetSize(singledigits[0]);
        total += GetSize(1000);

    }

    if(singledigits[1] != 0){   //Hundreds digit
        total += GetSize(singledigits[1]);
        total += GetSize(100);

    }

    if(singledigits[2] != 0){   //Tens and teens digits
        if(singledigits[2] > 1){                        //twenty, thirty etc...
            total += GetSize((singledigits[2]) * 10 );  
            total += GetSize(singledigits[3]);          //one, two etc...
        }

        if(singledigits[2] == 1){                       //tens and teens
            total += GetSize( (10 + singledigits[3]) );

        }
        
    }
    if((singledigits[3] != 0) && (singledigits[2] == 0)){                       //ones
        total += GetSize(singledigits[3]);

    }

    if( (singledigits[0] || singledigits[1]) != 0){
        if( (singledigits[2] || singledigits[3]) != 0){
            total += 3;                                             //and
        }
        
    }


    return (total);
}
