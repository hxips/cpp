#include <stdlib.h>
#include <math.h>
#include <stdio.h>



float* get_geometric_progression(float a, float r, int n)
{
    float* pr = (float*)malloc(sizeof(float) * n);

    for (int i = 0; i < n; ++i)
        pr[i] = a * pow(r, i);

    return pr;
}



int main()
{
    float b, q;
    int num;

    scanf("%f %f %i", &b, &q, &num);

    float* prog = get_geometric_progression(b, q, num);
    for (int i = 0; i < num; ++i)
        printf("%g\n", prog[i]);

    free(prog);
}