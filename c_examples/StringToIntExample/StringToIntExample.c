/*
 * File:      StringToIntExample.c
 * Copyright: James Hurst 2022
 * Purpose: We could just use strtol(), but this is an example
 *          of converting a string to an int manually.
 *
 * gcc -Wall StringToIntExample.c -o StringToIntExample

 */

#include <stdio.h>
#include <string.h>

static int stringToInt(char *str);

int main(void) {

    char string[] = "123456";
    int output;

    output = stringToInt(string);
    printf("Output: %d\n", output);

    return 0;
}

/*
 * Name:    stringToInt
 * Purpose: Convert a string to an integer value.
 */
static int stringToInt(char *string) {
    int tmp = 0;
    for (int i = 0; i < strlen(string); i++) {
        /* subtract '0' from ASCII code to convert to integer */
        int digit = (string[i] - '0');
        tmp = (tmp * 10) + digit;
    }

    return tmp;
}
