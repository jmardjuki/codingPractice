#include <stdio.h>
#include <string.h>

#define daString "543210"

/**
 *  atoi
 *  Convert strings of number into integer
 *  @params:
 *      const char * string = strings of number to be converted to integer
 *  @returns:
 *       int: converted integer from string
 */
int atoi(const char * string)
{
    int temp = 0;
    int number = 0;
    int size = strlen(string);

    for ( int i = 0; i < size; i++) {
        number *= 10;
        number += (int)(string[i] - '0');
    }
    return number;
}

/*** MAIN ***/
int main()
{
    char buffer[1024];
    strcpy(buffer, daString);
    int result = atoi(buffer);
    printf("%d\n", result);
    return 0;
}
