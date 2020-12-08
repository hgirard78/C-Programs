#include <stdio.h>
#include "divisor_sum.h"

int is_perfect_number(unsigned long n){
    if (divisor_sum(n) == n)
        return n;
    else
        return 0;
}