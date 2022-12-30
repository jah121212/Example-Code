/*
 * File:      Example2.c
 * Copyright: James Hurst 2022
 * Purpose: Can you spot any problem with this code?
 *          Explain what is happening here?
 *          Will this compile and execute?
 *
 * gcc -Wall Example2.c -o Example2

 */

#include <stdio.h>

static int* function1(void);
static int* function2(void);

int main(void) {

    int *ptr = NULL;

    ptr = function1();
    printf("The value found in the array is %d\n", *(ptr + 10));

    return 0;
}

static int* function1() {
    int array[] = {0,1,2,3,4,5,6,7,8,9};
    return array;
}

/* Could the call to function1 be replaced by function2 in main() */
/* Would there be any issues with doing this?
 */
static int* function2() {
    static int array[] = {0,1,2,3,4,5,6,7,8,9};
    return array;
}
