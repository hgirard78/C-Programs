#include <criterion/criterion.h>
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void setup(void)
{
}

void teardown(void)
{
}

Test(facto, facto_5)
{
    unsigned long n = 5;
    unsigned long res = facto(n);
    cr_assert(res == 120);
}
