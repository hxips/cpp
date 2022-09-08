#include <stdio.h>
#include <math.h>

int main()
{
    int n, result = 0;
    scanf_s("%i", &n);

    for (int i = 1; i < n; ++i)
    {
        for (int j = i; j <= n; ++j)
        {
            int q;
            q = (int)(sqrt(i * i + j * j));

            if (q == sqrt(i * i + j * j))
            {
                if (q <= n)
                {
                    bool y;
                    y = true;

                    for (int t = 2; t < n; t++)
                    {
                        if (i % t == 0 && j % t == 0)
                        {
                            y = false;
                        }
                    }

                    if (y)
                    {
                        printf("%i %i %i\n", i, j, q);
                    }
                }
            }
        }
    }
}
