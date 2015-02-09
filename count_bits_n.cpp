#include <stdio.h>

/*  Given a number N, tell if exists a number K so that sum of bits in all the numbers from 1 to K is equal to N.

    For n = 282657:
    Output: 38050.

    Sum of bits from 1 to 38050 = n */

typedef unsigned long long ULL;

ULL countSetBits(ULL n) {
    ULL ans = 0, log_val = 0, tmp = n;
    int i, x = 0;

    while (tmp >>= 1) ++log_val;

    /* 1LLU = shifting 1 to left by i and then converting it to unsigned long long. */
    for(i = log_val; i >= 0; --i)
        if(n & 1LLU << i)
            ans += ((1LLU << i) >> 1) * i + 1 + (1LLU << i) * x++;
    return ans;
}

void find_k(ULL n) {
    ULL l = 0, u = n+1, m;

    while(l != u) {
        m = (l + u ) / 2;
        if(countSetBits(m) >= n) u = m;
        else l = m + 1;
    }

    if(countSetBits(l) == n) printf("%llu\n",l);
    else printf("Does Not Exist.\n");
}

int main() {
    int t;
    ULL n;

    scanf("%d", &t);

    while(t--) {
        scanf("%llu", &n);
        find_k(n);
    }

    return 0;
}
