#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include "divisor_sum.h"

int main(int argc, char** argv){
    unsigned long param = strtoul(argv[1], NULL, 10);
    if (argc != 2 || param == 0)
        errx(1, "Error");
    unsigned long res = divisor_sum(param);
    printf("divisor_sum(%lu) = %lu", param, res);
    return 0;
}