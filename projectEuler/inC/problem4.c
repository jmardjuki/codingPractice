#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include <string.h>

#define BUFFER_SIZE 1024

/*************************************************************
 * isItPallindrome
 * Check if a string is a pallindrome
 * @params: char * string   : pointer to the string to be checked
 *          int length      : length of the string to be checked
 * @return: bool            : true if pallindrom, else false
 **************************************************************/
_Bool isItPallindrome(char * string, int length)
{
    int i = 0;
    int mid = length/2;

    // Base case
    if ( length%2 != 0) {
        return false;
    }
    
    // Go through the whole string until the mid
    for ( i = 0; i < mid; i++) {
        if ( string[i] != string[length-1-i]) {
            return false;
        }
    }
    return true;
}

/*************************************************************
 * convertToString
 * Covert the given number into string, and return the length of the string
 * @params: char * string   : buffer string for the charcter converted
 *          int number      : number to be converted into string
 * @return: int             : length of the string converted         
 *************************************************************/
int convertToString(char * string, int number)
{
    int remain = 0;
    int len = 0;
    int i = 0;
    int mid = 0;

    char temp;

    // Go through the number
    while ( number != 0 ) {
        remain = number%10;
        string[len] = '0' + remain;
        number = number-remain;
        number = number/10;
        len++;
    }
    
    mid = len/2;

    // Flip the string
    for ( i = 0; i < mid; i++) {
        temp = string[i];
        string [i] = string[len-1-i];
        string[len-1-i] = temp;
    }   

    return len;
}


///////////
//  MAIN
//////////  
int main(void)
{
    int i = 100, j = 100;
    int largestPal = 0;
    int temp = 0;

    // Test convertToString   
    char stringBuff[BUFFER_SIZE];
    int len = convertToString(stringBuff,123456);
    
    assert(strcmp("123456", stringBuff) == 0);
    assert(len == 6);
    

    // Test isItPallindrome function
    assert(isItPallindrome("aa", 2) == 1);
    assert(isItPallindrome("aba", 3) == 0);
    assert(isItPallindrome("9009", 4) == 1);

    // Generate the numbers, and find the largest palindrome
    // !Brute force
    for ( i = 0; i < 999; i++) {
        for ( j = 0; j < 999; j++) {
            temp = i*j;
            len = convertToString(stringBuff,temp);
            if ( (isItPallindrome(stringBuff, len)) && (temp > largestPal)) {
                largestPal = temp;
            }
        }
    }
    
    printf("%d\n", largestPal);

    return 0;
}
