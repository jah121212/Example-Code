/*
 * File:      Example3.c
 * Copyright: James Hurst 2022
 * Purpose:   Explain what is happening here?
 *            Will this even compile?
 *
 * gcc -Wall Example3.c -o Example3

 */

#include <stdio.h>

int main(void) {

    int a = 10;
    int b = 2;
    int *c = NULL;
    int d = 0;


    c = &b;

    d = a/*c;

    printf("The value of d is %d\n", d);

    return 0;
}

