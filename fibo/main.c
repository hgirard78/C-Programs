#include <stdio.h>
#include "fibo.h"

int main(){
    unsigned long i, res;
    res = 0;
    for (i = 0; i <= 89; i++){
        res = fibo(i);
        printf("fibo(%lu) = %lu\n", i, res);
    }
    res = fibo(90);
    printf("fibo(%d) = %lu", 90, res);
    return 0;
}