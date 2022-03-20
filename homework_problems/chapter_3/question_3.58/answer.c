#include <stdio.h>

long decode2(long x, long y, long z){
    long val;

    y = y - z;
    x = x * y;
    val = y;
    val = val << 63;
    val = val >> 63;
    val ^= x;
    return val;
}


int main(void){
    long x = 1;
    long y = 2;
    long z = 3;
    long result;

    result = decode2(x, y, z);
    printf("%ld\n", result);
    return 0;
}