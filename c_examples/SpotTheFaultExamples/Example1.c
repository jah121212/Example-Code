/*
 * File:      Example1.c
 * Copyright: James Hurst 2022
 * Purpose:   Explain what is happening here, is this a good idea?
 *            Will this even compile?
 *
 * gcc -Wall Example1.c -o Example1

 */

#include <stdio.h>

int main(void) {

    int array[] = {0,1,2,3,4,5,6,7,8,9};

    int index = 8;

    {
        int index = 5;
        printf("The value found in the array is %d\n", array[index]);
    }

    printf("The value found in the array is %d\n", array[index]);

    return 0;
}
