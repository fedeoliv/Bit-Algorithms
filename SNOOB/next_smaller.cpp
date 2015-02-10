#include <stdio.h>

/*  Find a number immediately smaller than given, with same number of logic 1 bits. */

void nextsmall(int n) {
    if((n&(n+1)) == 0) {
        printf("Not possible.\n");
        return;
    }

    int a = 1;

    while(a&n) a <<= 1;
    while(!(a&n)) a <<= 1;
    n-=(a/2);

    printf("%d\n", n);
}

int main() {
    int n = 4, small;
    nextsmall(n);
}
