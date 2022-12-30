/*
 * File:      IntToStringExample.c
 * Copyright: James Hurst 2022
 * Purpose: We could just use itoa(), but this is an example
 *          of converting a int to a string manually.
 *
 * gcc -Wall IntToStringExample.c -o IntToStringExample

 */

#include <stdio.h>
#include <string.h>

#define MAX_STRING_LEN 20

static void intToString(char *string, int number);

int main(void) {

    char string[MAX_STRING_LEN];
    int input = 123456;

    intToString(string, input);
    printf("Output string is: %s\n", string);

    return 0;
}

/*
 * Name:    intToString
 * Purpose: Convert an integer value to a string.
 */
static void intToString(char *string, int number) {
    int i         = 0;
    int n         = 0;
    int remainder = 0;
    int length    = 0;

    n = number;
    while (n != 0) {
        length++;
        n /= 10;
    }

    for (i = 0; i < length; i++) {
        remainder = number % 10;
        number /= 10;
        string[length - (i + 1)] = remainder + '0';
    }
    string[length] = '\0';
}
