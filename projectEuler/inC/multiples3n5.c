#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_NUMBER 1000

int main()
{   
    // O(n) solution   
    int i = 0,
        sum = 0;

    for ( i = 0; i < MAX_NUMBER; i++) {
        if ( i%3 == 0 || i%5 == 0 ) {
            sum += i;
        }
    }
    printf("%d\n", sum);

    
}
