#include <stdio.h>

int main()
{
    int a[10000];
    int b[10000];
    for (int i = 0; i < 10000; ++i)
    {
        int j;
        scanf_s("%i", &j);

        a[i] = j;

        int sum = 0;
        while (j != 0)
        {
            sum += j % 10;
            j /= 10;
        }

        b[i] = sum;
    }

    for (int j = 0; j < 10000; ++j)
    {
        for (int i = 0; i < 10000 - 1 - j; ++i)
        {
            if (b[i] > b[i + 1])
            {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;

                int bemp = b[i];
                b[i] = b[i + 1];
                b[i + 1] = bemp;
            }
        }
    }

    for (int i = 0; i < 10000; ++i)
    {
        printf("%i ", a[i]);
    }

    printf("\n");
}