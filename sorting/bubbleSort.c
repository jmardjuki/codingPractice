/***********************************************************
 *  File name: bubbleSort.c
 *  Description: Quick implementation of bubble sort
 *  -------------------------------------------------------
 *  Created by: Janet Mardjuki
 *  Date: 18 November 2015
 *
 ***********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*** FUNCTIONS DECLARATION ***/
/**
 *  bubbleSort
 *  Sort the array using bubble sort 
 *  @params:
 *      int * arr:  pointer array containing the elements to be sorted
 *      int size :  the array size
 */
void bubbleSort(int * arr, int size)
{
    int tmp = 0;
    _Bool swapped = true;
    while ( swapped ){
        swapped = false;
        for( int i=0; i < size; i++ ){
            if( arr[i-1] > arr[i] ){
                int tmp=arr[i-1];
                arr[i-1]=arr[i];
                arr[i]=tmp;
                swapped = true;
            }
        }
    }
    return;

}


/*** MAIN ***/
int main ()
{
    // Declare the size and initial array
    int size = 6;
    int arr[] = {3, 4, 1, 0, 2, 5};
    bubbleSort(arr, size);

    // Print the array
    for ( int i = 0; i < size; i++) {
        printf("%d\n", arr[i]);

    }   
    
    return 0;

}
