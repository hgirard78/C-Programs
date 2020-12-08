#include <stdio.h>
#include "is_perfect_number.h"

int main(){
    int res, i;
    for (i = 1; i < 100000; i++){
        res = is_perfect_number(i);
        if (res != 0)
            printf("%d\n", res);
    }
    return 0;
}