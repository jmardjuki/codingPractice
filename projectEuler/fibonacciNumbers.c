#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_FIBONACCI 4000000

_Bool isEven(long long number)
{
    if ( number % 2 == 0 ) {
        return true;
    }
    return false;

}

int main()
{
    long long first = 1;
    long long second = 2;
    long long temp = 0;
    long long sumEven = second;

    while (first < MAX_FIBONACCI) {
        temp = first + second;
        if ( isEven(temp) ) {
            sumEven += temp;
        }
        first = second;
        second = temp;
    }
    printf("%lld\n", sumEven);

    return 0;
}
