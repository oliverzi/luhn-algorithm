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

    // 0 = 48, 1 = 49, 2 = 50, 3 = 51, 4 = 52, 5 = 53, 6 = 54, 7 = 55, 8 = 56, 9 = 57

    if(a[0]==52)
        printf_s("The credit card is valid. It is issued by Visa.");
    if (a[0] == 53 && (a[1]>=49 && a[1]<=53))
        printf_s("The credit card is valid. It is issued by Mastercard.");
    if (a[0] == 54 && ((a[1] == 53) || (a[1]==48 && a[2]==49 && a[3]==49) || (a[1]==52 && a[2]==52)))
        printf_s("The credit card is valid. It is issued by Discover.");
    if (a[0] == 51 && (a[1]==52 || a[1]==55))
        printf_s("The credit card is valid. It is issued by American Express (Amex).");

    return 0;
}