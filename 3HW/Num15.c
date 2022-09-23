#include <stdio.h>

#define MAX 1000


void multiply(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int s = 0;
            for (int k = 0; k < n; ++k)
            {
                s += A[i][k] * B[k][j];
            }
            C[i][j] = s;
        }
    }
}


int main()
{
    int a[MAX][MAX];
    int b[MAX][MAX];
    int c[MAX][MAX];

    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            scanf_s("%i", &a[i][j]);
        }
    }

    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            scanf_s("%i", &b[i][j]);
        }
    }

    multiply(a, b, c, MAX);

    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j)
            printf("%i ", c[i][j]);
        printf("\n");
    }
    printf("\n");
}