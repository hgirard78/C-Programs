#include <stdio.h>
#include "power_of_two.h"

int main(){
    unsigned long i, res;
    for (i = 0; i < 63; i++){
        res = power_of_two(i);
        printf("power_of_two(%lu) = %lu\n", i, res);
    }
    res = power_of_two(63);
    printf("power_of_two(63) = %lu", res);
    return 0;
}
