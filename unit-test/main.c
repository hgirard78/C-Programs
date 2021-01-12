#include <criterion/criterion.h>
#include <stdio.h>
#include <stdlib.h>

unsigned long facto (unsigned long n)
{
    if (n == 0)
        return 1;
    return n * facto(n-1);
}


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
