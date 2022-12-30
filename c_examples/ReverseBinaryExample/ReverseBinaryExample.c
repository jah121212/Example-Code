/*
 * File:      ReverseBinaryExample.c
 * Copyright: James Hurst 2022
 * Purpose:   An example in C showing the reversal of the
 *            Bits in a Byte
 *
 * gcc -Wall ReverseBinaryExample.c -o ReverseBinaryExample

 */

#include <stdio.h>

#define BYTE_SIZE 8

int main(void) {

    unsigned char input  = 0x0c;
    unsigned char output = 0x00;

    int i = 0;
    int k = BYTE_SIZE - 1;
    unsigned char mask = 0x00;
    unsigned char tmp  = 0x00;

    printf("ReverseBinaryExample\n");

    /* Mask and shift */
    for(i=0; i<BYTE_SIZE; i++) {
        /* The mask is 1 shifted by by the index */
        mask = 0x01 << i;
        tmp = input & mask;
        /* Move to LSB */
        tmp = tmp >> i;
        /* Write to new location */
        output |= (tmp << k);

        k--;
    }

    printf("Input : 0x%.2x\n", input);
    printf("Output: 0x%.2x\n", output);

    return 0;
}