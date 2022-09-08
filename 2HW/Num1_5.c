#include <stdio.h>
int main()
{
	int a[1000];
	int n;
	scanf_s("%i", &n);
	for (int i = 0; i < n; ++i)
		scanf_s("%i", &a[i]);

	int k = 0;

	for (int i = 0; i < n; ++i)
	{
		if (a[i] >= 0)
		{
			a[k] = a[i];
			++k;
		}
	}

	for (int i = 0; i < n - k; ++i)
		printf("%i ", a[i]);
	printf("\n");
}