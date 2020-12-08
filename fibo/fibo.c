#include <stdio.h>

unsigned long fibo(unsigned long n){
    if (n == 0 || n == 1)
        return n;

    unsigned long i, nbr1 = 0, nbr2 = 1, next;

    for (i = 0; i < n; i++){
        next = nbr1 + nbr2;
        nbr1 = nbr2;
        nbr2 = next;
    }

    return next;
}