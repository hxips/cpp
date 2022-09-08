#include <stdio.h>


int main()
{
    int a, b;
    scanf_s("%i %i", &a, &b);

    int l = 1, n = a;

    for (int i = a; i <= b; ++i)
    {
        int j = i, Len = 1;

        while (j != 1)
        {
            if (j % 2 == 0)
            {
                j /= 2;
            }

            else
            {
                j = 3 * j + 1;
            }
            ++Len;
        }

        if (Len > l)
        {
            l = Len;
            n = i;
        }
        Len = 1;
    }

    printf("Number = %i, Lenght = %i", n, l);
}