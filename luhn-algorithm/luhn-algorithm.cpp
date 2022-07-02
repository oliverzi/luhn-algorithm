#include <stdio.h>
#include <math.h>
#include <cmath>

int length(int);

int main()
{
    int n=0;
    float x;

    while ((n < 16) || (n > 16)) {
        printf_s("Enter a credit card number: ");
        scanf_s("%f", &x);
        n = floor(log10(abs(x))) + 1;
        if ((n < 16) || (n > 16)) {
            printf_s("The entered credit card number doesn't have 16 digits!\n");
        }
    }

    printf_s("%d", n);

    return 0;

}