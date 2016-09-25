/*********************************************************
 *  File Name: reverseString.c
 *  Description: Quick implementation of reverse string in C
 *
 *  Created by: Janet Mardjuki
 *  Year: 2015
 ********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*** GLOBAL VARIABLES AND DEFINITIONS ***/
#define DA_STRING "Hello"


/*** FUNCTIONS IMPLEMENTATION ***/

/**
 *  reverseString
 *  Revesre the given string
 *  @params:
 *      char * str: Ponter to the char array containing  string
 */
void reverseString(char * str)
{
    int length = strlen(str);
    int midPos = (int)(length/2);
    char temp;

    for ( int i = 0; i < midPos; i++) {
        temp = str[i];
        str[i] = str[length-i-1];
        str[length-i-1] = temp;
    }

    return;
}

/*** MAIN ***/
int main()
{
    char string[1024] = DA_STRING;
    reverseString(string);
    printf("%s\n", string);

    return 0;
}
