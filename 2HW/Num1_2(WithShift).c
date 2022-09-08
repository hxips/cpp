#include <stdio.h>
int main()
{
	int a[1000];
	int n;
	scanf_s("%i", &n);

	for (int i = 0; i < n; ++i)
		scanf_s("%i", &a[i]);

	int j, num;
	scanf_s("%i %i", &num, &j);

	for (int i = n; i > j; --i)
	{
		a[i] = a[i - 1];
	}
	a[j + 1] = num;

	for (int i = 0; i <= n; ++i)
		printf("%i ", a[i]);
	printf("\n");
}