#include<stdio.h>

/* Function to get number of set bits in binary representation. */
int countSetBits(int n) {
    unsigned int count = 0;
    while(n) {
        n &= (n-1);
        count++;
    }
    return count;
}

int main() {
    int i = 15;
    printf("%d\n", countSetBits(i));
    return 0;
}
