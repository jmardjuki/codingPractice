#
# Date: 04 November 2016
# Score: 100% Correctness, 100% Performance
# Time Complexity: O(N)
# Storage Complexity: O(N)
# Time used: 34 min
#

# you can write to stdout for debugging purposes, e.g.
# print "this is a debug message"

def solution(A):
    # write your code in Python 2.7
    sizeA = len(A)
    arr = [1] * sizeA

    i = 0
    while (i < sizeA):
        value = A[i]-1
        if ( value < sizeA) and (arr[value] != 0):
            arr[value] = 0
        else:
            return 0
        i = i + 1

    i = 0
    while ( i < sizeA):
        if (arr[i] != 0):
            return 0
        i = i + 1
    return 1
