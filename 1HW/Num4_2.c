#include <stdio.h>
#include <limits.h>

int main()
{
	int n;

	scanf_s("%i", &n);

	int min = INT_MAX;
	bool is_min = false;
	int max = INT_MIN;
	bool is_max = false;

	for (int i = 0; i < n; ++i)
	{
		int a;
		scanf_s("%i", &a);
		if (a % 2 == 0)
		{
			if (a < min)
				min = a;
			is_min = true;
		}
		else
		{
			if (a > max)
				max = a;
			is_max = true;
		}
		
	}

	if (is_min)
		printf("Min = %i ", min);
	else
		printf("None ");

	if (is_max)
		printf("Max = %i", max);
	else
		printf("None");
}
