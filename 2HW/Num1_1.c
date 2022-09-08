#include <stdio.h>
int main()
{
	int a[1000];
	int n;
	scanf_s("%i", &n);

	int k;

	for (int i = 0; i < n; ++i)
	{
		scanf_s("%i", &k);
		a[i] = k;
		a[i + n] = k;
	}

	for (int i = 0; i < 2 * n; ++i)
		printf("%i ", a[i]);
	printf("\n");
}