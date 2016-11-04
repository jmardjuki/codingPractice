/* 
 * Date: 04 November 2016
 * Score: 100% Correctness, 100% Performance
 * Note: Same logic as python, but done to check out codility
 */

// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(int A[], int N) {
    // write your code in C99 (gcc 4.8.2)
    int arr[N];
    int i = 0;
    int value = 0;

    for ( i = 0; i < N; i++) {
        arr[i] = 1;
    }

    for ( i = 0; i < N; i++) {
        value = A[i] -1;
        if ( (value < N) && (arr[value]) != 0 ) {
            arr[value] = 0;
        }
        else {
            return 0;
        }
    }
    for ( i = 0; i < N; i++) {
        if (arr[i] != 0) {
            return 0;
        }
    }
    return 1;

}
