#include <stdio.h>

long cread(long *xp){
    return (xp ? *xp : 0);
}


int main(void){
    long *xp = NULL;
    printf("%ld", cread(xp));
    return 0;
}