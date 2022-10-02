#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long num_len(long long a)
{
    long dig = 0;
    // while (a > 0)
    // {
    //     a = a / 10;
    //     dig++;
    // }
    dig = log10(a) + 1;
    return dig;
}

long long power(long s)
{
    long long base = 10;
    long itr = s;
    long long exp = 1;
    while(itr)
    {
        exp = exp * base;
        itr -= 1;
    }
    return exp;
}

long long karatsuba(long long x, long long y, long size)
{
    // declarations
    long long U = 0, V = 0, W = 0, x1 = 0, x2 = 0, y1 = 0, y2 = 0, Z = 0;
    long long P;

    if (size == 1)
    {
        return x * y;
    }
    else
    {
        long long exp = 1;
        printf("--%ld\n", size/2);
        exp = power(size / 2);
        printf("%ld**\n", exp);
        x1 = x % exp;
        x2 = (x - x1) / exp;
        y1 = y % exp;
        y2 = (y - y1) / exp;
        U = karatsuba(x2, y2, size / 2);
        V = karatsuba(x1, y1, size / 2);
        x1 -= x2;
        y1 -= y2;
        W = karatsuba(x1, y1, size / 2);
        Z = U + V - W;
        P = (exp* exp* U) + exp* Z + V;
    }
    return P;
}

int main()
{
    long long a, b;
    long long y;
    long nx;
    long ny;

    printf("Enter the 2 numbers for the product: ");
    scanf("%lld %lld",&a, &b);

    nx = num_len(a);
    // printf("%ld\n", nx);
    ny = num_len(b);
    // printf("%ld\n", ny);

    if (nx >= ny)
        y = karatsuba(a, b, nx);
    else if(nx < ny)
        y = karatsuba(a, b, ny);
    else
        printf("Invalid inputs...\n");

    printf("Result of the product is: %lld\n", y);

    return 0;
}