#include <stdio.h>
int main()
{
	int a[1000];
	int n;
	scanf_s("%i", &n);
	for (int i = 0; i < n; ++i)
		scanf_s("%i", &a[i]);

	for (int i = 0; i < n; ++i)
		printf("%i %i ", a[i], a[i]);
	printf("\n");
}