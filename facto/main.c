#include<stdio.h>
#include"facto.h"

int main(){
    unsigned long res;
    for (unsigned long i = 0; i <= 19; i++){
        res = facto(i);
        printf("facto(%lu) = %lu\n", i, res);
    }
    res = facto(20);
    printf("facto(%d) = %lu", 20, res);

    return 0;
}

