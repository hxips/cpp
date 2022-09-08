#include <stdio.h>
#include <limits.h>

int main()
{
	int n;

	scanf_s("%i", &n);

	int max = INT_MIN;
	int k = 0;

	for (int i = 0; i < n; ++i)
	{
		int a;
		scanf_s("%i", &a);
		if (a > max)
		{
			max = a;
			k = 0;
		}

		if (a == max)
			++k;
	}

	printf("Max = %i, count = %i", max, k);
}
