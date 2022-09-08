#include <stdio.h>
int main()
{
	int a[1000];
	int n;
	scanf_s("%i", &n);
	for (int i = 0; i < n; ++i)
		scanf_s("%i", &a[i]);

	int j;
	scanf_s("%i", &j);

	for (int i = j; i < n - 1; ++i)
		a[i] = a[i + 1];

	for (int i = 0; i < n - 1; ++i)
		printf("%i ", a[i]);
	printf("\n");
}