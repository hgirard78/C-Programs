#include <criterion/criterion.h>
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main()
{
    unsigned long n = 5;
    unsigned long res = facto(n);
    printf("facto(%lu) = %lu\n", n, res);
}
