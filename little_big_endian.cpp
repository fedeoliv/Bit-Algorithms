#include <stdio.h>

/*  Little and big endian are two ways of storing multibyte data-types (int, float, etc).
    In little endian machines, last byte of binary representation of the multibyte data-type is stored first.
    On the other hand, in big endian machines, first byte of binary representation of the multibyte data-type
    is stored first.*/

/* function to show bytes in memory, from location start to start+n*/
void show_bytes(char *start, int n) {
    for(int i = 0; i < n; i++)
         printf("%.2x ", start[i]);
    printf("\n");
}

/* Verify if a number is little or big endian */
void endianess(unsigned int n) {
    char *c = (char*)&n;

    if(*c) printf("Little endian\n");
    else printf("Big endian\n");
}

/*  Convert from one to other endianness */
int rev_endianness(int num) {
    int byte0, byte1, byte2, byte3;
    byte0 = (num & 0x000000FF) >> 0 ;
    byte1 = (num & 0x0000FF00) >> 8 ;
    byte2 = (num & 0x00FF0000) >> 16 ;
    byte3 = (num & 0xFF000000) >> 24 ;
    return((byte0 << 24) | (byte1 << 16) | (byte2 << 8) | (byte3 << 0));
}

int main() {
    int n = 0x01234567;
    show_bytes((char *)&n, sizeof(n));
    endianess(n);

    printf("\n");
    int x = rev_endianness(n);
    printf("%d\n", x);
    show_bytes((char *)&x, sizeof(x));
    return 0;
}
