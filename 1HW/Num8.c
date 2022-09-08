#include <stdio.h>

int main()
{
    int a, b, c;
    scanf_s("%i %i %i", &a, &b, &c);
    int j;

    j = a + c - (a % c);

    for (j; j <= b; j += c)
        printf("%i ", j);
}
