#include <stdio.h>

float cube(float* p)
{
	return *p * *p * *p;
}



int main()
{
	float j;
	scanf("%f", &j);
	float* q = &j;

	printf("%g\n", cube(q));
}