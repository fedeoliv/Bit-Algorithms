#include <stdio.h>
#include <math.h>

/*  Given a positive integer n, count the total number of set bits in all numbers from 1 to n.
    Input: n = 3
    Output:  4 */

int countSetBits(int n) {
    /*  N = Number
        log_val = stores the value of log2(N)
        count = no of ones */
	int log_val = 1, tmp = n, bitCount = 0;

	/* Calculates Log2(N) */
	while(tmp >>= 1) ++log_val;

	/* For each bit position , we calculate the total possible 1s possible.
	 * For Eg . For Ones place , there can be atmost (N+1)/2 Ones
	 * Similarly we calculate for Each bit Pos #Step 1
	 * Now Error Stores number of extra 1s :
	 * 		For Eg: In 2nd bit pos , there will be 2 twos in each set of
	 * 		4 integers ( starting from 0 ) . So in case of an incomplete set
	 * 		we find the reminder of 1s in it
	 *
	 * Now we add count + error to get the total for each bit pos
	 * */

	for(int i = 1; i <= log_val; i++) {
		bitCount = bitCount + ((n+1)/(1<<i))*(1<<(i-1));
		int error =  (n+1) - (((n+1)/(1<<i))*(1<<i)) - (1<<(i-1));
		if(error > 0 ) bitCount = bitCount + error;
	}

	return bitCount;
}

int main() {
    int n = 8;
    printf("%d\n", countSetBits(n));
	return 0;
}
