#include <stdio.h>

void mult2_array(int* p, int n)
{
	for (int i = 0; i < n; ++i)
	{
		*p *= 2;
		++p;
	}
}



int main()
{
	int w[1000];
	int size;
	scanf("%i", &size);
	for (int i = 0; i < size; ++i)
		scanf("%i", &w[i]);
	int* q = &w[0];

	mult2_array(q, size);
	for (int i = 0; i < size; ++i)
		printf("%i ", w[i]);
}