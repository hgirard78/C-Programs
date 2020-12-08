#include <stdio.h>

unsigned long divisor_sum(unsigned long n){
    unsigned long res = 0, i = 1;
    while (i <= n / 2){
        if (n % i == 0)
            res += i;
        i++;
    }
    return res;
}