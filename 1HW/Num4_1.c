#include <stdio.h>
#include <limits.h>

int main()
{
	int n;

	scanf_s("%i", &n);

	int min = INT_MAX;

	for (int i = 0; i < n; ++i)
	{
		int a;
		scanf_s("%i", &a);
		if (a < min)
			min = a;
	}

	printf("Min = %i\n", min);
}

