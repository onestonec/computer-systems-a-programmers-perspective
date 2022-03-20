#include <stdio.h>

union ele{
    struct {
        long *p;
        long y;
    } e1;
    struct {
        long x;
        union ele *next;
    } e2;
};

int main()
{
    union u1;
    return 0;
}