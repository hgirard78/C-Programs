#include <stdio.h>

unsigned long isqrt(unsigned long n){
    unsigned long r = n;
    while(r * r > n)
    {
        r += n / r;
        r /= 2;
    }

    return r;
}

unsigned long sum_of_divisors(unsigned long n, size_t *count)
{
    unsigned long res = 1;
    unsigned long i = 2;
    unsigned long rac = isqrt(n);
    *count = 1;
    while (i < rac)
    {
        if (n % i == 0)
        {
            res += i;
            res += n / i;
            *count += 2;
        }
        i++;
    }
    
    if (rac * rac == n)
    {
        *count += 1;
        return res+rac;
    }
    return res;
}

int main()
{
    unsigned long x;
    unsigned long sum;
    size_t count;

    x = 28;
    sum = sum_of_divisors(x, &count);
    printf("x = %lu\n", x);
    printf("sum = %lu\n", sum);
    printf("count = %zu\n\n", count);

    x = 100;
    sum = sum_of_divisors(x, &count);
    printf("x = %lu\n", x);
    printf("sum = %lu\n", sum);
    printf("count = %zu\n\n", count);

    return 0;
}
