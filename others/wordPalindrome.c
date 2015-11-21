/*********************************************************
 *  File Name: wordPalindrome.c
 *  Description: Check if a string is pallindrome
 *-------------------------------------------------------
 *  Created by: Janet Mardjuki
 *  Date: 
 *********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

/*** GLOBAL VARIABLES ***/
#define DA_PALINDROME "madam"
#define DA_GARBAGE "dimsum"


/*** FUNCTIONS DECLARATION ***/

/**
 *  isItPalindrme
 *  Check whether a word is a palindrom word
 *  @params:
 *      const char * word: word to be checked if its palindrome
 */
_Bool isItPalindrome(const char * word)
{
    int size = strlen(word);
    for ( int i = 0; i < size/2 + 1; i++ ) {
        if ( (word[i]) != (word[size-1-i]) ) {
            return false;      
        }
    }
    return true;
}

int main(void)
{
    char string1[1024] = DA_PALINDROME;
    _Bool result = isItPalindrome(string1);  
    assert(result == true);
       
    char string2[1024] = DA_GARBAGE;
    result = isItPalindrome(string2);  
    assert(result == false);

    return 0;
}
