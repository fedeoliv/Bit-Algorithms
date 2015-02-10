#include <stdio.h>

/*  Given two numbers A and B, count number of bits needed to be flipped to convert A to B.
    A  = 1001001
    B  = 0010101
    a_xor_b = 1011100
    Number of bits needed = set bit count in a_xor_b = 4 */

int count_bit(int a,int b) {
    int c = a^b;
    int count = 0;

    while(c != 0) {
        c &= (c-1);
        count++;
    }
    return count;
}

int main() {
    int a = 3, b = 2;
    printf("%d\n", count_bit(a, b));

}
