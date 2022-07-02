#include <stdio.h>
#include <math.h>
#include <cmath>

int length(int);

int main()
{
    int i, p, n = 0;
    float x;
    char a[50];

    while ((n < 16) || (n > 16)) {
        printf_s("Enter a credit card number: ");
        scanf_s("%f", &x);
        n = floor(log10(abs(x))) + 1;
        if ((n < 16) || (n > 16)) {
            printf_s("The entered credit card number doesn't have 16 digits!\n");
        }
    }

    sprintf_s(a, "%f", x);

    if(a[0]==52)
        printf_s("The credit card is valid. It is issued by Visa.");

    return 0;
}