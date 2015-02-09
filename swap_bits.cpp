#include<stdio.h>

/*  Given a number x and two positions (from right side) in binary representation of x,
    write a function that swaps n bits at given two positions and returns the result.

    Input:
    x = 47 (00101111)
    p1 = 1 (Start from second bit from right side)
    p2 = 5 (Start from 6th bit from right side)
    n = 3 (No of bits to be swapped)

    Output:
    227 (11100011) */

int swapBits(unsigned int x, unsigned int p1, unsigned int p2, unsigned int n) {
    /* xor contains xor of two sets */
    unsigned int xorValue = ((x >> p1) ^ (x >> p2)) & ((1U << n) - 1);

    /* To swap two sets, we need to again XOR the xor with original sets */
    return x ^ ((xorValue << p1) | (xorValue << p2));
}

int main() {
    printf("%d\n", swapBits(28, 0, 3, 2));
    return 0;
}
