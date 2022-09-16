#include <stdio.h>

int main()
{
    int n;
    scanf_s("%i", &n);
    int a[1000];
    for (int i = 0; i < n; ++i)
        scanf_s("%i", &a[i]);

    int l = -1, r = n;
    while (r > l + 1)
    {
        int th1 = (l + (r - l + 1) / 3);
        int th2 = (l + (2 * (r - l) - 1) / 3);

        if (a[th1] == a[th2])
        {
            if (th1 == th2)
            {
                th1 = l + 1;
                th2 = r - 1;
            }

            else
            {
                l = th1;
                r = th2;
            }
        }

        if (a[th1] < a[th2])
            l = th1;
        else
            r = th2;
    }

      printf("%i\n", r);
}