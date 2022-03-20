#include <stdio.h>

int func4(int x, int y, int z){
    int val = z - y;
    int val2 = val;
    val2 >>= 31;
    val += val2;
    val >>= 1;
    val2 = val + y;

    if (val2 > x){
        val = func4(x, y, val2 - 1);
        val += val;
    } else {
        val = 0;
        if (val2 < x){
            val = func4(x, val2+1,z);
            val = 2*val + 1;
        }
    }
    return val;
}

int main(){

    for (int i = 0; i <= 14; i++)
    {
        int val = func4(i, 0, 14);

        if (val == 0)
        {
            printf("%d\n", i);
        }    
    }

    return 0;
}