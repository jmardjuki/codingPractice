#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TO_FIND 600851475143

_Bool isItPrime(unsigned long long numToCheck)
{
    unsigned long long i = 0;
    // Skip 1
    if ( numToCheck == 1 ) {
        return false;
    } 
    for ( i = 2; i*i <= numToCheck; i++) {
        if ( numToCheck % i == 0 ) {
            return false;
        }
    }
    return true;

}

int main()
{
    unsigned long long i = 0;
    unsigned long long daNumber = TO_FIND;
    unsigned long long largestNumber = 0;
 
    for (i = 2; i < daNumber ; i++) {
        if ( isItPrime(i) ) {
            if ( daNumber % i == 0 ) {
                largestNumber = i;
                daNumber = (unsigned long long)(daNumber/i); 
            }
        }
    }
    if ( daNumber > largestNumber ) {
        largestNumber = daNumber;
    }
    printf("%lld\n", largestNumber);

    return 0;
}
