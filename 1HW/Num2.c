#include <stdio.h>
#include <cmath>

int main()
{
    int a, b, c;
    bool t = false;

    scanf_s("%i %i %i", &a, &b, &c);

    if (abs(b - a) == 1 && abs(b - c) == 1 && abs(a - c) == 2)
    {
        printf("Consecutive ");
        t = true;
    }

    if (a < b && b < c)
    {
        printf("Increasing ");
        t = true;
    }

    if (a  > b && b > c)
    {
        printf("Decreasing ");
        t = true;
    }

    if (a == b == c)
    {
        printf("Equal");
        t = true;
    }

    if (not t)
    {
        printf("None");
    }

}
