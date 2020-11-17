#include <stdio.h>
#include <stdbool.h>

_Bool isOdd(int x)
{
    if(x & 1){
        return true;
    }
    return false;
}



int main()
{
    printf("%d\n", isOdd(-3));
    printf("%d\n", isOdd(4));

    return 0;
}
