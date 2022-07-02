#include <stdio.h>
#include <math.h>
#include <cmath>

int main()
{
    int i, n=0, e=0;
    long long x;
    long long a[16], d[16];
    long long b[16], c[16];

    // Entering the credit card number
    while ((n < 16) || (n > 16)) {
        printf_s("Enter a credit card number: ");
        scanf_s("%lld", &x);
        // Checking the length of the number
        n = floor(log10(abs(x))) + 1;
        if ((n < 16) || (n > 16)) {
            printf_s("The entered credit card number doesn't have 16 digits!\n");
        }
    }

    // Creating an integer array from the original number
    for (i = 15; i >= 0; i--) {
        a[i] = x % 10;
        x = x / 10;
    }

    // Dividing the original set into 2 sets
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

    // Doubling the first set
    for (i = 0; i < 16; i++) {
        d[i] = c[i] * 2;
    }

    // Adding the digits of double digit numbers
    for (i = 0; i < 16; i++) {
        int n = 0, m = 0;
        if ((d[i] / 10) >= 1) {
            n = d[i] / 10;
            m = d[i] % 10;
            d[i] = n + m;
        }
    }

    // Adding all the double digit numbers
    int rez = 0;
    for (i = 0; i < 8; i++) {
        rez = rez + d[i] + b[i];
    }

    // Checking if the credit card is recognized by any major U.S. credit card issuer
    if ((rez / 10 != 0) && (rez % 10 == 0)) {
        e++;
    }

    if(e==1){
        if (a[0] == 4) {
            printf_s("The credit card is valid. It is issued by Visa.");
        }
        if (a[0] == 5 && (a[1] >= 1 && a[1] <= 5)) {
            printf_s("The credit card is valid. It is issued by Mastercard.");
        }
        if (a[0] == 6 && ((a[1] == 5) || (a[1] == 0 && a[2] == 1 && a[3] == 1) || (a[1] == 4 && a[2] == 4))) {
            printf_s("The credit card is valid. It is issued by Discover.");
        }
        if (a[0] == 3 && (a[1] == 4 || a[1] == 7)) {
            printf_s("The credit card is valid. It is issued by American Express (Amex).");
        }
    }
    else {
        printf_s("The credit card has not been recognized.");
    }

    return 0;
}