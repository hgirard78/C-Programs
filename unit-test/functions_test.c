#include <criterion/criterion.h>
#include <stdio.h>
#include <stdlib.h>

unsigned long facto (unsigned long n)
{
    if (n == 0)
        return 1;
    return n * facto(n-1);
}

