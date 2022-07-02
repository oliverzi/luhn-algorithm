#include <stdio.h>
#include <math.h>
#include <cmath>

int main()
{
    int i, n=0, e=0;
    long long x;
    long long a[16], d[16];
    long long b[16], c[16];

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

    if (a[0] == 4) {
        printf_s("The credit card is valid. It is issued by Visa.");
        e++;
    }
    if (a[0] == 5 && (a[1] >= 1 && a[1] <= 5)) {
        printf_s("The credit card is valid. It is issued by Mastercard.");
        e++;
    }
    if (a[0] == 6 && ((a[1] == 5) || (a[1] == 0 && a[2] == 1 && a[3] == 1) || (a[1] == 4 && a[2] == 4))) {
        printf_s("The credit card is valid. It is issued by Discover.");
        e++;
    }
    if (a[0] == 3 && (a[1] == 4 || a[1] == 7)) {
        printf_s("The credit card is valid. It is issued by American Express (Amex).");
        e++;
    }
    if (e == 0) {
        printf_s("The credit card has not been recognized.");
    }

    // Seperating 2 sets
    int g = 0, h = 0;
    for (i = 0; i < 16; i++) {
        if (i % 2) {
            b[g] = a[i];
            g++;
        }
        else {
            c[h] = a[i];
            h++;
        }
    }

    // Doubling first set
    for (i = 0; i < 16; i++) {
        d[i] = c[i] * 2;
    }

    // Adding all the double digit numbers.
    for (i = 0; i < 16; i++) {
        int n = 0, m = 0;
        if ((d[i] / 10) >= 1) {
            n = d[i] / 10;
            m = d[i] % 10;
            d[i] = n + m;
        }
    }

    return 0;
}