#include <stdio.h>

unsigned char digit_count(unsigned long n){
    unsigned long i;
    if (n == 0)
        return 1;
    i = 0;
    while (n >= 1){
        n /= 10;
        i++;
    }
    return i;
}