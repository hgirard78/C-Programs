#include <stdio.h>
#include "digit_count.h"

int main(){
    unsigned long res, i, n;
    i = 1;
    res = digit_count(0);
    printf("digit_count(0) = %lu\n", res);
    for (n = 0; n <= 62; n++){
        res = digit_count(i);
        printf("digit_count(%lu) = %lu\n", i, res);
        i *= 2;
    }
    res = digit_count(i);
    printf("digit_count(%lu) = %lu",i, res);
    return 0;
}
