#include <stdio.h>
#include <math.h>
#include <cmath>

int main()
{
    int i, n=0;
    long long x;
    long long a[16];

    while ((n < 16) || (n > 16)) {
        printf_s("Enter a credit card number: ");
        scanf_s("%lld", &x);
        n = floor(log10(abs(x))) + 1;
        if ((n < 16) || (n > 16)) {
            printf_s("The entered credit card number doesn't have 16 digits!\n");
        }
    }

    for (i = 15; i >= 0; i--) {
        a[i] = x % 10;
        x = x / 10;
    }

    return 0;
}