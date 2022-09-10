#include <stdio.h>
int main()
{
	int a[1000];
	int n;
	scanf_s("%i", &n);

	for (int i = 0; i < n; ++i)
		scanf_s("%i", &a[i]);

	int l = 0, r = n - 1;
	
	while (l != r)
	{
		while (l < r)
		{
			if (a[l] % 2 == 0)
				break;
			else
				++l;
		}

		while (r > l)
		{
			if (a[r] % 2 != 0)
				break;
			else
				--r;
		}
		int temp = a[l];
		a[l] = a[r];
		a[r] = temp;
	}

	for (int i = 0; i < n; ++i)
		printf("%i ", a[i]);
	printf("\n");
}