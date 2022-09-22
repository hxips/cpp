#include <stdio.h>

void triangle(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < i; ++j)
            printf("*");
        printf("\n");
    }
}

int main()
{
    int a;
    scanf_s("%i", &a);
    triangle(a);    
}
