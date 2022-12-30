/*
 * File:      BinaryChopExample.c
 * Copyright: James Hurst 2022
 * Purpose:   An example in C showing a binary chop.
 *            A binary chop can only be performed on an
 *            ordered list, in this example an ordered
 *            integer array is used.
 *            Locate the target value in the array if it exists.
 *
 * gcc -Wall BinaryChopExample.c -o BinaryChopExample

 */

#include <stdio.h>

static int binaryChop(int *array, int length, int target);

int main(void) {

    int target = 9;
    int index = 0;

    /* Ordered lists */
    int array10[] = {0,1,2,3,4,5,6,7,8,9};
    int array9[]  = {0,1,2,3,4,5,6,7,8,};


    index = binaryChop(array10, sizeof(array10)/sizeof(array10[0]), target);
    printf("Target %d for array10 found at index %d\n", target, index);

    index = binaryChop(array9, sizeof(array9)/sizeof(array9[0]), target);
    printf("Target %d for array9 found at index %d\n", target, index);

    return 0;
}

/*
 * Name:    binaryChop
 * Purpose: Search an integer array for the target value,
 *          if found return the index of the array at which the
 *          value has been located or -1 if the value is not in
 *          the list.
 */
static int binaryChop(int *pArray, int length, int target) {
    int topIndex      = length - 1;
    int bottomIndex   = 0;
    int midPointIndex = 0;
    int foundIndex    = -1;

    /* Iterate through the array until either the target has been located or
     * no further iterations can be performed.
     */
    while (topIndex >= bottomIndex) {
        midPointIndex = (bottomIndex + topIndex) / 2;  // or a >> 1 could be used to replace '/ 2'

        /* If target value has been located return the index */
        if (pArray[midPointIndex] == target) {
            foundIndex =  midPointIndex;
            break;
        }

        /* If the value at midPointIndex is less than the target value then
         * discard the bottom half else discard the top half.
         */
        if (pArray[midPointIndex] < target) {
            bottomIndex = midPointIndex + 1;
        } else {
            topIndex = midPointIndex - 1;
        }
    }

    return foundIndex;
}
