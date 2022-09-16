#include <stdio.h>
int main()
{
    int a[1000];
    int n, m;
    scanf_s("%i %i", &n, &m);
    for (int i = 0; i < n * m; ++i)
        scanf_s("%i", &a[i]);

    for (int col = 0; col < m; ++col)
    {
        for (int str = 0; str < n; ++str)
        {
            for (int i = col; i < m * (n - 1); i += m)
            {
                if (a[i] > a[i + m])
                {
                    int temp = a[i];
                    a[i] = a[i + m];
                    a[i + m] = temp;
                }
            }
        }
    }

    for (int i = 0; i < n * m; i += m)
    {
        for (int j = 0; j < m; ++j)
        {
            printf("%i ", a[i + j]);
        }
        printf("\n");
    }
}