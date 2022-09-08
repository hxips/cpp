#include <iostream>

int main()
{
    int a, c = 1;

    scanf_s("%i", &a);

    while (c <= a)
    {
        printf("%5i -> %5i -> %5i\n", c, c * c, c * c * c);
        ++c;
    }
}

