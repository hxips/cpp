#include <stdio.h>

int main()
{
    int n;
    scanf_s("%i", &n);

    int a[1000];
    for (int i = 0; i < n; ++i)
        scanf_s("%i", &a[i]);

    int k;
    scanf_s("%i", &k);

    for (int i = n - 1; i >= 0; --i)
        a[i + k % n] = a[i];


    for (int i = 0; i < k; ++i)
        a[i] = a[n + i % n];


    for (int i = 0; i < n; ++i)
        printf("%i ", a[i]);
}