#include <stdio.h>
#include "isqrt.h"

int main(){
    unsigned long i, res;
    res = 0;
    for (i = 0; i < 200; i+= 8){
        res = isqrt(i);
        printf("isqrt(%lu) = %lu\n", i, res);
    }
    res = isqrt(200);
    printf("isqrt(200) = %lu", res);
    return 0;
}