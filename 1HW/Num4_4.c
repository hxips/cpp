#include <stdio.h>
#include <limits.h>

int main()
{
	int n;

	scanf_s("%i", &n);

	int b;
	scanf_s("%i", &b);

	bool is_inc = true;
	bool is_dec = true;
	bool is_eq = true;

	for (int i = 1; i < n; ++i)
	{
		int a;
		scanf_s("%i", &a);

		if (b > a)
		{
			is_eq = false;
			is_inc = false;
		}

		if (b < a)
		{
			is_eq = false;
			is_dec = false;
		}

		if (b == a)
		{
			is_inc = false;
			is_dec = false;
		}

		b = a;
	}
	if (is_dec)
		printf("Decreasing");
	if (is_eq)
		printf("Equal");
	if (is_inc)
		printf("Increasing");
	if (not (is_dec || is_inc || is_eq))
		printf("None");
}