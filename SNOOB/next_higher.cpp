#include <stdio.h>
typedef unsigned int uint;

/*  Given a number x, find next number with same number of 1 bits in it’s binary representation.
    For example, consider x = 12, whose binary representation is 1100 (excluding leading zeros on 32 bit machine).
    It contains two logic 1 bits. The next higher number with two logic 1 bits is 17 (10001).*/

uint snoob(uint x) {
    uint rightOne;
    uint nextHigherOneBit;
    uint rightOnesPattern;
    uint next = 0;

    if(x) {
        rightOne = x & -(signed)x;  /* Right most set bit */

        /* Reset the pattern and set next higher bit left part of x will be here */
        nextHigherOneBit = x + rightOne;
        rightOnesPattern = x ^ nextHigherOneBit;
        rightOnesPattern = (rightOnesPattern)/rightOne;
        rightOnesPattern >>= 2;
        next = nextHigherOneBit | rightOnesPattern;
    }

    return next;
}

int main() {
  int x = 12;
  printf("%u\n", snoob(x));
  return 0;
}
