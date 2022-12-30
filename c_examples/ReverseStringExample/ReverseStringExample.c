/*
 * File:      ReverseStringExample.c
 * Copyright: James Hurst 2022
 * Purpose: Reverse a string in place
 *
 * gcc -Wall ReverseStringExample.c -o ReverseStringExample

 */

#include <stdio.h>

int main(void) {

    int i = 0;
    char string[] = {'s','t','r','i','n','g'}; // \0 null terminator is excluded in this example
    int k = sizeof(string) - 1;
    char tmp;

    for(i = 0; i < sizeof(string)/2; i++) {  // sizeof returns size of 'string' array in bytes
        tmp = string[i];
        string[i] = string[k];
        string[k] = tmp;
        k--;
    }

    /* Print out the result char by char */
    printf("The string is now:\n");
    for(i = 0; i < sizeof(string); i++) {
        printf("%c", string[i]);
    }

    return 0;
}
