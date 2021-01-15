#include <criterion/criterion.h>
#include <stdio.h>
#include <stdlib.h>
#include "functions_test.h"

void setup(void)
{
    puts("Run before the test");
}

void teardown(void)
{
    puts("Run after the test");
}

Test(facto, facto_5, .init = setup, .fini = teardown)
{
    unsigned long n = 5;
    unsigned long res = facto(n);
    cr_assert(res == 120);
}
