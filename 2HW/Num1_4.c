#include <stdio.h>
int main()
{
	int a[1000];
	int n;
	scanf_s("%i", &n);
	for (int i = 0; i < n; ++i)
		scanf_s("%i", &a[i]);

	int l, r;
	scanf_s("%i %i", &l, &r);
	int len = r - l;

	for (int i = l; i < n - len; ++i)
		a[i] = a[i + len];

	for (int i = 0; i < n - len; ++i)
		printf("%i ", a[i]);
	printf("\n");
}